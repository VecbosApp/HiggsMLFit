// Configuration done by perl script
enum { ee=0, mm=1, em=2 };
int finalstate = ee;

int use1jet = 0;

void SetFinalState(int f) { finalstate=f; }

void Use1Jet(int what) { use1jet = what; }

// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMaxPt",        "Use pT of the hardest leptons", kTRUE);
  opts.addBoolOption("useMET",          "Use MET",                       kTRUE);
  opts.addBoolOption("useMll",          "Use Mll",                       kTRUE);
  if(use1jet) opts.addBoolOption("useBtag",         "Use jet impact parameters",     kTRUE);
  else opts.addBoolOption("useBtag",         "Use jet impact parameters",     kFALSE);
  // smearing options for PDFs systematics
  opts.addBoolOption("smearDeltaPhi",  "apply Gaussian smearing to deltaphi parameters", kFALSE);
  opts.addBoolOption("smearMinPt",     "apply Gaussian smearing to minPt parameters",    kFALSE);
  opts.addBoolOption("smearMET",       "apply Gaussian smearing to MET parameters",      kFALSE);
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

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar *jetcat = new RooRealVar("jetcat","jetcat",-1,1); // cut the -2 ( >1 jet )
  RooRealVar *met    = new RooRealVar("met","E_{T}^{miss}",0,200,"GeV");
  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","#Delta#phi",0,180,"#deg");
  RooRealVar *maxPtEle = new RooRealVar("maxPtEle","p_{T}^{max}",20,200,"GeV");
  RooRealVar *eleInvMass = new RooRealVar("eleInvMass","m(l^{+}l^{-})",12,150,"GeV");
  RooRealVar *bTagImpPar = new RooRealVar("bTagImpPar","b-tag",-1001.,2.0);
  RooRealVar *weight = new RooRealVar("weight","weight",-100,10000);

  theFit.AddFlatFileColumn(jetcat);
  theFit.AddFlatFileColumn(met);
  theFit.AddFlatFileColumn(deltaPhi);
  theFit.AddFlatFileColumn(maxPtEle);
  if (finalstate != em) theFit.AddFlatFileColumn(eleInvMass);
  theFit.AddFlatFileColumn(bTagImpPar);
  theFit.AddFlatFileColumn(weight);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  theFit.addSpecies("myFit", "sig_0j",    "Zero Jet Signal Component");
  theFit.addSpecies("myFit", "WW_0j",     "Zero Jet WW Component");
  theFit.addSpecies("myFit", "ttbar_0j",  "Zero Jet ttbar Component");
  if (finalstate != em) theFit.addSpecies("myFit", "Z_0j",      "Zero Jet Z Component");
  theFit.addSpecies("myFit", "other_0j",  "Zero Jet Other Bkgs Component");

  // define species in the 1-jet bin
  theFit.addSpecies("myFit", "sig_1j",    "One Jet Signal Component");
  theFit.addSpecies("myFit", "WW_1j",     "One Jet WW Component");
  theFit.addSpecies("myFit", "ttbar_1j",  "One Jet ttbar Component");
  if (finalstate != em) theFit.addSpecies("myFit", "Z_1j",      "One Jet Z Component");
  theFit.addSpecies("myFit", "other_1j",  "One Jet Other Bkgs Component");

  theFit.fitWithEff("sig_0j",   "sig_1j",   "sig");
  theFit.fitWithEff("WW_0j",    "WW_1j",    "WW");
  theFit.fitWithEff("ttbar_0j", "ttbar_1j", "ttbar");
  if (finalstate != em) theFit.fitWithEff("Z_0j",     "Z_1j",     "Z");
  theFit.fitWithEff("other_0j", "other_1j", "other");

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
    theFit.addPdfWName("myFit", "sig_0j",   "deltaPhi", "Cruijff",         "sig_deltaPhi");
    theFit.addPdfWName("myFit", "WW_0j",    "deltaPhi", "Cruijff",         "WW_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_0j", "deltaPhi", "Poly2",           "ttbar_deltaPhi");
    if (finalstate != em) theFit.addPdfWName("myFit", "Z_0j",     "deltaPhi", "Cruijff",         "Z_deltaPhi");
    theFit.addPdfWName("myFit", "other_0j", "deltaPhi", "Cruijff",         "other_deltaPhi");

    theFit.addPdfCopy("myFit", "sig_1j",   "deltaPhi", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "deltaPhi", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "deltaPhi", "ttbar_0j");
    if (finalstate != em) theFit.addPdfCopy("myFit", "Z_1j",     "deltaPhi", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "deltaPhi", "other_0j");
  }

  // maxPt PDF
  if(opts.getBoolVal("useMaxPt")) {
    theFit.addPdfWName("myFit", "sig_0j",   "maxPtEle",  "Cruijff", "sig_maxPt");
    theFit.addPdfWName("myFit", "WW_0j",    "maxPtEle",  "Cruijff", "WW_maxPt");
    theFit.addPdfWName("myFit", "ttbar_0j", "maxPtEle",  "Cruijff", "ttbar_maxPt");
    if (finalstate != em) theFit.addPdfWName("myFit", "Z_0j",     "maxPtEle",  "Cruijff", "Z_maxPt");
    theFit.addPdfWName("myFit", "other_0j", "maxPtEle",  "Cruijff", "other_maxPt");

    theFit.addPdfCopy("myFit", "sig_1j",   "maxPtEle", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "maxPtEle", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "maxPtEle", "ttbar_0j");
    if (finalstate != em) theFit.addPdfCopy("myFit", "Z_1j",     "maxPtEle", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "maxPtEle", "other_0j");
  }

  // mll PDF
  if(opts.getBoolVal("useMll")) {
    if (finalstate != em) {
      theFit.addPdfWName("myFit", "sig_0j",   "eleInvMass",  "Cruijff", "sig_mll");
      theFit.addPdfWName("myFit", "WW_0j",    "eleInvMass",  "DoubleGaussian", "WW_mll");
      theFit.addPdfWName("myFit", "ttbar_0j", "eleInvMass",  "Poly2", "ttbar_mll");
      if (finalstate != em) theFit.addPdfWName("myFit", "Z_0j",     "eleInvMass",  "Cruijff", "Z_mll");
      theFit.addPdfWName("myFit", "other_0j", "eleInvMass",  "Cruijff", "other_mll");

      theFit.addPdfCopy("myFit", "sig_1j",   "eleInvMass", "sig_0j");
      theFit.addPdfCopy("myFit", "WW_1j",    "eleInvMass", "WW_0j");
      theFit.addPdfCopy("myFit", "ttbar_1j", "eleInvMass", "ttbar_0j");
      if (finalstate != em) theFit.addPdfCopy("myFit", "Z_1j",     "eleInvMass", "Z_0j");
      theFit.addPdfCopy("myFit", "other_1j", "eleInvMass", "other_0j");
    }
  }

  if(opts.getBoolVal("useMET")) {
    theFit.addPdfWName("myFit", "sig_0j",   "met",  "Cruijff", "sig_met");
    theFit.addPdfWName("myFit", "WW_0j",    "met",  "DoubleGaussian", "WW_met");
    theFit.addPdfWName("myFit", "ttbar_0j", "met",  "Cruijff", "ttbar_met");
    if (finalstate != em) theFit.addPdfWName("myFit", "Z_0j",     "met",  "Cruijff", "Z_met");
    theFit.addPdfWName("myFit", "other_0j", "met",  "Cruijff", "other_met");

    theFit.addPdfCopy("myFit", "sig_1j",   "met", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "met", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "met", "ttbar_0j");
    if (finalstate != em) theFit.addPdfCopy("myFit", "Z_1j",     "met", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "met", "other_0j");
  }

  // jet impact parameters: used only in the 1-jet bin
  const int nbinsBtag = 8;
  double limitarrayBtag[] = {0.,0.05,0.1,0.15,0.2,0.25,0.40,1.0,2.0};

  TAxis* limitsBtag = new TAxis(nbinsBtag,limitarrayBtag) ;
  TList argsBtag ;
  argsBtag.Add(limitsBtag);

  if(opts.getBoolVal("useBtag")) {
    
    theFit.addPdfWName("myFit", "sig_0j",   "NoPdf",  "sig_0j_btag");
    theFit.addPdfWName("myFit", "WW_0j",    "NoPdf",  "WW_0j_btag");
    theFit.addPdfWName("myFit", "ttbar_0j", "NoPdf",  "ttbar_0j_btag");
    if (finalstate != em) theFit.addPdfWName("myFit", "Z_0j",     "NoPdf",  "Z_0j_btag");
    theFit.addPdfWName("myFit", "other_0j", "NoPdf",  "other_0j_btag");

    theFit.addPdfWName("myFit", "sig_1j",   "bTagImpPar", "BinnedPdf",  argsBtag, "sig_1j_btag");
    theFit.addPdfWName("myFit", "WW_1j",    "bTagImpPar", "BinnedPdf",  argsBtag, "WW_1j_btag");
    theFit.addPdfWName("myFit", "ttbar_1j", "bTagImpPar", "BinnedPdf",  argsBtag, "ttbar_1j_btag");
    if (finalstate != em) theFit.addPdfWName("myFit", "Z_1j",     "bTagImpPar", "BinnedPdf",  argsBtag, "Z_1j_btag");
    theFit.addPdfWName("myFit", "other_1j", "bTagImpPar", "BinnedPdf",  argsBtag, "other_1j_btag");

  }

  // jet bin category: val =  1 --> Njets = 0
  //                   val = -1 --> Njets = 1
  theFit.addPdfWName("myFit", "sig_0j" ,   "jetcat",  "Poly2",  "Nj_0");
  theFit.addPdfCopy("myFit",  "WW_0j",     "jetcat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "ttbar_0j",  "jetcat",  "sig_0j");
  if (finalstate != em) theFit.addPdfCopy("myFit",  "Z_0j",      "jetcat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "other_0j",  "jetcat",  "sig_0j");
                                            
  theFit.addPdfWName("myFit", "sig_1j" ,   "jetcat",  "Poly2",  "Nj_1");
  theFit.addPdfCopy("myFit",  "WW_1j",     "jetcat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "ttbar_1j",  "jetcat",  "sig_1j");
  if (finalstate != em) theFit.addPdfCopy("myFit",  "Z_1j",      "jetcat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "other_1j",  "jetcat",  "sig_1j");


  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char charfinalstate[4];
  if(finalstate==ee) sprintf(charfinalstate, "ee");
  if(finalstate==mm) sprintf(charfinalstate, "mm");
  if(finalstate==em) sprintf(charfinalstate, "em");

  char configfilename[200];
  if(!use1jet) sprintf(configfilename, "toyconfig/toy-%s.config",charfinalstate);
  if(use1jet) sprintf(configfilename, "toyconfig/toy-1j-%s.config",charfinalstate);

  theFit.initialize(configfilename);

  MLWjetGenerator theGenerator(theFit, "myFit");

  Int_t ngen =
    theFit.getRealPar("N_sig")->getVal()+
    theFit.getRealPar("N_WW")->getVal()+
    theFit.getRealPar("N_ttbar")->getVal()+
    theFit.getRealPar("N_other")->getVal();
  if (finalstate != em) ngen += theFit.getRealPar("N_Z")->getVal();

  // Generate...
  RooArgSet genVars(theFit.getObsList(MLStrList("deltaPhi","met","maxPtEle")));
  if (finalstate != em) genVars.add(theFit.getObsList(MLStrList("eleInvMass")));
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
  if (outfile==0) sprintf(resultfilename,"toys/output/results-%s.dat",charfinalstate);
  else sprintf(resultfilename, outfile);
  theStudy._fitParData->write(resultfilename);

  char variablesfilename[200];
  if (outfile==0) sprintf(variablesfilename,"toys/variablesHWW2l.root");
  else sprintf(variablesfilename,"variablesHWW2l.root");
  TFile varfile(variablesfilename,"RECREATE");

  RooArgSet *variables = theStudy._fitParData->get();
  variables->setName("variables");
  variables->Write();
  varfile.Close();

}
