{
//=========Macro generated from canvas: c/fitResult
//=========  (Sat Feb 19 12:21:50 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-26.0241,-45.86746,190.8434,240.8042);
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
   
   TH1D *frame_10605e270__1 = new TH1D("frame_10605e270__1","A RooPlot of "#Delta#phi"",30,0,180);
   frame_10605e270__1->SetMaximum(226.4706);
   frame_10605e270__1->SetDirectory(0);
   frame_10605e270__1->SetStats(0);
   frame_10605e270__1->SetMarkerStyle(8);
   frame_10605e270__1->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_10605e270__1->GetXaxis()->SetLabelFont(132);
   frame_10605e270__1->GetXaxis()->SetLabelSize(0.05);
   frame_10605e270__1->GetXaxis()->SetTitleSize(0.06);
   frame_10605e270__1->GetXaxis()->SetTitleFont(132);
   frame_10605e270__1->GetYaxis()->SetTitle("Events");
   frame_10605e270__1->GetYaxis()->SetLabelFont(132);
   frame_10605e270__1->GetYaxis()->SetLabelSize(0.05);
   frame_10605e270__1->GetYaxis()->SetTitleSize(0.06);
   frame_10605e270__1->GetYaxis()->SetTitleFont(132);
   frame_10605e270__1->GetZaxis()->SetLabelFont(132);
   frame_10605e270__1->GetZaxis()->SetLabelSize(0.05);
   frame_10605e270__1->GetZaxis()->SetTitleSize(0.06);
   frame_10605e270__1->GetZaxis()->SetTitleFont(132);
   frame_10605e270__1->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,3,1);
   grae->SetPointError(0,3,3,0.8272462,2.299527);
   grae->SetPoint(1,9,1);
   grae->SetPointError(1,3,3,0.8272462,2.299527);
   grae->SetPoint(2,15,1);
   grae->SetPointError(2,3,3,0.8272462,2.299527);
   grae->SetPoint(3,21,0);
   grae->SetPointError(3,3,3,0,1.147874);
   grae->SetPoint(4,27,4);
   grae->SetPointError(4,3,3,1.914339,3.162753);
   grae->SetPoint(5,33,0);
   grae->SetPointError(5,3,3,0,1.147874);
   grae->SetPoint(6,39,2);
   grae->SetPointError(6,3,3,1.291815,2.63786);
   grae->SetPoint(7,45,2);
   grae->SetPointError(7,3,3,1.291815,2.63786);
   grae->SetPoint(8,51,4);
   grae->SetPointError(8,3,3,1.914339,3.162753);
   grae->SetPoint(9,57,4);
   grae->SetPointError(9,3,3,1.914339,3.162753);
   grae->SetPoint(10,63,2);
   grae->SetPointError(10,3,3,1.291815,2.63786);
   grae->SetPoint(11,69,2);
   grae->SetPointError(11,3,3,1.291815,2.63786);
   grae->SetPoint(12,75,4);
   grae->SetPointError(12,3,3,1.914339,3.162753);
   grae->SetPoint(13,81,11);
   grae->SetPointError(13,3,3,3.265579,4.416521);
   grae->SetPoint(14,87,13);
   grae->SetPointError(14,3,3,3.558662,4.697573);
   grae->SetPoint(15,93,16);
   grae->SetPointError(15,3,3,3.957801,5.083066);
   grae->SetPoint(16,99,17);
   grae->SetPointError(16,3,3,4.082184,5.203719);
   grae->SetPoint(17,105,30);
   grae->SetPointError(17,3,3,5.446522,6.538046);
   grae->SetPoint(18,111,34);
   grae->SetPointError(18,3,3,5.802128,6.888101);
   grae->SetPoint(19,117,47);
   grae->SetPointError(19,3,3,6.831172,7.904289);
   grae->SetPoint(20,123,64);
   grae->SetPointError(20,3,3,7.979042,9.041691);
   grae->SetPoint(21,129,73);
   grae->SetPointError(21,3,3,8.524388,9.583044);
   grae->SetPoint(22,135,103);
   grae->SetPointError(22,3,3,9.661201,10.6612);
   grae->SetPoint(23,141,145);
   grae->SetPointError(23,3,3,11.55197,12.55197);
   grae->SetPoint(24,147,131);
   grae->SetPointError(24,3,3,10.95644,11.95644);
   grae->SetPoint(25,153,143);
   grae->SetPointError(25,3,3,11.46871,12.46871);
   grae->SetPoint(26,159,167);
   grae->SetPointError(26,3,3,12.43252,13.43252);
   grae->SetPoint(27,165,176);
   grae->SetPointError(27,3,3,12.77592,13.77592);
   grae->SetPoint(28,171,194);
   grae->SetPointError(28,3,3,13.43736,14.43736);
   grae->SetPoint(29,177,201);
   grae->SetPointError(29,3,3,13.68626,14.68626);
   
   TH1F *h_T11__2 = new TH1F("h_T11__2","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T11__2->SetMinimum(0);
   h_T11__2->SetMaximum(237.2549);
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
   graph->SetPoint(1,-6,0.5569181);
   graph->SetPoint(2,0,0.5569181);
   graph->SetPoint(3,6,0.6444793);
   graph->SetPoint(4,12,0.7522011);
   graph->SetPoint(5,18,0.8858263);
   graph->SetPoint(6,24,1.052997);
   graph->SetPoint(7,30,1.263949);
   graph->SetPoint(8,36,1.532483);
   graph->SetPoint(9,42,1.877302);
   graph->SetPoint(10,48,2.323879);
   graph->SetPoint(11,54,2.907025);
   graph->SetPoint(12,60,3.674392);
   graph->SetPoint(13,66,4.691196);
   graph->SetPoint(14,72,6.046402);
   graph->SetPoint(15,78,7.860555);
   graph->SetPoint(16,84,10.2951);
   graph->SetPoint(17,90,13.56241);
   graph->SetPoint(18,96,17.93449);
   graph->SetPoint(19,99,20.63718);
   graph->SetPoint(20,102,23.74639);
   graph->SetPoint(21,105,27.3125);
   graph->SetPoint(22,108,31.38759);
   graph->SetPoint(23,111,36.0239);
   graph->SetPoint(24,114,41.27153);
   graph->SetPoint(25,117,47.17549);
   graph->SetPoint(26,120,53.77206);
   graph->SetPoint(27,123,61.08438);
   graph->SetPoint(28,126,69.11756);
   graph->SetPoint(29,129,77.85328);
   graph->SetPoint(30,132,87.24454);
   graph->SetPoint(31,135,97.21064);
   graph->SetPoint(32,138,107.6334);
   graph->SetPoint(33,144,129.1784);
   graph->SetPoint(34,147,139.8698);
   graph->SetPoint(35,150,150.1661);
   graph->SetPoint(36,153,159.7846);
   graph->SetPoint(37,156,168.4357);
   graph->SetPoint(38,159,175.8391);
   graph->SetPoint(39,160.5,178.9918);
   graph->SetPoint(40,162,181.74);
   graph->SetPoint(41,163.5,184.0585);
   graph->SetPoint(42,165,185.9258);
   graph->SetPoint(43,166.5,187.3244);
   graph->SetPoint(44,168,188.2409);
   graph->SetPoint(45,169.5,188.6665);
   graph->SetPoint(46,171,188.6886);
   graph->SetPoint(47,174,188.5347);
   graph->SetPoint(48,180,187.8246);
   graph->SetPoint(49,180,187.8246);
   graph->SetPoint(50,186,187.8246);
   graph->SetPoint(51,186,0);
   
   TH1F *myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3 = new TH1F("myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3","Projection of Higgs to WW",100,-25.2,205.2);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetMinimum(0);
   myFit_Int[maxPtEle,projMet]_Norm[deltaPhi,maxPtEle,projMet]1__3->SetMaximum(207.5575);
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
   grae->SetPoint(0,3,1);
   grae->SetPointError(0,3,3,0.8272462,2.299527);
   grae->SetPoint(1,9,1);
   grae->SetPointError(1,3,3,0.8272462,2.299527);
   grae->SetPoint(2,15,1);
   grae->SetPointError(2,3,3,0.8272462,2.299527);
   grae->SetPoint(3,21,0);
   grae->SetPointError(3,3,3,0,1.147874);
   grae->SetPoint(4,27,4);
   grae->SetPointError(4,3,3,1.914339,3.162753);
   grae->SetPoint(5,33,0);
   grae->SetPointError(5,3,3,0,1.147874);
   grae->SetPoint(6,39,2);
   grae->SetPointError(6,3,3,1.291815,2.63786);
   grae->SetPoint(7,45,2);
   grae->SetPointError(7,3,3,1.291815,2.63786);
   grae->SetPoint(8,51,4);
   grae->SetPointError(8,3,3,1.914339,3.162753);
   grae->SetPoint(9,57,4);
   grae->SetPointError(9,3,3,1.914339,3.162753);
   grae->SetPoint(10,63,2);
   grae->SetPointError(10,3,3,1.291815,2.63786);
   grae->SetPoint(11,69,2);
   grae->SetPointError(11,3,3,1.291815,2.63786);
   grae->SetPoint(12,75,4);
   grae->SetPointError(12,3,3,1.914339,3.162753);
   grae->SetPoint(13,81,11);
   grae->SetPointError(13,3,3,3.265579,4.416521);
   grae->SetPoint(14,87,13);
   grae->SetPointError(14,3,3,3.558662,4.697573);
   grae->SetPoint(15,93,16);
   grae->SetPointError(15,3,3,3.957801,5.083066);
   grae->SetPoint(16,99,17);
   grae->SetPointError(16,3,3,4.082184,5.203719);
   grae->SetPoint(17,105,30);
   grae->SetPointError(17,3,3,5.446522,6.538046);
   grae->SetPoint(18,111,34);
   grae->SetPointError(18,3,3,5.802128,6.888101);
   grae->SetPoint(19,117,47);
   grae->SetPointError(19,3,3,6.831172,7.904289);
   grae->SetPoint(20,123,64);
   grae->SetPointError(20,3,3,7.979042,9.041691);
   grae->SetPoint(21,129,73);
   grae->SetPointError(21,3,3,8.524388,9.583044);
   grae->SetPoint(22,135,103);
   grae->SetPointError(22,3,3,9.661201,10.6612);
   grae->SetPoint(23,141,145);
   grae->SetPointError(23,3,3,11.55197,12.55197);
   grae->SetPoint(24,147,131);
   grae->SetPointError(24,3,3,10.95644,11.95644);
   grae->SetPoint(25,153,143);
   grae->SetPointError(25,3,3,11.46871,12.46871);
   grae->SetPoint(26,159,167);
   grae->SetPointError(26,3,3,12.43252,13.43252);
   grae->SetPoint(27,165,176);
   grae->SetPointError(27,3,3,12.77592,13.77592);
   grae->SetPoint(28,171,194);
   grae->SetPointError(28,3,3,13.43736,14.43736);
   grae->SetPoint(29,177,201);
   grae->SetPointError(29,3,3,13.68626,14.68626);
   
   TH1F *h_T12__4 = new TH1F("h_T12__4","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T12__4->SetMinimum(0);
   h_T12__4->SetMaximum(237.2549);
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
   
   TH1D *frame_10605e270__5 = new TH1D("frame_10605e270__5","A RooPlot of "#Delta#phi"",30,0,180);
   frame_10605e270__5->SetMaximum(226.4706);
   frame_10605e270__5->SetDirectory(0);
   frame_10605e270__5->SetStats(0);
   frame_10605e270__5->SetMarkerStyle(8);
   frame_10605e270__5->GetXaxis()->SetTitle("#Delta#phi [deg]");
   frame_10605e270__5->GetXaxis()->SetLabelFont(132);
   frame_10605e270__5->GetXaxis()->SetLabelSize(0.05);
   frame_10605e270__5->GetXaxis()->SetTitleSize(0.06);
   frame_10605e270__5->GetXaxis()->SetTitleFont(132);
   frame_10605e270__5->GetYaxis()->SetTitle("Events");
   frame_10605e270__5->GetYaxis()->SetLabelFont(132);
   frame_10605e270__5->GetYaxis()->SetLabelSize(0.05);
   frame_10605e270__5->GetYaxis()->SetTitleSize(0.06);
   frame_10605e270__5->GetYaxis()->SetTitleFont(132);
   frame_10605e270__5->GetZaxis()->SetLabelFont(132);
   frame_10605e270__5->GetZaxis()->SetLabelSize(0.05);
   frame_10605e270__5->GetZaxis()->SetTitleSize(0.06);
   frame_10605e270__5->GetZaxis()->SetTitleFont(132);
   frame_10605e270__5->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
