void makeStatSign(TString dir = "./toy-results/", TString file = "merged-ee.dat",
                  TString varfile = "variablesHWW2l.root", TString suffix = "ee") {
  
  gROOT->SetStyle("Plain");
  // do not display any of the standard histogram decorations
  //  gStyle->SetOptTitle(0);

  TH1D* N_sig_sign = new TH1D("N_sig_sign"," ",20, 0, 5.);

  TTree* ntp = readtoy(dir,file,varfile);

  ntp->Project("N_sig_sign","sqrt(2*abs(NLL_1-NLL_0))","covQual_1==3 && covQual_0==3 && sqrt(2*abs(NLL_1-NLL_0))>0");

  // pull distributions, fitted as Gaussians
  TCanvas* c1 = new TCanvas("c1","c1",500,500);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);

  N_sig_sign->Draw();
  N_sig_sign->GetXaxis()->SetTitle("#sqrt{2#Delta Log(L)}");
  TString signstring_sig(dir+"/N_sig_sign_");
  signstring_sig.Append(suffix);
  signstring_sig.Append(".png");
  c1->SaveAs(signstring_sig);

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
