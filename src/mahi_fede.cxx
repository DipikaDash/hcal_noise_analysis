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
#include "TColor.h"

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

  // color 
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs] = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs] = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  // trees
  //hcal_tree_noise tree_chisq15("/Users/jaehyeok/scratch/HcalTupleMaker_316944.root");
  //hcal_tree_noise tree_chisq50("/Users/jaehyeok/scratch/HcalTupleMaker_316944_chisqhe50.root");
  hcal_tree_noise tree_chisq15("/home/users/jaehyeok/scratch/HcalTupleMaker_316944_chisqhe15.root");
  hcal_tree_noise tree_chisq50("/home/users/jaehyeok/scratch/HcalTupleMaker_316944_chisqhe50.root");
  
  // histograms 
  TH2D *h2_chisq15vschisq50_hb     = new TH2D("h2_chisq15vschisq50_hb",     "h2_chisq15vschisq50_hb",    100, 0, 400, 100, 0, 400);
  TH2D *h2_chisq15vschisq50_he     = new TH2D("h2_chisq15vschisq50_he",     "h2_chisq15vschisq50_he",    100, 0, 400, 100, 0, 400);
  TH2D *h2r_chisq15vschisq50_hb    = new TH2D("h2r_chisq15vschisq50_hb",    "h2r_chisq15vschisq50_hb",   100, 0, 400, 100, 0, 2);
  TH2D *h2r_chisq15vschisq50_he    = new TH2D("h2r_chisq15vschisq50_he",    "h2r_chisq15vschisq50_he",   100, 0, 400, 100, 0, 2);
  
  TH2D *h2r_chisq15_mahivsm0_hb    = new TH2D("h2r_chisq15_mahivsm0_hb",    "h2r_chisq15_mahivsm0_hb",   100, 0, 400, 100, 0, 2);
  TH2D *h2r_chisq15_mahivsm0_he    = new TH2D("h2r_chisq15_mahivsm0_he",    "h2r_chisq15_mahivsm0_he",   100, 0, 400, 100, 0, 2);
  TH2D *h2r_chisq50_mahivsm0_hb    = new TH2D("h2r_chisq50_mahivsm0_hb",    "h2r_chisq50_mahivsm0_hb",   100, 0, 400, 100, 0, 2);
  TH2D *h2r_chisq50_mahivsm0_he    = new TH2D("h2r_chisq50_mahivsm0_he",    "h2r_chisq50_mahivsm0_he",   100, 0, 400, 100, 0, 2);
  
  TH2D *h2_timevsenergy_chisq15_hb = new TH2D("h2_timevsenergy_chisq15_hb", "h2_timevsenergy_chisq15_hb", 100, 0, 400, 50,-12.5, 12.5);
  TH2D *h2_timevsenergy_chisq15_he = new TH2D("h2_timevsenergy_chisq15_he", "h2_timevsenergy_chisq15_he", 100, 0, 400, 50,-12.5, 12.5);
  TH2D *h2_timevsenergy_chisq50_hb = new TH2D("h2_timevsenergy_chisq50_hb", "h2_timevsenergy_chisq50_hb", 100, 0, 400, 50,-12.5, 12.5);
  TH2D *h2_timevsenergy_chisq50_he = new TH2D("h2_timevsenergy_chisq50_he", "h2_timevsenergy_chisq50_he", 100, 0, 400, 50,-12.5, 12.5);
 

  // loop over trees
  for(unsigned int ientry=0; ientry<tree_chisq15.GetEntries(); ientry++)
  {
    vector<float> hb_chisq50, he_chisq50;
    vector<float> hb_chisq15, he_chisq15;
    vector<float> hb0_chisq50, he0_chisq50;
    vector<float> hb0_chisq15, he0_chisq15;
    vector<float> hb_t_chisq15, he_t_chisq15;
    vector<float> hb_t_chisq50, he_t_chisq50;
   
    //if(ientry>5) continue;
    
    tree_chisq15.GetEntry(ientry); 
    
    //if(tree_chisq15.OfficialDecisionRun2L().at(0)==0) continue;
    
    for(unsigned int i=0; i<tree_chisq15.HBHERecHitEnergy().size(); i++)
    {
      if(tree_chisq15.HBHERecHitSevLvl().at(i)>11) continue;
      
      // HB
      if (  Abs(tree_chisq15.HBHERecHitIEta().at(i))<16 || 
           (Abs(tree_chisq15.HBHERecHitIEta().at(i))==16 &&  tree_chisq15.HBHERecHitDepth().at(i)<3))
      {
        hb_chisq15.push_back(tree_chisq15.HBHERecHitEnergy().at(i));
        hb0_chisq15.push_back(tree_chisq15.HBHERecHitEnergyRaw().at(i));
        hb_t_chisq15.push_back(tree_chisq15.HBHERecHitTime().at(i));
      }
      // HE
      else  
      {
        he_chisq15.push_back(tree_chisq15.HBHERecHitEnergy().at(i));
        he0_chisq15.push_back(tree_chisq15.HBHERecHitEnergyRaw().at(i));
        he_t_chisq15.push_back(tree_chisq15.HBHERecHitTime().at(i));
      }
    }
    
    //
    tree_chisq50.GetEntry(ientry);  
    for(unsigned int i=0; i<tree_chisq50.HBHERecHitEnergy().size(); i++)
    {
      if(tree_chisq50.HBHERecHitSevLvl().at(i)>11) continue;
      
      // HB
      if (  Abs(tree_chisq50.HBHERecHitIEta().at(i))<16 || 
           (Abs(tree_chisq50.HBHERecHitIEta().at(i))==16 &&  tree_chisq50.HBHERecHitDepth().at(i)<3))
      {
        hb_chisq50.push_back(tree_chisq50.HBHERecHitEnergy().at(i));
        hb0_chisq50.push_back(tree_chisq50.HBHERecHitEnergyRaw().at(i));
        hb_t_chisq50.push_back(tree_chisq50.HBHERecHitTime().at(i));
      }
      // HE HPD
      else  
      {
        he_chisq50.push_back(tree_chisq50.HBHERecHitEnergy().at(i));
        he0_chisq50.push_back(tree_chisq50.HBHERecHitEnergyRaw().at(i));
        he_t_chisq50.push_back(tree_chisq50.HBHERecHitTime().at(i));
      }
    }

    if( hb_chisq15.size()!=hb_chisq50.size() || 
        he_chisq15.size()!=he_chisq50.size() ) 
    {
      cout << "size mismatch!! " << endl; 
      cout << "hb_chisq15.size(): " << hb_chisq15.size() << endl; 
      cout << "hb_chisq50.size(): " << hb_chisq50.size() << endl; 
      cout << "he_chisq15.size(): " << he_chisq15.size() << endl; 
      cout << "he_chisq50.size(): " << he_chisq50.size() << endl; 
    } 

    // HB 
    for(unsigned int i=0; i<hb_chisq15.size(); i++) 
    { 
      //if(hb0_chisq15.at(i)<50) continue; 
      FillTH2D(h2_chisq15vschisq50_hb,      hb_chisq15.at(i), hb_chisq50.at(i), 1);
      FillTH2D(h2r_chisq15vschisq50_hb,     hb_chisq15.at(i), hb_chisq50.at(i)/hb_chisq15.at(i), 1);
      FillTH2D(h2r_chisq15_mahivsm0_hb,     hb0_chisq15.at(i), hb_chisq15.at(i)/hb0_chisq15.at(i), 1);
      FillTH2D(h2r_chisq50_mahivsm0_hb,     hb0_chisq50.at(i), hb_chisq50.at(i)/hb0_chisq50.at(i), 1);
      FillTH2D(h2_timevsenergy_chisq15_hb,  hb_chisq15.at(i), hb_t_chisq15.at(i), 1);
      FillTH2D(h2_timevsenergy_chisq50_hb,  hb_chisq50.at(i), hb_t_chisq50.at(i), 1);
    }
    // HE 
    for(unsigned int i=0; i<he_chisq15.size(); i++) 
    {
      //if(he_mahi.at(i)<5) continue; 
      FillTH2D(h2_chisq15vschisq50_he,      he_chisq15.at(i), he_chisq50.at(i), 1);
      FillTH2D(h2r_chisq15vschisq50_he,     he_chisq15.at(i), he_chisq50.at(i)/he_chisq15.at(i), 1);
      FillTH2D(h2r_chisq15_mahivsm0_he,     he0_chisq15.at(i), he_chisq15.at(i)/he0_chisq15.at(i), 1);
      FillTH2D(h2r_chisq50_mahivsm0_he,     he0_chisq50.at(i), he_chisq50.at(i)/he0_chisq50.at(i), 1);
      FillTH2D(h2_timevsenergy_chisq15_he,  he_chisq15.at(i), he_t_chisq15.at(i), 1);
      FillTH2D(h2_timevsenergy_chisq50_he,  he_chisq50.at(i), he_t_chisq50.at(i), 1);
    }
  }
 
  // cosmetics 
  h2cosmetic(h2_chisq15vschisq50_hb, "HB", "E(chisq15) [GeV]", "E(chisq50) [GeV]", "Events/bin");
  h2cosmetic(h2_chisq15vschisq50_he, "HE", "E(chisq15) [GeV]", "E(chisq50) [GeV]", "Events/bin");
  h2cosmetic(h2r_chisq15vschisq50_hb,"HB", "E(chisq15) [GeV]", "E(chisq50)/E(chisq15)", "Events/bin");
  h2cosmetic(h2r_chisq15vschisq50_he,"HE", "E(chisq15) [GeV]", "E(chisq50)/E(chisq15)", "Events/bin");
  h2cosmetic(h2r_chisq15_mahivsm0_hb, "HB", "E(M0) [GeV]", "E(chisq15)/E(M0)", "Events/bin");
  h2cosmetic(h2r_chisq15_mahivsm0_he, "HE", "E(M0) [GeV]", "E(chisq15)/E(M0)", "Events/bin");
  h2cosmetic(h2r_chisq50_mahivsm0_hb, "HB", "E(M0) [GeV]", "E(chisq50)/E(M0)", "Events/bin");
  h2cosmetic(h2r_chisq50_mahivsm0_he, "HE", "E(M0) [GeV]", "E(chisq50)/E(M0)", "Events/bin");
  
  // draw
  TCanvas *c_chisq15vschisq50 = new TCanvas("c_chisq15vschisq50","c_chisq15vschisq50",800,1600);
  c_chisq15vschisq50->Divide(2,4); 
  c_chisq15vschisq50->cd(1); c_chisq15vschisq50->cd(1)->SetLogz(1); h2_chisq15vschisq50_hb->Draw("colz");
  c_chisq15vschisq50->cd(2); c_chisq15vschisq50->cd(2)->SetLogz(1); h2_chisq15vschisq50_he->Draw("colz");
  c_chisq15vschisq50->cd(3); c_chisq15vschisq50->cd(3)->SetLogz(1); h2r_chisq15vschisq50_hb->Draw("colz");
  c_chisq15vschisq50->cd(4); c_chisq15vschisq50->cd(4)->SetLogz(1); h2r_chisq15vschisq50_he->Draw("colz");
  c_chisq15vschisq50->cd(5); c_chisq15vschisq50->cd(5)->SetLogz(1); h2r_chisq15_mahivsm0_hb->Draw("colz");
  c_chisq15vschisq50->cd(6); c_chisq15vschisq50->cd(6)->SetLogz(1); h2r_chisq15_mahivsm0_he->Draw("colz");
  c_chisq15vschisq50->cd(7); c_chisq15vschisq50->cd(7)->SetLogz(1); h2r_chisq50_mahivsm0_hb->Draw("colz");
  c_chisq15vschisq50->cd(8); c_chisq15vschisq50->cd(8)->SetLogz(1); h2r_chisq50_mahivsm0_he->Draw("colz");
  c_chisq15vschisq50->Print("plots/chisq15vschisq50.pdf");

  TCanvas *c_chisq15vschisq50_time = new TCanvas("c_chisq15vschisq50_time","c_chisq15vschisq50_time",800,800);
  c_chisq15vschisq50_time->Divide(2,2); 
  c_chisq15vschisq50_time->cd(1); c_chisq15vschisq50_time->cd(1)->SetLogz(1); h2_timevsenergy_chisq15_hb->Draw("colz");
  c_chisq15vschisq50_time->cd(2); c_chisq15vschisq50_time->cd(2)->SetLogz(1); h2_timevsenergy_chisq15_he->Draw("colz");
  c_chisq15vschisq50_time->cd(3); c_chisq15vschisq50_time->cd(3)->SetLogz(1); h2_timevsenergy_chisq50_hb->Draw("colz");
  c_chisq15vschisq50_time->cd(4); c_chisq15vschisq50_time->cd(4)->SetLogz(1); h2_timevsenergy_chisq50_he->Draw("colz");
  c_chisq15vschisq50_time->Print("plots/chisq15vschisq50_time.pdf");

}


