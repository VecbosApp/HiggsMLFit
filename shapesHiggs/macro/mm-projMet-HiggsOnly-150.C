{
//=========Macro generated from canvas: c/fitResult
//=========  (Fri Feb 18 12:28:05 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-36.14458,-101.5392,265.0602,533.0809);
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
   
   TH1D *frame_1070e7500__6 = new TH1D("frame_1070e7500__6","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1070e7500__6->SetMaximum(501.3499);
   frame_1070e7500__6->SetDirectory(0);
   frame_1070e7500__6->SetStats(0);
   frame_1070e7500__6->SetMarkerStyle(8);
   frame_1070e7500__6->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1070e7500__6->GetXaxis()->SetLabelFont(132);
   frame_1070e7500__6->GetXaxis()->SetLabelSize(0.05);
   frame_1070e7500__6->GetXaxis()->SetTitleSize(0.06);
   frame_1070e7500__6->GetXaxis()->SetTitleFont(132);
   frame_1070e7500__6->GetYaxis()->SetTitle("Events");
   frame_1070e7500__6->GetYaxis()->SetLabelFont(132);
   frame_1070e7500__6->GetYaxis()->SetLabelSize(0.05);
   frame_1070e7500__6->GetYaxis()->SetTitleSize(0.06);
   frame_1070e7500__6->GetYaxis()->SetTitleFont(132);
   frame_1070e7500__6->GetZaxis()->SetLabelFont(132);
   frame_1070e7500__6->GetZaxis()->SetLabelSize(0.05);
   frame_1070e7500__6->GetZaxis()->SetTitleSize(0.06);
   frame_1070e7500__6->GetZaxis()->SetTitleFont(132);
   frame_1070e7500__6->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,44);
   grae->SetPointError(0,4.166667,4.166667,6.60794,7.68351);
   grae->SetPoint(1,12.5,66);
   grae->SetPointError(1,4.166667,4.166667,8.103403,9.165094);
   grae->SetPoint(2,20.83333,64);
   grae->SetPointError(2,4.166667,4.166667,7.979042,9.041691);
   grae->SetPoint(3,29.16667,105);
   grae->SetPointError(3,4.166667,4.166667,9.759142,10.75914);
   grae->SetPoint(4,37.5,156);
   grae->SetPointError(4,4.166667,4.166667,12,13);
   grae->SetPoint(5,45.83333,286);
   grae->SetPointError(5,4.166667,4.166667,16.41892,17.41892);
   grae->SetPoint(6,54.16667,442);
   grae->SetPointError(6,4.166667,4.166667,20.52974,21.52974);
   grae->SetPoint(7,62.5,404);
   grae->SetPointError(7,4.166667,4.166667,19.60597,20.60597);
   grae->SetPoint(8,70.83333,208);
   grae->SetPointError(8,4.166667,4.166667,13.93087,14.93087);
   grae->SetPoint(9,79.16667,50);
   grae->SetPointError(9,4.166667,4.166667,7.047337,8.118225);
   grae->SetPoint(10,87.5,8);
   grae->SetPointError(10,4.166667,4.166667,2.768386,3.945142);
   grae->SetPoint(11,95.83333,4);
   grae->SetPointError(11,4.166667,4.166667,1.914339,3.162753);
   grae->SetPoint(12,104.1667,1);
   grae->SetPointError(12,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(13,112.5,0);
   grae->SetPointError(13,4.166667,4.166667,0,1.147874);
   grae->SetPoint(14,120.8333,0);
   grae->SetPointError(14,4.166667,4.166667,0,1.147874);
   grae->SetPoint(15,129.1667,0);
   grae->SetPointError(15,4.166667,4.166667,0,1.147874);
   grae->SetPoint(16,137.5,0);
   grae->SetPointError(16,4.166667,4.166667,0,1.147874);
   grae->SetPoint(17,145.8333,1);
   grae->SetPointError(17,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(18,154.1667,0);
   grae->SetPointError(18,4.166667,4.166667,0,1.147874);
   grae->SetPoint(19,162.5,0);
   grae->SetPointError(19,4.166667,4.166667,0,1.147874);
   grae->SetPoint(20,170.8333,0);
   grae->SetPointError(20,4.166667,4.166667,0,1.147874);
   grae->SetPoint(21,179.1667,0);
   grae->SetPointError(21,4.166667,4.166667,0,1.147874);
   grae->SetPoint(22,187.5,0);
   grae->SetPointError(22,4.166667,4.166667,0,1.147874);
   grae->SetPoint(23,195.8333,0);
   grae->SetPointError(23,4.166667,4.166667,0,1.147874);
   grae->SetPoint(24,204.1667,0);
   grae->SetPointError(24,4.166667,4.166667,0,1.147874);
   grae->SetPoint(25,212.5,0);
   grae->SetPointError(25,4.166667,4.166667,0,1.147874);
   grae->SetPoint(26,220.8333,0);
   grae->SetPointError(26,4.166667,4.166667,0,1.147874);
   grae->SetPoint(27,229.1667,0);
   grae->SetPointError(27,4.166667,4.166667,0,1.147874);
   grae->SetPoint(28,237.5,0);
   grae->SetPointError(28,4.166667,4.166667,0,1.147874);
   grae->SetPoint(29,245.8333,0);
   grae->SetPointError(29,4.166667,4.166667,0,1.147874);
   
   TH1F *h_T13__7 = new TH1F("h_T13__7","Histogram of T1_plot__projMet",100,0,275);
   h_T13__7->SetMinimum(0);
   h_T13__7->SetMaximum(509.8827);
   h_T13__7->SetDirectory(0);
   h_T13__7->SetStats(0);
   h_T13__7->SetMarkerStyle(8);
   h_T13__7->GetXaxis()->SetLabelFont(132);
   h_T13__7->GetXaxis()->SetLabelSize(0.05);
   h_T13__7->GetXaxis()->SetTitleSize(0.06);
   h_T13__7->GetXaxis()->SetTitleFont(132);
   h_T13__7->GetYaxis()->SetLabelFont(132);
   h_T13__7->GetYaxis()->SetLabelSize(0.05);
   h_T13__7->GetYaxis()->SetTitleSize(0.06);
   h_T13__7->GetYaxis()->SetTitleFont(132);
   h_T13__7->GetZaxis()->SetLabelFont(132);
   h_T13__7->GetZaxis()->SetLabelSize(0.05);
   h_T13__7->GetZaxis()->SetTitleSize(0.06);
   h_T13__7->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T13);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(89);
   graph->SetName("myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-8.333333,0);
   graph->SetPoint(1,-8.333333,45.67984);
   graph->SetPoint(2,0,45.67984);
   graph->SetPoint(3,8.333333,52.12746);
   graph->SetPoint(4,12.5,56.79576);
   graph->SetPoint(5,16.66667,62.96399);
   graph->SetPoint(6,20.83333,71.30359);
   graph->SetPoint(7,22.91667,76.59439);
   graph->SetPoint(8,25,82.86043);
   graph->SetPoint(9,27.08333,90.3279);
   graph->SetPoint(10,29.16667,99.28012);
   graph->SetPoint(11,31.25,110.0696);
   graph->SetPoint(12,33.33333,123.1289);
   graph->SetPoint(13,35.41667,138.9765);
   graph->SetPoint(14,37.5,158.2091);
   graph->SetPoint(15,38.54167,169.2948);
   graph->SetPoint(16,39.58333,181.4662);
   graph->SetPoint(17,40.625,194.796);
   graph->SetPoint(18,41.66667,209.3452);
   graph->SetPoint(19,42.70833,225.1551);
   graph->SetPoint(20,43.75,242.239);
   graph->SetPoint(21,44.79167,260.5706);
   graph->SetPoint(22,45.83333,280.0724);
   graph->SetPoint(23,47.91667,321.9421);
   graph->SetPoint(24,50,365.7384);
   graph->SetPoint(25,52.08333,407.9346);
   graph->SetPoint(26,53.125,426.9858);
   graph->SetPoint(27,54.16667,443.8131);
   graph->SetPoint(28,55.20833,457.7828);
   graph->SetPoint(29,56.25,468.3268);
   graph->SetPoint(30,56.77083,472.1665);
   graph->SetPoint(31,57.29167,474.9907);
   graph->SetPoint(32,57.8125,476.7673);
   graph->SetPoint(33,58.33333,477.4761);
   graph->SetPoint(34,58.85417,476.888);
   graph->SetPoint(35,59.375,474.6156);
   graph->SetPoint(36,59.89583,470.6793);
   graph->SetPoint(37,60.41667,465.1279);
   graph->SetPoint(38,60.9375,458.0294);
   graph->SetPoint(39,61.45833,449.4692);
   graph->SetPoint(40,61.97917,439.5489);
   graph->SetPoint(41,62.5,428.3834);
   graph->SetPoint(42,63.02083,416.0986);
   graph->SetPoint(43,63.54167,402.8289);
   graph->SetPoint(44,64.58333,373.8979);
   graph->SetPoint(45,65.625,342.7326);
   graph->SetPoint(46,66.66667,310.4453);
   graph->SetPoint(47,68.75,246.4292);
   graph->SetPoint(48,69.79167,216.275);
   graph->SetPoint(49,70.83333,188.1099);
   graph->SetPoint(50,71.875,162.2781);
   graph->SetPoint(51,72.91667,138.9655);
   graph->SetPoint(52,73.95833,118.2253);
   graph->SetPoint(53,75,100.0057);
   graph->SetPoint(54,76.04167,84.17767);
   graph->SetPoint(55,77.08333,70.56114);
   graph->SetPoint(56,78.125,58.94634);
   graph->SetPoint(57,79.16667,49.1114);
   graph->SetPoint(58,80.20833,40.83549);
   graph->SetPoint(59,81.25,33.90795);
   graph->SetPoint(60,82.29167,28.13413);
   graph->SetPoint(61,83.33333,23.33861);
   graph->SetPoint(62,85.41667,16.08254);
   graph->SetPoint(63,87.5,11.13495);
   graph->SetPoint(64,89.58333,7.768383);
   graph->SetPoint(65,91.66667,5.473494);
   graph->SetPoint(66,95.83333,2.816791);
   graph->SetPoint(67,100,1.530104);
   graph->SetPoint(68,108.3333,0.534673);
   graph->SetPoint(69,116.6667,0.2302921);
   graph->SetPoint(70,125,0.1181053);
   graph->SetPoint(71,133.3333,0.06956357);
   graph->SetPoint(72,141.6667,0.04562254);
   graph->SetPoint(73,150,0.0325089);
   graph->SetPoint(74,158.3333,0.02469847);
   graph->SetPoint(75,166.6667,0.01972356);
   graph->SetPoint(76,175,0.01637811);
   graph->SetPoint(77,183.3333,0.01402662);
   graph->SetPoint(78,191.6667,0.01231239);
   graph->SetPoint(79,200,0.01102422);
   graph->SetPoint(80,208.3333,0.01003118);
   graph->SetPoint(81,216.6667,0.009248896);
   graph->SetPoint(82,225,0.008621102);
   graph->SetPoint(83,233.3333,0.008109155);
   graph->SetPoint(84,241.6667,0.007685819);
   graph->SetPoint(85,250,0.007331455);
   graph->SetPoint(86,250,0.007331455);
   graph->SetPoint(87,258.3333,0.007331455);
   graph->SetPoint(88,258.3333,0);
   
   TH1F *myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8 = new TH1F("myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8","Projection of Higgs to WW",100,-35,285);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->SetMinimum(0);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->SetMaximum(525.2237);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->SetDirectory(0);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->SetStats(0);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->SetMarkerStyle(8);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetXaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetXaxis()->SetTitleFont(132);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetYaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetYaxis()->SetTitleFont(132);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetZaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2__8->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[maxPtEle]_Norm[maxPtEle,projMet]2);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,44);
   grae->SetPointError(0,4.166667,4.166667,6.60794,7.68351);
   grae->SetPoint(1,12.5,66);
   grae->SetPointError(1,4.166667,4.166667,8.103403,9.165094);
   grae->SetPoint(2,20.83333,64);
   grae->SetPointError(2,4.166667,4.166667,7.979042,9.041691);
   grae->SetPoint(3,29.16667,105);
   grae->SetPointError(3,4.166667,4.166667,9.759142,10.75914);
   grae->SetPoint(4,37.5,156);
   grae->SetPointError(4,4.166667,4.166667,12,13);
   grae->SetPoint(5,45.83333,286);
   grae->SetPointError(5,4.166667,4.166667,16.41892,17.41892);
   grae->SetPoint(6,54.16667,442);
   grae->SetPointError(6,4.166667,4.166667,20.52974,21.52974);
   grae->SetPoint(7,62.5,404);
   grae->SetPointError(7,4.166667,4.166667,19.60597,20.60597);
   grae->SetPoint(8,70.83333,208);
   grae->SetPointError(8,4.166667,4.166667,13.93087,14.93087);
   grae->SetPoint(9,79.16667,50);
   grae->SetPointError(9,4.166667,4.166667,7.047337,8.118225);
   grae->SetPoint(10,87.5,8);
   grae->SetPointError(10,4.166667,4.166667,2.768386,3.945142);
   grae->SetPoint(11,95.83333,4);
   grae->SetPointError(11,4.166667,4.166667,1.914339,3.162753);
   grae->SetPoint(12,104.1667,1);
   grae->SetPointError(12,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(13,112.5,0);
   grae->SetPointError(13,4.166667,4.166667,0,1.147874);
   grae->SetPoint(14,120.8333,0);
   grae->SetPointError(14,4.166667,4.166667,0,1.147874);
   grae->SetPoint(15,129.1667,0);
   grae->SetPointError(15,4.166667,4.166667,0,1.147874);
   grae->SetPoint(16,137.5,0);
   grae->SetPointError(16,4.166667,4.166667,0,1.147874);
   grae->SetPoint(17,145.8333,1);
   grae->SetPointError(17,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(18,154.1667,0);
   grae->SetPointError(18,4.166667,4.166667,0,1.147874);
   grae->SetPoint(19,162.5,0);
   grae->SetPointError(19,4.166667,4.166667,0,1.147874);
   grae->SetPoint(20,170.8333,0);
   grae->SetPointError(20,4.166667,4.166667,0,1.147874);
   grae->SetPoint(21,179.1667,0);
   grae->SetPointError(21,4.166667,4.166667,0,1.147874);
   grae->SetPoint(22,187.5,0);
   grae->SetPointError(22,4.166667,4.166667,0,1.147874);
   grae->SetPoint(23,195.8333,0);
   grae->SetPointError(23,4.166667,4.166667,0,1.147874);
   grae->SetPoint(24,204.1667,0);
   grae->SetPointError(24,4.166667,4.166667,0,1.147874);
   grae->SetPoint(25,212.5,0);
   grae->SetPointError(25,4.166667,4.166667,0,1.147874);
   grae->SetPoint(26,220.8333,0);
   grae->SetPointError(26,4.166667,4.166667,0,1.147874);
   grae->SetPoint(27,229.1667,0);
   grae->SetPointError(27,4.166667,4.166667,0,1.147874);
   grae->SetPoint(28,237.5,0);
   grae->SetPointError(28,4.166667,4.166667,0,1.147874);
   grae->SetPoint(29,245.8333,0);
   grae->SetPointError(29,4.166667,4.166667,0,1.147874);
   
   TH1F *h_T14__9 = new TH1F("h_T14__9","Histogram of T1_plot__projMet",100,0,275);
   h_T14__9->SetMinimum(0);
   h_T14__9->SetMaximum(509.8827);
   h_T14__9->SetDirectory(0);
   h_T14__9->SetStats(0);
   h_T14__9->SetMarkerStyle(8);
   h_T14__9->GetXaxis()->SetLabelFont(132);
   h_T14__9->GetXaxis()->SetLabelSize(0.05);
   h_T14__9->GetXaxis()->SetTitleSize(0.06);
   h_T14__9->GetXaxis()->SetTitleFont(132);
   h_T14__9->GetYaxis()->SetLabelFont(132);
   h_T14__9->GetYaxis()->SetLabelSize(0.05);
   h_T14__9->GetYaxis()->SetTitleSize(0.06);
   h_T14__9->GetYaxis()->SetTitleFont(132);
   h_T14__9->GetZaxis()->SetLabelFont(132);
   h_T14__9->GetZaxis()->SetLabelSize(0.05);
   h_T14__9->GetZaxis()->SetTitleSize(0.06);
   h_T14__9->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T14);
   
   grae->Draw("p");
   
   TH1D *frame_1070e7500__10 = new TH1D("frame_1070e7500__10","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1070e7500__10->SetMaximum(501.3499);
   frame_1070e7500__10->SetDirectory(0);
   frame_1070e7500__10->SetStats(0);
   frame_1070e7500__10->SetMarkerStyle(8);
   frame_1070e7500__10->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1070e7500__10->GetXaxis()->SetLabelFont(132);
   frame_1070e7500__10->GetXaxis()->SetLabelSize(0.05);
   frame_1070e7500__10->GetXaxis()->SetTitleSize(0.06);
   frame_1070e7500__10->GetXaxis()->SetTitleFont(132);
   frame_1070e7500__10->GetYaxis()->SetTitle("Events");
   frame_1070e7500__10->GetYaxis()->SetLabelFont(132);
   frame_1070e7500__10->GetYaxis()->SetLabelSize(0.05);
   frame_1070e7500__10->GetYaxis()->SetTitleSize(0.06);
   frame_1070e7500__10->GetYaxis()->SetTitleFont(132);
   frame_1070e7500__10->GetZaxis()->SetLabelFont(132);
   frame_1070e7500__10->GetZaxis()->SetLabelSize(0.05);
   frame_1070e7500__10->GetZaxis()->SetTitleSize(0.06);
   frame_1070e7500__10->GetZaxis()->SetTitleFont(132);
   frame_1070e7500__10->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
