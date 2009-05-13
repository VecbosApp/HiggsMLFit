// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("weightedDataset", "use event weight instead of 1", kTRUE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMinPt",        "Use pT of the slowest leptons", kTRUE);
  opts.addBoolOption("useMET",          "Use MET",                       kTRUE);
  opts.addBoolOption("useDxyzEVT",      "Use jet impact parameters",     kTRUE);
  opts.addBoolOption("AllFit",          "Fit all species",        kFALSE);
  opts.addBoolOption("HiggsOnlyFit",    "Fit Higgs species only", kFALSE);
  opts.addBoolOption("WWOnlyFit",       "Fit WW species only",    kFALSE);
  opts.addBoolOption("ttbarOnlyFit",    "Fit ttbar species only", kFALSE);
  opts.addBoolOption("otherOnlyFit",    "Fit other species only", kTRUE);

  return opts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MLFit theFit;

void myFit() {

  MLFit theFit;

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar *jetCat = new RooRealVar("jetCat","jetCat",-2,2);
  RooRealVar *MET = new RooRealVar("MET","MET",30,200,"GeV");
  RooRealVar *deltaPhi = new RooRealVar("deltaPhi","deltaPhi",0,180,"#circ");
  RooRealVar *minPt = new RooRealVar("minPt","minPt",10,200,"GeV");
  RooRealVar *dxyEVT = new RooRealVar("dxyEVT","dxyEVT",0,5000,"#mum");
  RooRealVar *dszEVT = new RooRealVar("dszEVT","dszEVT",0,5000,"#mum");
  RooRealVar *weight = new RooRealVar("weight","weight",0,100);

  theFit.AddFlatFileColumn(jetCat);
  theFit.AddFlatFileColumn(MET);
  theFit.AddFlatFileColumn(deltaPhi);
  theFit.AddFlatFileColumn(minPt);
  theFit.AddFlatFileColumn(dxyEVT);
  theFit.AddFlatFileColumn(dszEVT);
  theFit.AddFlatFileColumn(weight);

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

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fit the sample
void FitHiggsWW() {
  
  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"datasets/Higgs_21X_data.root");
  else sprintf(datasetname,"datasets/hww_2e_Datasets_21X.root ");
  char treename[100];
  if(opts.getBoolVal("AllFit")) sprintf(treename,"data");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(treename,"Higgs");
  if(opts.getBoolVal("WWOnlyFit")) sprintf(treename,"WW");
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(treename,"ttbar");
  if(opts.getBoolVal("otherOnlyFit")) sprintf(treename,"other");
  theFit.addDataSetFromRootFile(treename, treename, datasetname);
  RooDataSet *data = theFit.getDataSet(treename);

  // use event weights
  if(opts.getBoolVal("weightedDataset")) data->setWeightVar("weight");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit...
  if(opts.getBoolVal("AllFit")) {
    char initconfigfile[200];
    sprintf(initconfigfile,"fitconfig/fitHiggs.config");
    theFit.initialize(initconfigfile);
  }
  if(opts.getBoolVal("HiggsOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-HiggsOnly.config");
  if(opts.getBoolVal("WWOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-WWOnly.config");
  if(opts.getBoolVal("ttbarOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-TTbarOnly.config");
  if(opts.getBoolVal("otherOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-otherOnly.config");

  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,theFit.getNoNormVars("myFit"),"MHTER");
  fitres->Print("V");
  
  // write the config file corresponding to the fit minimum
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename, "fitres/fitMinimumHiggsWW.config");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-HiggsOnly.config");
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-WWOnly.config");
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-TTbarOnly.config");
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-otherOnly.config");
  theFit.writeConfigFile(configfilename);  

  // save the fit result in ROOT 
  char rootfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(rootfilename, "fitres/fitMinimumHiggsWW.root");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(rootfilename,"shapesHiggs/root/fitRes-HiggsOnly.root");
  if(opts.getBoolVal("WWOnlyFit")) sprintf(rootfilename,"shapesHiggs/root/fitRes-WWOnly.root");
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(rootfilename,"shapesHiggs/root/fitRes-TTbarOnly.root");
  if(opts.getBoolVal("otherOnlyFit")) sprintf(rootfilename,"shapesHiggs/root/fitRes-otherOnly.root");

  TFile *file = new TFile(rootfilename,"recreate");
  fitres->Write();
  file->Close();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotHiggsWW(int nbins) {

  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"datasets/Higgs_21X_data.root");
  else sprintf(datasetname,"datasets/hww_2e_Datasets_21X.root ");
  char treename[100];
  if(opts.getBoolVal("AllFit")) sprintf(treename,"data");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(treename,"Higgs");
  if(opts.getBoolVal("WWOnlyFit")) sprintf(treename,"WW");
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(treename,"ttbar");
  if(opts.getBoolVal("otherOnlyFit")) sprintf(treename,"other");
  theFit.addDataSetFromRootFile(treename, treename, datasetname);
  RooDataSet *data = theFit.getDataSet(treename);

  bool usePoissonError=true;
  // use event weights
  if(opts.getBoolVal("weightedDataset")) {
    data->setWeightVar("weight");
    usePoissonError=false;
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimumHiggsWW.config");
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-HiggsOnly.config");
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-WWOnly.config");
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-TTbarOnly.config");
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "shapesHiggs/config/fitMinimum-otherOnly.config");
  theFit.initialize(configfilename);

  // draw normalized to the full yield, not N * N_0j_eff
  theFit.getRealPar("eff_sig")->setVal(1.);  
  theFit.getRealPar("eff_WW")->setVal(1.);  
  theFit.getRealPar("eff_ttbar")->setVal(1.);  
  theFit.getRealPar("eff_other")->setVal(1.);  

  if(opts.getBoolVal("useDeltaPhi")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("deltaPhi", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("#Delta #phi [#circ]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/deltaPhi-data.eps");
      sprintf(Cfilename,"fit-plots/macro/deltaPhi-data.C");
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/deltaPhi-HiggsOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/deltaPhi-HiggsOnly.C");
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/deltaPhi-WWOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/deltaPhi-WWOnly.C");
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/deltaPhi-ttbarOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/deltaPhi-ttbarOnly.C");
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/deltaPhi-otherOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/deltaPhi-otherOnly.C");
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }


  if(opts.getBoolVal("useMinPt")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("minPt", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("p_{T}^{min} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/minPt-data.eps");
      sprintf(Cfilename,"fit-plots/macro/minPt-data.C");
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/minPt-HiggsOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/minPt-HiggsOnly.C");
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/minPt-WWOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/minPt-WWOnly.C");
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/minPt-ttbarOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/minPt-ttbarOnly.C");
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/minPt-otherOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/minPt-otherOnly.C");
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

  if(opts.getBoolVal("useMET")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("MET", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("missing E_{T} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/MET-data.eps");
      sprintf(Cfilename,"fit-plots/macro/MET-data.C");
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/MET-HiggsOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/MET-HiggsOnly.C");
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/MET-WWOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/MET-WWOnly.C");
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/MET-ttbarOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/MET-ttbarOnly.C");
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/MET-otherOnly.eps");
      sprintf(Cfilename,"shapesHiggs/macro/MET-otherOnly.C");
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, const char *configfilename, int nbins, bool poissonError=true)
{

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar* Var = theFit->RealObservable(VarName);
  double min=Var->getMin();
  double max=Var->getMax();
  RooPlot *plot = Var->frame(min,max,nbins);
  
  // plot the data
  if(poissonError)
    theData->plotOn(plot);
  else 
  theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );

  double Ns = theFit->getRealPar("N_sig")->getVal();
  double NWW = theFit->getRealPar("N_WW")->getVal();
  double Nttbar = theFit->getRealPar("N_ttbar")->getVal();
  double Nother = theFit->getRealPar("N_other")->getVal();

  cout << "Ns = " << Ns << endl; 
  cout << "NWW = " << NWW << endl;
  cout << "Nttbar = " << Nttbar << endl;
  cout << "Nother = " << Nother << endl;
  
  // plot the total likelihood
  RooAbsPdf *thePdf = theFit->getPdf("myFit");
  thePdf->plotOn(plot, RooFit::LineColor(kBlack) );


  if(opts.getBoolVal("AllFit")) {
    // === plot (dashed) the ttbar component ===
    MLFit theFit2;

    // define the structure of the dataset
    RooRealVar *jetCat = new RooRealVar("jetCat","jetCat",-2,2);
    RooRealVar *MET = new RooRealVar("MET","MET",30,200,"GeV");
    RooRealVar *deltaPhi = new RooRealVar("deltaPhi","deltaPhi",0,180,"#circ");
    RooRealVar *minPt = new RooRealVar("minPt","minPt",10,200,"GeV");
    RooRealVar *dxyEVT = new RooRealVar("dxyEVT","dxyEVT",0,5000,"#mum");
    RooRealVar *dszEVT = new RooRealVar("dszEVT","dszEVT",0,5000,"#mum");
    RooRealVar *weight = new RooRealVar("weight","weight",0,100);

    theFit2.AddFlatFileColumn(jetCat);
    theFit2.AddFlatFileColumn(MET);
    theFit2.AddFlatFileColumn(deltaPhi);
    theFit2.AddFlatFileColumn(minPt);
    theFit2.AddFlatFileColumn(dxyEVT);
    theFit2.AddFlatFileColumn(dszEVT);
    theFit2.AddFlatFileColumn(weight);

    // define a fit model
    theFit2.addModel("myFit", "Higgs to WW");

    // define species in the 0-jet bin
    theFit2.addSpecies("myFit", "ttbar_0j",  "Zero Jet ttbar Component");
    theFit2.addPdfWName("myFit", "ttbar_0j", "deltaPhi", "poly2",    "ttbar_deltaPhi");
    theFit2.addPdfWName("myFit", "ttbar_0j", "minPt",  "Cruijff", "ttbar_minPt");
    const int nbins = 8;
    double limitarray[] = {30.0,40.0,50.0,60.0,70.0,80.0,100.0,150.0,200.0};
    TAxis* limits = new TAxis(nbins,limitarray) ;
    TList args ;
    args.Add(limits);
    theFit2.addPdfWName("myFit", "ttbar_0j", "MET",  "BinnedPdf", args, "ttbar_MET");

    RooAbsPdf *myPdf2 = theFit2.buildModel("ttbarFit");
    theFit2.initialize(configfilename);

    myPdf2->plotOn(plot, RooFit::Normalization(Nttbar/(Ns+NWW+Nother+Nttbar)),RooFit::LineColor(kBlack),RooFit::LineStyle(kDashed));

    // === etc etc... for the other components: still to do...
  
  }

  return plot;
}

