{
//=========Macro generated from canvas: c/fitResult
//=========  (Sat Feb 19 12:44:05 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-26.0241,-38.81217,190.8434,203.7639);
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
   
   TH1D *frame_10618a760__1 = new TH1D("frame_10618a760__1","A RooPlot of "#Delta#phi"",30,0,180);
   frame_10618a760__1->SetMaximum(191.6351);
   frame_10618a760__1->SetDirectory(0);
   frame_10618a760__1->SetStats(0);
   frame_10618a760__1->SetMarkerStyle(8);
   frame_10618a760__1->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_10618a760__1->GetXaxis()->SetLabelFont(132);
   frame_10618a760__1->GetXaxis()->SetLabelSize(0.05);
   frame_10618a760__1->GetXaxis()->SetTitleSize(0.06);
   frame_10618a760__1->GetXaxis()->SetTitleFont(132);
   frame_10618a760__1->GetYaxis()->SetTitle("Events");
   frame_10618a760__1->GetYaxis()->SetLabelFont(132);
   frame_10618a760__1->GetYaxis()->SetLabelSize(0.05);
   frame_10618a760__1->GetYaxis()->SetTitleSize(0.06);
   frame_10618a760__1->GetYaxis()->SetTitleFont(132);
   frame_10618a760__1->GetZaxis()->SetLabelFont(132);
   frame_10618a760__1->GetZaxis()->SetLabelSize(0.05);
   frame_10618a760__1->GetZaxis()->SetTitleSize(0.06);
   frame_10618a760__1->GetZaxis()->SetTitleFont(132);
   frame_10618a760__1->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3,0);
   grae->SetPointError(0,3,3,0,1.147874);
   grae->SetPoint(1,9,2);
   grae->SetPointError(1,3,3,1.291815,2.63786);
   grae->SetPoint(2,15,0);
   grae->SetPointError(2,3,3,0,1.147874);
   grae->SetPoint(3,21,0);
   grae->SetPointError(3,3,3,0,1.147874);
   grae->SetPoint(4,27,3);
   grae->SetPointError(4,3,3,1.632705,2.918186);
   grae->SetPoint(5,33,1);
   grae->SetPointError(5,3,3,0.8272462,2.299527);
   grae->SetPoint(6,39,1);
   grae->SetPointError(6,3,3,0.8272462,2.299527);
   grae->SetPoint(7,45,2);
   grae->SetPointError(7,3,3,1.291815,2.63786);
   grae->SetPoint(8,51,2);
   grae->SetPointError(8,3,3,1.291815,2.63786);
   grae->SetPoint(9,57,1);
   grae->SetPointError(9,3,3,0.8272462,2.299527);
   grae->SetPoint(10,63,1);
   grae->SetPointError(10,3,3,0.8272462,2.299527);
   grae->SetPoint(11,69,3);
   grae->SetPointError(11,3,3,1.632705,2.918186);
   grae->SetPoint(12,75,3);
   grae->SetPointError(12,3,3,1.632705,2.918186);
   grae->SetPoint(13,81,1);
   grae->SetPointError(13,3,3,0.8272462,2.299527);
   grae->SetPoint(14,87,6);
   grae->SetPointError(14,3,3,2.379931,3.583642);
   grae->SetPoint(15,93,8);
   grae->SetPointError(15,3,3,2.768386,3.945142);
   grae->SetPoint(16,99,5);
   grae->SetPointError(16,3,3,2.159691,3.382473);
   grae->SetPoint(17,105,9);
   grae->SetPointError(17,3,3,2.943461,4.110204);
   grae->SetPoint(18,111,11);
   grae->SetPointError(18,3,3,3.265579,4.416521);
   grae->SetPoint(19,117,31);
   grae->SetPointError(19,3,3,5.537565,6.627601);
   grae->SetPoint(20,123,25);
   grae->SetPointError(20,3,3,4.966335,6.066589);
   grae->SetPoint(21,129,50);
   grae->SetPointError(21,3,3,7.047337,8.118225);
   grae->SetPoint(22,135,71);
   grae->SetPointError(22,3,3,8.406258,9.465736);
   grae->SetPoint(23,141,86);
   grae->SetPointError(23,3,3,9.255555,10.30959);
   grae->SetPoint(24,147,97);
   grae->SetPointError(24,3,3,9.831854,10.88273);
   grae->SetPoint(25,153,106);
   grae->SetPointError(25,3,3,9.807764,10.80776);
   grae->SetPoint(26,159,142);
   grae->SetPointError(26,3,3,11.42686,12.42686);
   grae->SetPoint(27,165,166);
   grae->SetPointError(27,3,3,12.3938,13.3938);
   grae->SetPoint(28,171,158);
   grae->SetPointError(28,3,3,12.07975,13.07975);
   grae->SetPoint(29,177,169);
   grae->SetPointError(29,3,3,12.50961,13.50961);
   
   TH1F *h_T11__2 = new TH1F("h_T11__2","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T11__2->SetMinimum(0);
   h_T11__2->SetMaximum(200.7606);
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
   
   TGraph *graph = new TGraph(52);
   graph->SetName("myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-6,0);
   graph->SetPoint(1,-6,0.5311404);
   graph->SetPoint(2,0,0.5311404);
   graph->SetPoint(3,6,0.5790637);
   graph->SetPoint(4,12,0.6357423);
   graph->SetPoint(5,18,0.7033359);
   graph->SetPoint(6,24,0.7846697);
   graph->SetPoint(7,30,0.883478);
   graph->SetPoint(8,36,1.004751);
   graph->SetPoint(9,42,1.155232);
   graph->SetPoint(10,48,1.344139);
   graph->SetPoint(11,54,1.584217);
   graph->SetPoint(12,60,1.893293);
   graph->SetPoint(13,66,2.29658);
   graph->SetPoint(14,72,2.83011);
   graph->SetPoint(15,78,3.545834);
   graph->SetPoint(16,84,4.519188);
   graph->SetPoint(17,90,5.860114);
   graph->SetPoint(18,96,7.728711);
   graph->SetPoint(19,102,10.35633);
   graph->SetPoint(20,108,14.07146);
   graph->SetPoint(21,111,16.47261);
   graph->SetPoint(22,114,19.32562);
   graph->SetPoint(23,117,22.7083);
   graph->SetPoint(24,120,26.70572);
   graph->SetPoint(25,123,31.40771);
   graph->SetPoint(26,126,36.90444);
   graph->SetPoint(27,129,43.27973);
   graph->SetPoint(28,132,50.60163);
   graph->SetPoint(29,135,58.91012);
   graph->SetPoint(30,138,68.20231);
   graph->SetPoint(31,141,78.41604);
   graph->SetPoint(32,144,89.41379);
   graph->SetPoint(33,150,112.7632);
   graph->SetPoint(34,153,124.3829);
   graph->SetPoint(35,156,135.3434);
   graph->SetPoint(36,157.5,140.4121);
   graph->SetPoint(37,159,145.1171);
   graph->SetPoint(38,160.5,149.393);
   graph->SetPoint(39,162,153.1781);
   graph->SetPoint(40,163.5,156.4154);
   graph->SetPoint(41,165,159.0547);
   graph->SetPoint(42,166.5,161.0544);
   graph->SetPoint(43,168,162.3819);
   graph->SetPoint(44,169.5,163.0156);
   graph->SetPoint(45,171,163.0529);
   graph->SetPoint(46,174,162.7123);
   graph->SetPoint(47,177,161.951);
   graph->SetPoint(48,180,160.78);
   graph->SetPoint(49,180,160.78);
   graph->SetPoint(50,186,160.78);
   graph->SetPoint(51,186,0);
   
   TH1F *myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3 = new TH1F("myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3","Projection of Higgs to WW",100,-25.2,205.2);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetMinimum(0);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetMaximum(179.3582);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetDirectory(0);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetStats(0);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetMarkerStyle(8);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetXaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetXaxis()->SetTitleFont(132);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetYaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetYaxis()->SetTitleFont(132);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetZaxis()->SetLabelFont(132);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3,0);
   grae->SetPointError(0,3,3,0,1.147874);
   grae->SetPoint(1,9,2);
   grae->SetPointError(1,3,3,1.291815,2.63786);
   grae->SetPoint(2,15,0);
   grae->SetPointError(2,3,3,0,1.147874);
   grae->SetPoint(3,21,0);
   grae->SetPointError(3,3,3,0,1.147874);
   grae->SetPoint(4,27,3);
   grae->SetPointError(4,3,3,1.632705,2.918186);
   grae->SetPoint(5,33,1);
   grae->SetPointError(5,3,3,0.8272462,2.299527);
   grae->SetPoint(6,39,1);
   grae->SetPointError(6,3,3,0.8272462,2.299527);
   grae->SetPoint(7,45,2);
   grae->SetPointError(7,3,3,1.291815,2.63786);
   grae->SetPoint(8,51,2);
   grae->SetPointError(8,3,3,1.291815,2.63786);
   grae->SetPoint(9,57,1);
   grae->SetPointError(9,3,3,0.8272462,2.299527);
   grae->SetPoint(10,63,1);
   grae->SetPointError(10,3,3,0.8272462,2.299527);
   grae->SetPoint(11,69,3);
   grae->SetPointError(11,3,3,1.632705,2.918186);
   grae->SetPoint(12,75,3);
   grae->SetPointError(12,3,3,1.632705,2.918186);
   grae->SetPoint(13,81,1);
   grae->SetPointError(13,3,3,0.8272462,2.299527);
   grae->SetPoint(14,87,6);
   grae->SetPointError(14,3,3,2.379931,3.583642);
   grae->SetPoint(15,93,8);
   grae->SetPointError(15,3,3,2.768386,3.945142);
   grae->SetPoint(16,99,5);
   grae->SetPointError(16,3,3,2.159691,3.382473);
   grae->SetPoint(17,105,9);
   grae->SetPointError(17,3,3,2.943461,4.110204);
   grae->SetPoint(18,111,11);
   grae->SetPointError(18,3,3,3.265579,4.416521);
   grae->SetPoint(19,117,31);
   grae->SetPointError(19,3,3,5.537565,6.627601);
   grae->SetPoint(20,123,25);
   grae->SetPointError(20,3,3,4.966335,6.066589);
   grae->SetPoint(21,129,50);
   grae->SetPointError(21,3,3,7.047337,8.118225);
   grae->SetPoint(22,135,71);
   grae->SetPointError(22,3,3,8.406258,9.465736);
   grae->SetPoint(23,141,86);
   grae->SetPointError(23,3,3,9.255555,10.30959);
   grae->SetPoint(24,147,97);
   grae->SetPointError(24,3,3,9.831854,10.88273);
   grae->SetPoint(25,153,106);
   grae->SetPointError(25,3,3,9.807764,10.80776);
   grae->SetPoint(26,159,142);
   grae->SetPointError(26,3,3,11.42686,12.42686);
   grae->SetPoint(27,165,166);
   grae->SetPointError(27,3,3,12.3938,13.3938);
   grae->SetPoint(28,171,158);
   grae->SetPointError(28,3,3,12.07975,13.07975);
   grae->SetPoint(29,177,169);
   grae->SetPointError(29,3,3,12.50961,13.50961);
   
   TH1F *h_T12__4 = new TH1F("h_T12__4","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T12__4->SetMinimum(0);
   h_T12__4->SetMaximum(200.7606);
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
   
   TH1D *frame_10618a760__5 = new TH1D("frame_10618a760__5","A RooPlot of "#Delta#phi"",30,0,180);
   frame_10618a760__5->SetMaximum(191.6351);
   frame_10618a760__5->SetDirectory(0);
   frame_10618a760__5->SetStats(0);
   frame_10618a760__5->SetMarkerStyle(8);
   frame_10618a760__5->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_10618a760__5->GetXaxis()->SetLabelFont(132);
   frame_10618a760__5->GetXaxis()->SetLabelSize(0.05);
   frame_10618a760__5->GetXaxis()->SetTitleSize(0.06);
   frame_10618a760__5->GetXaxis()->SetTitleFont(132);
   frame_10618a760__5->GetYaxis()->SetTitle("Events");
   frame_10618a760__5->GetYaxis()->SetLabelFont(132);
   frame_10618a760__5->GetYaxis()->SetLabelSize(0.05);
   frame_10618a760__5->GetYaxis()->SetTitleSize(0.06);
   frame_10618a760__5->GetYaxis()->SetTitleFont(132);
   frame_10618a760__5->GetZaxis()->SetLabelFont(132);
   frame_10618a760__5->GetZaxis()->SetLabelSize(0.05);
   frame_10618a760__5->GetZaxis()->SetTitleSize(0.06);
   frame_10618a760__5->GetZaxis()->SetTitleFont(132);
   frame_10618a760__5->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
