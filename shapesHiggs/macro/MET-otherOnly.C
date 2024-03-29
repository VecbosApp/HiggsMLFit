{
//=========Macro generated from canvas: c/fitResult
//=========  (Wed May 13 16:19:53 2009) by ROOT version5.18/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,44,599,299);
   gStyle->SetOptStat(0);
   c->Range(5.421687,-1988.002,210.241,10437.01);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetTickx();
   c->SetTicky();
   c->SetLeftMargin(0.12);
   c->SetRightMargin(0.05);
   c->SetTopMargin(0.05);
   c->SetBottomMargin(0.16);
   c->SetFrameFillStyle(0);
   c->SetFrameBorderMode(0);
   c->SetFrameFillStyle(0);
   c->SetFrameBorderMode(0);
   
   TH1 *frame_0a89aa78 = new TH1D("frame_0a89aa78","A RooPlot of "MET"",17,30,200);
   frame_0a89aa78->SetMaximum(9815.76);
   frame_0a89aa78->SetDirectory(0);
   frame_0a89aa78->SetStats(0);
   frame_0a89aa78->SetMarkerStyle(8);
   frame_0a89aa78->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_0a89aa78->GetXaxis()->SetLabelFont(132);
   frame_0a89aa78->GetXaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetXaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetXaxis()->SetTitleFont(132);
   frame_0a89aa78->GetYaxis()->SetTitle("Events");
   frame_0a89aa78->GetYaxis()->SetLabelFont(132);
   frame_0a89aa78->GetYaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetYaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetYaxis()->SetTitleFont(132);
   frame_0a89aa78->GetZaxis()->SetLabelFont(132);
   frame_0a89aa78->GetZaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetZaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetZaxis()->SetTitleFont(132);
   frame_0a89aa78->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(17);
   grae->SetName("other_plot__MET");
   grae->SetTitle("Histogram of other_plot__MET");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,35,9211.017);
   grae->SetPointError(0,5,5,137.326,137.326);
   grae->SetPoint(1,45,3448.045);
   grae->SetPointError(1,5,5,81.34149,81.34149);
   grae->SetPoint(2,55,1432.609);
   grae->SetPointError(2,5,5,50.58234,50.58234);
   grae->SetPoint(3,65,668.9845);
   grae->SetPointError(3,5,5,33.25967,33.25967);
   grae->SetPoint(4,75,363.6029);
   grae->SetPointError(4,5,5,23.5769,23.5769);
   grae->SetPoint(5,85,134.8337);
   grae->SetPointError(5,5,5,11.78403,11.78403);
   grae->SetPoint(6,95,84.69037);
   grae->SetPointError(6,5,5,9.194762,9.194762);
   grae->SetPoint(7,105,62.40463);
   grae->SetPointError(7,5,5,8.026423,8.026423);
   grae->SetPoint(8,115,32.19039);
   grae->SetPointError(8,5,5,4.596163,4.596163);
   grae->SetPoint(9,125,29.92851);
   grae->SetPointError(9,5,5,5.461523,5.461523);
   grae->SetPoint(10,135,12.54761);
   grae->SetPointError(10,5,5,2.392472,2.392472);
   grae->SetPoint(11,145,16.26188);
   grae->SetPointError(11,5,5,4.418255,4.418255);
   grae->SetPoint(12,155,8.047626);
   grae->SetPointError(12,5,5,2.294131,2.294131);
   grae->SetPoint(13,165,8.261909);
   grae->SetPointError(13,5,5,2.307068,2.307068);
   grae->SetPoint(14,175,3.04762);
   grae->SetPointError(14,5,5,0.5491697,0.5491697);
   grae->SetPoint(15,185,4.809526);
   grae->SetPointError(15,5,5,2.225904,2.225904);
   grae->SetPoint(16,195,4.09524);
   grae->SetPointError(16,5,5,2.209288,2.209288);
   grae->Draw("p");
   
   TGraph *graph = new TGraph(58);
   graph->SetName("curve_myFitProjected");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,20,0);
   graph->SetPoint(1,20,9210.43);
   graph->SetPoint(2,30,9210.43);
   graph->SetPoint(3,35,9210.43);
   graph->SetPoint(4,37.5,9210.43);
   graph->SetPoint(5,38.75,9210.43);
   graph->SetPoint(6,39.375,9210.43);
   graph->SetPoint(7,39.6875,9210.43);
   graph->SetPoint(8,40,3448.277);
   graph->SetPoint(9,45,3448.277);
   graph->SetPoint(10,47.5,3448.277);
   graph->SetPoint(11,48.75,3448.277);
   graph->SetPoint(12,49.375,3448.277);
   graph->SetPoint(13,49.6875,3448.277);
   graph->SetPoint(14,50,1432.79);
   graph->SetPoint(15,55,1432.79);
   graph->SetPoint(16,57.5,1432.79);
   graph->SetPoint(17,58.75,1432.79);
   graph->SetPoint(18,59.375,1432.79);
   graph->SetPoint(19,59.6875,1432.79);
   graph->SetPoint(20,60,669.0913);
   graph->SetPoint(21,65,669.0913);
   graph->SetPoint(22,67.5,669.0913);
   graph->SetPoint(23,68.75,669.0913);
   graph->SetPoint(24,69.375,669.0913);
   graph->SetPoint(25,69.6875,669.0913);
   graph->SetPoint(26,70,363.6263);
   graph->SetPoint(27,75,363.6263);
   graph->SetPoint(28,77.5,363.6263);
   graph->SetPoint(29,78.75,363.6263);
   graph->SetPoint(30,79.375,363.6263);
   graph->SetPoint(31,79.6875,363.6263);
   graph->SetPoint(32,80,109.774);
   graph->SetPoint(33,90,109.774);
   graph->SetPoint(34,95,109.774);
   graph->SetPoint(35,97.5,109.774);
   graph->SetPoint(36,98.75,109.774);
   graph->SetPoint(37,99.375,109.774);
   graph->SetPoint(38,99.6875,109.774);
   graph->SetPoint(39,100,30.66809);
   graph->SetPoint(40,110,30.66809);
   graph->SetPoint(41,120,30.66809);
   graph->SetPoint(42,130,30.66809);
   graph->SetPoint(43,140,30.66809);
   graph->SetPoint(44,145,30.66809);
   graph->SetPoint(45,147.5,30.66809);
   graph->SetPoint(46,148.75,30.66809);
   graph->SetPoint(47,149.375,30.66809);
   graph->SetPoint(48,149.6875,30.66809);
   graph->SetPoint(49,150,5.654737);
   graph->SetPoint(50,160,5.654737);
   graph->SetPoint(51,170,5.654737);
   graph->SetPoint(52,180,5.654737);
   graph->SetPoint(53,190,5.654737);
   graph->SetPoint(54,200,0);
   graph->SetPoint(55,200,0);
   graph->SetPoint(56,210,0);
   graph->SetPoint(57,210,0);
   graph->Draw("l");
   
   TH1 *frame_0a89aa78 = new TH1D("frame_0a89aa78","A RooPlot of "MET"",17,30,200);
   frame_0a89aa78->SetMaximum(9815.76);
   frame_0a89aa78->SetDirectory(0);
   frame_0a89aa78->SetStats(0);
   frame_0a89aa78->SetMarkerStyle(8);
   frame_0a89aa78->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_0a89aa78->GetXaxis()->SetLabelFont(132);
   frame_0a89aa78->GetXaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetXaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetXaxis()->SetTitleFont(132);
   frame_0a89aa78->GetYaxis()->SetTitle("Events");
   frame_0a89aa78->GetYaxis()->SetLabelFont(132);
   frame_0a89aa78->GetYaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetYaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetYaxis()->SetTitleFont(132);
   frame_0a89aa78->GetZaxis()->SetLabelFont(132);
   frame_0a89aa78->GetZaxis()->SetLabelSize(0.05);
   frame_0a89aa78->GetZaxis()->SetTitleSize(0.06);
   frame_0a89aa78->GetZaxis()->SetTitleFont(132);
   frame_0a89aa78->Draw("axissame");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
