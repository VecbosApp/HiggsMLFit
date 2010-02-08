// macor to make usual plots from a set of Toys
void makeplotstoyHWW2e(TString dir = "./toy-results/", TString file = "merged-ee.dat", 
                       TString varfile = "variablesHWW2l.root", TString suffix = "ee") {
  
  gROOT->SetStyle("Plain");
  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);

  TH1D* N_sig_pull = new TH1D("N_sig_pull"," ",20, -4., 4.);
  TH1D* N_sig_err = new TH1D("N_sig_err"," ",50, 0, 50.);
  TH1D* N_sig_sign = new TH1D("N_sig_sign"," ",30, 0, 10.);

  TH1D* eff_sig_pull = new TH1D("eff_sig_pull"," ",20, -4., 4.);
  TH1D* eff_sig_err = new TH1D("eff_sig_err"," ",50, 0, 5.);

  TH1D* N_WW_pull = new TH1D("N_WW_pull"," ",20, -4., 4.);
  TH1D* N_WW_err = new TH1D("N_WW_err"," ",50, 0, 50.);

  TH1D* eff_WW_pull = new TH1D("eff_WW_pull"," ",20, -4., 4.);
  TH1D* eff_WW_err = new TH1D("eff_WW_err"," ",50, 0, 5.);

  TH1D* N_ttbar_pull = new TH1D("N_ttbar_pull"," ",20, -4., 4.);
  TH1D* N_ttbar_err = new TH1D("N_ttbar_err"," ",50, 0., 100.);

  TH1D* eff_ttbar_pull = new TH1D("eff_ttbar_pull"," ",20, -4., 4.);
  TH1D* eff_ttbar_err = new TH1D("eff_ttbar_err"," ",50, 0., 5.);

  TH1D* N_Z_pull = new TH1D("N_Z_pull"," ",20, -4., 4.);
  TH1D* N_Z_err = new TH1D("N_Z_err"," ",50, 0., 1000.);

  TH1D* eff_Z_pull = new TH1D("eff_Z_pull"," ",20, -4., 4.);
  TH1D* eff_Z_err = new TH1D("eff_Z_err"," ",50, 0., 5.);

  TH1D* N_other_pull = new TH1D("N_other_pull"," ",20, -4., 4.);
  TH1D* N_other_err = new TH1D("N_other_err"," ",50, 0., 50.);

  TH1D* eff_other_pull = new TH1D("eff_other_pull"," ",20, -4., 4.);
  TH1D* eff_other_err = new TH1D("eff_other_err"," ",50, 0., 5.);

  gStyle->SetOptFit(1111111);
  TTree* ntp = readtoy(dir,file,varfile);

  ntp->Project("N_sig_pull","(N_sig_0 - N_siggen)/N_sigerr_0","covQual_0==3");
  ntp->Project("N_sig_err","N_sigerr_0","covQual_0==3");

  ntp->Project("eff_sig_pull","(eff_sig_0 - eff_siggen)/eff_sigerr_0","covQual_0==3");
  ntp->Project("eff_sig_err","eff_sigerr_0","covQual_0==3");

  ntp->Project("N_WW_pull","(N_WW_0 - N_WWgen)/N_WWerr_0","covQual_0==3");
  ntp->Project("N_WW_err","N_WWerr_0","covQual_0==3");

  ntp->Project("eff_WW_pull","(eff_WW_0 - eff_WWgen)/eff_WWerr_0","covQual_0==3");
  ntp->Project("eff_WW_err","eff_WWerr_0","covQual_0==3");

  ntp->Project("N_ttbar_pull","(N_ttbar_0 - N_ttbargen)/N_ttbarerr_0","covQual_0==3");
  ntp->Project("N_ttbar_err","N_ttbarerr_0","covQual_0==3");

  ntp->Project("eff_ttbar_pull","(eff_ttbar_0 - eff_ttbargen)/eff_ttbarerr_0","covQual_0==3");
  ntp->Project("eff_ttbar_err","eff_ttbarerr_0","covQual_0==3");

  ntp->Project("N_Z_pull","(N_Z_0 - N_Zgen)/N_Zerr_0","covQual_0==3");
  ntp->Project("N_Z_err","N_Zerr_0","covQual_0==3");

  ntp->Project("eff_Z_pull","(eff_Z_0 - eff_Zgen)/eff_Zerr_0","covQual_0==3");
  ntp->Project("eff_Z_err","eff_Zerr_0","covQual_0==3");

  ntp->Project("N_other_pull","(N_other_0 - N_othergen)/N_othererr_0","covQual_0==3");
  ntp->Project("N_other_err","N_othererr_0","covQual_0==3");

  ntp->Project("eff_other_pull","(eff_other_0 - eff_othergen)/eff_othererr_0","covQual_0==3");
  ntp->Project("eff_other_err","eff_othererr_0","covQual_0==3");

 
  // pull distributions, fitted as Gaussians
  TCanvas* c1 = new TCanvas("c1","c1",500,500);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);

  N_sig_pull->Fit("gaus");
  N_sig_pull->GetXaxis()->SetTitle("Pull N_{sig}");
  TString pullstring_sig(dir+"/N_sig_pull_");
  pullstring_sig.Append(suffix);
  pullstring_sig.Append(".png");
  c1->SaveAs(pullstring_sig);

  eff_sig_pull->Fit("gaus");
  eff_sig_pull->GetXaxis()->SetTitle("Pull eff_{sig}");
  TString pullstring_eff_sig(dir+"/eff_sig_pull_");
  pullstring_eff_sig.Append(suffix);
  pullstring_eff_sig.Append(".png");
  c1->SaveAs(pullstring_eff_sig);

  N_WW_pull->Fit("gaus");
  N_WW_pull->GetXaxis()->SetTitle("Pull N_{WW}");
  TString pullstring_WW(dir+"/N_WW_pull_");
  pullstring_WW.Append(suffix);
  pullstring_WW.Append(".png");
  c1->SaveAs(pullstring_WW);

  eff_WW_pull->Fit("gaus");
  eff_WW_pull->GetXaxis()->SetTitle("Pull eff_{WW}");
  TString pullstring_eff_WW(dir+"/eff_WW_pull_");
  pullstring_eff_WW.Append(suffix);
  pullstring_eff_WW.Append(".png");
  c1->SaveAs(pullstring_eff_WW);

  N_ttbar_pull->Fit("gaus");
  N_ttbar_pull->GetXaxis()->SetTitle("Pull N_{tt bkg}");
  TString pullstring_ttbar(dir+"/N_ttbar_pull_");
  pullstring_ttbar.Append(suffix);
  pullstring_ttbar.Append(".png");
  c1->SaveAs(pullstring_ttbar);

  eff_ttbar_pull->Fit("gaus");
  eff_ttbar_pull->GetXaxis()->SetTitle("Pull eff_{ttbar}");
  TString pullstring_eff_ttbar(dir+"/eff_ttbar_pull_");
  pullstring_eff_ttbar.Append(suffix);
  pullstring_eff_ttbar.Append(".png");
  c1->SaveAs(pullstring_eff_ttbar);

  N_Z_pull->Fit("gaus");
  N_Z_pull->GetXaxis()->SetTitle("Pull N_{Z bkg}");
  TString pullstring_Z(dir+"/N_Z_pull_");
  pullstring_Z.Append(suffix);
  pullstring_Z.Append(".png");
  c1->SaveAs(pullstring_Z);

  eff_Z_pull->Fit("gaus");
  eff_Z_pull->GetXaxis()->SetTitle("Pull eff_{Z}");
  TString pullstring_eff_Z(dir+"/eff_Z_pull_");
  pullstring_eff_Z.Append(suffix);
  pullstring_eff_Z.Append(".png");
  c1->SaveAs(pullstring_eff_Z);

  N_other_pull->Fit("gaus");
  N_other_pull->GetXaxis()->SetTitle("Pull N_{other}");
  TString pullstring_other(dir+"/N_other_pull_");
  pullstring_other.Append(suffix);
  pullstring_other.Append(".png");
  c1->SaveAs(pullstring_other);

  eff_other_pull->Fit("gaus");
  eff_other_pull->GetXaxis()->SetTitle("Pull eff_{other}");
  TString pullstring_eff_other(dir+"/eff_other_pull_");
  pullstring_eff_other.Append(suffix);
  pullstring_eff_other.Append(".png");
  c1->SaveAs(pullstring_eff_other);

  // error distributions
  TCanvas* c2 = new TCanvas("c2","c2",500,500);
  c2->SetFillColor(0);
  c2->SetBorderMode(0);
  c2->SetBorderSize(2);
  c2->SetFrameBorderMode(0);
  c2->SetFrameBorderMode(0);
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(1111111);

  N_sig_err->GetXaxis()->SetTitle("#sigma(N_{sig})");
  N_sig_err->Draw();
  TString errstring_sig(dir+"/N_sig_err_");
  errstring_sig.Append(suffix);
  errstring_sig.Append(".png");
  c2->SaveAs(errstring_sig);

  eff_sig_err->GetXaxis()->SetTitle("#sigma(eff_{sig})");
  eff_sig_err->Draw();
  TString errstring_eff_sig(dir+"/eff_sig_err_");
  errstring_eff_sig.Append(suffix);
  errstring_eff_sig.Append(".png");
  c2->SaveAs(errstring_eff_sig);

  N_sig_sign->GetXaxis()->SetTitle("significance");
  N_sig_sign->Draw();
  TString signstring_N_sig(dir+"/N_sig_sign_");
  signstring_N_sig.Append(suffix);
  signstring_N_sig.Append(".png");
  c2->SaveAs(signstring_N_sig);

  N_WW_err->GetXaxis()->SetTitle("#sigma(N_{WW})");
  N_WW_err->Draw();
  TString errstring_WW(dir+"/N_WW_err_");
  errstring_WW.Append(suffix);
  errstring_WW.Append(".png");
  c2->SaveAs(errstring_WW);

  eff_WW_err->GetXaxis()->SetTitle("#sigma(eff_{WW})");
  eff_WW_err->Draw();
  TString errstring_eff_WW(dir+"/eff_WW_err_");
  errstring_eff_WW.Append(suffix);
  errstring_eff_WW.Append(".png");
  c2->SaveAs(errstring_eff_WW);

  N_ttbar_err->GetXaxis()->SetTitle("#sigma(N_{ttbar})");
  N_ttbar_err->Draw();
  TString errstring_ttbar(dir+"/N_ttbar_err_");
  errstring_ttbar.Append(suffix);
  errstring_ttbar.Append(".png");
  c2->SaveAs(errstring_ttbar);

  eff_ttbar_err->GetXaxis()->SetTitle("#sigma(eff_{ttbar})");
  eff_ttbar_err->Draw();
  TString errstring_eff_ttbar(dir+"/eff_ttbar_err_");
  errstring_eff_ttbar.Append(suffix);
  errstring_eff_ttbar.Append(".png");
  c2->SaveAs(errstring_eff_ttbar);

  N_Z_err->GetXaxis()->SetTitle("#sigma(N_{Z})");
  N_Z_err->Draw();
  TString errstring_Z(dir+"/N_Z_err_");
  errstring_Z.Append(suffix);
  errstring_Z.Append(".png");
  c2->SaveAs(errstring_Z);

  eff_Z_err->GetXaxis()->SetTitle("#sigma(eff_{Z})");
  eff_Z_err->Draw();
  TString errstring_eff_Z(dir+"/eff_Z_err_");
  errstring_eff_Z.Append(suffix);
  errstring_eff_Z.Append(".png");
  c2->SaveAs(errstring_eff_Z);

  N_other_err->GetXaxis()->SetTitle("#sigma(N_{other})");
  N_other_err->Draw();
  TString errstring_other(dir+"/N_other_err_");
  errstring_other.Append(suffix);
  errstring_other.Append(".png");
  c2->SaveAs(errstring_other);

  eff_other_err->GetXaxis()->SetTitle("#sigma(eff_{other})");
  eff_other_err->Draw();
  TString errstring_eff_other(dir+"/eff_other_err_");
  errstring_eff_other.Append(suffix);
  errstring_eff_other.Append(".png");
  c2->SaveAs(errstring_eff_other);

}

TTree *readtoy(const char* _dir, const char* _file="tmp.dat", const char* _varfile = "variables.root")
{

  RooDataSet *fitResData;
  TTree *ntp;

  TString dir(_dir);
  dir.Append("/");

  TString file(_file);
  file.Prepend(dir);
  
  TString varfile(_varfile);
  varfile.Prepend(dir);

  cout << "Reading data from:      " << file << endl;
  cout << "Reading variables from: " << varfile << endl;
  
  TFile f(varfile);

  RooArgSet *variables = (RooArgSet*)f.Get("variables");

  variables->Print();

  RooArgSet *errorVars = variables->selectByName("*err");
  TIterator *it = errorVars->createIterator();
  RooRealVar *var;
  while (var = (RooRealVar*)it->Next()) {
    var->setRange(-100000,100000);
  }

  fitResData = RooDataSet::read(file, *variables);
  ntp = &fitResData->tree();
  f.Close();
  return ntp;
}
