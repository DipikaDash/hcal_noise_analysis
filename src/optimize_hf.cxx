#include <iostream>
#include <string>
#include <stdlib.h> 

#include "TFile.h"
#include "TH1D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TRandom1.h"
#include "TRandom2.h"
#include "TLine.h"
#include "TError.h"

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

// 
// Caution 
// 
// 1. checking 4 previous and next 4 bins: depending on the distance between the
//    peaks from signal and noise, 4 should be revisited.
// 2. If they are very close, algorithm does not work. 
// 

///////////////////////////////////////////////////////////////////////////

using namespace std; 

int main(int argc, char *argv[])
{ 

    gErrorIgnoreLevel=kError+1;

    int IETA=1;
    int IPHI=1;
    int DEPTH=1;

    if(argc<4) {
        cout << "Enter [ieta] [iphi] [depth]" << endl;
        return 0;
    } 
    else 
    { 
        IETA=atoi(argv[1]);
        IPHI=atoi(argv[2]);
        DEPTH=atoi(argv[3]);
    }

    hcal_tree_noise tree("/Users/jaehyeok/scratch/results_9.root");
    
    cout << "Analyzing " << tree.GetEntries() << " events" << endl;

    TH2D *h2_anode1 = new TH2D("h2_anode1","h2_anode1",100, 0, 1000, 320, -110, 50);
    TH2D *h2_anode2 = new TH2D("h2_anode2","h2_anode2",100, 0, 1000, 320, -110, 50);

    // loop over tree
    for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
    //for(unsigned int ientry=0; ientry<1; ientry++)
    {
        tree.GetEntry(ientry);  
        
        for(unsigned int irec=0; irec<tree.HFPhase1RecHitDepth().size(); irec++) 
        { 
            if( tree.HFPhase1RecHitIEta().at(irec)!=IETA ||
                tree.HFPhase1RecHitIPhi().at(irec)!=IPHI ||
                tree.HFPhase1RecHitDepth().at(irec)!=DEPTH
              ) continue;

            if(0)  // debug  
            {    
                cout << ientry << " :: " 
                     << "(" 
                     << tree.HFPhase1RecHitIEta().at(irec) << ", " 
                     << tree.HFPhase1RecHitIPhi().at(irec) << ", "
                     << tree.HFPhase1RecHitDepth().at(irec) << ")" << endl; 
                cout << tree.HFPhase1RecHitQie10Time().at(irec).at(0) << ", "  
                     << tree.HFPhase1RecHitQie10Time().at(irec).at(1) << endl;  
                cout << tree.HFPhase1RecHitQie10Charge().at(irec).at(0) << ", "  
                     << tree.HFPhase1RecHitQie10Charge().at(irec).at(1) << endl;  
                cout << tree.HFPhase1RecHitQie10Energy().at(irec).at(0) << ", "  
                     << tree.HFPhase1RecHitQie10Energy().at(irec).at(1) << endl;   
            }

            //
            FillTH2D(h2_anode1, tree.HFPhase1RecHitQie10Charge().at(irec).at(0), 
                                tree.HFPhase1RecHitQie10Time().at(irec).at(0), 1);
            FillTH2D(h2_anode2, tree.HFPhase1RecHitQie10Charge().at(irec).at(1), 
                                tree.HFPhase1RecHitQie10Time().at(irec).at(1), 1);
        }
    }

 
    TCanvas *c = new TCanvas("c", "c", 800, 400); 
    c->Divide(2,1);
    c->cd(1); 
    h2_anode1->Draw("colz");
    c->cd(2); 
    h2_anode2->Draw("colz");
    c->Print(Form("plots/hf_ieta%i_iphi%i_depth%i.pdf", IETA, IPHI, DEPTH));

/*
    //
    // run the algo to find the valley 
    //
    // Find the maxima first: the minima should be between the two maxima 
    //  (1) At a given bin, check the previous and the next 4 bins 
    //  (2) Ask if this bin has the max y value of the nine bins
    //  (3) If no, go the next bin 
    //      If yes, make slopes with (-4,-1) bins and (1,4) bins
    //  (4) If the first slope is positive and the second is negative,
    //      mark the bin as local maximum
    //      If not, move to the next been  
    vector<int> max_ibin;
    for(int ibin=5; ibin<=(hall->GetXaxis()->GetNbins()-4); ibin++) 
    { 
        int max_ibin_of_9=ibin-4;
        for(int ibin_of_9=ibin-4; ibin_of_9<=ibin+4; ibin_of_9++)
        { 
            if(hall->GetBinContent(ibin_of_9)>hall->GetBinContent(max_ibin_of_9)) max_ibin_of_9 = ibin_of_9;
        }
        // if ibin is not the maximum of the 9 bins, continue
        if(max_ibin_of_9!=ibin) continue; 
 
        // check the slopes
        if(hall->GetBinContent(ibin-1)-hall->GetBinContent(ibin-4)>0 &&
           hall->GetBinContent(ibin+4)-hall->GetBinContent(ibin+1)<0)  max_ibin.push_back(ibin);

    }

    cout << max_ibin.size()  << endl; 

    // continue if there are more than two maxima
    if(max_ibin.size()>2) 
    { 
        cout << "[Error] There are more than 2 local maxima!" << endl;
    }

    // Find the valley (the mininma between the maxima) 
    //  (1) At a given bin, check the previous and the next 4 bins 
    //  (2) Ask if this bin has the min y value of the nine bins
    //  (3) If no, go the next bin 
    //      If yes, make slopes with (-4,-1) bins and (1,4) bins
    //  (4) If the first slope is negative and the second is positive,
    //      and the bin is bewteen the two maxima, mark the bin as local minimum.
    //      If not, move to the next been  
    vector<int> min_ibin;
    for(int ibin=max_ibin.at(0); ibin<=max_ibin.at(1); ibin++)  
    { 
cout << __LINE__ << " " << __FILE__ << endl; 
        int min_ibin_of_9=ibin-4;
        for(int ibin_of_9=ibin-4; ibin_of_9<=ibin+4; ibin_of_9++)
        { 
            if(hall->GetBinContent(ibin_of_9)<hall->GetBinContent(min_ibin_of_9)) min_ibin_of_9 = ibin_of_9;
        }
cout << __LINE__ << " " << __FILE__ << endl; 
        // if ibin is not the minimum of the 9 bins, continue
        if(min_ibin_of_9!=ibin) continue; 
        
        // check the slopes
        if(hall->GetBinContent(ibin-1)-hall->GetBinContent(ibin-4)<0 &&
           hall->GetBinContent(ibin+4)-hall->GetBinContent(ibin+1)>0)  min_ibin.push_back(ibin);
cout << __LINE__ << " " << __FILE__ << endl; 
    }

    cout << min_ibin.size()  << endl; 
    
    // continue if there are more than two maxima
    if(min_ibin.size()!=1) 
    { 
        cout << "[Error] There are more than 1 local minimum between the two maxima!" << endl;
    }

    // Finally, check if there are two maxima, and one minimum 
    // If yes, we found the valley 
    // If no, double check the channel
    
    //
    // visualization
    //
    TLine *l = new TLine(hall->GetBinCenter(min_ibin.at(0)), 0, hall->GetBinCenter(min_ibin.at(0)), hall->GetMaximum());
    l->SetLineStyle(2);
    l->SetLineColor(kRed);
    l->SetLineWidth(2);
    l->Draw("same");
    
    c->Print("hf.pdf");
*/
} 
