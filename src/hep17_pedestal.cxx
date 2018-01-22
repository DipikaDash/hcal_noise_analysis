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

bool do8ts=false; 
bool doRaddam=true; 

//int main(int argc, char *argv[])
int main()
{
  float raddam[13]={0.978,0.976,0.986,0.977,0.944,0.954,0.941,0.923,0.912,0.879,0.855,0.830,0.817};
  
  gErrorIgnoreLevel=kError+1;

  //hcal_tree_noise ped("/homes/jaehyeokyoo/scratch/SPE_gsel0_306233.root");
  hcal_tree_noise ped("/Users/jaehyeok/Downloads/PFGtuples/SPE_gsel0_306233.root");

  // Need Rrec for 
  //  - each channel 
  //      - ieta = 16-29
  //      - iphi = 63-66
  //      - depth = 1-7

  TH1D *h1[14][4][7];
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        h1[ieta-16][iphi-63][depth-1]
          = new TH1D(Form("h1_ieta%i_iphi%i_depth%i", ieta,iphi,depth),
                     Form("h1_ieta%i_iphi%i_depth%i", ieta,iphi,depth), 
                     200, 0, 800);
      }
    }
  }

  cout << "Analyzing ped: " << ped.GetEntries() << " events" << endl;
  // loop over trees
  for(unsigned int ientry=0; ientry<ped.GetEntries(); ientry++)
  {
    ped.GetEntry(ientry);  

    //  
    for(unsigned int idigi=0; idigi<ped.QIE11DigiIEta().size(); idigi++)
    {
      //if(!(ped.QIE11DigiIEta().at(idigi)==20 && ped.QIE11DigiIPhi().at(idigi)==66 && ped.QIE11DigiDepth().at(idigi)==2)) continue;
      float q8; 
      q8 = ped.QIE11DigiFC().at(idigi).at(1)+ped.QIE11DigiFC().at(idigi).at(2)
        +ped.QIE11DigiFC().at(idigi).at(3)+ped.QIE11DigiFC().at(idigi).at(4) 
        +ped.QIE11DigiFC().at(idigi).at(5)+ped.QIE11DigiFC().at(idigi).at(6)
        +ped.QIE11DigiFC().at(idigi).at(7)+ped.QIE11DigiFC().at(idigi).at(8);
      
      if(do8ts)
      {
        FillTH1D(h1[ped.QIE11DigiIEta().at(idigi)-16][ped.QIE11DigiIPhi().at(idigi)-63][ped.QIE11DigiDepth().at(idigi)-1], q8, 1.);
      }
      else 
      {
        FillTH1D(h1[ped.QIE11DigiIEta().at(idigi)-16][ped.QIE11DigiIPhi().at(idigi)-63][ped.QIE11DigiDepth().at(idigi)-1], ped.QIE11DigiFC().at(idigi).at(1)+ped.QIE11DigiFC().at(idigi).at(2), 1.);
        FillTH1D(h1[ped.QIE11DigiIEta().at(idigi)-16][ped.QIE11DigiIPhi().at(idigi)-63][ped.QIE11DigiDepth().at(idigi)-1], ped.QIE11DigiFC().at(idigi).at(3)+ped.QIE11DigiFC().at(idigi).at(4), 1.);
        FillTH1D(h1[ped.QIE11DigiIEta().at(idigi)-16][ped.QIE11DigiIPhi().at(idigi)-63][ped.QIE11DigiDepth().at(idigi)-1], ped.QIE11DigiFC().at(idigi).at(5)+ped.QIE11DigiFC().at(idigi).at(6), 1.);
        FillTH1D(h1[ped.QIE11DigiIEta().at(idigi)-16][ped.QIE11DigiIPhi().at(idigi)-63][ped.QIE11DigiDepth().at(idigi)-1], ped.QIE11DigiFC().at(idigi).at(7)+ped.QIE11DigiFC().at(idigi).at(8), 1.);
      } 
      //DEBUG cout << ped.QIE11DigiIEta().at(idigi) << " " << ped.QIE11DigiIPhi().at(idigi) << " " << ped.QIE11DigiDepth().at(idigi) << " : "  << ped.QIE11DigiFC().at(idigi).size() << endl;
    } 
  }
 
  //
  TH1D *h1_frac = new TH1D("h1_frac","h1_frac",20,0,0.3);
  
  //
  // pedestal distributions 
  //
  for(int ieta=16; ieta<30; ieta++)
  { 
    TCanvas *c = new TCanvas("c","c",3200,1800);
    c->SetGrid(1,1); 
    c->Divide(7,4); 
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        if(h1[ieta-16][iphi-63][depth-1]->Integral()==0) continue;
        int cut=h1[ieta-16][iphi-63][depth-1]->GetMean()/4;
        cut=cut+76;
        if(ieta>16 && doRaddam) cut = cut*raddam[ieta-17];
        c->cd((iphi-63)*7+depth);
        if(!do8ts) c->cd((iphi-63)*7+depth)->SetLogy(1);
        h1[ieta-16][iphi-63][depth-1]->SetLineColor(kBlack);
        h1[ieta-16][iphi-63][depth-1]->SetLineWidth(1);
        h1[ieta-16][iphi-63][depth-1]->SetFillColor(kYellow-9);
        h1[ieta-16][iphi-63][depth-1]->SetTitle(Form("(%i,%i,%i), %.0f#pm%.0f, %.4f %%", ieta,iphi,depth,
                            h1[ieta-16][iphi-63][depth-1]->GetMean(),
                            h1[ieta-16][iphi-63][depth-1]->GetRMS(),
                            h1[ieta-16][iphi-63][depth-1]->Integral(cut,1000)/h1[ieta-16][iphi-63][depth-1]->Integral()*100));
        h1[ieta-16][iphi-63][depth-1]->Draw("hist"); 
        cout << cut << " " << Form("(%i,%i,%i) %.4f %%", ieta,iphi,depth,h1[ieta-16][iphi-63][depth-1]->Integral(cut,1000)/h1[ieta-16][iphi-63][depth-1]->Integral()*100) << endl;
        FillTH1D(h1_frac,h1[ieta-16][iphi-63][depth-1]->Integral(cut,1000)/h1[ieta-16][iphi-63][depth-1]->Integral()*100,1.);
      }
    }
    c->Print(Form("plots/h1_ped_ieta%i_%s.pdf", ieta, do8ts?"8ts":"2ts"));
    delete c;
  } 

  // 
  // Summary of fractions 
  //  
  TCanvas *c_frac = new TCanvas("c_frac","c_frac",400,400);
  c_frac->cd(1);
  h1_frac->SetLineColor(kBlack);
  h1_frac->SetLineWidth(2);
  h1_frac->SetFillColor(kAzure-9);
  h1_frac->Draw("hist");
  c_frac->Print(Form("plots/h1_frac_%s.pdf",doRaddam?"Raddam":"noRaddam"));

}


