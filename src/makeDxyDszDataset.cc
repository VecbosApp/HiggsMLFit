#include <string>
#include <fstream>
#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "RooDataSet.h"

using namespace std;

void makeDxyDszDataset() {

  string species[4];
  species[0] = "Higgs";
  species[1] = "WW_2l";
  species[2] = "ttjetsMADGRAPH";
  species[3] = "other";

  for(int ispec=0; ispec<4; ispec++) {

    char namefileROOT[200];
    sprintf(namefileROOT,"datasets/hww_2e_Tree_%s_21X.root",species[ispec].c_str());

    char namefiletxt[100];
    sprintf( namefiletxt, "dxy_dsz-data-%s.txt",species[ispec].c_str() );

    ofstream myfile;
    myfile.open (namefiletxt);

    TFile *file = TFile::Open(namefileROOT);
    TTree *tree = (TTree*)file->Get("data");

    if(file) {
      
      float dxy, dsz;
      int jetCat;
      tree->SetBranchAddress("dxyEVT", &dxy);
      tree->SetBranchAddress("dszEVT", &dsz);
      tree->SetBranchAddress("jetCat", &jetCat);

      Long64_t nentries = tree->GetEntriesFast();
      for(Long64_t jentry=0; jentry<nentries;jentry++) {
        
        if (jentry%1000 == 0) std::cout << ">>> Dataset " << species[ispec] << ". Processing event # " << jentry << std::endl;
        
        tree->GetEntry(jentry);

        // jetCat = 1 for bin 0 and -1 for bin 1
        if(jetCat > 0 ) continue;

        myfile << dxy << "\t" << dsz << endl;
        
      }
      
    } else {
      cout << "ERROR, cannot open file with name " << namefileROOT << endl;
      cout << "Exiting." << endl;
      return;
    }

  }


}
