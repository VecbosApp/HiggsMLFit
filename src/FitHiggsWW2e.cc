int mH = 160;

void setHiggsMass(int mh) { mH = mh; }

RooDataSet *getDataSet(const char *rootfile) {

  cout << "roofitting file " << rootfile << endl;

  RooRealVar *njets = new RooRealVar("njets","njets",0,100);
  RooRealVar *dphill = new RooRealVar("dphill","#Delta#phi",0,130,"#deg");
  RooRealVar *gammaMRstar = new RooRealVar("gammaMRstar","#gamma M_{R}",0,500, "GeV/c^{2}");
  RooRealVar *R = new RooRealVar("R","R",0,1000);
  RooRealVar *baseW = new RooRealVar("baseW","baseW",0,1e+30);
  RooRealVar *weightFP = new RooRealVar("weightFP","weightFP",-1e+30,1e+30);
  //  RooRealVar *consecevent = new RooRealVar("consecevent","progressive event number",0,1e+30);   
  RooRealVar *WWSel = new RooRealVar("WWSel","WWSel",0,2);
  RooRealVar *WWSel1j = new RooRealVar("WWSel1j","WWSel1j",0,2);

  // run variables
  RooRealVar *run = new RooRealVar("run","run number",-1e+32,1e+32);
  RooRealVar *lumi = new RooRealVar("lumi","lumi section number",-1e+32,1e+32);
  RooRealVar *event = new RooRealVar("event","event number",-1e+32,1e+32);

  RooRealVar *channel = new RooRealVar("channel","channel",0,3);
  RooRealVar *dataset = new RooRealVar("dataset","dataset",-5000,10000);

  RooArgSet setHiggs(*njets,*dphill,*gammaMRstar,*R);
  RooArgSet setHiggs1(*WWSel,*WWSel1j,*run,*lumi,*event,*channel,*dataset);
  RooArgSet setWeightsMC(*baseW);
  RooArgSet setWeightsFake(*weightFP);
  setHiggs.add(setHiggs1);
  if(TString(rootfile).Contains("fake")) setHiggs.add(setWeightsFake);
  else setHiggs.add(setWeightsMC);

  TFile *file = TFile::Open(rootfile);
  TTree *tree = (TTree*)file->Get("latino");

  RooDataSet *data = 0;
  if(TString(rootfile).Contains("fake")) data = new RooDataSet("latino","latino",tree,setHiggs,"","weightFP");
  else  data = new RooDataSet("latino","latino",tree,setHiggs,"","baseW");

  return data;

}

RooDataHist *getDataHist(const char *rootfile, RooRealVar var, int nBin) {

  MLOptions opts = GetDefaultOptions();

  RooDataSet *data = getDataSet(rootfile);

  if(opts.getBoolVal("fitsf")) data = (RooDataSet*)data->reduce("channel<2");
  if(opts.getBoolVal("fitof")) data = (RooDataSet*)data->reduce("channel>=2");
  if(opts.getBoolVal("fit0j")) data = (RooDataSet*)data->reduce("WWSel");
  else data = (RooDataSet*)data->reduce("WWSel1j");

  TH1D *histo = new TH1D("histo","histo", nBin, var.getMin(), var.getMax());
  data->tree()->Project("histo",var.GetName());

  TString nameHist = TString(var.GetName()) + TString("_1DHist");

  RooDataHist *hist = new RooDataHist(nameHist.Data(),nameHist.Data(),RooArgList(var),histo);

  return hist;
}

// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("fitsf",           "H->WW->2e/mu nu", kTRUE);
  opts.addBoolOption("fitof",           "H->WW->emu2nu", kFALSE);
  opts.addBoolOption("fit0j",           "0jet bin", kTRUE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kFALSE);
  opts.addBoolOption("useGammaMR",      "Use gamma MR",                  kTRUE);
  opts.addBoolOption("useBtag",         "Use BTag",                      kFALSE);
  opts.addBoolOption("AllFit",          "Fit all species",        kFALSE);
  opts.addBoolOption("HiggsOnlyFit",    "Fit Higgs species only", kTRUE);
  opts.addBoolOption("WWOnlyFit",       "Fit WW species only",    kFALSE);
  opts.addBoolOption("topOnlyFit",      "Fit ttbar + tW species only", kFALSE);
  opts.addBoolOption("DYOnlyFit",       "Fit DY species only", kFALSE);
  opts.addBoolOption("WjetsOnlyFit",    "Fit W+jets species only", kFALSE);
  opts.addBoolOption("othersOnlyFit",   "Fit others species only", kFALSE);
  opts.addBoolOption("doNLLPlot",       "do the NLL plot",  kFALSE);

  return opts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MLFit theFit;

void myFit() {

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar *njets = new RooRealVar("njets","njets",0,2);
  RooRealVar *dphill = new RooRealVar("dphill","#Delta#phi",0,130,"#deg");
  RooRealVar *gammaMRstar = new RooRealVar("gammaMRstar","M_{R}",0,500, "GeV/c^{2}");
  RooRealVar *R = new RooRealVar("R","R",0,1000);
  RooRealVar *weight = new RooRealVar("weight","weight",-100,10000);
  RooRealVar *channel = new RooRealVar("channel","channel",0,3);

  theFit.AddFlatFileColumn(njets);
  theFit.AddFlatFileColumn(dphill);
  theFit.AddFlatFileColumn(gammaMRstar);
  theFit.AddFlatFileColumn(R);
  theFit.AddFlatFileColumn(weight);
  theFit.AddFlatFileColumn(channel);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  theFit.addSpecies("myFit", "sig",    "Signal Component");
  theFit.addSpecies("myFit", "WW",     "WW Component");
  theFit.addSpecies("myFit", "top",    "top Component");
  theFit.addSpecies("myFit", "Wjets",  "Wjets Component");
  theFit.addSpecies("myFit", "DY",     "DY Component");
  theFit.addSpecies("myFit", "others", "Others backgrounds Component");

  // final state suffix
  char finalstate[5];
  if(opts.getBoolVal("fitsf")) sprintf(finalstate,"sf");
  if(opts.getBoolVal("fitof")) sprintf(finalstate,"of");

  TList args;
  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {    
    theFit.addPdfWName("myFit", "sig",   "dphill", "Cruijff", (TString("sig_dphill")).Data());
    theFit.addPdfWName("myFit", "WW",    "dphill", "Cruijff", (TString("WW_dphill")).Data());
    theFit.addPdfWName("myFit", "top",   "dphill", "Poly2", (TString("top_dphill")).Data());
    RooDataHist *DYHist = getDataHist("results/datasets_trees_skim/Zjets_ll.root",*dphill,7);
    args.Clear();
    args.Add(DYHist);
    theFit.addPdfWName("myFit", "DY",    "dphill", "Hist", args, (TString("DY_dphill")).Data());
    theFit.addPdfWName("myFit", "Wjets", "dphill", "Gaussian", (TString("Wjets_dphill")).Data());
    if(opts.getBoolVal("fitof")) {
      theFit.addPdfWName("myFit", "others","dphill", "Expo", (TString("others_dphill")).Data());
    } else {
      RooDataHist *othersHist = getDataHist("results/datasets_trees_skim/others_ll.root",*dphill,20);
      args.Clear();
      args.Add(othersHist);
      theFit.addPdfWName("myFit", "others","dphill", "Hist", args, (TString("others_dphill")).Data());
    }
  }

  // MR
  if(opts.getBoolVal("useGammaMR")) {
    if(mH<250) theFit.addPdfWName("myFit", "sig",   "gammaMRstar",  "Cruijff", (TString("sig_gammaMRstar")).Data());
    else {
      char HiggsFile[200];
      sprintf(HiggsFile,"results/datasets_trees_skim/H%d_ll.root",mH);
      RooDataHist *HiggsHist = getDataHist(HiggsFile,*gammaMRstar,50);
      args.Clear();
      args.Add(HiggsHist);
      theFit.addPdfWName("myFit", "sig",   "gammaMRstar",  "Hist", args, (TString("sig_gammaMRstar")).Data());
    }
    if(opts.getBoolVal("fitof")) {
      theFit.addPdfWName("myFit", "WW",    "gammaMRstar",  "Cruijff", (TString("WW_gammaMRstar")).Data());
      theFit.addPdfWName("myFit", "top",   "gammaMRstar",  "Cruijff", (TString("top_gammaMRstar")).Data());
      theFit.addPdfWName("myFit", "Wjets", "gammaMRstar",  "Cruijff", (TString("Wjets_gammaMRstar")).Data());
      RooDataHist *DYHist = getDataHist("results/datasets_trees_skim/Zjets_ll.root",*gammaMRstar,10);
      args.Clear();
      args.Add(DYHist);
      theFit.addPdfWName("myFit", "DY",    "gammaMRstar",  "Hist", args, (TString("DY_gammaMRstar")).Data());
      RooDataHist *othersHist = getDataHist("results/datasets_trees_skim/others_ll.root",*gammaMRstar,25);
      args.Clear();
      args.Add(othersHist);
      theFit.addPdfWName("myFit", "others", "gammaMRstar",  "Hist", args, (TString("others_gammaMRstar")).Data());
    } else {
      RooDataHist *WWHist = getDataHist("results/datasets_trees_skim/WW_ll.root",*gammaMRstar,30);
      args.Clear();
      args.Add(WWHist);
      theFit.addPdfWName("myFit", "WW",    "gammaMRstar",  "Hist", args, (TString("WW_gammaMRstar")).Data());
      RooDataHist *TopHist = getDataHist("results/datasets_trees_skim/top_ll.root",*gammaMRstar,20);
      args.Clear();
      args.Add(TopHist);
      theFit.addPdfWName("myFit", "top",   "gammaMRstar",  "Hist", args, (TString("top_gammaMRstar")).Data());
      theFit.addPdfWName("myFit", "Wjets", "gammaMRstar",  "Cruijff", (TString("Wjets_gammaMRstar")).Data());
      RooDataHist *DYHist = getDataHist("results/datasets_trees_skim/Zjets_ll.root",*gammaMRstar,10);
      args.Clear();
      args.Add(DYHist);
      theFit.addPdfWName("myFit", "DY",    "gammaMRstar",  "Hist", args, (TString("DY_gammaMRstar")).Data());
      RooDataHist *othersHist = getDataHist("results/datasets_trees_skim/others_ll.root",*gammaMRstar,30);
      args.Clear();
      args.Add(othersHist);
      theFit.addPdfWName("myFit", "others", "gammaMRstar",  "Hist", args, (TString("others_gammaMRstar")).Data());
      cout << "Bella. DONE " << endl;
    }
  }
  
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fit the sample
void FitHiggsWW() {
  
  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // final state suffix
  char finalstate[5];
  if(opts.getBoolVal("fitsf") && (opts.getBoolVal("fit0j"))) sprintf(finalstate,"sf_0j");
  if(opts.getBoolVal("fitsf") && (!opts.getBoolVal("fit0j"))) sprintf(finalstate,"sf_1j");
  if(opts.getBoolVal("fitof") && (opts.getBoolVal("fit0j"))) sprintf(finalstate,"of_0j");
  if(opts.getBoolVal("fitof") && (!opts.getBoolVal("fit0j"))) sprintf(finalstate,"of_1j");

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results_data/datasets_trees_skim/dataset_ll.root");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/H%d_ll.root",mH);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/WW_ll.root");
  if(opts.getBoolVal("topOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/top_ll.root");
  if(opts.getBoolVal("DYOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/Zjets_ll.root");
  if(opts.getBoolVal("WjetsOnlyFit")) sprintf(datasetname,"results_data/datasets_trees_fake_skim/dataset_fake_ll.root");
  if(opts.getBoolVal("othersOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/others_ll.root");
  RooDataSet *data = getDataSet(datasetname);
  if(opts.getBoolVal("fitsf")) data = (RooDataSet*)data->reduce("channel<2");
  if(opts.getBoolVal("fitof")) data = (RooDataSet*)data->reduce("channel>=2");
  if(opts.getBoolVal("fit0j")) data = (RooDataSet*)data->reduce("WWSel");
  else data = (RooDataSet*)data->reduce("WWSel1j");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  RooAbsReal* nll = myPdf->createNLL(*data);

  // Initialize the fit...
  if(opts.getBoolVal("AllFit")) {
    char initconfigfile[200];
    // initalize backgrounds
    sprintf(initconfigfile,"fitconfig/fitHWW-%s-%dGeV.config",finalstate,mH);
    theFit.initialize(initconfigfile);
    // initializing signal
    sprintf(initconfigfile,"fitconfig/H%d-%s.config",mH,finalstate);
    theFit.initialize(initconfigfile);
  }
  if(opts.getBoolVal("HiggsOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-HiggsOnly.config");
  if(opts.getBoolVal("WWOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-WWOnly.config");
  if(opts.getBoolVal("topOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-TopOnly.config");
  if(opts.getBoolVal("DYOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-DYOnly.config");
  if(opts.getBoolVal("WjetsOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-WjetsOnly.config");
  if(opts.getBoolVal("othersOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-othersOnly.config");

  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),RooFit::FitOptions("MHTER"),
                                       RooFit::SumW2Error(kTRUE),RooFit::NumCPU(4));
  fitres->Print("V");

  // write the config file corresponding to the fit minimum
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename, "fitres/fitMinimum-%s-%dGeV.config",finalstate,mH);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-HiggsOnly.config",mH,finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-WWOnly.config",mH,finalstate);
  if(opts.getBoolVal("topOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-TopOnly.config",mH,finalstate);
  if(opts.getBoolVal("DYOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-DYOnly.config",mH,finalstate);
  if(opts.getBoolVal("WjetsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-WjetsOnly.config",mH,finalstate);
  if(opts.getBoolVal("othersOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-othersOnly.config",mH,finalstate);

  theFit.writeConfigFile(configfilename);  

  TFile *file = new TFile("fitres/fitresult.root","recreate");
  fitres->Write();
  file->Close();

  if(opts.getBoolVal("doNLLPlot")) {
    TCanvas *c = new TCanvas("c","fitResult",900,600);

    RooRealVar* Nsig = theFit.getRealPar("N_WW");
    RooAbsReal* pll = nll->createProfile(*Nsig) ;
    
    
    RooPlot *plot = Nsig->frame(0,20,20);
    pll->plotOn(plot,RooFit::ShiftToZero());
    
    plot->Draw();
    c->SaveAs("nll.eps");
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotHiggsWW(int nbins) {

  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // final state suffix
  char finalstate[5];
  if(opts.getBoolVal("fitsf") && (opts.getBoolVal("fit0j"))) sprintf(finalstate,"sf_0j");
  if(opts.getBoolVal("fitsf") && (!opts.getBoolVal("fit0j"))) sprintf(finalstate,"sf_1j");
  if(opts.getBoolVal("fitof") && (opts.getBoolVal("fit0j"))) sprintf(finalstate,"of_0j");
  if(opts.getBoolVal("fitof") && (!opts.getBoolVal("fit0j"))) sprintf(finalstate,"of_1j");

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results_data/datasets_trees_skim/dataset_ll.root");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/H%d_ll.root",mH);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/WW_ll.root");
  if(opts.getBoolVal("topOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/top_ll.root");
  if(opts.getBoolVal("DYOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/Zjets_ll.root");
  if(opts.getBoolVal("WjetsOnlyFit")) sprintf(datasetname,"results_data/datasets_trees_fake_skim/dataset_fake_ll.root");
  if(opts.getBoolVal("othersOnlyFit")) sprintf(datasetname,"results/datasets_trees_skim/others_ll.root");
  RooDataSet *data = getDataSet(datasetname);
  if(opts.getBoolVal("fitsf")) data = (RooDataSet*)data->reduce("channel<2");
  if(opts.getBoolVal("fitof")) data = (RooDataSet*)data->reduce("channel>=2");
  if(opts.getBoolVal("fit0j")) data = (RooDataSet*)data->reduce("WWSel");
  else data = (RooDataSet*)data->reduce("WWSel1j");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");


  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum-%s-%dGeV.config",finalstate,mH);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-HiggsOnly.config",mH,finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-WWOnly.config",mH,finalstate);
  if(opts.getBoolVal("topOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-TopOnly.config",mH,finalstate);
  if(opts.getBoolVal("DYOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-DYOnly.config",mH,finalstate);
  if(opts.getBoolVal("WjetsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-WjetsOnly.config",mH,finalstate);
  if(opts.getBoolVal("othersOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-othersOnly.config",mH,finalstate);
  theFit.initialize(configfilename);

  if(opts.getBoolVal("useDeltaPhi")) {
    TCanvas *c = new TCanvas("c","fitResult",900,600);
    RooPlot* MassPlot = MakePlot("dphill", &theFit, data, configfilename, nbins);

    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("#Delta#phi [deg]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    if(opts.getBoolVal("AllFit")) makeLegend();

    char epsfilename[200];
    char Rootfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-dphill-data.pdf",finalstate);
      sprintf(Rootfilename,"fit-plots/macro/%s-dphill-data.root",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-HiggsOnly-%d.pdf",finalstate,mH);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-HiggsOnly-%d.root",finalstate,mH);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-WWOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-WWOnly.root",finalstate);
    }
    if(opts.getBoolVal("topOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-topOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-topOnly.root",finalstate);
    }
    if(opts.getBoolVal("DYOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-DYOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-DYOnly.root",finalstate);
    }
    if(opts.getBoolVal("WjetsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-WjetsOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-WjetsOnly.root",finalstate);
    }
    if(opts.getBoolVal("othersOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-dphill-othersOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-dphill-othersOnly.root",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Rootfilename);
  }

  if(opts.getBoolVal("useGammaMR")) {
    TCanvas *c = new TCanvas("c","fitResult",900,600);
    RooPlot* MassPlot = MakePlot("gammaMRstar", &theFit, data, configfilename, nbins);    
    
    if(mH<250) {
      RooAbsPdf *thePdf = theFit.getPdf("myFit");
      thePdf->paramOn(MassPlot,RooFit::Layout(0.45));
      //      data->statOn(MassPlot,RooFit::Layout(0.55,0.99,0.8));
    }
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("M_{R} [GeV/c^{2}]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    if(opts.getBoolVal("AllFit")) makeLegend();

    char epsfilename[200];
    char Rootfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-MR-data.pdf",finalstate);
      sprintf(Rootfilename,"fit-plots/macro/%s-MR-data.root",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-HiggsOnly-%d.pdf",finalstate,mH);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-HiggsOnly-%d.root",finalstate,mH);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-WWOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-WWOnly.root",finalstate);
    }
    if(opts.getBoolVal("topOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-topOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-topOnly.root",finalstate);
    }
    if(opts.getBoolVal("DYOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-DYOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-DYOnly.root",finalstate);
    }
    if(opts.getBoolVal("WjetsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-WjetsOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-WjetsOnly.root",finalstate);
    }
    if(opts.getBoolVal("othersOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-MR-othersOnly.pdf",finalstate);
      sprintf(Rootfilename,"shapesHiggs/macro/%s-MR-othersOnly.root",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Rootfilename);
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, const char *configfilename, int nbins) {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar* Var = theFit->RealObservable(VarName);
  double min=Var->getMin();
  if(VarName.Contains("bTagImpPar")) min = 0.0; // restrict the btag variable to allowed range (-1000 is the default for bin 0)
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);
  
  // plot the data
  theData->plotOn(plot);
  //theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  double Ns = theFit->getRealPar("N_sig")->getVal();
  double NWW = theFit->getRealPar("N_WW")->getVal();
  double Ntop = theFit->getRealPar("N_top")->getVal();
  double NDY = theFit->getRealPar("N_DY")->getVal();
  double NWjets = theFit->getRealPar("N_Wjets")->getVal();
  double Nothers = theFit->getRealPar("N_others")->getVal();

  cout << "Ns = " << Ns << endl; 
  cout << "NWW = " << NWW << endl;
  cout << "Ntop = " << Ntop << endl;
  cout << "NDY = " << NDY << endl;
  cout << "Ntop = " << Ntop << endl;
  cout << "Nothers = " << Nothers << endl;

  theData->plotOn(plot);
  
  // plot the total likelihood
  RooAbsPdf *thePdf = theFit->getPdf("myFit");

  if(opts.getBoolVal("AllFit")) {
    thePdf->plotOn(plot, RooFit::Components("myFit_sig"), RooFit::LineColor(kRed), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::Components("myFit_WW"), RooFit::LineColor(kAzure-9), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::Components("myFit_top"), RooFit::LineColor(kYellow+3), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::Components("myFit_DY"), RooFit::LineColor(kGreen+2), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::Components("myFit_Wjets"), RooFit::LineColor(kGray+1), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::Components("myFit_others"), RooFit::LineColor(kAzure-2), RooFit::LineWidth(2) );       
    thePdf->plotOn(plot, RooFit::LineColor(kBlack) );
  }

  if(opts.getBoolVal("HiggsOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kRed+1) );
  if(opts.getBoolVal("WWOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kAzure-9) );
  if(opts.getBoolVal("topOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kYellow+3) );
  if(opts.getBoolVal("DYOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kGreen+2) );
  if(opts.getBoolVal("WjetsOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kGray+1) );
  if(opts.getBoolVal("othersOnlyFit")) thePdf->plotOn(plot, RooFit::LineColor(kAzure-2) );

  //theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );


  return plot;
}

void makeLegend() {
  // Legend
  TH1F *dataH = new TH1F("dataH","dataH",1,0,1);
  TH1F *totalH = new TH1F("totalH","totalH",1,0,1);
  TH1F *HiggsH = new TH1F("HiggsH","HiggsH",1,0,1);
  TH1F *WWH = new TH1F("WWH","WWH",1,0,1);
  TH1F *topH = new TH1F("topH","topH",1,0,1);
  TH1F *DYH = new TH1F("DYH","DYH",1,0,1);
  TH1F *WjetsH = new TH1F("WjetsH","WjetsH",1,0,1);
  TH1F *othersH = new TH1F("othersH","othersH",1,0,1);

  dataH->SetMarkerColor(kBlack);
  totalH->SetLineColor(kBlack);
  HiggsH->SetLineColor(kRed);
  WWH->SetLineColor(kPink+3);
  topH->SetLineColor(kBlue+2);
  DYH->SetLineColor(kBlue+2);
  WjetsH->SetLineColor(kBlue+2);
  othersH->SetLineColor(kViolet);


  TLegendEntry *legge;
  TLegend *leg;
  leg = new TLegend(0.5,0.5,0.95,0.9);
  leg->SetFillStyle(0); leg->SetBorderSize(0.); leg->SetTextSize(0.025);
  leg->SetFillColor(0);
  legge = leg->AddEntry(dataH,"Data", "lpe");
  legge = leg->AddEntry(totalH,"total","l");
  legge = leg->AddEntry(HiggsH,"H #rightarrow WW","l");
  legge = leg->AddEntry(WWH,"WW","l");
  legge = leg->AddEntry(topH,"t #bar{t}","l");
  legge = leg->AddEntry(DYH,"DY","l");
  legge = leg->AddEntry(WjetsH,"W+jets","l");
  legge = leg->AddEntry(othersH,"WZ,ZZ","l");
  leg->Draw();
  gPad->Update();
}

void sPlotHiggsWW(char *useOpt) {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();
  opts.setBoolVal(useOpt,kFALSE);

  // final state suffix
  char finalstate[5];
  if(opts.getBoolVal("fitee")) sprintf(finalstate,"ee");
  if(opts.getBoolVal("fitmm")) sprintf(finalstate,"mm");
  if(opts.getBoolVal("fitem")) sprintf(finalstate,"em");

  myFit();

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) {
    if(opts.getBoolVal("fitee")) sprintf(datasetname,"results_data/datasets/dataset_eg_ee.root");
    if(opts.getBoolVal("fitmm")) sprintf(datasetname,"results_data/datasets/dataset_mu_mm.root");
    if(opts.getBoolVal("fitem")) sprintf(datasetname,"results_data/datasets/dataset_muAndEg_em.root");
  }
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");
  data->reduce("jetcat==1");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum-%s-%dGeV.config",finalstate,mH);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-HiggsOnly.config"mH,finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-WWOnly.config"mH,finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-TTbarOnly.config"mH,finalstate);
  if(opts.getBoolVal("othersOnlyFit")) sprintf(configfilename, "fitres/fitMinimum%d-%s-othersOnly.config"mH,finalstate);
  theFit.initialize(configfilename);
  
  // fix all parameters, float the yields and fit
  theFit._parameterSet.selectByName("*")->setAttribAll("Constant",kTRUE);
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_sig")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_WW")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_ttbar")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_others")))->setConstant(kFALSE) ;

  RooFitResult *fitres =  myPdf->fitTo(*data,RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),RooFit::FitOptions("MHTER"),
                                       RooFit::SumW2Error(kTRUE),RooFit::NumCPU(4));
  fitres->Print("V");

  // add appropriate column to dataset
  RooArgList yieldsList;
  cout << "Fit fraclist: " << endl;
  theFit._fracList.Print("V");
  cout << "Fit fraclist end" << endl;
  yieldsList.add(*theFit._fracList.find("N_sig"));
  yieldsList.add(*theFit._fracList.find("N_WW"));
  yieldsList.add(*theFit._fracList.find("N_ttbar"));
  yieldsList.add(*theFit._fracList.find("N_others"));

  yieldsList.Print();

  RooDataSet* dsnew = MLSPlot::addSWeightToData((RooSimultaneous*)(myPdf), yieldsList, *data, 
                                                theFit.getNoNormVars("myFit")) ;
  
  char outfilename[200];
  sprintf(outfilename,"results_data/sPlot/sPlot-%s_muAndEg_em.root",useOpt);
  TFile sPlots(outfilename,"recreate");
  dsnew->tree()->Write();
  sPlots.Close();

}


