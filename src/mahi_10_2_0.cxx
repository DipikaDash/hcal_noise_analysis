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

  //hcal_tree_noise tree_data("/Users/jaehyeok/scratch/results_zerobias.root");
  hcal_tree_noise tree_data("/Users/jaehyeok/scratch/HcalTupleMaker_317478.root");

  TH1D *h1_hb  = new TH1D("h1_hb", "h1_hb", 100, 0., 2.);
  TH1D *h1_he  = new TH1D("h1_he", "h1_he", 100, 0., 2.);
  
  TH1D *h1_hb_0to5  = new TH1D("h1_hb_0to5", "h1_hb_0to5", 100, 0., 2.);
  TH1D *h1_he_0to5  = new TH1D("h1_he_0to5", "h1_he_0to5", 100, 0., 2.);
  TH1D *h1_hb_5to10  = new TH1D("h1_hb_5to10", "h1_hb_5to10", 100, 0., 2.);
  TH1D *h1_he_5to10  = new TH1D("h1_he_5to10", "h1_he_5to10", 100, 0., 2.);
  TH1D *h1_hb_10to20  = new TH1D("h1_hb_10to20", "h1_hb_10to20", 100, 0., 2.);
  TH1D *h1_he_10to20  = new TH1D("h1_he_10to20", "h1_he_10to20", 100, 0., 2.);
  TH1D *h1_hb_20toInf  = new TH1D("h1_hb_20toInf", "h1_hb_20toInf", 100, 0., 2.);
  TH1D *h1_he_20toInf  = new TH1D("h1_he_20toInf", "h1_he_20toInf", 100, 0., 2.);
  
  TH1D *h1_ieta[29];
  for(int ieta=0; ieta<29; ieta++)
  { 
    h1_ieta[ieta] =  new TH1D(Form("h1_ieta%i",ieta+1),  Form("h1_ieta%i",ieta+1), 100, 0., 2.);
  }

  TH2D *h2_hb  = new TH2D("h2_hb", "h2_hb", 100, 0, 20, 100, 0, 20);
  TH2D *h2_he  = new TH2D("h2_he", "h2_he", 100, 0, 20, 100, 0, 20);

  TH2D *h2_r_hb  = new TH2D("h2_r_hb", "h2_r_hb", 100, 0, 20, 100, 0., 2.);
  TH2D *h2_r_hb_1  = new TH2D("h2_r_hb_1", "h2_r_hb_1", 100, 0, 20, 100, 0., 2.);
  TH2D *h2_r_he  = new TH2D("h2_r_he", "h2_r_he", 100, 0, 20, 100, 0., 2.);
  TH2D *h2_r0_hb  = new TH2D("h2_r0_hb", "h2_r0_hb", 100, 0, 20, 100, 0., 2.);
  TH2D *h2_r0_he  = new TH2D("h2_r0_he", "h2_r0_he", 100, 0, 20, 100, 0., 2.);
  
  TH2D *h2_data_mahi  = new TH2D("h2_data_mahi", "h2_data_mahi", 70, -35, 35, 100, -2.5, 997.5);
  TH2D *h2_data_m2    = new TH2D("h2_data_m2",   "h2_data_m2",   70, -35, 35, 100, -2.5, 997.5);
  TH2D *h2_data_occ_mahi  = new TH2D("h2_data_occ_mahi", "h2_data_occ_mahi", 70, -35, 35, 100, 0, 300);
  TH2D *h2_data_occ_m2    = new TH2D("h2_data_occ_m2",   "h2_data_occ_m2",   70, -35, 35, 100, 0, 300);
 
  TH1D *h1_emahi_hb_1  = new TH1D("h1_emahi_hb_1", "h1_emahi_hb_1", 100, 0, 20);
  TH1D *h1_emahi_hb  = new TH1D("h1_emahi_hb", "h1_emahi_hb", 100, 0, 200);
  TH1D *h1_emahi_he  = new TH1D("h1_emahi_he", "h1_emahi_he", 100, 0, 200);
  TH1D *h1_em2_hb_1  = new TH1D("h1_em2_hb_1", "h1_em2_hb_1", 100, 0, 20);
  TH1D *h1_em2_hb  = new TH1D("h1_em2_hb", "h1_em2_hb", 100, 0, 200);
  TH1D *h1_em2_he  = new TH1D("h1_em2_he", "h1_em2_he", 100, 0, 200);
  
  TH1D *h1_data_hb_mahi  = new TH1D("h1_data_hb_mahi", "h1_data_hb_mahi", 100, 0, 20);
  TH1D *h1_data_he_mahi  = new TH1D("h1_data_he_mahi", "h1_data_he_mahi", 100, 0, 20);
  TH1D *h1_data_hb_m2  = new TH1D("h1_data_hb_m2", "h1_data_hb_m2", 100, 0, 20);
  TH1D *h1_data_he_m2  = new TH1D("h1_data_he_m2", "h1_data_he_m2", 100, 0, 20);
  h1_data_hb_mahi->Sumw2();
  h1_data_he_mahi->Sumw2();
  h1_data_hb_m2->Sumw2();
  h1_data_he_m2->Sumw2();

  cout << "Number of events: " << tree_data.GetEntries() << endl;

  // loop over tree_datas
  for(unsigned int ientry=0; ientry<tree_data.GetEntries(); ientry++)
  {
    vector<float> hb_mahi, he_mahi;
    vector<float> hb_m2, he_m2;
    vector<float> hb_m0, he_m0;
   
    //if(ientry>5) continue;
    
    tree_data.GetEntry(ientry); 

    //if(tree_data.OfficialDecisionRun2L().at(0)==0) continue;

    float eta_mahi[70];
    float eta_m2[70];
    float eta_occ_mahi[70];
    float eta_occ_m2[70];
    for(int i=0; i<70; i++)
    { 
      eta_mahi[i]=0;
      eta_m2[i]=0;
      eta_occ_mahi[i]=0;
      eta_occ_m2[i]=0;
    }

    for(unsigned int i=0; i<tree_data.HBHERecHitEnergy().size(); i++)
    {
      
      if(tree_data.HBHERecHitSevLvl().at(i)>11) continue;

      int ieta = tree_data.HBHERecHitIEta().at(i);
      if(ieta<0) ieta = ieta*-1;

      FillTH1D(h1_ieta[ieta-1], tree_data.HBHERecHitEnergy().at(i)/tree_data.HBHERecHitEnergyAux().at(i),1);

      //if (!(tree_data.HBHERecHitIEta().at(i)==17 || tree_data.HBHERecHitIEta().at(i)==18)) continue;
    
      if(tree_data.HBHERecHitEnergy().at(i)>5) eta_mahi[tree_data.HBHERecHitIEta().at(i)+35] += tree_data.HBHERecHitEnergy().at(i);
      if(tree_data.HBHERecHitEnergyAux().at(i)>5) eta_m2[tree_data.HBHERecHitIEta().at(i)+35]   += tree_data.HBHERecHitEnergyAux().at(i);
      eta_occ_mahi[tree_data.HBHERecHitIEta().at(i)+35] += (tree_data.HBHERecHitEnergy().at(i)>0);
      eta_occ_m2[tree_data.HBHERecHitIEta().at(i)+35]   += (tree_data.HBHERecHitEnergyAux().at(i)>0);

      //cout << tree_data.HBHERecHitIEta().at(i)+35 << " " << tree_data.HBHERecHitEnergy().at(i) << endl; 
      // HB
      if (  Abs(tree_data.HBHERecHitIEta().at(i))<16 || 
           (Abs(tree_data.HBHERecHitIEta().at(i))==16 &&  tree_data.HBHERecHitDepth().at(i)<3))
      {
        hb_mahi.push_back(tree_data.HBHERecHitEnergy().at(i));
        hb_m0.push_back(tree_data.HBHERecHitEnergyRaw().at(i));
        hb_m2.push_back(tree_data.HBHERecHitEnergyAux().at(i));
      }
      // HE HPD
      else  
      {
        he_mahi.push_back(tree_data.HBHERecHitEnergy().at(i));
        he_m0.push_back(tree_data.HBHERecHitEnergyRaw().at(i));
        he_m2.push_back(tree_data.HBHERecHitEnergyAux().at(i));
      }
    }
     
    for(int i=-35; i<=35; i++)
    {
      if(eta_mahi[i+35]>0) FillTH2D(h2_data_mahi, i, eta_mahi[i+35], 1);
      if(eta_mahi[i+35]>0) FillTH2D(h2_data_m2,   i, eta_m2[i+35],   1);
      FillTH2D(h2_data_occ_mahi, i, eta_occ_mahi[i+35], 1);
      FillTH2D(h2_data_occ_m2,   i, eta_occ_m2[i+35],   1);
    }

    //
    if( hb_m2.size()!=hb_mahi.size() || 
        he_m2.size()!=he_mahi.size() ) 
          cout << "size mismatch!! " << endl; 
   

    for(unsigned int i=0; i<he_m2.size(); i++) 
    {
      FillTH1D(h1_data_he_mahi, he_mahi.at(i), 1);
      FillTH1D(h1_data_he_m2,   he_m2.at(i), 1);
      
      //if(he_mahi.at(i)<5) continue; 
      FillTH1D(h1_he, he_mahi.at(i)/he_m2.at(i), 1);
      if(he_mahi.at(i)<5) FillTH1D(h1_he_0to5, he_mahi.at(i)/he_m2.at(i), 1); 
      else if(he_mahi.at(i)<10) FillTH1D(h1_he_5to10, he_mahi.at(i)/he_m2.at(i), 1); 
      else if(he_mahi.at(i)<20) FillTH1D(h1_he_10to20, he_mahi.at(i)/he_m2.at(i), 1); 
      else FillTH1D(h1_he_20toInf, he_mahi.at(i)/he_m2.at(i), 1); 
      FillTH2D(h2_he, he_mahi.at(i), he_m2.at(i), 1);
      FillTH2D(h2_r_he, he_mahi.at(i), he_mahi.at(i)/he_m2.at(i), 1);
      FillTH2D(h2_r0_he, he_mahi.at(i), he_mahi.at(i)/he_m2.at(i), 1);

      FillTH1D(h1_emahi_he, he_mahi.at(i), 1);
      FillTH1D(h1_em2_he, he_m2.at(i), 1); 

    }

    for(unsigned int i=0; i<hb_m2.size(); i++) 
    { 
      FillTH1D(h1_data_hb_mahi, hb_mahi.at(i), 1);
      FillTH1D(h1_data_hb_m2,   hb_m2.at(i), 1);
      
      FillTH2D(h2_r_hb_1, hb_mahi.at(i), hb_m2.at(i)/hb_mahi.at(i), 1);
      FillTH1D(h1_emahi_hb_1, hb_mahi.at(i), 1);
      FillTH1D(h1_em2_hb_1, hb_m2.at(i), 1);
      //if(hb_mahi.at(i)<5) continue; 
      FillTH1D(h1_hb, hb_mahi.at(i)/hb_m2.at(i), 1); 
      if(hb_mahi.at(i)<5) FillTH1D(h1_hb_0to5, hb_mahi.at(i)/hb_m2.at(i), 1); 
      else if(hb_mahi.at(i)<10) FillTH1D(h1_hb_5to10, hb_mahi.at(i)/hb_m2.at(i), 1); 
      else if(hb_mahi.at(i)<20) FillTH1D(h1_hb_10to20, hb_mahi.at(i)/hb_m2.at(i), 1); 
      else FillTH1D(h1_hb_20toInf, hb_mahi.at(i)/hb_m2.at(i), 1); 
      FillTH2D(h2_hb, hb_mahi.at(i), hb_m2.at(i), 1);
      FillTH2D(h2_r_hb, hb_mahi.at(i), hb_mahi.at(i)/hb_m2.at(i), 1);
      FillTH2D(h2_r0_hb, hb_mahi.at(i), hb_mahi.at(i)/hb_m2.at(i), 1);
      //if(!(hb_m2.at(i)/hb_mahi.at(i)<0.8 && hb_mahi.at(i)>50)) FillTH1D(h1_emahi_hb, hb_mahi.at(i), 1);
      FillTH1D(h1_emahi_hb, hb_mahi.at(i), 1);
      FillTH1D(h1_em2_hb, hb_m2.at(i), 1);
    }
  }
  
  //
  // mc 
  //
  TH1D *h1_mc_hb_mahi  = new TH1D("h1_mc_hb_mahi", "h1_mc_hb_mahi", 100, 0, 20);
  TH1D *h1_mc_he_mahi  = new TH1D("h1_mc_he_mahi", "h1_mc_he_mahi", 100, 0, 20);
  TH1D *h1_mc_hb_m2    = new TH1D("h1_mc_hb_m2", "h1_mc_hb_m2", 100, 0, 20);
  TH1D *h1_mc_he_m2    = new TH1D("h1_mc_he_m2", "h1_mc_he_m2", 100, 0, 20);
  h1_mc_hb_mahi->Sumw2();
  h1_mc_he_mahi->Sumw2();
  h1_mc_hb_m2->Sumw2();
  h1_mc_he_m2->Sumw2();
  
  TH2D *h2_mc_mahi  = new TH2D("h2_mc_mahi", "h2_mc_mahi", 70, -35, 35, 100, -2.5, 997.5);
  TH2D *h2_mc_m2    = new TH2D("h2_mc_m2",   "h2_mc_m2",   70, -35, 35, 100, -2.5, 997.5);
  TH2D *h2_mc_occ_mahi  = new TH2D("h2_mc_occ_mahi", "h2_mc_occ_mahi", 70, -35, 35, 100, 0, 300);
  TH2D *h2_mc_occ_m2    = new TH2D("h2_mc_occ_m2",   "h2_mc_occ_m2",   70, -35, 35, 100, 0, 300);
  
  //hcal_tree_noise tree_mc("/Users/jaehyeok/scratch/results_nugun.root");
  hcal_tree_noise tree_mc("/Users/jaehyeok/scratch/results_mc.root");
  
  for(unsigned int ientry=0; ientry<tree_mc.GetEntries(); ientry++)
  {
    tree_mc.GetEntry(ientry); 
    
    float eta_mahi[70];
    float eta_m2[70];
    float eta_occ_mahi[70];
    float eta_occ_m2[70];
    for(int i=0; i<70; i++)
    { 
      eta_mahi[i]=0;
      eta_m2[i]=0;
      eta_occ_mahi[i]=0;
      eta_occ_m2[i]=0;
    }

    for(unsigned int i=0; i<tree_mc.HBHERecHitEnergy().size(); i++)
    {
      if(tree_mc.HBHERecHitSevLvl().at(i)>11) continue;
      
      if(tree_mc.HBHERecHitEnergy().at(i)>5) eta_mahi[tree_mc.HBHERecHitIEta().at(i)+35] += tree_mc.HBHERecHitEnergy().at(i);
      if(tree_mc.HBHERecHitEnergyAux().at(i)>5) eta_m2[tree_mc.HBHERecHitIEta().at(i)+35] += tree_mc.HBHERecHitEnergyAux().at(i);
      //eta_mahi[tree_mc.HBHERecHitIEta().at(i)+35] += tree_mc.HBHERecHitEnergy().at(i);
      //eta_m2[tree_mc.HBHERecHitIEta().at(i)+35]   += tree_mc.HBHERecHitEnergyAux().at(i);
      eta_occ_mahi[tree_mc.HBHERecHitIEta().at(i)+35] += (tree_mc.HBHERecHitEnergy().at(i)>0);
      eta_occ_m2[tree_mc.HBHERecHitIEta().at(i)+35]   += (tree_mc.HBHERecHitEnergyAux().at(i)>0);
      
      if (  Abs(tree_mc.HBHERecHitIEta().at(i))<16 || 
           (Abs(tree_mc.HBHERecHitIEta().at(i))==16 &&  tree_mc.HBHERecHitDepth().at(i)<3)) 
      { 
        FillTH1D(h1_mc_hb_mahi, tree_mc.HBHERecHitEnergy().at(i), 1);
        FillTH1D(h1_mc_hb_m2,   tree_mc.HBHERecHitEnergyAux().at(i), 1);
      }
      else 
      { 
        FillTH1D(h1_mc_he_mahi, tree_mc.HBHERecHitEnergy().at(i), 1);
        FillTH1D(h1_mc_he_m2,   tree_mc.HBHERecHitEnergyAux().at(i), 1);
      }
    }
    
    for(int i=-35; i<=35; i++)
    {
      if(eta_mahi[i+35]>0) FillTH2D(h2_mc_mahi, i, eta_mahi[i+35], 1);
      if(eta_mahi[i+35]>0) FillTH2D(h2_mc_m2,   i, eta_m2[i+35],   1);
      FillTH2D(h2_mc_occ_mahi, i, eta_occ_mahi[i+35], 1);
      FillTH2D(h2_mc_occ_m2,   i, eta_occ_m2[i+35],   1);
    }


  }

  h1_hb_0to5->SetLineColor(kRed); 
  h1_hb_5to10->SetLineColor(kBlue); 
  h1_hb_10to20->SetLineColor(kGreen); 
  h1_hb_20toInf->SetLineColor(kViolet); 
  h1_he_0to5->SetLineColor(kRed); 
  h1_he_5to10->SetLineColor(kBlue); 
  h1_he_10to20->SetLineColor(kGreen); 
  h1_he_20toInf->SetLineColor(kViolet); 

  TCanvas *c = new TCanvas("c","c",1200,1600);
  c->Divide(3,4); 
  c->cd(1); 
  h1_hb->SetStats(0);
  h1_hb->SetMaximum(h1_hb->GetMaximum()*1.4);
  h1_hb->DrawNormalized("hist"); 
  h1_hb_0to5->DrawNormalized("hist same"); 
  h1_hb_5to10->DrawNormalized("hist same"); 
  h1_hb_10to20->DrawNormalized("hist same"); 
  h1_hb_20toInf->DrawNormalized("hist same"); 
  c->cd(2); 
  h1_he->SetStats(0);
  h1_he->SetMaximum(h1_he->GetMaximum()*1.2);
  h1_he->DrawNormalized("hist");
  h1_he_0to5->DrawNormalized("hist same"); 
  h1_he_5to10->DrawNormalized("hist same"); 
  h1_he_10to20->DrawNormalized("hist same"); 
  h1_he_20toInf->DrawNormalized("hist same"); 
  c->cd(3); 
  h1_ieta[16]->SetLineColor(kRed); 
  h1_ieta[20]->SetLineColor(kBlue); 
  h1_ieta[24]->SetLineColor(kGreen); 
  h1_ieta[27]->SetLineColor(kViolet); 
  h1_ieta[16]->SetStats(0);
  h1_ieta[16]->SetMaximum(h1_ieta[16]->GetMaximum()*1.2);
  h1_ieta[16]->DrawNormalized("hist");
  h1_ieta[20]->DrawNormalized("same hist");
  h1_ieta[24]->DrawNormalized("same hist");
  h1_ieta[27]->DrawNormalized("same hist");
  c->cd(4); c->cd(4)->SetLogz(1); h2_hb->SetStats(0); h2_hb->Draw("colz"); 
  c->cd(5); c->cd(5)->SetLogz(1); h2_he->SetStats(0); h2_he->Draw("colz");
  c->cd(7); c->cd(7)->SetLogz(1); h2_r_hb->SetStats(0); h2_r_hb->Draw("colz"); //prof_h2_r_hb->Draw("same");
  c->cd(8); c->cd(8)->SetLogz(1); h2_r_he->SetStats(0);  h2_r_he->Draw("colz");
  c->cd(10); c->cd(10)->SetLogz(1); h2_r0_hb->SetStats(0); h2_r0_hb->Draw("colz");
  c->cd(11); c->cd(11)->SetLogz(1); h2_r0_he->SetStats(0); h2_r0_he->Draw("colz");
  c->Print("plots/mahi.pdf");
  
  TCanvas *c_e = new TCanvas("c_e","c_e",1200,400);
  c_e->Divide(3,1); 
  c_e->cd(1); c_e->cd(1)->SetLogy(1); 
  h1_emahi_hb->SetLineColor(kRed);
  h1_emahi_hb->DrawNormalized("hist");
  h1_em2_hb->DrawNormalized("hist same");
  c_e->cd(2); c_e->cd(2)->SetLogy(1); 
  h1_emahi_he->SetLineColor(kRed);
  h1_emahi_he->DrawNormalized("hist");
  h1_em2_he->DrawNormalized("hist same");
  c_e->Print("plots/energy.pdf");

  h1_data_hb_mahi->Scale(1./h1_data_hb_mahi->Integral());
  h1_data_he_mahi->Scale(1./h1_data_he_mahi->Integral());
  h1_data_hb_m2->Scale(1./h1_data_hb_m2->Integral());
  h1_data_he_m2->Scale(1./h1_data_he_m2->Integral());
  h1_mc_hb_mahi->Scale(1./h1_mc_hb_mahi->Integral());
  h1_mc_he_mahi->Scale(1./h1_mc_he_mahi->Integral());
  h1_mc_hb_m2->Scale(1./h1_mc_hb_m2->Integral());
  h1_mc_he_m2->Scale(1./h1_mc_he_m2->Integral());

  h1_data_hb_mahi->SetLineColor(kBlack);  h1_data_hb_mahi->SetMarkerColor(kBlack);
  h1_data_he_mahi->SetLineColor(kBlack);  h1_data_he_mahi->SetMarkerColor(kBlack);
  h1_data_hb_m2->SetLineColor(kBlue);     h1_data_hb_m2->SetMarkerColor(kBlue);
  h1_data_he_m2->SetLineColor(kBlue);     h1_data_he_m2->SetMarkerColor(kBlue);
  h1_mc_hb_mahi->SetLineColor(kRed);      h1_mc_hb_mahi->SetMarkerColor(kRed);
  h1_mc_he_mahi->SetLineColor(kRed);      h1_mc_he_mahi->SetMarkerColor(kRed);
  h1_mc_hb_m2->SetLineColor(kGreen);      h1_mc_hb_m2->SetMarkerColor(kGreen);
  h1_mc_he_m2->SetLineColor(kGreen);      h1_mc_he_m2->SetMarkerColor(kGreen);
  
  //
  // Add ratio panel
  // 
  
  // data vs mc 
  TCanvas *c_datamc = new TCanvas("c_datamc","c_datamc",1600,800);
  c_datamc->Divide(4,2); 
  // MAHI  
  c_datamc->cd(1); c_datamc->cd(1)->SetLogy(1); h1_mc_hb_mahi->Draw("hist");   h1_mc_hb_m2->Draw("e same");    
  c_datamc->cd(2); c_datamc->cd(2)->SetLogy(1); h1_data_hb_mahi->Draw("hist"); h1_data_hb_m2->Draw("e same");    
  c_datamc->cd(3); c_datamc->cd(3)->SetLogy(1); h1_mc_hb_m2->Draw("hist");     h1_data_hb_m2->Draw("e same");    
  c_datamc->cd(4); c_datamc->cd(4)->SetLogy(1); h1_mc_hb_mahi->Draw("hist");   h1_data_hb_mahi->Draw("e same");    
  c_datamc->cd(5); c_datamc->cd(5)->SetLogy(1); h1_mc_he_mahi->Draw("hist");   h1_mc_he_m2->Draw("e same");    
  c_datamc->cd(6); c_datamc->cd(6)->SetLogy(1); h1_data_he_mahi->Draw("hist"); h1_data_he_m2->Draw("e same");    
  c_datamc->cd(7); c_datamc->cd(7)->SetLogy(1); h1_mc_he_m2->Draw("hist");     h1_data_he_m2->Draw("e same");    
  c_datamc->cd(8); c_datamc->cd(8)->SetLogy(1); h1_mc_he_mahi->Draw("hist");   h1_data_he_mahi->Draw("e same");    
  c_datamc->Print("plots/datamc.pdf");
  
  //
  TCanvas *c1 = ratioPlot(h1_mc_hb_mahi, h1_mc_hb_m2, "MC HB MAHI", "MC HB M2");
  c1->Print("plots/mcmc_hb.pdf");
  delete c1;
  TCanvas *c2 = ratioPlot(h1_data_hb_mahi, h1_data_hb_m2, "Data HB MAHI", "Data HB M2");
  c2->Print("plots/datadata_hb.pdf");
  delete c2;
  TCanvas *c3 = ratioPlot(h1_data_hb_mahi, h1_mc_hb_mahi, "Data HB MAHI", "MC HB MAHI");
  c3->Print("plots/datamc_hb_mahi.pdf");
  delete c3;
  TCanvas *c4 = ratioPlot(h1_data_hb_m2, h1_mc_hb_m2, "Data HB M2", "MC HB M2");
  c4->Print("plots/datamc_hb_m2.pdf");
  delete c4;
  TCanvas *c5 = ratioPlot(h1_mc_he_mahi, h1_mc_he_m2, "MC HE MAHI", "MC HE M2");
  c5->Print("plots/mcmc_he.pdf");
  delete c5;
  TCanvas *c6 = ratioPlot(h1_data_he_mahi, h1_data_he_m2, "Data HE MAHI", "Data HE M2");
  c6->Print("plots/datadata_he.pdf");
  delete c6;
  TCanvas *c7 = ratioPlot(h1_data_he_mahi, h1_mc_he_mahi, "Data HE MAHI", "MC HE MAHI");
  c7->Print("plots/datamc_he_mahi.pdf");
  delete c7;
  TCanvas *c8 = ratioPlot(h1_data_he_m2, h1_mc_he_m2, "Data HE M2", "MC HE M2");
  c8->Print("plots/datamc_he_m2.pdf");
  delete c8;

  //
  TCanvas *c_prof = new TCanvas("c_prof","c_prof",1800,800);
  c_prof->Divide(3,2);
  c_prof->cd(1);
  c_prof->cd(1)->SetLogz(1);
  h2_data_mahi->Draw("colz"); 
  c_prof->cd(2);
  c_prof->cd(2)->SetLogz(1);
  h2_data_m2->Draw("colz"); 
  c_prof->cd(3);
  TProfile *prof_h2_data_mahi  = h2_data_mahi->ProfileX();
  prof_h2_data_mahi->SetLineWidth(2);
  prof_h2_data_mahi->SetLineColor(kRed);
  prof_h2_data_mahi->SetMarkerColor(kRed);
  TProfile *prof_h2_data_m2  = h2_data_m2->ProfileX();
  prof_h2_data_m2->SetLineWidth(2);
  prof_h2_data_m2->SetLineColor(kBlack);
  prof_h2_data_m2->SetMarkerColor(kBlack);
  prof_h2_data_m2->SetMaximum(prof_h2_data_m2->GetMaximum()*1.4);
  prof_h2_data_m2->Draw("e");
  prof_h2_data_mahi->Draw("e same");
  c_prof->cd(4);
  c_prof->cd(4)->SetLogz(1);
  h2_mc_mahi->Draw("colz"); 
  c_prof->cd(5);
  c_prof->cd(5)->SetLogz(1);
  h2_mc_m2->Draw("colz"); 
  c_prof->cd(6);
  TProfile *prof_h2_mc_mahi  = h2_mc_mahi->ProfileX();
  prof_h2_mc_mahi->SetLineWidth(2);
  prof_h2_mc_mahi->SetLineColor(kRed);
  prof_h2_mc_mahi->SetMarkerColor(kRed);
  TProfile *prof_h2_mc_m2  = h2_mc_m2->ProfileX();
  prof_h2_mc_m2->SetLineWidth(2);
  prof_h2_mc_m2->SetLineColor(kBlack);
  prof_h2_mc_m2->SetMarkerColor(kBlack);
  prof_h2_mc_m2->SetMaximum(prof_h2_mc_m2->GetMaximum()*1.4);
  prof_h2_mc_m2->Draw("e");
  prof_h2_mc_mahi->Draw("e same");
  c_prof->Print("plots/prof.pdf");
  
  //
  TCanvas *c_occ_prof = new TCanvas("c_occ_prof","c_occ_prof",1800,800);
  c_occ_prof->Divide(3,2);
  c_occ_prof->cd(1);
  c_occ_prof->cd(1)->SetLogz(1);
  h2_data_occ_mahi->Draw("colz"); 
  c_occ_prof->cd(2);
  c_occ_prof->cd(2)->SetLogz(1);
  h2_data_occ_m2->Draw("colz"); 
  c_occ_prof->cd(3);
  TProfile *prof_h2_data_occ_mahi  = h2_data_occ_mahi->ProfileX();
  prof_h2_data_occ_mahi->SetLineWidth(2);
  prof_h2_data_occ_mahi->SetLineColor(kRed);
  prof_h2_data_occ_mahi->SetMarkerColor(kRed);
  TProfile *prof_h2_data_occ_m2  = h2_data_occ_m2->ProfileX();
  prof_h2_data_occ_m2->SetLineWidth(2);
  prof_h2_data_occ_m2->SetLineColor(kBlack);
  prof_h2_data_occ_m2->SetMarkerColor(kBlack);
  prof_h2_data_occ_m2->SetMaximum(prof_h2_data_occ_m2->GetMaximum()*1.4);
  prof_h2_data_occ_m2->Draw("e");
  prof_h2_data_occ_mahi->Draw("e same");
  c_occ_prof->cd(4);
  c_occ_prof->cd(4)->SetLogz(1);
  h2_mc_occ_mahi->Draw("colz"); 
  c_occ_prof->cd(5);
  c_occ_prof->cd(5)->SetLogz(1);
  h2_mc_occ_m2->Draw("colz"); 
  c_occ_prof->cd(6);
  TProfile *prof_h2_mc_occ_mahi  = h2_mc_occ_mahi->ProfileX();
  prof_h2_mc_occ_mahi->SetLineWidth(2);
  prof_h2_mc_occ_mahi->SetLineColor(kRed);
  prof_h2_mc_occ_mahi->SetMarkerColor(kRed);
  TProfile *prof_h2_mc_occ_m2  = h2_mc_occ_m2->ProfileX();
  prof_h2_mc_occ_m2->SetLineWidth(2);
  prof_h2_mc_occ_m2->SetLineColor(kBlack);
  prof_h2_mc_occ_m2->SetMarkerColor(kBlack);
  prof_h2_mc_occ_m2->SetMaximum(prof_h2_mc_occ_m2->GetMaximum()*1.4);
  prof_h2_mc_occ_m2->Draw("e");
  prof_h2_mc_occ_mahi->Draw("e same");
  c_occ_prof->Print("plots/prof_occ.pdf");

}


