{
//=========Macro generated from canvas: c/fitResult
//=========  (Sat Feb 19 13:09:13 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-57.83133,-80.91785,424.0964,424.8187);
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
   
   TH1D *frame_1072d5c10__6 = new TH1D("frame_1072d5c10__6","A RooPlot of "p_{T}^{max}"",30,0,400);
   frame_1072d5c10__6->SetMaximum(399.5319);
   frame_1072d5c10__6->SetDirectory(0);
   frame_1072d5c10__6->SetStats(0);
   frame_1072d5c10__6->SetMarkerStyle(8);
   frame_1072d5c10__6->GetXaxis()->SetTitle("p_{T}^{max} [GeV]");
   frame_1072d5c10__6->GetXaxis()->SetLabelFont(132);
   frame_1072d5c10__6->GetXaxis()->SetLabelSize(0.05);
   frame_1072d5c10__6->GetXaxis()->SetTitleSize(0.06);
   frame_1072d5c10__6->GetXaxis()->SetTitleFont(132);
   frame_1072d5c10__6->GetYaxis()->SetTitle("Events");
   frame_1072d5c10__6->GetYaxis()->SetLabelFont(132);
   frame_1072d5c10__6->GetYaxis()->SetLabelSize(0.05);
   frame_1072d5c10__6->GetYaxis()->SetTitleSize(0.06);
   frame_1072d5c10__6->GetYaxis()->SetTitleFont(132);
   frame_1072d5c10__6->GetZaxis()->SetLabelFont(132);
   frame_1072d5c10__6->GetZaxis()->SetLabelSize(0.05);
   frame_1072d5c10__6->GetZaxis()->SetTitleSize(0.06);
   frame_1072d5c10__6->GetZaxis()->SetTitleFont(132);
   frame_1072d5c10__6->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__maxPtEle");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,6.666667,0);
   grae->SetPointError(0,6.666667,6.666667,0,1.147874);
   grae->SetPoint(1,20,1);
   grae->SetPointError(1,6.666667,6.666667,0.8272462,2.299527);
   grae->SetPoint(2,33.33333,10);
   grae->SetPointError(2,6.666667,6.666667,3.108694,4.26695);
   grae->SetPoint(3,46.66667,66);
   grae->SetPointError(3,6.666667,6.666667,8.103403,9.165094);
   grae->SetPoint(4,60,124);
   grae->SetPointError(4,6.666667,6.666667,10.64675,11.64675);
   grae->SetPoint(5,73.33333,190);
   grae->SetPointError(5,6.666667,6.666667,13.29311,14.29311);
   grae->SetPoint(6,86.66667,248);
   grae->SetPointError(6,6.666667,6.666667,15.25595,16.25595);
   grae->SetPoint(7,100,318);
   grae->SetPointError(7,6.666667,6.666667,17.33956,18.33956);
   grae->SetPoint(8,113.3333,337);
   grae->SetPointError(8,6.666667,6.666667,17.86437,18.86437);
   grae->SetPoint(9,126.6667,327);
   grae->SetPointError(9,6.666667,6.666667,17.59005,18.59005);
   grae->SetPoint(10,140,361);
   grae->SetPointError(10,6.666667,6.666667,18.50658,19.50658);
   grae->SetPoint(11,153.3333,329);
   grae->SetPointError(11,6.666667,6.666667,17.64525,18.64525);
   grae->SetPoint(12,166.6667,304);
   grae->SetPointError(12,6.666667,6.666667,16.94276,17.94276);
   grae->SetPoint(13,180,268);
   grae->SetPointError(13,6.666667,6.666667,15.87834,16.87834);
   grae->SetPoint(14,193.3333,251);
   grae->SetPointError(14,6.666667,6.666667,15.35087,16.35087);
   grae->SetPoint(15,206.6667,191);
   grae->SetPointError(15,6.666667,6.666667,13.32932,14.32932);
   grae->SetPoint(16,220,177);
   grae->SetPointError(16,6.666667,6.666667,12.81353,13.81353);
   grae->SetPoint(17,233.3333,138);
   grae->SetPointError(17,6.666667,6.666667,11.25798,12.25798);
   grae->SetPoint(18,246.6667,92);
   grae->SetPointError(18,6.666667,6.666667,9.574201,10.62644);
   grae->SetPoint(19,260,61);
   grae->SetPointError(19,6.666667,6.666667,7.788779,8.852952);
   grae->SetPoint(20,273.3333,41);
   grae->SetPointError(20,6.666667,6.666667,6.376898,7.455185);
   grae->SetPoint(21,286.6667,38);
   grae->SetPointError(21,6.666667,6.666667,6.137163,7.218484);
   grae->SetPoint(22,300,15);
   grae->SetPointError(22,6.666667,6.666667,3.82938,4.958738);
   grae->SetPoint(23,313.3333,12);
   grae->SetPointError(23,6.666667,6.666667,3.415266,4.559819);
   grae->SetPoint(24,326.6667,7);
   grae->SetPointError(24,6.666667,6.666667,2.58147,3.770281);
   grae->SetPoint(25,340,5);
   grae->SetPointError(25,6.666667,6.666667,2.159691,3.382473);
   grae->SetPoint(26,353.3333,2);
   grae->SetPointError(26,6.666667,6.666667,1.291815,2.63786);
   grae->SetPoint(27,366.6667,3);
   grae->SetPointError(27,6.666667,6.666667,1.632705,2.918186);
   grae->SetPoint(28,380,0);
   grae->SetPointError(28,6.666667,6.666667,0,1.147874);
   grae->SetPoint(29,393.3333,5);
   grae->SetPointError(29,6.666667,6.666667,2.159691,3.382473);
   
   TH1F *h_T13__7 = new TH1F("h_T13__7","Histogram of T1_plot__maxPtEle",100,0,440);
   h_T13__7->SetMinimum(0);
   h_T13__7->SetMaximum(418.5572);
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
   
   TGraph *graph = new TGraph(71);
   graph->SetName("myFit_Norm[maxPtEle]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-13.33333,0);
   graph->SetPoint(1,-13.33333,1.104548);
   graph->SetPoint(2,0,1.104548);
   graph->SetPoint(3,6.666667,2.136251);
   graph->SetPoint(4,13.33333,3.970775);
   graph->SetPoint(5,20,7.093389);
   graph->SetPoint(6,26.66667,12.17833);
   graph->SetPoint(7,30,15.72128);
   graph->SetPoint(8,33.33333,20.09448);
   graph->SetPoint(9,36.66667,25.43049);
   graph->SetPoint(10,40,31.86555);
   graph->SetPoint(11,43.33333,39.53457);
   graph->SetPoint(12,46.66667,48.56478);
   graph->SetPoint(13,50,59.06832);
   graph->SetPoint(14,53.33333,71.13392);
   graph->SetPoint(15,56.66667,84.81793);
   graph->SetPoint(16,60,100.1354);
   graph->SetPoint(17,63.33333,117.0513);
   graph->SetPoint(18,66.66667,135.4732);
   graph->SetPoint(19,70,155.2458);
   graph->SetPoint(20,73.33333,176.1469);
   graph->SetPoint(21,80,220.1161);
   graph->SetPoint(22,86.66667,264.3529);
   graph->SetPoint(23,90,285.4193);
   graph->SetPoint(24,93.33333,305.1207);
   graph->SetPoint(25,96.66667,322.96);
   graph->SetPoint(26,100,338.4656);
   graph->SetPoint(27,101.6667,345.208);
   graph->SetPoint(28,103.3333,351.212);
   graph->SetPoint(29,105,356.4347);
   graph->SetPoint(30,106.6667,360.8385);
   graph->SetPoint(31,108.3333,364.3913);
   graph->SetPoint(32,110,367.067);
   graph->SetPoint(33,111.6667,368.8458);
   graph->SetPoint(34,113.3333,369.7146);
   graph->SetPoint(35,120,368.78);
   graph->SetPoint(36,126.6667,365.188);
   graph->SetPoint(37,133.3333,359.0899);
   graph->SetPoint(38,140,350.6124);
   graph->SetPoint(39,146.6667,339.9295);
   graph->SetPoint(40,153.3333,327.2563);
   graph->SetPoint(41,160,312.8416);
   graph->SetPoint(42,166.6667,296.9604);
   graph->SetPoint(43,173.3333,279.9045);
   graph->SetPoint(44,186.6667,243.4699);
   graph->SetPoint(45,200,205.8877);
   graph->SetPoint(46,213.3333,169.2643);
   graph->SetPoint(47,220,151.8585);
   graph->SetPoint(48,226.6667,135.2852);
   graph->SetPoint(49,233.3333,119.6738);
   graph->SetPoint(50,240,105.1199);
   graph->SetPoint(51,246.6667,91.68717);
   graph->SetPoint(52,253.3333,79.40897);
   graph->SetPoint(53,260,68.29172);
   graph->SetPoint(54,266.6667,58.31819);
   graph->SetPoint(55,273.3333,49.45127);
   graph->SetPoint(56,280,41.63785);
   graph->SetPoint(57,286.6667,34.81262);
   graph->SetPoint(58,293.3333,28.90164);
   graph->SetPoint(59,300,23.82571);
   graph->SetPoint(60,306.6667,19.50323);
   graph->SetPoint(61,320,12.795);
   graph->SetPoint(62,333.3333,8.160638);
   graph->SetPoint(63,346.6667,5.060084);
   graph->SetPoint(64,360,3.05029);
   graph->SetPoint(65,373.3333,1.787617);
   graph->SetPoint(66,386.6667,1.018492);
   graph->SetPoint(67,400,0.5641449);
   graph->SetPoint(68,400,0.5641449);
   graph->SetPoint(69,413.3333,0.5641449);
   graph->SetPoint(70,413.3333,0);
   
   TH1F *myFit_Norm[maxPtEle]2__8 = new TH1F("myFit_Norm[maxPtEle]2__8","Projection of Higgs to WW",100,-56,456);
   myFit_Norm[maxPtEle]2__8->SetMinimum(0);
   myFit_Norm[maxPtEle]2__8->SetMaximum(406.6861);
   myFit_Norm[maxPtEle]2__8->SetDirectory(0);
   myFit_Norm[maxPtEle]2__8->SetStats(0);
   myFit_Norm[maxPtEle]2__8->SetMarkerStyle(8);
   myFit_Norm[maxPtEle]2__8->GetXaxis()->SetLabelFont(132);
   myFit_Norm[maxPtEle]2__8->GetXaxis()->SetLabelSize(0.05);
   myFit_Norm[maxPtEle]2__8->GetXaxis()->SetTitleSize(0.06);
   myFit_Norm[maxPtEle]2__8->GetXaxis()->SetTitleFont(132);
   myFit_Norm[maxPtEle]2__8->GetYaxis()->SetLabelFont(132);
   myFit_Norm[maxPtEle]2__8->GetYaxis()->SetLabelSize(0.05);
   myFit_Norm[maxPtEle]2__8->GetYaxis()->SetTitleSize(0.06);
   myFit_Norm[maxPtEle]2__8->GetYaxis()->SetTitleFont(132);
   myFit_Norm[maxPtEle]2__8->GetZaxis()->SetLabelFont(132);
   myFit_Norm[maxPtEle]2__8->GetZaxis()->SetLabelSize(0.05);
   myFit_Norm[maxPtEle]2__8->GetZaxis()->SetTitleSize(0.06);
   myFit_Norm[maxPtEle]2__8->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Norm[maxPtEle]2);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__maxPtEle");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,6.666667,0);
   grae->SetPointError(0,6.666667,6.666667,0,1.147874);
   grae->SetPoint(1,20,1);
   grae->SetPointError(1,6.666667,6.666667,0.8272462,2.299527);
   grae->SetPoint(2,33.33333,10);
   grae->SetPointError(2,6.666667,6.666667,3.108694,4.26695);
   grae->SetPoint(3,46.66667,66);
   grae->SetPointError(3,6.666667,6.666667,8.103403,9.165094);
   grae->SetPoint(4,60,124);
   grae->SetPointError(4,6.666667,6.666667,10.64675,11.64675);
   grae->SetPoint(5,73.33333,190);
   grae->SetPointError(5,6.666667,6.666667,13.29311,14.29311);
   grae->SetPoint(6,86.66667,248);
   grae->SetPointError(6,6.666667,6.666667,15.25595,16.25595);
   grae->SetPoint(7,100,318);
   grae->SetPointError(7,6.666667,6.666667,17.33956,18.33956);
   grae->SetPoint(8,113.3333,337);
   grae->SetPointError(8,6.666667,6.666667,17.86437,18.86437);
   grae->SetPoint(9,126.6667,327);
   grae->SetPointError(9,6.666667,6.666667,17.59005,18.59005);
   grae->SetPoint(10,140,361);
   grae->SetPointError(10,6.666667,6.666667,18.50658,19.50658);
   grae->SetPoint(11,153.3333,329);
   grae->SetPointError(11,6.666667,6.666667,17.64525,18.64525);
   grae->SetPoint(12,166.6667,304);
   grae->SetPointError(12,6.666667,6.666667,16.94276,17.94276);
   grae->SetPoint(13,180,268);
   grae->SetPointError(13,6.666667,6.666667,15.87834,16.87834);
   grae->SetPoint(14,193.3333,251);
   grae->SetPointError(14,6.666667,6.666667,15.35087,16.35087);
   grae->SetPoint(15,206.6667,191);
   grae->SetPointError(15,6.666667,6.666667,13.32932,14.32932);
   grae->SetPoint(16,220,177);
   grae->SetPointError(16,6.666667,6.666667,12.81353,13.81353);
   grae->SetPoint(17,233.3333,138);
   grae->SetPointError(17,6.666667,6.666667,11.25798,12.25798);
   grae->SetPoint(18,246.6667,92);
   grae->SetPointError(18,6.666667,6.666667,9.574201,10.62644);
   grae->SetPoint(19,260,61);
   grae->SetPointError(19,6.666667,6.666667,7.788779,8.852952);
   grae->SetPoint(20,273.3333,41);
   grae->SetPointError(20,6.666667,6.666667,6.376898,7.455185);
   grae->SetPoint(21,286.6667,38);
   grae->SetPointError(21,6.666667,6.666667,6.137163,7.218484);
   grae->SetPoint(22,300,15);
   grae->SetPointError(22,6.666667,6.666667,3.82938,4.958738);
   grae->SetPoint(23,313.3333,12);
   grae->SetPointError(23,6.666667,6.666667,3.415266,4.559819);
   grae->SetPoint(24,326.6667,7);
   grae->SetPointError(24,6.666667,6.666667,2.58147,3.770281);
   grae->SetPoint(25,340,5);
   grae->SetPointError(25,6.666667,6.666667,2.159691,3.382473);
   grae->SetPoint(26,353.3333,2);
   grae->SetPointError(26,6.666667,6.666667,1.291815,2.63786);
   grae->SetPoint(27,366.6667,3);
   grae->SetPointError(27,6.666667,6.666667,1.632705,2.918186);
   grae->SetPoint(28,380,0);
   grae->SetPointError(28,6.666667,6.666667,0,1.147874);
   grae->SetPoint(29,393.3333,5);
   grae->SetPointError(29,6.666667,6.666667,2.159691,3.382473);
   
   TH1F *h_T14__9 = new TH1F("h_T14__9","Histogram of T1_plot__maxPtEle",100,0,440);
   h_T14__9->SetMinimum(0);
   h_T14__9->SetMaximum(418.5572);
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
   
   TH1D *frame_1072d5c10__10 = new TH1D("frame_1072d5c10__10","A RooPlot of "p_{T}^{max}"",30,0,400);
   frame_1072d5c10__10->SetMaximum(399.5319);
   frame_1072d5c10__10->SetDirectory(0);
   frame_1072d5c10__10->SetStats(0);
   frame_1072d5c10__10->SetMarkerStyle(8);
   frame_1072d5c10__10->GetXaxis()->SetTitle("p_{T}^{max} [GeV]");
   frame_1072d5c10__10->GetXaxis()->SetLabelFont(132);
   frame_1072d5c10__10->GetXaxis()->SetLabelSize(0.05);
   frame_1072d5c10__10->GetXaxis()->SetTitleSize(0.06);
   frame_1072d5c10__10->GetXaxis()->SetTitleFont(132);
   frame_1072d5c10__10->GetYaxis()->SetTitle("Events");
   frame_1072d5c10__10->GetYaxis()->SetLabelFont(132);
   frame_1072d5c10__10->GetYaxis()->SetLabelSize(0.05);
   frame_1072d5c10__10->GetYaxis()->SetTitleSize(0.06);
   frame_1072d5c10__10->GetYaxis()->SetTitleFont(132);
   frame_1072d5c10__10->GetZaxis()->SetLabelFont(132);
   frame_1072d5c10__10->GetZaxis()->SetLabelSize(0.05);
   frame_1072d5c10__10->GetZaxis()->SetTitleSize(0.06);
   frame_1072d5c10__10->GetZaxis()->SetTitleFont(132);
   frame_1072d5c10__10->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
