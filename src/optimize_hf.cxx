#include <iostream>
#include <string>
#include <stdlib.h> 

#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TError.h"
#include "TROOT.h"
#include "TMath.h"
#include "TVector3.h"

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

    // ntuples without MET variable 
    //hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017A-v1_RAW_20170608_114855/170608_094903/0000/*.root");
    //hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017A-v1_RAW_20170608_114855/170608_094903/0000/*_4.root");
    // ntuples with MET variable 
    //hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017A-v1_RAW_20170612_204717/170612_184739/0000/*_5*.root");
    //hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/SingleMuon/Run2017A-v1_RAW_20170613_102736/170613_082753/0000/results_5*.root");
    //hcal_tree_noise tree("/hadoop/cms/store/user/jaehyeok/MET/Run2017A-v1_RAW_20170613_094107/170613_074123/0000/results_5*.root");
    hcal_tree_noise tree("results_forwardjets_met.root");
    //hcal_tree_noise tree("/home/users/jaehyeok/scratch/met/*root");
    //hcal_tree_noise tree("/home/users/jaehyeok/scratch/singlemuon/*root");
    
    //hcal_tree_noise tree("~/scratch/results_forwardjets.root");
    
    cout << "Analyzing " << tree.GetEntries() << " events" << endl;

    // define histograms 
    TH2D *h2_anode1[83][72][2]; // [ieta], [iphi], [depth]
    TH2D *h2_anode2[83][72][2]; 
    TH2D *h2_asym[83][72][2]; 
    TH2D *h2_asym_tdccut[83][72][2]; 
    TH1D *h1_asym[83][72][2]; 
    TH1D *h1_asym_tdccut[83][72][2]; 
    for(int ieta=-41; ieta<=41; ieta++)
    {
        for(int iphi=1; iphi<=72; iphi++)
        {
            for(int depth=1; depth<=2; depth++)
            {
                h2_anode1[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_anode1_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_anode1_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                200, 0, 2000, 320, -110, 50);
                h2_anode2[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_anode2_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_anode2_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                200, 0, 2000, 320, -110, 50);
                h2_asym[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_asym_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_asym_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, 0, 2000, 100, 0, 2000);
                h2_asym_tdccut[ieta+41][iphi-1][depth-1] 
                    = new TH2D( Form("h2_asym_tdccut_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h2_asym_tdccut_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, 0, 2000, 100, 0, 2000);
                h1_asym[ieta+41][iphi-1][depth-1] 
                    = new TH1D( Form("h1_asym_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h1_asym_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, -2, 2);
                h1_asym_tdccut[ieta+41][iphi-1][depth-1] 
                    = new TH1D( Form("h1_asym_tdccut_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                Form("h1_asym_tdccut_ieta%i_iphi%i_depth%i", ieta, iphi, depth),
                                100, -2, 2);
            }
        }
    }
    TH1D *h1_met_nohbhefilter = new TH1D( "h1_met_nohbhefilter", "h1_met_nohbhefilter", 100, 0, 500);
    TH1D *h1_met = new TH1D( "h1_met", "h1_met", 100, 0, 500);
    TH1D *h1_met_tdc = new TH1D( "h1_met_tdc", "h1_met_tdc", 100, 0, 500);
    TH1D *h1_met_asym = new TH1D( "h1_met_asym", "h1_met_asym", 100, 0, 500);
    TH1D *h1_met_both = new TH1D( "h1_met_both", "h1_met_both", 100, 0, 500);
    TH1D *h1_met_cor = new TH1D( "h1_met_cor", "h1_met_cor", 100, -200, 200);
    TH1D *h1_met_phi = new TH1D( "h1_met_phi", "h1_met_phi", 30, -3.141592, 3.141592);

    // loop over tree
    for(unsigned int ientry=0; ientry<tree.GetEntries(); ientry++)
    //for(unsigned int ientry=0; ientry<100; ientry++)
    {
        if(ientry%10000==0) cout << ientry << "/" << tree.GetEntries()<< endl;
        
        tree.GetEntry(ientry);  

        //cout << tree.NominalMET().at(0) << ", " <<  tree.NominalMET().at(1) 
        //     << " = " << TMath::Sqrt(tree.NominalMET().at(0)*tree.NominalMET().at(0)
        //                            +tree.NominalMET().at(1)*tree.NominalMET().at(1)) << endl;
        
        // FIXME: need to apply HBHE event filters? 

        // corrections to the nominal MET
        float METx_tdc=0.;
        float METy_tdc=0.;
        float METx_asym=0.;
        float METy_asym=0.;
        float METx_both=0.;
        float METy_both=0.;

        for(unsigned int irec=0; irec<tree.HFPhase1RecHitDepth().size(); irec++) 
        { 
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

            float METx_tdc_cor=0.;
            float METy_tdc_cor=0.;
            float METx_asym_cor=0.;
            float METy_asym_cor=0.;
            // Calculate corrections 
            if(!passTDCcut(tree.HFPhase1RecHitIEta().at(irec), 
                          tree.HFPhase1RecHitQie10Charge().at(irec).at(0),
                          tree.HFPhase1RecHitQie10Time().at(irec).at(0)))
            {
               METx_tdc_cor = getMETx(tree.HFPhase1RecHitEta().at(irec),
                                      tree.HFPhase1RecHitPhi().at(irec),
                                      tree.HFPhase1RecHitQie10Energy().at(irec).at(0));
               METy_tdc_cor = getMETy(tree.HFPhase1RecHitEta().at(irec),
                                      tree.HFPhase1RecHitPhi().at(irec),
                                      tree.HFPhase1RecHitQie10Energy().at(irec).at(0));
            }
            if(!passTDCcut(tree.HFPhase1RecHitIEta().at(irec), 
                          tree.HFPhase1RecHitQie10Charge().at(irec).at(1),
                          tree.HFPhase1RecHitQie10Time().at(irec).at(1))) 
            {
               METx_tdc_cor = METx_tdc_cor + getMETx(tree.HFPhase1RecHitEta().at(irec),
                                                     tree.HFPhase1RecHitPhi().at(irec),
                                                     tree.HFPhase1RecHitQie10Energy().at(irec).at(1));
               METy_tdc_cor = METy_tdc_cor + getMETy(tree.HFPhase1RecHitEta().at(irec),
                                                     tree.HFPhase1RecHitPhi().at(irec),
                                                     tree.HFPhase1RecHitQie10Energy().at(irec).at(1));
            }

            if(!passAsymcut(tree.HFPhase1RecHitIEta().at(irec),
                            tree.HFPhase1RecHitDepth().at(irec),
                            tree.HFPhase1RecHitQie10Charge().at(irec).at(0),
                            tree.HFPhase1RecHitQie10Charge().at(irec).at(1)))
            {
               METx_asym_cor = METx_asym_cor + getMETx(tree.HFPhase1RecHitEta().at(irec),
                                                       tree.HFPhase1RecHitPhi().at(irec),
                                                       tree.HFPhase1RecHitQie10Energy().at(irec).at(1));
               METy_asym_cor = METy_asym_cor + getMETy(tree.HFPhase1RecHitEta().at(irec),
                                                       tree.HFPhase1RecHitPhi().at(irec),
                                                       tree.HFPhase1RecHitQie10Energy().at(irec).at(1));
            }

            METx_tdc = METx_tdc + METx_tdc_cor;
            METy_tdc = METy_tdc + METy_tdc_cor;
            METx_asym = METx_asym + METx_asym_cor;
            METy_asym = METy_asym + METy_asym_cor; 
            // in case channel fails both cuts, need to correct only once 
            // to avoid double correction (METx_tdc_cor=METx_asym_cor)
            if((METx_tdc_cor!=0 || METy_tdc_cor!=0) && (METx_asym_cor!=0 || METy_asym_cor!=0))
            {
                METx_both = METx_both + METx_tdc_cor;
                METy_both = METy_both + METy_tdc_cor;
            }
            else 
            { 
                METx_both = METx_both + METx_tdc_cor + METx_asym_cor;
                METy_both = METy_both + METy_tdc_cor + METy_asym_cor;
            }
            //if(METx_tdc_cor!=0 || METy_tdc_cor!=0) cout << "TDC cor: " << METx_tdc_cor << ", " << METy_tdc_cor << endl;
            //if(METx_asym_cor!=0 || METy_asym_cor!=0) cout << "Asym cor: " << METx_asym_cor << ", " << METy_asym_cor << endl;

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
            //cout << tree.HFPhase1RecHitIEta().at(irec) << " " << tree.HFPhase1RecHitIPhi().at(irec) << " " 
            //     << tree.HFPhase1RecHitDepth().at(irec) << " " << tree.HFPhase1RecHitQie10Charge().at(irec).size() 
            //     << " :: " << tree.HFPhase1RecHitQie10Charge().at(irec).at(0) << " " 
            //     << tree.HFPhase1RecHitQie10Charge().at(irec).at(1) << endl;
  
            if(tree.HFPhase1RecHitQie10Time().at(irec).at(0)>0 && tree.HFPhase1RecHitQie10Time().at(irec).at(1)>0)
                FillTH2D(h2_asym[index_ieta][index_iphi][index_depth],
                         tree.HFPhase1RecHitQie10Charge().at(irec).at(0), 
                         tree.HFPhase1RecHitQie10Charge().at(irec).at(1), 1);
            
            if((tree.HFPhase1RecHitQie10Charge().at(irec).at(0)+tree.HFPhase1RecHitQie10Charge().at(irec).at(1))>400) 
            {
                if(tree.HFPhase1RecHitQie10Time().at(irec).at(0)>0 && tree.HFPhase1RecHitQie10Time().at(irec).at(1)>0)
                    FillTH1D(h1_asym[index_ieta][index_iphi][index_depth], 
                             (tree.HFPhase1RecHitQie10Charge().at(irec).at(0)-tree.HFPhase1RecHitQie10Charge().at(irec).at(1))/
                             (tree.HFPhase1RecHitQie10Charge().at(irec).at(0)+tree.HFPhase1RecHitQie10Charge().at(irec).at(1)), 1);
            }
            
            if(passTDCcut(tree.HFPhase1RecHitIEta().at(irec), 
                          //tree.HFPhase1RecHitIPhi().at(irec),
                          //tree.HFPhase1RecHitDepth().at(irec),
                          tree.HFPhase1RecHitQie10Charge().at(irec).at(0),
                          tree.HFPhase1RecHitQie10Time().at(irec).at(0))
             && passTDCcut(tree.HFPhase1RecHitIEta().at(irec), 
                          //tree.HFPhase1RecHitIPhi().at(irec),
                          //tree.HFPhase1RecHitDepth().at(irec),
                          tree.HFPhase1RecHitQie10Charge().at(irec).at(1),
                          tree.HFPhase1RecHitQie10Time().at(irec).at(1))
                          )
           { 
                if(tree.HFPhase1RecHitQie10Time().at(irec).at(0)>0 && tree.HFPhase1RecHitQie10Time().at(irec).at(1)>0)
                    FillTH2D(h2_asym_tdccut[index_ieta][index_iphi][index_depth], 
                             tree.HFPhase1RecHitQie10Charge().at(irec).at(0), 
                             tree.HFPhase1RecHitQie10Charge().at(irec).at(1), 1);
                if((tree.HFPhase1RecHitQie10Charge().at(irec).at(0)+tree.HFPhase1RecHitQie10Charge().at(irec).at(1))>400) 
                {
                    if(tree.HFPhase1RecHitQie10Time().at(irec).at(0)>0 && tree.HFPhase1RecHitQie10Time().at(irec).at(1)>0)
                        FillTH1D(h1_asym_tdccut[index_ieta][index_iphi][index_depth], 
                                 (tree.HFPhase1RecHitQie10Charge().at(irec).at(0)-tree.HFPhase1RecHitQie10Charge().at(irec).at(1))/
                                 (tree.HFPhase1RecHitQie10Charge().at(irec).at(0)+tree.HFPhase1RecHitQie10Charge().at(irec).at(1)), 1);
                }
           } 
        }

        // recalculate MET
        float MET      = getMET(tree.NominalMET().at(0), tree.NominalMET().at(1));
        float MET_tdc  = getMET(tree.NominalMET().at(0)+METx_tdc, tree.NominalMET().at(1)+METy_tdc);
        float MET_asym = getMET(tree.NominalMET().at(0)+METx_asym, tree.NominalMET().at(1)+METy_asym);
        float MET_both = getMET(tree.NominalMET().at(0)+METx_both, tree.NominalMET().at(1)+METy_both); 
    
        FillTH1D(h1_met_nohbhefilter, MET, 1);
        if(!tree.OfficialDecisionRun2L().at(0) || !tree.IsoNoiseFilterDecision().at(0)) continue;
        FillTH1D(h1_met, MET, 1);
        FillTH1D(h1_met_tdc, MET_tdc, 1);
        FillTH1D(h1_met_asym, MET_asym, 1);
        FillTH1D(h1_met_both, MET_both, 1);
        if(MET-MET_both) FillTH1D(h1_met_cor, MET-MET_both, 1);
       
        TVector3 met(tree.NominalMET().at(0), tree.NominalMET().at(1), 0);
        FillTH1D(h1_met_phi, met.Phi(), 1);

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
                h2_asym[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h2_asym[ieta+41][iphi-1][depth-1]->Write();
                h2_asym_tdccut[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h2_asym_tdccut[ieta+41][iphi-1][depth-1]->Write();
                h1_asym[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h1_asym[ieta+41][iphi-1][depth-1]->Write();
                h1_asym_tdccut[ieta+41][iphi-1][depth-1]->SetDirectory(0);
                h1_asym_tdccut[ieta+41][iphi-1][depth-1]->Write();
            }
        }
    }
    h1_met_nohbhefilter->SetDirectory(0); h1_met_nohbhefilter->Write();
    h1_met->SetDirectory(0); h1_met->Write();
    h1_met_tdc->SetDirectory(0); h1_met_tdc->Write();
    h1_met_asym->SetDirectory(0); h1_met_asym->Write();
    h1_met_both->SetDirectory(0); h1_met_both->Write();
    h1_met_cor->SetDirectory(0); h1_met_cor->Write();
    h1_met_phi->SetDirectory(0); h1_met_phi->Write();
    HistFile->Close();

/*
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
                         200, 0, 2000, 320, -110, 50);
         h2_anode2[ieta+41][depth-1] 
             = new TH2D( Form("h2_anode2_ieta%i_depth%i", ieta, depth),
                         Form("h2_anode2_ieta%i_depth%i", ieta, depth),
                         200, 0, 2000, 320, -110, 50); 
        
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
*/
  

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
