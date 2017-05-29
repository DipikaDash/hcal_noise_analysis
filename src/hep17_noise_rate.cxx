#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>

#include "TFile.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

using namespace std; 

//int main(int argc, char *argv[])
int main()
{
    gStyle->SetOptStat(111111);

    hcal_tree_noise tree("/Users/jaehyeok/Research/cms/UCSB/HCAL/Noise/ntuples/results_run291781.root");

    cout << "Analyzing " << tree.GetEntries() << " events" << endl;

      TH1D *h1_RBXHits_17   = new TH1D("h1_RBXHits_17", "h1_RBXHits_17", 72, 0, 72);
      TH1D *h1_RBXHits_16   = new TH1D("h1_RBXHits_16", "h1_RBXHits_16", 72, 0, 72);
      TH1D *h1_HPDHits_17   = new TH1D("h1_HPDHits_17", "h1_HPDHits_17", 20, 0, 20);
      TH1D *h1_HPDHits_16   = new TH1D("h1_HPDHits_16", "h1_HPDHits_16", 20, 0, 20);
      TH1D *h1_Erec_17      = new TH1D("h1_Erec_17",    "h1_Erec_17", 40, 0, 20);
      TH1D *h1_Erec_16      = new TH1D("h1_Erec_16",    "h1_Erec_16", 40, 0, 20);
      TH1D *h1_sumErec_17   = new TH1D("h1_sumErec_17", "h1_sumErec_17", 40, 0, 200);
      TH1D *h1_sumErec_16   = new TH1D("h1_sumErec_16", "h1_sumErec_16", 40, 0, 200);
      TH1D *h1_R45_17   = new TH1D("h1_R45_17", "h1_R45_17", 72, 0, 72);
      TH1D *h1_R45_16   = new TH1D("h1_R45_16", "h1_R45_16", 72, 0, 72);
      
      TH2F *h2_R45_17   = new TH2F("h2_R45_17", "h2_R45_17", 100, 0, 100, 100, -1, 1);
      TH2F *h2_R45_16   = new TH2F("h2_R45_16", "h2_R45_16", 100, 0, 100, 100, -1, 1);

    // loop over tree
    //for(unsigned int ientry=0; ientry<100; ientry++)
    for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
    {
        tree.GetEntry(ientry); 
      
        if((ientry%1000)==0) cout << ientry << "/" << tree.GetEntries() << endl;

        // 
        //  Triggers 
        // 
        //  30  HLT_CaloJet10_NoJetID_HCALPhase1_v1 
        //  31  HLT_CaloJet20_NoJetID_HCALPhase1_v1 
        //  32  HLT_CaloJet50_NoJetID_HCALPhase1_v1  
        //
        if(!tree.HLTInsideDatasetTriggerDecisions().at(30)) continue; 
        //if(!tree.HLTInsideDatasetTriggerDecisions().at(31)) continue; 
        //if(!tree.HLTInsideDatasetTriggerDecisions().at(32)) continue; 

        // HEP17: RBX=52, HPD=208-211
        // HEP16: RBX=51, HPD=204-207

        int N_HPDHits_204=0;
        int N_HPDHits_205=0;
        int N_HPDHits_206=0;
        int N_HPDHits_207=0;
        int N_HPDHits_208=0;
        int N_HPDHits_209=0;
        int N_HPDHits_210=0;
        int N_HPDHits_211=0; 
        float sumErec_17=0;
        float sumErec_16=0;
        int N_R45ch_17=0;
        int N_R45ch_16=0;
        //
        // Loop over channels
        //
        for(unsigned int irec=0; irec<tree.HBHERecHitIEta().size(); irec++) 
        {  
            // HPD occupancy 
            if(tree.HBHERecHitRBXid().at(irec)==52)  // HEP17
            {   
                sumErec_17 = sumErec_17 + tree.HBHERecHitEnergy().at(irec);
                h1_Erec_17->Fill(tree.HBHERecHitEnergy().at(irec)>19.999?19.999:tree.HBHERecHitEnergy().at(irec));
                if(tree.HBHERecHitHPDid().at(irec)==208 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_208++;
                if(tree.HBHERecHitHPDid().at(irec)==209 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_209++;
                if(tree.HBHERecHitHPDid().at(irec)==210 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_210++;
                if(tree.HBHERecHitHPDid().at(irec)==211 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_211++;
                
                float R45num = tree.HBHERecHitAuxFC().at(irec).at(4)-tree.HBHERecHitAuxFC().at(irec).at(5);
                float R45den = tree.HBHERecHitAuxFC().at(irec).at(4)+tree.HBHERecHitAuxFC().at(irec).at(5);
                h2_R45_17->Fill(R45den,R45num/R45den); 

                if(flagWordDecoder(tree.HBHERecHitFlags().at(irec),15)==true) N_R45ch_17++; 
            } 
            if(tree.HBHERecHitRBXid().at(irec)==51) // HEP16
            { 
                sumErec_16 = sumErec_16 + tree.HBHERecHitEnergy().at(irec); 
                h1_Erec_16->Fill(tree.HBHERecHitEnergy().at(irec)>19.999?19.999:tree.HBHERecHitEnergy().at(irec));
                if(tree.HBHERecHitHPDid().at(irec)==204 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_204++;
                if(tree.HBHERecHitHPDid().at(irec)==205 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_205++;
                if(tree.HBHERecHitHPDid().at(irec)==206 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_206++;
                if(tree.HBHERecHitHPDid().at(irec)==207 && tree.HBHERecHitEnergy().at(irec)>0.5) N_HPDHits_207++;
               
                float R45num = tree.HBHERecHitAuxFC().at(irec).at(4)-tree.HBHERecHitAuxFC().at(irec).at(5);
                float R45den = tree.HBHERecHitAuxFC().at(irec).at(4)+tree.HBHERecHitAuxFC().at(irec).at(5);
                h2_R45_16->Fill(R45den,R45num/R45den);                         
                
                if(flagWordDecoder(tree.HBHERecHitFlags().at(irec),15)==true) N_R45ch_16++;
            } 

        } 
        //cout << "HEP17: " << N_HPDHits_208 << " " << N_HPDHits_209 << " " << N_HPDHits_210 << " " << N_HPDHits_211 << endl;
        //cout << "HEP16: " << N_HPDHits_204 << " " << N_HPDHits_205 << " " << N_HPDHits_206 << " " << N_HPDHits_207 << endl;
        
        h1_HPDHits_17->Fill(N_HPDHits_208);
        h1_HPDHits_17->Fill(N_HPDHits_209);
        h1_HPDHits_17->Fill(N_HPDHits_210);
        h1_HPDHits_17->Fill(N_HPDHits_211);
        
        h1_HPDHits_16->Fill(N_HPDHits_204);
        h1_HPDHits_16->Fill(N_HPDHits_205);
        h1_HPDHits_16->Fill(N_HPDHits_206);
        h1_HPDHits_16->Fill(N_HPDHits_207);
        
        h1_RBXHits_17->Fill(N_HPDHits_208+N_HPDHits_209+N_HPDHits_210+N_HPDHits_211);
        h1_RBXHits_16->Fill(N_HPDHits_204+N_HPDHits_205+N_HPDHits_206+N_HPDHits_207);
        
        h1_sumErec_17->Fill(sumErec_17);
        h1_sumErec_16->Fill(sumErec_16); 

        h1_R45_17->Fill(N_R45ch_17);
        h1_R45_16->Fill(N_R45ch_16); 

    }  
    
    TCanvas *c = new TCanvas("c","c",1200,800); 
    c->Divide(3,2);
    c->cd(1);
    c->cd(1)->SetLogy(1);
    h1_Erec_17->DrawNormalized("hist");
    c->cd(2);
    c->cd(2)->SetLogy(1);
    h1_Erec_16->DrawNormalized("hist");
    c->cd(3);
    c->cd(3)->SetLogy(1);
    //h1_sumErec_17->DrawNormalized("hist");
    h1_sumErec_16->DrawNormalized("e");
    c->cd(4);
    c->cd(4)->SetLogy(1);
    h1_HPDHits_17->DrawNormalized("hist");
    h1_HPDHits_16->DrawNormalized("e same");
    c->cd(5);
    c->cd(5)->SetLogy(1);
    h1_R45_17->DrawNormalized("hist");
    h1_R45_16->DrawNormalized("e same");
    c->Print("plots/2d.pdf");
  
    // 
    // 
    // 
    TCanvas *c_occ = new TCanvas("c_occ","c_occ",1200,400); 
    c_occ->Divide(2,1); 

    h1cosmetic(h1_HPDHits_17, "", kBlue, 1, 0, "Number of RecHits per RM"); 
    h1cosmetic(h1_HPDHits_16, "", kRed,  1, 0, "Number of RecHits per RM"); 
    h1cosmetic(h1_RBXHits_17, "", kBlue, 1, 0, "Number of RecHits per RBX"); 
    h1cosmetic(h1_RBXHits_16, "", kRed,  1, 0, "Number of RecHits per RBX"); 

    TLegend *l1 = new TLegend(0.6, 0.7, 0.90, 0.90);
    l1->SetNColumns(1);
    l1->SetBorderSize(0);
    l1->SetFillColor(0);
    l1->SetFillStyle(0);
    //l1->SetTextFont(42);
    l1->SetTextAlign(12);
    l1->SetTextSize(0.06);
    l1->SetFillColor(kWhite);
    l1->SetLineColor(kWhite);
    l1->SetShadowColor(kWhite);
    l1->AddEntry(h1_HPDHits_17,          " HEP17",    "lp");
    l1->AddEntry(h1_HPDHits_16,          " HEP16",    "lp");

    c_occ->cd(1);
    c_occ->cd(1)->SetLogy(1);
    h1_HPDHits_17->DrawNormalized("ep");
    h1_HPDHits_16->DrawNormalized("ep same"); 
    l1->Draw();
    c_occ->cd(2);
    c_occ->cd(2)->SetLogy(1);
    h1_RBXHits_17->DrawNormalized("ep");
    h1_RBXHits_16->DrawNormalized("ep same");
    l1->Draw();
    c_occ->Print("plots/c_occ.pdf");
    
    // 
    // 
    // 
    TCanvas *c_rechit = new TCanvas("c_rechit","c_rechit",600,400); 
    
    h1cosmetic(h1_Erec_17, "", kBlue, 1, 0, "E_{RecHit} [GeV]"); 
    h1cosmetic(h1_Erec_16, "", kRed, 1, 0, "E_{RecHit} [GeV]"); 
    
    c_rechit->cd(1);
    c_rechit->cd(1)->SetLogy(1);
    h1_Erec_17->DrawNormalized("ep");
    h1_Erec_16->DrawNormalized("ep same"); 
    l1->Draw();
    c_rechit->Print("plots/c_rechit.pdf");

    
}
