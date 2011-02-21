// Configuration done by perl script
enum { ee=0, mm=1, em=2 };
int finalstate = em;
int use1jet = 0;
int Hmass = 160;

// the finalstate is not used in this macro, but it is here because the
// perl script executes that (being the same to submit GenerateHWW2e.cc)
void Use1Jet(int what) { use1jet = what; }

void SetHiggsMass(int what) { Hmass = what; }

// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("weightedDataset", "use event weight instead of 1", kFALSE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMaxPt",        "Use pT of the hardest leptons", kTRUE);
  opts.addBoolOption("usepMET",         "Use Projected MET",             kTRUE);
  opts.addBoolOption("useMll",          "Use Mll",                       kFALSE);
  opts.addBoolOption("useBtag",         "Use BTag",                      kFALSE);
  opts.addBoolOption("AllFit",          "Fit all species",        kTRUE);
  opts.addBoolOption("HiggsOnlyFit",    "Fit Higgs species only", kFALSE);
  opts.addBoolOption("WWOnlyFit",       "Fit WW species only",    kFALSE);
  opts.addBoolOption("ttbarOnlyFit",    "Fit ttbar species only", kFALSE);
  opts.addBoolOption("otherOnlyFit",    "Fit other species only", kFALSE);
  opts.addBoolOption("doNLLPlot",       "do the NLL plot",  kFALSE);
  opts.addBoolOption("fitZeroSig",      "fit fixing signal to zero",  kTRUE);
  opts.addBoolOption("includeSystematics", "add systemaic uncertainties in the minimization", kTRUE);

  return opts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MLFit theFit;
MLFit *theFit2[10000];

void Generate(Int_t nexp = 1, UInt_t iseed = 65539, char* outfile= 0) {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  TDatime *now = new TDatime();
  int today = now->GetDate();
  int clock = now->GetTime();
  int seed = today+clock+iseed;
  // Set the random number seed...
  RooRandom::randomGenerator()->SetSeed(seed);

  RooRealVar *jetcat = new RooRealVar("jetcat","jetcat",-1,1); // cut the -2 ( >1 jet )
  RooRealVar *projMet  = new RooRealVar("projMet","E_{T}^{miss}",0,250,"GeV");
  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","#Delta#phi",0,180,"#deg");
  RooRealVar *maxPtEle = new RooRealVar("maxPtEle","p_{T}^{max}",0,150,"GeV");
  RooRealVar *eleInvMass = new RooRealVar("eleInvMass","m(l^{+}l^{-})",0,1e+30,"GeV");
  RooRealVar *bTagImpPar = new RooRealVar("bTagImpPar","b-tag",-1000.,1e+30);
  RooRealVar *weight = new RooRealVar("weight","weight",-100,10000);
  RooRealVar *finalstate = new RooRealVar("finalstate","finalstate",0,2);

  theFit.AddFlatFileColumn(jetcat);
  theFit.AddFlatFileColumn(projMet);
  theFit.AddFlatFileColumn(deltaPhi);
  theFit.AddFlatFileColumn(maxPtEle);
  theFit.AddFlatFileColumn(weight);
  theFit.AddFlatFileColumn(finalstate);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  // ee
  theFit.addSpecies("myFit", "sig_ee",    "Signal Component to ee");
  theFit.addSpecies("myFit", "WW_ee",     "Sig Component to ee");
  theFit.addSpecies("myFit", "ttbar_ee",  "ttbar Component to ee ");
  theFit.addSpecies("myFit", "other_ee",  "Other Bkgs Component to ee");

  // mm
  theFit.addSpecies("myFit", "sig_mm",    "Signal Component to mm");
  theFit.addSpecies("myFit", "WW_mm",     "Sig Component to mm");
  theFit.addSpecies("myFit", "ttbar_mm",  "ttbar Component to mm");
  theFit.addSpecies("myFit", "other_mm",  "Other Bkgs Component to mm");

  // em
  theFit.addSpecies("myFit", "sig_em",    "Signal Component to em");
  theFit.addSpecies("myFit", "WW_em",     "Sig Component to em");
  theFit.addSpecies("myFit", "ttbar_em",  "ttbar Component to em");
  theFit.addSpecies("myFit", "other_em",  "Other Bkgs Component to em");

  // efficiencies from the channel -> selected channel
  RooRealVar *eff_sig_ee = new RooRealVar("eff_sig_ee","eff_sig_ee",0.5,0,1);
  RooRealVar *eff_sig_mm = new RooRealVar("eff_sig_mm","eff_sig_mm",0.5,0,1);
  RooRealVar *eff_sig_em = new RooRealVar("eff_sig_em","eff_sig_em",0.5,0,1);

  // RooRealVar *eff_WW_ee = new RooRealVar("eff_WW_ee","eff_WW_ee",0.5,0,1);
  // RooRealVar *eff_WW_mm = new RooRealVar("eff_WW_mm","eff_WW_mm",0.5,0,1);
  // RooRealVar *eff_WW_em = new RooRealVar("eff_WW_em","eff_WW_em",0.5,0,1);

  // minimize respect Higgs xsec
  RooRealVar *N_sig_2l2nu = new RooRealVar("N_sig_2l2nu","N_sig_2l2nu",0);
  theFit.defineYield("sig_ee","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_ee));
  theFit.defineYield("sig_mm","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_mm));
  theFit.defineYield("sig_em","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_em));

  // also take W+W- background as correlated between the three final states 
  // RooRealVar *N_WW_2l2nu = new RooRealVar("N_WW_2l2nu","N_WW_2l2nu",0);
  // theFit.defineYield("WW_ee","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_ee));
  // theFit.defineYield("WW_mm","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_mm));
  // theFit.defineYield("WW_em","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_em));

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
    theFit.addPdfWName("myFit", "sig_ee",   "deltaPhi", "Cruijff",         "sig_ee_deltaPhi");
    theFit.addPdfWName("myFit", "WW_ee",    "deltaPhi", "Cruijff",         "WW_ee_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_ee", "deltaPhi", "Gaussian",        "ttbar_ee_deltaPhi");
    theFit.addPdfWName("myFit", "other_ee", "deltaPhi", "Cruijff",         "other_ee_deltaPhi");

    theFit.addPdfWName("myFit", "sig_mm",   "deltaPhi", "Cruijff",         "sig_mm_deltaPhi");
    theFit.addPdfWName("myFit", "WW_mm",    "deltaPhi", "Cruijff",         "WW_mm_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_mm", "deltaPhi", "Cruijff",         "ttbar_mm_deltaPhi");
    theFit.addPdfWName("myFit", "other_mm", "deltaPhi", "Cruijff",         "other_mm_deltaPhi");

    theFit.addPdfWName("myFit", "sig_em",   "deltaPhi", "Cruijff",         "sig_em_deltaPhi");
    theFit.addPdfWName("myFit", "WW_em",    "deltaPhi", "Cruijff",         "WW_em_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_em", "deltaPhi", "Cruijff",         "ttbar_em_deltaPhi");
    theFit.addPdfWName("myFit", "other_em", "deltaPhi", "Cruijff",         "other_em_deltaPhi");
  }

  // maxPt PDF
  if(opts.getBoolVal("useMaxPt")) {
    theFit.addPdfWName("myFit", "sig_ee",   "maxPtEle",  "Cruijff", "sig_ee_maxPt");
    theFit.addPdfWName("myFit", "WW_ee",    "maxPtEle",  "Cruijff", "WW_ee_maxPt");
    theFit.addPdfWName("myFit", "ttbar_ee", "maxPtEle",  "Cruijff", "ttbar_ee_maxPt");
    theFit.addPdfWName("myFit", "other_ee", "maxPtEle",  "Cruijff", "other_ee_maxPt");

    theFit.addPdfWName("myFit", "sig_mm",   "maxPtEle",  "Cruijff", "sig_mm_maxPt");
    theFit.addPdfWName("myFit", "WW_mm",    "maxPtEle",  "Cruijff", "WW_mm_maxPt");
    theFit.addPdfWName("myFit", "ttbar_mm", "maxPtEle",  "Cruijff", "ttbar_mm_maxPt");
    theFit.addPdfWName("myFit", "other_mm", "maxPtEle",  "Cruijff", "other_mm_maxPt");

    theFit.addPdfWName("myFit", "sig_em",   "maxPtEle",  "Cruijff", "sig_em_maxPt");
    theFit.addPdfWName("myFit", "WW_em",    "maxPtEle",  "Cruijff", "WW_em_maxPt");
    theFit.addPdfWName("myFit", "ttbar_em", "maxPtEle",  "Cruijff", "ttbar_em_maxPt");
    theFit.addPdfWName("myFit", "other_em", "maxPtEle",  "Cruijff", "other_em_maxPt");
  }

  if(opts.getBoolVal("usepMET")) {
    theFit.addPdfWName("myFit", "sig_ee",   "projMet",  "Cruijff", "sig_ee_projMet");
    theFit.addPdfWName("myFit", "WW_ee",    "projMet",  "Cruijff", "WW_ee_projMet");
    theFit.addPdfWName("myFit", "ttbar_ee", "projMet",  "Gaussian", "ttbar_ee_projMet");
    theFit.addPdfWName("myFit", "other_ee", "projMet",  "Cruijff", "other_ee_projMet");

    theFit.addPdfWName("myFit", "sig_mm",   "projMet",  "Cruijff",  "sig_mm_projMet");
    theFit.addPdfWName("myFit", "WW_mm",    "projMet",  "Cruijff",  "WW_mm_projMet");
    theFit.addPdfWName("myFit", "ttbar_mm", "projMet",  "Cruijff", "ttbar_mm_projMet");
    theFit.addPdfWName("myFit", "other_mm", "projMet",  "Cruijff",  "other_mm_projMet");

    theFit.addPdfWName("myFit", "sig_em",   "projMet",  "Cruijff",  "sig_em_projMet");
    theFit.addPdfWName("myFit", "WW_em",    "projMet",  "Cruijff",  "WW_em_projMet");
    theFit.addPdfWName("myFit", "ttbar_em", "projMet",  "Cruijff", "ttbar_em_projMet");
    theFit.addPdfWName("myFit", "other_em", "projMet",  "Cruijff",  "other_em_projMet");
  }

  // final state category (called ExclJet to confuse people...)
  theFit.addPdfWName("myFit", "sig_ee" , "finalstate", "ExclJet", "finalstate_ee");
  theFit.addPdfCopy("myFit", "WW_ee", "finalstate", "sig_ee");
  theFit.addPdfCopy("myFit", "ttbar_ee", "finalstate", "sig_ee");
  theFit.addPdfCopy("myFit", "other_ee", "finalstate", "sig_ee");

  theFit.addPdfWName("myFit", "sig_mm" , "finalstate", "ExclJet", "finalstate_mm");
  theFit.addPdfCopy("myFit", "WW_mm", "finalstate", "sig_mm");
  theFit.addPdfCopy("myFit", "ttbar_mm", "finalstate", "sig_mm");
  theFit.addPdfCopy("myFit", "other_mm", "finalstate", "sig_mm");

  theFit.addPdfWName("myFit", "sig_em" , "finalstate", "ExclJet", "finalstate_em");
  theFit.addPdfCopy("myFit", "WW_em", "finalstate", "sig_em");
  theFit.addPdfCopy("myFit", "ttbar_em", "finalstate", "sig_em");
  theFit.addPdfCopy("myFit", "other_em", "finalstate", "sig_em");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfile[200];
  // initialize backgrounds
  sprintf(configfile,"toyconfig/toy-ll-mH%d.config",Hmass);
  theFit.initialize(configfile);
  // initialize signals
  sprintf(configfile,"fitconfig/H%d-ee.config",Hmass);
  theFit.initialize(configfile);
  sprintf(configfile,"fitconfig/H%d-mm.config",Hmass);
  theFit.initialize(configfile);
  sprintf(configfile,"fitconfig/H%d-em.config",Hmass);
  theFit.initialize(configfile);
  // initialize mass-dependent yields
  sprintf(configfile,"toyconfig/yields-mH%d.config",Hmass);
  theFit.initialize(configfile);

  MLHWWGenerator theGenerator(theFit, "myFit");

  Int_t ngen = theFit.getRealPar("N_sig_2l2nu")->getVal()+
    theFit.getRealPar("N_WW_ee")->getVal()+theFit.getRealPar("N_WW_mm")->getVal()+theFit.getRealPar("N_WW_em")->getVal()+
    //theFit.getRealPar("N_WW_2l2nu")->getVal()+
    theFit.getRealPar("N_ttbar_ee")->getVal()+theFit.getRealPar("N_ttbar_mm")->getVal()+theFit.getRealPar("N_ttbar_em")->getVal()+
    theFit.getRealPar("N_other_ee")->getVal()+theFit.getRealPar("N_other_mm")->getVal()+theFit.getRealPar("N_other_em")->getVal();
  
  // the systematics
  RooArgSet constraintPdfs;
  if(opts.getBoolVal("includeSystematics")) {
    RooRealVar eff_sig_ee_m("eff_sig_ee_m","eff_sig_ee_m",theFit.getRealPar("eff_sig_ee")->getVal());
    RooRealVar eff_sig_ee_s("eff_sig_ee_s","eff_sig_ee_s",theFit.getRealPar("eff_sig_ee")->getError());
    RooGaussian* eff_sig_ee_pdf = new RooGaussian("eff_sig_ee_pdf","eff_sig_ee_pdf", *eff_sig_ee, eff_sig_ee_m, eff_sig_ee_s);

    RooRealVar eff_sig_mm_m("eff_sig_mm_m","eff_sig_mm_m",theFit.getRealPar("eff_sig_mm")->getVal());
    RooRealVar eff_sig_mm_s("eff_sig_mm_s","eff_sig_mm_s",theFit.getRealPar("eff_sig_mm")->getError());
    RooGaussian* eff_sig_mm_pdf = new RooGaussian("eff_sig_mm_pdf","eff_sig_mm_pdf", *eff_sig_mm, eff_sig_mm_m, eff_sig_mm_s);

    RooRealVar eff_sig_em_m("eff_sig_em_m","eff_sig_em_m",theFit.getRealPar("eff_sig_em")->getVal());
    RooRealVar eff_sig_em_s("eff_sig_em_s","eff_sig_em_s",theFit.getRealPar("eff_sig_em")->getError());
    RooGaussian* eff_sig_em_pdf = new RooGaussian("eff_sig_em_pdf","eff_sig_em_pdf", *eff_sig_em, eff_sig_em_m, eff_sig_em_s);

    constraintPdfs.add(RooArgSet(*eff_sig_ee_pdf,*eff_sig_mm_pdf,*eff_sig_em_pdf));
  }
  
  // Generate...
  RooArgSet genVars(theFit.getObsList(MLStrList("projMet","deltaPhi","maxPtEle")));
  MLToyStudy theStudy(theGenerator, genVars, "E", "MTE", 0, theFit.getNoNormVars("myFit"), constraintPdfs);
  theStudy.addFit(*myPdf);

  RooAbsPdf *myPdf2 = 0;

  if(opts.getBoolVal("fitZeroSig")) {
    getSecondFit(0);
    // build the fit likelihood
    myPdf2 = theFit2[0]->buildModel("myFit0");
    
    // Initialize the fit...
    // initialize backgrounds
    sprintf(configfile,"toyconfig/toy-ll-mH%d.config",Hmass);
    theFit2[0]->initialize(configfile);
    // initialize signals
    sprintf(configfile,"fitconfig/H%d-ee.config",Hmass);
    theFit2[0]->initialize(configfile);
    sprintf(configfile,"fitconfig/H%d-mm.config",Hmass);
    theFit2[0]->initialize(configfile);
    sprintf(configfile,"fitconfig/H%d-em.config",Hmass);
    theFit2[0]->initialize(configfile);
    // initialize mass-dependent yields
    sprintf(configfile,"toyconfig/yields-mH%d.config",Hmass);
    theFit2[0]->initialize(configfile);

    theFit2[0]->getRealPar("N_sig_2l2nu")->setVal(0.);
    theFit2[0]->getRealPar("N_sig_2l2nu")->setConstant(kTRUE);
  }

  if( myPdf2 !=0 ) theStudy.addFit(*myPdf2);

  theStudy.generateAndFit(nexp,ngen);
  
  char resultfilename[200];
  if (outfile==0) sprintf(resultfilename,"toys/output/resultsHWW2l2nu.dat");
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

  
void getSecondFit(int ifit) {

  MLFit *theIFit = new MLFit();
  char fitname[200];
  sprintf(fitname,"myFit%d",ifit);

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar *jetcat = new RooRealVar("jetcat","jetcat",-1,1); // cut the -2 ( >1 jet )
  RooRealVar *projMet  = new RooRealVar("projMet","E_{T}^{miss}",0,250,"GeV");
  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","#Delta#phi",0,180,"#deg");
  RooRealVar *maxPtEle = new RooRealVar("maxPtEle","p_{T}^{max}",0,150,"GeV");
  RooRealVar *eleInvMass = new RooRealVar("eleInvMass","m(l^{+}l^{-})",0,1e+30,"GeV");
  RooRealVar *bTagImpPar = new RooRealVar("bTagImpPar","b-tag",-1000.,1e+30);
  RooRealVar *weight = new RooRealVar("weight","weight",-100,10000);
  RooRealVar *finalstate = new RooRealVar("finalstate","finalstate",0,2);

  theIFit->AddFlatFileColumn(jetcat);
  theIFit->AddFlatFileColumn(projMet);
  theIFit->AddFlatFileColumn(deltaPhi);
  theIFit->AddFlatFileColumn(maxPtEle);
  theIFit->AddFlatFileColumn(weight);
  theIFit->AddFlatFileColumn(finalstate);

  // define a fit model
  theIFit->addModel(fitname, "Higgs to WW");

  // define species in the 0-jet bin
  // ee
  theIFit->addSpecies(fitname, "sig_ee",    "Signal Component to ee");
  theIFit->addSpecies(fitname, "WW_ee",     "Sig Component to ee");
  theIFit->addSpecies(fitname, "ttbar_ee",  "ttbar Component to ee ");
  theIFit->addSpecies(fitname, "other_ee",  "Other Bkgs Component to ee");

  // mm
  theIFit->addSpecies(fitname, "sig_mm",    "Signal Component to mm");
  theIFit->addSpecies(fitname, "WW_mm",     "Sig Component to mm");
  theIFit->addSpecies(fitname, "ttbar_mm",  "ttbar Component to mm");
  theIFit->addSpecies(fitname, "other_mm",  "Other Bkgs Component to mm");

  // em
  theIFit->addSpecies(fitname, "sig_em",    "Signal Component to em");
  theIFit->addSpecies(fitname, "WW_em",     "Sig Component to em");
  theIFit->addSpecies(fitname, "ttbar_em",  "ttbar Component to em");
  theIFit->addSpecies(fitname, "other_em",  "Other Bkgs Component to em");

  // efficiencies from the channel -> selected channel
  RooRealVar *eff_sig_ee = new RooRealVar("eff_sig_ee","eff_sig_ee",0.5,0,1);
  RooRealVar *eff_sig_mm = new RooRealVar("eff_sig_mm","eff_sig_mm",0.5,0,1);
  RooRealVar *eff_sig_em = new RooRealVar("eff_sig_em","eff_sig_em",0.5,0,1);

  // RooRealVar *eff_WW_ee = new RooRealVar("eff_WW_ee","eff_WW_ee",0.5,0,1);
  // RooRealVar *eff_WW_mm = new RooRealVar("eff_WW_mm","eff_WW_mm",0.5,0,1);
  // RooRealVar *eff_WW_em = new RooRealVar("eff_WW_em","eff_WW_em",0.5,0,1);

  // minimize respect Higgs xsec
  RooRealVar *N_sig_2l2nu = new RooRealVar("N_sig_2l2nu","N_sig_2l2nu",0);
  theIFit->defineYield("sig_ee","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_ee));
  theIFit->defineYield("sig_mm","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_mm));
  theIFit->defineYield("sig_em","@0*@1", RooArgList(*N_sig_2l2nu,*eff_sig_em));

  // also take W+W- background as correlated between the three final states 
  // RooRealVar *N_WW_2l2nu = new RooRealVar("N_WW_2l2nu","N_WW_2l2nu",0);
  // theIFit->defineYield("WW_ee","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_ee));
  // theIFit->defineYield("WW_mm","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_mm));
  // theIFit->defineYield("WW_em","@0*@1", RooArgList(*N_WW_2l2nu,*eff_WW_em));

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
    theIFit->addPdfWName(fitname, "sig_ee",   "deltaPhi", "Cruijff",         "sig_ee_deltaPhi");
    theIFit->addPdfWName(fitname, "WW_ee",    "deltaPhi", "Cruijff",         "WW_ee_deltaPhi");
    theIFit->addPdfWName(fitname, "ttbar_ee", "deltaPhi", "Gaussian",        "ttbar_ee_deltaPhi");
    theIFit->addPdfWName(fitname, "other_ee", "deltaPhi", "Cruijff",         "other_ee_deltaPhi");

    theIFit->addPdfWName(fitname, "sig_mm",   "deltaPhi", "Cruijff",         "sig_mm_deltaPhi");
    theIFit->addPdfWName(fitname, "WW_mm",    "deltaPhi", "Cruijff",         "WW_mm_deltaPhi");
    theIFit->addPdfWName(fitname, "ttbar_mm", "deltaPhi", "Cruijff",         "ttbar_mm_deltaPhi");
    theIFit->addPdfWName(fitname, "other_mm", "deltaPhi", "Cruijff",         "other_mm_deltaPhi");

    theIFit->addPdfWName(fitname, "sig_em",   "deltaPhi", "Cruijff",         "sig_em_deltaPhi");
    theIFit->addPdfWName(fitname, "WW_em",    "deltaPhi", "Cruijff",         "WW_em_deltaPhi");
    theIFit->addPdfWName(fitname, "ttbar_em", "deltaPhi", "Cruijff",         "ttbar_em_deltaPhi");
    theIFit->addPdfWName(fitname, "other_em", "deltaPhi", "Cruijff",         "other_em_deltaPhi");
  }

  // maxPt PDF
  if(opts.getBoolVal("useMaxPt")) {
    theIFit->addPdfWName(fitname, "sig_ee",   "maxPtEle",  "Cruijff", "sig_ee_maxPt");
    theIFit->addPdfWName(fitname, "WW_ee",    "maxPtEle",  "Cruijff", "WW_ee_maxPt");
    theIFit->addPdfWName(fitname, "ttbar_ee", "maxPtEle",  "Cruijff", "ttbar_ee_maxPt");
    theIFit->addPdfWName(fitname, "other_ee", "maxPtEle",  "Cruijff", "other_ee_maxPt");

    theIFit->addPdfWName(fitname, "sig_mm",   "maxPtEle",  "Cruijff", "sig_mm_maxPt");
    theIFit->addPdfWName(fitname, "WW_mm",    "maxPtEle",  "Cruijff", "WW_mm_maxPt");
    theIFit->addPdfWName(fitname, "ttbar_mm", "maxPtEle",  "Cruijff", "ttbar_mm_maxPt");
    theIFit->addPdfWName(fitname, "other_mm", "maxPtEle",  "Cruijff", "other_mm_maxPt");

    theIFit->addPdfWName(fitname, "sig_em",   "maxPtEle",  "Cruijff", "sig_em_maxPt");
    theIFit->addPdfWName(fitname, "WW_em",    "maxPtEle",  "Cruijff", "WW_em_maxPt");
    theIFit->addPdfWName(fitname, "ttbar_em", "maxPtEle",  "Cruijff", "ttbar_em_maxPt");
    theIFit->addPdfWName(fitname, "other_em", "maxPtEle",  "Cruijff", "other_em_maxPt");
  }

  if(opts.getBoolVal("usepMET")) {
    theIFit->addPdfWName(fitname, "sig_ee",   "projMet",  "Cruijff", "sig_ee_projMet");
    theIFit->addPdfWName(fitname, "WW_ee",    "projMet",  "Cruijff", "WW_ee_projMet");
    theIFit->addPdfWName(fitname, "ttbar_ee", "projMet",  "Gaussian", "ttbar_ee_projMet");
    theIFit->addPdfWName(fitname, "other_ee", "projMet",  "Cruijff", "other_ee_projMet");

    theIFit->addPdfWName(fitname, "sig_mm",   "projMet",  "Cruijff",  "sig_mm_projMet");
    theIFit->addPdfWName(fitname, "WW_mm",    "projMet",  "Cruijff",  "WW_mm_projMet");
    theIFit->addPdfWName(fitname, "ttbar_mm", "projMet",  "Cruijff", "ttbar_mm_projMet");
    theIFit->addPdfWName(fitname, "other_mm", "projMet",  "Cruijff",  "other_mm_projMet");

    theIFit->addPdfWName(fitname, "sig_em",   "projMet",  "Cruijff",  "sig_em_projMet");
    theIFit->addPdfWName(fitname, "WW_em",    "projMet",  "Cruijff",  "WW_em_projMet");
    theIFit->addPdfWName(fitname, "ttbar_em", "projMet",  "Cruijff", "ttbar_em_projMet");
    theIFit->addPdfWName(fitname, "other_em", "projMet",  "Cruijff",  "other_em_projMet");
  }

  // final state category (called ExclJet to confuse people...)
  theIFit->addPdfWName(fitname, "sig_ee" , "finalstate", "ExclJet", "finalstate_ee");
  theIFit->addPdfCopy(fitname, "WW_ee", "finalstate", "sig_ee");
  theIFit->addPdfCopy(fitname, "ttbar_ee", "finalstate", "sig_ee");
  theIFit->addPdfCopy(fitname, "other_ee", "finalstate", "sig_ee");

  theIFit->addPdfWName(fitname, "sig_mm" , "finalstate", "ExclJet", "finalstate_mm");
  theIFit->addPdfCopy(fitname, "WW_mm", "finalstate", "sig_mm");
  theIFit->addPdfCopy(fitname, "ttbar_mm", "finalstate", "sig_mm");
  theIFit->addPdfCopy(fitname, "other_mm", "finalstate", "sig_mm");

  theIFit->addPdfWName(fitname, "sig_em" , "finalstate", "ExclJet", "finalstate_em");
  theIFit->addPdfCopy(fitname, "WW_em", "finalstate", "sig_em");
  theIFit->addPdfCopy(fitname, "ttbar_em", "finalstate", "sig_em");
  theIFit->addPdfCopy(fitname, "other_em", "finalstate", "sig_em");

  // build the fit likelihood
  RooAbsPdf *myPdf = theIFit->buildModel(fitname);

  // Initialize the fit...
  char configfile[200];
  // initalize backgrounds
  sprintf(configfile,"toyconfig/toy-ll-mH%d.config",Hmass);
  theIFit->initialize(configfile);
  // initializing signals
  sprintf(configfile,"fitconfig/H%d-ee.config",Hmass);
  theIFit->initialize(configfile);
  sprintf(configfile,"fitconfig/H%d-mm.config",Hmass);
  theIFit->initialize(configfile);
  sprintf(configfile,"fitconfig/H%d-em.config",Hmass);
  theIFit->initialize(configfile);
  // initialize mass-dependent yields
  sprintf(configfile,"toyconfig/yields-mH%d.config",Hmass);
  theIFit->initialize(configfile);

  theIFit->Print();
  theFit2[ifit] = theIFit;

}
