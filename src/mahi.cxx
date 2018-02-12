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
  
  gErrorIgnoreLevel=kError+1;

  //hcal_tree_noise tree("/home/users/jaehyeok/scratch/results_10_0_0.root");
  hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017E-v1_RAW_20180204_220953/180204_211018/0000/results_8*");

  TH1D *h1_hb  = new TH1D("h1_hb", "h1_hb", 100, 0., 2.);
  TH1D *h1_he  = new TH1D("h1_he", "h1_he", 100, 0., 2.);
  TH1D *h1_hep17  = new TH1D("h1_hep17", "h1_hep17", 100, 0., 2.);
  
  TH2D *h2_hb  = new TH2D("h2_hb", "h2_hb", 100, 0, 400, 100, 0, 400);
  TH2D *h2_he  = new TH2D("h2_he", "h2_he", 100, 0, 400, 100, 0, 400);
  TH2D *h2_hep17  = new TH2D("h2_hep17", "h2_hep17", 100, 0, 400, 100, 0, 400);

  TH2D *h2_r_hb  = new TH2D("h2_r_hb", "h2_r_hb", 100, 0, 400, 100, 0., 2.);
  TH2D *h2_r_hb_1  = new TH2D("h2_r_hb_1", "h2_r_hb_1", 100, 0, 20, 100, 0., 2.);
  TH2D *h2_r_he  = new TH2D("h2_r_he", "h2_r_he", 100, 0, 400, 100, 0., 2.);
  TH2D *h2_r_hep17  = new TH2D("h2_r_hep17", "h2_r_hep17", 100, 0, 400, 100, 0., 2.);
  TH2D *h2_r0_hb  = new TH2D("h2_r0_hb", "h2_r0_hb", 100, 0, 400, 100, 0., 2.);
  TH2D *h2_r0_he  = new TH2D("h2_r0_he", "h2_r0_he", 100, 0, 400, 100, 0., 2.);
  TH2D *h2_r0_hep17  = new TH2D("h2_r0_hep17", "h2_r0_hep17", 100, 0, 400, 100, 0., 2.);
 
  TH2D *h2_r2over0_hep17  = new TH2D("h2_r2over0_hep17", "h2_r2over0_hep17", 100, 0, 200, 100, 0., 2.);
  TH2D *h2_rmahiover0_hep17  = new TH2D("h2_rmahiover0_hep17", "h2_rmahiover0_hep17", 100, 0, 200, 100, 0., 2.);


  TH1D *h1_bx  = new TH1D("h1_bx", "h1_bx", 3600, 0, 3600);
  //TH2D *h2_he_test  = new TH2D("h2_he_test", "h2_he_test", 100, 0, 400, 100, 0, 400);
  //TH1D *h1_hep17_test  = new TH1D("h1_hep17_test", "h1_hep17_test", 100, 0., 2.);
  //TH1D *h1_hep17_test2  = new TH1D("h1_hep17_test2", "h1_hep17_test2", 100, 0., 2.);
  
  TH1D *h1_emahi_hb_1  = new TH1D("h1_emahi_hb_1", "h1_emahi_hb_1", 100, 0, 20);
  TH1D *h1_emahi_hb  = new TH1D("h1_emahi_hb", "h1_emahi_hb", 100, 0, 500);
  TH1D *h1_emahi_he  = new TH1D("h1_emahi_he", "h1_emahi_he", 100, 0, 500);
  TH1D *h1_emahi_hep17  = new TH1D("h1_emahi_hep17", "h1_emahi_hep17", 100, 0, 200);
  TH1D *h1_em2_hb_1  = new TH1D("h1_em2_hb_1", "h1_em2_hb_1", 100, 0, 20);
  TH1D *h1_em2_hb  = new TH1D("h1_em2_hb", "h1_em2_hb", 100, 0, 500);
  TH1D *h1_em2_he  = new TH1D("h1_em2_he", "h1_em2_he", 100, 0, 500);
  TH1D *h1_em2_hep17  = new TH1D("h1_em2_hep17", "h1_em2_hep17", 100, 0, 200);

  cout << "Number of events: " << tree.GetEntries() << endl;

  // loop over trees
  for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
  {
    vector<float> hb_mahi, he_mahi, hep17_mahi;
    vector<float> hb_m2, he_m2, hep17_m2;
    vector<float> hb_m0, he_m0, hep17_m0;
   
    //if(ientry>5) continue;
    
    tree.GetEntry(ientry); 

    //if(tree.OfficialDecisionRun2L().at(0)==0) continue;
   

    for(unsigned int i=0; i<tree.HBHERecHitEnergy().size(); i++)
    {
      
      if(tree.HBHERecHitSevLvl().at(i)>11) continue;

      //if (!(tree.HBHERecHitIEta().at(i)==17 || tree.HBHERecHitIEta().at(i)==18)) continue;
      
      // HB
      if (  Abs(tree.HBHERecHitIEta().at(i))<16 || 
           (Abs(tree.HBHERecHitIEta().at(i))==16 &&  tree.HBHERecHitDepth().at(i)<3))
      {
        hb_mahi.push_back(tree.HBHERecHitEnergy().at(i));
        hb_m0.push_back(tree.HBHERecHitEnergyRaw().at(i));
        hb_m2.push_back(tree.HBHERecHitEnergyAux().at(i));
      }
      // HEP17
      else if ( tree.HBHERecHitIEta().at(i)>0 && tree.HBHERecHitIPhi().at(i)>=63 && tree.HBHERecHitIPhi().at(i)<=66)  
      {
        hep17_mahi.push_back(tree.HBHERecHitEnergy().at(i));
        hep17_m0.push_back(tree.HBHERecHitEnergyRaw().at(i));
        hep17_m2.push_back(tree.HBHERecHitEnergyAux().at(i));
      }
      // HE HPD
      else  
      {
        he_mahi.push_back(tree.HBHERecHitEnergy().at(i));
        he_m0.push_back(tree.HBHERecHitEnergyRaw().at(i));
        he_m2.push_back(tree.HBHERecHitEnergyAux().at(i));
      }
    }
   
    //
    if( hb_m2.size()!=hb_mahi.size() || 
        he_m2.size()!=he_mahi.size() || 
        hep17_m2.size()!=hep17_mahi.size())  cout << "size mismatch!! " << endl; 
   

    for(unsigned int i=0; i<he_m2.size(); i++) 
    {
      if(he_mahi.at(i)<5) continue; 
      FillTH1D(h1_he, he_m2.at(i)/he_mahi.at(i), 1);
      FillTH2D(h2_he, he_mahi.at(i), he_m2.at(i), 1);
      FillTH2D(h2_r_he, he_mahi.at(i), he_m2.at(i)/he_mahi.at(i), 1);
      FillTH2D(h2_r0_he, he_mahi.at(i), he_m0.at(i)/he_mahi.at(i), 1);
      
      if(he_m2.at(i)/he_mahi.at(i)>0.58 && he_m2.at(i)/he_mahi.at(i)<0.66) 
      {
        FillTH1D(h1_bx, tree.bx(), 1); 
        //FillTH2D(h2_he_test, he_mahi.at(i), he_m0.at(i), 1);
        //FillTH1D(h1_he_test, he_m0.at(i)/he_mahi.at(i), 1);
      }
      //if(he_m2.at(i)/he_mahi.at(i)>0.52 && he_m2.at(i)/he_mahi.at(i)<0.56) 
      //  FillTH1D(h1_he_test2, he_m0.at(i)/he_mahi.at(i), 1);

      FillTH1D(h1_emahi_he, he_mahi.at(i), 1);
      FillTH1D(h1_em2_he, he_m2.at(i), 1);
    }

    for(unsigned int i=0; i<hb_m2.size(); i++) 
    { 
      FillTH2D(h2_r_hb_1, hb_mahi.at(i), hb_m2.at(i)/hb_mahi.at(i), 1);
      FillTH1D(h1_emahi_hb_1, hb_mahi.at(i), 1);
      FillTH1D(h1_em2_hb_1, hb_m2.at(i), 1);
      if(hb_mahi.at(i)<5) continue; 
      FillTH1D(h1_hb, hb_m2.at(i)/hb_mahi.at(i), 1); 
      //if(!(hb_m2.at(i)/hb_mahi.at(i)<0.8 && hb_mahi.at(i)>50)) continue; 
      FillTH2D(h2_hb, hb_mahi.at(i), hb_m2.at(i), 1);
      FillTH2D(h2_r_hb, hb_mahi.at(i), hb_m2.at(i)/hb_mahi.at(i), 1);
      FillTH2D(h2_r0_hb, hb_mahi.at(i), hb_m0.at(i)/hb_mahi.at(i), 1);
      //if(!(hb_m2.at(i)/hb_mahi.at(i)<0.8 && hb_mahi.at(i)>50)) FillTH1D(h1_emahi_hb, hb_mahi.at(i), 1);
      FillTH1D(h1_emahi_hb, hb_mahi.at(i), 1);
      FillTH1D(h1_em2_hb, hb_m2.at(i), 1);
    }
    for(unsigned int i=0; i<hep17_m2.size(); i++) 
    {
      FillTH2D(h2_r2over0_hep17, hep17_m0.at(i), hep17_m2.at(i)/hep17_m0.at(i), 1);
      FillTH2D(h2_rmahiover0_hep17, hep17_m0.at(i), hep17_mahi.at(i)/hep17_m0.at(i), 1);

      if(hep17_mahi.at(i)<5) continue; 
      FillTH1D(h1_hep17, hep17_m2.at(i)/hep17_mahi.at(i), 1); 
      FillTH2D(h2_hep17, hep17_mahi.at(i), hep17_m2.at(i), 1);
      FillTH2D(h2_r_hep17, hep17_mahi.at(i), hep17_m2.at(i)/hep17_mahi.at(i), 1);
      FillTH2D(h2_r0_hep17, hep17_mahi.at(i), hep17_m0.at(i)/hep17_mahi.at(i), 1);
      FillTH1D(h1_emahi_hep17, hep17_mahi.at(i), 1);
      FillTH1D(h1_em2_hep17, hep17_m2.at(i), 1);
      
//      if(hep17_m2.at(i)/hep17_mahi.at(i)>0.7 && hep17_m2.at(i)/hep17_mahi.at(i)<0.9) 
//      { 
//        FillTH1D(h1_bx, tree.bx(), 1);
//      }
    }
  }


  TCanvas *c = new TCanvas("c","c",1200,1600);
  c->Divide(3,4); 
  c->cd(1); h1_hb->Draw("hist");
  c->cd(2); h1_he->Draw("hist");
  c->cd(3); h1_hep17->Draw("hist");
  c->cd(4); c->cd(4)->SetLogz(1); h2_hb->SetStats(0); h2_hb->Draw("colz"); 
  c->cd(5); c->cd(5)->SetLogz(1); h2_he->SetStats(0); h2_he->Draw("colz");
  c->cd(6); c->cd(6)->SetLogz(1); h2_hep17->SetStats(0); h2_hep17->Draw("colz");
  c->cd(7); c->cd(7)->SetLogz(1); h2_r_hb->SetStats(0); h2_r_hb->Draw("colz"); //prof_h2_r_hb->Draw("same");
  c->cd(8); c->cd(8)->SetLogz(1); h2_r_he->SetStats(0);  h2_r_he->Draw("colz");
  c->cd(9); c->cd(9)->SetLogz(1); h2_r_hep17->SetStats(0); h2_r_hep17->Draw("colz");
  c->cd(10); c->cd(10)->SetLogz(1); h2_r0_hb->SetStats(0); h2_r0_hb->Draw("colz");
  c->cd(11); c->cd(11)->SetLogz(1); h2_r0_he->SetStats(0); h2_r0_he->Draw("colz");
  c->cd(12); c->cd(12)->SetLogz(1); h2_r0_hep17->SetStats(0); h2_r0_hep17->Draw("colz");
  c->Print("plots/mahi.pdf");
  
  TCanvas *c_bx = new TCanvas("c_bx","c_bx",1200,400);
  c_bx->cd(1); h1_bx->Draw("hist");
  c_bx->Print("plots/bx.C");
  c_bx->Print("plots/bx.pdf");
  
  TCanvas *c_test = new TCanvas("c_test","c_test",800,400);
  c_test->Divide(2,1); 
  c_test->cd(1); c_test->cd(1)->SetLogz(1); h2_r2over0_hep17->SetStats(0); h2_r2over0_hep17->Draw("colz");
  c_test->cd(2); c_test->cd(2)->SetLogz(1); h2_rmahiover0_hep17->SetStats(0); h2_rmahiover0_hep17->Draw("colz");
  c_test->Print("plots/test.pdf");

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
  c_e->cd(3); c_e->cd(3)->SetLogy(1); 
  h1_emahi_hep17->SetLineColor(kRed);
  h1_emahi_hep17->DrawNormalized("hist");
  h1_em2_hep17->DrawNormalized("hist same");
  c_e->Print("plots/energy.pdf");

  TProfile *prof_h2_r_hb_1  = h2_r_hb_1->ProfileX();
  TCanvas *c_prof = new TCanvas("c_prof","c_prof",800,400);
  c_prof->Divide(2,1);
  c_prof->cd(1);
  h1_emahi_hb_1->SetLineWidth(3);
  h1_em2_hb_1->SetLineWidth(3);
  h1_emahi_hb_1->SetLineColor(kRed);
  h1_emahi_hb_1->DrawNormalized("hist");
  h1_em2_hb_1->DrawNormalized("hist same");
  c_prof->cd(2);
  prof_h2_r_hb_1->SetLineWidth(3);
  prof_h2_r_hb_1->SetLineColor(kRed);
  prof_h2_r_hb_1->GetYaxis()->SetRangeUser(0.7,2.0);
  prof_h2_r_hb_1->Draw("hist");
  c_prof->Print("plots/hb_prof_energy.pdf");

  cout << "mahi: " << h1_emahi_hb_1->GetMean() << endl;
  cout << "m2  : " << h1_em2_hb_1->GetMean() << endl;

}


