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

#include "hcal_tree_noise.hpp"
#include "utilities.hpp"

using namespace std; 

//int main(int argc, char *argv[])
int main()
{
  gErrorIgnoreLevel=kError+1;
/* 
  hcal_tree_noise zero("/hadoop/cms/store/user/jaehyeok/ZeroBias/Run2017F-PromptReco-v1_RECO_20171223_053521/171223_043552/0000/results_1.root");
  hcal_tree_noise jetht("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017F-JetHTJetPlusHOFilter-17Nov2017-v1_RAW-RECO_20171223_031608/171223_021646/0000/results_1.root");
  hcal_tree_noise met("/hadoop/cms/store/user/jaehyeok/MET/Run2017F-HighMET-PromptReco-v1_RAW-RECO_20171229_005222/171228_235239/0000/results_1.root");
  hcal_tree_noise pion("/hadoop/cms/store/user/jaehyeok/DoublePion_E-100/RunIISummer17DRPremix-92X_upgrade2017_realistic_v10-v2_GEN-SIM-RECO_20171223_072119/171223_062133/0000/results_mc_9.root");
*/

  hcal_tree_noise zero("/hadoop/cms/store/user/jaehyeok/ZeroBias/Run2017F-PromptReco-v1_RECO_20171223_053521/171223_043552/0000/results_1*.root");
  hcal_tree_noise jetht("/hadoop/cms/store/user/jaehyeok/JetHT/Run2017F-JetHTJetPlusHOFilter-17Nov2017-v1_RAW-RECO_20171223_031608/171223_021646/0000/results_*.root");
  hcal_tree_noise met("/hadoop/cms/store/user/jaehyeok/MET/Run2017F-HighMET-PromptReco-v1_RAW-RECO_20171229_005222/171228_235239/0000/results_*.root");
  hcal_tree_noise pion("/hadoop/cms/store/user/jaehyeok/DoublePion_E-100/RunIISummer17DRPremix-92X_upgrade2017_realistic_v10-v2_GEN-SIM-RECO_20171223_072119/171223_062133/0000/results_mc_10.root");

  // Need Rrec for 
  //  - each channel 
  //      - ieta = 16-29
  //      - iphi = 63-66
  //      - depth = 1-7
  //  - different Nvtx 
  //      - mean = 35 rms=7
  //      - about 15% with Nvtx=1
  //      - <25 >45

  TH1D *h1_zero[14][4][7][3]; // ieta iphi depth nvtx
  TH1D *h1_zero_depth[14][4][7][3]; // ieta iphi depth nvtx
  TH1D *h1_jetht[14][4][7][3]; // ieta iphi depth nvtx 
  TH1D *h1_met[14][4][7][3]; // ieta iphi depth nvtx 
  TH1D *h1_pion[14][4][7][3]; // ieta iphi depth nvtx
  TH2D *h2_jetht_energy_frac[14][4][3]; // ieta iphi depth nvtx
  TH2D *h2_zero_energy_frac[14][4][3]; // ieta iphi depth nvtx
  float bin[82]={0.0,0.01,0.0112202,0.0125893,0.0141254,0.0158489,0.0177828,0.0199526,0.0223872,0.0251189,0.0281838,0.0316228,0.0354813,0.0398107,0.0446684,0.0501187,0.0562341,0.0630957,0.0707946,0.0794328,0.0891251,0.1,0.112202,0.125893,0.141254,0.158489,0.177828,0.199526,0.223872,0.251189,0.281838,0.316228,0.354813,0.398107,0.446684,0.501187,0.562341,0.630957,0.707946,0.794328,0.891251,1,1.12202,1.25893,1.41254,1.58489,1.77828,1.99526,2.23872,2.51189,2.81838,3.16228,3.54813,3.98107,4.46684,5.01187,5.62341,6.30957,7.07946,7.94328,8.91251,10,11.2202,12.5893,14.1254,15.8489,17.7828,19.9526,22.3872,25.1189,28.1838,31.6228,35.4813,39.8107,44.6684,50.1187,56.2341,63.0957,70.7946,79.4328,89.1251,100};
//  float bin[251]={0.001,0.00104713,0.00109648,0.00114815,0.00120226,0.00125893,0.00131826,0.00138038,0.00144544,0.00151356,0.00158489,0.00165959,0.0017378,0.0018197,0.00190546,0.00199526,0.0020893,0.00218776,0.00229087,0.00239883,0.00251189,0.00263027,0.00275423,0.00288403,0.00301995,0.00316228,0.00331131,0.00346737,0.00363078,0.00380189,0.00398107,0.00416869,0.00436516,0.00457088,0.0047863,0.00501187,0.00524807,0.00549541,0.0057544,0.0060256,0.00630957,0.00660693,0.00691831,0.00724436,0.00758578,0.00794328,0.00831764,0.00870964,0.00912011,0.00954993,0.01,0.0104713,0.0109648,0.0114815,0.0120226,0.0125893,0.0131826,0.0138038,0.0144544,0.0151356,0.0158489,0.0165959,0.017378,0.018197,0.0190546,0.0199526,0.020893,0.0218776,0.0229087,0.0239883,0.0251189,0.0263027,0.0275423,0.0288403,0.0301995,0.0316228,0.0331131,0.0346737,0.0363078,0.0380189,0.0398107,0.0416869,0.0436516,0.0457088,0.047863,0.0501187,0.0524807,0.0549541,0.057544,0.060256,0.0630957,0.0660694,0.0691831,0.0724436,0.0758578,0.0794328,0.0831764,0.0870964,0.0912011,0.0954993,0.1,0.104713,0.109648,0.114815,0.120226,0.125893,0.131826,0.138038,0.144544,0.151356,0.158489,0.165959,0.17378,0.18197,0.190546,0.199526,0.20893,0.218776,0.229087,0.239883,0.251189,0.263027,0.275423,0.288403,0.301995,0.316228,0.331131,0.346737,0.363078,0.380189,0.398107,0.416869,0.436516,0.457088,0.47863,0.501187,0.524807,0.549541,0.57544,0.60256,0.630957,0.660693,0.691831,0.724436,0.758578,0.794328,0.831764,0.870964,0.912011,0.954993,1,1.04713,1.09648,1.14815,1.20226,1.25893,1.31826,1.38038,1.44544,1.51356,1.58489,1.65959,1.7378,1.8197,1.90546,1.99526,2.0893,2.18776,2.29087,2.39883,2.51189,2.63027,2.75423,2.88403,3.01995,3.16228,3.31131,3.46737,3.63078,3.80189,3.98107,4.16869,4.36516,4.57088,4.7863,5.01187,5.24807,5.49541,5.7544,6.0256,6.30957,6.60693,6.91831,7.24436,7.58578,7.94328,8.31764,8.70964,9.12011,9.54993,10,10.4713,10.9648,11.4815,12.0226,12.5893,13.1826,13.8038,14.4544,15.1356,15.8489,16.5959,17.378,18.197,19.0546,19.9526,20.893,21.8776,22.9087,23.9883,25.1189,26.3027,27.5423,28.8403,30.1995,31.6228,33.1131,34.6737,36.3078,38.0189,39.8107,41.6869,43.6516,45.7088,47.863,50.1187,52.4807,54.9541,57.544,60.256,63.0957,66.0694,69.1831,72.4436,75.8578,79.4328,83.1764,87.0964,91.2011,95.4993,100.};
//  float bin[371]={0,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.1,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.2,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.3,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.4,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.5,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.6,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.7,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.8,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.9,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1,1.05,1.1,1.15,1.2,1.25,1.3,1.35,1.4,1.45,1.5,1.55,1.6,1.65,1.7,1.75,1.8,1.85,1.9,1.95,2,2.05,2.1,2.15,2.2,2.25,2.3,2.35,2.4,2.45,2.5,2.55,2.6,2.65,2.7,2.75,2.8,2.85,2.9,2.95,3,3.05,3.1,3.15,3.2,3.25,3.3,3.35,3.4,3.45,3.5,3.55,3.6,3.65,3.7,3.75,3.8,3.85,3.9,3.95,4,4.05,4.1,4.15,4.2,4.25,4.3,4.35,4.4,4.45,4.5,4.55,4.6,4.65,4.7,4.75,4.8,4.85,4.9,4.95,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5,10,10.5,11,11.5,12,12.5,13,13.5,14,14.5,15,15.5,16,16.5,17,17.5,18,18.5,19,19.5,20,20.5,21,21.5,22,22.5,23,23.5,24,24.5,25,25.5,26,26.5,27,27.5,28,28.5,29,29.5,30,30.5,31,31.5,32,32.5,33,33.5,34,34.5,35,35.5,36,36.5,37,37.5,38,38.5,39,39.5,40,40.5,41,41.5,42,42.5,43,43.5,44,44.5,45,45.5,46,46.5,47,47.5,48,48.5,49,49.5,50,50.5,51,51.5,52,52.5,53,53.5,54,54.5,55,55.5,56,56.5,57,57.5,58,58.5,59,59.5,60,60.5,61,61.5,62,62.5,63,63.5,64,64.5,65,65.5,66,66.5,67,67.5,68,68.5,69,69.5,70,70.5,71,71.5,72,72.5,73,73.5,74,74.5,75,75.5,76,76.5,77,77.5,78,78.5,79,79.5,80,80.5,81,81.5,82,82.5,83,83.5,84,84.5,85,85.5,86,86.5,87,87.5,88,88.5,89,89.5,90,90.5,91,91.5,92,92.5,93,93.5,94,94.5,95,95.5,96,96.5,97,97.5,98,98.5,99,99.5,100}; 
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        for(int invtx=0; invtx<3; invtx++) 
        {
          h1_zero[ieta-16][iphi-63][depth-1][invtx] = new
            TH1D( Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                //10000, 0, 100);
            81, bin);
          h1_zero[ieta-16][iphi-63][depth-1][invtx]->Sumw2();
          h1_zero_depth[ieta-16][iphi-63][depth-1][invtx] = new
            TH1D( Form("h1_zero_depth_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                Form("h1_zero_depth_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                7, -0.5, 6.5);
          h1_zero_depth[ieta-16][iphi-63][depth-1][invtx]->Sumw2();
          h1_jetht[ieta-16][iphi-63][depth-1][invtx] = new
            TH1D( Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                //10000, 0, 100);
            81, bin);
          h1_jetht[ieta-16][iphi-63][depth-1][invtx]->Sumw2();
          h1_met[ieta-16][iphi-63][depth-1][invtx] = new
            TH1D( Form("h1_met_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                Form("h1_met_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                //10000, 0, 100);
            81, bin);
          h1_met[ieta-16][iphi-63][depth-1][invtx]->Sumw2();
          h1_pion[ieta-16][iphi-63][depth-1][invtx] = new
            TH1D( Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),
                //10000, 0, 100);
            81, bin);
          h1_pion[ieta-16][iphi-63][depth-1][invtx]->Sumw2();
         
          if(depth==1)
          {
            h2_jetht_energy_frac[ieta-16][iphi-63][invtx] = new
              TH2D( Form("h2_jetht_energy_frac_ieta%i_iphi%i_nvtx%i", ieta,iphi,invtx),
                  Form("h2_jetht_energy_frac_ieta%i_iphi%i_nvtx%i", ieta,iphi,invtx),
                  100, 0, 10, 7, 0.5, 7.5);
            h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->Sumw2();
            h2_zero_energy_frac[ieta-16][iphi-63][invtx] = new
              TH2D( Form("h2_zero_energy_frac_ieta%i_iphi%i_nvtx%i", ieta,iphi,invtx),
                  Form("h2_zero_energy_frac_ieta%i_iphi%i_nvtx%i", ieta,iphi,invtx),
                  100, 0, 10, 7, 0.5, 7.5);
            h2_zero_energy_frac[ieta-16][iphi-63][invtx]->Sumw2();
          }
        }
      }
    }
  }

  cout << "Analyzing ZeroBias : " << zero.GetEntries() << " events" << endl;
  // loop over trees
  for(unsigned int ientry=0; ientry<zero.GetEntries(); ientry++)
  {
    zero.GetEntry(ientry);  
    float zero_energy[14][4][7][3]; // ieta iphi depth nvtx 
    for(int ieta=16; ieta<30; ieta++)
    {
      for(int iphi=63; iphi<67; iphi++)
      {
        for(int depth=1; depth<8; depth++)
        {
          for(int invtx=0; invtx<3; invtx++) 
          {
            zero_energy[ieta-16][iphi-63][depth-1][invtx] = 0.; 
          }
        }
      }
    }
    //  
    for(unsigned int irec=0; irec<zero.HBHERecHitEnergy().size(); irec++)
    {
      // ndepth
      if(zero.HBHERecHitEnergy().at(irec)<0.5) 
      {
        int notherdepths=0;
        for(unsigned int irec2=0; irec2<zero.HBHERecHitEnergy().size(); irec2++)
        {
          if(zero.HBHERecHitIEta().at(irec)==zero.HBHERecHitIEta().at(irec2) &&
             zero.HBHERecHitIPhi().at(irec)==zero.HBHERecHitIPhi().at(irec2) && 
             zero.HBHERecHitDepth().at(irec)!=zero.HBHERecHitDepth().at(irec2))
          {
          notherdepths++;
          } 
        } 
        FillTH1D(h1_zero_depth[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][0], notherdepths, 1.);
      } 
      
      FillTH1D(h1_zero[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][0], zero.HBHERecHitEnergy().at(irec), 1.);
      if(zero.Nvtx().at(0)<25) 
        FillTH1D(h1_zero[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][1], zero.HBHERecHitEnergy().at(irec), 1.);
      if(zero.Nvtx().at(0)>45)
        FillTH1D(h1_zero[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][2], zero.HBHERecHitEnergy().at(irec), 1.);
      
      // store energy per channel first
      zero_energy[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][0] 
        = zero.HBHERecHitEnergy().at(irec);
      if(zero.Nvtx().at(0)<25) 
        zero_energy[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][1] 
          = zero.HBHERecHitEnergy().at(irec);
      if(zero.Nvtx().at(0)>45) 
        zero_energy[zero.HBHERecHitIEta().at(irec)-16][zero.HBHERecHitIPhi().at(irec)-63][zero.HBHERecHitDepth().at(irec)-1][2] 
          = zero.HBHERecHitEnergy().at(irec);
    } 
    
    // 
    for(int ieta=16; ieta<30; ieta++) 
    {
      for(int iphi=63; iphi<67; iphi++) 
      {
        for(int invtx=0; invtx<3; invtx++) 
        { 
          // first get the total energy per tower
          float energy=0.;
          for(int depth=1; depth<=7; depth++)
          {
            if(zero_energy[ieta-16][iphi-63][depth-1][invtx]==0.) continue;
             energy=energy+zero_energy[ieta-16][iphi-63][depth-1][invtx];
          } 
          if (energy==0.) continue;
          for(int depth=1; depth<=7; depth++)
            h2_zero_energy_frac[ieta-16][iphi-63][invtx]->Fill(energy, depth, zero_energy[ieta-16][iphi-63][depth-1][invtx]/energy); 
        } 
      } 
    } 
  
  } 

  cout << "Analyzing JetHT    : " << jetht.GetEntries() << " events" << endl;
  for(unsigned int ientry=0; ientry<jetht.GetEntries(); ientry++)
  {
    jetht.GetEntry(ientry); 
    float jetht_energy[14][4][7][3]; // ieta iphi depth nvtx 
    for(int ieta=16; ieta<30; ieta++)
    {
      for(int iphi=63; iphi<67; iphi++)
      {
        for(int depth=1; depth<8; depth++)
        {
          for(int invtx=0; invtx<3; invtx++) 
          {
            jetht_energy[ieta-16][iphi-63][depth-1][invtx] = 0.; 
          }
        }
      }
    }
            //  
    for(unsigned int irec=0; irec<jetht.HBHERecHitEnergy().size(); irec++)
    {
      FillTH1D(h1_jetht[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][0], jetht.HBHERecHitEnergy().at(irec), 1.);
      if(jetht.Nvtx().at(0)<25) 
        FillTH1D(h1_jetht[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][1], jetht.HBHERecHitEnergy().at(irec), 1.);
      if(jetht.Nvtx().at(0)>45) 
        FillTH1D(h1_jetht[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][2], jetht.HBHERecHitEnergy().at(irec), 1.); 

      // store energy per channel first
      jetht_energy[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][0] 
        = jetht.HBHERecHitEnergy().at(irec);
      if(jetht.Nvtx().at(0)<25) 
        jetht_energy[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][1] 
          = jetht.HBHERecHitEnergy().at(irec);
      if(jetht.Nvtx().at(0)>45) 
        jetht_energy[jetht.HBHERecHitIEta().at(irec)-16][jetht.HBHERecHitIPhi().at(irec)-63][jetht.HBHERecHitDepth().at(irec)-1][2] 
          = jetht.HBHERecHitEnergy().at(irec);
    } 
    
    // 
    for(int ieta=16; ieta<30; ieta++) 
    {
      for(int iphi=63; iphi<67; iphi++) 
      {
        for(int invtx=0; invtx<3; invtx++) 
        { 
          // first get the total energy per tower
          float energy=0.;
          for(int depth=1; depth<=7; depth++)
          {
            if(jetht_energy[ieta-16][iphi-63][depth-1][invtx]==0.) continue;
             energy=energy+jetht_energy[ieta-16][iphi-63][depth-1][invtx];
          } 
          if (energy==0.) continue;
          for(int depth=1; depth<=7; depth++)
            h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->Fill(energy, depth, jetht_energy[ieta-16][iphi-63][depth-1][invtx]/energy); 
        } 
      } 
    } 

  } 
  
  cout << "Analyzing MET      : " << met.GetEntries() << " events" << endl;
  for(unsigned int ientry=0; ientry<met.GetEntries(); ientry++)
  {
    met.GetEntry(ientry); 
    //  
    for(unsigned int irec=0; irec<met.HBHERecHitEnergy().size(); irec++)
    {
      FillTH1D(h1_met[met.HBHERecHitIEta().at(irec)-16][met.HBHERecHitIPhi().at(irec)-63][met.HBHERecHitDepth().at(irec)-1][0], met.HBHERecHitEnergy().at(irec), 1.);
      if(met.Nvtx().at(0)<25) 
        FillTH1D(h1_met[met.HBHERecHitIEta().at(irec)-16][met.HBHERecHitIPhi().at(irec)-63][met.HBHERecHitDepth().at(irec)-1][1], met.HBHERecHitEnergy().at(irec), 1.);
      if(met.Nvtx().at(0)>45) 
        FillTH1D(h1_met[met.HBHERecHitIEta().at(irec)-16][met.HBHERecHitIPhi().at(irec)-63][met.HBHERecHitDepth().at(irec)-1][2], met.HBHERecHitEnergy().at(irec), 1.);
    } 
  }

  cout << "Analyzing Pion     : " << pion.GetEntries() << " events" << endl;
  for(unsigned int ientry=0; ientry<pion.GetEntries(); ientry++) 
  {
    pion.GetEntry(ientry); 
    //  
    for(unsigned int irec=0; irec<pion.HBHERecHitEnergy().size(); irec++)
    {
      FillTH1D(h1_pion[pion.HBHERecHitIEta().at(irec)-16][pion.HBHERecHitIPhi().at(irec)-63][pion.HBHERecHitDepth().at(irec)-1][0], pion.HBHERecHitEnergy().at(irec), 1.);
      if(pion.Nvtx().at(0)<25) 
        FillTH1D(h1_pion[pion.HBHERecHitIEta().at(irec)-16][pion.HBHERecHitIPhi().at(irec)-63][pion.HBHERecHitDepth().at(irec)-1][1], pion.HBHERecHitEnergy().at(irec), 1.);
      if(pion.Nvtx().at(0)>45) 
        FillTH1D(h1_pion[pion.HBHERecHitIEta().at(irec)-16][pion.HBHERecHitIPhi().at(irec)-63][pion.HBHERecHitDepth().at(irec)-1][2], pion.HBHERecHitEnergy().at(irec), 1.);
    } 
  } 

  //
  TFile *HistFile = new TFile("hep17_erec.root", "RECREATE");
  gROOT->cd();
  HistFile->cd();
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        for(int invtx=0; invtx<3; invtx++)
        {
          if(h1_zero[ieta-16][iphi-63][depth-1][invtx]->Integral()!=0)
          {
            h1_zero[ieta-16][iphi-63][depth-1][invtx]->SetDirectory(0);
            h1_zero[ieta-16][iphi-63][depth-1][invtx]->Write(0);
            h1_zero_depth[ieta-16][iphi-63][depth-1][invtx]->SetDirectory(0);
            h1_zero_depth[ieta-16][iphi-63][depth-1][invtx]->Write(0);
          }
          if(h1_jetht[ieta-16][iphi-63][depth-1][invtx]->Integral()!=0)
          {
            h1_jetht[ieta-16][iphi-63][depth-1][invtx]->SetDirectory(0);
            h1_jetht[ieta-16][iphi-63][depth-1][invtx]->Write(0);
          }

          if(h1_met[ieta-16][iphi-63][depth-1][invtx]->Integral()!=0)
          {
            h1_met[ieta-16][iphi-63][depth-1][invtx]->SetDirectory(0);
            h1_met[ieta-16][iphi-63][depth-1][invtx]->Write(0);
          }
          if(h1_pion[ieta-16][iphi-63][depth-1][invtx]->Integral()!=0)
          {
            h1_pion[ieta-16][iphi-63][depth-1][invtx]->SetDirectory(0);
            h1_pion[ieta-16][iphi-63][depth-1][invtx]->Write(0);
          }

          if(depth==1 && h2_zero_energy_frac[ieta-16][iphi-63][invtx]->Integral()!=0)
          { 
            // renorm 
            for(int x=1; x<=h2_zero_energy_frac[ieta-16][iphi-63][invtx]->GetXaxis()->GetNbins(); x++)
            {
              float scale=0;
              scale = h2_zero_energy_frac[ieta-16][iphi-63][invtx]->Integral(x,x,1,7);
              if(scale==0) continue;
              for(int y=1; y<=7; y++)
              {
                h2_zero_energy_frac[ieta-16][iphi-63][invtx]->SetBinContent(x,y,
                  h2_zero_energy_frac[ieta-16][iphi-63][invtx]->GetBinContent(x,y)/scale
                );
              }
            }
            h2_zero_energy_frac[ieta-16][iphi-63][invtx]->SetDirectory(0);
            h2_zero_energy_frac[ieta-16][iphi-63][invtx]->Write(0);
          }

          if(depth==1 && h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->Integral()!=0)
          { 
            // renorm 
            for(int x=1; x<=h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->GetXaxis()->GetNbins(); x++)
            {
              float scale=0;
              scale = h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->Integral(x,x,1,7);
              if(scale==0) continue;
              for(int y=1; y<=7; y++)
              {
                h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->SetBinContent(x,y,
                  h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->GetBinContent(x,y)/scale
                );
              }
            }
            h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->SetDirectory(0);
            h2_jetht_energy_frac[ieta-16][iphi-63][invtx]->Write(0);
          }
        }
      }
    }
  }


}
