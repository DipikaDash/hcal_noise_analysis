// hcal_tree_noise: noise version of hcal_tree to handle reduce tree ntuples
// File generated with generate_hcal_tree.exe

#ifndef H_hcal_tree_NOISE
#define H_hcal_tree_NOISE

#include <vector>
#include <string>

#include "TTree.h"
#include "TChain.h"

#include "hcal_tree.hpp"

class hcal_tree_noise : public hcal_tree{
public:
  hcal_tree_noise(); // Constructor to create tree
  hcal_tree_noise(const std::string &filename); // Constructor to read tree

  virtual void GetEntry(const long entry);

  virtual void Fill();

  virtual std::string Type() const;

  virtual ~hcal_tree_noise();


private:
};

#endif
