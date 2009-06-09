// macor to make usual plots from a set of Toys
void makePdfSystToyHWW2e(TString dir = "./toys", TString file = "merged-results-finalstate0-mass160.dat", 
                         TString varfile = "variablesHWW2e.root", TString suffix = "H160") {
  
  gROOT->SetStyle("Plain");
  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);

  TH1D* N_sig_delta = new TH1D("N_sig_delta"," ",50, -1., 1.);

  gStyle->SetOptStat(1111111);
  TTree* ntp = readtoy(dir,file,varfile);

  ntp->Project("N_sig_delta","(N_sig_1 - N_sig_0)/N_sig_1 * 100","covQual_1==3 && covQual_0==3");
 
  // delta distributions
  TCanvas* c1 = new TCanvas("c1","c1",500,500);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);

  N_sig_delta->GetXaxis()->SetTitle("#Delta N_{sig}/N_{sig} [%]");
  N_sig_delta->Draw();
  TString deltastring_sig(dir+"/N_sig_delta_");
  deltastring_sig.Append(suffix);
  deltastring_sig.Append(".eps");
  c1->SaveAs(deltastring_sig);

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
  fitResData = RooDataSet::read(file, *variables);
  ntp = &fitResData->tree();
  f.Close();
  return ntp;
}
