#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip> // for setw()

#include "TROOT.h"
#include "TF1.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TBranch.h"
#include "TString.h"
#include "TStyle.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

using namespace std;

bool DRAWPLOTS    = false;  // draw plots or not (make "Fig" directory first before turning this on)
bool VERBOSE      = false;  // print out mean +/- sigma for each channel

//
int main() 
{ 
  // do not print out too many errors ... 
  gErrorIgnoreLevel=kError+1;

  // fit pannel display option
  gStyle->SetOptFit(1011);
  gStyle->SetOptStat(111111); 

  //
  // Get the tree from the PFG ntuple 
  //
  TString rootfile = "outputFile_run313818.root";
  hcal_tree_noise tree(rootfile.Data());

  // 
  // Define histograms per channel
  //  -number of indices in eta, phi, depth
  // 
  const int nieta = 83;
  const int niphi = 72;
  const int ndepth = 7; 
  TH1F *h1_FC[nieta][niphi][ndepth]; 
  for(int ieta=0; ieta<nieta; ieta++) 
  { 
    for(int iphi=0; iphi<niphi; iphi++) 
    {
      for(int idepth=0; idepth<ndepth; idepth++) 
      { 
          h1_FC[ieta][iphi][idepth] = new 
            TH1F( Form("h1_FC_ieta%s_iphi%i_depth%i",
                  (ieta>=41?Form("%i",ieta-41):Form("m%i",41-ieta)),
                  iphi+1,  
                  (idepth+1)),
                Form("h1_FC_ieta%s_iphi%i_depth%i",
                  (ieta>=41?Form("%i",ieta-41):Form("m%i",41-ieta)),
                  iphi+1,  
                  (idepth+1)),
                100, 0, 5000);
          h1_FC[ieta][iphi][idepth]->Sumw2();
      }
    }
  }

  //
  // Define and initialize arrays to be used to make a text file 
  //
  float FC_mean[nieta][niphi][ndepth];    // mean of fC
  float FC_sigma[nieta][niphi][ndepth];   // sigma of fC 
  for(int ieta=0; ieta<nieta; ieta++) 
  { 
    for(int iphi=0; iphi<niphi; iphi++) 
    {
      for(int idepth=0; idepth<ndepth; idepth++) 
      { 
        FC_mean[ieta][iphi][idepth] = -999.; 
        FC_sigma[ieta][iphi][idepth] = -999.; 
      }
    }
  }

  //
  // Loop over events 
  //
  unsigned int nentries = tree.GetEntries();
  cout << "[HE dark current] The number of entries is: " << nentries << endl;

  // main event loop
  //for(unsigned int ievent = 0; ievent<nentries; ievent++) 
  for(unsigned int ievent = 0; ievent<100; ievent++) 
  {
    tree.GetEntry(ievent); 

    // Progress indicator 
    if(ievent%100==0) cout << "[HE dark current] Processed " << ievent << " out of " << nentries << " events" << endl; 

    // fill histogram 
    for(unsigned int i=0; i<tree.QIE11DigiIEta().size(); i++) 
    {
      int ieta =  tree.QIE11DigiIEta().at(i);
      int iphi =  tree.QIE11DigiIPhi().at(i);
      int idepth =  tree.QIE11DigiDepth().at(i);

      if(tree.QIE11DigiFC().at(i).size()!=8)
      { 
        cout << "[Error] nTS is not 8 for channel (" << ieta << ", " << iphi << ", " << idepth << ")" << endl;
        continue;
      }
      
      float ch_total_charge = 0;

      for(unsigned int its=0; its<tree.QIE11DigiFC().at(i).size(); its++)   
      { 
        ch_total_charge = ch_total_charge + tree.QIE11DigiFC().at(i).at(its);
      }
      h1_FC[ieta+41][iphi-1][idepth-1]->Fill(ch_total_charge); 
    }

  } //for(unsigned int ievent = 0; ievent<nentries; ievent++) 

  // 
  // Extract mean and sigma 
  // 
  cout << endl; 
  cout << " ........................... Extraction of mean and sigma ...............................  " << endl; 
  cout << endl; 

  for(int ieta=0; ieta<nieta; ieta++) 
  { 
    for(int iphi=0; iphi<niphi; iphi++) 
    {
      for(int idepth=0; idepth<ndepth; idepth++) 
      { 
        if( h1_FC[ieta][iphi][idepth]->Integral()==0 ) continue;

        if(VERBOSE) 
        { 
          cout << "[HE dark current] For ieta, iphi, depth = ";
          cout << (ieta-41) <<  ", " << (iphi+1) << ", " << (idepth+1) << endl;
          cout << "[HE dark current] charge in 8 TSs [fC] = " << h1_FC[ieta][iphi][idepth]->GetMean() << " +/- " 
            << h1_FC[ieta][iphi][idepth]->GetRMS() << endl;  
        } 

        FC_mean[ieta][iphi][idepth] = h1_FC[ieta][iphi][idepth]->GetMean();   
        FC_sigma[ieta][iphi][idepth] = h1_FC[ieta][iphi][idepth]->GetRMS(); 
      }
    }
  }

  // 
  // Drawing : charge distribution per channel 
  // 
  // 
  if(DRAWPLOTS)
  {
    cout << endl; 
    cout << " ........................................................................................  " << endl; 
    cout << " ..................................... Drawing ..........................................  " << endl; 
    cout << " ........................................................................................  " << endl; 
    cout << endl; 

    for(int ieta=0; ieta<nieta; ieta++) 
    { 
      for(int iphi=0; iphi<niphi; iphi++) 
      {
        for(int idepth=0; idepth<ndepth; idepth++) 
        {  
          // Draw plots if the mean/sigma is too large or too small 
          bool DRAWCHANNEL=false;
          float highFC(0.), lowFC(999.);
          float highFCsigma(0.), lowFCsigma(999.);
          if(FC_mean[ieta][iphi][idepth]>highFC || FC_mean[ieta][iphi][idepth]<lowFC) DRAWCHANNEL=true;
          if(FC_sigma[ieta][iphi][idepth]>highFCsigma || FC_sigma[ieta][iphi][idepth]<lowFCsigma) DRAWCHANNEL=true;
          
          if(!DRAWCHANNEL) continue;

          // Skip if the histogram is empty (= channel does not exis in the ntuple) 
          if( h1_FC[ieta][iphi][idepth]->Integral()==0 ) continue;

          // Canvas for each channel
          TCanvas *c = new TCanvas("c", "c", 400, 400); 
          c->cd(1); 
          c->cd(1)->SetLogy(1); 
          h1_FC[ieta][iphi][idepth]->Draw("hist e"); 
          c->Print(Form("plots/FC_ieta%s_iphi%i_depth%i.pdf",(ieta>=41?Form("%i",ieta-41):Form("m%i",41-ieta)),(iphi+1),(idepth+1))); 
          delete c;
        }
      }
    }
  } 

  // 
  // Print file 
  // 
  cout << endl; 
  cout << " ............................ Printing text file ........................................  " << endl; 
  cout << endl; 

  // File name depending on option
  TString HEDarkCurrent = rootfile;
  HEDarkCurrent.ReplaceAll(".root",".txt");
  HEDarkCurrent.ReplaceAll("../","");
  HEDarkCurrent = "HEDarkCurrent_"+HEDarkCurrent;

  cout << "[HE dark current] Printing file : " << HEDarkCurrent.Data() << endl;

  // Open file 
  ofstream fout(HEDarkCurrent.Data(), ios_base::app | ios_base::out);

  // Printing table 
  fout <<
    setw(10) << "ieta"   <<
    setw(10) << "iphi" <<
    setw(10) << "depth"  <<
    setw(15) << "mean [fC]" << 
    setw(15) << "rms [fC]" 
    << endl; 
  for(int iphi=0; iphi<niphi; iphi++) 
  { 
    for(int ieta=0; ieta<nieta; ieta++) 
    {
      for(int idepth=0; idepth<ndepth; idepth++) 
      { 
        if(FC_mean[ieta][iphi][idepth] == -999 ) continue;

        fout <<
          setw(10) << (ieta-41)   <<
          setw(10) << iphi+1 <<
          setw(10) << (idepth+1)  <<
          setw(15) << Form("%.2f", FC_mean[ieta][iphi][idepth]) << 
          setw(15) << Form("%.2f", FC_sigma[ieta][iphi][idepth])  
          << endl; 
      }
    }
  }

  fout.close();

  return 0;
}
