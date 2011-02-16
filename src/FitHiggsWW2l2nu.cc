// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("weightedDataset", "use event weight instead of 1", kFALSE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kFALSE);
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
  RooRealVar *eff_ee = new RooRealVar("eff_ee","eff_ee",0.5,0,1);
  RooRealVar *eff_mm = new RooRealVar("eff_mm","eff_mm",0.5,0,1);
  RooRealVar *eff_em = new RooRealVar("eff_em","eff_em",0.5,0,1);

  // minimize respect Higgs xsec
  RooRealVar *N_sig_2l2nu = new RooRealVar("N_sig_2l2nu","N_sig_2l2nu",0);
  theFit.defineYield("sig_ee","@0*@1",RooArgList(*N_sig_2l2nu,*eff_ee)); // eff means eff * BR(2l->2e)
  theFit.defineYield("sig_mm","@0*@1",RooArgList(*N_sig_2l2nu,*eff_mm)); // " "
  theFit.defineYield("sig_em","@0*@1",RooArgList(*N_sig_2l2nu,*eff_em)); // " "

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
    theFit.addPdfWName("myFit", "ttbar_ee", "projMet",  "Cruijff", "ttbar_ee_projMet");
    theFit.addPdfWName("myFit", "other_ee", "projMet",  "Cruijff", "other_ee_projMet");

    theFit.addPdfWName("myFit", "sig_mm",   "projMet",  "Cruijff",  "sig_mm_projMet");
    theFit.addPdfWName("myFit", "WW_mm",    "projMet",  "Cruijff",  "WW_mm_projMet");
    theFit.addPdfWName("myFit", "ttbar_mm", "projMet",  "Gaussian", "ttbar_mm_projMet");
    theFit.addPdfWName("myFit", "other_mm", "projMet",  "Cruijff",  "other_mm_projMet");

    theFit.addPdfWName("myFit", "sig_em",   "projMet",  "Cruijff",  "sig_em_projMet");
    theFit.addPdfWName("myFit", "WW_em",    "projMet",  "Cruijff",  "WW_em_projMet");
    theFit.addPdfWName("myFit", "ttbar_em", "projMet",  "Gaussian", "ttbar_em_projMet");
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

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fit the sample
void FitHiggsWW() {
  
  myFit();

  // Various fit options...
  MLOptions opts = GetDefaultOptions();

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results_data/datasets/dataset_muAndEg_ll.root");
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");
  data->reduce("jetcat==1");

  // use event weights
  if(opts.getBoolVal("weightedDataset")) data->setWeightVar("weight");

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");
  
  RooAbsReal* nll = myPdf->createNLL(*data);

  // Initialize the fit...
  if(opts.getBoolVal("AllFit")) theFit.initialize("fitconfig/fitHWW-ll-160GeV.config");

  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,RooFit::ConditionalObservables(theFit.getNoNormVars("myFit")),RooFit::FitOptions("MHTER"),
                                       RooFit::SumW2Error(kTRUE));
  fitres->Print("V");

  // write the config file corresponding to the fit minimum
  theFit.writeConfigFile("fitres/fitMinimum-ll-160GeV.config");  

  TFile *file = new TFile("fitres/fitresult-ll.root","recreate");
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

  // Load the data
  char datasetname[200];
  if(opts.getBoolVal("AllFit")) sprintf(datasetname,"results_data/datasets/dataset_muAndEg_ll.root");
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");
  data->reduce("jetcat==1");

  bool usePoissonError=true;
  // use event weights
  if(opts.getBoolVal("weightedDataset")) {
    data->setWeightVar("weight");
    usePoissonError=false;
  }

  // build the fit likelihood
  RooAbsPdf *myPdf = theFit.buildModel("myFit");


  // Initialize the fit...
  theFit.initialize("fitres/fitMinimum-ll-160GeV.config");

  if(opts.getBoolVal("useDeltaPhi")) {
    TCanvas *c = new TCanvas("c","fitResult",900,600);
    RooPlot* MassPlot = MakePlot("expCosDphi", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("e^{cos(#Delta#phi)}");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    makeLegend();

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
    TCanvas *c = new TCanvas("c","fitResult",900,600);
    RooPlot* MassPlot = MakePlot("maxPtEle", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("p_{T}^{max} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    makeLegend();

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
    TCanvas *c = new TCanvas("c","fitResult",900,600);
    RooPlot* MassPlot = MakePlot("projMet", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("proj. missing E_{T} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    makeLegend();

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

  thePdf->plotOn(plot, RooFit::Components("myFit_sig"), RooFit::LineColor(kRed), RooFit::LineWidth(2) );       
  thePdf->plotOn(plot, RooFit::Components("myFit_WW"), RooFit::LineColor(kPink+3), RooFit::LineWidth(2) );       
  thePdf->plotOn(plot, RooFit::Components("myFit_ttbar"), RooFit::LineColor(kBlue+2), RooFit::LineWidth(2) );       
  thePdf->plotOn(plot, RooFit::Components("myFit_other"), RooFit::LineColor(kViolet), RooFit::LineWidth(2) );       

  thePdf->plotOn(plot, RooFit::LineColor(kBlack) );

  if(poissonError)
    theData->plotOn(plot);
  else 
    theData->plotOn(plot, RooFit::DataError(RooAbsData::SumW2) );


  return plot;
}

void makeLegend() {
  // Legend
  TH1F *dataH = new TH1F("dataH","dataH",1,0,1);
  TH1F *totalH = new TH1F("totalH","totalH",1,0,1);
  TH1F *HiggsH = new TH1F("HiggsH","HiggsH",1,0,1);
  TH1F *WWH = new TH1F("WWH","WWH",1,0,1);
  TH1F *ttbarH = new TH1F("ttbarH","ttbarH",1,0,1);
  TH1F *otherH = new TH1F("otherH","otherH",1,0,1);

  dataH->SetMarkerColor(kBlack);
  totalH->SetLineColor(kBlack);
  HiggsH->SetLineColor(kRed);
  WWH->SetLineColor(kPink+3);
  ttbarH->SetLineColor(kBlue+2);
  otherH->SetLineColor(kViolet);


  TLegendEntry *legge;
  TLegend *leg;
  leg = new TLegend(0.5,0.5,0.95,0.9);
  leg->SetFillStyle(0); leg->SetBorderSize(0.); leg->SetTextSize(0.025);
  leg->SetFillColor(0);
  legge = leg->AddEntry(dataH,"Data", "lpe");
  legge = leg->AddEntry(totalH,"total","l");
  legge = leg->AddEntry(HiggsH,"H #rightarrow WW","l");
  legge = leg->AddEntry(WWH,"WW","l");
  legge = leg->AddEntry(ttbarH,"t #bar{t}","l");
  legge = leg->AddEntry(otherH,"other","l");
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
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum-%s-160GeV.config",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-HiggsOnly.config",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-WWOnly.config",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-TTbarOnly.config",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "fitres/fitMinimum160-%s-otherOnly.config",finalstate);
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

  yieldsList.Print();

  RooDataSet* dsnew = MLSPlot::addSWeightToData((RooSimultaneous*)(myPdf), yieldsList, *data, 
                                                theFit.getNoNormVars("myFit")) ;
  
  char outfilename[200];
  sprintf(outfilename,"results_data/sPlot/sPlot-%s_muAndEg_em.root",useOpt);
  TFile sPlots(outfilename,"recreate");
  dsnew->tree()->Write();
  sPlots.Close();

}
