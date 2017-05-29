#include <iostream>
#include "TH1D.h" 
#include "TH2D.h" 
#include "TString.h" 

//
//
//
bool passHBHELoose(int HPDHits, int HPDNoOtherHits, 
                   int MaxZeros, int HasBadRBXRechitR45Loose)
{
    bool pass = true;
    
    // Loose selection
    int minHPDHits_         =   17;
    int minHPDNoOtherHits_  =   10;
    int minZeros_           =   9999; 

    if(0)  // debugging 
    { 
       std::cout << "[Debug] maxHPDHits = " << HPDHits << ", " 
                 << "maxHPDNoOtherHits = " << HPDNoOtherHits << ", " 
                 << "maxZeros = " << MaxZeros << ", " 
                 << "HasBadRBXRechitR45Loose = " <<HasBadRBXRechitR45Loose << " " 
                 << std::endl;
    }

    //
    // Apply cuts
    //
    if( HPDHits>=minHPDHits_ ) pass = false;
    if( HPDNoOtherHits >= minHPDNoOtherHits_ ) pass=false;
    if( MaxZeros >= minZeros_ ) pass = false;
    if( HasBadRBXRechitR45Loose ) pass = false;

    return pass;
}

//
//
//
bool passHBHEIso(int NumIsolatedNoiseChannels, 
                 float IsolatedNoiseSumE, 
                 float IsolatedNoiseSumEt)
{
    bool pass = true;
    
    // Loose selection
    int     minNumIsolatedNoiseChannels_    =   10;
    float   minIsolatedNoiseSumE_           =   50.0;
    float   minIsolatedNoiseSumEt_          =   25.0;

    if(0)  // debugging 
    { 
       std::cout << "[Debug] NumIsolatedNoiseChannels = " << NumIsolatedNoiseChannels << ", " 
                 << "IsolatedNoiseSumE = " << IsolatedNoiseSumE << ", " 
                 << "IsolatedNoiseSumEt = " << IsolatedNoiseSumEt << " " 
                 << std::endl;
    }

    //
    // Apply cuts
    //
    if( NumIsolatedNoiseChannels>=minNumIsolatedNoiseChannels_ ) pass = false;
    if( IsolatedNoiseSumE>=minIsolatedNoiseSumE_ ) pass = false;
    if( IsolatedNoiseSumEt>=minIsolatedNoiseSumEt_ ) pass = false;

    return pass;
}

bool flagWordDecoder( int word, unsigned int bitNo )
{
    if( ((word >> bitNo ) & 1) > 0 ) return true;
    else return false;
}

//
// h1 cosmetics
//
void h1cosmetic(TH1D* &h1, const char* title, int linecolor=kBlack, int linewidth=1, int fillcolor=0, TString var="")
{
    h1->SetLineColor(linecolor);
    h1->SetLineWidth(linewidth);
    h1->SetMarkerColor(linecolor);
    h1->SetMarkerStyle(20);
    h1->SetMarkerSize(1);
    h1->SetFillColor(fillcolor);
    h1->SetTitle(title);
    h1->SetXTitle(var);
    h1->SetStats(0);
}

//
//TH1D initialization
//
TH1D* InitTH1D(char* Name, char* Title, int Nbins, double XMin, double XMax)
{
    TH1D *h1 = new TH1D(Name, Title, Nbins, XMin, XMax);
    h1->Sumw2();
    return h1;
}

//
//TH2D initialization
//
TH2D* InitTH2D(char* Name, char* Title, int NXbins, double XMin, double XMax, int NYbins, double YMin, double YMax)
{
    TH2D *h2 = new TH2D(Name, Title, NXbins, XMin, XMax, NYbins, YMin, YMax);
    h2->Sumw2();
    return h2;
}

//
// Fill TH1D
//
void FillTH1D(TH1D* &h1, double var, double weight)
{
    if(var >= h1->GetXaxis()->GetBinUpEdge(h1->GetXaxis()->GetNbins()))
        var=h1->GetXaxis()->GetBinUpEdge(h1->GetXaxis()->GetNbins())-0.00001;
    if(var < h1->GetXaxis()->GetBinLowEdge(1))
        var=h1->GetXaxis()->GetBinLowEdge(1)+0.00001;
    h1->Fill(var, weight);
}

//
// Fill TH2D
//
void FillTH2D(TH2D* &h2, double varX, double varY, double weight){
    if(varX >= h2->GetXaxis()->GetBinUpEdge(h2->GetXaxis()->GetNbins()))
        varX=h2->GetXaxis()->GetBinUpEdge(h2->GetXaxis()->GetNbins())-0.00001;
    if(varY >= h2->GetYaxis()->GetBinUpEdge(h2->GetYaxis()->GetNbins()))
        varY=h2->GetYaxis()->GetBinUpEdge(h2->GetYaxis()->GetNbins())-0.00001;
    if(varX < h2->GetXaxis()->GetBinLowEdge(1))
        varX=h2->GetXaxis()->GetBinLowEdge(1)+0.00001;
    if(varY < h2->GetYaxis()->GetBinLowEdge(1))
        varY=h2->GetYaxis()->GetBinLowEdge(1)+0.00001;
    h2->Fill(varX, varY, weight);
}

