#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>

#include "TFile.h"
#include "TH2D.h"
#include "TStyle.h"
#include "TCanvas.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

using namespace std; 

void compare(TString sample1, TString sample2);


int main()
{ 
  gErrorIgnoreLevel=kError+1;
  
  //TString sample1 = "/hadoop/cms/store/user/jaehyeok/MET/mahiOFF_RelVal_met2017F-v1_RECO_20180131_101858/180131_091915/0000/results_*.root"; 
  //TString sample2 = "/hadoop/cms/store/user/jaehyeok/MET/mahiON_RelVal_met2017F-v1_RECO_20180131_101928/180131_091944/0000/results_*.root";
  
  //TString sample1 = "/hadoop/cms/store/user/jaehyeok/SingleMuon/mahiOFF_RelVal_sigMu2017F-v1_RECO_20180131_102000/180131_092017/0000/results_*root";
  //TString sample2 = "/hadoop/cms/store/user/jaehyeok/SingleMuon/mahiON_RelVal_sigMu2017F-v1_RECO_20180131_102039/180131_092056/0000/results_*.root"; 
  
  //TString sample1 = "/hadoop/cms/store/user/jaehyeok/RelValQCD_FlatPt_15_3000HS_13/mahiON-v1_GEN-SIM-RECO_20180131_093650/180131_083706/0000/results_mc_1*root";
  //TString sample2 = "/hadoop/cms/store/user/jaehyeok/RelValQCD_FlatPt_15_3000HS_13/mahiOFF-v1_GEN-SIM-RECO_20180131_093623/180131_083639/0000/results_mc_1*.root"; 
  
  TString sample1 = "/hadoop/cms/store/user/jaehyeok/RelValQCD_FlatPt_15_3000HS_13/HS1M-v1_GEN-SIM-RECO_20180131_093553/180131_083609/0000/results_mc_1*root";
  TString sample2 = "/hadoop/cms/store/user/jaehyeok/RelValQCD_FlatPt_15_3000HS_13/HECOLL-v1_GEN-SIM-RECO_20180131_093501/180131_083527/0000/results_mc_1*.root"; 
  
  
  compare(sample1, sample2);
}

void compare(TString sample1, TString sample2)
{
    hcal_tree_noise tree1(sample1.Data());
    hcal_tree_noise tree2(sample1.Data());

    cout << "Analyzing: " << endl; 
    cout << sample1 << ": " <<  tree1.GetEntries() << " events" << endl;
    cout << sample2 << ": " <<  tree2.GetEntries() << " events" << endl;
  
    //
    TH1D *h1_1_hpd         = new TH1D("h1_1_hpd",      "h1_1_hpd",      49, -0.5, 48.5);//19, -0.5, 18.5);
    TH1D *h1_1_hpdother    = new TH1D("h1_1_hpdother", "h1_1_hpdother", 19, -0.5, 18.5);
    TH1D *h1_1_r45         = new TH1D("h1_1_r45",      "h1_1_r45",       2, -0.5,  1.5);
    TH1D *h1_1_numiso      = new TH1D("h1_1_numiso",   "h1_1_numiso",   51, -0.5, 50.5);
    TH1D *h1_1_isosume     = new TH1D("h1_1_isosume",  "h1_1_isosume",  120, 0., 3000.);
    TH1D *h1_1_isosumet    = new TH1D("h1_1_isosumet", "h1_1_isosumet", 200, 0., 2500.);
    TH1D *h1_1_hbhe2l      = new TH1D("h1_1_hbhe2l",   "h1_1_hbhe2l",   2, -0.5,  1.5);
    TH1D *h1_1_hbheiso     = new TH1D("h1_1_hbheiso",  "h1_1_hbheiso",  2, -0.5,  1.5);

    TH1D *h1_2_hpd         = new TH1D("h1_2_hpd",      "h1_2_hpd",      49, -0.5, 48.5);//19, -0.5, 18.5);
    TH1D *h1_2_hpdother    = new TH1D("h1_2_hpdother", "h1_2_hpdother", 19, -0.5, 18.5);
    TH1D *h1_2_r45         = new TH1D("h1_2_r45",      "h1_2_r45",       2, -0.5,  1.5);
    TH1D *h1_2_numiso      = new TH1D("h1_2_numiso",   "h1_2_numiso",   51, -0.5, 50.5);
    TH1D *h1_2_isosume     = new TH1D("h1_2_isosume",  "h1_2_isosume",  120, 0., 3000.);
    TH1D *h1_2_isosumet    = new TH1D("h1_2_isosumet", "h1_2_isosumet", 200, 0., 2500.);
    TH1D *h1_2_hbhe2l      = new TH1D("h1_2_hbhe2l",   "h1_2_hbhe2l",   2, -0.5,  1.5);
    TH1D *h1_2_hbheiso     = new TH1D("h1_2_hbheiso",  "h1_2_hbheiso",  2, -0.5,  1.5);

    // loop over tree1
    for(unsigned int ientry=0; ientry<tree1.GetEntries(); ientry++)
    {
        tree1.GetEntry(ientry); 
        
        FillTH1D(h1_1_hpd,        tree1.HPDHits().at(0),                  1);
        FillTH1D(h1_1_hpdother,   tree1.HPDNoOtherHits().at(0),           1);
        FillTH1D(h1_1_r45,        tree1.HasBadRBXRechitR45Loose().at(0),  1);
        FillTH1D(h1_1_numiso,     tree1.NumIsolatedNoiseChannels().at(0), 1);
        FillTH1D(h1_1_isosume,    tree1.IsolatedNoiseSumE().at(0),        1);
        FillTH1D(h1_1_isosumet,   tree1.IsolatedNoiseSumEt().at(0),       1);
        FillTH1D(h1_1_hbhe2l,     tree1.OfficialDecisionRun2L().at(0),    1);
        FillTH1D(h1_1_hbheiso,    tree1.IsoNoiseFilterDecision().at(0),   1);
    } 

    h1cosmetic(h1_1_hpd,       "# HPD hits",                     kBlue, 1, 0, "# HPD hits");
    h1cosmetic(h1_1_hpdother,  "# HPD other hits",               kBlue, 1, 0, "# HPD other hits");
    h1cosmetic(h1_1_r45,       "R45 decision",                   kBlue, 1, 0, "R45 filter decision");
    h1cosmetic(h1_1_numiso,    "# isolated channels",            kBlue, 1, 0, "# isolated channels");
    h1cosmetic(h1_1_isosume,   "Sum E of isolated channels",     kBlue, 1, 0, "Sum E of isolated channels [GeV]");
    h1cosmetic(h1_1_isosumet,  "Sum ET of isolated channels",    kBlue, 1, 0, "Sum ET of isolated channels [GeV]");
    h1cosmetic(h1_1_hbhe2l,    "Decision of HBHE Run2 Loose WP", kBlue, 1, 0, "Decision of HBHE Run2 Loose WP");
    h1cosmetic(h1_1_hbheiso,   "Decision of HBHEIso filter",     kBlue, 1, 0, "Decision of HBHEIso filter");

    // loop over tree2
    for(unsigned int ientry=0; ientry<tree2.GetEntries(); ientry++)
    {
      tree2.GetEntry(ientry); 

      FillTH1D(h1_2_hpd,        tree2.HPDHits().at(0),                  1);
      FillTH1D(h1_2_hpdother,   tree2.HPDNoOtherHits().at(0),           1);
      FillTH1D(h1_2_r45,        tree2.HasBadRBXRechitR45Loose().at(0),  1);
      FillTH1D(h1_2_numiso,     tree2.NumIsolatedNoiseChannels().at(0), 1);
      FillTH1D(h1_2_isosume,    tree2.IsolatedNoiseSumE().at(0),        1);
      FillTH1D(h1_2_isosumet,   tree2.IsolatedNoiseSumEt().at(0),       1);
      FillTH1D(h1_2_hbhe2l,     tree2.OfficialDecisionRun2L().at(0),    1);
      FillTH1D(h1_2_hbheiso,    tree2.IsoNoiseFilterDecision().at(0),   1);
    } 

    h1cosmetic(h1_2_hpd,       "# HPD hits",                     kRed, 1, 0, "# HPD hits");
    h1cosmetic(h1_2_hpdother,  "# HPD other hits",               kRed, 1, 0, "# HPD other hits");
    h1cosmetic(h1_2_r45,       "R45 decision",                   kRed, 1, 0, "R45 filter decision");
    h1cosmetic(h1_2_numiso,    "# isolated channels",            kRed, 1, 0, "# isolated channels");
    h1cosmetic(h1_2_isosume,   "Sum E of isolated channels",     kRed, 1, 0, "Sum E of isolated channels [GeV]");
    h1cosmetic(h1_2_isosumet,  "Sum ET of isolated channels",    kRed, 1, 0, "Sum ET of isolated channels [GeV]");
    h1cosmetic(h1_2_hbhe2l,    "Decision of HBHE Run2 Loose WP", kRed, 1, 0, "Decision of HBHE Run2 Loose WP");
    h1cosmetic(h1_2_hbheiso,   "Decision of HBHEIso filter",     kRed, 1, 0, "Decision of HBHEIso filter");

    TCanvas *c = new TCanvas("c","c",900,900); 
    c->Divide(3,3);
    c->cd(1); c->cd(1)->SetLogy(1); 
    h1_1_hpd->Draw("ep");
    h1_2_hpd->Draw("ep same");
    c->cd(2); c->cd(2)->SetLogy(1); 
    h1_1_hpdother->Draw("ep");
    h1_2_hpdother->Draw("ep same");
    c->cd(3); c->cd(3)->SetLogy(1); 
    h1_1_r45->SetMinimum(1);
    h1_1_r45->Draw("ep");
    h1_2_r45->Draw("ep same");
    c->cd(4); c->cd(4)->SetLogy(1); 
    h1_1_numiso->Draw("ep");
    h1_2_numiso->Draw("ep same");
    c->cd(5); c->cd(5)->SetLogy(1); 
    h1_1_isosume->Draw("ep");
    h1_2_isosume->Draw("ep same");
    c->cd(6); c->cd(6)->SetLogy(1); 
    h1_1_isosumet->Draw("ep");
    h1_2_isosumet->Draw("ep same");
    c->cd(7); c->cd(7)->SetLogy(1); 
    h1_1_hbhe2l->Draw("ep");
    //h1_2_hbhe2l->Draw("ep same");
    c->cd(8); c->cd(8)->SetLogy(1); 
    h1_1_hbheiso->Draw("ep");
    //h1_2_hbheiso->Draw("ep same");
    c->Print("plots/hbhe.pdf");
    
    for(int i=1; i<20; i++)
    { 
      cout << i << " :: " << h1_1_hpd->GetBinContent(i) << " " << h1_2_hpd->GetBinContent(i) << endl;
    }
}
