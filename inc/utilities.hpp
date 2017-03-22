#include <iostream>

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

