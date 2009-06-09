int higgsmass = 160; // GeV
void SetHiggsMass(int m) {
  higgsmass=m;
}

enum { ee=0, mm=1, em=2 };
int finalstate = ee;
void SetFinalState(int f) {
  finalstate=f;
}


// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMinPt",        "Use pT of the slowest leptons", kTRUE);
  opts.addBoolOption("useMET",          "Use MET",                       kTRUE);
  opts.addBoolOption("useDxyzEVT",      "Use jet impact parameters",     kTRUE);
  // smearing options for PDFs systematics
  opts.addBoolOption("smearDeltaPhi",  "apply Gaussian smearing to deltaphi parameters", kFALSE);
  opts.addBoolOption("smearMinPt",     "apply Gaussian smearing to minPt parameters",    kFALSE);
  opts.addBoolOption("smearMET",       "apply Gaussian smearing to MET parameters",      kTRUE);
  opts.addBoolOption("smearEff",       "apply Gaussian smearing to jet bin fraction",    kFALSE);

  return opts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MLFit theFit;

void Generate(Int_t nexp = 1, UInt_t iseed = 65539, char* outfile= 0) {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  TDatime *now = new TDatime();
  int today = now->GetDate();
  int clock = now->GetTime();
  int seed = today+clock+iseed;
  // Set the random number seed...
  RooRandom::randomGenerator()->SetSeed(seed);

  MLFit theFit;

  RooRealVar *jetCat = new RooRealVar("jetCat","jetCat",-2,2);
  RooRealVar *MET = new RooRealVar("MET","MET",30,200,"GeV");
  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","deltaPhi",0,180,"#circ");
  RooRealVar *minPt = new RooRealVar("minPt","minPt",10,200,"GeV");
  RooRealVar *dxyEVT = new RooRealVar("dxyEVT","dxyEVT",0,5000,"#mum");
  RooRealVar *dszEVT = new RooRealVar("dszEVT","dszEVT",0,5000,"#mum");

  theFit.AddFlatFileColumn(jetCat);
  theFit.AddFlatFileColumn(MET);
  theFit.AddFlatFileColumn(deltaPhi);
  theFit.AddFlatFileColumn(minPt);
  theFit.AddFlatFileColumn(dxyEVT);
  theFit.AddFlatFileColumn(dszEVT);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  theFit.addSpecies("myFit", "sig_0j",    "Zero Jet Signal Component");
  theFit.addSpecies("myFit", "WW_0j",     "Zero Jet Signal Component");
  theFit.addSpecies("myFit", "ttbar_0j",  "Zero Jet ttbar Component");
  theFit.addSpecies("myFit", "other_0j",  "Zero Jet Other Bkgs Component");

  // define species in the 1-jet bin
  theFit.addSpecies("myFit", "sig_1j",    "One Jet Signal Component");
  theFit.addSpecies("myFit", "WW_1j",     "One Jet Signal Component");
  theFit.addSpecies("myFit", "ttbar_1j",  "One Jet ttbar Component");
  theFit.addSpecies("myFit", "other_1j",  "One Jet Other Bkgs Component");

  theFit.fitWithEff("sig_0j",   "sig_1j",   "sig");
  theFit.fitWithEff("WW_0j",    "WW_1j",    "WW");
  theFit.fitWithEff("ttbar_0j", "ttbar_1j", "ttbar");
  theFit.fitWithEff("other_0j", "other_1j", "other");

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
    theFit.addPdfWName("myFit", "sig_0j",   "deltaPhi", "CrystalCruijff",  "sig_deltaPhi");
    theFit.addPdfWName("myFit", "WW_0j",    "deltaPhi", "Cruijff",    "WW_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_0j", "deltaPhi", "Poly2",    "ttbar_deltaPhi");
    theFit.addPdfWName("myFit", "other_0j", "deltaPhi", "DoubleGaussian", "other_deltaPhi");

    theFit.addPdfCopy("myFit", "sig_1j",   "deltaPhi", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "deltaPhi", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "deltaPhi", "ttbar_0j");
    theFit.addPdfCopy("myFit", "other_1j", "deltaPhi", "other_0j");
  }

  // minPt PDF
  if(opts.getBoolVal("useMinPt")) {
    theFit.addPdfWName("myFit", "sig_0j",   "minPt",  "Cruijff", "sig_minPt");
    theFit.addPdfWName("myFit", "WW_0j",    "minPt",  "Cruijff", "WW_minPt");
    theFit.addPdfWName("myFit", "ttbar_0j", "minPt",  "Cruijff", "ttbar_minPt");
    theFit.addPdfWName("myFit", "other_0j", "minPt",  "Cruijff", "other_minPt");

    theFit.addPdfCopy("myFit", "sig_1j",   "minPt", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "minPt", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "minPt", "ttbar_0j");
    theFit.addPdfCopy("myFit", "other_1j", "minPt", "other_0j");
  }

  // MET PDF
  // use histogram PDF to limit sensitivity to the tail
  const int nbins = 8;
  double limitarray[] = {30.0,40.0,50.0,60.0,70.0,80.0,100.0,150.0,200.0};

  TAxis* limits = new TAxis(nbins,limitarray) ;
  TList args ;
  args.Add(limits);

  if(opts.getBoolVal("useMET")) {
    theFit.addPdfWName("myFit", "sig_0j",   "MET",  "BinnedPdf", args, "sig_MET");
    theFit.addPdfWName("myFit", "WW_0j",    "MET",  "BinnedPdf", args, "WW_MET");
    theFit.addPdfWName("myFit", "ttbar_0j", "MET",  "BinnedPdf", args, "ttbar_MET");
    theFit.addPdfWName("myFit", "other_0j", "MET",  "BinnedPdf", args, "other_MET");

    theFit.addPdfCopy("myFit", "sig_1j",   "MET", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "MET", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "MET", "ttbar_0j");
    theFit.addPdfCopy("myFit", "other_1j", "MET", "other_0j");
  }

  // jet impact parameters: used only in the 1-jet bin
  if(opts.getBoolVal("useDxyzEVT")) {
    
    MLStrList obs("dxyEVT","dszEVT");
    MLStrList sig_args("datasets/binning.txt","datasets/dxy_dsz-data-sig.txt");
    MLStrList WW_args("datasets/binning.txt","datasets/dxy_dsz-data-WW.txt");
    MLStrList ttbar_args("datasets/binning.txt","datasets/dxy_dsz-data-ttbar.txt");
    MLStrList other_args("datasets/binning.txt","datasets/dxy_dsz-data-other.txt");

    theFit.addPdfWName("myFit", "sig_0j",   obs, "2DNoPdf", TList(), "sig_0j_DxyzEVT");
    theFit.addPdfWName("myFit", "WW_0j",    obs, "2DNoPdf", TList(), "WW_0j_DxyzEVT");
    theFit.addPdfWName("myFit", "ttbar_0j", obs, "2DNoPdf", TList(), "ttbar_0j_DxyzEVT");
    theFit.addPdfWName("myFit", "other_0j", obs, "2DNoPdf", TList(), "other_0j_DxyzEVT");

    theFit.addPdfWName("myFit", "sig_1j",   obs, "2DArbHist",  sig_args,   "sig_1j_DxyzEVT");
    theFit.addPdfWName("myFit", "WW_1j",    obs, "2DArbHist",  WW_args,    "WW_1j_DxyzEVT");
    theFit.addPdfWName("myFit", "ttbar_1j", obs, "2DArbHist",  ttbar_args, "ttbar_1j_DxyzEVT");
    theFit.addPdfWName("myFit", "other_1j", obs, "2DArbHist",  other_args, "other_1j_DxyzEVT");

  }

  // jet bin category: val =  1 --> Njets = 0
  //                   val = -1 --> Njets = 1
  theFit.addPdfWName("myFit", "sig_0j" ,   "jetCat",  "Poly2",  "Nj_0");
  theFit.addPdfCopy("myFit",  "WW_0j",     "jetCat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "ttbar_0j",  "jetCat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "other_0j",  "jetCat",  "sig_0j");
                                            
  theFit.addPdfWName("myFit", "sig_1j" ,   "jetCat",  "Poly2",  "Nj_1");
  theFit.addPdfCopy("myFit",  "WW_1j",     "jetCat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "ttbar_1j",  "jetCat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "other_1j",  "jetCat",  "sig_1j");



  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  sprintf(configfilename, "toyconfig/toyHWW-finalstate%d-%dGeV.config",finalstate,higgsmass);

  theFit.initialize(configfilename);

  MLWjetGenerator theGenerator(theFit, "myFit");

  Int_t ngen =
    theFit.getRealPar("N_sig")->getVal()+
    theFit.getRealPar("N_WW")->getVal()+
    theFit.getRealPar("N_ttbar")->getVal()+
    theFit.getRealPar("N_other")->getVal();

  // Generate...
  RooArgSet genVars(theFit.getObsList(MLStrList("deltaPhi","MET","minPt","dxyEVT","dszEVT")));
  MLToyStudy theStudy(theGenerator, genVars, "E", "MTE", 0, theFit.getNoNormVars("myFit"));
  theStudy.addFit(*myPdf);

  RooAbsPdf *myPdf2 = 0;

  // smear group of correlated parameters for systematics
  if(opts.getBoolVal("smearDeltaPhi")) {
    MLStrList sig_deltaPhi_params("sig_deltaPhi_mean","sig_deltaPhi_sigma","sig_deltaPhi_alpha","sig_deltaPhi_alphaCB","sig_deltaPhi_nCB");
    MLStrList WW_deltaPhi_params("WW_deltaPhi_mean","WW_deltaPhi_sigmaL","WW_deltaPhi_sigmaR","WW_deltaPhi_alphaL","WW_deltaPhi_alphaR");
    MLStrList ttbar_deltaPhi_params("ttbar_deltaPhi_p1","ttbar_deltaPhi_p2");
    MLStrList other_deltaPhi_params("other_deltaPhi_mean1","other_deltaPhi_sigma1","other_deltaPhi_mean2","other_deltaPhi_sigma2","other_deltaPhi_f1");
    MLStrList deltaPhi_params(sig_deltaPhi_params);
    deltaPhi_params.Add(WW_deltaPhi_params);
    deltaPhi_params.Add(ttbar_deltaPhi_params);
    deltaPhi_params.Add(other_deltaPhi_params);
    theFit.smearConstantParameters(deltaPhi_params);
    myPdf2 = theFit.buildModel("myFit");
  }

  if(opts.getBoolVal("smearMinPt")) {
    MLStrList sig_minPt_params("sig_minPt_mean","sig_minPt_sigmaL","sig_minPt_sigmaR","sig_minPt_alphaL","sig_minPt_alphaR");
    MLStrList WW_minPt_params("WW_minPt_mean","WW_minPt_sigmaL","WW_minPt_sigmaR","WW_minPt_alphaL","WW_minPt_alphaR");
    MLStrList ttbar_minPt_params("ttbar_minPt_mean","ttbar_minPt_sigmaL","ttbar_minPt_sigmaR","ttbar_minPt_alphaL","ttbar_minPt_alphaR");
    MLStrList other_minPt_params("other_minPt_mean","other_minPt_sigmaL","other_minPt_sigmaR","other_minPt_alphaL","other_minPt_alphaR");
    MLStrList minPt_params(sig_minPt_params);
    minPt_params.Add(WW_minPt_params);
    minPt_params.Add(ttbar_minPt_params);
    minPt_params.Add(other_minPt_params);
    theFit.smearConstantParameters(minPt_params);
    myPdf2 = theFit.buildModel("myFit");
  }

  if(opts.getBoolVal("smearMinPt")) {
    MLStrList sig_MET_params("sig_MET_bin1","sig_MET_bin2","sig_MET_bin3","sig_MET_bin4","sig_MET_bin5","sig_MET_bin6","sig_MET_bin7");
    MLStrList WW_MET_params("WW_MET_bin1","WW_MET_bin2","WW_MET_bin3","WW_MET_bin4","WW_MET_bin5","WW_MET_bin6","WW_MET_bin7");
    MLStrList ttbar_MET_params("ttbar_MET_bin1","ttbar_MET_bin2","ttbar_MET_bin3","ttbar_MET_bin4","ttbar_MET_bin5","ttbar_MET_bin6","ttbar_MET_bin7");
    MLStrList other_MET_params("other_MET_bin1","other_MET_bin2","other_MET_bin3","other_MET_bin4","other_MET_bin5","other_MET_bin6","other_MET_bin7");
    MLStrList MET_params(sig_MET_params);
    MET_params.Add(WW_MET_params);
    MET_params.Add(ttbar_MET_params);
    MET_params.Add(other_MET_params);
    theFit.smearConstantParameters(MET_params);
    myPdf2 = theFit.buildModel("myFit");
  }

  if(opts.getBoolVal("smearEff")) {
    theFit.smearConstantParameters(MLStrList("eff_sig","eff_WW"));
    myPdf2 = theFit.buildModel("myFit");
  }

  if( myPdf2 !=0 ) theStudy.addFit(*myPdf2);

  theStudy.generateAndFit(nexp,ngen);

  char resultfilename[200];
  if (outfile==0) sprintf(resultfilename,"toys/output/resultsHWW-finalstate%d-%dGeV.dat",finalstate,higgsmass);
  else sprintf(resultfilename, outfile);
  theStudy._fitParData->write(resultfilename);

  char variablesfilename[200];
  if (outfile==0) sprintf(variablesfilename,"toys/variablesHWW2e.root");
  else sprintf(variablesfilename,"variablesHWW2e.root");
  TFile varfile(variablesfilename,"RECREATE");

  RooArgSet *variables = theStudy._fitParData->get();
  variables->setName("variables");
  variables->Write();
  varfile.Close();

}



