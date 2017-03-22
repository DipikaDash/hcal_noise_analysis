// hcal_tree_noise: noise version of hcal_tree to handle reduce tree ntuples
//File generated with generate_hcal_tree.exe

#include "hcal_tree.hpp"

#include "hcal_tree_noise.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "TTree.h"
#include "TBranch.h"
#include "TChain.h"

using namespace std;

hcal_tree_noise::hcal_tree_noise():
  hcal_tree(){
}

hcal_tree_noise::hcal_tree_noise(const string &filename):
  hcal_tree(filename){
}

void hcal_tree_noise::Fill(){
  hcal_tree::Fill();
  //Resetting variables
}

string hcal_tree_noise::Type() const{
  return "noise";
}

hcal_tree_noise::~hcal_tree_noise(){
}

void hcal_tree_noise::GetEntry(const long entry){
  hcal_tree::GetEntry(entry);

}

