#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>

#include "TFile.h"
#include "TH2D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TError.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"



using namespace std; 

//int main(int argc, char *argv[])
int main()
{
  gErrorIgnoreLevel=kError+1;
  
  hcal_tree_noise zero("/hadoop/cms/store/user/jaehyeok/ZeroBias/Run2017F-PromptReco-v1_RECO_20171223_053521/171223_043552/0000/results_1*.root");
  hcal_tree_noise jetht("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017F-JetHTJetPlusHOFilter-17Nov2017-v1_RAW-RECO_20171223_031608/171223_021646/0000/results_*.root");

  cout << "Analyzing ZeroBias : " << zero.GetEntries() << " events" << endl;
  cout << "Analyzing JetHT    : " << jetht.GetEntries() << " events" << endl;

  // Need Rrec for 
  //  - each channel 
  //      - ieta = 16-29
  //      - iphi = 63-66
  //      - depth = 1-7
  //  - different Nvtx 
  //      - mean = 35 rms=7
  //      - about 15% with Nvtx=1
  //      - <25 >45

  TH1D *h1_zero[14][4][7]; // ieta iphi depth 
  TH1D *h1_jetht[14][4][7]; // ieta iphi depth 
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        h1_zero[ieta-16][iphi-63][depth-1] = new
          TH1D( Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),
                Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),
                10000, 0, 100);
        h1_zero[ieta-16][iphi-63][depth-1]->Sumw2();
        h1_jetht[ieta-16][iphi-63][depth-1] = new
          TH1D( Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),
                Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),
                10000, 0, 100);
        h1_jetht[ieta-16][iphi-63][depth-1]->Sumw2();
      }
    }
  }

  // loop over trees
  for(unsigned int ientry=0; ientry<zero.GetEntries(); ientry++)
  {
    zero.GetEntry(ientry); 
    //  
    for(unsigned int irec=0; irec<zero.HBHERecHitEnergy().size(); irec++)
    {
      FillTH1D(h1_zero[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1], zero.HBHERecHitEnergy().at(irec), 1.);
    } 
  } 

  for(unsigned int ientry=0; ientry<jetht.GetEntries(); ientry++)
  {
    jetht.GetEntry(ientry); 
    //  
    for(unsigned int irec=0; irec<jetht.HBHERecHitEnergy().size(); irec++)
    {
      FillTH1D(h1_jetht[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1], jetht.HBHERecHitEnergy().at(irec), 1.);
    } 
  } 

  TFile *HistFile = new TFile("hep17_erec.root", "RECREATE");
  gROOT->cd();
  HistFile->cd();
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        if(h1_zero[ieta-16][iphi-63][depth-1]->Integral()!=0)
        {
          h1_zero[ieta-16][iphi-63][depth-1]->SetDirectory(0);
          h1_zero[ieta-16][iphi-63][depth-1]->Write(0);
        }
        if(h1_jetht[ieta-16][iphi-63][depth-1]->Integral()!=0)
        {
          h1_jetht[ieta-16][iphi-63][depth-1]->SetDirectory(0);
          h1_jetht[ieta-16][iphi-63][depth-1]->Write(0);
        }
      }
    }
  }
}
