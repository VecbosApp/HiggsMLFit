{
//=========Macro generated from canvas: c/fitResult
//=========  (Sat Nov  7 14:56:07 2009) by ROOT version5.22/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,22,600,300);
   gStyle->SetOptStat(0);
   c->Range(-28.91566,-0.5415296,212.0482,2.843031);
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
   
   TH1 *frame_172102176 = new TH1D("frame_172102176","A RooPlot of "E_{T}^{miss}"",20,0,200);
   frame_172102176->SetMaximum(2.673803);
   frame_172102176->SetDirectory(0);
   frame_172102176->SetStats(0);
   frame_172102176->SetMarkerStyle(8);
   frame_172102176->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_172102176->GetXaxis()->SetLabelFont(132);
   frame_172102176->GetXaxis()->SetLabelSize(0.05);
   frame_172102176->GetXaxis()->SetTitleSize(0.06);
   frame_172102176->GetXaxis()->SetTitleFont(132);
   frame_172102176->GetYaxis()->SetTitle("Events");
   frame_172102176->GetYaxis()->SetLabelFont(132);
   frame_172102176->GetYaxis()->SetLabelSize(0.05);
   frame_172102176->GetYaxis()->SetTitleSize(0.06);
   frame_172102176->GetYaxis()->SetTitleFont(132);
   frame_172102176->GetZaxis()->SetLabelFont(132);
   frame_172102176->GetZaxis()->SetLabelSize(0.05);
   frame_172102176->GetZaxis()->SetTitleSize(0.06);
   frame_172102176->GetZaxis()->SetTitleFont(132);
   frame_172102176->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__met");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,5,0.1023543);
   grae->SetPointError(0,5,5,0.01289542,0.01289542);
   grae->SetPoint(1,15,0.3151865);
   grae->SetPointError(1,5,5,0.02262903,0.02262903);
   grae->SetPoint(2,25,0.5247689);
   grae->SetPointError(2,5,5,0.0291989,0.0291989);
   grae->SetPoint(3,35,0.7895859);
   grae->SetPointError(3,5,5,0.03581651,0.03581651);
   grae->SetPoint(4,45,1.322481);
   grae->SetPointError(4,5,5,0.04635295,0.04635295);
   grae->SetPoint(5,55,2.06659);
   grae->SetPointError(5,5,5,0.05794403,0.05794403);
   grae->SetPoint(6,65,2.474361);
   grae->SetPointError(6,5,5,0.06340377,0.06340377);
   grae->SetPoint(7,75,2.272913);
   grae->SetPointError(7,5,5,0.06076787,0.06076787);
   grae->SetPoint(8,85,1.275365);
   grae->SetPointError(8,5,5,0.04551976,0.04551976);
   grae->SetPoint(9,95,0.4679058);
   grae->SetPointError(9,5,5,0.02757156,0.02757156);
   grae->SetPoint(10,105,0.1218504);
   grae->SetPointError(10,5,5,0.01407005,0.01407005);
   grae->SetPoint(11,115,0.05198944);
   grae->SetPointError(11,5,5,0.009190521,0.009190521);
   grae->SetPoint(12,125,0.02112071);
   grae->SetPointError(12,5,5,0.005857831,0.005857831);
   grae->SetPoint(13,135,0.02599472);
   grae->SetPointError(13,5,5,0.00649868,0.00649868);
   grae->SetPoint(14,145,0.00974802);
   grae->SetPointError(14,5,5,0.003979612,0.003979612);
   grae->SetPoint(15,155,0.01299736);
   grae->SetPointError(15,5,5,0.004595261,0.004595261);
   grae->SetPoint(16,165,0.00649868);
   grae->SetPointError(16,5,5,0.00324934,0.00324934);
   grae->SetPoint(17,175,0.00487401);
   grae->SetPointError(17,5,5,0.002814011,0.002814011);
   grae->SetPoint(18,185,0.00812335);
   grae->SetPointError(18,5,5,0.003632873,0.003632873);
   grae->SetPoint(19,195,0.00324934);
   grae->SetPointError(19,5,5,0.00229763,0.00229763);
   
   TH1 *h_T14 = new TH1F("h_T14","Histogram of T1_plot__met",100,0,220);
   h_T14->SetMinimum(0);
   h_T14->SetMaximum(2.791446);
   h_T14->SetDirectory(0);
   h_T14->SetStats(0);
   h_T14->SetMarkerStyle(8);
   h_T14->GetXaxis()->SetLabelFont(132);
   h_T14->GetXaxis()->SetLabelSize(0.05);
   h_T14->GetXaxis()->SetTitleSize(0.06);
   h_T14->GetXaxis()->SetTitleFont(132);
   h_T14->GetYaxis()->SetLabelFont(132);
   h_T14->GetYaxis()->SetLabelSize(0.05);
   h_T14->GetYaxis()->SetTitleSize(0.06);
   h_T14->GetYaxis()->SetTitleFont(132);
   h_T14->GetZaxis()->SetLabelFont(132);
   h_T14->GetZaxis()->SetLabelSize(0.05);
   h_T14->GetZaxis()->SetTitleSize(0.06);
   h_T14->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T14);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(76);
   graph->SetName("myFit_Int[jetcat]_Norm[met,jetcat]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-10,0);
   graph->SetPoint(1,-10,0.0942584);
   graph->SetPoint(2,0,0.0942584);
   graph->SetPoint(3,5,0.1307205);
   graph->SetPoint(4,10,0.1815599);
   graph->SetPoint(5,12.5,0.2138955);
   graph->SetPoint(6,15,0.2517906);
   graph->SetPoint(7,17.5,0.2960317);
   graph->SetPoint(8,20,0.3474482);
   graph->SetPoint(9,22.5,0.4068889);
   graph->SetPoint(10,25,0.4751886);
   graph->SetPoint(11,27.5,0.5531223);
   graph->SetPoint(12,30,0.6413482);
   graph->SetPoint(13,32.5,0.7403378);
   graph->SetPoint(14,35,0.8502963);
   graph->SetPoint(15,37.5,0.9710759);
   graph->SetPoint(16,40,1.102088);
   graph->SetPoint(17,42.5,1.242222);
   graph->SetPoint(18,45,1.389782);
   graph->SetPoint(19,50,1.697273);
   graph->SetPoint(20,52.5,1.850745);
   graph->SetPoint(21,55,1.998876);
   graph->SetPoint(22,57.5,2.137369);
   graph->SetPoint(23,60,2.261825);
   graph->SetPoint(24,61.25,2.317445);
   graph->SetPoint(25,62.5,2.367985);
   graph->SetPoint(26,63.75,2.412979);
   graph->SetPoint(27,65,2.452001);
   graph->SetPoint(28,66.25,2.484677);
   graph->SetPoint(29,67.5,2.510686);
   graph->SetPoint(30,68.75,2.529772);
   graph->SetPoint(31,70,2.541743);
   graph->SetPoint(32,71.25,2.546479);
   graph->SetPoint(33,71.875,2.544423);
   graph->SetPoint(34,72.5,2.533969);
   graph->SetPoint(35,73.125,2.514939);
   graph->SetPoint(36,73.75,2.487583);
   graph->SetPoint(37,74.375,2.452255);
   graph->SetPoint(38,75,2.409404);
   graph->SetPoint(39,75.625,2.359563);
   graph->SetPoint(40,76.25,2.303337);
   graph->SetPoint(41,77.5,2.17442);
   graph->SetPoint(42,78.75,2.028363);
   graph->SetPoint(43,80,1.871072);
   graph->SetPoint(44,82.5,1.544909);
   graph->SetPoint(45,83.75,1.385436);
   graph->SetPoint(46,85,1.233179);
   graph->SetPoint(47,86.25,1.090579);
   graph->SetPoint(48,87.5,0.9592067);
   graph->SetPoint(49,88.75,0.8398717);
   graph->SetPoint(50,90,0.7327661);
   graph->SetPoint(51,91.25,0.637609);
   graph->SetPoint(52,92.5,0.5537846);
   graph->SetPoint(53,93.75,0.4804612);
   graph->SetPoint(54,95,0.4166888);
   graph->SetPoint(55,96.25,0.3614738);
   graph->SetPoint(56,97.5,0.3138336);
   graph->SetPoint(57,98.75,0.2728328);
   graph->SetPoint(58,100,0.2376061);
   graph->SetPoint(59,102.5,0.1814243);
   graph->SetPoint(60,105,0.140031);
   graph->SetPoint(61,107.5,0.109425);
   graph->SetPoint(62,110,0.08664969);
   graph->SetPoint(63,115,0.05660855);
   graph->SetPoint(64,120,0.03901565);
   graph->SetPoint(65,130,0.02138052);
   graph->SetPoint(66,140,0.01365973);
   graph->SetPoint(67,150,0.009768069);
   graph->SetPoint(68,160,0.007576739);
   graph->SetPoint(69,170,0.00623247);
   graph->SetPoint(70,180,0.005351109);
   graph->SetPoint(71,190,0.004742243);
   graph->SetPoint(72,200,0.004303722);
   graph->SetPoint(73,200,0.004303722);
   graph->SetPoint(74,210,0.004303722);
   graph->SetPoint(75,210,0);
   
   TH1 *myFit_Int[jetcat]_Norm[met,jetcat]4 = new TH1F("myFit_Int[jetcat]_Norm[met,jetcat]4","Projection of Higgs to WW",100,-32,232);
   myFit_Int[jetcat]_Norm[met,jetcat]4->SetMinimum(0);
   myFit_Int[jetcat]_Norm[met,jetcat]4->SetMaximum(2.801126);
   myFit_Int[jetcat]_Norm[met,jetcat]4->SetDirectory(0);
   myFit_Int[jetcat]_Norm[met,jetcat]4->SetStats(0);
   myFit_Int[jetcat]_Norm[met,jetcat]4->SetMarkerStyle(8);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetXaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetXaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetYaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetYaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetZaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]4->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[jetcat]_Norm[met,jetcat]4);
   
   graph->Draw("l");
   
   TH1 *frame_172102176 = new TH1D("frame_172102176","A RooPlot of "E_{T}^{miss}"",20,0,200);
   frame_172102176->SetMaximum(2.673803);
   frame_172102176->SetDirectory(0);
   frame_172102176->SetStats(0);
   frame_172102176->SetMarkerStyle(8);
   frame_172102176->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_172102176->GetXaxis()->SetLabelFont(132);
   frame_172102176->GetXaxis()->SetLabelSize(0.05);
   frame_172102176->GetXaxis()->SetTitleSize(0.06);
   frame_172102176->GetXaxis()->SetTitleFont(132);
   frame_172102176->GetYaxis()->SetTitle("Events");
   frame_172102176->GetYaxis()->SetLabelFont(132);
   frame_172102176->GetYaxis()->SetLabelSize(0.05);
   frame_172102176->GetYaxis()->SetTitleSize(0.06);
   frame_172102176->GetYaxis()->SetTitleFont(132);
   frame_172102176->GetZaxis()->SetLabelFont(132);
   frame_172102176->GetZaxis()->SetLabelSize(0.05);
   frame_172102176->GetZaxis()->SetTitleSize(0.06);
   frame_172102176->GetZaxis()->SetTitleFont(132);
   frame_172102176->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
