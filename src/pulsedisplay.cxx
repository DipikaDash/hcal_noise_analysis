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
#include "TChain.h"
#include "TError.h"
#include "THStack.h"

#include "utilities.hpp"

using namespace std;

bool printHit(int run, int ls, int evt, int ieta, int iphi, int depth)
{
  bool printPulses = false;
  /* R = 0.7-0.9 or 1.3-1.6
  if (run==316944 && ls==20 && evt==1188239 && ieta==-28 && iphi==19 && depth==5) printPulses=true;
  if (run==316944 && ls==20 && evt==1183221 && ieta==-28 && iphi==59 && depth==4) printPulses=true;
  if (run==316944 && ls==20 && evt==1189348 && ieta==-28 && iphi==51 && depth==5) printPulses=true;
  if (run==316944 && ls==20 && evt==1223228 && ieta==-24 && iphi==41 && depth==2) printPulses=true;
  if (run==316944 && ls==20 && evt==1239916 && ieta==-28 && iphi==65 && depth==5) printPulses=true;
  if (run==316944 && ls==20 && evt==1215720 && ieta==27 && iphi==63 && depth==2) printPulses=true;
  if (run==316944 && ls==20 && evt==1246187 && ieta==28 && iphi==69 && depth==4) printPulses=true;
  if (run==316944 && ls==21 && evt==1617238 && ieta==28 && iphi==3 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==1407137 && ieta==-28 && iphi==67 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==2115348 && ieta==27 && iphi==5 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==2143618 && ieta==-28 && iphi==3 && depth==4) printPulses=true;
  if (run==316944 && ls==21 && evt==1589710 && ieta==-29 && iphi==59 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1949849 && ieta==-24 && iphi==51 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2439451 && ieta==24 && iphi==15 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2377929 && ieta==-28 && iphi==21 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==2738506 && ieta==-29 && iphi==15 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2497165 && ieta==28 && iphi==61 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==2431834 && ieta==-25 && iphi==65 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1903071 && ieta==-28 && iphi==35 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==1293509 && ieta==27 && iphi==23 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2368053 && ieta==25 && iphi==9 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1576109 && ieta==-28 && iphi==19 && depth==6) printPulses=true;
  if (run==316944 && ls==21 && evt==2609972 && ieta==-28 && iphi==25 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==1762703 && ieta==-28 && iphi==13 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==1989641 && ieta==25 && iphi==35 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==2256905 && ieta==-29 && iphi==69 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2390004 && ieta==28 && iphi==45 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2485054 && ieta==24 && iphi==23 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2383680 && ieta==29 && iphi==1 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1967801 && ieta==-29 && iphi==59 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2459053 && ieta==-28 && iphi==65 && depth==4) printPulses=true;
  if (run==316944 && ls==21 && evt==2407792 && ieta==-28 && iphi==61 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2407792 && ieta==-28 && iphi==61 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==2729772 && ieta==28 && iphi==49 && depth==5) printPulses=true;
  if (run==316944 && ls==21 && evt==1493732 && ieta==-24 && iphi==67 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1895836 && ieta==-28 && iphi==27 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==1895836 && ieta==-29 && iphi==27 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2270234 && ieta==28 && iphi==11 && depth==2) printPulses=true;
  */
  if (run==316944 && ls==20 && evt==1229992 && ieta==23 && iphi==21 && depth==2) printPulses=true;
  if (run==316944 && ls==20 && evt==1243270 && ieta==24 && iphi==57 && depth==2) printPulses=true;
  if (run==316944 && ls==20 && evt==1243270 && ieta==25 && iphi==57 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2432478 && ieta==22 && iphi==11 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2432478 && ieta==23 && iphi==11 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2432478 && ieta==22 && iphi==11 && depth==3) printPulses=true;
  if (run==316944 && ls==21 && evt==2071904 && ieta==-24 && iphi==5 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2704352 && ieta==24 && iphi==33 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2143903 && ieta==-29 && iphi==19 && depth==2) printPulses=true;
  if (run==316944 && ls==21 && evt==2143903 && ieta==-28 && iphi==19 && depth==6) printPulses=true;
  return printPulses;
}

int main()
{
    gErrorIgnoreLevel=kError+1;

    for(int ip=0; ip<2; ip++) 
    { 

    TChain* ch = new TChain("mahiDebugger/HcalTree"); 
    if(ip==0) ch->Add("/Users/jaehyeok/scratch/mahidebugger_3p1b.root"); 
    if(ip==1) ch->Add("/Users/jaehyeok/scratch/mahidebugger_7p.root"); 

    int run;
    int ls;
    int evt;
    int ieta;
    int iphi;
    int depth;
    float inputTS[10];
    float itPulse[10];
    float p1Pulse[10];
    float n1Pulse[10];
    float p2Pulse[10];
    float n2Pulse[10];
    float p3Pulse[10];
    float n3Pulse[10];
    float p1Energy;
    float n1Energy;
    float p2Energy;
    float n2Energy;
    float p3Energy;
    float n3Energy;
    float mahiEnergy;
    float pedEnergy;
    float inGain;

    ch->SetBranchAddress("run",        &run);
    ch->SetBranchAddress("ls",         &ls);
    ch->SetBranchAddress("evt",        &evt);
    ch->SetBranchAddress("ieta",       &ieta);
    ch->SetBranchAddress("iphi",       &iphi);
    ch->SetBranchAddress("depth",      &depth);
    ch->SetBranchAddress("inputTS",    &inputTS);
    ch->SetBranchAddress("itPulse",    &itPulse);
    ch->SetBranchAddress("p1Pulse",    &p1Pulse);
    ch->SetBranchAddress("n1Pulse",    &n1Pulse);
    ch->SetBranchAddress("p2Pulse",    &p2Pulse);
    ch->SetBranchAddress("n2Pulse",    &n2Pulse);
    ch->SetBranchAddress("p3Pulse",    &p3Pulse);
    ch->SetBranchAddress("n3Pulse",    &n3Pulse);
    ch->SetBranchAddress("p1Energy",   &p1Energy);
    ch->SetBranchAddress("n1Energy",   &n1Energy);
    ch->SetBranchAddress("p2Energy",   &p2Energy);
    ch->SetBranchAddress("n2Energy",   &n2Energy);
    ch->SetBranchAddress("p3Energy",   &p3Energy);
    ch->SetBranchAddress("n3Energy",   &n3Energy);
    ch->SetBranchAddress("mahiEnergy", &mahiEnergy);
    ch->SetBranchAddress("pedEnergy",  &pedEnergy);
    ch->SetBranchAddress("inGain",     &inGain);

    int nentries = ch->GetEntries();

    float p1Energy_prev=-999;
    float n1Energy_prev=-999;
    float p2Energy_prev=-999;
    float n2Energy_prev=-999;
    float p3Energy_prev=-999;
    float n3Energy_prev=-999;

    for(int i=0; i<nentries; i++)
    { 
      ch->GetEntry(i);
     
      //cout << run << " " << ls << " " << evt << " " << ieta << " " << iphi << " " << depth  
      //     << " = " << printHit(run,ls,evt,ieta,iphi,depth) << endl;
      if(!printHit(run,ls,evt,ieta,iphi,depth)) continue;

      // histograms
      TH1D *h1_data = InitTH1D("h1_data", "h1_data", 8, -0.5, 7.5); 
      TH1D *h1_it   = InitTH1D("h1_it",   "h1_it",   8, -0.5, 7.5); 
      TH1D *h1_p1   = InitTH1D("h1_p1",   "h1_p1",   8, -0.5, 7.5); 
      TH1D *h1_p2   = InitTH1D("h1_p2",   "h1_p2",   8, -0.5, 7.5); 
      TH1D *h1_p3   = InitTH1D("h1_p3",   "h1_p3",   8, -0.5, 7.5); 
      TH1D *h1_n1   = InitTH1D("h1_n1",   "h1_n1",   8, -0.5, 7.5); 
      TH1D *h1_n2   = InitTH1D("h1_n2",   "h1_n2",   8, -0.5, 7.5); 
      TH1D *h1_n3   = InitTH1D("h1_n3",   "h1_n3",   8, -0.5, 7.5); 
      TH1D *h1_ped  = InitTH1D("h1_ped",  "h1_ped",  8, -0.5, 7.5); 
      TH1D *h1_all  = InitTH1D("h1_all",  "h1_all",  8, -0.5, 7.5); 
  
      // Fix OOT energy
      if(p1Energy_prev == p1Energy) p1Energy = 0; 
      if(p2Energy_prev == p2Energy) p2Energy = 0;
      if(p3Energy_prev == p3Energy) p3Energy = 0;
      if(n1Energy_prev == n1Energy) n1Energy = 0;
      if(n2Energy_prev == n2Energy) n2Energy = 0;
      if(n3Energy_prev == n3Energy) n3Energy = 0;
      p1Energy_prev = p1Energy; 
      p2Energy_prev = p2Energy;
      p3Energy_prev = p3Energy;
      n1Energy_prev = n1Energy;
      n2Energy_prev = n2Energy;
      n3Energy_prev = n3Energy;

      if(1)
      {
        cout << run << " " << ls << " " << evt << " " << endl; 
        cout << p3Energy << endl; 
        cout << p2Energy << endl; 
        cout << p1Energy << endl; 
        cout << mahiEnergy << endl; 
        cout << n1Energy << endl; 
        cout << n2Energy << endl; 
        cout << n3Energy << endl; 
        cout << pedEnergy << endl; 
      }

      for(int its=0; its<8; its++) 
      {
        if(p2Energy<0) p2Energy=0; 
        if(p3Energy<0) p3Energy=0; 
        if(n2Energy<0) n2Energy=0; 
        if(n3Energy<0) n3Energy=0; 

        h1_data->SetBinContent(its+1, inputTS[its]*inGain);
        h1_it->SetBinContent(its+1, itPulse[its]*mahiEnergy*inGain);
        h1_p1->SetBinContent(its+1, p1Pulse[its]*p1Energy*inGain);
        h1_p2->SetBinContent(its+1, p2Pulse[its]*p2Energy*inGain);
        h1_p3->SetBinContent(its+1, p3Pulse[its]*p3Energy*inGain);
        h1_n1->SetBinContent(its+1, n1Pulse[its]*n1Energy*inGain);
        h1_n2->SetBinContent(its+1, n2Pulse[its]*n2Energy*inGain);
        h1_n3->SetBinContent(its+1, n3Pulse[its]*n3Energy*inGain);
        h1_ped->SetBinContent(its+1, 0.125*pedEnergy*inGain); 
        float all = itPulse[its]*mahiEnergy; 
        all += p1Pulse[its]*p1Energy + p2Pulse[its]*p2Energy + p3Pulse[its]*p3Energy;
        all += n1Pulse[its]*n1Energy + n2Pulse[its]*n2Energy + n3Pulse[its]*n3Energy;
        all +=  0.125*pedEnergy;
        h1_all->SetBinContent(its+1, all*inGain); 
      }

      h1_data->SetLineColor(kBlack); h1_data->SetMarkerColor(kBlack);
      h1_data->SetMarkerStyle(20);   h1_data->SetMarkerSize(1); 
      /*
      h1_it->SetLineColor(kBlack);   h1_it->SetFillColorAlpha(kYellow+1, 0.2);
      h1_p1->SetLineColor(kBlack);   h1_p1->SetFillColorAlpha(kBlue+1,   0.2);
      h1_p2->SetLineColor(kBlack);   h1_p2->SetFillColorAlpha(kBlue+5,   0.2);
      h1_p3->SetLineColor(kBlack);   h1_p3->SetFillColorAlpha(kBlue+5,   0.2);
      h1_n1->SetLineColor(kBlack);   h1_n1->SetFillColorAlpha(kRed+1,    0.2);
      h1_n2->SetLineColor(kBlack);   h1_n2->SetFillColorAlpha(kRed+5,    0.2);
      h1_n3->SetLineColor(kBlack);   h1_n3->SetFillColorAlpha(kRed+5,    0.2);
      h1_ped->SetLineColor(kBlack);  h1_ped->SetFillColorAlpha(kGreen+5, 0.2);
      */
      h1_it->SetLineColor(kBlack);   h1_it->SetFillColor(kYellow-10);
      h1_p1->SetLineColor(kBlack);   h1_p1->SetFillColor(kAzure+1);
      h1_p2->SetLineColor(kBlack);   h1_p2->SetFillColor(kAzure+6);
      h1_p3->SetLineColor(kBlack);   h1_p3->SetFillColor(kAzure);
      h1_n1->SetLineColor(kBlack);   h1_n1->SetFillColor(kPink+1);
      h1_n2->SetLineColor(kBlack);   h1_n2->SetFillColor(kPink+6);
      h1_n3->SetLineColor(kBlack);   h1_n3->SetFillColor(kPink);
      h1_ped->SetLineColor(kBlack);  h1_ped->SetFillColor(kGreen-10);
      h1_all->SetLineColor(kBlack);  h1_all->SetLineWidth(2);

      // legend 
      TLegend *l1 = new TLegend(0.25, 0.6, 0.85, 0.85);
      l1->SetNColumns(2);
      l1->SetBorderSize(0);
      l1->SetFillColor(0);
      l1->SetFillStyle(0);
      l1->SetTextFont(42);
      l1->SetTextAlign(12);
      l1->SetTextSize(0.06);
      l1->SetFillColor(kWhite);
      l1->SetLineColor(kWhite);
      l1->SetShadowColor(kWhite);
      l1->AddEntry(h1_data, " digi", "p");
      if(h1_ped->Integral()>0) l1->AddEntry(h1_ped, " baseline", "f");
      if(h1_p3->Integral()>0) l1->AddEntry(h1_p3,   " -3 BX",     "f");
      if(h1_p2->Integral()>0) l1->AddEntry(h1_p2,   " -2 BX",     "f");
      if(h1_p1->Integral()>0) l1->AddEntry(h1_p1,   " -1 BX",     "f");
      if(h1_it->Integral()>0) l1->AddEntry(h1_it,   " In-time",   "f");
      if(h1_n1->Integral()>0) l1->AddEntry(h1_n1,   " +1BX",     "f");
      if(h1_n2->Integral()>0) l1->AddEntry(h1_n2,   " +2BX",     "f");
      if(h1_n3->Integral()>0) l1->AddEntry(h1_n3,   " +3BX",     "f"); 
      
      // 
      TCanvas *c = new TCanvas("c","c",1200,400); 
      c->Divide(2,1); 
      c->cd(1); 
      THStack *st = new THStack("st", Form("run=%i ls=%i evt=%i (%i, %i, %i), E=%.1f fC (%.1f GeV)",run, ls, evt, ieta,iphi,depth, mahiEnergy, mahiEnergy*inGain));
      if(h1_ped->Integral()>0) st->Add(h1_ped);
      if(h1_p3->Integral()>0) st->Add(h1_p3);
      if(h1_p2->Integral()>0) st->Add(h1_p2);
      if(h1_p1->Integral()>0) st->Add(h1_p1);
      if(h1_n1->Integral()>0) st->Add(h1_n1);
      if(h1_n2->Integral()>0) st->Add(h1_n2);
      if(h1_n3->Integral()>0) st->Add(h1_n3); 
      if(h1_it->Integral()>0) st->Add(h1_it);
      //st->SetMaximum(h1_data->GetMaximum()*1.8); 
      //st->SetMinimum(h1_ped->GetMaximum()*0.5); 
      st->Draw("hist");
      st->SetMaximum(h1_data->GetMaximum()*1.8); 
      if(ip==0) st->SetMinimum(h1_ped->GetMaximum()*0.5); 
      if(ip==1) st->SetMinimum(h1_data->GetMinimum()*0.1); 
      h1_data->Draw("ep same"); 
      l1->Draw();
      c->cd(2)->SetLogy(1); 
      st->Draw("hist");
      h1_data->Draw("ep same");
      c->Print(Form("plots_%s/0p95to1p05/pulse_run%i_ls%i_evt%i_ieta%i_iphi%i_depth%i.pdf", ip==0?"3p1b":"7p", run, ls, evt, ieta, iphi, depth));
    }

    } // for(ip) 
}
