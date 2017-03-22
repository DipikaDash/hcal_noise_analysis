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

//int main(int argc, char *argv[])
int main()
{
    //hcal_tree_noise met("/Users/jaehyeok/Research/cms/UCSB/HCAL/Noise/ntuples/results_*.root");
    hcal_tree_noise met("/Users/jaehyeok/scratch/results.root");

    cout << "Analyzing " << met.GetEntries() << " events" << endl;

    TH2F *h2    = new TH2F("h2",    "h2", 2, 0, 2, 2, 0, 2);
    TH2F *h2iso = new TH2F("h2iso", "h2iso", 2, 0, 2, 2, 0, 2);

    // loop over tree
    for(unsigned int ientry=0; ientry<met.GetEntries(); ientry++)
    {
        met.GetEntry(ientry); 
        
        //
        // Check the HCALNoiseSummary-based filter decisions
        // 

        // HBHELoose filter
        bool mydecision = passHBHELoose(met.HPDHits().at(0), 
                                        met.HPDNoOtherHits().at(0),
                                        met.MaxZeros().at(0),
                                        met.HasBadRBXRechitR45Loose().at(0)); 
        h2->Fill(mydecision, met.OfficialDecisionRun2L().at(0), 1);

        // HBHEIso filter
        mydecision = passHBHEIso(met.NumIsolatedNoiseChannels().at(0), 
                                 met.IsolatedNoiseSumE().at(0), 
                                 met.IsolatedNoiseSumEt().at(0)); 
        h2iso->Fill(mydecision, met.IsoNoiseFilterDecision().at(0), 1);
       
        //
        // Loop over channels
        //
        for(unsigned int irec=0; irec<met.HBHERecHitEta().size(); irec++) 
        { 
            //if(irec>0) continue; // FIXME  

            if(0) 
            {
                cout << met.HBHERecHitEta().at(irec) <<  ", " 
                     << met.HBHERecHitPhi().at(irec) <<  ", " 
                     << met.HBHERecHitEnergy().at(irec) << endl; 
            } 
/*
            // loop over TSs
            for(unsigned int its=0; its<met.HBHERecHitAuxAllfC().at(irec).size(); its++)  
            { 
                cout << met.HBHERecHitAuxAllfC().at(irec).at(its) << endl; 
            } 
*/
        } 
    } 

    TCanvas *c = new TCanvas("c","c",800,400); 
    c->Divide(2,1);
    c->cd(1);
    h2->Draw("colz text");
    c->cd(2);
    h2iso->Draw("colz text");
    c->Print("plots/2d.pdf");
}
