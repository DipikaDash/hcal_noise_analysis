#include <iostream>
#include <vector>

#include "TSystem.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TFile.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TString.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"

#include "utilities.hpp"

using namespace std;

int main()
{
  TFile* infile = TFile::Open("hep17_erec.root"); 

  TH1D *h1_zero[14][4][7]; // ieta iphi depth 
  TH1D *h1_jetht[14][4][7]; // ieta iphi depth 
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      for(int depth=1; depth<8; depth++)
      {
        if(infile->Get(Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth))) 
        { 
          h1_zero[ieta-16][iphi-63][depth-1]
           = static_cast<TH1D*>(infile->Get(Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth)));
          h1_zero[ieta-16][iphi-63][depth-1]->Rebin(1);
          h1cosmetic(h1_zero[ieta-16][iphi-63][depth-1],  Form("ieta=%i,iphi=%i,depth=%i", ieta,iphi,depth), kBlack, 1, 0, "E_{rechit} [GeV]"); 
        }
        else 
        { 
          h1_zero[ieta-16][iphi-63][depth-1] = new TH1D(Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),Form("h1_zero_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),1,0,1);
        } 

        if(infile->Get(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth)))
        {
          h1_jetht[ieta-16][iphi-63][depth-1]
           = static_cast<TH1D*>(infile->Get(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth)));
          h1_jetht[ieta-16][iphi-63][depth-1]->Rebin(1);
          h1cosmetic(h1_jetht[ieta-16][iphi-63][depth-1], Form("ieta=%i,iphi=%i,depth=%i", ieta,iphi,depth), kRed,   1, 0, "E_{rechit} [GeV]"); 
        }
        else 
        { 
          h1_jetht[ieta-16][iphi-63][depth-1] = new TH1D(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),Form("h1_jetht_erec_ieta%i_iphi%i_depth%i", ieta,iphi,depth),1,0,1);
        } 
      }
    }
  }

  TLegend *l1 = new TLegend(0.5, 0.7, 0.90, 0.90);
  l1->SetNColumns(1);
  l1->SetBorderSize(0);
  l1->SetFillColor(0);
  l1->SetFillStyle(0);
  l1->SetTextAlign(12);
  //l1->SetTextSize(0.06);
  l1->SetFillColor(kWhite);
  l1->SetLineColor(kWhite);
  l1->SetShadowColor(kWhite);
  l1->AddEntry(h1_zero[0][0][0],   " ZeroBias",  "l");
  l1->AddEntry(h1_jetht[0][0][0],  " JetHT",     "l");

  //
  for(int ieta=16; ieta<30; ieta++)
  {
    for(int iphi=63; iphi<67; iphi++)
    {
      TCanvas *c = new TCanvas("c","c",1400,200);
      c->Divide(7,1); 
      for(int depth=1; depth<8; depth++) 
      {
        c->cd(depth);
        c->cd(depth)->SetLogy(1);
        c->cd(depth)->SetLogx(1);  
        if(h1_zero[ieta-16][iphi-63][depth-1]->Integral()!=0) 
        {
          h1_zero[ieta-16][iphi-63][depth-1]->DrawNormalized("e");
          h1_jetht[ieta-16][iphi-63][depth-1]->DrawNormalized("e same");
        }
      }
      c->Print(Form("plots/h1_erec_ieta%i_iphi%i.pdf", ieta,iphi));
      delete c;
    }
  }

}
