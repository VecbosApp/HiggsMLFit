// Configuration done by perl script
enum { ee=0, mm=1, em=2 };
int finalstate = em;
int use1jet = 0;
int higgsmass = 160;

void SetFinalState(int f) { finalstate=f; }

void Use1Jet(int what) { use1jet = what; }

void SetHiggsMass(int what) { higgsmass = what; }

// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMaxPt",        "Use pT of the hardest leptons", kTRUE);
  opts.addBoolOption("usepMET",         "Use Projected MET",             kTRUE);
  if(use1jet) opts.addBoolOption("useBtag",         "Use jet impact parameters",     kTRUE);
  else opts.addBoolOption("useBtag",         "Use jet impact parameters",     kFALSE);
  // do a Master Cavoto Test
  opts.addBoolOption("MCT",   "use MC Higgs, WW, generate the others",  kFALSE);
  // re-fit with signal fixed at 0 to evaluate the statistical significance
  opts.addBoolOption("fitZeroSig",        "do a second fit with N_sig=0",  kFALSE);
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
  RooRealVar *projMet  = new RooRealVar("projMet","E_{T}^{miss}",0,250,"GeV");
  //  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","#Delta#phi",0,180,"#deg");
  RooRealVar *expCosDphi = new RooRealVar("expCosDphi","e^{cos(#Delta#phi)}",exp(-1.),exp(1.));
  RooRealVar *maxPtEle = new RooRealVar("maxPtEle","p_{T}^{max}",0,150,"GeV");
  RooRealVar *eleInvMass = new RooRealVar("eleInvMass","m(l^{+}l^{-})",0,1e+30,"GeV");
  RooRealVar *bTagImpPar = new RooRealVar("bTagImpPar","b-tag",-1000.,1e+30);
  RooRealVar *weight = new RooRealVar("weight","weight",-100,10000);

  theFit.AddFlatFileColumn(jetcat);
  theFit.AddFlatFileColumn(projMet);
  //  theFit.AddFlatFileColumn(deltaPhi);
  theFit.AddFlatFileColumn(expCosDphi);
  theFit.AddFlatFileColumn(maxPtEle);
//   theFit.AddFlatFileColumn(eleInvMass);
//   theFit.AddFlatFileColumn(bTagImpPar);
  theFit.AddFlatFileColumn(weight);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  theFit.addSpecies("myFit", "sig",    "Signal Component");
  theFit.addSpecies("myFit", "WW",     "Sig Component");
  theFit.addSpecies("myFit", "ttbar",  "ttbar Component");
  theFit.addSpecies("myFit", "other",  "Other Bkgs Component");

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
//     theFit.addPdfWName("myFit", "sig",   "deltaPhi", "Cruijff",         "sig_deltaPhi");
//     theFit.addPdfWName("myFit", "WW",    "deltaPhi", "Cruijff",         "WW_deltaPhi");
//     theFit.addPdfWName("myFit", "ttbar", "deltaPhi", "Gaussian",        "ttbar_deltaPhi");
//     theFit.addPdfWName("myFit", "other", "deltaPhi", "Gaussian",        "other_deltaPhi");
    
    theFit.addPdfWName("myFit", "sig",   "expCosDphi", "Cruijff",         "sig_deltaPhi");
    theFit.addPdfWName("myFit", "WW",    "expCosDphi", "Cruijff",         "WW_deltaPhi");
    if(finalstate==mm) theFit.addPdfWName("myFit", "ttbar", "expCosDphi", "Poly2",  "ttbar_deltaPhi");
    else theFit.addPdfWName("myFit", "ttbar", "expCosDphi", "Cruijff",  "ttbar_deltaPhi");
    theFit.addPdfWName("myFit", "other", "expCosDphi", "Expo",            "other_deltaPhi");
  }

  // maxPt PDF
  if(opts.getBoolVal("useMaxPt")) {
    theFit.addPdfWName("myFit", "sig",   "maxPtEle",  "Cruijff", "sig_maxPt");
    theFit.addPdfWName("myFit", "WW",    "maxPtEle",  "Cruijff", "WW_maxPt");
    theFit.addPdfWName("myFit", "ttbar", "maxPtEle",  "Cruijff", "ttbar_maxPt");
    theFit.addPdfWName("myFit", "other", "maxPtEle",  "Cruijff", "other_maxPt");
  }

  if(opts.getBoolVal("usepMET")) {
    theFit.addPdfWName("myFit", "sig",   "projMet",  "Cruijff", "sig_projMet");
    theFit.addPdfWName("myFit", "WW",    "projMet",  "Cruijff", "WW_projMet");
    if(finalstate!=ee) theFit.addPdfWName("myFit", "ttbar", "projMet",  "Cruijff", "ttbar_projMet");
    else theFit.addPdfWName("myFit", "ttbar", "projMet",  "Gaussian", "ttbar_projMet");
    theFit.addPdfWName("myFit", "other", "projMet",  "Cruijff", "other_projMet");
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char charfinalstate[4];
  if(finalstate==ee) sprintf(charfinalstate, "ee");
  if(finalstate==mm) sprintf(charfinalstate, "mm");
  if(finalstate==em) sprintf(charfinalstate, "em");

  char configfilename[200];
  if(!use1jet) sprintf(configfilename, "toyconfig/toy-%s-NoMllTightId-mH%d.config",charfinalstate,higgsmass);
  if(use1jet) sprintf(configfilename, "toyconfig/toy-1j-%s-NoMllTightId-mH%d.config",charfinalstate,higgsmass);

  theFit.initialize(configfilename);

  MLGenerator theGenerator(theFit, "myFit");

  Int_t ngen =
    theFit.getRealPar("N_sig")->getVal()+
    theFit.getRealPar("N_WW")->getVal()+
    theFit.getRealPar("N_ttbar")->getVal()+
    theFit.getRealPar("N_other")->getVal();

  // Generate...
  RooArgSet genVars(theFit.getObsList(MLStrList("expCosDphi","projMet","maxPtEle")));
  MLToyStudy theStudy(theGenerator, genVars, "E", "MTE", 0, theFit.getNoNormVars("myFit"));
  if(opts.getBoolVal("MCT")) {
    if(finalstate==ee) {
      theStudy.addMockSpecies("sig","datasets/H160_ee.root","T1");
      theStudy.addMockSpecies("WW","datasets/WW_ee.root","T1");
    }
    if(finalstate==mm) {
      theStudy.addMockSpecies("sig","datasets/H160_mm.root","T1");
      theStudy.addMockSpecies("WW","datasets/WW_mm.root","T1");
    }
    if(finalstate==em) {
      theStudy.addMockSpecies("sig","datasets/H160_em.root","T1");
      theStudy.addMockSpecies("WW","datasets/WW_em.root","T1");
    }
  }

  theStudy.addFit(*myPdf);

  RooAbsPdf *myPdf2 = 0;

  if(opts.getBoolVal("fitZeroSig")) {

    getSecondFit();
    // build the fit likelihood
    myPdf2 = theFit2.buildModel("myFit2");
    
    // Initialize the fit...
    char charfinalstate[4];
    if(finalstate==ee) sprintf(charfinalstate, "ee");
    if(finalstate==mm) sprintf(charfinalstate, "mm");
    if(finalstate==em) sprintf(charfinalstate, "em");
    
    char configfilename[200];
    if(!use1jet) sprintf(configfilename, "toyconfig/toy-%s-NoMllTightId-mH%d.config",charfinalstate,higgsmass);
    if(use1jet) sprintf(configfilename, "toyconfig/toy-1j-%s-NoMllTightId-mH%d.config",charfinalstate,higgsmass);

    theFit2.initialize(configfilename);
  }

  if(opts.getBoolVal("fitZeroSig")) {
    theFit2.getRealPar("N_sig")->setVal(0.);
    theFit2.getRealPar("N_sig")->setConstant(kTRUE);
  }

  if( myPdf2 !=0 ) theStudy.addFit(*myPdf2);

  theStudy.generateAndFit(nexp,ngen);

  char resultfilename[200];
  if (outfile==0) sprintf(resultfilename,"toys/output/results-mH%d-%s.dat",higgsmass,charfinalstate);
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
