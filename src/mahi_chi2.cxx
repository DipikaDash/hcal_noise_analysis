#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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

  TH1D *h1_1chi2_1pulse  = new TH1D("h1_1chi2_1pulse", "h1_1chi2_1pulse", 100, 0., 100.);
  TH1D *h1_1chi2_3pulse  = new TH1D("h1_1chi2_3pulse", "h1_1chi2_3pulse", 100, 0., 100.);
  
  TH1D *h1_niter_1pulse  = new TH1D("h1_niter_1pulse", "h1_niter_1pulse", 10, 0., 10.);
  TH1D *h1_niter_3pulse  = new TH1D("h1_niter_3pulse", "h1_niter_3pulse", 10, 0., 10.);
  
  TH1D *h1_12chi2_1pulse  = new TH1D("h1_12chi2_1pulse", "h1_12chi2_1pulse", 100, -1., 1.);
  TH1D *h1_12chi2_3pulse  = new TH1D("h1_12chi2_3pulse", "h1_12chi2_3pulse", 100, -1., 1.);
  TH1D *h1_23chi2_1pulse  = new TH1D("h1_23chi2_1pulse", "h1_23chi2_1pulse", 100, -1., 1.);
  TH1D *h1_23chi2_3pulse  = new TH1D("h1_23chi2_3pulse", "h1_23chi2_3pulse", 100, -1., 1.);
  TH1D *h1_34chi2_1pulse  = new TH1D("h1_34chi2_1pulse", "h1_34chi2_1pulse", 100, -1., 1.);
  TH1D *h1_34chi2_3pulse  = new TH1D("h1_34chi2_3pulse", "h1_34chi2_3pulse", 100, -1., 1.);
  TH1D *h1_45chi2_1pulse  = new TH1D("h1_45chi2_1pulse", "h1_45chi2_1pulse", 100, -1., 1.);
  TH1D *h1_45chi2_3pulse  = new TH1D("h1_45chi2_3pulse", "h1_45chi2_3pulse", 100, -1., 1.);
  
  TH1D *h1_r_12chi2_1pulse  = new TH1D("h1_r_12chi2_1pulse", "h1_r_12chi2_1pulse", 100, -1., 1.);
  TH1D *h1_r_12chi2_3pulse  = new TH1D("h1_r_12chi2_3pulse", "h1_r_12chi2_3pulse", 100, -1., 1.);
  TH1D *h1_r_23chi2_1pulse  = new TH1D("h1_r_23chi2_1pulse", "h1_r_23chi2_1pulse", 100, -1., 1.);
  TH1D *h1_r_23chi2_3pulse  = new TH1D("h1_r_23chi2_3pulse", "h1_r_23chi2_3pulse", 100, -1., 1.);
  TH1D *h1_r_34chi2_1pulse  = new TH1D("h1_r_34chi2_1pulse", "h1_r_34chi2_1pulse", 100, -1., 1.);
  TH1D *h1_r_34chi2_3pulse  = new TH1D("h1_r_34chi2_3pulse", "h1_r_34chi2_3pulse", 100, -1., 1.);
  TH1D *h1_r_45chi2_1pulse  = new TH1D("h1_r_45chi2_1pulse", "h1_r_45chi2_1pulse", 100, -1., 1.);
  TH1D *h1_r_45chi2_3pulse  = new TH1D("h1_r_45chi2_3pulse", "h1_r_45chi2_3pulse", 100, -1., 1.);
  
  TH2D *h2_1chi2vse_1pulse  = new TH2D("h2_1chi2vse_1pulse", "h2_1chi2vse_1pulse", 100, 0, 10, 100, 0., 100.);
  TH2D *h2_1chi2vse_3pulse  = new TH2D("h2_1chi2vse_3pulse", "h2_1chi2vse_3pulse", 100, 0, 10, 100, 0., 100.);
  
  TH2D *h2_nitervse_1pulse  = new TH2D("h2_nitervse_1pulse", "h2_nitervse_1pulse", 100, 0, 10, 10, 0., 10.);
  TH2D *h2_nitervse_3pulse  = new TH2D("h2_nitervse_3pulse", "h2_nitervse_3pulse", 100, 0, 10, 10, 0., 10.);
  
  TH2D *h2_1chi2vsniter_1pulse  = new TH2D("h2_1chi2vsniter_1pulse", "h2_1chi2vsniter_1pulse", 10, 0, 10, 100, 0., 100.);
  TH2D *h2_1chi2vsniter_3pulse  = new TH2D("h2_1chi2vsniter_3pulse", "h2_1chi2vsniter_3pulse", 10, 0, 10, 100, 0., 100.);

  ifstream filein("/home/users/jaehyeok/scratch/log_250k.txt");
  string line;
  if(filein.is_open()) {
    while(filein.good()){

      // get a line from fin_data
      getline(filein, line);
      
      if(line.find("#")!=string::npos ) continue;

      float temp[100];
      for(int i=0; i<100; i++) temp[i]=-1111;  
     
      int is1pulse=0;

      stringstream stream(line);
      for(int i=0; i<100; i++)  
      {
        stream >> temp[i];  
        if(temp[i]) continue;
      }

      vector<float> onepulse; 
      vector<float> threepulse; 
      vector<float> energy_coord; 
      
      for(int i=0; i<100; i++) 
      { 
        if(temp[i]==111111) is1pulse++;
      }

      // ----------------------------------------------
      if(is1pulse==1) 
      { 
        for(int i=0; i<100; i++) 
        {
          if(temp[i]==-1111) continue;
          if(temp[i]!=111111)  
          {
            energy_coord.push_back(temp[i]);
          }
        }
      }

      // ----------------------------------------------
      if(is1pulse!=1) 
      {
        int howmany111111=0;
        for(int i=0; i<100; i++) 
        {
          if(temp[i]==-1111) continue;

          // check which 111111
          if(temp[i]==111111) 
          { 
            howmany111111++;  
          } 

          if(temp[i]!=111111) 
          { 
            if(howmany111111==1) // always 1-pulse
            {
              onepulse.push_back(temp[i]);
            }

            if(howmany111111==2)
            {
              if(is1pulse==2) // 1-pulse 
              { 
                energy_coord.push_back(temp[i]);
              }
              if(is1pulse==3)  //3-pulse
              {
                threepulse.push_back(temp[i]);
              }
            }
            if(howmany111111==3)
            {
              energy_coord.push_back(temp[i]);
            }
          } 
        }
      } 

      if(0)  // debug
      {
        for(unsigned int i=0; i<onepulse.size(); i++) 
          cout << onepulse.at(i) << " ";   
        //for(unsigned int i=0; i<threepulse.size(); i++) 
        //  cout << threepulse.at(i) << " ";   
        //for(unsigned int i=0; i<energy_coord.size(); i++) 
        //  cout << energy_coord.at(i) << " ";   
        cout << endl;
      }

      // vectors are ready. let's make plots
      for(unsigned int i=0; i<onepulse.size(); i++) 
      {
        if(i==0)
        {
          FillTH1D(h1_1chi2_1pulse, onepulse.at(i), 1);
          FillTH2D(h2_1chi2vse_1pulse, energy_coord.at(0), onepulse.at(i), 1);
        }
        if(i==1) 
        { 
          FillTH1D(h1_12chi2_1pulse, onepulse.at(i)-onepulse.at(i-1), 1);
          FillTH1D(h1_r_12chi2_1pulse, (onepulse.at(i)-onepulse.at(i-1))/onepulse.at(i-1), 1); 
        }
        if(i==2) 
        { 
          FillTH1D(h1_23chi2_1pulse, onepulse.at(i)-onepulse.at(i-1), 1);
          FillTH1D(h1_r_23chi2_1pulse, (onepulse.at(i)-onepulse.at(i-1))/onepulse.at(i-1), 1);
        }
        if(i==3) 
        { 
          FillTH1D(h1_34chi2_1pulse, onepulse.at(i)-onepulse.at(i-1), 1);
          FillTH1D(h1_r_34chi2_1pulse, (onepulse.at(i)-onepulse.at(i-1))/onepulse.at(i-1), 1);
        }
        if(i==4) 
        { 
          FillTH1D(h1_45chi2_1pulse, onepulse.at(i)-onepulse.at(i-1), 1);
          FillTH1D(h1_r_45chi2_1pulse, (onepulse.at(i)-onepulse.at(i-1))/onepulse.at(i-1), 1);
        }
      }
      for(unsigned int i=0; i<threepulse.size(); i++) 
      {
        if(i==0)
        {
          FillTH1D(h1_1chi2_3pulse, threepulse.at(i), 1);
          FillTH2D(h2_1chi2vse_3pulse, energy_coord.at(0), threepulse.at(i), 1);
        }
        if(i==1) 
        { 
          FillTH1D(h1_12chi2_3pulse, threepulse.at(i)-threepulse.at(i-1), 1);
          FillTH1D(h1_r_12chi2_3pulse, (threepulse.at(i)-threepulse.at(i-1))/threepulse.at(i-1), 1);
          cout << "diff: " << threepulse.at(i)-threepulse.at(i-1) << endl;
        }
        if(i==2) 
        { 
          FillTH1D(h1_23chi2_3pulse, threepulse.at(i)-threepulse.at(i-1), 1);
          FillTH1D(h1_r_23chi2_3pulse, (threepulse.at(i)-threepulse.at(i-1))/threepulse.at(i-1), 1);
        }
        if(i==3) 
        { 
          FillTH1D(h1_34chi2_3pulse, threepulse.at(i)-threepulse.at(i-1), 1);
          FillTH1D(h1_r_34chi2_3pulse, (threepulse.at(i)-threepulse.at(i-1))/threepulse.at(i-1), 1);
        }
        if(i==4) 
        { 
          FillTH1D(h1_45chi2_3pulse, threepulse.at(i)-threepulse.at(i-1), 1);
          FillTH1D(h1_r_45chi2_3pulse, (threepulse.at(i)-threepulse.at(i-1))/threepulse.at(i-1), 1);
        }
      }
      if(onepulse.size()) 
      { 
        FillTH1D(h1_niter_1pulse, onepulse.size(), 1);
        FillTH2D(h2_nitervse_1pulse, energy_coord.at(0), onepulse.size(), 1);
        FillTH2D(h2_1chi2vsniter_1pulse, onepulse.size(), onepulse.at(0), 1);
      }
      if(threepulse.size())  
      { 
        FillTH1D(h1_niter_3pulse, threepulse.size(), 1);
        FillTH2D(h2_nitervse_3pulse, energy_coord.at(0), threepulse.size(), 1);
        FillTH2D(h2_1chi2vsniter_3pulse, threepulse.size(), threepulse.at(0), 1);
      }
    }
  } 
  filein.close();

  //
  TCanvas *c_1chi2 = new TCanvas("c_1chi2","c_1chi2",800,2000);
  c_1chi2->Divide(2,5); 
  c_1chi2->cd(1); c_1chi2->cd(1)->SetLogy(1); h1_1chi2_1pulse->Draw("hist");
  c_1chi2->cd(2); c_1chi2->cd(2)->SetLogy(1); h1_1chi2_3pulse->Draw("hist");
  c_1chi2->cd(3); c_1chi2->cd(3)->SetLogz(1); h2_1chi2vse_1pulse->Draw("colz");
  c_1chi2->cd(4); c_1chi2->cd(4)->SetLogz(1); h2_1chi2vse_3pulse->Draw("colz");
  c_1chi2->cd(5); c_1chi2->cd(5)->SetLogy(1); h1_niter_1pulse->Draw("hist");
  c_1chi2->cd(6); c_1chi2->cd(6)->SetLogy(1); h1_niter_3pulse->Draw("hist");
  c_1chi2->cd(7); c_1chi2->cd(7)->SetLogz(1); h2_nitervse_1pulse->Draw("colz");
  c_1chi2->cd(8); c_1chi2->cd(8)->SetLogz(1); h2_nitervse_3pulse->Draw("colz");
  c_1chi2->cd(9); c_1chi2->cd(9)->SetLogz(1); h2_1chi2vsniter_1pulse->Draw("colz");
  c_1chi2->cd(10); c_1chi2->cd(10)->SetLogz(1); h2_1chi2vsniter_3pulse->Draw("colz");
  c_1chi2->Print("plots/c_1chi2.pdf"); 
  
  //
  TCanvas *c_deltachi2_onepulse = new TCanvas("c_deltachi2_onepulse","c_deltachi2_onepulse",1600,800);
  c_deltachi2_onepulse->Divide(4,2); 
  c_deltachi2_onepulse->cd(1); c_deltachi2_onepulse->cd(1)->SetLogy(1); h1_12chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(2); c_deltachi2_onepulse->cd(2)->SetLogy(1); h1_23chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(3); c_deltachi2_onepulse->cd(3)->SetLogy(1); h1_34chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(4); c_deltachi2_onepulse->cd(4)->SetLogy(1); h1_45chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(5); c_deltachi2_onepulse->cd(5)->SetLogy(1); h1_r_12chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(6); c_deltachi2_onepulse->cd(6)->SetLogy(1); h1_r_23chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(7); c_deltachi2_onepulse->cd(7)->SetLogy(1); h1_r_34chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->cd(8); c_deltachi2_onepulse->cd(8)->SetLogy(1); h1_r_45chi2_1pulse->Draw("hist");
  c_deltachi2_onepulse->Print("plots/c_deltachi2_onepulse.pdf"); 

  //
  TCanvas *c_deltachi2_threepulse = new TCanvas("c_deltachi2_threepulse","c_deltachi2_threepulse",1600,800);
  c_deltachi2_threepulse->Divide(4,2); 
  c_deltachi2_threepulse->cd(1); c_deltachi2_threepulse->cd(1)->SetLogy(1); h1_12chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(2); c_deltachi2_threepulse->cd(2)->SetLogy(1); h1_23chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(3); c_deltachi2_threepulse->cd(3)->SetLogy(1); h1_34chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(4); c_deltachi2_threepulse->cd(4)->SetLogy(1); h1_45chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(5); c_deltachi2_threepulse->cd(5)->SetLogy(1); h1_r_12chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(6); c_deltachi2_threepulse->cd(6)->SetLogy(1); h1_r_23chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(7); c_deltachi2_threepulse->cd(7)->SetLogy(1); h1_r_34chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->cd(8); c_deltachi2_threepulse->cd(8)->SetLogy(1); h1_r_45chi2_3pulse->Draw("hist");
  c_deltachi2_threepulse->Print("plots/c_deltachi2_threepulse.pdf"); 

}


