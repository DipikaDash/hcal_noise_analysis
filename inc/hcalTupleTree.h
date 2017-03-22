//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar  2 12:31:47 2017 by ROOT version 6.05/01
// from TChain hcalTupleTree/tree
//////////////////////////////////////////////////////////

#ifndef hcalTupleTree_h
#define hcalTupleTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "string"
#include "vector"

// In order to use vector of vectors : vector<vector<data type> >
// ACLiC makes dictionary for this
// [ref] http://root.cern.ch/phpBB3/viewtopic.php?f=3&t=10236&p=44117#p44117
#ifdef __MAKECINT__
#pragma link C++ class std::vector < std::vector<int> >+;
#pragma link C++ class std::vector < std::vector<double> >+;
#endif

using namespace std;

class hcalTupleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   string          *HLTKey;
   vector<string>  *HLTInsideDatasetTriggerNames;
   vector<string>  *HLTOutsideDatasetTriggerNames;
   vector<bool>    *HLTInsideDatasetTriggerDecisions;
   vector<bool>    *HLTOutsideDatasetTriggerDecisions;
   vector<double>  *EBET;
   vector<double>  *EBSumE;
   vector<double>  *EBSumET;
   vector<double>  *EEET;
   vector<double>  *EESumE;
   vector<double>  *EESumET;
   vector<double>  *HBET;
   vector<double>  *HBSumE;
   vector<double>  *HBSumET;
   vector<double>  *HEET;
   vector<double>  *HESumE;
   vector<double>  *HESumET;
   vector<double>  *HFET;
   vector<double>  *JetEMEB;
   vector<double>  *JetEMEE;
   vector<double>  *JetEMFrac;
   vector<double>  *JetEMHF;
   vector<double>  *JetEta;
   vector<double>  *JetHadFrac;
   vector<double>  *JetHadHB;
   vector<double>  *JetHadHE;
   vector<double>  *JetHadHF;
   vector<double>  *JetPhi;
   vector<double>  *JetPt;
   vector<double>  *NominalMET;
   vector<double>  *HBHERecHitEnergyRaw;
   vector<double>  *IsolatedNoiseSumE;
   vector<double>  *IsolatedNoiseSumEt;
   vector<double>  *MaxE2E10;
   vector<double>  *MinE2E10;
   vector<double>  *NegativeNoiseSumE;
   vector<double>  *NegativeNoiseSumEt;
   vector<double>  *RBXEnergy;
   vector<double>  *RBXEnergy15;
   vector<double>  *SpikeNoiseSumE;
   vector<double>  *SpikeNoiseSumEt;
   vector<double>  *MuonCalEnergyEm;
   vector<double>  *MuonCalEnergyEmS25;
   vector<double>  *MuonCalEnergyHad;
   vector<double>  *MuonCalEnergyHadS9;
   vector<double>  *MuonEta;
   vector<double>  *MuonPhi;
   vector<double>  *MuonPt;
   vector<vector<double> > *HBHERecHitAuxAllfC;
   vector<vector<double> > *HBHERecHitAuxEnergy;
   vector<vector<double> > *HBHERecHitAuxFC;
   vector<vector<double> > *HBHERecHitAuxGain;
   vector<vector<double> > *HBHERecHitAuxPedFC;
   vector<vector<double> > *HBHERecHitAuxRCGain;
   vector<vector<double> > *RBXCharge;
   vector<vector<double> > *RBXCharge15;
   vector<float>   *HBHERecHitEnergy;
   vector<float>   *HBHERecHitEta;
   vector<float>   *HBHERecHitPhi;
   vector<float>   *HBHERecHitTime;
   vector<float>   *HFRecHitEnergy;
   vector<float>   *HFRecHitEta;
   vector<float>   *HFRecHitPhi;
   vector<float>   *HFRecHitTime;
   vector<int>     *JetN60;
   vector<int>     *JetN90;
   vector<int>     *HBHERecHitAux;
   vector<int>     *HBHERecHitDepth;
   vector<int>     *HBHERecHitFlags;
   vector<int>     *HBHERecHitHPDid;
   vector<int>     *HBHERecHitIEta;
   vector<int>     *HBHERecHitIPhi;
   vector<int>     *HBHERecHitRBXid;
   vector<int>     *HFRecHitAux;
   vector<int>     *HFRecHitDepth;
   vector<int>     *HFRecHitFlags;
   vector<int>     *HFRecHitHPDid;
   vector<int>     *HFRecHitIEta;
   vector<int>     *HFRecHitIPhi;
   vector<int>     *HFRecHitRBXid;
   vector<int>     *HPDHits;
   vector<int>     *HPDNoOtherHits;
   vector<int>     *HasBadRBXR45;
   vector<int>     *HasBadRBXRechitR45Loose;
   vector<int>     *HasBadRBXRechitR45Tight;
   vector<int>     *IsoNoiseFilterDecision;
   vector<int>     *MaxZeros;
   vector<int>     *NumIsolatedNoiseChannels;
   vector<int>     *NumNegativeNoiseChannels;
   vector<int>     *NumSpikeNoiseChannels;
   vector<int>     *OfficialDecision;
   vector<int>     *OfficialDecisionRun1;
   vector<int>     *OfficialDecisionRun2L;
   vector<int>     *OfficialDecisionRun2T;
   vector<int>     *MuonCSC2DRecHitsSize;
   vector<int>     *MuonCSCSegmentsSize;
   vector<int>     *MuonDT1DCosmicRecHitsSize;
   vector<int>     *MuonDT1DRecHitsSize;
   vector<int>     *MuonDTRecCosmicSegmentsSize;
   vector<int>     *MuonDTRecSegmentsSize;
   vector<int>     *MuonNumberOfChambers;
   vector<int>     *MuonNumberOfMatchedRPCLayers;
   vector<int>     *MuonNumberOfMatchedStations;
   vector<int>     *MuonRPCRecHitsSize;
   vector<int>     *HLTBits;
   vector<int>     *HLTInsideDatasetTriggerPrescales;
   vector<int>     *HLTOutsideDatasetTriggerPrescales;
   vector<vector<int> > *HBHERecHitAuxADC;
   vector<vector<int> > *HBHERecHitAuxCapID;
   vector<vector<int> > *L1PhysBits;
   vector<vector<int> > *L1TechBits;
   UInt_t          bx;
   UInt_t          event;
   UInt_t          ls;
   UInt_t          run;

   // List of branches
   TBranch        *b_HLTKey;   //!
   TBranch        *b_HLTInsideDatasetTriggerNames;   //!
   TBranch        *b_HLTOutsideDatasetTriggerNames;   //!
   TBranch        *b_HLTInsideDatasetTriggerDecisions;   //!
   TBranch        *b_HLTOutsideDatasetTriggerDecisions;   //!
   TBranch        *b_EBET;   //!
   TBranch        *b_EBSumE;   //!
   TBranch        *b_EBSumET;   //!
   TBranch        *b_EEET;   //!
   TBranch        *b_EESumE;   //!
   TBranch        *b_EESumET;   //!
   TBranch        *b_HBET;   //!
   TBranch        *b_HBSumE;   //!
   TBranch        *b_HBSumET;   //!
   TBranch        *b_HEET;   //!
   TBranch        *b_HESumE;   //!
   TBranch        *b_HESumET;   //!
   TBranch        *b_HFET;   //!
   TBranch        *b_JetEMEB;   //!
   TBranch        *b_JetEMEE;   //!
   TBranch        *b_JetEMFrac;   //!
   TBranch        *b_JetEMHF;   //!
   TBranch        *b_JetEta;   //!
   TBranch        *b_JetHadFrac;   //!
   TBranch        *b_JetHadHB;   //!
   TBranch        *b_JetHadHE;   //!
   TBranch        *b_JetHadHF;   //!
   TBranch        *b_JetPhi;   //!
   TBranch        *b_JetPt;   //!
   TBranch        *b_NominalMET;   //!
   TBranch        *b_HBHERecHitEnergyRaw;   //!
   TBranch        *b_IsolatedNoiseSumE;   //!
   TBranch        *b_IsolatedNoiseSumEt;   //!
   TBranch        *b_MaxE2E10;   //!
   TBranch        *b_MinE2E10;   //!
   TBranch        *b_NegativeNoiseSumE;   //!
   TBranch        *b_NegativeNoiseSumEt;   //!
   TBranch        *b_RBXEnergy;   //!
   TBranch        *b_RBXEnergy15;   //!
   TBranch        *b_SpikeNoiseSumE;   //!
   TBranch        *b_SpikeNoiseSumEt;   //!
   TBranch        *b_MuonCalEnergyEm;   //!
   TBranch        *b_MuonCalEnergyEmS25;   //!
   TBranch        *b_MuonCalEnergyHad;   //!
   TBranch        *b_MuonCalEnergyHadS9;   //!
   TBranch        *b_MuonEta;   //!
   TBranch        *b_MuonPhi;   //!
   TBranch        *b_MuonPt;   //!
   TBranch        *b_HBHERecHitAuxAllfC;   //!
   TBranch        *b_HBHERecHitAuxEnergy;   //!
   TBranch        *b_HBHERecHitAuxFC;   //!
   TBranch        *b_HBHERecHitAuxGain;   //!
   TBranch        *b_HBHERecHitAuxPedFC;   //!
   TBranch        *b_HBHERecHitAuxRCGain;   //!
   TBranch        *b_RBXCharge;   //!
   TBranch        *b_RBXCharge15;   //!
   TBranch        *b_HBHERecHitEnergy;   //!
   TBranch        *b_HBHERecHitEta;   //!
   TBranch        *b_HBHERecHitPhi;   //!
   TBranch        *b_HBHERecHitTime;   //!
   TBranch        *b_HFRecHitEnergy;   //!
   TBranch        *b_HFRecHitEta;   //!
   TBranch        *b_HFRecHitPhi;   //!
   TBranch        *b_HFRecHitTime;   //!
   TBranch        *b_JetN60;   //!
   TBranch        *b_JetN90;   //!
   TBranch        *b_HBHERecHitAux;   //!
   TBranch        *b_HBHERecHitDepth;   //!
   TBranch        *b_HBHERecHitFlags;   //!
   TBranch        *b_HBHERecHitHPDid;   //!
   TBranch        *b_HBHERecHitIEta;   //!
   TBranch        *b_HBHERecHitIPhi;   //!
   TBranch        *b_HBHERecHitRBXid;   //!
   TBranch        *b_HFRecHitAux;   //!
   TBranch        *b_HFRecHitDepth;   //!
   TBranch        *b_HFRecHitFlags;   //!
   TBranch        *b_HFRecHitHPDid;   //!
   TBranch        *b_HFRecHitIEta;   //!
   TBranch        *b_HFRecHitIPhi;   //!
   TBranch        *b_HFRecHitRBXid;   //!
   TBranch        *b_HPDHits;   //!
   TBranch        *b_HPDNoOtherHits;   //!
   TBranch        *b_HasBadRBXR45;   //!
   TBranch        *b_HasBadRBXRechitR45Loose;   //!
   TBranch        *b_HasBadRBXRechitR45Tight;   //!
   TBranch        *b_IsoNoiseFilterDecision;   //!
   TBranch        *b_MaxZeros;   //!
   TBranch        *b_NumIsolatedNoiseChannels;   //!
   TBranch        *b_NumNegativeNoiseChannels;   //!
   TBranch        *b_NumSpikeNoiseChannels;   //!
   TBranch        *b_OfficialDecision;   //!
   TBranch        *b_OfficialDecisionRun1;   //!
   TBranch        *b_OfficialDecisionRun2L;   //!
   TBranch        *b_OfficialDecisionRun2T;   //!
   TBranch        *b_MuonCSC2DRecHitsSize;   //!
   TBranch        *b_MuonCSCSegmentsSize;   //!
   TBranch        *b_MuonDT1DCosmicRecHitsSize;   //!
   TBranch        *b_MuonDT1DRecHitsSize;   //!
   TBranch        *b_MuonDTRecCosmicSegmentsSize;   //!
   TBranch        *b_MuonDTRecSegmentsSize;   //!
   TBranch        *b_MuonNumberOfChambers;   //!
   TBranch        *b_MuonNumberOfMatchedRPCLayers;   //!
   TBranch        *b_MuonNumberOfMatchedStations;   //!
   TBranch        *b_MuonRPCRecHitsSize;   //!
   TBranch        *b_HLTBits;   //!
   TBranch        *b_HLTInsideDatasetTriggerPrescales;   //!
   TBranch        *b_HLTOutsideDatasetTriggerPrescales;   //!
   TBranch        *b_HBHERecHitAuxADC;   //!
   TBranch        *b_HBHERecHitAuxCapID;   //!
   TBranch        *b_L1PhysBits;   //!
   TBranch        *b_L1TechBits;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_event;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_run;   //!

   hcalTupleTree(TTree *tree=0);
   virtual ~hcalTupleTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Int_t    GetEntries();
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef hcalTupleTree_cxx
hcalTupleTree::hcalTupleTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("hcalTupleTree",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("hcalTupleTree/tree","");
      chain->Add("../results_1.root");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

hcalTupleTree::~hcalTupleTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t hcalTupleTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Int_t hcalTupleTree::GetEntries()
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntries();
}
Long64_t hcalTupleTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void hcalTupleTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   HLTKey = 0;
   HLTInsideDatasetTriggerNames = 0;
   HLTOutsideDatasetTriggerNames = 0;
   HLTInsideDatasetTriggerDecisions = 0;
   HLTOutsideDatasetTriggerDecisions = 0;
   EBET = 0;
   EBSumE = 0;
   EBSumET = 0;
   EEET = 0;
   EESumE = 0;
   EESumET = 0;
   HBET = 0;
   HBSumE = 0;
   HBSumET = 0;
   HEET = 0;
   HESumE = 0;
   HESumET = 0;
   HFET = 0;
   JetEMEB = 0;
   JetEMEE = 0;
   JetEMFrac = 0;
   JetEMHF = 0;
   JetEta = 0;
   JetHadFrac = 0;
   JetHadHB = 0;
   JetHadHE = 0;
   JetHadHF = 0;
   JetPhi = 0;
   JetPt = 0;
   NominalMET = 0;
   HBHERecHitEnergyRaw = 0;
   IsolatedNoiseSumE = 0;
   IsolatedNoiseSumEt = 0;
   MaxE2E10 = 0;
   MinE2E10 = 0;
   NegativeNoiseSumE = 0;
   NegativeNoiseSumEt = 0;
   RBXEnergy = 0;
   RBXEnergy15 = 0;
   SpikeNoiseSumE = 0;
   SpikeNoiseSumEt = 0;
   MuonCalEnergyEm = 0;
   MuonCalEnergyEmS25 = 0;
   MuonCalEnergyHad = 0;
   MuonCalEnergyHadS9 = 0;
   MuonEta = 0;
   MuonPhi = 0;
   MuonPt = 0;
   HBHERecHitAuxAllfC = 0;
   HBHERecHitAuxEnergy = 0;
   HBHERecHitAuxFC = 0;
   HBHERecHitAuxGain = 0;
   HBHERecHitAuxPedFC = 0;
   HBHERecHitAuxRCGain = 0;
   RBXCharge = 0;
   RBXCharge15 = 0;
   HBHERecHitEnergy = 0;
   HBHERecHitEta = 0;
   HBHERecHitPhi = 0;
   HBHERecHitTime = 0;
   HFRecHitEnergy = 0;
   HFRecHitEta = 0;
   HFRecHitPhi = 0;
   HFRecHitTime = 0;
   JetN60 = 0;
   JetN90 = 0;
   HBHERecHitAux = 0;
   HBHERecHitDepth = 0;
   HBHERecHitFlags = 0;
   HBHERecHitHPDid = 0;
   HBHERecHitIEta = 0;
   HBHERecHitIPhi = 0;
   HBHERecHitRBXid = 0;
   HFRecHitAux = 0;
   HFRecHitDepth = 0;
   HFRecHitFlags = 0;
   HFRecHitHPDid = 0;
   HFRecHitIEta = 0;
   HFRecHitIPhi = 0;
   HFRecHitRBXid = 0;
   HPDHits = 0;
   HPDNoOtherHits = 0;
   HasBadRBXR45 = 0;
   HasBadRBXRechitR45Loose = 0;
   HasBadRBXRechitR45Tight = 0;
   IsoNoiseFilterDecision = 0;
   MaxZeros = 0;
   NumIsolatedNoiseChannels = 0;
   NumNegativeNoiseChannels = 0;
   NumSpikeNoiseChannels = 0;
   OfficialDecision = 0;
   OfficialDecisionRun1 = 0;
   OfficialDecisionRun2L = 0;
   OfficialDecisionRun2T = 0;
   MuonCSC2DRecHitsSize = 0;
   MuonCSCSegmentsSize = 0;
   MuonDT1DCosmicRecHitsSize = 0;
   MuonDT1DRecHitsSize = 0;
   MuonDTRecCosmicSegmentsSize = 0;
   MuonDTRecSegmentsSize = 0;
   MuonNumberOfChambers = 0;
   MuonNumberOfMatchedRPCLayers = 0;
   MuonNumberOfMatchedStations = 0;
   MuonRPCRecHitsSize = 0;
   HLTBits = 0;
   HLTInsideDatasetTriggerPrescales = 0;
   HLTOutsideDatasetTriggerPrescales = 0;
   HBHERecHitAuxADC = 0;
   HBHERecHitAuxCapID = 0;
   L1PhysBits = 0;
   L1TechBits = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HLTKey", &HLTKey, &b_HLTKey);
   fChain->SetBranchAddress("HLTInsideDatasetTriggerNames", &HLTInsideDatasetTriggerNames, &b_HLTInsideDatasetTriggerNames);
   fChain->SetBranchAddress("HLTOutsideDatasetTriggerNames", &HLTOutsideDatasetTriggerNames, &b_HLTOutsideDatasetTriggerNames);
   fChain->SetBranchAddress("HLTInsideDatasetTriggerDecisions", &HLTInsideDatasetTriggerDecisions, &b_HLTInsideDatasetTriggerDecisions);
   fChain->SetBranchAddress("HLTOutsideDatasetTriggerDecisions", &HLTOutsideDatasetTriggerDecisions, &b_HLTOutsideDatasetTriggerDecisions);
   fChain->SetBranchAddress("EBET", &EBET, &b_EBET);
   fChain->SetBranchAddress("EBSumE", &EBSumE, &b_EBSumE);
   fChain->SetBranchAddress("EBSumET", &EBSumET, &b_EBSumET);
   fChain->SetBranchAddress("EEET", &EEET, &b_EEET);
   fChain->SetBranchAddress("EESumE", &EESumE, &b_EESumE);
   fChain->SetBranchAddress("EESumET", &EESumET, &b_EESumET);
   fChain->SetBranchAddress("HBET", &HBET, &b_HBET);
   fChain->SetBranchAddress("HBSumE", &HBSumE, &b_HBSumE);
   fChain->SetBranchAddress("HBSumET", &HBSumET, &b_HBSumET);
   fChain->SetBranchAddress("HEET", &HEET, &b_HEET);
   fChain->SetBranchAddress("HESumE", &HESumE, &b_HESumE);
   fChain->SetBranchAddress("HESumET", &HESumET, &b_HESumET);
   fChain->SetBranchAddress("HFET", &HFET, &b_HFET);
   fChain->SetBranchAddress("JetEMEB", &JetEMEB, &b_JetEMEB);
   fChain->SetBranchAddress("JetEMEE", &JetEMEE, &b_JetEMEE);
   fChain->SetBranchAddress("JetEMFrac", &JetEMFrac, &b_JetEMFrac);
   fChain->SetBranchAddress("JetEMHF", &JetEMHF, &b_JetEMHF);
   fChain->SetBranchAddress("JetEta", &JetEta, &b_JetEta);
   fChain->SetBranchAddress("JetHadFrac", &JetHadFrac, &b_JetHadFrac);
   fChain->SetBranchAddress("JetHadHB", &JetHadHB, &b_JetHadHB);
   fChain->SetBranchAddress("JetHadHE", &JetHadHE, &b_JetHadHE);
   fChain->SetBranchAddress("JetHadHF", &JetHadHF, &b_JetHadHF);
   fChain->SetBranchAddress("JetPhi", &JetPhi, &b_JetPhi);
   fChain->SetBranchAddress("JetPt", &JetPt, &b_JetPt);
   fChain->SetBranchAddress("NominalMET", &NominalMET, &b_NominalMET);
   fChain->SetBranchAddress("HBHERecHitEnergyRaw", &HBHERecHitEnergyRaw, &b_HBHERecHitEnergyRaw);
   fChain->SetBranchAddress("IsolatedNoiseSumE", &IsolatedNoiseSumE, &b_IsolatedNoiseSumE);
   fChain->SetBranchAddress("IsolatedNoiseSumEt", &IsolatedNoiseSumEt, &b_IsolatedNoiseSumEt);
   fChain->SetBranchAddress("MaxE2E10", &MaxE2E10, &b_MaxE2E10);
   fChain->SetBranchAddress("MinE2E10", &MinE2E10, &b_MinE2E10);
   fChain->SetBranchAddress("NegativeNoiseSumE", &NegativeNoiseSumE, &b_NegativeNoiseSumE);
   fChain->SetBranchAddress("NegativeNoiseSumEt", &NegativeNoiseSumEt, &b_NegativeNoiseSumEt);
   fChain->SetBranchAddress("RBXEnergy", &RBXEnergy, &b_RBXEnergy);
   fChain->SetBranchAddress("RBXEnergy15", &RBXEnergy15, &b_RBXEnergy15);
   fChain->SetBranchAddress("SpikeNoiseSumE", &SpikeNoiseSumE, &b_SpikeNoiseSumE);
   fChain->SetBranchAddress("SpikeNoiseSumEt", &SpikeNoiseSumEt, &b_SpikeNoiseSumEt);
   fChain->SetBranchAddress("MuonCalEnergyEm", &MuonCalEnergyEm, &b_MuonCalEnergyEm);
   fChain->SetBranchAddress("MuonCalEnergyEmS25", &MuonCalEnergyEmS25, &b_MuonCalEnergyEmS25);
   fChain->SetBranchAddress("MuonCalEnergyHad", &MuonCalEnergyHad, &b_MuonCalEnergyHad);
   fChain->SetBranchAddress("MuonCalEnergyHadS9", &MuonCalEnergyHadS9, &b_MuonCalEnergyHadS9);
   fChain->SetBranchAddress("MuonEta", &MuonEta, &b_MuonEta);
   fChain->SetBranchAddress("MuonPhi", &MuonPhi, &b_MuonPhi);
   fChain->SetBranchAddress("MuonPt", &MuonPt, &b_MuonPt);
   fChain->SetBranchAddress("HBHERecHitAuxAllfC", &HBHERecHitAuxAllfC, &b_HBHERecHitAuxAllfC);
   fChain->SetBranchAddress("HBHERecHitAuxEnergy", &HBHERecHitAuxEnergy, &b_HBHERecHitAuxEnergy);
   fChain->SetBranchAddress("HBHERecHitAuxFC", &HBHERecHitAuxFC, &b_HBHERecHitAuxFC);
   fChain->SetBranchAddress("HBHERecHitAuxGain", &HBHERecHitAuxGain, &b_HBHERecHitAuxGain);
   fChain->SetBranchAddress("HBHERecHitAuxPedFC", &HBHERecHitAuxPedFC, &b_HBHERecHitAuxPedFC);
   fChain->SetBranchAddress("HBHERecHitAuxRCGain", &HBHERecHitAuxRCGain, &b_HBHERecHitAuxRCGain);
   fChain->SetBranchAddress("RBXCharge", &RBXCharge, &b_RBXCharge);
   fChain->SetBranchAddress("RBXCharge15", &RBXCharge15, &b_RBXCharge15);
   fChain->SetBranchAddress("HBHERecHitEnergy", &HBHERecHitEnergy, &b_HBHERecHitEnergy);
   fChain->SetBranchAddress("HBHERecHitEta", &HBHERecHitEta, &b_HBHERecHitEta);
   fChain->SetBranchAddress("HBHERecHitPhi", &HBHERecHitPhi, &b_HBHERecHitPhi);
   fChain->SetBranchAddress("HBHERecHitTime", &HBHERecHitTime, &b_HBHERecHitTime);
   fChain->SetBranchAddress("HFRecHitEnergy", &HFRecHitEnergy, &b_HFRecHitEnergy);
   fChain->SetBranchAddress("HFRecHitEta", &HFRecHitEta, &b_HFRecHitEta);
   fChain->SetBranchAddress("HFRecHitPhi", &HFRecHitPhi, &b_HFRecHitPhi);
   fChain->SetBranchAddress("HFRecHitTime", &HFRecHitTime, &b_HFRecHitTime);
   fChain->SetBranchAddress("JetN60", &JetN60, &b_JetN60);
   fChain->SetBranchAddress("JetN90", &JetN90, &b_JetN90);
   fChain->SetBranchAddress("HBHERecHitAux", &HBHERecHitAux, &b_HBHERecHitAux);
   fChain->SetBranchAddress("HBHERecHitDepth", &HBHERecHitDepth, &b_HBHERecHitDepth);
   fChain->SetBranchAddress("HBHERecHitFlags", &HBHERecHitFlags, &b_HBHERecHitFlags);
   fChain->SetBranchAddress("HBHERecHitHPDid", &HBHERecHitHPDid, &b_HBHERecHitHPDid);
   fChain->SetBranchAddress("HBHERecHitIEta", &HBHERecHitIEta, &b_HBHERecHitIEta);
   fChain->SetBranchAddress("HBHERecHitIPhi", &HBHERecHitIPhi, &b_HBHERecHitIPhi);
   fChain->SetBranchAddress("HBHERecHitRBXid", &HBHERecHitRBXid, &b_HBHERecHitRBXid);
   fChain->SetBranchAddress("HFRecHitAux", &HFRecHitAux, &b_HFRecHitAux);
   fChain->SetBranchAddress("HFRecHitDepth", &HFRecHitDepth, &b_HFRecHitDepth);
   fChain->SetBranchAddress("HFRecHitFlags", &HFRecHitFlags, &b_HFRecHitFlags);
   fChain->SetBranchAddress("HFRecHitHPDid", &HFRecHitHPDid, &b_HFRecHitHPDid);
   fChain->SetBranchAddress("HFRecHitIEta", &HFRecHitIEta, &b_HFRecHitIEta);
   fChain->SetBranchAddress("HFRecHitIPhi", &HFRecHitIPhi, &b_HFRecHitIPhi);
   fChain->SetBranchAddress("HFRecHitRBXid", &HFRecHitRBXid, &b_HFRecHitRBXid);
   fChain->SetBranchAddress("HPDHits", &HPDHits, &b_HPDHits);
   fChain->SetBranchAddress("HPDNoOtherHits", &HPDNoOtherHits, &b_HPDNoOtherHits);
   fChain->SetBranchAddress("HasBadRBXR45", &HasBadRBXR45, &b_HasBadRBXR45);
   fChain->SetBranchAddress("HasBadRBXRechitR45Loose", &HasBadRBXRechitR45Loose, &b_HasBadRBXRechitR45Loose);
   fChain->SetBranchAddress("HasBadRBXRechitR45Tight", &HasBadRBXRechitR45Tight, &b_HasBadRBXRechitR45Tight);
   fChain->SetBranchAddress("IsoNoiseFilterDecision", &IsoNoiseFilterDecision, &b_IsoNoiseFilterDecision);
   fChain->SetBranchAddress("MaxZeros", &MaxZeros, &b_MaxZeros);
   fChain->SetBranchAddress("NumIsolatedNoiseChannels", &NumIsolatedNoiseChannels, &b_NumIsolatedNoiseChannels);
   fChain->SetBranchAddress("NumNegativeNoiseChannels", &NumNegativeNoiseChannels, &b_NumNegativeNoiseChannels);
   fChain->SetBranchAddress("NumSpikeNoiseChannels", &NumSpikeNoiseChannels, &b_NumSpikeNoiseChannels);
   fChain->SetBranchAddress("OfficialDecision", &OfficialDecision, &b_OfficialDecision);
   fChain->SetBranchAddress("OfficialDecisionRun1", &OfficialDecisionRun1, &b_OfficialDecisionRun1);
   fChain->SetBranchAddress("OfficialDecisionRun2L", &OfficialDecisionRun2L, &b_OfficialDecisionRun2L);
   fChain->SetBranchAddress("OfficialDecisionRun2T", &OfficialDecisionRun2T, &b_OfficialDecisionRun2T);
   fChain->SetBranchAddress("MuonCSC2DRecHitsSize", &MuonCSC2DRecHitsSize, &b_MuonCSC2DRecHitsSize);
   fChain->SetBranchAddress("MuonCSCSegmentsSize", &MuonCSCSegmentsSize, &b_MuonCSCSegmentsSize);
   fChain->SetBranchAddress("MuonDT1DCosmicRecHitsSize", &MuonDT1DCosmicRecHitsSize, &b_MuonDT1DCosmicRecHitsSize);
   fChain->SetBranchAddress("MuonDT1DRecHitsSize", &MuonDT1DRecHitsSize, &b_MuonDT1DRecHitsSize);
   fChain->SetBranchAddress("MuonDTRecCosmicSegmentsSize", &MuonDTRecCosmicSegmentsSize, &b_MuonDTRecCosmicSegmentsSize);
   fChain->SetBranchAddress("MuonDTRecSegmentsSize", &MuonDTRecSegmentsSize, &b_MuonDTRecSegmentsSize);
   fChain->SetBranchAddress("MuonNumberOfChambers", &MuonNumberOfChambers, &b_MuonNumberOfChambers);
   fChain->SetBranchAddress("MuonNumberOfMatchedRPCLayers", &MuonNumberOfMatchedRPCLayers, &b_MuonNumberOfMatchedRPCLayers);
   fChain->SetBranchAddress("MuonNumberOfMatchedStations", &MuonNumberOfMatchedStations, &b_MuonNumberOfMatchedStations);
   fChain->SetBranchAddress("MuonRPCRecHitsSize", &MuonRPCRecHitsSize, &b_MuonRPCRecHitsSize);
   fChain->SetBranchAddress("HLTBits", &HLTBits, &b_HLTBits);
   fChain->SetBranchAddress("HLTInsideDatasetTriggerPrescales", &HLTInsideDatasetTriggerPrescales, &b_HLTInsideDatasetTriggerPrescales);
   fChain->SetBranchAddress("HLTOutsideDatasetTriggerPrescales", &HLTOutsideDatasetTriggerPrescales, &b_HLTOutsideDatasetTriggerPrescales);
   fChain->SetBranchAddress("HBHERecHitAuxADC", &HBHERecHitAuxADC, &b_HBHERecHitAuxADC);
   fChain->SetBranchAddress("HBHERecHitAuxCapID", &HBHERecHitAuxCapID, &b_HBHERecHitAuxCapID);
   fChain->SetBranchAddress("L1PhysBits", &L1PhysBits, &b_L1PhysBits);
   fChain->SetBranchAddress("L1TechBits", &L1TechBits, &b_L1TechBits);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("run", &run, &b_run);
   Notify();
}

Bool_t hcalTupleTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void hcalTupleTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t hcalTupleTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   if(entry==1) return 1;
   else return 1;
}
#endif // #ifdef hcalTupleTree_cxx
