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

float dR(float eta1, float phi1, float eta2, float phi2)
{
  return TMath::Sqrt((eta1-eta2)*(eta1-eta2)+(phi1-phi2)*(phi1-phi2));
}

float dPhi(float phi1, float phi2)
{ 
  float deltaPhi = phi1 - phi2;
  if(deltaPhi>TMath::Pi()) deltaPhi = 2*TMath::Pi() - deltaPhi;
  if(deltaPhi<-1*TMath::Pi()) deltaPhi = 2*TMath::Pi() + deltaPhi;
  return Abs(deltaPhi);
}

float dEta(float eta1, float eta2) 
{ 
  return eta1-eta2;
}

//int main(int argc, char *argv[])
int main()
{
  
  gErrorIgnoreLevel=kError+1;

  //hcal_tree_noise tree_nu("/hadoop/cms/store/user/jaehyeok/RelValNuGun/__GEN-SIM-RECO_20180317_231702/180318_062520/0000/results_mc_1.root");
  hcal_tree_noise tree_nu("/hadoop/cms/store/user/jaehyeok/RelValQCD_FlatPt_15_3000HS_13/__GEN-SIM-RECO_20180317_232731/180318_062802/0000/results_mc_1.root");
  cout << "Number of NuGun events: " << tree_nu.GetEntries() << endl;

  TH1D *h1_dR  = new TH1D("h1_dR", "h1_dR", 30, 0., 3.);
  TH2D *h2_dRvsPhi  = new TH2D("h2_dRvsPhi", "h2_dRvsPhi", 100, 0., 10., 100, -3.14, 3.14);
  TH2D *h2_dRvsEta  = new TH2D("h2_dRvsEta", "h2_dRvsEta", 100, 0., 10., 100, -3.5, 3.5);
  TH2D *h2_dEtavsdPhi  = new TH2D("h2_dEtavsdPhi", "h2_dEtavsdPhi", 100, -10., 10., 50, -3.14, 3.14);
  TH1D *h1_dPhi  = new TH1D("h1_dPhi", "h1_dPhi", 30, 0., 3.);
  TH2D *h2_JetPtvsSumE  = new TH2D("h2_JetPtvsSumE", "h2_JetPtvsSumE", 100, 0., 1000., 100, 0, 1000);
  TH1D *h1_ratio  = new TH1D("h1_ratio", "h1_ratio", 50, -2., 2.);
 
  // DEBUG 
  TH1D *h1_dR_  = new TH1D("h1_dR_", "h1_dR_", 100, 0., 10.);
  TH2D *h2_dRvsPhi_  = new TH2D("h2_dRvsPhi_", "h2_dRvsPhi_", 100, 0., 10., 100, -3.14, 3.14);
  TH2D *h2_dRvsEta_  = new TH2D("h2_dRvsEta_", "h2_dRvsEta_", 100, 0., 10., 100, -3.5, 3.5);

  // loop over trees
  for(unsigned int ientry=0; ientry<tree_nu.GetEntries(); ientry++)
  //for(unsigned int ientry=0; ientry<1000; ientry++)
  {
    tree_nu.GetEntry(ientry); 

    for(unsigned int ijet=0; ijet<tree_nu.JetPt().size(); ijet++)
    { 
      float esum_rh = 0;
      if(Abs(tree_nu.JetEta().at(ijet))<2 || Abs(tree_nu.JetEta().at(ijet))>2.5) continue; // Select jets well within HE
      if(tree_nu.JetPt().at(ijet)<30) continue;
      for(unsigned int irec=0; irec<tree_nu.HBHERecHitEnergy().size(); irec++)
      { 
        bool isHE = true;
        if(Abs(tree_nu.HBHERecHitIEta().at(irec))<16) isHE = false;
        if(Abs(tree_nu.HBHERecHitIEta().at(irec))==16 && tree_nu.HBHERecHitDepth().at(irec)!=4) isHE = false;
        if(!isHE) continue;
        //if(tree_nu.HBHERecHitEnergy().at(irec)<5) continue;
        
        float deltaR = dR(tree_nu.JetEta().at(ijet), tree_nu.JetPhi().at(ijet),
                          tree_nu.HBHERecHitEta().at(irec), tree_nu.HBHERecHitPhi().at(irec));
        FillTH1D(h1_dR, deltaR, 1); 
        FillTH2D(h2_dRvsPhi, deltaR, tree_nu.JetPhi().at(ijet), 1); 
        FillTH2D(h2_dRvsEta, deltaR, tree_nu.JetEta().at(ijet), 1); 
        FillTH2D(h2_dEtavsdPhi, 
                 dEta(tree_nu.JetEta().at(ijet), tree_nu.HBHERecHitEta().at(irec)), 
                 dPhi(tree_nu.JetPhi().at(ijet), tree_nu.HBHERecHitPhi().at(irec)), 1); 
        if(Abs(dEta(tree_nu.JetEta().at(ijet), tree_nu.HBHERecHitEta().at(irec)))<2) 
        FillTH1D(h1_dPhi, dPhi(tree_nu.JetPhi().at(ijet), tree_nu.HBHERecHitPhi().at(irec)), 1); 
        cout << tree_nu.JetEta().at(ijet) << " " 
             << tree_nu.JetPhi().at(ijet) << " " 
             << tree_nu.JetPt().at(ijet) << ", " 
             << tree_nu.HBHERecHitEta().at(irec) << " " 
             << tree_nu.HBHERecHitPhi().at(irec) << " " 
             << tree_nu.HBHERecHitDepth().at(irec) << " " 
             << tree_nu.HBHERecHitEnergy().at(irec) <<  " = " 
             << deltaR << endl; 

        if(deltaR>0.5) continue;
        float theta = 2*TMath::ATan(TMath::Exp(-1*tree_nu.HBHERecHitEta().at(irec)));  
        // theta is w.r.t. z axis
        esum_rh = esum_rh +  TMath::Sin(theta)*tree_nu.HBHERecHitEnergy().at(irec);
      }
      FillTH2D(h2_JetPtvsSumE, tree_nu.JetPt().at(ijet), esum_rh, 1); 
      FillTH1D(h1_ratio, esum_rh/tree_nu.JetPt().at(ijet), 1); 

      // DEBUGGING 
      for(unsigned int ijet2=0; ijet2<tree_nu.JetPt().size(); ijet2++) 
      { 
        if(ijet==ijet2) continue;
        if(tree_nu.JetPt().at(ijet2)<30) continue;
        float deltaR = dR(tree_nu.JetEta().at(ijet), tree_nu.JetPhi().at(ijet),
            tree_nu.JetEta().at(ijet2), tree_nu.JetPhi().at(ijet2));
        FillTH1D(h1_dR_, deltaR, 1); 
        FillTH2D(h2_dRvsPhi_, deltaR, tree_nu.JetPhi().at(ijet), 1); 
        FillTH2D(h2_dRvsEta_, deltaR, tree_nu.JetEta().at(ijet), 1); 
      }
    }
  }

  //
  //
  //
  TCanvas *c = new TCanvas("c","c",1200,1600);
  c->Divide(3,4); 
  c->cd(1); c->cd(1)->SetLogy(1); h1_dR->Draw("hist");
  c->cd(2); c->cd(2)->SetLogz(1); h2_dRvsPhi->Draw("colz");
  c->cd(3); c->cd(3)->SetLogz(1); h2_dRvsEta->Draw("colz");
  c->cd(4); c->cd(4)->SetLogy(1); h1_dR_->Draw("hist");
  c->cd(5); c->cd(5)->SetLogz(1); h2_dRvsPhi_->Draw("colz");
  c->cd(6); c->cd(6)->SetLogz(1); h2_dRvsEta_->Draw("colz");
  c->cd(7); c->cd(7)->SetLogz(1); h2_dEtavsdPhi->Draw("colz");
  c->cd(8); c->cd(8)->SetLogy(1); h1_dPhi->Draw("hist");
  c->cd(9); c->cd(9)->SetLogz(1); h2_JetPtvsSumE->Draw("colz");
  c->cd(10); c->cd(10)->SetLogy(10); h1_ratio->Draw("hist");
  c->Print("plots/depth.pdf");
  

}


