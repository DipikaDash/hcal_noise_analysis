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
    TFile* infile = TFile::Open("optimize_hf_singlemuon.root"); 

    TH1D *h1_met        = static_cast<TH1D*>(infile->Get("h1_met"));
    TH1D *h1_met_tdc    = static_cast<TH1D*>(infile->Get("h1_met_tdc"));
    TH1D *h1_met_asym   = static_cast<TH1D*>(infile->Get("h1_met_asym"));
    TH1D *h1_met_both   = static_cast<TH1D*>(infile->Get("h1_met_both"));
    TH1D *h1_met_cor    = static_cast<TH1D*>(infile->Get("h1_met_cor"));

    h1_met->Rebin(4);
    h1_met_tdc->Rebin(4);
    h1_met_asym->Rebin(4);
    h1_met_both->Rebin(4);

    h1cosmetic(h1_met,      "Nominal MET",                   kBlack,    2, 0, "MET [GeV]"); 
    h1cosmetic(h1_met_tdc,  "MET with TDC cut",              kBlue,     2, 0, "MET [GeV]"); 
    h1cosmetic(h1_met_asym, "MET with charge asymmetry cut", kGreen,    2, 0, "MET [GeV]"); 
    h1cosmetic(h1_met_both, "MET with both cuts",            kRed,      2, 0, "MET [GeV]"); 
    h1cosmetic(h1_met_cor,  "Nominal MET - Corrected MET",   kRed,      2, 0, "Nominal MET - Corrected MET [GeV]");  


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
    l1->AddEntry(h1_met,          " Nominal",               "l");
    l1->AddEntry(h1_met_tdc,      " TDC",                   "l");
    l1->AddEntry(h1_met_asym,     " Charge asym ",          "l");
    l1->AddEntry(h1_met_both,     " TDC + Charge asym ",    "l");

    TCanvas *c = new TCanvas("c","c",800,800);
    c->Divide(2,2);
    c->cd(1);
    c->cd(1)->SetLogy(1);
    h1_met->Draw("hist");
    h1_met_tdc->Draw("hist same");
    h1_met_asym->Draw("hist same");
    h1_met_both->Draw("hist same");
    l1->Draw();
    c->cd(2);
    c->cd(2)->SetLogy(1);
    h1_met_cor->Draw("hist");
    c->cd(3);
    c->cd(3)->SetLogy(0);
    h1_met->Draw("hist");
    h1_met_tdc->Draw("hist same");
    h1_met_asym->Draw("hist same");
    h1_met_both->Draw("hist same");
    l1->Draw();
    c->cd(4);
    c->cd(4)->SetLogy(0);
    h1_met_cor->Draw("hist");
    c->Print("plots/met.pdf"); 

    cout << "MET>100 before cleaning: " << h1_met->Integral(6,100) << endl;
    cout << "MET>100 after cleaning : " << h1_met_both->Integral(6,100) << endl;

}
