// Set Fit Options
MLOptions GetDefaultOptions() {
  MLOptions opts;
  // Fit configuration
  opts.addBoolOption("fitee",           "H->WW->2e2nu", kTRUE);
  opts.addBoolOption("fitmm",           "H->WW->2m2nu", kFALSE);
  opts.addBoolOption("fitem",           "H->WW->2e2nu", kFALSE);
  opts.addBoolOption("weightedDataset", "use event weight instead of 1", kTRUE);
  opts.addBoolOption("useDeltaPhi",     "Use leptons delta phi",         kTRUE);
  opts.addBoolOption("useMaxPt",        "Use pT of the hardest leptons", kTRUE);
  opts.addBoolOption("useMET",          "Use MET",                       kTRUE);
  opts.addBoolOption("useMll",          "Use Mll",                       kTRUE);
  opts.addBoolOption("useBtag",         "Use jet impact parameters",     kFALSE);
  opts.addBoolOption("AllFit",          "Fit all species",        kFALSE);
  opts.addBoolOption("HiggsOnlyFit",    "Fit Higgs species only", kTRUE);
  opts.addBoolOption("WWOnlyFit",       "Fit WW species only",    kFALSE);
  opts.addBoolOption("ttbarOnlyFit",    "Fit ttbar species only", kFALSE);
  opts.addBoolOption("ZOnlyFit",        "Fit Z species only",     kFALSE);
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
  theFit.AddFlatFileColumn(eleInvMass);
  theFit.AddFlatFileColumn(bTagImpPar);
  theFit.AddFlatFileColumn(weight);

  // define a fit model
  theFit.addModel("myFit", "Higgs to WW");

  // define species in the 0-jet bin
  theFit.addSpecies("myFit", "WW_0j",     "Zero Jet Sig Component");
  theFit.addSpecies("myFit", "sig_0j",    "Zero Jet Signal Component");
  theFit.addSpecies("myFit", "ttbar_0j",  "Zero Jet ttbar Component");
  theFit.addSpecies("myFit", "Z_0j",      "Zero Jet Z Component");
  theFit.addSpecies("myFit", "other_0j",  "Zero Jet Other Bkgs Component");

  // define species in the 1-jet bin
  theFit.addSpecies("myFit", "sig_1j",    "One Jet Signal Component");
  theFit.addSpecies("myFit", "WW_1j",     "One Jet WW Component");
  theFit.addSpecies("myFit", "ttbar_1j",  "One Jet ttbar Component");
  theFit.addSpecies("myFit", "Z_1j",      "One Jet Z Component");
  theFit.addSpecies("myFit", "other_1j",  "One Jet Other Bkgs Component");

  theFit.fitWithEff("sig_0j",   "sig_1j",   "sig");
  theFit.fitWithEff("WW_0j",    "WW_1j",    "WW");
  theFit.fitWithEff("ttbar_0j", "ttbar_1j", "ttbar");
  theFit.fitWithEff("Z_0j",     "Z_1j",     "Z");
  theFit.fitWithEff("other_0j", "other_1j", "other");

  // deltaPhi PDF
  if(opts.getBoolVal("useDeltaPhi")) {
    theFit.addPdfWName("myFit", "sig_0j",   "deltaPhi", "Cruijff",         "sig_deltaPhi");
    theFit.addPdfWName("myFit", "WW_0j",    "deltaPhi", "Cruijff",         "WW_deltaPhi");
    theFit.addPdfWName("myFit", "ttbar_0j", "deltaPhi", "Poly2",           "ttbar_deltaPhi");
    theFit.addPdfWName("myFit", "Z_0j",     "deltaPhi", "Cruijff",         "Z_deltaPhi");
    theFit.addPdfWName("myFit", "other_0j", "deltaPhi", "Cruijff",         "other_deltaPhi");

    theFit.addPdfCopy("myFit", "sig_1j",   "deltaPhi", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "deltaPhi", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "deltaPhi", "ttbar_0j");
    theFit.addPdfCopy("myFit", "Z_1j",     "deltaPhi", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "deltaPhi", "other_0j");
  }

  // maxPt PDF
  if(opts.getBoolVal("useMaxPt")) {
    theFit.addPdfWName("myFit", "sig_0j",   "maxPtEle",  "Cruijff", "sig_maxPt");
    theFit.addPdfWName("myFit", "WW_0j",    "maxPtEle",  "Cruijff", "WW_maxPt");
    theFit.addPdfWName("myFit", "ttbar_0j", "maxPtEle",  "Cruijff", "ttbar_maxPt");
    theFit.addPdfWName("myFit", "Z_0j",     "maxPtEle",  "Cruijff", "Z_maxPt");
    theFit.addPdfWName("myFit", "other_0j", "maxPtEle",  "Cruijff", "other_maxPt");

    theFit.addPdfCopy("myFit", "sig_1j",   "maxPtEle", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "maxPtEle", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "maxPtEle", "ttbar_0j");
    theFit.addPdfCopy("myFit", "Z_1j",     "maxPtEle", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "maxPtEle", "other_0j");
  }

  // mll PDF
  if(opts.getBoolVal("useMll")) {
    theFit.addPdfWName("myFit", "sig_0j",   "eleInvMass",  "Cruijff", "sig_mll");
    theFit.addPdfWName("myFit", "WW_0j",    "eleInvMass",  "DoubleGaussian", "WW_mll");
    theFit.addPdfWName("myFit", "ttbar_0j", "eleInvMass",  "Poly2", "ttbar_mll");
    theFit.addPdfWName("myFit", "Z_0j",     "eleInvMass",  "Cruijff", "Z_mll");
    theFit.addPdfWName("myFit", "other_0j", "eleInvMass",  "Cruijff", "other_mll");

    theFit.addPdfCopy("myFit", "sig_1j",   "eleInvMass", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "eleInvMass", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "eleInvMass", "ttbar_0j");
    theFit.addPdfCopy("myFit", "Z_1j",     "eleInvMass", "Z_0j");
    theFit.addPdfCopy("myFit", "other_1j", "eleInvMass", "other_0j");
  }

  // met PDF
  // use histogram PDF to limit sensitivity to the tail
//   const int nbinsMET = 12;
//   double limitarrayMET[] = {0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0,4 0.0, 50.0, 60.0, 70.0, 100., 200.0};

//   TAxis* limitsMET = new TAxis(nbinsMET,limitarrayMET) ;
//   TList argsMET ;
//   argsMET.Add(limitsMET);

//   if(opts.getBoolVal("useMET")) {
//     theFit.addPdfWName("myFit", "sig_0j",   "met",  "BinnedPdf", argsMET, "sig_met");
//     theFit.addPdfWName("myFit", "WW_0j",    "met",  "BinnedPdf", argsMET, "WW_met");
//     theFit.addPdfWName("myFit", "ttbar_0j", "met",  "BinnedPdf", argsMET, "ttbar_met");
//     theFit.addPdfWName("myFit", "Z_0j",     "met",  "BinnedPdf", argsMET, "Z_met");
//     theFit.addPdfWName("myFit", "other_0j", "met",  "BinnedPdf", argsMET, "other_met");

//     theFit.addPdfCopy("myFit", "sig_1j",   "met", "sig_0j");
//     theFit.addPdfCopy("myFit", "WW_1j",    "met", "WW_0j");
//     theFit.addPdfCopy("myFit", "ttbar_1j", "met", "ttbar_0j");
//     theFit.addPdfCopy("myFit", "Z_1j",     "met", "Z_0j");
//     theFit.addPdfCopy("myFit", "other_1j", "met", "other_0j");
//   }

  if(opts.getBoolVal("useMET")) {
    theFit.addPdfWName("myFit", "sig_0j",   "met",  "Cruijff", "sig_met");
    theFit.addPdfWName("myFit", "WW_0j",    "met",  "DoubleGaussian", "WW_met");
    theFit.addPdfWName("myFit", "ttbar_0j", "met",  "Cruijff", "ttbar_met");
    theFit.addPdfWName("myFit", "Z_0j",     "met",  "Cruijff", "Z_met");
    theFit.addPdfWName("myFit", "other_0j", "met",  "Cruijff", "other_met");

    theFit.addPdfCopy("myFit", "sig_1j",   "met", "sig_0j");
    theFit.addPdfCopy("myFit", "WW_1j",    "met", "WW_0j");
    theFit.addPdfCopy("myFit", "ttbar_1j", "met", "ttbar_0j");
    theFit.addPdfCopy("myFit", "Z_1j",     "met", "Z_0j");
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
    theFit.addPdfWName("myFit", "Z_0j",     "NoPdf",  "Z_0j_btag");
    theFit.addPdfWName("myFit", "other_0j", "NoPdf",  "other_0j_btag");

    theFit.addPdfWName("myFit", "sig_1j",   "bTagImpPar", "BinnedPdf",  argsBtag, "sig_1j_btag");
    theFit.addPdfWName("myFit", "WW_1j",    "bTagImpPar", "BinnedPdf",  argsBtag, "WW_1j_btag");
    theFit.addPdfWName("myFit", "ttbar_1j", "bTagImpPar", "BinnedPdf",  argsBtag, "ttbar_1j_btag");
    theFit.addPdfWName("myFit", "Z_1j",     "bTagImpPar", "BinnedPdf",  argsBtag, "Z_1j_btag");
    theFit.addPdfWName("myFit", "other_1j", "bTagImpPar", "BinnedPdf",  argsBtag, "other_1j_btag");

  }

  // jet bin category: val =  1 --> Njets = 0
  //                   val = -1 --> Njets = 1
  theFit.addPdfWName("myFit", "sig_0j" ,   "jetcat",  "Poly2",  "Nj_0");
  theFit.addPdfCopy("myFit",  "WW_0j",     "jetcat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "ttbar_0j",  "jetcat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "Z_0j",      "jetcat",  "sig_0j");
  theFit.addPdfCopy("myFit",  "other_0j",  "jetcat",  "sig_0j");
                                            
  theFit.addPdfWName("myFit", "sig_1j" ,   "jetcat",  "Poly2",  "Nj_1");
  theFit.addPdfCopy("myFit",  "WW_1j",     "jetcat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "ttbar_1j",  "jetcat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "Z_1j",      "jetcat",  "sig_1j");
  theFit.addPdfCopy("myFit",  "other_1j",  "jetcat",  "sig_1j");

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
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets/H165_%s.root",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets/WW_%s.root",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(datasetname,"results/datasets/TTbarJetsMadgraph_%s.root",finalstate);
  if(opts.getBoolVal("ZOnlyFit")) sprintf(datasetname,"results/datasets/Zspecies_%s.root",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(datasetname,"results/datasets/others_%s.root",finalstate);
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");

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
  if(opts.getBoolVal("ZOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-ZOnly.config");
  if(opts.getBoolVal("otherOnlyFit")) theFit.initialize("shapesHiggs/config/HiggsWWFit-otherOnly.config");

  // Print Fit configuration 
  myPdf->getParameters(data)->selectByAttrib("Constant",kTRUE)->Print("V");  
  myPdf->getParameters(data)->selectByAttrib("Constant",kFALSE)->Print("V");
  
  RooFitResult *fitres =  myPdf->fitTo(*data,theFit.getNoNormVars("myFit"),"MHTER");
  fitres->Print("V");
  
  // write the config file corresponding to the fit minimum
  char configfilename[200];
  if(opts.getBoolVal("AllFit")) sprintf(configfilename, "fitres/fitMinimum-%s.config",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-HiggsOnly.config",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-WWOnly.config",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-TTbarOnly.config",finalstate);
  if(opts.getBoolVal("ZOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-ZOnly.config",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-otherOnly.config",finalstate);

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
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(datasetname,"results/datasets/H165_%s.root",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(datasetname,"results/datasets/WW_%s.root",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(datasetname,"results/datasets/TTbarJetsMadgraph_%s.root",finalstate);
  if(opts.getBoolVal("ZOnlyFit")) sprintf(datasetname,"results/datasets/Zspecies_%s.root",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(datasetname,"results/datasets/others_%s.root",finalstate);
  theFit.addDataSetFromRootFile("T1", "T1", datasetname);
  RooDataSet *data = theFit.getDataSet("T1");

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
  if(opts.getBoolVal("AllFit")) sprintf(configfilename,"fitres/fitMinimum-%s-160GeV.config",finalstate);
  if(opts.getBoolVal("HiggsOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-HiggsOnly.config",finalstate);
  if(opts.getBoolVal("WWOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-WWOnly.config",finalstate);
  if(opts.getBoolVal("ttbarOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-TTbarOnly.config",finalstate);
  if(opts.getBoolVal("ZOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-ZOnly.config",finalstate);
  if(opts.getBoolVal("otherOnlyFit")) sprintf(configfilename, "fitres/fitMinimum-%s-otherOnly.config",finalstate);
  theFit.initialize(configfilename);

  // draw normalized to the full yield, not N * N_0j_eff
  theFit.getRealPar("eff_sig")->setVal(1.);  
  theFit.getRealPar("eff_WW")->setVal(1.);  
  theFit.getRealPar("eff_ttbar")->setVal(1.);  
  theFit.getRealPar("eff_Z")->setVal(1.);  
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
      sprintf(epsfilename,"fit-plots/eps/%s-deltaPhi-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-deltaPhi-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-HiggsOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-HiggsOnly.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("ZOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ZOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ZOnly.C",finalstate);
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
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-HiggsOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-HiggsOnly.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("ZOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ZOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ZOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-maxPt-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-maxPt-otherOnly.C",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

  if(opts.getBoolVal("useMET")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("met", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("missing E_{T} [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-met-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-met-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-met-HiggsOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-met-HiggsOnly.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-met-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-met-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-met-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-met-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("ZOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ZOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ZOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-met-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-met-otherOnly.C",finalstate);
    }
    c->SaveAs(epsfilename);
    c->SaveAs(Cfilename);
  }

  if(opts.getBoolVal("useMll")) {
    TCanvas *c = new TCanvas("c","fitResult");
    RooPlot* MassPlot = MakePlot("eleInvMass", &theFit, data, configfilename, nbins, usePoissonError);    
    
    MassPlot->SetAxisColor(1,"x");
    MassPlot->SetLabelColor(1, "X");
    MassPlot->SetLabelColor(1, "Y");
    MassPlot->SetXTitle("m(l^{+}l^{-}) [GeV]");

    MassPlot->SetYTitle("Events");
    MassPlot->Draw();

    char epsfilename[200];
    char Cfilename[200];

    if(opts.getBoolVal("AllFit")) {
      sprintf(epsfilename,"fit-plots/eps/%s-mll-data.eps",finalstate);
      sprintf(Cfilename,"fit-plots/macro/%s-mll-data.C",finalstate);
    }
    if(opts.getBoolVal("HiggsOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-mll-HiggsOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-mll-HiggsOnly.C",finalstate);
    }
    if(opts.getBoolVal("WWOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-mll-WWOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-mll-WWOnly.C",finalstate);
    }
    if(opts.getBoolVal("ttbarOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-mll-ttbarOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-mll-ttbarOnly.C",finalstate);
    }
    if(opts.getBoolVal("ZOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-deltaPhi-ZOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-deltaPhi-ZOnly.C",finalstate);
    }
    if(opts.getBoolVal("otherOnlyFit")) {
      sprintf(epsfilename,"shapesHiggs/eps/%s-mll-otherOnly.eps",finalstate);
      sprintf(Cfilename,"shapesHiggs/macro/%s-mll-otherOnly.C",finalstate);
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


//   if(opts.getBoolVal("AllFit")) {
//     // === plot (dashed) the WW component ===
//     MLFit theFit2;
    
//     RooRealVar *jetcat = new RooRealVar("jetcat","jetcat",-1,1); // cut the -2 ( >1 jet )
//     RooRealVar *met    = new RooRealVar("met","E_{T}^{miss}",0,200,"GeV");
//     RooRealVar *deltaPhi = new RooRealVar("deltaPhi","#Delta#phi",0,180,"#deg");
//     RooRealVar *maxPtEle = new RooRealVar("maxPtEle","p_{T}^{max}",20,200,"GeV");
//     RooRealVar *eleInvMass = new RooRealVar("eleInvMass","m(l^{+}l^{-})",12,150,"GeV");
//     RooRealVar *bTagImpPar = new RooRealVar("bTagImpPar","b-tag",-1001.,2.0);
//     RooRealVar *weight = new RooRealVar("weight","weight",0,10000);
    
//     theFit2.AddFlatFileColumn(jetcat);
//     theFit2.AddFlatFileColumn(met);
//     theFit2.AddFlatFileColumn(deltaPhi);
//     theFit2.AddFlatFileColumn(maxPtEle);
//     theFit2.AddFlatFileColumn(eleInvMass);
//     theFit2.AddFlatFileColumn(bTagImpPar);
//     theFit2.AddFlatFileColumn(weight);

//     // define a fit model
//     theFit2.addModel("WWFit", "WW only component fit");

//     // define species in the 0-jet bin
//     theFit2.addSpecies("WWFit", "WW",  "WW Component");
//     theFit2.addPdfWName("WWFit", "WW", "deltaPhi", "Cruijff",    "WW_deltaPhi");
//     theFit2.addPdfWName("WWFit", "WW", "maxPt",  "Cruijff", "WW_maxPt");
//     const int nbins = 8;
//     double limitarray[] = {30.0,40.0,50.0,60.0,70.0,80.0,100.0,150.0,200.0};
//     TAxis* limits = new TAxis(nbins,limitarray) ;
//     TList args ;
//     args.Add(limits);
//     theFit2.addPdfWName("WWFit", "WW", "met",  "BinnedPdf", args, "WW_met");

//     RooAbsPdf *myPdf2 = theFit2.buildModel("WWFit");
//     theFit2.initialize(configfilename);

//     myPdf2->plotOn(plot, RooFit::Normalization(NWW/(Ns+NWW+Nother+Nttbar)),RooFit::LineColor(kBlack),RooFit::LineStyle(kDashed));

//     // ===  plot (dashed) the ttbar component ===
//     MLFit theFit3;

//     theFit3.AddFlatFileColumn(jetCat);
//     theFit3.AddFlatFileColumn(met);
//     theFit3.AddFlatFileColumn(deltaPhi);
//     theFit3.AddFlatFileColumn(maxPt);
//     theFit3.AddFlatFileColumn(dxyEVT);
//     theFit3.AddFlatFileColumn(dszEVT);
//     theFit3.AddFlatFileColumn(weight);

//     // define a fit model
//     theFit3.addModel("ttbarFit", "ttbar only component fit");

//     // define species in the 0-jet bin
//     theFit3.addSpecies("ttbarFit", "ttbar",  "ttbar Component");
//     theFit3.addPdfWName("ttbarFit", "ttbar", "deltaPhi", "Poly2",    "ttbar_deltaPhi");
//     theFit3.addPdfWName("ttbarFit", "ttbar", "maxPt",  "Cruijff", "ttbar_maxPt");
//     const int nbins = 8;
//     double limitarray[] = {30.0,40.0,50.0,60.0,70.0,80.0,100.0,150.0,200.0};
//     TAxis* limits = new TAxis(nbins,limitarray) ;
//     TList args ;
//     args.Add(limits);
//     theFit3.addPdfWName("ttbarFit", "ttbar", "met",  "BinnedPdf", args, "ttbar_met");

//     RooAbsPdf *myPdf3 = theFit3.buildModel("ttbarFit");
//     theFit3.initialize(configfilename);

//     myPdf3->plotOn(plot, RooFit::Normalization(Nttbar/(Ns+NWW+Nother+Nttbar)),RooFit::LineColor(kBlack),RooFit::LineStyle(kDotted));



//     // ===  plot (dashed) the ttbar component ===
//     MLFit theFit4;

//     theFit4.AddFlatFileColumn(jetCat);
//     theFit4.AddFlatFileColumn(met);
//     theFit4.AddFlatFileColumn(deltaPhi);
//     theFit4.AddFlatFileColumn(maxPt);
//     theFit4.AddFlatFileColumn(dxyEVT);
//     theFit4.AddFlatFileColumn(dszEVT);
//     theFit4.AddFlatFileColumn(weight);

//     // define a fit model
//     theFit4.addModel("otherFit", "other only component fit");

//     // define species in the 0-jet bin
//     theFit4.addSpecies("otherFit", "other",  "other Component");
//     theFit4.addPdfWName("otherFit", "other", "deltaPhi", "DoubleGaussian",    "other_deltaPhi");
//     theFit4.addPdfWName("otherFit", "other", "maxPt",  "Cruijff", "other_maxPt");
//     const int nbins = 8;
//     double limitarray[] = {30.0,40.0,50.0,60.0,70.0,80.0,100.0,150.0,200.0};
//     TAxis* limits = new TAxis(nbins,limitarray) ;
//     TList args ;
//     args.Add(limits);
//     theFit4.addPdfWName("otherFit", "other", "met",  "BinnedPdf", args, "other_met");

//     RooAbsPdf *myPdf4 = theFit4.buildModel("otherFit");
//     theFit4.initialize(configfilename);

//     myPdf4->plotOn(plot, RooFit::Normalization(Nother/(Ns+NWW+Nother+Nttbar)),RooFit::LineColor(kBlack),RooFit::LineStyle(kDotted));

//   }

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
  (static_cast<RooRealVar*>(theFit._parameterSet.find("eff_sig")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("eff_WW")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("eff_ttbar")))->setConstant(kFALSE) ;
  (static_cast<RooRealVar*>(theFit._parameterSet.find("eff_other")))->setConstant(kFALSE) ;

  RooFitResult *fitres =  myPdf->fitTo(*data,theFit.getNoNormVars("myFit"),"MHTER");
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
  yieldsList.add(*theFit._fracList.find("N_sig"));
  yieldsList.add(*theFit._fracList.find("N_WW_1j"));
  yieldsList.add(*theFit._fracList.find("N_ttbar_1j"));
  yieldsList.add(*theFit._fracList.find("N_other_1j"));

  cout << "Macro" << endl;
  yieldsList.Print();
  cout << "End macro" << endl;

  RooDataSet* dsnew = MLSPlot::addSWeightToData((RooSimultaneous*)(myPdf), yieldsList, *data, 
                                                theFit.getNoNormVars("myFit")) ;

  TFile sPlots("sPlots-noDeltaPhi-finalstate0-mass160.root","recreate");
  dsnew->Write();
  sPlots.Close();

}
