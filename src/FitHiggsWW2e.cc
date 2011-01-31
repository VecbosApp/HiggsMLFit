// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("fitee",           "H->WW->2e2nu", kFALSE);
  opts.addBoolOption("fitmm",           "H->WW->2m2nu", kFALSE);
  opts.addBoolOption("fitem",           "H->WW->emu2nu", kTRUE);
  opts.addBoolOption("weightedDataset", "use event weight instead of 1", kTRUE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMaxPt",        "Use pT of the hardest leptons", kTRUE);
  opts.addBoolOption("usepMET",         "Use Projected MET",             kTRUE);
  opts.addBoolOption("useMll",          "Use Mll",                       kFALSE);
  opts.addBoolOption("useBtag",         "Use jet impact parameters",     kFALSE);
  opts.addBoolOption("AllFit",          "Fit all species",        kFALSE);
  opts.addBoolOption("HiggsOnlyFit",    "Fit Higgs species only", kTRUE);
  opts.addBoolOption("WWOnlyFit",       "Fit WW species only",    kFALSE);
  opts.addBoolOption("ttbarOnlyFit",    "Fit ttbar species only", kFALSE);
  opts.addBoolOption("otherOnlyFit",    "Fit other species only", kFALSE);

  return opts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MLFit theFit;

void myFit() {

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
    if(opts.getBoolVal("fitmm")) theFit.addPdfWName("myFit", "ttbar", "expCosDphi", "Poly2",  "ttbar_deltaPhi");
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

  // mll PDF
  if(opts.getBoolVal("useMll")) {
    theFit.addPdfWName("myFit", "sig",   "eleInvMass",  "Cruijff", "sig_mll");
    theFit.addPdfWName("myFit", "WW",    "eleInvMass",  "DoubleGaussian", "WW_mll");
    theFit.addPdfWName("myFit", "ttbar", "eleInvMass",  "Poly2", "ttbar_mll");
    theFit.addPdfWName("myFit", "other", "eleInvMass",  "Cruijff", "other_mll");
  }

  if(opts.getBoolVal("usepMET")) {
    theFit.addPdfWName("myFit", "sig",   "projMet",  "Cruijff", "sig_projMet");
    theFit.addPdfWName("myFit", "WW",    "projMet",  "Cruijff", "WW_projMet");
    if(!opts.getBoolVal("fitee")) theFit.addPdfWName("myFit", "ttbar", "projMet",  "Cruijff", "ttbar_projMet");
    else theFit.addPdfWName("myFit", "ttbar", "projMet",  "Gaussian", "ttbar_projMet");
    theFit.addPdfWName("myFit", "other", "projMet",  "Cruijff", "other_projMet");
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
  if(opts.getBoolVal("fitee")) sprintf(finalstate,"ee");
  if(opts.getBoolVal("fitmm")) sprintf(finalstate,"mm");
  if(opts.getBoolVal("fitem")) sprintf(finalstate,"em");

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results/datasets/Higgs_data_%s.root",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets/H160_%s.root",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets/WW_%s.root",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(datasetname,"results/datasets/top_%s.root",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(datasetname,"results/datasets/others_%s.root",finalstate);
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");
  data->reduce("jetcat==1");
  //  data = (RooDataSet*)data->reduce("bTagImpPar>0");

  // use event weights
  if(opts.getBoolVal("weightedDataset")) data->setWeightVar("weight");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  // Initialize the fit...
  if(opts.getBoolVal("AllFit")) {
    char initconfigfile[200];
    sprintf(initconfigfile,"fitconfig/fitHWW-%s.config",finalstate);
    theFit.initialize(initconfigfile);
  }
  if(opts.getBoolVal("HiggsOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-HiggsOnly.config");
  if(opts.getBoolVal("WWOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-WWOnly.config");
  if(opts.getBoolVal("ttbarOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-TTbarOnly.config");
  if(opts.getBoolVal("otherOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-otherOnly.config");

  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),RooFit::FitOptions("MHTER"),
                                       RooFit::SumW2Error(kTRUE));
  fitres->Print("V");
  
  // write the config file corresponding to the fit minimum
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename, "fitres/fitMinimum160-%s.config",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-HiggsOnly.config",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-WWOnly.config",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-TTbarOnly.config",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-otherOnly.config",finalstate);

  theFit.writeConfigFile(configfilename);  

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlotHiggsWW(int nbins) {

  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // final state suffix
  char finalstate[5];
  if(opts.getBoolVal("fitee")) sprintf(finalstate,"ee");
  if(opts.getBoolVal("fitmm")) sprintf(finalstate,"mm");
  if(opts.getBoolVal("fitem")) sprintf(finalstate,"em");

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results/datasets/Higgs_data_%s.root",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets/H160_%s.root",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets/WW_%s.root",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(datasetname,"results/datasets/top_%s.root",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(datasetname,"results/datasets/others_%s.root",finalstate);
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");
  data->reduce("jetcat==1");
  //  data = (RooDataSet*)data->reduce("bTagImpPar>0");

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
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum160-%s-160GeV.config",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-HiggsOnly.config",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-WWOnly.config",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-TTbarOnly.config",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-otherOnly.config",finalstate);
  theFit.initialize(configfilename);

  if(opts.getBoolVal("useDeltaPhi")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("expCosDphi", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("e^{cos(#Delta#phi)}");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-deltaPhi-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-deltaPhi-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-HiggsOnly-160.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-HiggsOnly-160.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-otherOnly.C",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }


  if(opts.getBoolVal("useMaxPt")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("maxPtEle", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("p_{T}^{max} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-maxPt-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-maxPt-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-HiggsOnly-160.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-HiggsOnly-160.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-otherOnly.C",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

  if(opts.getBoolVal("usepMET")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("projMet", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("proj. missing E_{T} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-projMet-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-projMet-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-projMet-HiggsOnly-160.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-projMet-HiggsOnly-160.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-projMet-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-projMet-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-projMet-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-projMet-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-projMet-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-projMet-otherOnly.C",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make the plot for a given variable
RooPlot *MakePlot(TString VarName, MLFit* theFit, RooDataSet* theData, const char *configfilename, int nbins, bool poissonError=true) {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  RooRealVar* Var = theFit->RealObservable(VarName);
  double min=Var->getMin();
  if(VarName.Contains("bTagImpPar")) min = 0.0; // restrict the btag variable to allowed range (-1000 is the default for bin 0)
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
  thePdf->plotOn(plot, RooFit::LineColor(kViolet+7) );

  if(poissonError)
    theData->plotOn(plot);
  else 
    theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );


  return plot;
}



void sPlotHiggsWW() {

  // Various fit options...
  MLOptions opts = GetDefaultOptions();
  opts.setBoolVal("useDeltaPhi",kFALSE);

  myFit();

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"datasets/Higgs_21X_data.root");
  else sprintf(datasetname,"datasets/hww_2m_Datasets_21X.root ");
  char treename[100];
  if(opts.getBoolVal("AllFit")) sprintf(treename,"theData");
  theFit.addDataSetFromRootFile(treename, treename, datasetname);

  RooDataSet *data = theFit.getDataSet(treename);

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");

  // Initialize the fit...
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum-finalstate0-160GeV.config");
  theFit.initialize(configfilename);

  
  // fix all parameters, float the yields and fit
  theFit._parameterSet.selectByName("*")->setAttribAll("Constant",kTRUE);
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_sig")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_WW")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_ttbar")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("N_other")))->setConstant(kFALSE) ;

  RooFitResult *fitres =  myPdf->fitTo(*data,RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),RooFit::FitOptions("MHTER"),
                                       RooFit::SumW2Error(kTRUE));
  fitres->Print("V");

  // add appropriate column to dataset
  RooArgList yieldsList;
  cout << "Fit fraclist: " << endl;
  theFit._fracList.Print("V");
  cout << "Fit fraclist end" << endl;
  yieldsList.add(*theFit._fracList.find("N_sig"));
  yieldsList.add(*theFit._fracList.find("N_WW"));
  yieldsList.add(*theFit._fracList.find("N_ttbar"));
  yieldsList.add(*theFit._fracList.find("N_other"));

  cout << "Macro" << endl;
  yieldsList.Print();
  cout << "End macro" << endl;

  RooDataSet* dsnew = MLSPlot::addSWeightToData((RooSimultaneous*)(myPdf), yieldsList, *data, 
                                                theFit.getNoNormVars("myFit")) ;

  TFile sPlots("sPlots-noDeltaPhi-finalstate0-mass160.root","recreate");
  dsnew->Write();
  sPlots.Close();

}
