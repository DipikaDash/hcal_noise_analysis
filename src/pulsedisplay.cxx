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
#include "TAxis.h"

#include "utilities.hpp"

using namespace std;

bool printHit(int run, int ls, int evt, int ieta, int iphi, int depth, bool isData=true)
{
  bool printPulses = false;
  // 
  // data
  // 
  if(isData)
  { /*
    //R = 0.7-0.9 or 1.3-1.6 
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
    // good ones 
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
    // HB R<0.9 || R>1.2 
    if (run==316944 && ls==2 && evt==103418 && ieta==9 && iphi==37 && depth==1) printPulses=true;
    if (run==316944 && ls==2 && evt==92016 && ieta==-8 && iphi==49 && depth==1) printPulses=true;
    if (run==316944 && ls==2 && evt==92016 && ieta==-9 && iphi==49 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==195419 && ieta==3 && iphi==18 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==1 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==2 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==4 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==8 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==9 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==11 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==5 && evt==256407 && ieta==6 && iphi==70 && depth==1) printPulses=true;
    if (run==316944 && ls==7 && evt==368266 && ieta==2 && iphi==55 && depth==1) printPulses=true;
    if (run==316944 && ls==7 && evt==351062 && ieta==8 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==7 && evt==351062 && ieta==9 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==523406 && ieta==5 && iphi==36 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==523406 && ieta==6 && iphi==36 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==549303 && ieta==-10 && iphi==63 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==549303 && ieta==-11 && iphi==63 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==549303 && ieta==-15 && iphi==63 && depth==2) printPulses=true;
    if (run==316944 && ls==11 && evt==612006 && ieta==-1 && iphi==65 && depth==1) printPulses=true;
    if (run==316944 && ls==11 && evt==612006 && ieta==-3 && iphi==65 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==5 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==9 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==16 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==14 && evt==759443 && ieta==8 && iphi==18 && depth==1) printPulses=true;
    if (run==316944 && ls==14 && evt==759443 && ieta==9 && iphi==18 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1186124 && ieta==-2 && iphi==23 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1193632 && ieta==8 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1193632 && ieta==9 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1155766 && ieta==-6 && iphi==29 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1155766 && ieta==-7 && iphi==29 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1155766 && ieta==-10 && iphi==29 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==2423004 && ieta==8 && iphi==53 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==2423004 && ieta==9 && iphi==53 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==1290606 && ieta==-14 && iphi==65 && depth==1) printPulses=true;
    // if( e_1.at(i)>10 && (e_2.at(i)/e_1.at(i)>0.6 && e_2.at(i)/e_1.at(i)<0.9) ) 
    if (run==316944 && ls==7 && evt==368266 && ieta==-16 && iphi==55 && depth==4) printPulses=true;
    if (run==316944 && ls==20 && evt==1213760 && ieta==-28 && iphi==59 && depth==5) printPulses=true;
    if (run==316944 && ls==20 && evt==1274224 && ieta==25 && iphi==53 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1274224 && ieta==25 && iphi==59 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1244265 && ieta==27 && iphi==35 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1252798 && ieta==-29 && iphi==11 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1252798 && ieta==-28 && iphi==7 && depth==6) printPulses=true;
    if (run==316944 && ls==20 && evt==1179792 && ieta==-29 && iphi==15 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1192868 && ieta==24 && iphi==23 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1270826 && ieta==25 && iphi==27 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1268876 && ieta==-26 && iphi==45 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1192270 && ieta==-25 && iphi==53 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1192270 && ieta==25 && iphi==61 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1205180 && ieta==-20 && iphi==68 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1254042 && ieta==28 && iphi==57 && depth==6) printPulses=true;
    if (run==316944 && ls==20 && evt==1281188 && ieta==29 && iphi==43 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1190573 && ieta==25 && iphi==71 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1196906 && ieta==-29 && iphi==69 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1228051 && ieta==24 && iphi==33 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1183221 && ieta==-27 && iphi==27 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1182112 && ieta==28 && iphi==11 && depth==7) printPulses=true;
    if (run==316944 && ls==20 && evt==1201112 && ieta==28 && iphi==61 && depth==6) printPulses=true;
    if (run==316944 && ls==20 && evt==1223870 && ieta==-28 && iphi==61 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1206580 && ieta==-24 && iphi==3 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1189933 && ieta==21 && iphi==47 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1189933 && ieta==29 && iphi==69 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1200301 && ieta==24 && iphi==1 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1281918 && ieta==20 && iphi==54 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1256570 && ieta==-28 && iphi==47 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1267650 && ieta==-26 && iphi==51 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1222725 && ieta==-24 && iphi==31 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1222725 && ieta==-28 && iphi==25 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1231938 && ieta==-29 && iphi==57 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1265653 && ieta==-24 && iphi==35 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1265653 && ieta==25 && iphi==21 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1273718 && ieta==-24 && iphi==51 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1221540 && ieta==-24 && iphi==33 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1217506 && ieta==-24 && iphi==9 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1242855 && ieta==28 && iphi==15 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1282030 && ieta==28 && iphi==59 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1249200 && ieta==-25 && iphi==11 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1249200 && ieta==-26 && iphi==11 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1249200 && ieta==-24 && iphi==13 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1189348 && ieta==-26 && iphi==19 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1246369 && ieta==29 && iphi==65 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1197576 && ieta==-28 && iphi==13 && depth==4) printPulses=true;
    if (run==316944 && ls==20 && evt==1244229 && ieta==29 && iphi==65 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1241894 && ieta==27 && iphi==3 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1271842 && ieta==22 && iphi==11 && depth==3) printPulses=true;
    // HE 3p1b vs 6p1b, R>1.2, E>20
    if (run==316944 && ls==20 && evt==1227403 && ieta==-28 && iphi==51 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1227403 && ieta==-28 && iphi==53 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1230528 && ieta==-28 && iphi==55 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1239136 && ieta==-28 && iphi==65 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1265619 && ieta==28 && iphi==25 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1271308 && ieta==-24 && iphi==63 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1242855 && ieta==28 && iphi==7 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1197576 && ieta==-29 && iphi==15 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1197576 && ieta==-29 && iphi==15 && depth==3) printPulses=true;
    if (run==316944 && ls==20 && evt==1241894 && ieta==-22 && iphi==43 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1246187 && ieta==28 && iphi==69 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1246187 && ieta==28 && iphi==67 && depth==3) printPulses=true;
    if (run==316944 && ls==21 && evt==1554451 && ieta==29 && iphi==23 && depth==2) printPulses=true;
    if (run==316944 && ls==21 && evt==2253040 && ieta==-28 && iphi==55 && depth==2) printPulses=true;
    if (run==316944 && ls==21 && evt==2253040 && ieta==-29 && iphi==55 && depth==3) printPulses=true;
    */
    //  $ ./run/mahi_baseline.exe 8p1b 8p1b_ped0p5gev
    /*
    if (run==316944 && ls==2 && evt==92016 && ieta==-8 && iphi==49 && depth==1) printPulses=true;
    if (run==316944 && ls==2 && evt==92016 && ieta==-9 && iphi==49 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==1 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==5 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==7 && evt==368266 && ieta==2 && iphi==55 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==523406 && ieta==3 && iphi==36 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==8 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==16 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==17 && evt==990618 && ieta==6 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==18 && evt==1037289 && ieta==-7 && iphi==36 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1193632 && ieta==9 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1265619 && ieta==28 && iphi==25 && depth==2) printPulses=true;
    if (run==316944 && ls==20 && evt==1212195 && ieta==-2 && iphi==60 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1155766 && ieta==-7 && iphi==29 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1155766 && ieta==-10 && iphi==29 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==1617238 && ieta==28 && iphi==3 && depth==5) printPulses=true;
    if (run==316944 && ls==21 && evt==1484904 && ieta==-8 && iphi==23 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==2253040 && ieta==-28 && iphi==55 && depth==2) printPulses=true;
    // ./run/mahi_baseline.exe 8p1b 8p1b_nonneg
    if (run==316944 && ls==4 && evt==184975 && ieta==3 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==4 && evt==184975 && ieta==6 && iphi==50 && depth==1) printPulses=true;
    if (run==316944 && ls==5 && evt==256407 && ieta==6 && iphi==70 && depth==1) printPulses=true;
    if (run==316944 && ls==7 && evt==368266 && ieta==2 && iphi==55 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==523406 && ieta==3 && iphi==36 && depth==1) printPulses=true;
    if (run==316944 && ls==10 && evt==549303 && ieta==-14 && iphi==63 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==9 && iphi==61 && depth==1) printPulses=true;
    if (run==316944 && ls==12 && evt==671611 && ieta==15 && iphi==61 && depth==2) printPulses=true;
    if (run==316944 && ls==13 && evt==747340 && ieta==-10 && iphi==22 && depth==1) printPulses=true;
    if (run==316944 && ls==14 && evt==765889 && ieta==-7 && iphi==68 && depth==1) printPulses=true;
    if (run==316944 && ls==14 && evt==765889 && ieta==11 && iphi==68 && depth==1) printPulses=true;
    if (run==316944 && ls==17 && evt==990618 && ieta==-3 && iphi==8 && depth==1) printPulses=true;
    if (run==316944 && ls==20 && evt==1256570 && ieta==9 && iphi==13 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==2432478 && ieta==-8 && iphi==13 && depth==1) printPulses=true;
    if (run==316944 && ls==21 && evt==2243817 && ieta==-14 && iphi==61 && depth==1) printPulses=true;
    */
    // test 
    // if (run==316944 && ls==4 && evt==184975 && ieta==2 && iphi==50 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22190988 && ieta==-1 && iphi==14 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22190988 && ieta==-6 && iphi==31 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-1 && iphi==27 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-1 && iphi==53 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-1 && iphi==62 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-1 && iphi==71 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-2 && iphi==54 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-2 && iphi==62 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-4 && iphi==46 && depth==1) printPulses=true;
    if(run==325308 && ls ==45 && evt==22330793 && ieta==-4 && iphi==61 && depth==1) printPulses=true;

  }
  //
  // MC
  

  else 
  { // HE pT>30, R = 0.6 - 0.9
    /*
    if (run==1 && ls==2646 && evt==2645002 && ieta==29 && iphi==59 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645005 && ieta==-23 && iphi==17 && depth==5) printPulses=true;
    if (run==1 && ls==2646 && evt==2645013 && ieta==-26 && iphi==25 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645016 && ieta==27 && iphi==63 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645037 && ieta==28 && iphi==61 && depth==5) printPulses=true;
    if (run==1 && ls==2646 && evt==2645045 && ieta==25 && iphi==17 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645045 && ieta==26 && iphi==17 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645048 && ieta==27 && iphi==49 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645057 && ieta==-27 && iphi==49 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645057 && ieta==-27 && iphi==49 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645060 && ieta==19 && iphi==43 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645065 && ieta==-26 && iphi==15 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645059 && ieta==21 && iphi==5 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645093 && ieta==25 && iphi==13 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645095 && ieta==26 && iphi==71 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645085 && ieta==-17 && iphi==60 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645111 && ieta==-27 && iphi==55 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645130 && ieta==26 && iphi==27 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645140 && ieta==-23 && iphi==25 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645138 && ieta==24 && iphi==61 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645166 && ieta==29 && iphi==33 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645207 && ieta==25 && iphi==9 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645202 && ieta==29 && iphi==67 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645249 && ieta==-27 && iphi==63 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645249 && ieta==-28 && iphi==63 && depth==5) printPulses=true;
    if (run==1 && ls==2646 && evt==2645259 && ieta==-29 && iphi==23 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645255 && ieta==-18 && iphi==23 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645258 && ieta==-25 && iphi==67 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645258 && ieta==-25 && iphi==67 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645262 && ieta==-28 && iphi==1 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645263 && ieta==-28 && iphi==35 && depth==4) printPulses=true;
    if (run==1 && ls==2646 && evt==2645285 && ieta==-17 && iphi==49 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645301 && ieta==19 && iphi==39 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645317 && ieta==-29 && iphi==7 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645318 && ieta==-24 && iphi==51 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645318 && ieta==22 && iphi==15 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645318 && ieta==-24 && iphi==51 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645322 && ieta==-25 && iphi==51 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645346 && ieta==28 && iphi==17 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645359 && ieta==-17 && iphi==24 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645359 && ieta==-17 && iphi==24 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645367 && ieta==-25 && iphi==51 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645367 && ieta==-26 && iphi==51 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645385 && ieta==27 && iphi==17 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645398 && ieta==23 && iphi==3 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645404 && ieta==-27 && iphi==21 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645417 && ieta==-24 && iphi==57 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645415 && ieta==-17 && iphi==60 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645434 && ieta==-28 && iphi==45 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645434 && ieta==-29 && iphi==45 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645445 && ieta==-27 && iphi==21 && depth==4) printPulses=true;
    if (run==1 && ls==2646 && evt==2645448 && ieta==-23 && iphi==17 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645448 && ieta==-24 && iphi==19 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645444 && ieta==29 && iphi==1 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645444 && ieta==28 && iphi==71 && depth==6) printPulses=true;
    if (run==1 && ls==2646 && evt==2645461 && ieta==-29 && iphi==33 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645461 && ieta==-28 && iphi==33 && depth==4) printPulses=true;
    if (run==1 && ls==2646 && evt==2645460 && ieta==-18 && iphi==7 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645460 && ieta==-19 && iphi==7 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645460 && ieta==-19 && iphi==8 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645473 && ieta==24 && iphi==5 && depth==4) printPulses=true;
    if (run==1 && ls==2646 && evt==2645485 && ieta==26 && iphi==19 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645481 && ieta==28 && iphi==61 && depth==3) printPulses=true;
    if (run==1 && ls==2646 && evt==2645486 && ieta==-27 && iphi==5 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645490 && ieta==-25 && iphi==11 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645490 && ieta==-26 && iphi==11 && depth==2) printPulses=true;
    if (run==1 && ls==2646 && evt==2645490 && ieta==-25 && iphi==9 && depth==3) printPulses=true;
    */
    // HB pT>15 R<0.9 || R>1.1
    /*
    if (run==1 && ls==2646 && evt==2645107 && ieta==9 && iphi==17 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645126 && ieta==12 && iphi==47 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645132 && ieta==-5 && iphi==41 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645238 && ieta==-12 && iphi==56 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645263 && ieta==-3 && iphi==55 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645289 && ieta==-10 && iphi==51 && depth==1) printPulses=true;
    if (run==1 && ls==2646 && evt==2645370 && ieta==12 && iphi==35 && depth==1) printPulses=true;
    */
    // HE pT>10 R=0.2-0.3
    // if (run==1 && ls==2646 && evt==2645046 && ieta==-28 && iphi==43 && depth==1) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645050 && ieta==28 && iphi==7 && depth==4) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645058 && ieta==26 && iphi==11 && depth==1) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645060 && ieta==28 && iphi==43 && depth==6) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645064 && ieta==28 && iphi==67 && depth==5) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645073 && ieta==28 && iphi==13 && depth==1) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645109 && ieta==29 && iphi==15 && depth==2) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645102 && ieta==-28 && iphi==55 && depth==1) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645102 && ieta==28 && iphi==1 && depth==2) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645105 && ieta==27 && iphi==3 && depth==1) printPulses=true;
    // if (run==1 && ls==2646 && evt==2645105 && ieta==27 && iphi==71 && depth==1) printPulses=true;
     if (run==1 && ls==2646 && evt==2645118 && ieta==-28 && iphi==21 && depth==5) printPulses=true;
  }
  return printPulses;
}

TLegend* drawPulsePlot(TChain *ch, int printIndex, THStack* &st, TH1D* &h1_data, TString title, float &max) 
                  //int run, int ls, int evt, int ieta, int iphi, int depth, 
{ 
  float inputTS[10];
  float itPulse[10];
  float p1Pulse[10];
  float n1Pulse[10];
  float p2Pulse[10];
  float n2Pulse[10];
  float p3Pulse[10];
  float n3Pulse[10];
  float n4Pulse[10];
  float p1Energy=0;
  float n1Energy=0;
  float p2Energy=0;
  float n2Energy=0;
  float p3Energy=0;
  float n3Energy=0;
  float n4Energy=0;
  float mahiEnergy=0;
  float pedEnergy=0;
  float inGain=0;
  float chiSq=0;

  ch->SetBranchAddress("inputTS",    &inputTS);
  ch->SetBranchAddress("itPulse",    &itPulse);
  ch->SetBranchAddress("p1Pulse",    &p1Pulse);
  ch->SetBranchAddress("n1Pulse",    &n1Pulse);
  ch->SetBranchAddress("p2Pulse",    &p2Pulse);
  ch->SetBranchAddress("n2Pulse",    &n2Pulse);
  ch->SetBranchAddress("p3Pulse",    &p3Pulse);
  ch->SetBranchAddress("n3Pulse",    &n3Pulse);
  ch->SetBranchAddress("n4Pulse",    &n4Pulse);
  ch->SetBranchAddress("p1Energy",   &p1Energy);
  ch->SetBranchAddress("n1Energy",   &n1Energy);
  ch->SetBranchAddress("p2Energy",   &p2Energy);
  ch->SetBranchAddress("n2Energy",   &n2Energy);
  ch->SetBranchAddress("p3Energy",   &p3Energy);
  ch->SetBranchAddress("n3Energy",   &n3Energy);
  ch->SetBranchAddress("n4Energy",   &n4Energy);
  ch->SetBranchAddress("mahiEnergy", &mahiEnergy);
  ch->SetBranchAddress("pedEnergy",  &pedEnergy);
  ch->SetBranchAddress("inGain",     &inGain);
  ch->SetBranchAddress("chiSq",      &chiSq);
      
  TH1D *h1_it   = InitTH1D("h1_it",   "h1_it",   8, -0.5, 7.5); 
  TH1D *h1_p1   = InitTH1D("h1_p1",   "h1_p1",   8, -0.5, 7.5); 
  TH1D *h1_p2   = InitTH1D("h1_p2",   "h1_p2",   8, -0.5, 7.5); 
  TH1D *h1_p3   = InitTH1D("h1_p3",   "h1_p3",   8, -0.5, 7.5); 
  TH1D *h1_n1   = InitTH1D("h1_n1",   "h1_n1",   8, -0.5, 7.5); 
  TH1D *h1_n2   = InitTH1D("h1_n2",   "h1_n2",   8, -0.5, 7.5); 
  TH1D *h1_n3   = InitTH1D("h1_n3",   "h1_n3",   8, -0.5, 7.5); 
  TH1D *h1_n4   = InitTH1D("h1_n4",   "h1_n4",   8, -0.5, 7.5); 
  TH1D *h1_ped  = InitTH1D("h1_ped",  "h1_ped",  8, -0.5, 7.5); 
  TH1D *h1_all  = InitTH1D("h1_all",  "h1_all",  8, -0.5, 7.5); 

  ch->GetEntry(printIndex);

  title.ReplaceAll("E= GeV", Form("E= %.1f GeV", mahiEnergy*inGain)); 
  title.ReplaceAll("chi2=", Form("#chi^{2}= %.1f", chiSq)); 

  if(0)
  {
    cout << title << endl; 
    cout << p3Energy << endl; 
    cout << p2Energy << endl; 
    cout << p1Energy << endl; 
    cout << mahiEnergy << endl; 
    cout << n1Energy << endl; 
    cout << n2Energy << endl; 
    cout << n3Energy << endl; 
    cout << n4Energy << endl; 
    cout << pedEnergy << endl; 
  }
  

  for(int its=0; its<8; its++) 
  {
    if(p2Energy<0) p2Energy=0; 
    if(p3Energy<0) p3Energy=0; 
    if(n2Energy<0) n2Energy=0; 
    if(n3Energy<0) n3Energy=0; 
    if(n4Energy<0) n4Energy=0; 

    h1_data->SetBinContent(its+1, inputTS[its]*inGain);
    h1_it->SetBinContent(its+1, itPulse[its]*mahiEnergy*inGain);
    h1_p1->SetBinContent(its+1, p1Pulse[its]*p1Energy*inGain);
    h1_p2->SetBinContent(its+1, p2Pulse[its]*p2Energy*inGain);
    h1_p3->SetBinContent(its+1, p3Pulse[its]*p3Energy*inGain);
    h1_n1->SetBinContent(its+1, n1Pulse[its]*n1Energy*inGain);
    h1_n2->SetBinContent(its+1, n2Pulse[its]*n2Energy*inGain);
    h1_n3->SetBinContent(its+1, n3Pulse[its]*n3Energy*inGain);
    h1_n4->SetBinContent(its+1, n4Pulse[its]*n4Energy*inGain);
    h1_ped->SetBinContent(its+1, pedEnergy*inGain);
  } 
  
  //  
  if(mahiEnergy>0) h1_it->Scale(mahiEnergy*inGain/h1_it->Integral(1,8));
  if(p1Energy>0) h1_p1->Scale(p1Energy*inGain/h1_p1->Integral(1,8));
  if(p2Energy>0) h1_p2->Scale(p2Energy*inGain/h1_p2->Integral(1,8));
  if(p3Energy>0) h1_p3->Scale(p3Energy*inGain/h1_p3->Integral(1,8));
  if(n1Energy>0) h1_n1->Scale(n1Energy*inGain/h1_n1->Integral(1,8));
  if(n2Energy>0) h1_n2->Scale(n2Energy*inGain/h1_n2->Integral(1,8));
  if(n3Energy>0) h1_n3->Scale(n3Energy*inGain/h1_n3->Integral(1,8));
  if(n4Energy>0) h1_n4->Scale(n4Energy*inGain/h1_n4->Integral(1,8));

  // all 
  for(int its=0; its<8; its++)
  {
    float all = 0;
    all = h1_it->GetBinContent(its+1);  
    all += h1_p1->GetBinContent(its+1);
    all += h1_p2->GetBinContent(its+1);
    all += h1_p3->GetBinContent(its+1);
    all += h1_n1->GetBinContent(its+1);
    all += h1_n2->GetBinContent(its+1);
    all += h1_n3->GetBinContent(its+1);
    all += h1_n4->GetBinContent(its+1);
    all += h1_ped->GetBinContent(its+1);
    h1_all->SetBinContent(its+1, all); 
  }

  if(h1_all->GetMaximum()>max) max = h1_all->GetMaximum();

  h1_data->SetLineColor(kBlack); h1_data->SetMarkerColor(kBlack);
  h1_data->SetMarkerStyle(20);   h1_data->SetMarkerSize(1); 
  h1_it->SetLineColor(kBlack);   h1_it->SetFillColor(kYellow-10);
  h1_p1->SetLineColor(kBlack);   h1_p1->SetFillColor(kAzure+1);
  h1_p2->SetLineColor(kBlack);   h1_p2->SetFillColor(kAzure+6);
  h1_p3->SetLineColor(kBlack);   h1_p3->SetFillColor(kAzure);
  h1_n1->SetLineColor(kBlack);   h1_n1->SetFillColor(kPink+1);
  h1_n2->SetLineColor(kBlack);   h1_n2->SetFillColor(kPink+6);
  h1_n3->SetLineColor(kBlack);   h1_n3->SetFillColor(kPink);
  h1_n4->SetLineColor(kBlack);   h1_n4->SetFillColor(kPink-3);
  h1_ped->SetLineColor(kBlack);  h1_ped->SetFillColor(kGreen-10);
  h1_all->SetLineColor(kBlack);  h1_all->SetLineWidth(2);

  // legend 
  TLegend *l1 = new TLegend(0.15, 0.3, 0.25, 0.85);
  l1->SetNColumns(1);
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
  if(h1_ped->Integral(1,8)>0) l1->AddEntry(h1_ped, Form(" base (%.1f GeV)",h1_ped->Integral(1,8)), "f");
  if(h1_p3->Integral(1,8)>0) l1->AddEntry(h1_p3,   Form(" -3BX (%.1f GeV)",h1_p3->Integral(1,8)),  "f");
  if(h1_p2->Integral(1,8)>0) l1->AddEntry(h1_p2,   Form(" -2BX (%.1f GeV)",h1_p2->Integral(1,8)),  "f");
  if(h1_p1->Integral(1,8)>0) l1->AddEntry(h1_p1,   Form(" -1BX (%.1f GeV)",h1_p1->Integral(1,8)),  "f");
  if(h1_it->Integral(1,8)>0) l1->AddEntry(h1_it,   Form("  0BX (%.1f GeV)",h1_it->Integral(1,8)),  "f");
  if(h1_n1->Integral(1,8)>0) l1->AddEntry(h1_n1,   Form(" +1BX (%.1f GeV)",h1_n1->Integral(1,8)),  "f");
  if(h1_n2->Integral(1,8)>0) l1->AddEntry(h1_n2,   Form(" +2BX (%.1f GeV)",h1_n2->Integral(1,8)),  "f");
  if(h1_n3->Integral(1,8)>0) l1->AddEntry(h1_n3,   Form(" +3BX (%.1f GeV)",h1_n3->Integral(1,8)),  "f"); 
  if(h1_n4->Integral(1,8)>0) l1->AddEntry(h1_n4,   Form(" +4BX (%.1f GeV)",h1_n4->Integral(1,8)),  "f");

  if(h1_ped->Integral(1,8)>0) st->Add(h1_ped);
  if(h1_p3->Integral(1,8)>0) st->Add(h1_p3);
  if(h1_p2->Integral(1,8)>0) st->Add(h1_p2);
  if(h1_p1->Integral(1,8)>0) st->Add(h1_p1);
  if(h1_n1->Integral(1,8)>0) st->Add(h1_n1);
  if(h1_n2->Integral(1,8)>0) st->Add(h1_n2);
  if(h1_n3->Integral(1,8)>0) st->Add(h1_n3); 
  if(h1_n4->Integral(1,8)>0) st->Add(h1_n4); 
  if(h1_it->Integral(1,8)>0) st->Add(h1_it);
  st->SetTitle(title); 
  st->SetMaximum(h1_data->GetMaximum()*1.2); 
  //st->SetMinimum(h1_ped->GetMaximum()*0.5); 
  //st->GetXaxis()->SetLabelSize(0.);
  //st->GetYaxis()->SetLabelSize(0.);
  return l1;
}

int main()
{
    gErrorIgnoreLevel=kError+1;
    // TChain* ch_3p1b     = new TChain("mahiDebugger/HcalTree"); 
    //TChain* ch_3p1b_fix = new TChain("mahiDebugger/HcalTree"); 
    TChain* ch_8p       = new TChain("mahiDebugger/HcalTree"); 
    // TChain* ch_8p_fix   = new TChain("mahiDebugger/HcalTree"); 
    //  ch_3p1b->Add("/homes/jaehyeokyoo/HCAL/ntuples/mahidebugger_2018_3p1b_cov_notfix.root"); 
    // ch_3p1b_fix->Add("/homes/jaehyeokyoo/HCAL/ntuples/mahidebugger_2018_3p1b_cov_fix.root"); 
    ch_8p->Add("/eos/home-d/ddash//HCAL/MAHI/mahidebugger_8p_nonneg1.root");          //mahidebugger_1_8p.root");//mahidebugger_8p_nonneg1.root"); 
    // ch_8p_fix->Add("/homes/jaehyeokyoo/HCAL/ntuples/mahidebugger_2018_8p_cov_fix.root"); 
    
    int run;
    int ls;
    int evt;
    int ieta;
    int iphi;
    int depth;
    float mahiEnergy;
    float inGain;
    ch_8p->SetBranchAddress("run",        &run);
    ch_8p->SetBranchAddress("ls",         &ls);
    ch_8p->SetBranchAddress("evt",        &evt);
    ch_8p->SetBranchAddress("ieta",       &ieta);
    ch_8p->SetBranchAddress("iphi",       &iphi);
    ch_8p->SetBranchAddress("depth",      &depth);
    ch_8p->SetBranchAddress("mahiEnergy", &mahiEnergy);
    ch_8p->SetBranchAddress("inGain", &inGain);
    vector<int> vec_printIndex;
    vector<TString> vec_title;
    vector<float> vec_energy;

    int nentries = ch_8p->GetEntries();
    for(int i=0; i<nentries; i++)
    {
      ch_8p->GetEntry(i); 

      // if ((mahiEnergy * inGain) > 1 && (mahiEnergy * inGain) < 10 )
      //	{
           
      //  vec_energy.push_back(mahiEnergy * inGain);
      //	   if (vec_energy.size() >11) 
      //	   break;
	  // cout << "mahi" << mahiEnergy << "*" << "gain"<< inGain << endl;
      //	   cout << "run: "<< run << " ls: " << ls << " event: " << evt << " ieta: " << ieta << " iphi: "<< iphi << " depth: " << depth << endl;
      //		}
         if(printHit(run,ls,evt,ieta,iphi,depth))
       {

        vec_printIndex.push_back(i);
        vec_title.push_back(Form("run=%i ls=%i evt=%i (%i, %i, %i)",run, ls, evt, ieta, iphi, depth));
       }
    }

     for(unsigned int i=0; i<vec_printIndex.size(); i++) 
    //for(unsigned int i=0; i< 11; i++)
    {
      // cout << vec_energy.at(i) << endl;
      cout << vec_title.at(i).Data() << endl;

      // THStack *st_3p1b        = new THStack("st_3p1b",      Form("3p1b %s", vec_title.at(i).Data()));
      // THStack *st_3p1b_fix    = new THStack("st_3p1b_fix",  Form("3p1b fix %s", vec_title.at(i).Data()));
      THStack *st_8p          = new THStack("st_8p",        Form("8p   %s", vec_title.at(i).Data()));
      // THStack *st_8p_fix      = new THStack("st_8p_fix",    Form("8p fix   %s", vec_title.at(i).Data()));
      // TH1D *h1_3p1b_data    = InitTH1D("h1_3p1b_data",    "h1_3p1b_data",     8, -0.5, 7.5); 
      //TH1D *h1_3p1b_fix_data    = InitTH1D("h1_3p1b_fix_data",    "h1_3p1b_fix_data",     8, -0.5, 7.5); 
      TH1D *h1_8p_data      = InitTH1D("h1_8p_data",      "h1_8p_data",       8, -0.5, 7.5); 
      // TH1D *h1_8p_fix_data      = InitTH1D("h1_8p_fix_data",      "h1_8p_fix_data",       8, -0.5, 7.5); 

      float max=-1;
      //TLegend *leg_3p1b = drawPulsePlot(ch_3p1b, vec_printIndex.at(i), st_3p1b, h1_3p1b_data, 
      //                  Form("3 pulses + baseline:     %s, E= GeV, chi2=; TS; E [GeV]", vec_title.at(i).Data()), max);
      // TLegend *leg_3p1b_fix = drawPulsePlot(ch_3p1b_fix, vec_printIndex.at(i), st_3p1b_fix, h1_3p1b_fix_data, 
      //                    Form("3 pulses + baseline (cov fixes):     %s, E= GeV, chi2=; TS; E [GeV]", vec_title.at(i).Data()), max);
      TLegend *leg_8p   = drawPulsePlot(ch_8p,   vec_printIndex.at(i), st_8p,   h1_8p_data,   
					Form("8 pulses + no baseline:  E=%s GeV, chi2=; TS; E [GeV]", vec_title.at(i).Data()),max);
      //TLegend *leg_8p_fix = drawPulsePlot(ch_8p_fix, vec_printIndex.at(i), st_8p_fix, h1_8p_fix_data, 
      //                    Form("8 pulses + no baseline (cov fixes):     %s, E= GeV, chi2=; TS; E [GeV]", vec_title.at(i).Data()), max);
   
      if(h1_8p_data->GetMaximum()>max) max=h1_8p_data->GetMaximum();
 
      //
      TCanvas *c = new TCanvas("c","c",1600,1000); 
      // c->Divide(2,2); 
      //c->cd(1); 
      // st_3p1b->Draw("hist");
      // st_3p1b->SetMaximum(max*1.2);
      // h1_3p1b_data->Draw("p same");
      // leg_3p1b->Draw();
      // c->cd(2); 
      st_8p->Draw(); 
      st_8p->SetMaximum(max*1.2);
      h1_8p_data->Draw("p same");
      leg_8p->Draw();
      //c->cd(3); 
      //st_3p1b_fix->Draw("hist");
      //st_3p1b_fix->SetMaximum(max*1.2);
      //h1_3p1b_fix_data->Draw("p same");
      //leg_3p1b_fix->Draw();
      //c->cd(4); 
      //st_8p_fix->Draw(); 
      //st_8p_fix->SetMaximum(max*1.2);
      //h1_8p_fix_data->Draw("p same");
      //leg_8p_fix->Draw();
      c->Print(Form("plots/pulse/pulse_run%i_ls%i_evt%i_ieta%i_iphi%i_depth%i.pdf", run, ls, evt, ieta, iphi, depth));
      // c->Print(Form("plots/pulse/pulse%f_325308_1_n8p.png",vec_energy.at(i)));
    }

}
