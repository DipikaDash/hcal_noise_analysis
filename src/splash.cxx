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

  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs] =   { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs] =  { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

/*
  // from: https://root.cern.ch/phpBB3/viewtopic.php?t=18987
  const UInt_t Number = 5;
  Double_t Red[Number]    = { 1.00, 0.00, 1.00, 1.00, 0.00};
  Double_t Green[Number]  = { 0.00, 1.00, 1.00, 0.00, 0.00};
  Double_t Blue[Number]   = { 0.00, 0.00, 1.00, 1.00, 1.00};
  Double_t Length[Number] = { 0.00, 0.25, 0.50, 0.75, 1.00 };
  Int_t nb=255;
  TColor::CreateGradientColorTable(Number,Length,Blue,Green,Red,nb);
*/

  hcal_tree_noise tree("/home/users/jaehyeok/HCAL/ntupler/files/splashes2018/HcalTupleMaker_splashes_newvar_skim.root"); 

  cout << "Number of events: " << tree.GetEntries() << endl;

  // loop over trees
  for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
  {

    // HBHERecHits
    TH2D *h2_ietavsiphi_energy[8];
    TH2D *h2_ietavsiphi_time[8];
    TH2D *h2_ietavstime[8];
    TH2D *h2_ietavsenergy[8];
    TH2D *h2_iphivstime[8];
    TH2D *h2_iphivsenergy[8];

    for(int i=0; i<8; i++)
    {
      h2_ietavsiphi_energy[i] = new TH2D(Form("h2_ietavsiphi_energy_depth%i",i), Form("h2_ietavsiphi_energy_depth%i",i), 83,-41.5,41.5,72,0.5,72.5);
      h2_ietavsiphi_time[i]   = new TH2D(Form("h2_ietavsiphi_time_depth%i",i),   Form("h2_ietavsiphi_time_depth%i",i),   83,-41.5,41.5,72,0.5,72.5);
      h2_ietavstime[i]        = new TH2D(Form("h2_ietavstime_depth%i",i),        Form("h2_ietavstime_depth%i",i),        83,-41.5,41.5,150,-50,100);
      h2_ietavsenergy[i]      = new TH2D(Form("h2_ietavsenergy_depth%i",i),      Form("h2_ietavsenergy_depth%i",i),      83,-41.5,41.5,100,0,3000);
      h2_iphivstime[i]        = new TH2D(Form("h2_iphivstime_depth%i",i),        Form("h2_iphivstime_depth%i",i),        72,0.5,72.5,150,-50,100);
      h2_iphivsenergy[i]      = new TH2D(Form("h2_iphivsenergy_depth%i",i),      Form("h2_iphivsenergy_depth%i",i),      72,0.5,72.5,100,0,3000);
    }

    // Digi 
    TH2D *h2digi_ietavsiphi_energy[8];
    TH2D *h2digi_ietavsiphi_time[8];
    TH2D *h2digi_ietavstime[8];
    TH2D *h2digi_ietavsenergy[8];
    TH2D *h2digi_iphivstime[8];
    TH2D *h2digi_iphivsenergy[8];

    for(int i=0; i<8; i++)
    {
      h2digi_ietavsiphi_energy[i] = new TH2D(Form("h2digi_ietavsiphi_energy_depth%i",i), Form("h2digi_ietavsiphi_energy_depth%i",i), 83,-41.5,41.5,72,0.5,72.5);
      h2digi_ietavsiphi_time[i]   = new TH2D(Form("h2digi_ietavsiphi_time_depth%i",i),   Form("h2digi_ietavsiphi_time_depth%i",i),   83,-41.5,41.5,72,0.5,72.5);
      h2digi_ietavstime[i]        = new TH2D(Form("h2digi_ietavstime_depth%i",i),        Form("h2digi_ietavstime_depth%i",i),        83,-41.5,41.5,200,0,200);
      h2digi_ietavsenergy[i]      = new TH2D(Form("h2digi_ietavsenergy_depth%i",i),      Form("h2digi_ietavsenergy_depth%i",i),      83,-41.5,41.5,100,0,10000);
      h2digi_iphivstime[i]        = new TH2D(Form("h2digi_iphivstime_depth%i",i),        Form("h2digi_iphivstime_depth%i",i),        72,0.5,72.5,200,0,200);
      h2digi_iphivsenergy[i]      = new TH2D(Form("h2digi_iphivsenergy_depth%i",i),      Form("h2digi_iphivsenergy_depth%i",i),      72,0.5,72.5,100,0,10000);
    }


    //if(ientry>0) continue;

    tree.GetEntry(ientry); 

    //
    // HBHERechit
    //
    for(unsigned int i=0; i<tree.HBHERecHitEnergy().size(); i++)
    {
        FillTH2D(h2_ietavsiphi_energy[0], tree.HBHERecHitIEta().at(i), tree.HBHERecHitIPhi().at(i), tree.HBHERecHitEnergy().at(i));
        if(Abs(tree.HBHERecHitTime().at(i))<10000) FillTH2D(h2_ietavsiphi_time[0],   tree.HBHERecHitIEta().at(i), tree.HBHERecHitIPhi().at(i), tree.HBHERecHitTime().at(i));
        FillTH2D(h2_ietavstime[0],        tree.HBHERecHitIEta().at(i), tree.HBHERecHitTime().at(i), 1);
        FillTH2D(h2_ietavsenergy[0],      tree.HBHERecHitIEta().at(i), tree.HBHERecHitEnergy().at(i), 1);
        FillTH2D(h2_iphivstime[0],        tree.HBHERecHitIPhi().at(i), tree.HBHERecHitTime().at(i), 1);
        FillTH2D(h2_iphivsenergy[0],      tree.HBHERecHitIPhi().at(i), tree.HBHERecHitEnergy().at(i), 1); 
        
        FillTH2D(h2_ietavsiphi_energy[tree.HBHERecHitDepth().at(i)], tree.HBHERecHitIEta().at(i), tree.HBHERecHitIPhi().at(i), tree.HBHERecHitEnergy().at(i));
        if(Abs(tree.HBHERecHitTime().at(i))<10000) FillTH2D(h2_ietavsiphi_time[tree.HBHERecHitDepth().at(i)],   tree.HBHERecHitIEta().at(i), tree.HBHERecHitIPhi().at(i), tree.HBHERecHitTime().at(i));
        FillTH2D(h2_ietavstime[tree.HBHERecHitDepth().at(i)],        tree.HBHERecHitIEta().at(i), tree.HBHERecHitTime().at(i), 1);
        FillTH2D(h2_ietavsenergy[tree.HBHERecHitDepth().at(i)],      tree.HBHERecHitIEta().at(i), tree.HBHERecHitEnergy().at(i), 1);
        FillTH2D(h2_iphivstime[tree.HBHERecHitDepth().at(i)],        tree.HBHERecHitIPhi().at(i), tree.HBHERecHitTime().at(i), 1);
        FillTH2D(h2_iphivsenergy[tree.HBHERecHitDepth().at(i)],      tree.HBHERecHitIPhi().at(i), tree.HBHERecHitEnergy().at(i), 1); 
    }

    for(int i=0; i<8; i++)
    {
      h2cosmetic(h2_ietavsiphi_energy[i], "IEta vs IPhi (Energy in z)", "IEta", "IPhi", "Energy");
      h2cosmetic(h2_ietavsiphi_time[i],   "IEta vs IPhi (Time in z)", "IEta", "IPhi", "Time [ns]");
      h2cosmetic(h2_ietavstime[i],        "IEta vs Time", "IEta", "Time [ns]", "Rechits/bin");
      h2cosmetic(h2_ietavsenergy[i],      "IEta vs Energy", "IEta", "Energy [GeV]", "Rechits/bin");
      h2cosmetic(h2_iphivstime[i],        "IPhi vs Time", "IPhi", "Time [ns]", "Rechits/bin");
      h2cosmetic(h2_iphivsenergy[i],      "IPhi vs Energy", "IPhi", "Energy [GeV]", "Rechits/bin");
    }

    // draw 
    for(int i=0; i<8; i++)
    {
      TCanvas *c = new TCanvas("c","c",800,900);
      c->Divide(2,3); 
      c->cd(1); 
      c->cd(1)->SetLogz(1); 
      h2_ietavstime[i]->Draw("colz");
      c->cd(2); 
      c->cd(2)->SetLogz(1); 
      h2_iphivstime[i]->Draw("colz");
      c->cd(3); 
      c->cd(3)->SetLogz(1); 
      h2_ietavsenergy[i]->Draw("colz");
      c->cd(4); 
      c->cd(4)->SetLogz(1); 
      h2_iphivsenergy[i]->Draw("colz");
      c->cd(5); 
      c->cd(5)->SetLogz(1); 
      h2_ietavsiphi_energy[i]->Draw("colz");
      c->cd(6); 
      c->cd(6)->SetLogz(0); 
      h2_ietavsiphi_time[i]->Draw("colz");
      c->Print(Form("plots/splash_%i_%i_%i_depth%i.pdf",tree.run(), tree.ls(), tree.event(), i));
      delete c;
    }
    
    // 
    // Digis QIE11+QIE8 
    // 
    for(unsigned int i=0; i<tree.QIE11DigiIEta().size(); i++)
    { 
      // Sum over 8 TS
      float totalFC = 0;
      float time = 0; 
      for(int its=0; its<8; its++) 
      { 
         totalFC = totalFC + tree.QIE11DigiFC().at(i).at(its)/1000.;
         time = time + its*tree.QIE11DigiFC().at(i).at(its)*25./1000.;
      } 
      time = time / totalFC; 

      FillTH2D(h2digi_ietavsiphi_energy[0], tree.QIE11DigiIEta().at(i), tree.QIE11DigiIPhi().at(i), totalFC);
      FillTH2D(h2digi_ietavsiphi_time[0],   tree.QIE11DigiIEta().at(i), tree.QIE11DigiIPhi().at(i), time);
      FillTH2D(h2digi_ietavstime[0],        tree.QIE11DigiIEta().at(i), time, 1);
      FillTH2D(h2digi_ietavsenergy[0],      tree.QIE11DigiIEta().at(i), totalFC, 1);
      FillTH2D(h2digi_iphivstime[0],        tree.QIE11DigiIPhi().at(i), time, 1);
      FillTH2D(h2digi_iphivsenergy[0],      tree.QIE11DigiIPhi().at(i), totalFC, 1); 

      FillTH2D(h2digi_ietavsiphi_energy[tree.QIE11DigiDepth().at(i)], tree.QIE11DigiIEta().at(i), tree.QIE11DigiIPhi().at(i), totalFC);
      FillTH2D(h2digi_ietavsiphi_time[tree.QIE11DigiDepth().at(i)],   tree.QIE11DigiIEta().at(i), tree.QIE11DigiIPhi().at(i), time);
      FillTH2D(h2digi_ietavstime[tree.QIE11DigiDepth().at(i)],        tree.QIE11DigiIEta().at(i), time, 1);
      FillTH2D(h2digi_ietavsenergy[tree.QIE11DigiDepth().at(i)],      tree.QIE11DigiIEta().at(i), totalFC, 1);
      FillTH2D(h2digi_iphivstime[tree.QIE11DigiDepth().at(i)],        tree.QIE11DigiIPhi().at(i), time, 1);
      FillTH2D(h2digi_iphivsenergy[tree.QIE11DigiDepth().at(i)],      tree.QIE11DigiIPhi().at(i), totalFC, 1); 
    } 
    //
    for(unsigned int i=0; i<tree.HBHEDigiIEta().size(); i++)
    { 
      // Sum over 8 TS
      float totalFC = 0;
      float time = 0; 
      for(int its=0; its<8; its++) 
      { 
         totalFC = totalFC + tree.HBHEDigiAllFC().at(i).at(its)/1000.;
         time = time + its*tree.HBHEDigiAllFC().at(i).at(its)*25./1000.;
      } 
      time = time / totalFC; 

      FillTH2D(h2digi_ietavsiphi_energy[0], tree.HBHEDigiIEta().at(i), tree.HBHEDigiIPhi().at(i), totalFC);
      FillTH2D(h2digi_ietavsiphi_time[0],   tree.HBHEDigiIEta().at(i), tree.HBHEDigiIPhi().at(i), time);
      FillTH2D(h2digi_ietavstime[0],        tree.HBHEDigiIEta().at(i), time, 1);
      FillTH2D(h2digi_ietavsenergy[0],      tree.HBHEDigiIEta().at(i), totalFC, 1);
      FillTH2D(h2digi_iphivstime[0],        tree.HBHEDigiIPhi().at(i), time, 1);
      FillTH2D(h2digi_iphivsenergy[0],      tree.HBHEDigiIPhi().at(i), totalFC, 1); 

      FillTH2D(h2digi_ietavsiphi_energy[tree.HBHEDigiDepth().at(i)], tree.HBHEDigiIEta().at(i), tree.HBHEDigiIPhi().at(i), totalFC);
      FillTH2D(h2digi_ietavsiphi_time[tree.HBHEDigiDepth().at(i)],   tree.HBHEDigiIEta().at(i), tree.HBHEDigiIPhi().at(i), time);
      FillTH2D(h2digi_ietavstime[tree.HBHEDigiDepth().at(i)],        tree.HBHEDigiIEta().at(i), time, 1);
      FillTH2D(h2digi_ietavsenergy[tree.HBHEDigiDepth().at(i)],      tree.HBHEDigiIEta().at(i), totalFC, 1);
      FillTH2D(h2digi_iphivstime[tree.HBHEDigiDepth().at(i)],        tree.HBHEDigiIPhi().at(i), time, 1);
      FillTH2D(h2digi_iphivsenergy[tree.HBHEDigiDepth().at(i)],      tree.HBHEDigiIPhi().at(i), totalFC, 1); 
    } 
    //
    for(int i=0; i<8; i++)
    {
      h2cosmetic(h2digi_ietavsiphi_energy[i], "IEta vs IPhi (sum pC 8TS in z)", "IEta", "IPhi", "sum pC 8TS");
      h2cosmetic(h2digi_ietavsiphi_time[i],   "IEta vs IPhi (Time in z)", "IEta", "IPhi", "Time [ns]");
      h2cosmetic(h2digi_ietavstime[i],        "IEta vs Time", "IEta", "Time [ns]", "channels/bin");
      h2cosmetic(h2digi_ietavsenergy[i],      "IEta vs sum pC 8TS", "IEta", "sum pC 8TS", "channels/bin");
      h2cosmetic(h2digi_iphivstime[i],        "IPhi vs Time", "IPhi", "Time [ns]", "channels/bin");
      h2cosmetic(h2digi_iphivsenergy[i],      "IPhi vs sum pC 8TS", "IPhi", "sum pC 8TS", "channels/bin");
    }

    // draw 
    for(int i=0; i<8; i++)
    {
      TCanvas *c = new TCanvas("c","c",800,900);
      c->Divide(2,3); 
      c->cd(1); 
      c->cd(1)->SetLogz(1); 
      h2digi_ietavstime[i]->Draw("colz");
      c->cd(2); 
      c->cd(2)->SetLogz(1); 
      h2digi_iphivstime[i]->Draw("colz");
      c->cd(3); 
      c->cd(3)->SetLogz(1); 
      h2digi_ietavsenergy[i]->Draw("colz");
      c->cd(4); 
      c->cd(4)->SetLogz(1); 
      h2digi_iphivsenergy[i]->Draw("colz");
      c->cd(5); 
      c->cd(5)->SetLogz(1); 
      h2digi_ietavsiphi_energy[i]->Draw("colz");
      c->cd(6); 
      c->cd(6)->SetLogz(0); 
      h2digi_ietavsiphi_time[i]->Draw("colz");
      c->Print(Form("plots/splash_digi_%i_%i_%i_depth%i.pdf",tree.run(), tree.ls(), tree.event(), i));
      delete c;
    }

  }


}
