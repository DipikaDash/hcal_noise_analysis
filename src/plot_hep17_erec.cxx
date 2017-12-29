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

int rebin=3;

TH1D* renormTH1D(TH1D *h1) 
{ 
  TH1D *h1renorm = static_cast<TH1D*>(h1->Clone());
  for(int ibin=1; ibin<=h1->GetXaxis()->GetNbins(); ibin++) 
    h1renorm->SetBinContent(ibin, h1->GetBinContent(ibin)/(h1->GetXaxis()->GetBinUpEdge(ibin)-h1->GetXaxis()->GetBinLowEdge(ibin)));
  return h1renorm;
}

int main()
{
  TFile* infile = TFile::Open("hep17_erec.root"); 

  for(int invtx=0; invtx<3; invtx++) 
  { 
    TH1D *h1_zero[14][4][7]; // ieta iphi depth 
    TH1D *h1_jetht[14][4][7]; // ieta iphi depth 
    TH1D *h1_pion[14][4][7]; // ieta iphi depth  
  
    TString nvtxcut = "";
    if(invtx==1) nvtxcut = ", Nvtx<25";
    if(invtx==2) nvtxcut = ", Nvtx>45";
    

    for(int ieta=16; ieta<30; ieta++)
    {
      for(int iphi=63; iphi<67; iphi++)
      {
        for(int depth=1; depth<8; depth++)
        {
          if(infile->Get(Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx))) 
          { 
            h1_zero[ieta-16][iphi-63][depth-1]
              = renormTH1D(static_cast<TH1D*>(infile->Get(Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx))));
            h1_zero[ieta-16][iphi-63][depth-1]->Rebin(rebin);
            h1cosmetic(h1_zero[ieta-16][iphi-63][depth-1],  Form("ieta=%i,iphi=%i,depth=%i%s", ieta,iphi,depth,nvtxcut.Data()), kBlack, 1, 0, "E_{rechit} [GeV]"); 
            h1_zero[ieta-16][iphi-63][depth-1]->SetMarkerSize(0); 
            h1_zero[ieta-16][iphi-63][depth-1]->GetXaxis()->SetRange(2,10000); 
          }
          else 
          { 
            h1_zero[ieta-16][iphi-63][depth-1] = new TH1D(Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),Form("h1_zero_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),1,0,1);
          } 

          if(infile->Get(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx)))
          {
            h1_jetht[ieta-16][iphi-63][depth-1]
              = renormTH1D(static_cast<TH1D*>(infile->Get(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx))));
            h1_jetht[ieta-16][iphi-63][depth-1]->Rebin(rebin);
            h1cosmetic(h1_jetht[ieta-16][iphi-63][depth-1], Form("ieta=%i,iphi=%i,depth=%i%s", ieta,iphi,depth,nvtxcut.Data()), kRed,   1, 0, "E_{rechit} [GeV]"); 
            h1_jetht[ieta-16][iphi-63][depth-1]->SetMarkerSize(0);
            h1_jetht[ieta-16][iphi-63][depth-1]->GetXaxis()->SetRange(2,10000); 
          }
          else 
          { 
            h1_jetht[ieta-16][iphi-63][depth-1] = new TH1D(Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),Form("h1_jetht_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),1,0,1);
          } 

          if(infile->Get(Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx)))
          {
            h1_pion[ieta-16][iphi-63][depth-1]
              = renormTH1D(static_cast<TH1D*>(infile->Get(Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx))));
            h1_pion[ieta-16][iphi-63][depth-1]->Rebin(rebin);
            h1cosmetic(h1_pion[ieta-16][iphi-63][depth-1], Form("ieta=%i,iphi=%i,depth=%i%s", ieta,iphi,depth,nvtxcut.Data()), kBlue,   1, 0, "E_{rechit} [GeV]"); 
            h1_pion[ieta-16][iphi-63][depth-1]->SetMarkerSize(0);
            h1_pion[ieta-16][iphi-63][depth-1]->GetXaxis()->SetRange(2,10000); 
          }
          else 
          { 
            h1_pion[ieta-16][iphi-63][depth-1] = new TH1D(Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),Form("h1_pion_erec_ieta%i_iphi%i_depth%i_nvtx%i", ieta,iphi,depth,invtx),1,0,1);
          } 
        }
      }
    }

    TLegend *l1 = new TLegend(0.6, 0.7, 0.90, 0.90);
    l1->SetNColumns(1);
    l1->SetBorderSize(0);
    l1->SetFillColor(0);
    l1->SetFillStyle(0);
    l1->SetTextAlign(12);
    //l1->SetTextSize(0.06);
    l1->SetFillColor(kWhite);
    l1->SetLineColor(kWhite);
    l1->SetShadowColor(kWhite);
    l1->AddEntry(h1_zero[5][0][0],   " ZeroBias",  "l");
    l1->AddEntry(h1_jetht[5][0][0],  " JetHT",     "l");
    l1->AddEntry(h1_pion[5][0][0],   " Pion MC",     "l");

    //
    for(int ieta=16; ieta<30; ieta++)
    {
      TH1D *h1_jetht_ratio[4][7]; 
      TH1D *h1_pion_ratio[4][7]; 
      TCanvas *c = new TCanvas("c","c",3200,1800);
      c->Divide(7,4); 
      for(int iphi=63; iphi<67; iphi++)
      {
        for(int depth=1; depth<8; depth++) 
        {
          if(h1_zero[ieta-16][iphi-63][depth-1]->Integral()!=0) 
          { 
            h1_zero[ieta-16][iphi-63][depth-1]->Scale(1./h1_zero[ieta-16][iphi-63][depth-1]->Integral());
            h1_jetht[ieta-16][iphi-63][depth-1]->Scale(h1_zero[ieta-16][iphi-63][depth-1]->Integral(1,10)/h1_jetht[ieta-16][iphi-63][depth-1]->Integral(1,10));
            h1_pion[ieta-16][iphi-63][depth-1]->Scale(h1_zero[ieta-16][iphi-63][depth-1]->Integral(1,10)/h1_pion[ieta-16][iphi-63][depth-1]->Integral(1,10));
            h1_jetht_ratio[iphi-63][depth-1] = static_cast<TH1D*>(h1_jetht[ieta-16][iphi-63][depth-1]->Clone()); 
            h1_jetht_ratio[iphi-63][depth-1]->Divide(h1_zero[ieta-16][iphi-63][depth-1]);
            h1_pion_ratio[iphi-63][depth-1] = static_cast<TH1D*>(h1_pion[ieta-16][iphi-63][depth-1]->Clone()); 
            h1_pion_ratio[iphi-63][depth-1]->Divide(h1_zero[ieta-16][iphi-63][depth-1]);
            c->cd((iphi-63)*7+depth);
            //          TCanvas *c = new TCanvas("c","c",600,400); 
            //          c->cd();
            // pad 1
            TPad *pad1 = new TPad("p_main", "p_main", 0.0, 0.25, 1.0, 1.0);
            //        pad1->SetBottomMargin(0.04);
            //        pad1->SetRightMargin(0.1);
            //        pad1->SetLeftMargin(0.2);
            pad1->Draw();
            pad1->cd();
            pad1->cd()->SetLogx(1);
            pad1->cd()->SetLogy(1); 
            h1_zero[ieta-16][iphi-63][depth-1]->GetXaxis()->SetLabelSize(0.0);
            h1_zero[ieta-16][iphi-63][depth-1]->GetYaxis()->SetLabelSize(0.06);
            h1_zero[ieta-16][iphi-63][depth-1]->Draw("e");
            h1_jetht[ieta-16][iphi-63][depth-1]->Draw("e same");
            //          h1_pion[ieta-16][iphi-63][depth-1]->Draw("e same");
            l1->Draw("same");
            // pad 2 
            //          c->cd();
            c->cd((iphi-63)*7+depth);
            TPad *pad2 = new TPad("p_pull", "p_pull", 0.0, 0.0, 1.0, 0.3);
            //          pad2->SetLeftMargin(0.2);
            //          pad2->SetTopMargin(0.04);
            //          pad2->SetRightMargin(0.1);
            pad2->SetBottomMargin(0.4); 
            pad2->Draw();
            pad2->cd();
            pad2->cd()->SetLogx(1);
            h1_jetht_ratio[iphi-63][depth-1]->SetMaximum(4);
            h1_jetht_ratio[iphi-63][depth-1]->SetMinimum(0); 
            h1_jetht_ratio[iphi-63][depth-1]->GetYaxis()->SetNdivisions(505);;
            h1_jetht_ratio[iphi-63][depth-1]->GetYaxis()->SetTitle("Events");
            h1_jetht_ratio[iphi-63][depth-1]->GetYaxis()->SetLabelSize(0.15);
            h1_jetht_ratio[iphi-63][depth-1]->GetXaxis()->SetLabelSize(0.15);
            h1_jetht_ratio[iphi-63][depth-1]->GetXaxis()->SetTitle("E_{rec} [GeV]");
            h1_jetht_ratio[iphi-63][depth-1]->GetXaxis()->SetTitleSize(0.15);
            h1_jetht_ratio[iphi-63][depth-1]->GetXaxis()->SetTitleOffset(1.2);
            h1_jetht_ratio[iphi-63][depth-1]->Draw("e");
            //          h1_pion_ratio[iphi-63][depth-1]->Draw("e same");
            //          c->Print(Form("plots/h1_erec_ieta%i_iphi%i_depth%i.pdf", ieta, iphi, depth));
            //          delete c;
          }
        }
      }
      c->Print(Form("plots/h1_erec_ieta%i_nvtx%i.pdf", ieta, invtx));
      //delete h1_jetht_ratio;
      //delete h1_pion_ratio;
      delete c;
    }
  }
}
