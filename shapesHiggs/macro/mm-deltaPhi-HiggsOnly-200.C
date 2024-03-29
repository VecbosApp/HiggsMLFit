{
//=========Macro generated from canvas: c/fitResult
//=========  (Fri Feb 18 15:01:59 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-26.0241,-52.90352,190.8434,277.7435);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetLeftMargin(0.12);
   c->SetRightMargin(0.05);
   c->SetTopMargin(0.05);
   c->SetBottomMargin(0.16);
   c->SetFrameFillStyle(0);
   c->SetFrameBorderMode(0);
   c->SetFrameFillStyle(0);
   c->SetFrameBorderMode(0);
   
   TH1D *frame_104e66640__1 = new TH1D("frame_104e66640__1","A RooPlot of "#Delta#phi"",30,0,180);
   frame_104e66640__1->SetMaximum(261.2112);
   frame_104e66640__1->SetDirectory(0);
   frame_104e66640__1->SetStats(0);
   frame_104e66640__1->SetMarkerStyle(8);
   frame_104e66640__1->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_104e66640__1->GetXaxis()->SetLabelFont(132);
   frame_104e66640__1->GetXaxis()->SetLabelSize(0.05);
   frame_104e66640__1->GetXaxis()->SetTitleSize(0.06);
   frame_104e66640__1->GetXaxis()->SetTitleFont(132);
   frame_104e66640__1->GetYaxis()->SetTitle("Events");
   frame_104e66640__1->GetYaxis()->SetLabelFont(132);
   frame_104e66640__1->GetYaxis()->SetLabelSize(0.05);
   frame_104e66640__1->GetYaxis()->SetTitleSize(0.06);
   frame_104e66640__1->GetYaxis()->SetTitleFont(132);
   frame_104e66640__1->GetZaxis()->SetLabelFont(132);
   frame_104e66640__1->GetZaxis()->SetLabelSize(0.05);
   frame_104e66640__1->GetZaxis()->SetTitleSize(0.06);
   frame_104e66640__1->GetZaxis()->SetTitleFont(132);
   frame_104e66640__1->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3,146);
   grae->SetPointError(0,3,3,11.59339,12.59339);
   grae->SetPoint(1,9,154);
   grae->SetPointError(1,3,3,11.91974,12.91974);
   grae->SetPoint(2,15,152);
   grae->SetPointError(2,3,3,11.83896,12.83896);
   grae->SetPoint(3,21,184);
   grae->SetPointError(3,3,3,13.07387,14.07387);
   grae->SetPoint(4,27,210);
   grae->SetPointError(4,3,3,14,15);
   grae->SetPoint(5,33,210);
   grae->SetPointError(5,3,3,14,15);
   grae->SetPoint(6,39,209);
   grae->SetPointError(6,3,3,13.96548,14.96548);
   grae->SetPoint(7,45,212);
   grae->SetPointError(7,3,3,14.0688,15.0688);
   grae->SetPoint(8,51,193);
   grae->SetPointError(8,3,3,13.40144,14.40144);
   grae->SetPoint(9,57,233);
   grae->SetPointError(9,3,3,14.77252,15.77252);
   grae->SetPoint(10,63,216);
   grae->SetPointError(10,3,3,14.20544,15.20544);
   grae->SetPoint(11,69,229);
   grae->SetPointError(11,3,3,14.641,15.641);
   grae->SetPoint(12,75,228);
   grae->SetPointError(12,3,3,14.60794,15.60794);
   grae->SetPoint(13,81,200);
   grae->SetPointError(13,3,3,13.65097,14.65097);
   grae->SetPoint(14,87,221);
   grae->SetPointError(14,3,3,14.37447,15.37447);
   grae->SetPoint(15,93,147);
   grae->SetPointError(15,3,3,11.63466,12.63466);
   grae->SetPoint(16,99,125);
   grae->SetPointError(16,3,3,10.69151,11.69151);
   grae->SetPoint(17,105,91);
   grae->SetPointError(17,3,3,9.521834,10.57436);
   grae->SetPoint(18,111,98);
   grae->SetPointError(18,3,3,9.882579,10.93319);
   grae->SetPoint(19,117,81);
   grae->SetPointError(19,3,3,8.981384,10.03706);
   grae->SetPoint(20,123,73);
   grae->SetPointError(20,3,3,8.524388,9.583044);
   grae->SetPoint(21,129,52);
   grae->SetPointError(21,3,3,7.187836,8.257346);
   grae->SetPoint(22,135,35);
   grae->SetPointError(22,3,3,5.887675,6.97241);
   grae->SetPoint(23,141,40);
   grae->SetPointError(23,3,3,6.298,7.377261);
   grae->SetPoint(24,147,48);
   grae->SetPointError(24,3,3,6.903979,7.97633);
   grae->SetPoint(25,153,29);
   grae->SetPointError(25,3,3,5.353932,6.44702);
   grae->SetPoint(26,159,23);
   grae->SetPointError(26,3,3,4.760717,5.865235);
   grae->SetPoint(27,165,36);
   grae->SetPointError(27,3,3,5.971996,7.055545);
   grae->SetPoint(28,171,28);
   grae->SetPointError(28,3,3,5.259711,6.354446);
   grae->SetPoint(29,177,24);
   grae->SetPointError(29,3,3,4.864612,5.966932);
   
   TH1F *h_T11__2 = new TH1F("h_T11__2","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T11__2->SetMinimum(0);
   h_T11__2->SetMaximum(271.8258);
   h_T11__2->SetDirectory(0);
   h_T11__2->SetStats(0);
   h_T11__2->SetMarkerStyle(8);
   h_T11__2->GetXaxis()->SetLabelFont(132);
   h_T11__2->GetXaxis()->SetLabelSize(0.05);
   h_T11__2->GetXaxis()->SetTitleSize(0.06);
   h_T11__2->GetXaxis()->SetTitleFont(132);
   h_T11__2->GetYaxis()->SetLabelFont(132);
   h_T11__2->GetYaxis()->SetLabelSize(0.05);
   h_T11__2->GetYaxis()->SetTitleSize(0.06);
   h_T11__2->GetYaxis()->SetTitleFont(132);
   h_T11__2->GetZaxis()->SetLabelFont(132);
   h_T11__2->GetZaxis()->SetLabelSize(0.05);
   h_T11__2->GetZaxis()->SetTitleSize(0.06);
   h_T11__2->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T11);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(49);
   graph->SetName("myFit_Norm[deltaPhi]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-6,0);
   graph->SetPoint(1,-6,140.253);
   graph->SetPoint(2,0,140.253);
   graph->SetPoint(3,6,151.5769);
   graph->SetPoint(4,12,162.7165);
   graph->SetPoint(5,18,173.5034);
   graph->SetPoint(6,24,183.7647);
   graph->SetPoint(7,30,193.3276);
   graph->SetPoint(8,36,202.0242);
   graph->SetPoint(9,42,209.6963);
   graph->SetPoint(10,48,216.2);
   graph->SetPoint(11,54,221.4105);
   graph->SetPoint(12,60,225.226);
   graph->SetPoint(13,66,227.5708);
   graph->SetPoint(14,72,228.3979);
   graph->SetPoint(15,73.5,228.0499);
   graph->SetPoint(16,75,226.739);
   graph->SetPoint(17,76.5,224.4831);
   graph->SetPoint(18,78,221.3311);
   graph->SetPoint(19,79.5,217.3491);
   graph->SetPoint(20,81,212.6183);
   graph->SetPoint(21,82.5,207.2306);
   graph->SetPoint(22,84,201.2854);
   graph->SetPoint(23,87,188.1344);
   graph->SetPoint(24,90,173.9708);
   graph->SetPoint(25,96,145.3435);
   graph->SetPoint(26,99,131.8784);
   graph->SetPoint(27,102,119.3867);
   graph->SetPoint(28,105,108.0088);
   graph->SetPoint(29,108,97.78769);
   graph->SetPoint(30,111,88.69863);
   graph->SetPoint(31,114,80.67406);
   graph->SetPoint(32,117,73.62314);
   graph->SetPoint(33,120,67.44542);
   graph->SetPoint(34,123,62.04);
   graph->SetPoint(35,126,57.31099);
   graph->SetPoint(36,129,53.17052);
   graph->SetPoint(37,132,49.53993);
   graph->SetPoint(38,138,43.54061);
   graph->SetPoint(39,144,38.86258);
   graph->SetPoint(40,150,35.17262);
   graph->SetPoint(41,156,32.22689);
   graph->SetPoint(42,162,29.84722);
   graph->SetPoint(43,168,27.9028);
   graph->SetPoint(44,174,26.29687);
   graph->SetPoint(45,180,24.95715);
   graph->SetPoint(46,180,24.95715);
   graph->SetPoint(47,186,24.95715);
   graph->SetPoint(48,186,0);
   
   TH1F *myFit_Norm[deltaPhi]1__3 = new TH1F("myFit_Norm[deltaPhi]1__3","Projection of Higgs to WW",100,-25.2,205.2);
   myFit_Norm[deltaPhi]1__3->SetMinimum(0);
   myFit_Norm[deltaPhi]1__3->SetMaximum(251.2377);
   myFit_Norm[deltaPhi]1__3->SetDirectory(0);
   myFit_Norm[deltaPhi]1__3->SetStats(0);
   myFit_Norm[deltaPhi]1__3->SetMarkerStyle(8);
   myFit_Norm[deltaPhi]1__3->GetXaxis()->SetLabelFont(132);
   myFit_Norm[deltaPhi]1__3->GetXaxis()->SetLabelSize(0.05);
   myFit_Norm[deltaPhi]1__3->GetXaxis()->SetTitleSize(0.06);
   myFit_Norm[deltaPhi]1__3->GetXaxis()->SetTitleFont(132);
   myFit_Norm[deltaPhi]1__3->GetYaxis()->SetLabelFont(132);
   myFit_Norm[deltaPhi]1__3->GetYaxis()->SetLabelSize(0.05);
   myFit_Norm[deltaPhi]1__3->GetYaxis()->SetTitleSize(0.06);
   myFit_Norm[deltaPhi]1__3->GetYaxis()->SetTitleFont(132);
   myFit_Norm[deltaPhi]1__3->GetZaxis()->SetLabelFont(132);
   myFit_Norm[deltaPhi]1__3->GetZaxis()->SetLabelSize(0.05);
   myFit_Norm[deltaPhi]1__3->GetZaxis()->SetTitleSize(0.06);
   myFit_Norm[deltaPhi]1__3->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Norm[deltaPhi]1);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3,146);
   grae->SetPointError(0,3,3,11.59339,12.59339);
   grae->SetPoint(1,9,154);
   grae->SetPointError(1,3,3,11.91974,12.91974);
   grae->SetPoint(2,15,152);
   grae->SetPointError(2,3,3,11.83896,12.83896);
   grae->SetPoint(3,21,184);
   grae->SetPointError(3,3,3,13.07387,14.07387);
   grae->SetPoint(4,27,210);
   grae->SetPointError(4,3,3,14,15);
   grae->SetPoint(5,33,210);
   grae->SetPointError(5,3,3,14,15);
   grae->SetPoint(6,39,209);
   grae->SetPointError(6,3,3,13.96548,14.96548);
   grae->SetPoint(7,45,212);
   grae->SetPointError(7,3,3,14.0688,15.0688);
   grae->SetPoint(8,51,193);
   grae->SetPointError(8,3,3,13.40144,14.40144);
   grae->SetPoint(9,57,233);
   grae->SetPointError(9,3,3,14.77252,15.77252);
   grae->SetPoint(10,63,216);
   grae->SetPointError(10,3,3,14.20544,15.20544);
   grae->SetPoint(11,69,229);
   grae->SetPointError(11,3,3,14.641,15.641);
   grae->SetPoint(12,75,228);
   grae->SetPointError(12,3,3,14.60794,15.60794);
   grae->SetPoint(13,81,200);
   grae->SetPointError(13,3,3,13.65097,14.65097);
   grae->SetPoint(14,87,221);
   grae->SetPointError(14,3,3,14.37447,15.37447);
   grae->SetPoint(15,93,147);
   grae->SetPointError(15,3,3,11.63466,12.63466);
   grae->SetPoint(16,99,125);
   grae->SetPointError(16,3,3,10.69151,11.69151);
   grae->SetPoint(17,105,91);
   grae->SetPointError(17,3,3,9.521834,10.57436);
   grae->SetPoint(18,111,98);
   grae->SetPointError(18,3,3,9.882579,10.93319);
   grae->SetPoint(19,117,81);
   grae->SetPointError(19,3,3,8.981384,10.03706);
   grae->SetPoint(20,123,73);
   grae->SetPointError(20,3,3,8.524388,9.583044);
   grae->SetPoint(21,129,52);
   grae->SetPointError(21,3,3,7.187836,8.257346);
   grae->SetPoint(22,135,35);
   grae->SetPointError(22,3,3,5.887675,6.97241);
   grae->SetPoint(23,141,40);
   grae->SetPointError(23,3,3,6.298,7.377261);
   grae->SetPoint(24,147,48);
   grae->SetPointError(24,3,3,6.903979,7.97633);
   grae->SetPoint(25,153,29);
   grae->SetPointError(25,3,3,5.353932,6.44702);
   grae->SetPoint(26,159,23);
   grae->SetPointError(26,3,3,4.760717,5.865235);
   grae->SetPoint(27,165,36);
   grae->SetPointError(27,3,3,5.971996,7.055545);
   grae->SetPoint(28,171,28);
   grae->SetPointError(28,3,3,5.259711,6.354446);
   grae->SetPoint(29,177,24);
   grae->SetPointError(29,3,3,4.864612,5.966932);
   
   TH1F *h_T12__4 = new TH1F("h_T12__4","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T12__4->SetMinimum(0);
   h_T12__4->SetMaximum(271.8258);
   h_T12__4->SetDirectory(0);
   h_T12__4->SetStats(0);
   h_T12__4->SetMarkerStyle(8);
   h_T12__4->GetXaxis()->SetLabelFont(132);
   h_T12__4->GetXaxis()->SetLabelSize(0.05);
   h_T12__4->GetXaxis()->SetTitleSize(0.06);
   h_T12__4->GetXaxis()->SetTitleFont(132);
   h_T12__4->GetYaxis()->SetLabelFont(132);
   h_T12__4->GetYaxis()->SetLabelSize(0.05);
   h_T12__4->GetYaxis()->SetTitleSize(0.06);
   h_T12__4->GetYaxis()->SetTitleFont(132);
   h_T12__4->GetZaxis()->SetLabelFont(132);
   h_T12__4->GetZaxis()->SetLabelSize(0.05);
   h_T12__4->GetZaxis()->SetTitleSize(0.06);
   h_T12__4->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T12);
   
   grae->Draw("p");
   
   TH1D *frame_104e66640__5 = new TH1D("frame_104e66640__5","A RooPlot of "#Delta#phi"",30,0,180);
   frame_104e66640__5->SetMaximum(261.2112);
   frame_104e66640__5->SetDirectory(0);
   frame_104e66640__5->SetStats(0);
   frame_104e66640__5->SetMarkerStyle(8);
   frame_104e66640__5->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_104e66640__5->GetXaxis()->SetLabelFont(132);
   frame_104e66640__5->GetXaxis()->SetLabelSize(0.05);
   frame_104e66640__5->GetXaxis()->SetTitleSize(0.06);
   frame_104e66640__5->GetXaxis()->SetTitleFont(132);
   frame_104e66640__5->GetYaxis()->SetTitle("Events");
   frame_104e66640__5->GetYaxis()->SetLabelFont(132);
   frame_104e66640__5->GetYaxis()->SetLabelSize(0.05);
   frame_104e66640__5->GetYaxis()->SetTitleSize(0.06);
   frame_104e66640__5->GetYaxis()->SetTitleFont(132);
   frame_104e66640__5->GetZaxis()->SetLabelFont(132);
   frame_104e66640__5->GetZaxis()->SetLabelSize(0.05);
   frame_104e66640__5->GetZaxis()->SetTitleSize(0.06);
   frame_104e66640__5->GetZaxis()->SetTitleFont(132);
   frame_104e66640__5->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
