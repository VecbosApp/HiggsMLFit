{
//=========Macro generated from canvas: c/fitResult
//=========  (Fri Nov  6 15:58:08 2009) by ROOT version5.22/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,22,600,300);
   gStyle->SetOptStat(0);
   c->Range(-28.91566,-501.1136,212.0482,2630.847);
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
   
   TH1 *frame_204242912 = new TH1D("frame_204242912","A RooPlot of "E_{T}^{miss}"",28,0,200);
   frame_204242912->SetMaximum(2474.249);
   frame_204242912->SetDirectory(0);
   frame_204242912->SetStats(0);
   frame_204242912->SetMarkerStyle(8);
   frame_204242912->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_204242912->GetXaxis()->SetLabelFont(132);
   frame_204242912->GetXaxis()->SetLabelSize(0.05);
   frame_204242912->GetXaxis()->SetTitleSize(0.06);
   frame_204242912->GetXaxis()->SetTitleFont(132);
   frame_204242912->GetYaxis()->SetTitle("Events");
   frame_204242912->GetYaxis()->SetLabelFont(132);
   frame_204242912->GetYaxis()->SetLabelSize(0.05);
   frame_204242912->GetYaxis()->SetTitleSize(0.06);
   frame_204242912->GetYaxis()->SetTitleFont(132);
   frame_204242912->GetZaxis()->SetLabelFont(132);
   frame_204242912->GetZaxis()->SetLabelSize(0.05);
   frame_204242912->GetZaxis()->SetTitleSize(0.06);
   frame_204242912->GetZaxis()->SetTitleFont(132);
   frame_204242912->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(28);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__met");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3.571429,600);
   grae->SetPointError(0,3.571429,3.571429,24,25);
   grae->SetPoint(1,10.71429,1578);
   grae->SetPointError(1,3.571429,3.571429,39.22719,40.22719);
   grae->SetPoint(2,17.85714,2073);
   grae->SetPointError(2,3.571429,3.571429,45.03296,46.03296);
   grae->SetPoint(3,25,2228);
   grae->SetPointError(3,3.571429,3.571429,46.70434,47.70434);
   grae->SetPoint(4,32.14286,2263);
   grae->SetPointError(4,3.571429,3.571429,47.07363,48.07363);
   grae->SetPoint(5,39.28571,2208);
   grae->SetPointError(5,3.571429,3.571429,46.49202,47.49202);
   grae->SetPoint(6,46.42857,2080);
   grae->SetPointError(6,3.571429,3.571429,45.10976,46.10976);
   grae->SetPoint(7,53.57143,1923);
   grae->SetPointError(7,3.571429,3.571429,43.35487,44.35487);
   grae->SetPoint(8,60.71429,1619);
   grae->SetPointError(8,3.571429,3.571429,39.73991,40.73991);
   grae->SetPoint(9,67.85714,1205);
   grae->SetPointError(9,3.571429,3.571429,34.21671,35.21671);
   grae->SetPoint(10,75,782);
   grae->SetPointError(10,3.571429,3.571429,27.46873,28.46873);
   grae->SetPoint(11,82.14286,455);
   grae->SetPointError(11,3.571429,3.571429,20.83659,21.83659);
   grae->SetPoint(12,89.28571,213);
   grae->SetPointError(12,3.571429,3.571429,14.10308,15.10308);
   grae->SetPoint(13,96.42857,124);
   grae->SetPointError(13,3.571429,3.571429,10.64675,11.64675);
   grae->SetPoint(14,103.5714,75);
   grae->SetPointError(14,3.571429,3.571429,8.640903,9.698771);
   grae->SetPoint(15,110.7143,44);
   grae->SetPointError(15,3.571429,3.571429,6.60794,7.68351);
   grae->SetPoint(16,117.8571,41);
   grae->SetPointError(16,3.571429,3.571429,6.376898,7.455185);
   grae->SetPoint(17,125,38);
   grae->SetPointError(17,3.571429,3.571429,6.137163,7.218484);
   grae->SetPoint(18,132.1429,27);
   grae->SetPointError(18,3.571429,3.571429,5.163771,6.260244);
   grae->SetPoint(19,139.2857,27);
   grae->SetPointError(19,3.571429,3.571429,5.163771,6.260244);
   grae->SetPoint(20,146.4286,13);
   grae->SetPointError(20,3.571429,3.571429,3.558662,4.697573);
   grae->SetPoint(21,153.5714,21);
   grae->SetPointError(21,3.571429,3.571429,4.545807,5.655182);
   grae->SetPoint(22,160.7143,7);
   grae->SetPointError(22,3.571429,3.571429,2.58147,3.770281);
   grae->SetPoint(23,167.8571,10);
   grae->SetPointError(23,3.571429,3.571429,3.108694,4.26695);
   grae->SetPoint(24,175,6);
   grae->SetPointError(24,3.571429,3.571429,2.379931,3.583642);
   grae->SetPoint(25,182.1429,4);
   grae->SetPointError(25,3.571429,3.571429,1.914339,3.162753);
   grae->SetPoint(26,189.2857,2);
   grae->SetPointError(26,3.571429,3.571429,1.291815,2.63786);
   grae->SetPoint(27,196.4286,10);
   grae->SetPointError(27,3.571429,3.571429,3.108694,4.26695);
   
   TH1 *h_T111 = new TH1F("h_T111","Histogram of T1_plot__met",100,0,220);
   h_T111->SetMinimum(0);
   h_T111->SetMaximum(2542.11);
   h_T111->SetDirectory(0);
   h_T111->SetStats(0);
   h_T111->SetMarkerStyle(8);
   h_T111->GetXaxis()->SetLabelFont(132);
   h_T111->GetXaxis()->SetLabelSize(0.05);
   h_T111->GetXaxis()->SetTitleSize(0.06);
   h_T111->GetXaxis()->SetTitleFont(132);
   h_T111->GetYaxis()->SetLabelFont(132);
   h_T111->GetYaxis()->SetLabelSize(0.05);
   h_T111->GetYaxis()->SetTitleSize(0.06);
   h_T111->GetYaxis()->SetTitleFont(132);
   h_T111->GetZaxis()->SetLabelFont(132);
   h_T111->GetZaxis()->SetLabelSize(0.05);
   h_T111->GetZaxis()->SetTitleSize(0.06);
   h_T111->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T111);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(67);
   graph->SetName("myFit_Int[jetcat]_Norm[met,jetcat]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-7.142857,0);
   graph->SetPoint(1,-7.142857,709.8298);
   graph->SetPoint(2,0,709.8298);
   graph->SetPoint(3,1.785714,792.9206);
   graph->SetPoint(4,3.571429,887.9257);
   graph->SetPoint(5,5.357143,997.2239);
   graph->SetPoint(6,7.142857,1122.694);
   graph->SetPoint(7,8.928571,1264.933);
   graph->SetPoint(8,10.71429,1422.419);
   graph->SetPoint(9,14.28571,1762.98);
   graph->SetPoint(10,16.07143,1929.152);
   graph->SetPoint(11,16.96429,2006.636);
   graph->SetPoint(12,17.85714,2078.604);
   graph->SetPoint(13,18.75,2143.84);
   graph->SetPoint(14,19.64286,2201.3);
   graph->SetPoint(15,20.53571,2250.161);
   graph->SetPoint(16,21.42857,2289.868);
   graph->SetPoint(17,22.32143,2320.16);
   graph->SetPoint(18,23.21429,2341.079);
   graph->SetPoint(19,24.10714,2352.964);
   graph->SetPoint(20,25,2356.427);
   graph->SetPoint(21,25.89286,2352.311);
   graph->SetPoint(22,26.78571,2341.636);
   graph->SetPoint(23,28.57143,2305.236);
   graph->SetPoint(24,32.14286,2204.441);
   graph->SetPoint(25,33.92857,2154.842);
   graph->SetPoint(26,35.71429,2111.347);
   graph->SetPoint(27,37.5,2074.785);
   graph->SetPoint(28,39.28571,2043.98);
   graph->SetPoint(29,42.85714,1989.952);
   graph->SetPoint(30,46.42857,1929.456);
   graph->SetPoint(31,48.21429,1892.368);
   graph->SetPoint(32,50,1849.592);
   graph->SetPoint(33,51.78571,1800.925);
   graph->SetPoint(34,53.57143,1746.523);
   graph->SetPoint(35,55.35714,1686.793);
   graph->SetPoint(36,57.14286,1622.3);
   graph->SetPoint(37,60.71429,1481.732);
   graph->SetPoint(38,64.28571,1330.6);
   graph->SetPoint(39,71.42857,1019.754);
   graph->SetPoint(40,75,870.2891);
   graph->SetPoint(41,78.57143,730.233);
   graph->SetPoint(42,82.14286,602.4055);
   graph->SetPoint(43,85.71429,488.5916);
   graph->SetPoint(44,89.28571,389.6123);
   graph->SetPoint(45,92.85714,305.4562);
   graph->SetPoint(46,96.42857,235.4479);
   graph->SetPoint(47,100,178.431);
   graph->SetPoint(48,103.5714,132.946);
   graph->SetPoint(49,107.1429,97.38899);
   graph->SetPoint(50,110.7143,70.14134);
   graph->SetPoint(51,114.2857,49.66699);
   graph->SetPoint(52,121.4286,23.66705);
   graph->SetPoint(53,128.5714,10.53753);
   graph->SetPoint(54,135.7143,4.383812);
   graph->SetPoint(55,142.8571,1.704054);
   graph->SetPoint(56,150,0.6189179);
   graph->SetPoint(57,157.1429,0.2100396);
   graph->SetPoint(58,164.2857,0.06660205);
   graph->SetPoint(59,171.4286,0.01973297);
   graph->SetPoint(60,178.5714,0.005462803);
   graph->SetPoint(61,185.7143,0.001413049);
   graph->SetPoint(62,192.8571,0.0003415206);
   graph->SetPoint(63,200,7.7125e-05);
   graph->SetPoint(64,200,7.7125e-05);
   graph->SetPoint(65,207.1429,7.7125e-05);
   graph->SetPoint(66,207.1429,0);
   
   TH1 *myFit_Int[jetcat]_Norm[met,jetcat]11 = new TH1F("myFit_Int[jetcat]_Norm[met,jetcat]11","Projection of Higgs to WW",100,-28.57143,228.5714);
   myFit_Int[jetcat]_Norm[met,jetcat]11->SetMinimum(0);
   myFit_Int[jetcat]_Norm[met,jetcat]11->SetMaximum(2592.07);
   myFit_Int[jetcat]_Norm[met,jetcat]11->SetDirectory(0);
   myFit_Int[jetcat]_Norm[met,jetcat]11->SetStats(0);
   myFit_Int[jetcat]_Norm[met,jetcat]11->SetMarkerStyle(8);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetXaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetXaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetYaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetYaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetZaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]11->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[jetcat]_Norm[met,jetcat]11);
   
   graph->Draw("l");
   
   TH1 *frame_204242912 = new TH1D("frame_204242912","A RooPlot of "E_{T}^{miss}"",28,0,200);
   frame_204242912->SetMaximum(2474.249);
   frame_204242912->SetDirectory(0);
   frame_204242912->SetStats(0);
   frame_204242912->SetMarkerStyle(8);
   frame_204242912->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_204242912->GetXaxis()->SetLabelFont(132);
   frame_204242912->GetXaxis()->SetLabelSize(0.05);
   frame_204242912->GetXaxis()->SetTitleSize(0.06);
   frame_204242912->GetXaxis()->SetTitleFont(132);
   frame_204242912->GetYaxis()->SetTitle("Events");
   frame_204242912->GetYaxis()->SetLabelFont(132);
   frame_204242912->GetYaxis()->SetLabelSize(0.05);
   frame_204242912->GetYaxis()->SetTitleSize(0.06);
   frame_204242912->GetYaxis()->SetTitleFont(132);
   frame_204242912->GetZaxis()->SetLabelFont(132);
   frame_204242912->GetZaxis()->SetLabelSize(0.05);
   frame_204242912->GetZaxis()->SetTitleSize(0.06);
   frame_204242912->GetZaxis()->SetTitleFont(132);
   frame_204242912->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
