#include <iostream>
#include <string>
#include <stdlib.h> 

#include "TFile.h"
#include "TH1D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TError.h"
#include "TROOT.h"

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

int main()
{ 

    gErrorIgnoreLevel=kError+1;
/*
    hcal_tree_noise tree("/Users/jaehyeok/scratch/results_9.root");
    
    cout << "Analyzing " << tree.GetEntries() << " events" << endl;

    // define histograms 
    TH2D *h2_anode1[83][72][2]; // [ieta], [iphi], [depth]
    TH2D *h2_anode2[83][72][2]; 
    for(int ieta=-41; ieta<=41; ieta++)
    {
        for(int iphi=1; iphi<=72; iphi++)
        {
            for(int depth=1; depth<=2; depth++)
            {
                h2_anode1[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_anode1_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_anode1_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, 0, 1000, 320, -110, 50);
                h2_anode2[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_anode2_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_anode2_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, 0, 1000, 320, -110, 50);
            }
        }
    }

    // loop over tree
    for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
    //for(unsigned int ientry=0; ientry<100; ientry++)
    {
        tree.GetEntry(ientry);  
        
        for(unsigned int irec=0; irec<tree.HFPhase1RecHitDepth().size(); irec++) 
        { 
            //if( tree.HFPhase1RecHitIEta().at(irec)!=IETA ||
            //    tree.HFPhase1RecHitIPhi().at(irec)!=IPHI ||
            //    tree.HFPhase1RecHitDepth().at(irec)!=DEPTH
            //  ) continue;

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
            int index_ieta=tree.HFPhase1RecHitIEta().at(irec)+41;
            int index_iphi=tree.HFPhase1RecHitIPhi().at(irec)-1;
            int index_depth=tree.HFPhase1RecHitDepth().at(irec)-1;
            FillTH2D(h2_anode1[index_ieta][index_iphi][index_depth], 
                     tree.HFPhase1RecHitQie10Charge().at(irec).at(0), 
                     tree.HFPhase1RecHitQie10Time().at(irec).at(0), 1);
            FillTH2D(h2_anode2[index_ieta][index_iphi][index_depth], 
                     tree.HFPhase1RecHitQie10Charge().at(irec).at(1), 
                     tree.HFPhase1RecHitQie10Time().at(irec).at(1), 1);
        }
    }
 
    TFile *HistFile = new TFile("optimize_hf.root", "RECREATE");
    gROOT->cd();
    HistFile->cd();

    for(int ieta=-41; ieta<=41; ieta++)
    {
        for(int iphi=1; iphi<=72; iphi++)
        {
            for(int depth=1; depth<=2; depth++)
            {
                //if(ieta>-29 && ieta<29) continue;
                if( h2_anode1[ieta+41][iphi-1][depth-1]->Integral()==0  && 
                    h2_anode2[ieta+41][iphi-1][depth-1]->Integral()==0 
                    ) continue;
                h2_anode1[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h2_anode1[ieta+41][iphi-1][depth-1]->Write();
                h2_anode2[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h2_anode2[ieta+41][iphi-1][depth-1]->Write();
            }
        }
    }
    HistFile->Close();
*/

  // 
  // Read histograms from a file
  //
  TFile* infile  = TFile::Open("optimize_hf.root", "READ");
    
  // merge iphi
  TH2D *h2_anode1[83][2]; // [ieta], [iphi], [depth]
  TH2D *h2_anode2[83][2]; 
  for(int ieta=-41; ieta<=41; ieta++)
  {
     for(int depth=1; depth<=2; depth++)
     {
         h2_anode1[ieta+41][depth-1] 
             = new TH2D( Form("h2_anode1_ieta%i_depth%i", ieta, depth),
                         Form("h2_anode1_ieta%i_depth%i", ieta, depth),
                         100, 0, 1000, 320, -110, 50);
         h2_anode2[ieta+41][depth-1] 
             = new TH2D( Form("h2_anode2_ieta%i_depth%i", ieta, depth),
                         Form("h2_anode2_ieta%i_depth%i", ieta, depth),
                         100, 0, 1000, 320, -110, 50); 
        
        for(int iphi=1; iphi<=72; iphi++) 
        { 
           TH2D *h2_temp = infile->Get(Form("h2_anode1_ieta%i_iphi%i_depth%i", ieta, iphi, depth)); 
           if(h2_temp) h2_anode1[ieta+41][depth-1]->Add()
           h2_temp = infile->Get(Form("h2_anode2_ieta%i_iphi%i_depth%i", ieta, iphi, depth)); 
           if(h2_temp) h2_anode2[ieta+41][depth-1]->Add()
           delete h2_temp;
        }
     }
  }

  

h2_anode2_ieta41_iphi51_depth2


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
