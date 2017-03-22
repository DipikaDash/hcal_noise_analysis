// hcal_tree: base class to handle reduce tree ntuples
//File generated with generate_hcal_tree.exe

#include "hcal_tree.hpp"

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

#include "TROOT.h"
#include "TTree.h"
#include "TBranch.h"
#include "TChain.h"
#include "TTreeFormula.h"

using namespace std;

bool hcal_tree::VectorLoader::loaded_ = false;

hcal_tree::VectorLoader hcal_tree::vl_ = hcal_tree::VectorLoader();

hcal_tree::VectorLoader::VectorLoader(){
  if(!loaded_){
    gROOT->ProcessLine("#include <vector>");
    loaded_ = true;
  }
}

const double hcal_tree::bad_val_ = -999.;

hcal_tree::hcal_tree():
  chain_("junk", "junk"),
  tree_("hcalTupleTree/tree", "hcalTupleTree/tree"),
  entry_(0),
  read_only_(false),
  bx_(0),
  b_bx_(tree_.Branch("bx", &bx_)),
  c_bx_(false),
  event_(0),
  b_event_(tree_.Branch("event", &event_)),
  c_event_(false),
  ls_(0),
  b_ls_(tree_.Branch("ls", &ls_)),
  c_ls_(false),
  run_(0),
  b_run_(tree_.Branch("run", &run_)),
  c_run_(false),
  HLTInsideDatasetTriggerDecisions_(0),
  p_HLTInsideDatasetTriggerDecisions_(&HLTInsideDatasetTriggerDecisions_),
  b_HLTInsideDatasetTriggerDecisions_(tree_.Branch("HLTInsideDatasetTriggerDecisions", &p_HLTInsideDatasetTriggerDecisions_)),
  c_HLTInsideDatasetTriggerDecisions_(false),
  HLTOutsideDatasetTriggerDecisions_(0),
  p_HLTOutsideDatasetTriggerDecisions_(&HLTOutsideDatasetTriggerDecisions_),
  b_HLTOutsideDatasetTriggerDecisions_(tree_.Branch("HLTOutsideDatasetTriggerDecisions", &p_HLTOutsideDatasetTriggerDecisions_)),
  c_HLTOutsideDatasetTriggerDecisions_(false),
  EBET_(0),
  p_EBET_(&EBET_),
  b_EBET_(tree_.Branch("EBET", &p_EBET_)),
  c_EBET_(false),
  EBSumE_(0),
  p_EBSumE_(&EBSumE_),
  b_EBSumE_(tree_.Branch("EBSumE", &p_EBSumE_)),
  c_EBSumE_(false),
  EBSumET_(0),
  p_EBSumET_(&EBSumET_),
  b_EBSumET_(tree_.Branch("EBSumET", &p_EBSumET_)),
  c_EBSumET_(false),
  EEET_(0),
  p_EEET_(&EEET_),
  b_EEET_(tree_.Branch("EEET", &p_EEET_)),
  c_EEET_(false),
  EESumE_(0),
  p_EESumE_(&EESumE_),
  b_EESumE_(tree_.Branch("EESumE", &p_EESumE_)),
  c_EESumE_(false),
  EESumET_(0),
  p_EESumET_(&EESumET_),
  b_EESumET_(tree_.Branch("EESumET", &p_EESumET_)),
  c_EESumET_(false),
  HBET_(0),
  p_HBET_(&HBET_),
  b_HBET_(tree_.Branch("HBET", &p_HBET_)),
  c_HBET_(false),
  HBHERecHitEnergyRaw_(0),
  p_HBHERecHitEnergyRaw_(&HBHERecHitEnergyRaw_),
  b_HBHERecHitEnergyRaw_(tree_.Branch("HBHERecHitEnergyRaw", &p_HBHERecHitEnergyRaw_)),
  c_HBHERecHitEnergyRaw_(false),
  HBSumE_(0),
  p_HBSumE_(&HBSumE_),
  b_HBSumE_(tree_.Branch("HBSumE", &p_HBSumE_)),
  c_HBSumE_(false),
  HBSumET_(0),
  p_HBSumET_(&HBSumET_),
  b_HBSumET_(tree_.Branch("HBSumET", &p_HBSumET_)),
  c_HBSumET_(false),
  HEET_(0),
  p_HEET_(&HEET_),
  b_HEET_(tree_.Branch("HEET", &p_HEET_)),
  c_HEET_(false),
  HESumE_(0),
  p_HESumE_(&HESumE_),
  b_HESumE_(tree_.Branch("HESumE", &p_HESumE_)),
  c_HESumE_(false),
  HESumET_(0),
  p_HESumET_(&HESumET_),
  b_HESumET_(tree_.Branch("HESumET", &p_HESumET_)),
  c_HESumET_(false),
  HFET_(0),
  p_HFET_(&HFET_),
  b_HFET_(tree_.Branch("HFET", &p_HFET_)),
  c_HFET_(false),
  IsolatedNoiseSumE_(0),
  p_IsolatedNoiseSumE_(&IsolatedNoiseSumE_),
  b_IsolatedNoiseSumE_(tree_.Branch("IsolatedNoiseSumE", &p_IsolatedNoiseSumE_)),
  c_IsolatedNoiseSumE_(false),
  IsolatedNoiseSumEt_(0),
  p_IsolatedNoiseSumEt_(&IsolatedNoiseSumEt_),
  b_IsolatedNoiseSumEt_(tree_.Branch("IsolatedNoiseSumEt", &p_IsolatedNoiseSumEt_)),
  c_IsolatedNoiseSumEt_(false),
  JetEMEB_(0),
  p_JetEMEB_(&JetEMEB_),
  b_JetEMEB_(tree_.Branch("JetEMEB", &p_JetEMEB_)),
  c_JetEMEB_(false),
  JetEMEE_(0),
  p_JetEMEE_(&JetEMEE_),
  b_JetEMEE_(tree_.Branch("JetEMEE", &p_JetEMEE_)),
  c_JetEMEE_(false),
  JetEMFrac_(0),
  p_JetEMFrac_(&JetEMFrac_),
  b_JetEMFrac_(tree_.Branch("JetEMFrac", &p_JetEMFrac_)),
  c_JetEMFrac_(false),
  JetEMHF_(0),
  p_JetEMHF_(&JetEMHF_),
  b_JetEMHF_(tree_.Branch("JetEMHF", &p_JetEMHF_)),
  c_JetEMHF_(false),
  JetEta_(0),
  p_JetEta_(&JetEta_),
  b_JetEta_(tree_.Branch("JetEta", &p_JetEta_)),
  c_JetEta_(false),
  JetHadFrac_(0),
  p_JetHadFrac_(&JetHadFrac_),
  b_JetHadFrac_(tree_.Branch("JetHadFrac", &p_JetHadFrac_)),
  c_JetHadFrac_(false),
  JetHadHB_(0),
  p_JetHadHB_(&JetHadHB_),
  b_JetHadHB_(tree_.Branch("JetHadHB", &p_JetHadHB_)),
  c_JetHadHB_(false),
  JetHadHE_(0),
  p_JetHadHE_(&JetHadHE_),
  b_JetHadHE_(tree_.Branch("JetHadHE", &p_JetHadHE_)),
  c_JetHadHE_(false),
  JetHadHF_(0),
  p_JetHadHF_(&JetHadHF_),
  b_JetHadHF_(tree_.Branch("JetHadHF", &p_JetHadHF_)),
  c_JetHadHF_(false),
  JetPhi_(0),
  p_JetPhi_(&JetPhi_),
  b_JetPhi_(tree_.Branch("JetPhi", &p_JetPhi_)),
  c_JetPhi_(false),
  JetPt_(0),
  p_JetPt_(&JetPt_),
  b_JetPt_(tree_.Branch("JetPt", &p_JetPt_)),
  c_JetPt_(false),
  MaxE2E10_(0),
  p_MaxE2E10_(&MaxE2E10_),
  b_MaxE2E10_(tree_.Branch("MaxE2E10", &p_MaxE2E10_)),
  c_MaxE2E10_(false),
  MinE2E10_(0),
  p_MinE2E10_(&MinE2E10_),
  b_MinE2E10_(tree_.Branch("MinE2E10", &p_MinE2E10_)),
  c_MinE2E10_(false),
  MuonCalEnergyEm_(0),
  p_MuonCalEnergyEm_(&MuonCalEnergyEm_),
  b_MuonCalEnergyEm_(tree_.Branch("MuonCalEnergyEm", &p_MuonCalEnergyEm_)),
  c_MuonCalEnergyEm_(false),
  MuonCalEnergyEmS25_(0),
  p_MuonCalEnergyEmS25_(&MuonCalEnergyEmS25_),
  b_MuonCalEnergyEmS25_(tree_.Branch("MuonCalEnergyEmS25", &p_MuonCalEnergyEmS25_)),
  c_MuonCalEnergyEmS25_(false),
  MuonCalEnergyHad_(0),
  p_MuonCalEnergyHad_(&MuonCalEnergyHad_),
  b_MuonCalEnergyHad_(tree_.Branch("MuonCalEnergyHad", &p_MuonCalEnergyHad_)),
  c_MuonCalEnergyHad_(false),
  MuonCalEnergyHadS9_(0),
  p_MuonCalEnergyHadS9_(&MuonCalEnergyHadS9_),
  b_MuonCalEnergyHadS9_(tree_.Branch("MuonCalEnergyHadS9", &p_MuonCalEnergyHadS9_)),
  c_MuonCalEnergyHadS9_(false),
  MuonEta_(0),
  p_MuonEta_(&MuonEta_),
  b_MuonEta_(tree_.Branch("MuonEta", &p_MuonEta_)),
  c_MuonEta_(false),
  MuonPhi_(0),
  p_MuonPhi_(&MuonPhi_),
  b_MuonPhi_(tree_.Branch("MuonPhi", &p_MuonPhi_)),
  c_MuonPhi_(false),
  MuonPt_(0),
  p_MuonPt_(&MuonPt_),
  b_MuonPt_(tree_.Branch("MuonPt", &p_MuonPt_)),
  c_MuonPt_(false),
  NegativeNoiseSumE_(0),
  p_NegativeNoiseSumE_(&NegativeNoiseSumE_),
  b_NegativeNoiseSumE_(tree_.Branch("NegativeNoiseSumE", &p_NegativeNoiseSumE_)),
  c_NegativeNoiseSumE_(false),
  NegativeNoiseSumEt_(0),
  p_NegativeNoiseSumEt_(&NegativeNoiseSumEt_),
  b_NegativeNoiseSumEt_(tree_.Branch("NegativeNoiseSumEt", &p_NegativeNoiseSumEt_)),
  c_NegativeNoiseSumEt_(false),
  NominalMET_(0),
  p_NominalMET_(&NominalMET_),
  b_NominalMET_(tree_.Branch("NominalMET", &p_NominalMET_)),
  c_NominalMET_(false),
  RBXEnergy_(0),
  p_RBXEnergy_(&RBXEnergy_),
  b_RBXEnergy_(tree_.Branch("RBXEnergy", &p_RBXEnergy_)),
  c_RBXEnergy_(false),
  RBXEnergy15_(0),
  p_RBXEnergy15_(&RBXEnergy15_),
  b_RBXEnergy15_(tree_.Branch("RBXEnergy15", &p_RBXEnergy15_)),
  c_RBXEnergy15_(false),
  SpikeNoiseSumE_(0),
  p_SpikeNoiseSumE_(&SpikeNoiseSumE_),
  b_SpikeNoiseSumE_(tree_.Branch("SpikeNoiseSumE", &p_SpikeNoiseSumE_)),
  c_SpikeNoiseSumE_(false),
  SpikeNoiseSumEt_(0),
  p_SpikeNoiseSumEt_(&SpikeNoiseSumEt_),
  b_SpikeNoiseSumEt_(tree_.Branch("SpikeNoiseSumEt", &p_SpikeNoiseSumEt_)),
  c_SpikeNoiseSumEt_(false),
  HBHERecHitEnergy_(0),
  p_HBHERecHitEnergy_(&HBHERecHitEnergy_),
  b_HBHERecHitEnergy_(tree_.Branch("HBHERecHitEnergy", &p_HBHERecHitEnergy_)),
  c_HBHERecHitEnergy_(false),
  HBHERecHitEta_(0),
  p_HBHERecHitEta_(&HBHERecHitEta_),
  b_HBHERecHitEta_(tree_.Branch("HBHERecHitEta", &p_HBHERecHitEta_)),
  c_HBHERecHitEta_(false),
  HBHERecHitPhi_(0),
  p_HBHERecHitPhi_(&HBHERecHitPhi_),
  b_HBHERecHitPhi_(tree_.Branch("HBHERecHitPhi", &p_HBHERecHitPhi_)),
  c_HBHERecHitPhi_(false),
  HBHERecHitTime_(0),
  p_HBHERecHitTime_(&HBHERecHitTime_),
  b_HBHERecHitTime_(tree_.Branch("HBHERecHitTime", &p_HBHERecHitTime_)),
  c_HBHERecHitTime_(false),
  HFRecHitEnergy_(0),
  p_HFRecHitEnergy_(&HFRecHitEnergy_),
  b_HFRecHitEnergy_(tree_.Branch("HFRecHitEnergy", &p_HFRecHitEnergy_)),
  c_HFRecHitEnergy_(false),
  HFRecHitEta_(0),
  p_HFRecHitEta_(&HFRecHitEta_),
  b_HFRecHitEta_(tree_.Branch("HFRecHitEta", &p_HFRecHitEta_)),
  c_HFRecHitEta_(false),
  HFRecHitPhi_(0),
  p_HFRecHitPhi_(&HFRecHitPhi_),
  b_HFRecHitPhi_(tree_.Branch("HFRecHitPhi", &p_HFRecHitPhi_)),
  c_HFRecHitPhi_(false),
  HFRecHitTime_(0),
  p_HFRecHitTime_(&HFRecHitTime_),
  b_HFRecHitTime_(tree_.Branch("HFRecHitTime", &p_HFRecHitTime_)),
  c_HFRecHitTime_(false),
  HBHERecHitAux_(0),
  p_HBHERecHitAux_(&HBHERecHitAux_),
  b_HBHERecHitAux_(tree_.Branch("HBHERecHitAux", &p_HBHERecHitAux_)),
  c_HBHERecHitAux_(false),
  HBHERecHitDepth_(0),
  p_HBHERecHitDepth_(&HBHERecHitDepth_),
  b_HBHERecHitDepth_(tree_.Branch("HBHERecHitDepth", &p_HBHERecHitDepth_)),
  c_HBHERecHitDepth_(false),
  HBHERecHitFlags_(0),
  p_HBHERecHitFlags_(&HBHERecHitFlags_),
  b_HBHERecHitFlags_(tree_.Branch("HBHERecHitFlags", &p_HBHERecHitFlags_)),
  c_HBHERecHitFlags_(false),
  HBHERecHitHPDid_(0),
  p_HBHERecHitHPDid_(&HBHERecHitHPDid_),
  b_HBHERecHitHPDid_(tree_.Branch("HBHERecHitHPDid", &p_HBHERecHitHPDid_)),
  c_HBHERecHitHPDid_(false),
  HBHERecHitIEta_(0),
  p_HBHERecHitIEta_(&HBHERecHitIEta_),
  b_HBHERecHitIEta_(tree_.Branch("HBHERecHitIEta", &p_HBHERecHitIEta_)),
  c_HBHERecHitIEta_(false),
  HBHERecHitIPhi_(0),
  p_HBHERecHitIPhi_(&HBHERecHitIPhi_),
  b_HBHERecHitIPhi_(tree_.Branch("HBHERecHitIPhi", &p_HBHERecHitIPhi_)),
  c_HBHERecHitIPhi_(false),
  HBHERecHitRBXid_(0),
  p_HBHERecHitRBXid_(&HBHERecHitRBXid_),
  b_HBHERecHitRBXid_(tree_.Branch("HBHERecHitRBXid", &p_HBHERecHitRBXid_)),
  c_HBHERecHitRBXid_(false),
  HFRecHitAux_(0),
  p_HFRecHitAux_(&HFRecHitAux_),
  b_HFRecHitAux_(tree_.Branch("HFRecHitAux", &p_HFRecHitAux_)),
  c_HFRecHitAux_(false),
  HFRecHitDepth_(0),
  p_HFRecHitDepth_(&HFRecHitDepth_),
  b_HFRecHitDepth_(tree_.Branch("HFRecHitDepth", &p_HFRecHitDepth_)),
  c_HFRecHitDepth_(false),
  HFRecHitFlags_(0),
  p_HFRecHitFlags_(&HFRecHitFlags_),
  b_HFRecHitFlags_(tree_.Branch("HFRecHitFlags", &p_HFRecHitFlags_)),
  c_HFRecHitFlags_(false),
  HFRecHitHPDid_(0),
  p_HFRecHitHPDid_(&HFRecHitHPDid_),
  b_HFRecHitHPDid_(tree_.Branch("HFRecHitHPDid", &p_HFRecHitHPDid_)),
  c_HFRecHitHPDid_(false),
  HFRecHitIEta_(0),
  p_HFRecHitIEta_(&HFRecHitIEta_),
  b_HFRecHitIEta_(tree_.Branch("HFRecHitIEta", &p_HFRecHitIEta_)),
  c_HFRecHitIEta_(false),
  HFRecHitIPhi_(0),
  p_HFRecHitIPhi_(&HFRecHitIPhi_),
  b_HFRecHitIPhi_(tree_.Branch("HFRecHitIPhi", &p_HFRecHitIPhi_)),
  c_HFRecHitIPhi_(false),
  HFRecHitRBXid_(0),
  p_HFRecHitRBXid_(&HFRecHitRBXid_),
  b_HFRecHitRBXid_(tree_.Branch("HFRecHitRBXid", &p_HFRecHitRBXid_)),
  c_HFRecHitRBXid_(false),
  HLTBits_(0),
  p_HLTBits_(&HLTBits_),
  b_HLTBits_(tree_.Branch("HLTBits", &p_HLTBits_)),
  c_HLTBits_(false),
  HLTInsideDatasetTriggerPrescales_(0),
  p_HLTInsideDatasetTriggerPrescales_(&HLTInsideDatasetTriggerPrescales_),
  b_HLTInsideDatasetTriggerPrescales_(tree_.Branch("HLTInsideDatasetTriggerPrescales", &p_HLTInsideDatasetTriggerPrescales_)),
  c_HLTInsideDatasetTriggerPrescales_(false),
  HLTOutsideDatasetTriggerPrescales_(0),
  p_HLTOutsideDatasetTriggerPrescales_(&HLTOutsideDatasetTriggerPrescales_),
  b_HLTOutsideDatasetTriggerPrescales_(tree_.Branch("HLTOutsideDatasetTriggerPrescales", &p_HLTOutsideDatasetTriggerPrescales_)),
  c_HLTOutsideDatasetTriggerPrescales_(false),
  HPDHits_(0),
  p_HPDHits_(&HPDHits_),
  b_HPDHits_(tree_.Branch("HPDHits", &p_HPDHits_)),
  c_HPDHits_(false),
  HPDNoOtherHits_(0),
  p_HPDNoOtherHits_(&HPDNoOtherHits_),
  b_HPDNoOtherHits_(tree_.Branch("HPDNoOtherHits", &p_HPDNoOtherHits_)),
  c_HPDNoOtherHits_(false),
  HasBadRBXR45_(0),
  p_HasBadRBXR45_(&HasBadRBXR45_),
  b_HasBadRBXR45_(tree_.Branch("HasBadRBXR45", &p_HasBadRBXR45_)),
  c_HasBadRBXR45_(false),
  HasBadRBXRechitR45Loose_(0),
  p_HasBadRBXRechitR45Loose_(&HasBadRBXRechitR45Loose_),
  b_HasBadRBXRechitR45Loose_(tree_.Branch("HasBadRBXRechitR45Loose", &p_HasBadRBXRechitR45Loose_)),
  c_HasBadRBXRechitR45Loose_(false),
  HasBadRBXRechitR45Tight_(0),
  p_HasBadRBXRechitR45Tight_(&HasBadRBXRechitR45Tight_),
  b_HasBadRBXRechitR45Tight_(tree_.Branch("HasBadRBXRechitR45Tight", &p_HasBadRBXRechitR45Tight_)),
  c_HasBadRBXRechitR45Tight_(false),
  IsoNoiseFilterDecision_(0),
  p_IsoNoiseFilterDecision_(&IsoNoiseFilterDecision_),
  b_IsoNoiseFilterDecision_(tree_.Branch("IsoNoiseFilterDecision", &p_IsoNoiseFilterDecision_)),
  c_IsoNoiseFilterDecision_(false),
  JetN60_(0),
  p_JetN60_(&JetN60_),
  b_JetN60_(tree_.Branch("JetN60", &p_JetN60_)),
  c_JetN60_(false),
  JetN90_(0),
  p_JetN90_(&JetN90_),
  b_JetN90_(tree_.Branch("JetN90", &p_JetN90_)),
  c_JetN90_(false),
  MaxZeros_(0),
  p_MaxZeros_(&MaxZeros_),
  b_MaxZeros_(tree_.Branch("MaxZeros", &p_MaxZeros_)),
  c_MaxZeros_(false),
  MuonCSC2DRecHitsSize_(0),
  p_MuonCSC2DRecHitsSize_(&MuonCSC2DRecHitsSize_),
  b_MuonCSC2DRecHitsSize_(tree_.Branch("MuonCSC2DRecHitsSize", &p_MuonCSC2DRecHitsSize_)),
  c_MuonCSC2DRecHitsSize_(false),
  MuonCSCSegmentsSize_(0),
  p_MuonCSCSegmentsSize_(&MuonCSCSegmentsSize_),
  b_MuonCSCSegmentsSize_(tree_.Branch("MuonCSCSegmentsSize", &p_MuonCSCSegmentsSize_)),
  c_MuonCSCSegmentsSize_(false),
  MuonDT1DCosmicRecHitsSize_(0),
  p_MuonDT1DCosmicRecHitsSize_(&MuonDT1DCosmicRecHitsSize_),
  b_MuonDT1DCosmicRecHitsSize_(tree_.Branch("MuonDT1DCosmicRecHitsSize", &p_MuonDT1DCosmicRecHitsSize_)),
  c_MuonDT1DCosmicRecHitsSize_(false),
  MuonDT1DRecHitsSize_(0),
  p_MuonDT1DRecHitsSize_(&MuonDT1DRecHitsSize_),
  b_MuonDT1DRecHitsSize_(tree_.Branch("MuonDT1DRecHitsSize", &p_MuonDT1DRecHitsSize_)),
  c_MuonDT1DRecHitsSize_(false),
  MuonDTRecCosmicSegmentsSize_(0),
  p_MuonDTRecCosmicSegmentsSize_(&MuonDTRecCosmicSegmentsSize_),
  b_MuonDTRecCosmicSegmentsSize_(tree_.Branch("MuonDTRecCosmicSegmentsSize", &p_MuonDTRecCosmicSegmentsSize_)),
  c_MuonDTRecCosmicSegmentsSize_(false),
  MuonDTRecSegmentsSize_(0),
  p_MuonDTRecSegmentsSize_(&MuonDTRecSegmentsSize_),
  b_MuonDTRecSegmentsSize_(tree_.Branch("MuonDTRecSegmentsSize", &p_MuonDTRecSegmentsSize_)),
  c_MuonDTRecSegmentsSize_(false),
  MuonNumberOfChambers_(0),
  p_MuonNumberOfChambers_(&MuonNumberOfChambers_),
  b_MuonNumberOfChambers_(tree_.Branch("MuonNumberOfChambers", &p_MuonNumberOfChambers_)),
  c_MuonNumberOfChambers_(false),
  MuonNumberOfMatchedRPCLayers_(0),
  p_MuonNumberOfMatchedRPCLayers_(&MuonNumberOfMatchedRPCLayers_),
  b_MuonNumberOfMatchedRPCLayers_(tree_.Branch("MuonNumberOfMatchedRPCLayers", &p_MuonNumberOfMatchedRPCLayers_)),
  c_MuonNumberOfMatchedRPCLayers_(false),
  MuonNumberOfMatchedStations_(0),
  p_MuonNumberOfMatchedStations_(&MuonNumberOfMatchedStations_),
  b_MuonNumberOfMatchedStations_(tree_.Branch("MuonNumberOfMatchedStations", &p_MuonNumberOfMatchedStations_)),
  c_MuonNumberOfMatchedStations_(false),
  MuonRPCRecHitsSize_(0),
  p_MuonRPCRecHitsSize_(&MuonRPCRecHitsSize_),
  b_MuonRPCRecHitsSize_(tree_.Branch("MuonRPCRecHitsSize", &p_MuonRPCRecHitsSize_)),
  c_MuonRPCRecHitsSize_(false),
  NumIsolatedNoiseChannels_(0),
  p_NumIsolatedNoiseChannels_(&NumIsolatedNoiseChannels_),
  b_NumIsolatedNoiseChannels_(tree_.Branch("NumIsolatedNoiseChannels", &p_NumIsolatedNoiseChannels_)),
  c_NumIsolatedNoiseChannels_(false),
  NumNegativeNoiseChannels_(0),
  p_NumNegativeNoiseChannels_(&NumNegativeNoiseChannels_),
  b_NumNegativeNoiseChannels_(tree_.Branch("NumNegativeNoiseChannels", &p_NumNegativeNoiseChannels_)),
  c_NumNegativeNoiseChannels_(false),
  NumSpikeNoiseChannels_(0),
  p_NumSpikeNoiseChannels_(&NumSpikeNoiseChannels_),
  b_NumSpikeNoiseChannels_(tree_.Branch("NumSpikeNoiseChannels", &p_NumSpikeNoiseChannels_)),
  c_NumSpikeNoiseChannels_(false),
  OfficialDecision_(0),
  p_OfficialDecision_(&OfficialDecision_),
  b_OfficialDecision_(tree_.Branch("OfficialDecision", &p_OfficialDecision_)),
  c_OfficialDecision_(false),
  OfficialDecisionRun1_(0),
  p_OfficialDecisionRun1_(&OfficialDecisionRun1_),
  b_OfficialDecisionRun1_(tree_.Branch("OfficialDecisionRun1", &p_OfficialDecisionRun1_)),
  c_OfficialDecisionRun1_(false),
  OfficialDecisionRun2L_(0),
  p_OfficialDecisionRun2L_(&OfficialDecisionRun2L_),
  b_OfficialDecisionRun2L_(tree_.Branch("OfficialDecisionRun2L", &p_OfficialDecisionRun2L_)),
  c_OfficialDecisionRun2L_(false),
  OfficialDecisionRun2T_(0),
  p_OfficialDecisionRun2T_(&OfficialDecisionRun2T_),
  b_OfficialDecisionRun2T_(tree_.Branch("OfficialDecisionRun2T", &p_OfficialDecisionRun2T_)),
  c_OfficialDecisionRun2T_(false),
  HLTInsideDatasetTriggerNames_(0),
  p_HLTInsideDatasetTriggerNames_(&HLTInsideDatasetTriggerNames_),
  b_HLTInsideDatasetTriggerNames_(tree_.Branch("HLTInsideDatasetTriggerNames", &p_HLTInsideDatasetTriggerNames_)),
  c_HLTInsideDatasetTriggerNames_(false),
  HLTOutsideDatasetTriggerNames_(0),
  p_HLTOutsideDatasetTriggerNames_(&HLTOutsideDatasetTriggerNames_),
  b_HLTOutsideDatasetTriggerNames_(tree_.Branch("HLTOutsideDatasetTriggerNames", &p_HLTOutsideDatasetTriggerNames_)),
  c_HLTOutsideDatasetTriggerNames_(false),
  HBHERecHitAuxAllfC_(0),
  p_HBHERecHitAuxAllfC_(&HBHERecHitAuxAllfC_),
  b_HBHERecHitAuxAllfC_(tree_.Branch("HBHERecHitAuxAllfC", &p_HBHERecHitAuxAllfC_)),
  c_HBHERecHitAuxAllfC_(false),
  HBHERecHitAuxEnergy_(0),
  p_HBHERecHitAuxEnergy_(&HBHERecHitAuxEnergy_),
  b_HBHERecHitAuxEnergy_(tree_.Branch("HBHERecHitAuxEnergy", &p_HBHERecHitAuxEnergy_)),
  c_HBHERecHitAuxEnergy_(false),
  HBHERecHitAuxFC_(0),
  p_HBHERecHitAuxFC_(&HBHERecHitAuxFC_),
  b_HBHERecHitAuxFC_(tree_.Branch("HBHERecHitAuxFC", &p_HBHERecHitAuxFC_)),
  c_HBHERecHitAuxFC_(false),
  HBHERecHitAuxGain_(0),
  p_HBHERecHitAuxGain_(&HBHERecHitAuxGain_),
  b_HBHERecHitAuxGain_(tree_.Branch("HBHERecHitAuxGain", &p_HBHERecHitAuxGain_)),
  c_HBHERecHitAuxGain_(false),
  HBHERecHitAuxPedFC_(0),
  p_HBHERecHitAuxPedFC_(&HBHERecHitAuxPedFC_),
  b_HBHERecHitAuxPedFC_(tree_.Branch("HBHERecHitAuxPedFC", &p_HBHERecHitAuxPedFC_)),
  c_HBHERecHitAuxPedFC_(false),
  HBHERecHitAuxRCGain_(0),
  p_HBHERecHitAuxRCGain_(&HBHERecHitAuxRCGain_),
  b_HBHERecHitAuxRCGain_(tree_.Branch("HBHERecHitAuxRCGain", &p_HBHERecHitAuxRCGain_)),
  c_HBHERecHitAuxRCGain_(false),
  RBXCharge_(0),
  p_RBXCharge_(&RBXCharge_),
  b_RBXCharge_(tree_.Branch("RBXCharge", &p_RBXCharge_)),
  c_RBXCharge_(false),
  RBXCharge15_(0),
  p_RBXCharge15_(&RBXCharge15_),
  b_RBXCharge15_(tree_.Branch("RBXCharge15", &p_RBXCharge15_)),
  c_RBXCharge15_(false),
  HBHERecHitAuxADC_(0),
  p_HBHERecHitAuxADC_(&HBHERecHitAuxADC_),
  b_HBHERecHitAuxADC_(tree_.Branch("HBHERecHitAuxADC", &p_HBHERecHitAuxADC_)),
  c_HBHERecHitAuxADC_(false),
  HBHERecHitAuxCapID_(0),
  p_HBHERecHitAuxCapID_(&HBHERecHitAuxCapID_),
  b_HBHERecHitAuxCapID_(tree_.Branch("HBHERecHitAuxCapID", &p_HBHERecHitAuxCapID_)),
  c_HBHERecHitAuxCapID_(false),
  L1PhysBits_(0),
  p_L1PhysBits_(&L1PhysBits_),
  b_L1PhysBits_(tree_.Branch("L1PhysBits", &p_L1PhysBits_)),
  c_L1PhysBits_(false),
  L1TechBits_(0),
  b_L1TechBits_(tree_.Branch("L1TechBits", &L1TechBits_)),
  c_L1TechBits_(false){
}

hcal_tree::hcal_tree(const string &filename):
  chain_("hcalTupleTree/tree","hcalTupleTree/tree"),
  tree_("junk","junk"),
  entry_(0),
  read_only_(true),
  bx_(0),
  b_bx_(NULL),
  c_bx_(false),
  event_(0),
  b_event_(NULL),
  c_event_(false),
  ls_(0),
  b_ls_(NULL),
  c_ls_(false),
  run_(0),
  b_run_(NULL),
  c_run_(false),
  HLTInsideDatasetTriggerDecisions_(0),
  p_HLTInsideDatasetTriggerDecisions_(&HLTInsideDatasetTriggerDecisions_),
  b_HLTInsideDatasetTriggerDecisions_(NULL),
  c_HLTInsideDatasetTriggerDecisions_(false),
  HLTOutsideDatasetTriggerDecisions_(0),
  p_HLTOutsideDatasetTriggerDecisions_(&HLTOutsideDatasetTriggerDecisions_),
  b_HLTOutsideDatasetTriggerDecisions_(NULL),
  c_HLTOutsideDatasetTriggerDecisions_(false),
  EBET_(0),
  p_EBET_(&EBET_),
  b_EBET_(NULL),
  c_EBET_(false),
  EBSumE_(0),
  p_EBSumE_(&EBSumE_),
  b_EBSumE_(NULL),
  c_EBSumE_(false),
  EBSumET_(0),
  p_EBSumET_(&EBSumET_),
  b_EBSumET_(NULL),
  c_EBSumET_(false),
  EEET_(0),
  p_EEET_(&EEET_),
  b_EEET_(NULL),
  c_EEET_(false),
  EESumE_(0),
  p_EESumE_(&EESumE_),
  b_EESumE_(NULL),
  c_EESumE_(false),
  EESumET_(0),
  p_EESumET_(&EESumET_),
  b_EESumET_(NULL),
  c_EESumET_(false),
  HBET_(0),
  p_HBET_(&HBET_),
  b_HBET_(NULL),
  c_HBET_(false),
  HBHERecHitEnergyRaw_(0),
  p_HBHERecHitEnergyRaw_(&HBHERecHitEnergyRaw_),
  b_HBHERecHitEnergyRaw_(NULL),
  c_HBHERecHitEnergyRaw_(false),
  HBSumE_(0),
  p_HBSumE_(&HBSumE_),
  b_HBSumE_(NULL),
  c_HBSumE_(false),
  HBSumET_(0),
  p_HBSumET_(&HBSumET_),
  b_HBSumET_(NULL),
  c_HBSumET_(false),
  HEET_(0),
  p_HEET_(&HEET_),
  b_HEET_(NULL),
  c_HEET_(false),
  HESumE_(0),
  p_HESumE_(&HESumE_),
  b_HESumE_(NULL),
  c_HESumE_(false),
  HESumET_(0),
  p_HESumET_(&HESumET_),
  b_HESumET_(NULL),
  c_HESumET_(false),
  HFET_(0),
  p_HFET_(&HFET_),
  b_HFET_(NULL),
  c_HFET_(false),
  IsolatedNoiseSumE_(0),
  p_IsolatedNoiseSumE_(&IsolatedNoiseSumE_),
  b_IsolatedNoiseSumE_(NULL),
  c_IsolatedNoiseSumE_(false),
  IsolatedNoiseSumEt_(0),
  p_IsolatedNoiseSumEt_(&IsolatedNoiseSumEt_),
  b_IsolatedNoiseSumEt_(NULL),
  c_IsolatedNoiseSumEt_(false),
  JetEMEB_(0),
  p_JetEMEB_(&JetEMEB_),
  b_JetEMEB_(NULL),
  c_JetEMEB_(false),
  JetEMEE_(0),
  p_JetEMEE_(&JetEMEE_),
  b_JetEMEE_(NULL),
  c_JetEMEE_(false),
  JetEMFrac_(0),
  p_JetEMFrac_(&JetEMFrac_),
  b_JetEMFrac_(NULL),
  c_JetEMFrac_(false),
  JetEMHF_(0),
  p_JetEMHF_(&JetEMHF_),
  b_JetEMHF_(NULL),
  c_JetEMHF_(false),
  JetEta_(0),
  p_JetEta_(&JetEta_),
  b_JetEta_(NULL),
  c_JetEta_(false),
  JetHadFrac_(0),
  p_JetHadFrac_(&JetHadFrac_),
  b_JetHadFrac_(NULL),
  c_JetHadFrac_(false),
  JetHadHB_(0),
  p_JetHadHB_(&JetHadHB_),
  b_JetHadHB_(NULL),
  c_JetHadHB_(false),
  JetHadHE_(0),
  p_JetHadHE_(&JetHadHE_),
  b_JetHadHE_(NULL),
  c_JetHadHE_(false),
  JetHadHF_(0),
  p_JetHadHF_(&JetHadHF_),
  b_JetHadHF_(NULL),
  c_JetHadHF_(false),
  JetPhi_(0),
  p_JetPhi_(&JetPhi_),
  b_JetPhi_(NULL),
  c_JetPhi_(false),
  JetPt_(0),
  p_JetPt_(&JetPt_),
  b_JetPt_(NULL),
  c_JetPt_(false),
  MaxE2E10_(0),
  p_MaxE2E10_(&MaxE2E10_),
  b_MaxE2E10_(NULL),
  c_MaxE2E10_(false),
  MinE2E10_(0),
  p_MinE2E10_(&MinE2E10_),
  b_MinE2E10_(NULL),
  c_MinE2E10_(false),
  MuonCalEnergyEm_(0),
  p_MuonCalEnergyEm_(&MuonCalEnergyEm_),
  b_MuonCalEnergyEm_(NULL),
  c_MuonCalEnergyEm_(false),
  MuonCalEnergyEmS25_(0),
  p_MuonCalEnergyEmS25_(&MuonCalEnergyEmS25_),
  b_MuonCalEnergyEmS25_(NULL),
  c_MuonCalEnergyEmS25_(false),
  MuonCalEnergyHad_(0),
  p_MuonCalEnergyHad_(&MuonCalEnergyHad_),
  b_MuonCalEnergyHad_(NULL),
  c_MuonCalEnergyHad_(false),
  MuonCalEnergyHadS9_(0),
  p_MuonCalEnergyHadS9_(&MuonCalEnergyHadS9_),
  b_MuonCalEnergyHadS9_(NULL),
  c_MuonCalEnergyHadS9_(false),
  MuonEta_(0),
  p_MuonEta_(&MuonEta_),
  b_MuonEta_(NULL),
  c_MuonEta_(false),
  MuonPhi_(0),
  p_MuonPhi_(&MuonPhi_),
  b_MuonPhi_(NULL),
  c_MuonPhi_(false),
  MuonPt_(0),
  p_MuonPt_(&MuonPt_),
  b_MuonPt_(NULL),
  c_MuonPt_(false),
  NegativeNoiseSumE_(0),
  p_NegativeNoiseSumE_(&NegativeNoiseSumE_),
  b_NegativeNoiseSumE_(NULL),
  c_NegativeNoiseSumE_(false),
  NegativeNoiseSumEt_(0),
  p_NegativeNoiseSumEt_(&NegativeNoiseSumEt_),
  b_NegativeNoiseSumEt_(NULL),
  c_NegativeNoiseSumEt_(false),
  NominalMET_(0),
  p_NominalMET_(&NominalMET_),
  b_NominalMET_(NULL),
  c_NominalMET_(false),
  RBXEnergy_(0),
  p_RBXEnergy_(&RBXEnergy_),
  b_RBXEnergy_(NULL),
  c_RBXEnergy_(false),
  RBXEnergy15_(0),
  p_RBXEnergy15_(&RBXEnergy15_),
  b_RBXEnergy15_(NULL),
  c_RBXEnergy15_(false),
  SpikeNoiseSumE_(0),
  p_SpikeNoiseSumE_(&SpikeNoiseSumE_),
  b_SpikeNoiseSumE_(NULL),
  c_SpikeNoiseSumE_(false),
  SpikeNoiseSumEt_(0),
  p_SpikeNoiseSumEt_(&SpikeNoiseSumEt_),
  b_SpikeNoiseSumEt_(NULL),
  c_SpikeNoiseSumEt_(false),
  HBHERecHitEnergy_(0),
  p_HBHERecHitEnergy_(&HBHERecHitEnergy_),
  b_HBHERecHitEnergy_(NULL),
  c_HBHERecHitEnergy_(false),
  HBHERecHitEta_(0),
  p_HBHERecHitEta_(&HBHERecHitEta_),
  b_HBHERecHitEta_(NULL),
  c_HBHERecHitEta_(false),
  HBHERecHitPhi_(0),
  p_HBHERecHitPhi_(&HBHERecHitPhi_),
  b_HBHERecHitPhi_(NULL),
  c_HBHERecHitPhi_(false),
  HBHERecHitTime_(0),
  p_HBHERecHitTime_(&HBHERecHitTime_),
  b_HBHERecHitTime_(NULL),
  c_HBHERecHitTime_(false),
  HFRecHitEnergy_(0),
  p_HFRecHitEnergy_(&HFRecHitEnergy_),
  b_HFRecHitEnergy_(NULL),
  c_HFRecHitEnergy_(false),
  HFRecHitEta_(0),
  p_HFRecHitEta_(&HFRecHitEta_),
  b_HFRecHitEta_(NULL),
  c_HFRecHitEta_(false),
  HFRecHitPhi_(0),
  p_HFRecHitPhi_(&HFRecHitPhi_),
  b_HFRecHitPhi_(NULL),
  c_HFRecHitPhi_(false),
  HFRecHitTime_(0),
  p_HFRecHitTime_(&HFRecHitTime_),
  b_HFRecHitTime_(NULL),
  c_HFRecHitTime_(false),
  HBHERecHitAux_(0),
  p_HBHERecHitAux_(&HBHERecHitAux_),
  b_HBHERecHitAux_(NULL),
  c_HBHERecHitAux_(false),
  HBHERecHitDepth_(0),
  p_HBHERecHitDepth_(&HBHERecHitDepth_),
  b_HBHERecHitDepth_(NULL),
  c_HBHERecHitDepth_(false),
  HBHERecHitFlags_(0),
  p_HBHERecHitFlags_(&HBHERecHitFlags_),
  b_HBHERecHitFlags_(NULL),
  c_HBHERecHitFlags_(false),
  HBHERecHitHPDid_(0),
  p_HBHERecHitHPDid_(&HBHERecHitHPDid_),
  b_HBHERecHitHPDid_(NULL),
  c_HBHERecHitHPDid_(false),
  HBHERecHitIEta_(0),
  p_HBHERecHitIEta_(&HBHERecHitIEta_),
  b_HBHERecHitIEta_(NULL),
  c_HBHERecHitIEta_(false),
  HBHERecHitIPhi_(0),
  p_HBHERecHitIPhi_(&HBHERecHitIPhi_),
  b_HBHERecHitIPhi_(NULL),
  c_HBHERecHitIPhi_(false),
  HBHERecHitRBXid_(0),
  p_HBHERecHitRBXid_(&HBHERecHitRBXid_),
  b_HBHERecHitRBXid_(NULL),
  c_HBHERecHitRBXid_(false),
  HFRecHitAux_(0),
  p_HFRecHitAux_(&HFRecHitAux_),
  b_HFRecHitAux_(NULL),
  c_HFRecHitAux_(false),
  HFRecHitDepth_(0),
  p_HFRecHitDepth_(&HFRecHitDepth_),
  b_HFRecHitDepth_(NULL),
  c_HFRecHitDepth_(false),
  HFRecHitFlags_(0),
  p_HFRecHitFlags_(&HFRecHitFlags_),
  b_HFRecHitFlags_(NULL),
  c_HFRecHitFlags_(false),
  HFRecHitHPDid_(0),
  p_HFRecHitHPDid_(&HFRecHitHPDid_),
  b_HFRecHitHPDid_(NULL),
  c_HFRecHitHPDid_(false),
  HFRecHitIEta_(0),
  p_HFRecHitIEta_(&HFRecHitIEta_),
  b_HFRecHitIEta_(NULL),
  c_HFRecHitIEta_(false),
  HFRecHitIPhi_(0),
  p_HFRecHitIPhi_(&HFRecHitIPhi_),
  b_HFRecHitIPhi_(NULL),
  c_HFRecHitIPhi_(false),
  HFRecHitRBXid_(0),
  p_HFRecHitRBXid_(&HFRecHitRBXid_),
  b_HFRecHitRBXid_(NULL),
  c_HFRecHitRBXid_(false),
  HLTBits_(0),
  p_HLTBits_(&HLTBits_),
  b_HLTBits_(NULL),
  c_HLTBits_(false),
  HLTInsideDatasetTriggerPrescales_(0),
  p_HLTInsideDatasetTriggerPrescales_(&HLTInsideDatasetTriggerPrescales_),
  b_HLTInsideDatasetTriggerPrescales_(NULL),
  c_HLTInsideDatasetTriggerPrescales_(false),
  HLTOutsideDatasetTriggerPrescales_(0),
  p_HLTOutsideDatasetTriggerPrescales_(&HLTOutsideDatasetTriggerPrescales_),
  b_HLTOutsideDatasetTriggerPrescales_(NULL),
  c_HLTOutsideDatasetTriggerPrescales_(false),
  HPDHits_(0),
  p_HPDHits_(&HPDHits_),
  b_HPDHits_(NULL),
  c_HPDHits_(false),
  HPDNoOtherHits_(0),
  p_HPDNoOtherHits_(&HPDNoOtherHits_),
  b_HPDNoOtherHits_(NULL),
  c_HPDNoOtherHits_(false),
  HasBadRBXR45_(0),
  p_HasBadRBXR45_(&HasBadRBXR45_),
  b_HasBadRBXR45_(NULL),
  c_HasBadRBXR45_(false),
  HasBadRBXRechitR45Loose_(0),
  p_HasBadRBXRechitR45Loose_(&HasBadRBXRechitR45Loose_),
  b_HasBadRBXRechitR45Loose_(NULL),
  c_HasBadRBXRechitR45Loose_(false),
  HasBadRBXRechitR45Tight_(0),
  p_HasBadRBXRechitR45Tight_(&HasBadRBXRechitR45Tight_),
  b_HasBadRBXRechitR45Tight_(NULL),
  c_HasBadRBXRechitR45Tight_(false),
  IsoNoiseFilterDecision_(0),
  p_IsoNoiseFilterDecision_(&IsoNoiseFilterDecision_),
  b_IsoNoiseFilterDecision_(NULL),
  c_IsoNoiseFilterDecision_(false),
  JetN60_(0),
  p_JetN60_(&JetN60_),
  b_JetN60_(NULL),
  c_JetN60_(false),
  JetN90_(0),
  p_JetN90_(&JetN90_),
  b_JetN90_(NULL),
  c_JetN90_(false),
  MaxZeros_(0),
  p_MaxZeros_(&MaxZeros_),
  b_MaxZeros_(NULL),
  c_MaxZeros_(false),
  MuonCSC2DRecHitsSize_(0),
  p_MuonCSC2DRecHitsSize_(&MuonCSC2DRecHitsSize_),
  b_MuonCSC2DRecHitsSize_(NULL),
  c_MuonCSC2DRecHitsSize_(false),
  MuonCSCSegmentsSize_(0),
  p_MuonCSCSegmentsSize_(&MuonCSCSegmentsSize_),
  b_MuonCSCSegmentsSize_(NULL),
  c_MuonCSCSegmentsSize_(false),
  MuonDT1DCosmicRecHitsSize_(0),
  p_MuonDT1DCosmicRecHitsSize_(&MuonDT1DCosmicRecHitsSize_),
  b_MuonDT1DCosmicRecHitsSize_(NULL),
  c_MuonDT1DCosmicRecHitsSize_(false),
  MuonDT1DRecHitsSize_(0),
  p_MuonDT1DRecHitsSize_(&MuonDT1DRecHitsSize_),
  b_MuonDT1DRecHitsSize_(NULL),
  c_MuonDT1DRecHitsSize_(false),
  MuonDTRecCosmicSegmentsSize_(0),
  p_MuonDTRecCosmicSegmentsSize_(&MuonDTRecCosmicSegmentsSize_),
  b_MuonDTRecCosmicSegmentsSize_(NULL),
  c_MuonDTRecCosmicSegmentsSize_(false),
  MuonDTRecSegmentsSize_(0),
  p_MuonDTRecSegmentsSize_(&MuonDTRecSegmentsSize_),
  b_MuonDTRecSegmentsSize_(NULL),
  c_MuonDTRecSegmentsSize_(false),
  MuonNumberOfChambers_(0),
  p_MuonNumberOfChambers_(&MuonNumberOfChambers_),
  b_MuonNumberOfChambers_(NULL),
  c_MuonNumberOfChambers_(false),
  MuonNumberOfMatchedRPCLayers_(0),
  p_MuonNumberOfMatchedRPCLayers_(&MuonNumberOfMatchedRPCLayers_),
  b_MuonNumberOfMatchedRPCLayers_(NULL),
  c_MuonNumberOfMatchedRPCLayers_(false),
  MuonNumberOfMatchedStations_(0),
  p_MuonNumberOfMatchedStations_(&MuonNumberOfMatchedStations_),
  b_MuonNumberOfMatchedStations_(NULL),
  c_MuonNumberOfMatchedStations_(false),
  MuonRPCRecHitsSize_(0),
  p_MuonRPCRecHitsSize_(&MuonRPCRecHitsSize_),
  b_MuonRPCRecHitsSize_(NULL),
  c_MuonRPCRecHitsSize_(false),
  NumIsolatedNoiseChannels_(0),
  p_NumIsolatedNoiseChannels_(&NumIsolatedNoiseChannels_),
  b_NumIsolatedNoiseChannels_(NULL),
  c_NumIsolatedNoiseChannels_(false),
  NumNegativeNoiseChannels_(0),
  p_NumNegativeNoiseChannels_(&NumNegativeNoiseChannels_),
  b_NumNegativeNoiseChannels_(NULL),
  c_NumNegativeNoiseChannels_(false),
  NumSpikeNoiseChannels_(0),
  p_NumSpikeNoiseChannels_(&NumSpikeNoiseChannels_),
  b_NumSpikeNoiseChannels_(NULL),
  c_NumSpikeNoiseChannels_(false),
  OfficialDecision_(0),
  p_OfficialDecision_(&OfficialDecision_),
  b_OfficialDecision_(NULL),
  c_OfficialDecision_(false),
  OfficialDecisionRun1_(0),
  p_OfficialDecisionRun1_(&OfficialDecisionRun1_),
  b_OfficialDecisionRun1_(NULL),
  c_OfficialDecisionRun1_(false),
  OfficialDecisionRun2L_(0),
  p_OfficialDecisionRun2L_(&OfficialDecisionRun2L_),
  b_OfficialDecisionRun2L_(NULL),
  c_OfficialDecisionRun2L_(false),
  OfficialDecisionRun2T_(0),
  p_OfficialDecisionRun2T_(&OfficialDecisionRun2T_),
  b_OfficialDecisionRun2T_(NULL),
  c_OfficialDecisionRun2T_(false),
  HLTInsideDatasetTriggerNames_(0),
  p_HLTInsideDatasetTriggerNames_(&HLTInsideDatasetTriggerNames_),
  b_HLTInsideDatasetTriggerNames_(NULL),
  c_HLTInsideDatasetTriggerNames_(false),
  HLTOutsideDatasetTriggerNames_(0),
  p_HLTOutsideDatasetTriggerNames_(&HLTOutsideDatasetTriggerNames_),
  b_HLTOutsideDatasetTriggerNames_(NULL),
  c_HLTOutsideDatasetTriggerNames_(false),
  HBHERecHitAuxAllfC_(0),
  p_HBHERecHitAuxAllfC_(&HBHERecHitAuxAllfC_),
  b_HBHERecHitAuxAllfC_(NULL),
  c_HBHERecHitAuxAllfC_(false),
  HBHERecHitAuxEnergy_(0),
  p_HBHERecHitAuxEnergy_(&HBHERecHitAuxEnergy_),
  b_HBHERecHitAuxEnergy_(NULL),
  c_HBHERecHitAuxEnergy_(false),
  HBHERecHitAuxFC_(0),
  p_HBHERecHitAuxFC_(&HBHERecHitAuxFC_),
  b_HBHERecHitAuxFC_(NULL),
  c_HBHERecHitAuxFC_(false),
  HBHERecHitAuxGain_(0),
  p_HBHERecHitAuxGain_(&HBHERecHitAuxGain_),
  b_HBHERecHitAuxGain_(NULL),
  c_HBHERecHitAuxGain_(false),
  HBHERecHitAuxPedFC_(0),
  p_HBHERecHitAuxPedFC_(&HBHERecHitAuxPedFC_),
  b_HBHERecHitAuxPedFC_(NULL),
  c_HBHERecHitAuxPedFC_(false),
  HBHERecHitAuxRCGain_(0),
  p_HBHERecHitAuxRCGain_(&HBHERecHitAuxRCGain_),
  b_HBHERecHitAuxRCGain_(NULL),
  c_HBHERecHitAuxRCGain_(false),
  RBXCharge_(0),
  p_RBXCharge_(&RBXCharge_),
  b_RBXCharge_(NULL),
  c_RBXCharge_(false),
  RBXCharge15_(0),
  p_RBXCharge15_(&RBXCharge15_),
  b_RBXCharge15_(NULL),
  c_RBXCharge15_(false),
  HBHERecHitAuxADC_(0),
  p_HBHERecHitAuxADC_(&HBHERecHitAuxADC_),
  b_HBHERecHitAuxADC_(NULL),
  c_HBHERecHitAuxADC_(false),
  HBHERecHitAuxCapID_(0),
  p_HBHERecHitAuxCapID_(&HBHERecHitAuxCapID_),
  b_HBHERecHitAuxCapID_(NULL),
  c_HBHERecHitAuxCapID_(false),
  L1PhysBits_(0),
  p_L1PhysBits_(&L1PhysBits_),
  b_L1PhysBits_(NULL),
  c_L1PhysBits_(false),
  L1TechBits_(0),
  p_L1TechBits_(&L1TechBits_),
  b_L1TechBits_(NULL),
  c_L1TechBits_(false){
  chain_.Add(filename.c_str());
  chain_.SetBranchAddress("bx", &bx_, &b_bx_);
  chain_.SetBranchAddress("event", &event_, &b_event_);
  chain_.SetBranchAddress("ls", &ls_, &b_ls_);
  chain_.SetBranchAddress("run", &run_, &b_run_);
  chain_.SetBranchAddress("HLTInsideDatasetTriggerDecisions", &p_HLTInsideDatasetTriggerDecisions_, &b_HLTInsideDatasetTriggerDecisions_);
  chain_.SetBranchAddress("HLTOutsideDatasetTriggerDecisions", &p_HLTOutsideDatasetTriggerDecisions_, &b_HLTOutsideDatasetTriggerDecisions_);
  chain_.SetBranchAddress("EBET", &p_EBET_, &b_EBET_);
  chain_.SetBranchAddress("EBSumE", &p_EBSumE_, &b_EBSumE_);
  chain_.SetBranchAddress("EBSumET", &p_EBSumET_, &b_EBSumET_);
  chain_.SetBranchAddress("EEET", &p_EEET_, &b_EEET_);
  chain_.SetBranchAddress("EESumE", &p_EESumE_, &b_EESumE_);
  chain_.SetBranchAddress("EESumET", &p_EESumET_, &b_EESumET_);
  chain_.SetBranchAddress("HBET", &p_HBET_, &b_HBET_);
  chain_.SetBranchAddress("HBHERecHitEnergyRaw", &p_HBHERecHitEnergyRaw_, &b_HBHERecHitEnergyRaw_);
  chain_.SetBranchAddress("HBSumE", &p_HBSumE_, &b_HBSumE_);
  chain_.SetBranchAddress("HBSumET", &p_HBSumET_, &b_HBSumET_);
  chain_.SetBranchAddress("HEET", &p_HEET_, &b_HEET_);
  chain_.SetBranchAddress("HESumE", &p_HESumE_, &b_HESumE_);
  chain_.SetBranchAddress("HESumET", &p_HESumET_, &b_HESumET_);
  chain_.SetBranchAddress("HFET", &p_HFET_, &b_HFET_);
  chain_.SetBranchAddress("IsolatedNoiseSumE", &p_IsolatedNoiseSumE_, &b_IsolatedNoiseSumE_);
  chain_.SetBranchAddress("IsolatedNoiseSumEt", &p_IsolatedNoiseSumEt_, &b_IsolatedNoiseSumEt_);
  chain_.SetBranchAddress("JetEMEB", &p_JetEMEB_, &b_JetEMEB_);
  chain_.SetBranchAddress("JetEMEE", &p_JetEMEE_, &b_JetEMEE_);
  chain_.SetBranchAddress("JetEMFrac", &p_JetEMFrac_, &b_JetEMFrac_);
  chain_.SetBranchAddress("JetEMHF", &p_JetEMHF_, &b_JetEMHF_);
  chain_.SetBranchAddress("JetEta", &p_JetEta_, &b_JetEta_);
  chain_.SetBranchAddress("JetHadFrac", &p_JetHadFrac_, &b_JetHadFrac_);
  chain_.SetBranchAddress("JetHadHB", &p_JetHadHB_, &b_JetHadHB_);
  chain_.SetBranchAddress("JetHadHE", &p_JetHadHE_, &b_JetHadHE_);
  chain_.SetBranchAddress("JetHadHF", &p_JetHadHF_, &b_JetHadHF_);
  chain_.SetBranchAddress("JetPhi", &p_JetPhi_, &b_JetPhi_);
  chain_.SetBranchAddress("JetPt", &p_JetPt_, &b_JetPt_);
  chain_.SetBranchAddress("MaxE2E10", &p_MaxE2E10_, &b_MaxE2E10_);
  chain_.SetBranchAddress("MinE2E10", &p_MinE2E10_, &b_MinE2E10_);
  chain_.SetBranchAddress("MuonCalEnergyEm", &p_MuonCalEnergyEm_, &b_MuonCalEnergyEm_);
  chain_.SetBranchAddress("MuonCalEnergyEmS25", &p_MuonCalEnergyEmS25_, &b_MuonCalEnergyEmS25_);
  chain_.SetBranchAddress("MuonCalEnergyHad", &p_MuonCalEnergyHad_, &b_MuonCalEnergyHad_);
  chain_.SetBranchAddress("MuonCalEnergyHadS9", &p_MuonCalEnergyHadS9_, &b_MuonCalEnergyHadS9_);
  chain_.SetBranchAddress("MuonEta", &p_MuonEta_, &b_MuonEta_);
  chain_.SetBranchAddress("MuonPhi", &p_MuonPhi_, &b_MuonPhi_);
  chain_.SetBranchAddress("MuonPt", &p_MuonPt_, &b_MuonPt_);
  chain_.SetBranchAddress("NegativeNoiseSumE", &p_NegativeNoiseSumE_, &b_NegativeNoiseSumE_);
  chain_.SetBranchAddress("NegativeNoiseSumEt", &p_NegativeNoiseSumEt_, &b_NegativeNoiseSumEt_);
  chain_.SetBranchAddress("NominalMET", &p_NominalMET_, &b_NominalMET_);
  chain_.SetBranchAddress("RBXEnergy", &p_RBXEnergy_, &b_RBXEnergy_);
  chain_.SetBranchAddress("RBXEnergy15", &p_RBXEnergy15_, &b_RBXEnergy15_);
  chain_.SetBranchAddress("SpikeNoiseSumE", &p_SpikeNoiseSumE_, &b_SpikeNoiseSumE_);
  chain_.SetBranchAddress("SpikeNoiseSumEt", &p_SpikeNoiseSumEt_, &b_SpikeNoiseSumEt_);
  chain_.SetBranchAddress("HBHERecHitEnergy", &p_HBHERecHitEnergy_, &b_HBHERecHitEnergy_);
  chain_.SetBranchAddress("HBHERecHitEta", &p_HBHERecHitEta_, &b_HBHERecHitEta_);
  chain_.SetBranchAddress("HBHERecHitPhi", &p_HBHERecHitPhi_, &b_HBHERecHitPhi_);
  chain_.SetBranchAddress("HBHERecHitTime", &p_HBHERecHitTime_, &b_HBHERecHitTime_);
  chain_.SetBranchAddress("HFRecHitEnergy", &p_HFRecHitEnergy_, &b_HFRecHitEnergy_);
  chain_.SetBranchAddress("HFRecHitEta", &p_HFRecHitEta_, &b_HFRecHitEta_);
  chain_.SetBranchAddress("HFRecHitPhi", &p_HFRecHitPhi_, &b_HFRecHitPhi_);
  chain_.SetBranchAddress("HFRecHitTime", &p_HFRecHitTime_, &b_HFRecHitTime_);
  chain_.SetBranchAddress("HBHERecHitAux", &p_HBHERecHitAux_, &b_HBHERecHitAux_);
  chain_.SetBranchAddress("HBHERecHitDepth", &p_HBHERecHitDepth_, &b_HBHERecHitDepth_);
  chain_.SetBranchAddress("HBHERecHitFlags", &p_HBHERecHitFlags_, &b_HBHERecHitFlags_);
  chain_.SetBranchAddress("HBHERecHitHPDid", &p_HBHERecHitHPDid_, &b_HBHERecHitHPDid_);
  chain_.SetBranchAddress("HBHERecHitIEta", &p_HBHERecHitIEta_, &b_HBHERecHitIEta_);
  chain_.SetBranchAddress("HBHERecHitIPhi", &p_HBHERecHitIPhi_, &b_HBHERecHitIPhi_);
  chain_.SetBranchAddress("HBHERecHitRBXid", &p_HBHERecHitRBXid_, &b_HBHERecHitRBXid_);
  chain_.SetBranchAddress("HFRecHitAux", &p_HFRecHitAux_, &b_HFRecHitAux_);
  chain_.SetBranchAddress("HFRecHitDepth", &p_HFRecHitDepth_, &b_HFRecHitDepth_);
  chain_.SetBranchAddress("HFRecHitFlags", &p_HFRecHitFlags_, &b_HFRecHitFlags_);
  chain_.SetBranchAddress("HFRecHitHPDid", &p_HFRecHitHPDid_, &b_HFRecHitHPDid_);
  chain_.SetBranchAddress("HFRecHitIEta", &p_HFRecHitIEta_, &b_HFRecHitIEta_);
  chain_.SetBranchAddress("HFRecHitIPhi", &p_HFRecHitIPhi_, &b_HFRecHitIPhi_);
  chain_.SetBranchAddress("HFRecHitRBXid", &p_HFRecHitRBXid_, &b_HFRecHitRBXid_);
  chain_.SetBranchAddress("HLTBits", &p_HLTBits_, &b_HLTBits_);
  chain_.SetBranchAddress("HLTInsideDatasetTriggerPrescales", &p_HLTInsideDatasetTriggerPrescales_, &b_HLTInsideDatasetTriggerPrescales_);
  chain_.SetBranchAddress("HLTOutsideDatasetTriggerPrescales", &p_HLTOutsideDatasetTriggerPrescales_, &b_HLTOutsideDatasetTriggerPrescales_);
  chain_.SetBranchAddress("HPDHits", &p_HPDHits_, &b_HPDHits_);
  chain_.SetBranchAddress("HPDNoOtherHits", &p_HPDNoOtherHits_, &b_HPDNoOtherHits_);
  chain_.SetBranchAddress("HasBadRBXR45", &p_HasBadRBXR45_, &b_HasBadRBXR45_);
  chain_.SetBranchAddress("HasBadRBXRechitR45Loose", &p_HasBadRBXRechitR45Loose_, &b_HasBadRBXRechitR45Loose_);
  chain_.SetBranchAddress("HasBadRBXRechitR45Tight", &p_HasBadRBXRechitR45Tight_, &b_HasBadRBXRechitR45Tight_);
  chain_.SetBranchAddress("IsoNoiseFilterDecision", &p_IsoNoiseFilterDecision_, &b_IsoNoiseFilterDecision_);
  chain_.SetBranchAddress("JetN60", &p_JetN60_, &b_JetN60_);
  chain_.SetBranchAddress("JetN90", &p_JetN90_, &b_JetN90_);
  chain_.SetBranchAddress("MaxZeros", &p_MaxZeros_, &b_MaxZeros_);
  chain_.SetBranchAddress("MuonCSC2DRecHitsSize", &p_MuonCSC2DRecHitsSize_, &b_MuonCSC2DRecHitsSize_);
  chain_.SetBranchAddress("MuonCSCSegmentsSize", &p_MuonCSCSegmentsSize_, &b_MuonCSCSegmentsSize_);
  chain_.SetBranchAddress("MuonDT1DCosmicRecHitsSize", &p_MuonDT1DCosmicRecHitsSize_, &b_MuonDT1DCosmicRecHitsSize_);
  chain_.SetBranchAddress("MuonDT1DRecHitsSize", &p_MuonDT1DRecHitsSize_, &b_MuonDT1DRecHitsSize_);
  chain_.SetBranchAddress("MuonDTRecCosmicSegmentsSize", &p_MuonDTRecCosmicSegmentsSize_, &b_MuonDTRecCosmicSegmentsSize_);
  chain_.SetBranchAddress("MuonDTRecSegmentsSize", &p_MuonDTRecSegmentsSize_, &b_MuonDTRecSegmentsSize_);
  chain_.SetBranchAddress("MuonNumberOfChambers", &p_MuonNumberOfChambers_, &b_MuonNumberOfChambers_);
  chain_.SetBranchAddress("MuonNumberOfMatchedRPCLayers", &p_MuonNumberOfMatchedRPCLayers_, &b_MuonNumberOfMatchedRPCLayers_);
  chain_.SetBranchAddress("MuonNumberOfMatchedStations", &p_MuonNumberOfMatchedStations_, &b_MuonNumberOfMatchedStations_);
  chain_.SetBranchAddress("MuonRPCRecHitsSize", &p_MuonRPCRecHitsSize_, &b_MuonRPCRecHitsSize_);
  chain_.SetBranchAddress("NumIsolatedNoiseChannels", &p_NumIsolatedNoiseChannels_, &b_NumIsolatedNoiseChannels_);
  chain_.SetBranchAddress("NumNegativeNoiseChannels", &p_NumNegativeNoiseChannels_, &b_NumNegativeNoiseChannels_);
  chain_.SetBranchAddress("NumSpikeNoiseChannels", &p_NumSpikeNoiseChannels_, &b_NumSpikeNoiseChannels_);
  chain_.SetBranchAddress("OfficialDecision", &p_OfficialDecision_, &b_OfficialDecision_);
  chain_.SetBranchAddress("OfficialDecisionRun1", &p_OfficialDecisionRun1_, &b_OfficialDecisionRun1_);
  chain_.SetBranchAddress("OfficialDecisionRun2L", &p_OfficialDecisionRun2L_, &b_OfficialDecisionRun2L_);
  chain_.SetBranchAddress("OfficialDecisionRun2T", &p_OfficialDecisionRun2T_, &b_OfficialDecisionRun2T_);
  chain_.SetBranchAddress("HLTInsideDatasetTriggerNames", &p_HLTInsideDatasetTriggerNames_, &b_HLTInsideDatasetTriggerNames_);
  chain_.SetBranchAddress("HLTOutsideDatasetTriggerNames", &p_HLTOutsideDatasetTriggerNames_, &b_HLTOutsideDatasetTriggerNames_);
  chain_.SetBranchAddress("HBHERecHitAuxAllfC", &p_HBHERecHitAuxAllfC_, &b_HBHERecHitAuxAllfC_);
  chain_.SetBranchAddress("HBHERecHitAuxEnergy", &p_HBHERecHitAuxEnergy_, &b_HBHERecHitAuxEnergy_);
  chain_.SetBranchAddress("HBHERecHitAuxFC", &p_HBHERecHitAuxFC_, &b_HBHERecHitAuxFC_);
  chain_.SetBranchAddress("HBHERecHitAuxGain", &p_HBHERecHitAuxGain_, &b_HBHERecHitAuxGain_);
  chain_.SetBranchAddress("HBHERecHitAuxPedFC", &p_HBHERecHitAuxPedFC_, &b_HBHERecHitAuxPedFC_);
  chain_.SetBranchAddress("HBHERecHitAuxRCGain", &p_HBHERecHitAuxRCGain_, &b_HBHERecHitAuxRCGain_);
  chain_.SetBranchAddress("RBXCharge", &p_RBXCharge_, &b_RBXCharge_);
  chain_.SetBranchAddress("RBXCharge15", &p_RBXCharge15_, &b_RBXCharge15_);
  chain_.SetBranchAddress("HBHERecHitAuxADC", &p_HBHERecHitAuxADC_, &b_HBHERecHitAuxADC_);
  chain_.SetBranchAddress("HBHERecHitAuxCapID", &p_HBHERecHitAuxCapID_, &b_HBHERecHitAuxCapID_);
  chain_.SetBranchAddress("L1PhysBits", &p_L1PhysBits_, &b_L1PhysBits_);
  chain_.SetBranchAddress("L1TechBits", &p_L1TechBits_, &b_L1TechBits_);
}

void hcal_tree::Fill(){
  if(read_only_){
    throw std::logic_error("Trying to write to read-only tree");
  }else{
    tree_.Fill();
  }

  //Resetting variables
  bx_ = static_cast<int >(bad_val_);
  event_ = static_cast<int >(bad_val_);
  ls_ = static_cast<int >(bad_val_);
  run_ = static_cast<int >(bad_val_);
  HLTInsideDatasetTriggerDecisions_.clear();
  HLTOutsideDatasetTriggerDecisions_.clear();
  EBET_.clear();
  EBSumE_.clear();
  EBSumET_.clear();
  EEET_.clear();
  EESumE_.clear();
  EESumET_.clear();
  HBET_.clear();
  HBHERecHitEnergyRaw_.clear();
  HBSumE_.clear();
  HBSumET_.clear();
  HEET_.clear();
  HESumE_.clear();
  HESumET_.clear();
  HFET_.clear();
  IsolatedNoiseSumE_.clear();
  IsolatedNoiseSumEt_.clear();
  JetEMEB_.clear();
  JetEMEE_.clear();
  JetEMFrac_.clear();
  JetEMHF_.clear();
  JetEta_.clear();
  JetHadFrac_.clear();
  JetHadHB_.clear();
  JetHadHE_.clear();
  JetHadHF_.clear();
  JetPhi_.clear();
  JetPt_.clear();
  MaxE2E10_.clear();
  MinE2E10_.clear();
  MuonCalEnergyEm_.clear();
  MuonCalEnergyEmS25_.clear();
  MuonCalEnergyHad_.clear();
  MuonCalEnergyHadS9_.clear();
  MuonEta_.clear();
  MuonPhi_.clear();
  MuonPt_.clear();
  NegativeNoiseSumE_.clear();
  NegativeNoiseSumEt_.clear();
  NominalMET_.clear();
  RBXEnergy_.clear();
  RBXEnergy15_.clear();
  SpikeNoiseSumE_.clear();
  SpikeNoiseSumEt_.clear();
  HBHERecHitEnergy_.clear();
  HBHERecHitEta_.clear();
  HBHERecHitPhi_.clear();
  HBHERecHitTime_.clear();
  HFRecHitEnergy_.clear();
  HFRecHitEta_.clear();
  HFRecHitPhi_.clear();
  HFRecHitTime_.clear();
  HBHERecHitAux_.clear();
  HBHERecHitDepth_.clear();
  HBHERecHitFlags_.clear();
  HBHERecHitHPDid_.clear();
  HBHERecHitIEta_.clear();
  HBHERecHitIPhi_.clear();
  HBHERecHitRBXid_.clear();
  HFRecHitAux_.clear();
  HFRecHitDepth_.clear();
  HFRecHitFlags_.clear();
  HFRecHitHPDid_.clear();
  HFRecHitIEta_.clear();
  HFRecHitIPhi_.clear();
  HFRecHitRBXid_.clear();
  HLTBits_.clear();
  HLTInsideDatasetTriggerPrescales_.clear();
  HLTOutsideDatasetTriggerPrescales_.clear();
  HPDHits_.clear();
  HPDNoOtherHits_.clear();
  HasBadRBXR45_.clear();
  HasBadRBXRechitR45Loose_.clear();
  HasBadRBXRechitR45Tight_.clear();
  IsoNoiseFilterDecision_.clear();
  JetN60_.clear();
  JetN90_.clear();
  MaxZeros_.clear();
  MuonCSC2DRecHitsSize_.clear();
  MuonCSCSegmentsSize_.clear();
  MuonDT1DCosmicRecHitsSize_.clear();
  MuonDT1DRecHitsSize_.clear();
  MuonDTRecCosmicSegmentsSize_.clear();
  MuonDTRecSegmentsSize_.clear();
  MuonNumberOfChambers_.clear();
  MuonNumberOfMatchedRPCLayers_.clear();
  MuonNumberOfMatchedStations_.clear();
  MuonRPCRecHitsSize_.clear();
  NumIsolatedNoiseChannels_.clear();
  NumNegativeNoiseChannels_.clear();
  NumSpikeNoiseChannels_.clear();
  OfficialDecision_.clear();
  OfficialDecisionRun1_.clear();
  OfficialDecisionRun2L_.clear();
  OfficialDecisionRun2T_.clear();
  HLTInsideDatasetTriggerNames_.clear();
  HLTOutsideDatasetTriggerNames_.clear();
  HBHERecHitAuxAllfC_.clear();
  HBHERecHitAuxEnergy_.clear();
  HBHERecHitAuxFC_.clear();
  HBHERecHitAuxGain_.clear();
  HBHERecHitAuxPedFC_.clear();
  HBHERecHitAuxRCGain_.clear();
  RBXCharge_.clear();
  RBXCharge15_.clear();
  HBHERecHitAuxADC_.clear();
  HBHERecHitAuxCapID_.clear();
  L1PhysBits_.clear();
  L1TechBits_.clear();
}

void hcal_tree::Write(){
  if(read_only_){
    throw std::logic_error("Trying to write to read-only tree.");
  }else{
    tree_.Write();
  }
}

string hcal_tree::Type() const{
  return "";
}

hcal_tree::~hcal_tree(){
}

int hcal_tree::Add(const std::string &filename){
  if(!read_only_){
    throw std::logic_error("Trying to add files to tree opened for writing.");
  }
  return chain_.Add(filename.c_str());
}

float hcal_tree::GetBranchValue(TString branch){
 TTreeFormula f("formula",branch, &chain_);
 float result = f.EvalInstance(0);
 return result;
}

bool hcal_tree::PassString(TString cut){
 TTreeFormula f("formula",cut, &chain_);
 bool result = f.EvalInstance(0);
 return result;
}

long hcal_tree::GetEntries() const{
  if(read_only_){
    return chain_.GetEntries();
  }else{
    return tree_.GetEntries();
  }
}

void hcal_tree::GetEntry(const long entry){
  if(!read_only_){
    throw std::logic_error("Trying to read from write-only tree.");
  }

  c_bx_ = false;
  c_event_ = false;
  c_ls_ = false;
  c_run_ = false;
  c_HLTInsideDatasetTriggerDecisions_ = false;
  c_HLTOutsideDatasetTriggerDecisions_ = false;
  c_EBET_ = false;
  c_EBSumE_ = false;
  c_EBSumET_ = false;
  c_EEET_ = false;
  c_EESumE_ = false;
  c_EESumET_ = false;
  c_HBET_ = false;
  c_HBHERecHitEnergyRaw_ = false;
  c_HBSumE_ = false;
  c_HBSumET_ = false;
  c_HEET_ = false;
  c_HESumE_ = false;
  c_HESumET_ = false;
  c_HFET_ = false;
  c_IsolatedNoiseSumE_ = false;
  c_IsolatedNoiseSumEt_ = false;
  c_JetEMEB_ = false;
  c_JetEMEE_ = false;
  c_JetEMFrac_ = false;
  c_JetEMHF_ = false;
  c_JetEta_ = false;
  c_JetHadFrac_ = false;
  c_JetHadHB_ = false;
  c_JetHadHE_ = false;
  c_JetHadHF_ = false;
  c_JetPhi_ = false;
  c_JetPt_ = false;
  c_MaxE2E10_ = false;
  c_MinE2E10_ = false;
  c_MuonCalEnergyEm_ = false;
  c_MuonCalEnergyEmS25_ = false;
  c_MuonCalEnergyHad_ = false;
  c_MuonCalEnergyHadS9_ = false;
  c_MuonEta_ = false;
  c_MuonPhi_ = false;
  c_MuonPt_ = false;
  c_NegativeNoiseSumE_ = false;
  c_NegativeNoiseSumEt_ = false;
  c_NominalMET_ = false;
  c_RBXEnergy_ = false;
  c_RBXEnergy15_ = false;
  c_SpikeNoiseSumE_ = false;
  c_SpikeNoiseSumEt_ = false;
  c_HBHERecHitEnergy_ = false;
  c_HBHERecHitEta_ = false;
  c_HBHERecHitPhi_ = false;
  c_HBHERecHitTime_ = false;
  c_HFRecHitEnergy_ = false;
  c_HFRecHitEta_ = false;
  c_HFRecHitPhi_ = false;
  c_HFRecHitTime_ = false;
  c_HBHERecHitAux_ = false;
  c_HBHERecHitDepth_ = false;
  c_HBHERecHitFlags_ = false;
  c_HBHERecHitHPDid_ = false;
  c_HBHERecHitIEta_ = false;
  c_HBHERecHitIPhi_ = false;
  c_HBHERecHitRBXid_ = false;
  c_HFRecHitAux_ = false;
  c_HFRecHitDepth_ = false;
  c_HFRecHitFlags_ = false;
  c_HFRecHitHPDid_ = false;
  c_HFRecHitIEta_ = false;
  c_HFRecHitIPhi_ = false;
  c_HFRecHitRBXid_ = false;
  c_HLTBits_ = false;
  c_HLTInsideDatasetTriggerPrescales_ = false;
  c_HLTOutsideDatasetTriggerPrescales_ = false;
  c_HPDHits_ = false;
  c_HPDNoOtherHits_ = false;
  c_HasBadRBXR45_ = false;
  c_HasBadRBXRechitR45Loose_ = false;
  c_HasBadRBXRechitR45Tight_ = false;
  c_IsoNoiseFilterDecision_ = false;
  c_JetN60_ = false;
  c_JetN90_ = false;
  c_MaxZeros_ = false;
  c_MuonCSC2DRecHitsSize_ = false;
  c_MuonCSCSegmentsSize_ = false;
  c_MuonDT1DCosmicRecHitsSize_ = false;
  c_MuonDT1DRecHitsSize_ = false;
  c_MuonDTRecCosmicSegmentsSize_ = false;
  c_MuonDTRecSegmentsSize_ = false;
  c_MuonNumberOfChambers_ = false;
  c_MuonNumberOfMatchedRPCLayers_ = false;
  c_MuonNumberOfMatchedStations_ = false;
  c_MuonRPCRecHitsSize_ = false;
  c_NumIsolatedNoiseChannels_ = false;
  c_NumNegativeNoiseChannels_ = false;
  c_NumSpikeNoiseChannels_ = false;
  c_OfficialDecision_ = false;
  c_OfficialDecisionRun1_ = false;
  c_OfficialDecisionRun2L_ = false;
  c_OfficialDecisionRun2T_ = false;
  c_HLTInsideDatasetTriggerNames_ = false;
  c_HLTOutsideDatasetTriggerNames_ = false;
  c_HBHERecHitAuxAllfC_ = false;
  c_HBHERecHitAuxEnergy_ = false;
  c_HBHERecHitAuxFC_ = false;
  c_HBHERecHitAuxGain_ = false;
  c_HBHERecHitAuxPedFC_ = false;
  c_HBHERecHitAuxRCGain_ = false;
  c_RBXCharge_ = false;
  c_RBXCharge15_ = false;
  c_HBHERecHitAuxADC_ = false;
  c_HBHERecHitAuxCapID_ = false;
  c_L1PhysBits_ = false;
  c_L1TechBits_ = false;
  entry_ = chain_.LoadTree(entry);
}

int  const & hcal_tree::bx() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_bx_ && b_bx_){
    b_bx_->GetEntry(entry_);
    c_bx_ = true;
  }
  return bx_;
}

int  const & hcal_tree::event() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

int  const & hcal_tree::ls() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_ls_ && b_ls_){
    b_ls_->GetEntry(entry_);
    c_ls_ = true;
  }
  return ls_;
}

int  const & hcal_tree::run() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<bool>  const & hcal_tree::HLTInsideDatasetTriggerDecisions() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTInsideDatasetTriggerDecisions_ && b_HLTInsideDatasetTriggerDecisions_){
    b_HLTInsideDatasetTriggerDecisions_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerDecisions_ = true;
  }
  return HLTInsideDatasetTriggerDecisions_;
}

std::vector<bool>  const & hcal_tree::HLTOutsideDatasetTriggerDecisions() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTOutsideDatasetTriggerDecisions_ && b_HLTOutsideDatasetTriggerDecisions_){
    b_HLTOutsideDatasetTriggerDecisions_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerDecisions_ = true;
  }
  return HLTOutsideDatasetTriggerDecisions_;
}

std::vector<double>  const & hcal_tree::EBET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EBET_ && b_EBET_){
    b_EBET_->GetEntry(entry_);
    c_EBET_ = true;
  }
  return EBET_;
}

std::vector<double>  const & hcal_tree::EBSumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EBSumE_ && b_EBSumE_){
    b_EBSumE_->GetEntry(entry_);
    c_EBSumE_ = true;
  }
  return EBSumE_;
}

std::vector<double>  const & hcal_tree::EBSumET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EBSumET_ && b_EBSumET_){
    b_EBSumET_->GetEntry(entry_);
    c_EBSumET_ = true;
  }
  return EBSumET_;
}

std::vector<double>  const & hcal_tree::EEET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EEET_ && b_EEET_){
    b_EEET_->GetEntry(entry_);
    c_EEET_ = true;
  }
  return EEET_;
}

std::vector<double>  const & hcal_tree::EESumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EESumE_ && b_EESumE_){
    b_EESumE_->GetEntry(entry_);
    c_EESumE_ = true;
  }
  return EESumE_;
}

std::vector<double>  const & hcal_tree::EESumET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_EESumET_ && b_EESumET_){
    b_EESumET_->GetEntry(entry_);
    c_EESumET_ = true;
  }
  return EESumET_;
}

std::vector<double>  const & hcal_tree::HBET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBET_ && b_HBET_){
    b_HBET_->GetEntry(entry_);
    c_HBET_ = true;
  }
  return HBET_;
}

std::vector<double>  const & hcal_tree::HBHERecHitEnergyRaw() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitEnergyRaw_ && b_HBHERecHitEnergyRaw_){
    b_HBHERecHitEnergyRaw_->GetEntry(entry_);
    c_HBHERecHitEnergyRaw_ = true;
  }
  return HBHERecHitEnergyRaw_;
}

std::vector<double>  const & hcal_tree::HBSumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBSumE_ && b_HBSumE_){
    b_HBSumE_->GetEntry(entry_);
    c_HBSumE_ = true;
  }
  return HBSumE_;
}

std::vector<double>  const & hcal_tree::HBSumET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBSumET_ && b_HBSumET_){
    b_HBSumET_->GetEntry(entry_);
    c_HBSumET_ = true;
  }
  return HBSumET_;
}

std::vector<double>  const & hcal_tree::HEET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HEET_ && b_HEET_){
    b_HEET_->GetEntry(entry_);
    c_HEET_ = true;
  }
  return HEET_;
}

std::vector<double>  const & hcal_tree::HESumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HESumE_ && b_HESumE_){
    b_HESumE_->GetEntry(entry_);
    c_HESumE_ = true;
  }
  return HESumE_;
}

std::vector<double>  const & hcal_tree::HESumET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HESumET_ && b_HESumET_){
    b_HESumET_->GetEntry(entry_);
    c_HESumET_ = true;
  }
  return HESumET_;
}

std::vector<double>  const & hcal_tree::HFET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFET_ && b_HFET_){
    b_HFET_->GetEntry(entry_);
    c_HFET_ = true;
  }
  return HFET_;
}

std::vector<double>  const & hcal_tree::IsolatedNoiseSumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_IsolatedNoiseSumE_ && b_IsolatedNoiseSumE_){
    b_IsolatedNoiseSumE_->GetEntry(entry_);
    c_IsolatedNoiseSumE_ = true;
  }
  return IsolatedNoiseSumE_;
}

std::vector<double>  const & hcal_tree::IsolatedNoiseSumEt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_IsolatedNoiseSumEt_ && b_IsolatedNoiseSumEt_){
    b_IsolatedNoiseSumEt_->GetEntry(entry_);
    c_IsolatedNoiseSumEt_ = true;
  }
  return IsolatedNoiseSumEt_;
}

std::vector<double>  const & hcal_tree::JetEMEB() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetEMEB_ && b_JetEMEB_){
    b_JetEMEB_->GetEntry(entry_);
    c_JetEMEB_ = true;
  }
  return JetEMEB_;
}

std::vector<double>  const & hcal_tree::JetEMEE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetEMEE_ && b_JetEMEE_){
    b_JetEMEE_->GetEntry(entry_);
    c_JetEMEE_ = true;
  }
  return JetEMEE_;
}

std::vector<double>  const & hcal_tree::JetEMFrac() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetEMFrac_ && b_JetEMFrac_){
    b_JetEMFrac_->GetEntry(entry_);
    c_JetEMFrac_ = true;
  }
  return JetEMFrac_;
}

std::vector<double>  const & hcal_tree::JetEMHF() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetEMHF_ && b_JetEMHF_){
    b_JetEMHF_->GetEntry(entry_);
    c_JetEMHF_ = true;
  }
  return JetEMHF_;
}

std::vector<double>  const & hcal_tree::JetEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetEta_ && b_JetEta_){
    b_JetEta_->GetEntry(entry_);
    c_JetEta_ = true;
  }
  return JetEta_;
}

std::vector<double>  const & hcal_tree::JetHadFrac() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetHadFrac_ && b_JetHadFrac_){
    b_JetHadFrac_->GetEntry(entry_);
    c_JetHadFrac_ = true;
  }
  return JetHadFrac_;
}

std::vector<double>  const & hcal_tree::JetHadHB() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetHadHB_ && b_JetHadHB_){
    b_JetHadHB_->GetEntry(entry_);
    c_JetHadHB_ = true;
  }
  return JetHadHB_;
}

std::vector<double>  const & hcal_tree::JetHadHE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetHadHE_ && b_JetHadHE_){
    b_JetHadHE_->GetEntry(entry_);
    c_JetHadHE_ = true;
  }
  return JetHadHE_;
}

std::vector<double>  const & hcal_tree::JetHadHF() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetHadHF_ && b_JetHadHF_){
    b_JetHadHF_->GetEntry(entry_);
    c_JetHadHF_ = true;
  }
  return JetHadHF_;
}

std::vector<double>  const & hcal_tree::JetPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetPhi_ && b_JetPhi_){
    b_JetPhi_->GetEntry(entry_);
    c_JetPhi_ = true;
  }
  return JetPhi_;
}

std::vector<double>  const & hcal_tree::JetPt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetPt_ && b_JetPt_){
    b_JetPt_->GetEntry(entry_);
    c_JetPt_ = true;
  }
  return JetPt_;
}

std::vector<double>  const & hcal_tree::MaxE2E10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MaxE2E10_ && b_MaxE2E10_){
    b_MaxE2E10_->GetEntry(entry_);
    c_MaxE2E10_ = true;
  }
  return MaxE2E10_;
}

std::vector<double>  const & hcal_tree::MinE2E10() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MinE2E10_ && b_MinE2E10_){
    b_MinE2E10_->GetEntry(entry_);
    c_MinE2E10_ = true;
  }
  return MinE2E10_;
}

std::vector<double>  const & hcal_tree::MuonCalEnergyEm() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCalEnergyEm_ && b_MuonCalEnergyEm_){
    b_MuonCalEnergyEm_->GetEntry(entry_);
    c_MuonCalEnergyEm_ = true;
  }
  return MuonCalEnergyEm_;
}

std::vector<double>  const & hcal_tree::MuonCalEnergyEmS25() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCalEnergyEmS25_ && b_MuonCalEnergyEmS25_){
    b_MuonCalEnergyEmS25_->GetEntry(entry_);
    c_MuonCalEnergyEmS25_ = true;
  }
  return MuonCalEnergyEmS25_;
}

std::vector<double>  const & hcal_tree::MuonCalEnergyHad() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCalEnergyHad_ && b_MuonCalEnergyHad_){
    b_MuonCalEnergyHad_->GetEntry(entry_);
    c_MuonCalEnergyHad_ = true;
  }
  return MuonCalEnergyHad_;
}

std::vector<double>  const & hcal_tree::MuonCalEnergyHadS9() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCalEnergyHadS9_ && b_MuonCalEnergyHadS9_){
    b_MuonCalEnergyHadS9_->GetEntry(entry_);
    c_MuonCalEnergyHadS9_ = true;
  }
  return MuonCalEnergyHadS9_;
}

std::vector<double>  const & hcal_tree::MuonEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonEta_ && b_MuonEta_){
    b_MuonEta_->GetEntry(entry_);
    c_MuonEta_ = true;
  }
  return MuonEta_;
}

std::vector<double>  const & hcal_tree::MuonPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonPhi_ && b_MuonPhi_){
    b_MuonPhi_->GetEntry(entry_);
    c_MuonPhi_ = true;
  }
  return MuonPhi_;
}

std::vector<double>  const & hcal_tree::MuonPt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonPt_ && b_MuonPt_){
    b_MuonPt_->GetEntry(entry_);
    c_MuonPt_ = true;
  }
  return MuonPt_;
}

std::vector<double>  const & hcal_tree::NegativeNoiseSumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NegativeNoiseSumE_ && b_NegativeNoiseSumE_){
    b_NegativeNoiseSumE_->GetEntry(entry_);
    c_NegativeNoiseSumE_ = true;
  }
  return NegativeNoiseSumE_;
}

std::vector<double>  const & hcal_tree::NegativeNoiseSumEt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NegativeNoiseSumEt_ && b_NegativeNoiseSumEt_){
    b_NegativeNoiseSumEt_->GetEntry(entry_);
    c_NegativeNoiseSumEt_ = true;
  }
  return NegativeNoiseSumEt_;
}

std::vector<double>  const & hcal_tree::NominalMET() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NominalMET_ && b_NominalMET_){
    b_NominalMET_->GetEntry(entry_);
    c_NominalMET_ = true;
  }
  return NominalMET_;
}

std::vector<double>  const & hcal_tree::RBXEnergy() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_RBXEnergy_ && b_RBXEnergy_){
    b_RBXEnergy_->GetEntry(entry_);
    c_RBXEnergy_ = true;
  }
  return RBXEnergy_;
}

std::vector<double>  const & hcal_tree::RBXEnergy15() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_RBXEnergy15_ && b_RBXEnergy15_){
    b_RBXEnergy15_->GetEntry(entry_);
    c_RBXEnergy15_ = true;
  }
  return RBXEnergy15_;
}

std::vector<double>  const & hcal_tree::SpikeNoiseSumE() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_SpikeNoiseSumE_ && b_SpikeNoiseSumE_){
    b_SpikeNoiseSumE_->GetEntry(entry_);
    c_SpikeNoiseSumE_ = true;
  }
  return SpikeNoiseSumE_;
}

std::vector<double>  const & hcal_tree::SpikeNoiseSumEt() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_SpikeNoiseSumEt_ && b_SpikeNoiseSumEt_){
    b_SpikeNoiseSumEt_->GetEntry(entry_);
    c_SpikeNoiseSumEt_ = true;
  }
  return SpikeNoiseSumEt_;
}

std::vector<float>  const & hcal_tree::HBHERecHitEnergy() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitEnergy_ && b_HBHERecHitEnergy_){
    b_HBHERecHitEnergy_->GetEntry(entry_);
    c_HBHERecHitEnergy_ = true;
  }
  return HBHERecHitEnergy_;
}

std::vector<float>  const & hcal_tree::HBHERecHitEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitEta_ && b_HBHERecHitEta_){
    b_HBHERecHitEta_->GetEntry(entry_);
    c_HBHERecHitEta_ = true;
  }
  return HBHERecHitEta_;
}

std::vector<float>  const & hcal_tree::HBHERecHitPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitPhi_ && b_HBHERecHitPhi_){
    b_HBHERecHitPhi_->GetEntry(entry_);
    c_HBHERecHitPhi_ = true;
  }
  return HBHERecHitPhi_;
}

std::vector<float>  const & hcal_tree::HBHERecHitTime() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitTime_ && b_HBHERecHitTime_){
    b_HBHERecHitTime_->GetEntry(entry_);
    c_HBHERecHitTime_ = true;
  }
  return HBHERecHitTime_;
}

std::vector<float>  const & hcal_tree::HFRecHitEnergy() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitEnergy_ && b_HFRecHitEnergy_){
    b_HFRecHitEnergy_->GetEntry(entry_);
    c_HFRecHitEnergy_ = true;
  }
  return HFRecHitEnergy_;
}

std::vector<float>  const & hcal_tree::HFRecHitEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitEta_ && b_HFRecHitEta_){
    b_HFRecHitEta_->GetEntry(entry_);
    c_HFRecHitEta_ = true;
  }
  return HFRecHitEta_;
}

std::vector<float>  const & hcal_tree::HFRecHitPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitPhi_ && b_HFRecHitPhi_){
    b_HFRecHitPhi_->GetEntry(entry_);
    c_HFRecHitPhi_ = true;
  }
  return HFRecHitPhi_;
}

std::vector<float>  const & hcal_tree::HFRecHitTime() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitTime_ && b_HFRecHitTime_){
    b_HFRecHitTime_->GetEntry(entry_);
    c_HFRecHitTime_ = true;
  }
  return HFRecHitTime_;
}

std::vector<int>  const & hcal_tree::HBHERecHitAux() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAux_ && b_HBHERecHitAux_){
    b_HBHERecHitAux_->GetEntry(entry_);
    c_HBHERecHitAux_ = true;
  }
  return HBHERecHitAux_;
}

std::vector<int>  const & hcal_tree::HBHERecHitDepth() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitDepth_ && b_HBHERecHitDepth_){
    b_HBHERecHitDepth_->GetEntry(entry_);
    c_HBHERecHitDepth_ = true;
  }
  return HBHERecHitDepth_;
}

std::vector<int>  const & hcal_tree::HBHERecHitFlags() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitFlags_ && b_HBHERecHitFlags_){
    b_HBHERecHitFlags_->GetEntry(entry_);
    c_HBHERecHitFlags_ = true;
  }
  return HBHERecHitFlags_;
}

std::vector<int>  const & hcal_tree::HBHERecHitHPDid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitHPDid_ && b_HBHERecHitHPDid_){
    b_HBHERecHitHPDid_->GetEntry(entry_);
    c_HBHERecHitHPDid_ = true;
  }
  return HBHERecHitHPDid_;
}

std::vector<int>  const & hcal_tree::HBHERecHitIEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitIEta_ && b_HBHERecHitIEta_){
    b_HBHERecHitIEta_->GetEntry(entry_);
    c_HBHERecHitIEta_ = true;
  }
  return HBHERecHitIEta_;
}

std::vector<int>  const & hcal_tree::HBHERecHitIPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitIPhi_ && b_HBHERecHitIPhi_){
    b_HBHERecHitIPhi_->GetEntry(entry_);
    c_HBHERecHitIPhi_ = true;
  }
  return HBHERecHitIPhi_;
}

std::vector<int>  const & hcal_tree::HBHERecHitRBXid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitRBXid_ && b_HBHERecHitRBXid_){
    b_HBHERecHitRBXid_->GetEntry(entry_);
    c_HBHERecHitRBXid_ = true;
  }
  return HBHERecHitRBXid_;
}

std::vector<int>  const & hcal_tree::HFRecHitAux() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitAux_ && b_HFRecHitAux_){
    b_HFRecHitAux_->GetEntry(entry_);
    c_HFRecHitAux_ = true;
  }
  return HFRecHitAux_;
}

std::vector<int>  const & hcal_tree::HFRecHitDepth() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitDepth_ && b_HFRecHitDepth_){
    b_HFRecHitDepth_->GetEntry(entry_);
    c_HFRecHitDepth_ = true;
  }
  return HFRecHitDepth_;
}

std::vector<int>  const & hcal_tree::HFRecHitFlags() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitFlags_ && b_HFRecHitFlags_){
    b_HFRecHitFlags_->GetEntry(entry_);
    c_HFRecHitFlags_ = true;
  }
  return HFRecHitFlags_;
}

std::vector<int>  const & hcal_tree::HFRecHitHPDid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitHPDid_ && b_HFRecHitHPDid_){
    b_HFRecHitHPDid_->GetEntry(entry_);
    c_HFRecHitHPDid_ = true;
  }
  return HFRecHitHPDid_;
}

std::vector<int>  const & hcal_tree::HFRecHitIEta() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitIEta_ && b_HFRecHitIEta_){
    b_HFRecHitIEta_->GetEntry(entry_);
    c_HFRecHitIEta_ = true;
  }
  return HFRecHitIEta_;
}

std::vector<int>  const & hcal_tree::HFRecHitIPhi() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitIPhi_ && b_HFRecHitIPhi_){
    b_HFRecHitIPhi_->GetEntry(entry_);
    c_HFRecHitIPhi_ = true;
  }
  return HFRecHitIPhi_;
}

std::vector<int>  const & hcal_tree::HFRecHitRBXid() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HFRecHitRBXid_ && b_HFRecHitRBXid_){
    b_HFRecHitRBXid_->GetEntry(entry_);
    c_HFRecHitRBXid_ = true;
  }
  return HFRecHitRBXid_;
}

std::vector<int>  const & hcal_tree::HLTBits() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTBits_ && b_HLTBits_){
    b_HLTBits_->GetEntry(entry_);
    c_HLTBits_ = true;
  }
  return HLTBits_;
}

std::vector<int>  const & hcal_tree::HLTInsideDatasetTriggerPrescales() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTInsideDatasetTriggerPrescales_ && b_HLTInsideDatasetTriggerPrescales_){
    b_HLTInsideDatasetTriggerPrescales_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerPrescales_ = true;
  }
  return HLTInsideDatasetTriggerPrescales_;
}

std::vector<int>  const & hcal_tree::HLTOutsideDatasetTriggerPrescales() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTOutsideDatasetTriggerPrescales_ && b_HLTOutsideDatasetTriggerPrescales_){
    b_HLTOutsideDatasetTriggerPrescales_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerPrescales_ = true;
  }
  return HLTOutsideDatasetTriggerPrescales_;
}

std::vector<int>  const & hcal_tree::HPDHits() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HPDHits_ && b_HPDHits_){
    b_HPDHits_->GetEntry(entry_);
    c_HPDHits_ = true;
  }
  return HPDHits_;
}

std::vector<int>  const & hcal_tree::HPDNoOtherHits() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HPDNoOtherHits_ && b_HPDNoOtherHits_){
    b_HPDNoOtherHits_->GetEntry(entry_);
    c_HPDNoOtherHits_ = true;
  }
  return HPDNoOtherHits_;
}

std::vector<int>  const & hcal_tree::HasBadRBXR45() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HasBadRBXR45_ && b_HasBadRBXR45_){
    b_HasBadRBXR45_->GetEntry(entry_);
    c_HasBadRBXR45_ = true;
  }
  return HasBadRBXR45_;
}

std::vector<int>  const & hcal_tree::HasBadRBXRechitR45Loose() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HasBadRBXRechitR45Loose_ && b_HasBadRBXRechitR45Loose_){
    b_HasBadRBXRechitR45Loose_->GetEntry(entry_);
    c_HasBadRBXRechitR45Loose_ = true;
  }
  return HasBadRBXRechitR45Loose_;
}

std::vector<int>  const & hcal_tree::HasBadRBXRechitR45Tight() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HasBadRBXRechitR45Tight_ && b_HasBadRBXRechitR45Tight_){
    b_HasBadRBXRechitR45Tight_->GetEntry(entry_);
    c_HasBadRBXRechitR45Tight_ = true;
  }
  return HasBadRBXRechitR45Tight_;
}

std::vector<int>  const & hcal_tree::IsoNoiseFilterDecision() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_IsoNoiseFilterDecision_ && b_IsoNoiseFilterDecision_){
    b_IsoNoiseFilterDecision_->GetEntry(entry_);
    c_IsoNoiseFilterDecision_ = true;
  }
  return IsoNoiseFilterDecision_;
}

std::vector<int>  const & hcal_tree::JetN60() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetN60_ && b_JetN60_){
    b_JetN60_->GetEntry(entry_);
    c_JetN60_ = true;
  }
  return JetN60_;
}

std::vector<int>  const & hcal_tree::JetN90() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_JetN90_ && b_JetN90_){
    b_JetN90_->GetEntry(entry_);
    c_JetN90_ = true;
  }
  return JetN90_;
}

std::vector<int>  const & hcal_tree::MaxZeros() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MaxZeros_ && b_MaxZeros_){
    b_MaxZeros_->GetEntry(entry_);
    c_MaxZeros_ = true;
  }
  return MaxZeros_;
}

std::vector<int>  const & hcal_tree::MuonCSC2DRecHitsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCSC2DRecHitsSize_ && b_MuonCSC2DRecHitsSize_){
    b_MuonCSC2DRecHitsSize_->GetEntry(entry_);
    c_MuonCSC2DRecHitsSize_ = true;
  }
  return MuonCSC2DRecHitsSize_;
}

std::vector<int>  const & hcal_tree::MuonCSCSegmentsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonCSCSegmentsSize_ && b_MuonCSCSegmentsSize_){
    b_MuonCSCSegmentsSize_->GetEntry(entry_);
    c_MuonCSCSegmentsSize_ = true;
  }
  return MuonCSCSegmentsSize_;
}

std::vector<int>  const & hcal_tree::MuonDT1DCosmicRecHitsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonDT1DCosmicRecHitsSize_ && b_MuonDT1DCosmicRecHitsSize_){
    b_MuonDT1DCosmicRecHitsSize_->GetEntry(entry_);
    c_MuonDT1DCosmicRecHitsSize_ = true;
  }
  return MuonDT1DCosmicRecHitsSize_;
}

std::vector<int>  const & hcal_tree::MuonDT1DRecHitsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonDT1DRecHitsSize_ && b_MuonDT1DRecHitsSize_){
    b_MuonDT1DRecHitsSize_->GetEntry(entry_);
    c_MuonDT1DRecHitsSize_ = true;
  }
  return MuonDT1DRecHitsSize_;
}

std::vector<int>  const & hcal_tree::MuonDTRecCosmicSegmentsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonDTRecCosmicSegmentsSize_ && b_MuonDTRecCosmicSegmentsSize_){
    b_MuonDTRecCosmicSegmentsSize_->GetEntry(entry_);
    c_MuonDTRecCosmicSegmentsSize_ = true;
  }
  return MuonDTRecCosmicSegmentsSize_;
}

std::vector<int>  const & hcal_tree::MuonDTRecSegmentsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonDTRecSegmentsSize_ && b_MuonDTRecSegmentsSize_){
    b_MuonDTRecSegmentsSize_->GetEntry(entry_);
    c_MuonDTRecSegmentsSize_ = true;
  }
  return MuonDTRecSegmentsSize_;
}

std::vector<int>  const & hcal_tree::MuonNumberOfChambers() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonNumberOfChambers_ && b_MuonNumberOfChambers_){
    b_MuonNumberOfChambers_->GetEntry(entry_);
    c_MuonNumberOfChambers_ = true;
  }
  return MuonNumberOfChambers_;
}

std::vector<int>  const & hcal_tree::MuonNumberOfMatchedRPCLayers() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonNumberOfMatchedRPCLayers_ && b_MuonNumberOfMatchedRPCLayers_){
    b_MuonNumberOfMatchedRPCLayers_->GetEntry(entry_);
    c_MuonNumberOfMatchedRPCLayers_ = true;
  }
  return MuonNumberOfMatchedRPCLayers_;
}

std::vector<int>  const & hcal_tree::MuonNumberOfMatchedStations() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonNumberOfMatchedStations_ && b_MuonNumberOfMatchedStations_){
    b_MuonNumberOfMatchedStations_->GetEntry(entry_);
    c_MuonNumberOfMatchedStations_ = true;
  }
  return MuonNumberOfMatchedStations_;
}

std::vector<int>  const & hcal_tree::MuonRPCRecHitsSize() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_MuonRPCRecHitsSize_ && b_MuonRPCRecHitsSize_){
    b_MuonRPCRecHitsSize_->GetEntry(entry_);
    c_MuonRPCRecHitsSize_ = true;
  }
  return MuonRPCRecHitsSize_;
}

std::vector<int>  const & hcal_tree::NumIsolatedNoiseChannels() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NumIsolatedNoiseChannels_ && b_NumIsolatedNoiseChannels_){
    b_NumIsolatedNoiseChannels_->GetEntry(entry_);
    c_NumIsolatedNoiseChannels_ = true;
  }
  return NumIsolatedNoiseChannels_;
}

std::vector<int>  const & hcal_tree::NumNegativeNoiseChannels() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NumNegativeNoiseChannels_ && b_NumNegativeNoiseChannels_){
    b_NumNegativeNoiseChannels_->GetEntry(entry_);
    c_NumNegativeNoiseChannels_ = true;
  }
  return NumNegativeNoiseChannels_;
}

std::vector<int>  const & hcal_tree::NumSpikeNoiseChannels() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_NumSpikeNoiseChannels_ && b_NumSpikeNoiseChannels_){
    b_NumSpikeNoiseChannels_->GetEntry(entry_);
    c_NumSpikeNoiseChannels_ = true;
  }
  return NumSpikeNoiseChannels_;
}

std::vector<int>  const & hcal_tree::OfficialDecision() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_OfficialDecision_ && b_OfficialDecision_){
    b_OfficialDecision_->GetEntry(entry_);
    c_OfficialDecision_ = true;
  }
  return OfficialDecision_;
}

std::vector<int>  const & hcal_tree::OfficialDecisionRun1() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_OfficialDecisionRun1_ && b_OfficialDecisionRun1_){
    b_OfficialDecisionRun1_->GetEntry(entry_);
    c_OfficialDecisionRun1_ = true;
  }
  return OfficialDecisionRun1_;
}

std::vector<int>  const & hcal_tree::OfficialDecisionRun2L() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_OfficialDecisionRun2L_ && b_OfficialDecisionRun2L_){
    b_OfficialDecisionRun2L_->GetEntry(entry_);
    c_OfficialDecisionRun2L_ = true;
  }
  return OfficialDecisionRun2L_;
}

std::vector<int>  const & hcal_tree::OfficialDecisionRun2T() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_OfficialDecisionRun2T_ && b_OfficialDecisionRun2T_){
    b_OfficialDecisionRun2T_->GetEntry(entry_);
    c_OfficialDecisionRun2T_ = true;
  }
  return OfficialDecisionRun2T_;
}

std::vector<std::string>  const & hcal_tree::HLTInsideDatasetTriggerNames() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTInsideDatasetTriggerNames_ && b_HLTInsideDatasetTriggerNames_){
    b_HLTInsideDatasetTriggerNames_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerNames_ = true;
  }
  return HLTInsideDatasetTriggerNames_;
}

std::vector<std::string>  const & hcal_tree::HLTOutsideDatasetTriggerNames() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HLTOutsideDatasetTriggerNames_ && b_HLTOutsideDatasetTriggerNames_){
    b_HLTOutsideDatasetTriggerNames_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerNames_ = true;
  }
  return HLTOutsideDatasetTriggerNames_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxAllfC() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxAllfC_ && b_HBHERecHitAuxAllfC_){
    b_HBHERecHitAuxAllfC_->GetEntry(entry_);
    c_HBHERecHitAuxAllfC_ = true;
  }
  return HBHERecHitAuxAllfC_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxEnergy() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxEnergy_ && b_HBHERecHitAuxEnergy_){
    b_HBHERecHitAuxEnergy_->GetEntry(entry_);
    c_HBHERecHitAuxEnergy_ = true;
  }
  return HBHERecHitAuxEnergy_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxFC() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxFC_ && b_HBHERecHitAuxFC_){
    b_HBHERecHitAuxFC_->GetEntry(entry_);
    c_HBHERecHitAuxFC_ = true;
  }
  return HBHERecHitAuxFC_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxGain() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxGain_ && b_HBHERecHitAuxGain_){
    b_HBHERecHitAuxGain_->GetEntry(entry_);
    c_HBHERecHitAuxGain_ = true;
  }
  return HBHERecHitAuxGain_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxPedFC() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxPedFC_ && b_HBHERecHitAuxPedFC_){
    b_HBHERecHitAuxPedFC_->GetEntry(entry_);
    c_HBHERecHitAuxPedFC_ = true;
  }
  return HBHERecHitAuxPedFC_;
}

std::vector<std::vector<double> >  const & hcal_tree::HBHERecHitAuxRCGain() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxRCGain_ && b_HBHERecHitAuxRCGain_){
    b_HBHERecHitAuxRCGain_->GetEntry(entry_);
    c_HBHERecHitAuxRCGain_ = true;
  }
  return HBHERecHitAuxRCGain_;
}

std::vector<std::vector<double> >  const & hcal_tree::RBXCharge() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_RBXCharge_ && b_RBXCharge_){
    b_RBXCharge_->GetEntry(entry_);
    c_RBXCharge_ = true;
  }
  return RBXCharge_;
}

std::vector<std::vector<double> >  const & hcal_tree::RBXCharge15() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_RBXCharge15_ && b_RBXCharge15_){
    b_RBXCharge15_->GetEntry(entry_);
    c_RBXCharge15_ = true;
  }
  return RBXCharge15_;
}

std::vector<std::vector<int> >  const & hcal_tree::HBHERecHitAuxADC() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxADC_ && b_HBHERecHitAuxADC_){
    b_HBHERecHitAuxADC_->GetEntry(entry_);
    c_HBHERecHitAuxADC_ = true;
  }
  return HBHERecHitAuxADC_;
}

std::vector<std::vector<int> >  const & hcal_tree::HBHERecHitAuxCapID() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_HBHERecHitAuxCapID_ && b_HBHERecHitAuxCapID_){
    b_HBHERecHitAuxCapID_->GetEntry(entry_);
    c_HBHERecHitAuxCapID_ = true;
  }
  return HBHERecHitAuxCapID_;
}

std::vector<std::vector<int> >  const & hcal_tree::L1PhysBits() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_L1PhysBits_ && b_L1PhysBits_){
    b_L1PhysBits_->GetEntry(entry_);
    c_L1PhysBits_ = true;
  }
  return L1PhysBits_;
}

std::vector<std::vector<int> >  const & hcal_tree::L1TechBits() const{
  if(!read_only_){
    throw std::logic_error("Trying to write to const tree.");
  }
  if(!c_L1TechBits_ && b_L1TechBits_){
    b_L1TechBits_->GetEntry(entry_);
    c_L1TechBits_ = true;
  }
  return L1TechBits_;
}

int  & hcal_tree::bx(){
  if(read_only_ && !c_bx_ && b_bx_){
    b_bx_->GetEntry(entry_);
    c_bx_ = true;
  }
  return bx_;
}

int  & hcal_tree::event(){
  if(read_only_ && !c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

int  & hcal_tree::ls(){
  if(read_only_ && !c_ls_ && b_ls_){
    b_ls_->GetEntry(entry_);
    c_ls_ = true;
  }
  return ls_;
}

int  & hcal_tree::run(){
  if(read_only_ && !c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<bool>  & hcal_tree::HLTInsideDatasetTriggerDecisions(){
  if(read_only_ && !c_HLTInsideDatasetTriggerDecisions_ && b_HLTInsideDatasetTriggerDecisions_){
    b_HLTInsideDatasetTriggerDecisions_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerDecisions_ = true;
  }
  return HLTInsideDatasetTriggerDecisions_;
}

std::vector<bool>  & hcal_tree::HLTOutsideDatasetTriggerDecisions(){
  if(read_only_ && !c_HLTOutsideDatasetTriggerDecisions_ && b_HLTOutsideDatasetTriggerDecisions_){
    b_HLTOutsideDatasetTriggerDecisions_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerDecisions_ = true;
  }
  return HLTOutsideDatasetTriggerDecisions_;
}

std::vector<double>  & hcal_tree::EBET(){
  if(read_only_ && !c_EBET_ && b_EBET_){
    b_EBET_->GetEntry(entry_);
    c_EBET_ = true;
  }
  return EBET_;
}

std::vector<double>  & hcal_tree::EBSumE(){
  if(read_only_ && !c_EBSumE_ && b_EBSumE_){
    b_EBSumE_->GetEntry(entry_);
    c_EBSumE_ = true;
  }
  return EBSumE_;
}

std::vector<double>  & hcal_tree::EBSumET(){
  if(read_only_ && !c_EBSumET_ && b_EBSumET_){
    b_EBSumET_->GetEntry(entry_);
    c_EBSumET_ = true;
  }
  return EBSumET_;
}

std::vector<double>  & hcal_tree::EEET(){
  if(read_only_ && !c_EEET_ && b_EEET_){
    b_EEET_->GetEntry(entry_);
    c_EEET_ = true;
  }
  return EEET_;
}

std::vector<double>  & hcal_tree::EESumE(){
  if(read_only_ && !c_EESumE_ && b_EESumE_){
    b_EESumE_->GetEntry(entry_);
    c_EESumE_ = true;
  }
  return EESumE_;
}

std::vector<double>  & hcal_tree::EESumET(){
  if(read_only_ && !c_EESumET_ && b_EESumET_){
    b_EESumET_->GetEntry(entry_);
    c_EESumET_ = true;
  }
  return EESumET_;
}

std::vector<double>  & hcal_tree::HBET(){
  if(read_only_ && !c_HBET_ && b_HBET_){
    b_HBET_->GetEntry(entry_);
    c_HBET_ = true;
  }
  return HBET_;
}

std::vector<double>  & hcal_tree::HBHERecHitEnergyRaw(){
  if(read_only_ && !c_HBHERecHitEnergyRaw_ && b_HBHERecHitEnergyRaw_){
    b_HBHERecHitEnergyRaw_->GetEntry(entry_);
    c_HBHERecHitEnergyRaw_ = true;
  }
  return HBHERecHitEnergyRaw_;
}

std::vector<double>  & hcal_tree::HBSumE(){
  if(read_only_ && !c_HBSumE_ && b_HBSumE_){
    b_HBSumE_->GetEntry(entry_);
    c_HBSumE_ = true;
  }
  return HBSumE_;
}

std::vector<double>  & hcal_tree::HBSumET(){
  if(read_only_ && !c_HBSumET_ && b_HBSumET_){
    b_HBSumET_->GetEntry(entry_);
    c_HBSumET_ = true;
  }
  return HBSumET_;
}

std::vector<double>  & hcal_tree::HEET(){
  if(read_only_ && !c_HEET_ && b_HEET_){
    b_HEET_->GetEntry(entry_);
    c_HEET_ = true;
  }
  return HEET_;
}

std::vector<double>  & hcal_tree::HESumE(){
  if(read_only_ && !c_HESumE_ && b_HESumE_){
    b_HESumE_->GetEntry(entry_);
    c_HESumE_ = true;
  }
  return HESumE_;
}

std::vector<double>  & hcal_tree::HESumET(){
  if(read_only_ && !c_HESumET_ && b_HESumET_){
    b_HESumET_->GetEntry(entry_);
    c_HESumET_ = true;
  }
  return HESumET_;
}

std::vector<double>  & hcal_tree::HFET(){
  if(read_only_ && !c_HFET_ && b_HFET_){
    b_HFET_->GetEntry(entry_);
    c_HFET_ = true;
  }
  return HFET_;
}

std::vector<double>  & hcal_tree::IsolatedNoiseSumE(){
  if(read_only_ && !c_IsolatedNoiseSumE_ && b_IsolatedNoiseSumE_){
    b_IsolatedNoiseSumE_->GetEntry(entry_);
    c_IsolatedNoiseSumE_ = true;
  }
  return IsolatedNoiseSumE_;
}

std::vector<double>  & hcal_tree::IsolatedNoiseSumEt(){
  if(read_only_ && !c_IsolatedNoiseSumEt_ && b_IsolatedNoiseSumEt_){
    b_IsolatedNoiseSumEt_->GetEntry(entry_);
    c_IsolatedNoiseSumEt_ = true;
  }
  return IsolatedNoiseSumEt_;
}

std::vector<double>  & hcal_tree::JetEMEB(){
  if(read_only_ && !c_JetEMEB_ && b_JetEMEB_){
    b_JetEMEB_->GetEntry(entry_);
    c_JetEMEB_ = true;
  }
  return JetEMEB_;
}

std::vector<double>  & hcal_tree::JetEMEE(){
  if(read_only_ && !c_JetEMEE_ && b_JetEMEE_){
    b_JetEMEE_->GetEntry(entry_);
    c_JetEMEE_ = true;
  }
  return JetEMEE_;
}

std::vector<double>  & hcal_tree::JetEMFrac(){
  if(read_only_ && !c_JetEMFrac_ && b_JetEMFrac_){
    b_JetEMFrac_->GetEntry(entry_);
    c_JetEMFrac_ = true;
  }
  return JetEMFrac_;
}

std::vector<double>  & hcal_tree::JetEMHF(){
  if(read_only_ && !c_JetEMHF_ && b_JetEMHF_){
    b_JetEMHF_->GetEntry(entry_);
    c_JetEMHF_ = true;
  }
  return JetEMHF_;
}

std::vector<double>  & hcal_tree::JetEta(){
  if(read_only_ && !c_JetEta_ && b_JetEta_){
    b_JetEta_->GetEntry(entry_);
    c_JetEta_ = true;
  }
  return JetEta_;
}

std::vector<double>  & hcal_tree::JetHadFrac(){
  if(read_only_ && !c_JetHadFrac_ && b_JetHadFrac_){
    b_JetHadFrac_->GetEntry(entry_);
    c_JetHadFrac_ = true;
  }
  return JetHadFrac_;
}

std::vector<double>  & hcal_tree::JetHadHB(){
  if(read_only_ && !c_JetHadHB_ && b_JetHadHB_){
    b_JetHadHB_->GetEntry(entry_);
    c_JetHadHB_ = true;
  }
  return JetHadHB_;
}

std::vector<double>  & hcal_tree::JetHadHE(){
  if(read_only_ && !c_JetHadHE_ && b_JetHadHE_){
    b_JetHadHE_->GetEntry(entry_);
    c_JetHadHE_ = true;
  }
  return JetHadHE_;
}

std::vector<double>  & hcal_tree::JetHadHF(){
  if(read_only_ && !c_JetHadHF_ && b_JetHadHF_){
    b_JetHadHF_->GetEntry(entry_);
    c_JetHadHF_ = true;
  }
  return JetHadHF_;
}

std::vector<double>  & hcal_tree::JetPhi(){
  if(read_only_ && !c_JetPhi_ && b_JetPhi_){
    b_JetPhi_->GetEntry(entry_);
    c_JetPhi_ = true;
  }
  return JetPhi_;
}

std::vector<double>  & hcal_tree::JetPt(){
  if(read_only_ && !c_JetPt_ && b_JetPt_){
    b_JetPt_->GetEntry(entry_);
    c_JetPt_ = true;
  }
  return JetPt_;
}

std::vector<double>  & hcal_tree::MaxE2E10(){
  if(read_only_ && !c_MaxE2E10_ && b_MaxE2E10_){
    b_MaxE2E10_->GetEntry(entry_);
    c_MaxE2E10_ = true;
  }
  return MaxE2E10_;
}

std::vector<double>  & hcal_tree::MinE2E10(){
  if(read_only_ && !c_MinE2E10_ && b_MinE2E10_){
    b_MinE2E10_->GetEntry(entry_);
    c_MinE2E10_ = true;
  }
  return MinE2E10_;
}

std::vector<double>  & hcal_tree::MuonCalEnergyEm(){
  if(read_only_ && !c_MuonCalEnergyEm_ && b_MuonCalEnergyEm_){
    b_MuonCalEnergyEm_->GetEntry(entry_);
    c_MuonCalEnergyEm_ = true;
  }
  return MuonCalEnergyEm_;
}

std::vector<double>  & hcal_tree::MuonCalEnergyEmS25(){
  if(read_only_ && !c_MuonCalEnergyEmS25_ && b_MuonCalEnergyEmS25_){
    b_MuonCalEnergyEmS25_->GetEntry(entry_);
    c_MuonCalEnergyEmS25_ = true;
  }
  return MuonCalEnergyEmS25_;
}

std::vector<double>  & hcal_tree::MuonCalEnergyHad(){
  if(read_only_ && !c_MuonCalEnergyHad_ && b_MuonCalEnergyHad_){
    b_MuonCalEnergyHad_->GetEntry(entry_);
    c_MuonCalEnergyHad_ = true;
  }
  return MuonCalEnergyHad_;
}

std::vector<double>  & hcal_tree::MuonCalEnergyHadS9(){
  if(read_only_ && !c_MuonCalEnergyHadS9_ && b_MuonCalEnergyHadS9_){
    b_MuonCalEnergyHadS9_->GetEntry(entry_);
    c_MuonCalEnergyHadS9_ = true;
  }
  return MuonCalEnergyHadS9_;
}

std::vector<double>  & hcal_tree::MuonEta(){
  if(read_only_ && !c_MuonEta_ && b_MuonEta_){
    b_MuonEta_->GetEntry(entry_);
    c_MuonEta_ = true;
  }
  return MuonEta_;
}

std::vector<double>  & hcal_tree::MuonPhi(){
  if(read_only_ && !c_MuonPhi_ && b_MuonPhi_){
    b_MuonPhi_->GetEntry(entry_);
    c_MuonPhi_ = true;
  }
  return MuonPhi_;
}

std::vector<double>  & hcal_tree::MuonPt(){
  if(read_only_ && !c_MuonPt_ && b_MuonPt_){
    b_MuonPt_->GetEntry(entry_);
    c_MuonPt_ = true;
  }
  return MuonPt_;
}

std::vector<double>  & hcal_tree::NegativeNoiseSumE(){
  if(read_only_ && !c_NegativeNoiseSumE_ && b_NegativeNoiseSumE_){
    b_NegativeNoiseSumE_->GetEntry(entry_);
    c_NegativeNoiseSumE_ = true;
  }
  return NegativeNoiseSumE_;
}

std::vector<double>  & hcal_tree::NegativeNoiseSumEt(){
  if(read_only_ && !c_NegativeNoiseSumEt_ && b_NegativeNoiseSumEt_){
    b_NegativeNoiseSumEt_->GetEntry(entry_);
    c_NegativeNoiseSumEt_ = true;
  }
  return NegativeNoiseSumEt_;
}

std::vector<double>  & hcal_tree::NominalMET(){
  if(read_only_ && !c_NominalMET_ && b_NominalMET_){
    b_NominalMET_->GetEntry(entry_);
    c_NominalMET_ = true;
  }
  return NominalMET_;
}

std::vector<double>  & hcal_tree::RBXEnergy(){
  if(read_only_ && !c_RBXEnergy_ && b_RBXEnergy_){
    b_RBXEnergy_->GetEntry(entry_);
    c_RBXEnergy_ = true;
  }
  return RBXEnergy_;
}

std::vector<double>  & hcal_tree::RBXEnergy15(){
  if(read_only_ && !c_RBXEnergy15_ && b_RBXEnergy15_){
    b_RBXEnergy15_->GetEntry(entry_);
    c_RBXEnergy15_ = true;
  }
  return RBXEnergy15_;
}

std::vector<double>  & hcal_tree::SpikeNoiseSumE(){
  if(read_only_ && !c_SpikeNoiseSumE_ && b_SpikeNoiseSumE_){
    b_SpikeNoiseSumE_->GetEntry(entry_);
    c_SpikeNoiseSumE_ = true;
  }
  return SpikeNoiseSumE_;
}

std::vector<double>  & hcal_tree::SpikeNoiseSumEt(){
  if(read_only_ && !c_SpikeNoiseSumEt_ && b_SpikeNoiseSumEt_){
    b_SpikeNoiseSumEt_->GetEntry(entry_);
    c_SpikeNoiseSumEt_ = true;
  }
  return SpikeNoiseSumEt_;
}

std::vector<float>  & hcal_tree::HBHERecHitEnergy(){
  if(read_only_ && !c_HBHERecHitEnergy_ && b_HBHERecHitEnergy_){
    b_HBHERecHitEnergy_->GetEntry(entry_);
    c_HBHERecHitEnergy_ = true;
  }
  return HBHERecHitEnergy_;
}

std::vector<float>  & hcal_tree::HBHERecHitEta(){
  if(read_only_ && !c_HBHERecHitEta_ && b_HBHERecHitEta_){
    b_HBHERecHitEta_->GetEntry(entry_);
    c_HBHERecHitEta_ = true;
  }
  return HBHERecHitEta_;
}

std::vector<float>  & hcal_tree::HBHERecHitPhi(){
  if(read_only_ && !c_HBHERecHitPhi_ && b_HBHERecHitPhi_){
    b_HBHERecHitPhi_->GetEntry(entry_);
    c_HBHERecHitPhi_ = true;
  }
  return HBHERecHitPhi_;
}

std::vector<float>  & hcal_tree::HBHERecHitTime(){
  if(read_only_ && !c_HBHERecHitTime_ && b_HBHERecHitTime_){
    b_HBHERecHitTime_->GetEntry(entry_);
    c_HBHERecHitTime_ = true;
  }
  return HBHERecHitTime_;
}

std::vector<float>  & hcal_tree::HFRecHitEnergy(){
  if(read_only_ && !c_HFRecHitEnergy_ && b_HFRecHitEnergy_){
    b_HFRecHitEnergy_->GetEntry(entry_);
    c_HFRecHitEnergy_ = true;
  }
  return HFRecHitEnergy_;
}

std::vector<float>  & hcal_tree::HFRecHitEta(){
  if(read_only_ && !c_HFRecHitEta_ && b_HFRecHitEta_){
    b_HFRecHitEta_->GetEntry(entry_);
    c_HFRecHitEta_ = true;
  }
  return HFRecHitEta_;
}

std::vector<float>  & hcal_tree::HFRecHitPhi(){
  if(read_only_ && !c_HFRecHitPhi_ && b_HFRecHitPhi_){
    b_HFRecHitPhi_->GetEntry(entry_);
    c_HFRecHitPhi_ = true;
  }
  return HFRecHitPhi_;
}

std::vector<float>  & hcal_tree::HFRecHitTime(){
  if(read_only_ && !c_HFRecHitTime_ && b_HFRecHitTime_){
    b_HFRecHitTime_->GetEntry(entry_);
    c_HFRecHitTime_ = true;
  }
  return HFRecHitTime_;
}

std::vector<int>  & hcal_tree::HBHERecHitAux(){
  if(read_only_ && !c_HBHERecHitAux_ && b_HBHERecHitAux_){
    b_HBHERecHitAux_->GetEntry(entry_);
    c_HBHERecHitAux_ = true;
  }
  return HBHERecHitAux_;
}

std::vector<int>  & hcal_tree::HBHERecHitDepth(){
  if(read_only_ && !c_HBHERecHitDepth_ && b_HBHERecHitDepth_){
    b_HBHERecHitDepth_->GetEntry(entry_);
    c_HBHERecHitDepth_ = true;
  }
  return HBHERecHitDepth_;
}

std::vector<int>  & hcal_tree::HBHERecHitFlags(){
  if(read_only_ && !c_HBHERecHitFlags_ && b_HBHERecHitFlags_){
    b_HBHERecHitFlags_->GetEntry(entry_);
    c_HBHERecHitFlags_ = true;
  }
  return HBHERecHitFlags_;
}

std::vector<int>  & hcal_tree::HBHERecHitHPDid(){
  if(read_only_ && !c_HBHERecHitHPDid_ && b_HBHERecHitHPDid_){
    b_HBHERecHitHPDid_->GetEntry(entry_);
    c_HBHERecHitHPDid_ = true;
  }
  return HBHERecHitHPDid_;
}

std::vector<int>  & hcal_tree::HBHERecHitIEta(){
  if(read_only_ && !c_HBHERecHitIEta_ && b_HBHERecHitIEta_){
    b_HBHERecHitIEta_->GetEntry(entry_);
    c_HBHERecHitIEta_ = true;
  }
  return HBHERecHitIEta_;
}

std::vector<int>  & hcal_tree::HBHERecHitIPhi(){
  if(read_only_ && !c_HBHERecHitIPhi_ && b_HBHERecHitIPhi_){
    b_HBHERecHitIPhi_->GetEntry(entry_);
    c_HBHERecHitIPhi_ = true;
  }
  return HBHERecHitIPhi_;
}

std::vector<int>  & hcal_tree::HBHERecHitRBXid(){
  if(read_only_ && !c_HBHERecHitRBXid_ && b_HBHERecHitRBXid_){
    b_HBHERecHitRBXid_->GetEntry(entry_);
    c_HBHERecHitRBXid_ = true;
  }
  return HBHERecHitRBXid_;
}

std::vector<int>  & hcal_tree::HFRecHitAux(){
  if(read_only_ && !c_HFRecHitAux_ && b_HFRecHitAux_){
    b_HFRecHitAux_->GetEntry(entry_);
    c_HFRecHitAux_ = true;
  }
  return HFRecHitAux_;
}

std::vector<int>  & hcal_tree::HFRecHitDepth(){
  if(read_only_ && !c_HFRecHitDepth_ && b_HFRecHitDepth_){
    b_HFRecHitDepth_->GetEntry(entry_);
    c_HFRecHitDepth_ = true;
  }
  return HFRecHitDepth_;
}

std::vector<int>  & hcal_tree::HFRecHitFlags(){
  if(read_only_ && !c_HFRecHitFlags_ && b_HFRecHitFlags_){
    b_HFRecHitFlags_->GetEntry(entry_);
    c_HFRecHitFlags_ = true;
  }
  return HFRecHitFlags_;
}

std::vector<int>  & hcal_tree::HFRecHitHPDid(){
  if(read_only_ && !c_HFRecHitHPDid_ && b_HFRecHitHPDid_){
    b_HFRecHitHPDid_->GetEntry(entry_);
    c_HFRecHitHPDid_ = true;
  }
  return HFRecHitHPDid_;
}

std::vector<int>  & hcal_tree::HFRecHitIEta(){
  if(read_only_ && !c_HFRecHitIEta_ && b_HFRecHitIEta_){
    b_HFRecHitIEta_->GetEntry(entry_);
    c_HFRecHitIEta_ = true;
  }
  return HFRecHitIEta_;
}

std::vector<int>  & hcal_tree::HFRecHitIPhi(){
  if(read_only_ && !c_HFRecHitIPhi_ && b_HFRecHitIPhi_){
    b_HFRecHitIPhi_->GetEntry(entry_);
    c_HFRecHitIPhi_ = true;
  }
  return HFRecHitIPhi_;
}

std::vector<int>  & hcal_tree::HFRecHitRBXid(){
  if(read_only_ && !c_HFRecHitRBXid_ && b_HFRecHitRBXid_){
    b_HFRecHitRBXid_->GetEntry(entry_);
    c_HFRecHitRBXid_ = true;
  }
  return HFRecHitRBXid_;
}

std::vector<int>  & hcal_tree::HLTBits(){
  if(read_only_ && !c_HLTBits_ && b_HLTBits_){
    b_HLTBits_->GetEntry(entry_);
    c_HLTBits_ = true;
  }
  return HLTBits_;
}

std::vector<int>  & hcal_tree::HLTInsideDatasetTriggerPrescales(){
  if(read_only_ && !c_HLTInsideDatasetTriggerPrescales_ && b_HLTInsideDatasetTriggerPrescales_){
    b_HLTInsideDatasetTriggerPrescales_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerPrescales_ = true;
  }
  return HLTInsideDatasetTriggerPrescales_;
}

std::vector<int>  & hcal_tree::HLTOutsideDatasetTriggerPrescales(){
  if(read_only_ && !c_HLTOutsideDatasetTriggerPrescales_ && b_HLTOutsideDatasetTriggerPrescales_){
    b_HLTOutsideDatasetTriggerPrescales_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerPrescales_ = true;
  }
  return HLTOutsideDatasetTriggerPrescales_;
}

std::vector<int>  & hcal_tree::HPDHits(){
  if(read_only_ && !c_HPDHits_ && b_HPDHits_){
    b_HPDHits_->GetEntry(entry_);
    c_HPDHits_ = true;
  }
  return HPDHits_;
}

std::vector<int>  & hcal_tree::HPDNoOtherHits(){
  if(read_only_ && !c_HPDNoOtherHits_ && b_HPDNoOtherHits_){
    b_HPDNoOtherHits_->GetEntry(entry_);
    c_HPDNoOtherHits_ = true;
  }
  return HPDNoOtherHits_;
}

std::vector<int>  & hcal_tree::HasBadRBXR45(){
  if(read_only_ && !c_HasBadRBXR45_ && b_HasBadRBXR45_){
    b_HasBadRBXR45_->GetEntry(entry_);
    c_HasBadRBXR45_ = true;
  }
  return HasBadRBXR45_;
}

std::vector<int>  & hcal_tree::HasBadRBXRechitR45Loose(){
  if(read_only_ && !c_HasBadRBXRechitR45Loose_ && b_HasBadRBXRechitR45Loose_){
    b_HasBadRBXRechitR45Loose_->GetEntry(entry_);
    c_HasBadRBXRechitR45Loose_ = true;
  }
  return HasBadRBXRechitR45Loose_;
}

std::vector<int>  & hcal_tree::HasBadRBXRechitR45Tight(){
  if(read_only_ && !c_HasBadRBXRechitR45Tight_ && b_HasBadRBXRechitR45Tight_){
    b_HasBadRBXRechitR45Tight_->GetEntry(entry_);
    c_HasBadRBXRechitR45Tight_ = true;
  }
  return HasBadRBXRechitR45Tight_;
}

std::vector<int>  & hcal_tree::IsoNoiseFilterDecision(){
  if(read_only_ && !c_IsoNoiseFilterDecision_ && b_IsoNoiseFilterDecision_){
    b_IsoNoiseFilterDecision_->GetEntry(entry_);
    c_IsoNoiseFilterDecision_ = true;
  }
  return IsoNoiseFilterDecision_;
}

std::vector<int>  & hcal_tree::JetN60(){
  if(read_only_ && !c_JetN60_ && b_JetN60_){
    b_JetN60_->GetEntry(entry_);
    c_JetN60_ = true;
  }
  return JetN60_;
}

std::vector<int>  & hcal_tree::JetN90(){
  if(read_only_ && !c_JetN90_ && b_JetN90_){
    b_JetN90_->GetEntry(entry_);
    c_JetN90_ = true;
  }
  return JetN90_;
}

std::vector<int>  & hcal_tree::MaxZeros(){
  if(read_only_ && !c_MaxZeros_ && b_MaxZeros_){
    b_MaxZeros_->GetEntry(entry_);
    c_MaxZeros_ = true;
  }
  return MaxZeros_;
}

std::vector<int>  & hcal_tree::MuonCSC2DRecHitsSize(){
  if(read_only_ && !c_MuonCSC2DRecHitsSize_ && b_MuonCSC2DRecHitsSize_){
    b_MuonCSC2DRecHitsSize_->GetEntry(entry_);
    c_MuonCSC2DRecHitsSize_ = true;
  }
  return MuonCSC2DRecHitsSize_;
}

std::vector<int>  & hcal_tree::MuonCSCSegmentsSize(){
  if(read_only_ && !c_MuonCSCSegmentsSize_ && b_MuonCSCSegmentsSize_){
    b_MuonCSCSegmentsSize_->GetEntry(entry_);
    c_MuonCSCSegmentsSize_ = true;
  }
  return MuonCSCSegmentsSize_;
}

std::vector<int>  & hcal_tree::MuonDT1DCosmicRecHitsSize(){
  if(read_only_ && !c_MuonDT1DCosmicRecHitsSize_ && b_MuonDT1DCosmicRecHitsSize_){
    b_MuonDT1DCosmicRecHitsSize_->GetEntry(entry_);
    c_MuonDT1DCosmicRecHitsSize_ = true;
  }
  return MuonDT1DCosmicRecHitsSize_;
}

std::vector<int>  & hcal_tree::MuonDT1DRecHitsSize(){
  if(read_only_ && !c_MuonDT1DRecHitsSize_ && b_MuonDT1DRecHitsSize_){
    b_MuonDT1DRecHitsSize_->GetEntry(entry_);
    c_MuonDT1DRecHitsSize_ = true;
  }
  return MuonDT1DRecHitsSize_;
}

std::vector<int>  & hcal_tree::MuonDTRecCosmicSegmentsSize(){
  if(read_only_ && !c_MuonDTRecCosmicSegmentsSize_ && b_MuonDTRecCosmicSegmentsSize_){
    b_MuonDTRecCosmicSegmentsSize_->GetEntry(entry_);
    c_MuonDTRecCosmicSegmentsSize_ = true;
  }
  return MuonDTRecCosmicSegmentsSize_;
}

std::vector<int>  & hcal_tree::MuonDTRecSegmentsSize(){
  if(read_only_ && !c_MuonDTRecSegmentsSize_ && b_MuonDTRecSegmentsSize_){
    b_MuonDTRecSegmentsSize_->GetEntry(entry_);
    c_MuonDTRecSegmentsSize_ = true;
  }
  return MuonDTRecSegmentsSize_;
}

std::vector<int>  & hcal_tree::MuonNumberOfChambers(){
  if(read_only_ && !c_MuonNumberOfChambers_ && b_MuonNumberOfChambers_){
    b_MuonNumberOfChambers_->GetEntry(entry_);
    c_MuonNumberOfChambers_ = true;
  }
  return MuonNumberOfChambers_;
}

std::vector<int>  & hcal_tree::MuonNumberOfMatchedRPCLayers(){
  if(read_only_ && !c_MuonNumberOfMatchedRPCLayers_ && b_MuonNumberOfMatchedRPCLayers_){
    b_MuonNumberOfMatchedRPCLayers_->GetEntry(entry_);
    c_MuonNumberOfMatchedRPCLayers_ = true;
  }
  return MuonNumberOfMatchedRPCLayers_;
}

std::vector<int>  & hcal_tree::MuonNumberOfMatchedStations(){
  if(read_only_ && !c_MuonNumberOfMatchedStations_ && b_MuonNumberOfMatchedStations_){
    b_MuonNumberOfMatchedStations_->GetEntry(entry_);
    c_MuonNumberOfMatchedStations_ = true;
  }
  return MuonNumberOfMatchedStations_;
}

std::vector<int>  & hcal_tree::MuonRPCRecHitsSize(){
  if(read_only_ && !c_MuonRPCRecHitsSize_ && b_MuonRPCRecHitsSize_){
    b_MuonRPCRecHitsSize_->GetEntry(entry_);
    c_MuonRPCRecHitsSize_ = true;
  }
  return MuonRPCRecHitsSize_;
}

std::vector<int>  & hcal_tree::NumIsolatedNoiseChannels(){
  if(read_only_ && !c_NumIsolatedNoiseChannels_ && b_NumIsolatedNoiseChannels_){
    b_NumIsolatedNoiseChannels_->GetEntry(entry_);
    c_NumIsolatedNoiseChannels_ = true;
  }
  return NumIsolatedNoiseChannels_;
}

std::vector<int>  & hcal_tree::NumNegativeNoiseChannels(){
  if(read_only_ && !c_NumNegativeNoiseChannels_ && b_NumNegativeNoiseChannels_){
    b_NumNegativeNoiseChannels_->GetEntry(entry_);
    c_NumNegativeNoiseChannels_ = true;
  }
  return NumNegativeNoiseChannels_;
}

std::vector<int>  & hcal_tree::NumSpikeNoiseChannels(){
  if(read_only_ && !c_NumSpikeNoiseChannels_ && b_NumSpikeNoiseChannels_){
    b_NumSpikeNoiseChannels_->GetEntry(entry_);
    c_NumSpikeNoiseChannels_ = true;
  }
  return NumSpikeNoiseChannels_;
}

std::vector<int>  & hcal_tree::OfficialDecision(){
  if(read_only_ && !c_OfficialDecision_ && b_OfficialDecision_){
    b_OfficialDecision_->GetEntry(entry_);
    c_OfficialDecision_ = true;
  }
  return OfficialDecision_;
}

std::vector<int>  & hcal_tree::OfficialDecisionRun1(){
  if(read_only_ && !c_OfficialDecisionRun1_ && b_OfficialDecisionRun1_){
    b_OfficialDecisionRun1_->GetEntry(entry_);
    c_OfficialDecisionRun1_ = true;
  }
  return OfficialDecisionRun1_;
}

std::vector<int>  & hcal_tree::OfficialDecisionRun2L(){
  if(read_only_ && !c_OfficialDecisionRun2L_ && b_OfficialDecisionRun2L_){
    b_OfficialDecisionRun2L_->GetEntry(entry_);
    c_OfficialDecisionRun2L_ = true;
  }
  return OfficialDecisionRun2L_;
}

std::vector<int>  & hcal_tree::OfficialDecisionRun2T(){
  if(read_only_ && !c_OfficialDecisionRun2T_ && b_OfficialDecisionRun2T_){
    b_OfficialDecisionRun2T_->GetEntry(entry_);
    c_OfficialDecisionRun2T_ = true;
  }
  return OfficialDecisionRun2T_;
}

std::vector<std::string>  & hcal_tree::HLTInsideDatasetTriggerNames(){
  if(read_only_ && !c_HLTInsideDatasetTriggerNames_ && b_HLTInsideDatasetTriggerNames_){
    b_HLTInsideDatasetTriggerNames_->GetEntry(entry_);
    c_HLTInsideDatasetTriggerNames_ = true;
  }
  return HLTInsideDatasetTriggerNames_;
}

std::vector<std::string>  & hcal_tree::HLTOutsideDatasetTriggerNames(){
  if(read_only_ && !c_HLTOutsideDatasetTriggerNames_ && b_HLTOutsideDatasetTriggerNames_){
    b_HLTOutsideDatasetTriggerNames_->GetEntry(entry_);
    c_HLTOutsideDatasetTriggerNames_ = true;
  }
  return HLTOutsideDatasetTriggerNames_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxAllfC(){
  if(read_only_ && !c_HBHERecHitAuxAllfC_ && b_HBHERecHitAuxAllfC_){
    b_HBHERecHitAuxAllfC_->GetEntry(entry_);
    c_HBHERecHitAuxAllfC_ = true;
  }
  return HBHERecHitAuxAllfC_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxEnergy(){
  if(read_only_ && !c_HBHERecHitAuxEnergy_ && b_HBHERecHitAuxEnergy_){
    b_HBHERecHitAuxEnergy_->GetEntry(entry_);
    c_HBHERecHitAuxEnergy_ = true;
  }
  return HBHERecHitAuxEnergy_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxFC(){
  if(read_only_ && !c_HBHERecHitAuxFC_ && b_HBHERecHitAuxFC_){
    b_HBHERecHitAuxFC_->GetEntry(entry_);
    c_HBHERecHitAuxFC_ = true;
  }
  return HBHERecHitAuxFC_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxGain(){
  if(read_only_ && !c_HBHERecHitAuxGain_ && b_HBHERecHitAuxGain_){
    b_HBHERecHitAuxGain_->GetEntry(entry_);
    c_HBHERecHitAuxGain_ = true;
  }
  return HBHERecHitAuxGain_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxPedFC(){
  if(read_only_ && !c_HBHERecHitAuxPedFC_ && b_HBHERecHitAuxPedFC_){
    b_HBHERecHitAuxPedFC_->GetEntry(entry_);
    c_HBHERecHitAuxPedFC_ = true;
  }
  return HBHERecHitAuxPedFC_;
}

std::vector<std::vector<double> >  & hcal_tree::HBHERecHitAuxRCGain(){
  if(read_only_ && !c_HBHERecHitAuxRCGain_ && b_HBHERecHitAuxRCGain_){
    b_HBHERecHitAuxRCGain_->GetEntry(entry_);
    c_HBHERecHitAuxRCGain_ = true;
  }
  return HBHERecHitAuxRCGain_;
}

std::vector<std::vector<double> >  & hcal_tree::RBXCharge(){
  if(read_only_ && !c_RBXCharge_ && b_RBXCharge_){
    b_RBXCharge_->GetEntry(entry_);
    c_RBXCharge_ = true;
  }
  return RBXCharge_;
}

std::vector<std::vector<double> >  & hcal_tree::RBXCharge15(){
  if(read_only_ && !c_RBXCharge15_ && b_RBXCharge15_){
    b_RBXCharge15_->GetEntry(entry_);
    c_RBXCharge15_ = true;
  }
  return RBXCharge15_;
}

std::vector<std::vector<int> >  & hcal_tree::HBHERecHitAuxADC(){
  if(read_only_ && !c_HBHERecHitAuxADC_ && b_HBHERecHitAuxADC_){
    b_HBHERecHitAuxADC_->GetEntry(entry_);
    c_HBHERecHitAuxADC_ = true;
  }
  return HBHERecHitAuxADC_;
}

std::vector<std::vector<int> >  & hcal_tree::HBHERecHitAuxCapID(){
  if(read_only_ && !c_HBHERecHitAuxCapID_ && b_HBHERecHitAuxCapID_){
    b_HBHERecHitAuxCapID_->GetEntry(entry_);
    c_HBHERecHitAuxCapID_ = true;
  }
  return HBHERecHitAuxCapID_;
}

std::vector<std::vector<int> >  & hcal_tree::L1PhysBits(){
  if(read_only_ && !c_L1PhysBits_ && b_L1PhysBits_){
    b_L1PhysBits_->GetEntry(entry_);
    c_L1PhysBits_ = true;
  }
  return L1PhysBits_;
}

std::vector<std::vector<int> >  & hcal_tree::L1TechBits(){
  if(read_only_ && !c_L1TechBits_ && b_L1TechBits_){
    b_L1TechBits_->GetEntry(entry_);
    c_L1TechBits_ = true;
  }
  return L1TechBits_;
}

#include "hcal_tree_noise.hpp"
hcal_tree* NewTree(const std::type_info &type){

  if(type == typeid(hcal_tree)) return new hcal_tree;
  else if(type == typeid(hcal_tree_noise)) return static_cast<hcal_tree*>(new hcal_tree_noise);
  else return new hcal_tree;
}

