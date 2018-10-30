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
#include "TProfile.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

using namespace std; 

float Abs(float x)
{
  if(x>=0) return x;
  else return -1*x;
}

//int main(int argc, char *argv[])
int main()
{
  gStyle->SetOptStat(0); 
  gErrorIgnoreLevel=kError+1;

  hcal_tree_noise tree_3p("/homes/jaehyeokyoo/HCAL/ntuples/HcalTupleMaker_316944_default.root"); 
  hcal_tree_noise tree_5p("/homes/jaehyeokyoo/HCAL/ntuples/HcalTupleMaker_316944_5pulse.root"); 
  hcal_tree_noise tree_7p("/homes/jaehyeokyoo/HCAL/ntuples/HcalTupleMaker_316944_7pulse.root"); 

  TH1D *h1_hb_base_3p  = InitTH1D("h1_hb_base_3p", "h1_hb_base_3p", 50, 0., 5.);
  TH1D *h1_he_base_3p  = InitTH1D("h1_he_base_3p", "h1_he_base_3p", 50, 0., 5.);
  TH1D *h1_hb_base_5p  = InitTH1D("h1_hb_base_5p", "h1_hb_base_5p", 50, 0., 5.);
  TH1D *h1_he_base_5p  = InitTH1D("h1_he_base_5p", "h1_he_base_5p", 50, 0., 5.);
  TH1D *h1_hb_base_7p  = InitTH1D("h1_hb_base_7p", "h1_hb_base_7p", 50, 0., 5.);
  TH1D *h1_he_base_7p  = InitTH1D("h1_he_base_7p", "h1_he_base_7p", 50, 0., 5.);

  TH2D *h2_hb_base_3p  = InitTH2D("h2_hb_base_3p", "h2_hb_base_3p", 60, -30, 30, 50, 0., 5.);
  TH2D *h2_he_base_3p  = InitTH2D("h2_he_base_3p", "h2_he_base_3p", 60, -30, 30, 50, 0., 5.);
  TH2D *h2_hb_base_5p  = InitTH2D("h2_hb_base_5p", "h2_hb_base_5p", 60, -30, 30, 50, 0., 5.);
  TH2D *h2_he_base_5p  = InitTH2D("h2_he_base_5p", "h2_he_base_5p", 60, -30, 30, 50, 0., 5.);
  TH2D *h2_hb_base_7p  = InitTH2D("h2_hb_base_7p", "h2_hb_base_7p", 60, -30, 30, 50, 0., 5.);
  TH2D *h2_he_base_7p  = InitTH2D("h2_he_base_7p", "h2_he_base_7p", 60, -30, 30, 50, 0., 5.);

  vector<int> ieta_3p, iphi_3p, depth_3p; 
  vector<float> base_3p, e_3p;
  vector<int> ieta_5p, iphi_5p, depth_5p; 
  vector<float> base_5p, e_5p;
  vector<int> ieta_7p, iphi_7p, depth_7p; 
  vector<float> base_7p, e_7p;
  
  // loop over tree_datas
  for(unsigned int ientry=0; ientry<tree_3p.GetEntries(); ientry++)
  {
    //if(ientry>5) continue;
    
    tree_3p.GetEntry(ientry); 

    //if(tree_3p.OfficialDecisionRun2L().at(0)==0) continue;

    for(unsigned int i=0; i<tree_3p.HBHERecHitEnergy().size(); i++)
    {
      
      if(tree_3p.HBHERecHitSevLvl().at(i)>11) continue;

      ieta_3p.push_back(tree_3p.HBHERecHitIEta().at(i)); 
      iphi_3p.push_back(tree_3p.HBHERecHitIPhi().at(i)); 
      depth_3p.push_back(tree_3p.HBHERecHitDepth().at(i)); 
      base_3p.push_back(tree_3p.HBHERecHitTime().at(i)); 
      e_3p.push_back(tree_3p.HBHERecHitEnergy().at(i)); 
    }
     
    for(unsigned int i=0; i<base_3p.size(); i++) 
    {

      if (Abs(ieta_3p.at(i))<16 || (Abs(ieta_3p.at(i))==16 && depth_3p.at(i)<3))
      {
        FillTH1D(h1_hb_base_3p, base_3p.at(i), 1);
        FillTH2D(h2_hb_base_3p, ieta_3p.at(i), base_3p.at(i), 1);
      }
      else 
      { 
        FillTH1D(h1_he_base_3p, base_3p.at(i), 1);
        FillTH2D(h2_he_base_3p, ieta_3p.at(i), base_3p.at(i), 1);
      }
    }
  } // 3p

  // 5p 
  for(unsigned int ientry=0; ientry<tree_5p.GetEntries(); ientry++)
  {
    //if(ientry>5) continue;
    
    tree_5p.GetEntry(ientry); 

    //if(tree_5p.OfficialDecisionRun2L().at(0)==0) continue;

    for(unsigned int i=0; i<tree_5p.HBHERecHitEnergy().size(); i++)
    {
      
      if(tree_5p.HBHERecHitSevLvl().at(i)>11) continue;

      ieta_5p.push_back(tree_5p.HBHERecHitIEta().at(i)); 
      iphi_5p.push_back(tree_5p.HBHERecHitIPhi().at(i)); 
      depth_5p.push_back(tree_5p.HBHERecHitDepth().at(i)); 
      base_5p.push_back(tree_5p.HBHERecHitTime().at(i)); 
      e_5p.push_back(tree_5p.HBHERecHitEnergy().at(i)); 
    }
     
    for(unsigned int i=0; i<base_5p.size(); i++) 
    {

      if (Abs(ieta_5p.at(i))<16 || (Abs(ieta_5p.at(i))==16 && depth_5p.at(i)<3))
      {
        FillTH1D(h1_hb_base_5p, base_5p.at(i), 1);
        FillTH2D(h2_hb_base_5p, ieta_5p.at(i), base_5p.at(i), 1);
      }
      else 
      { 
        FillTH1D(h1_he_base_5p, base_5p.at(i), 1);
        FillTH2D(h2_he_base_5p, ieta_5p.at(i), base_5p.at(i), 1);
      }
      //FillTH2D(h2_r0_he, he_mahi.at(i), he_mahi.at(i)/he_m2.at(i), 1);
    }
  } // 5p
 
  // 7p
  for(unsigned int ientry=0; ientry<tree_7p.GetEntries(); ientry++)
  {
    //if(ientry>5) continue;
    
    tree_7p.GetEntry(ientry); 

    //if(tree_7p.OfficialDecisionRun2L().at(0)==0) continue;

    for(unsigned int i=0; i<tree_7p.HBHERecHitEnergy().size(); i++)
    {
      
      if(tree_7p.HBHERecHitSevLvl().at(i)>11) continue;

      ieta_7p.push_back(tree_7p.HBHERecHitIEta().at(i)); 
      iphi_7p.push_back(tree_7p.HBHERecHitIPhi().at(i)); 
      depth_7p.push_back(tree_7p.HBHERecHitDepth().at(i)); 
      base_7p.push_back(tree_7p.HBHERecHitTime().at(i)); 
      e_7p.push_back(tree_7p.HBHERecHitEnergy().at(i)); 
    }
     
    for(unsigned int i=0; i<base_7p.size(); i++) 
    {

      if (Abs(ieta_7p.at(i))<16 || (Abs(ieta_7p.at(i))==16 && depth_7p.at(i)<3))
      {
        FillTH1D(h1_hb_base_7p, base_7p.at(i), 1);
        FillTH2D(h2_hb_base_7p, ieta_7p.at(i), base_7p.at(i), 1);
      }
      else 
      { 
        FillTH1D(h1_he_base_7p, base_7p.at(i), 1);
        FillTH2D(h2_he_base_7p, ieta_7p.at(i), base_7p.at(i), 1);
      }
      //FillTH2D(h2_r0_he, he_mahi.at(i), he_mahi.at(i)/he_m2.at(i), 1);
    }
  } // 7p

  // 
  TCanvas *c_e = new TCanvas("c_e","c_e",800,1200);
  c_e->Divide(2,3); 
  c_e->cd(1); c_e->cd(1)->SetLogy(1); 
  h1_hb_base_3p->SetLineColor(kBlack);
  h1_hb_base_5p->SetLineColor(kBlue);
  h1_hb_base_7p->SetLineColor(kRed);
  h1_hb_base_3p->Draw("hist");
  h1_hb_base_5p->Draw("hist same");
  h1_hb_base_7p->Draw("hist same");
  c_e->cd(2); c_e->cd(2)->SetLogy(1); 
  h1_he_base_3p->SetLineColor(kBlack);
  h1_he_base_5p->SetLineColor(kBlue);
  h1_he_base_7p->SetLineColor(kRed);
  h1_he_base_3p->Draw("hist");
  h1_he_base_5p->Draw("hist same");
  h1_he_base_7p->Draw("hist same");
  c_e->cd(3);
  TH1D *h1_hb_base_5p_ratio = static_cast<TH1D*>(h1_hb_base_5p->Clone());
  h1_hb_base_5p_ratio->Divide(h1_hb_base_3p);
  TH1D *h1_hb_base_7p_ratio = static_cast<TH1D*>(h1_hb_base_7p->Clone());
  h1_hb_base_7p_ratio->Divide(h1_hb_base_3p);
  h1_hb_base_5p_ratio->Draw("e");
  h1_hb_base_7p_ratio->Draw("e same");
  c_e->cd(4);
  TH1D *h1_he_base_5p_ratio = static_cast<TH1D*>(h1_he_base_5p->Clone());
  h1_he_base_5p_ratio->Divide(h1_he_base_3p);
  TH1D *h1_he_base_7p_ratio = static_cast<TH1D*>(h1_he_base_7p->Clone());
  h1_he_base_7p_ratio->Divide(h1_he_base_3p);
  h1_he_base_5p_ratio->Draw("e");
  h1_he_base_7p_ratio->Draw("e same");
  c_e->cd(5);
  TProfile *prof_h2_hb_base_3p = h2_hb_base_3p->ProfileX(); prof_h2_hb_base_3p->SetLineColor(kBlack);
  TProfile *prof_h2_hb_base_5p = h2_hb_base_5p->ProfileX(); prof_h2_hb_base_5p->SetLineColor(kBlue); 
  TProfile *prof_h2_hb_base_7p = h2_hb_base_7p->ProfileX(); prof_h2_hb_base_7p->SetLineColor(kRed);
  prof_h2_hb_base_3p->Draw("e");
  prof_h2_hb_base_5p->Draw("e same");
  prof_h2_hb_base_7p->Draw("e same");
  c_e->cd(6);
  TProfile *prof_h2_he_base_3p = h2_he_base_3p->ProfileX(); prof_h2_he_base_3p->SetLineColor(kBlack); 
  TProfile *prof_h2_he_base_5p = h2_he_base_5p->ProfileX(); prof_h2_he_base_5p->SetLineColor(kBlue); 
  TProfile *prof_h2_he_base_7p = h2_he_base_7p->ProfileX(); prof_h2_he_base_7p->SetLineColor(kRed);
  prof_h2_he_base_3p->Draw("e");
  prof_h2_he_base_5p->Draw("e same");
  prof_h2_he_base_7p->Draw("e same");
  c_e->Print("plots/base.pdf");
}


