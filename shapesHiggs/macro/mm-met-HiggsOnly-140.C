{
//=========Macro generated from canvas: c/fitResult
//=========  (Tue Feb  9 18:41:44 2010) by ROOT version5.22/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,22,600,300);
   gStyle->SetOptStat(0);
   c->Range(-28.91566,-113.9539,212.0482,598.2578);
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
   
   TH1 *frame_177813312 = new TH1D("frame_177813312","A RooPlot of "E_{T}^{miss}"",50,0,200);
   frame_177813312->SetMaximum(562.6472);
   frame_177813312->SetDirectory(0);
   frame_177813312->SetStats(0);
   frame_177813312->SetMarkerStyle(8);
   frame_177813312->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_177813312->GetXaxis()->SetLabelFont(132);
   frame_177813312->GetXaxis()->SetLabelSize(0.05);
   frame_177813312->GetXaxis()->SetTitleSize(0.06);
   frame_177813312->GetXaxis()->SetTitleFont(132);
   frame_177813312->GetYaxis()->SetTitle("Events");
   frame_177813312->GetYaxis()->SetLabelFont(132);
   frame_177813312->GetYaxis()->SetLabelSize(0.05);
   frame_177813312->GetYaxis()->SetTitleSize(0.06);
   frame_177813312->GetYaxis()->SetTitleFont(132);
   frame_177813312->GetZaxis()->SetLabelFont(132);
   frame_177813312->GetZaxis()->SetLabelSize(0.05);
   frame_177813312->GetZaxis()->SetTitleSize(0.06);
   frame_177813312->GetZaxis()->SetTitleFont(132);
   frame_177813312->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(50);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__met");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,2,0);
   grae->SetPointError(0,2,2,0,1.147874);
   grae->SetPoint(1,6,0);
   grae->SetPointError(1,2,2,0,1.147874);
   grae->SetPoint(2,10,0);
   grae->SetPointError(2,2,2,0,1.147874);
   grae->SetPoint(3,14,0);
   grae->SetPointError(3,2,2,0,1.147874);
   grae->SetPoint(4,18,0);
   grae->SetPointError(4,2,2,0,1.147874);
   grae->SetPoint(5,22,0);
   grae->SetPointError(5,2,2,0,1.147874);
   grae->SetPoint(6,26,0);
   grae->SetPointError(6,2,2,0,1.147874);
   grae->SetPoint(7,30,125);
   grae->SetPointError(7,2,2,10.69151,11.69151);
   grae->SetPoint(8,34,292);
   grae->SetPointError(8,2,2,16.59532,17.59532);
   grae->SetPoint(9,38,326);
   grae->SetPointError(9,2,2,17.56239,18.56239);
   grae->SetPoint(10,42,411);
   grae->SetPointError(10,2,2,19.7793,20.7793);
   grae->SetPoint(11,46,458);
   grae->SetPointError(11,2,2,20.90677,21.90677);
   grae->SetPoint(12,50,470);
   grae->SetPointError(12,2,2,21.18525,22.18525);
   grae->SetPoint(13,54,414);
   grae->SetPointError(13,2,2,19.85313,20.85313);
   grae->SetPoint(14,58,438);
   grae->SetPointError(14,2,2,20.43442,21.43442);
   grae->SetPoint(15,62,336);
   grae->SetPointError(15,2,2,17.83712,18.83712);
   grae->SetPoint(16,66,217);
   grae->SetPointError(16,2,2,14.2394,15.2394);
   grae->SetPoint(17,70,118);
   grae->SetPointError(17,2,2,10.37428,11.37428);
   grae->SetPoint(18,74,75);
   grae->SetPointError(18,2,2,8.640903,9.698771);
   grae->SetPoint(19,78,40);
   grae->SetPointError(19,2,2,6.298,7.377261);
   grae->SetPoint(20,82,34);
   grae->SetPointError(20,2,2,5.802128,6.888101);
   grae->SetPoint(21,86,20);
   grae->SetPointError(21,2,2,4.434448,5.546519);
   grae->SetPoint(22,90,20);
   grae->SetPointError(22,2,2,4.434448,5.546519);
   grae->SetPoint(23,94,16);
   grae->SetPointError(23,2,2,3.957801,5.083066);
   grae->SetPoint(24,98,12);
   grae->SetPointError(24,2,2,3.415266,4.559819);
   grae->SetPoint(25,102,10);
   grae->SetPointError(25,2,2,3.108694,4.26695);
   grae->SetPoint(26,106,7);
   grae->SetPointError(26,2,2,2.58147,3.770281);
   grae->SetPoint(27,110,7);
   grae->SetPointError(27,2,2,2.58147,3.770281);
   grae->SetPoint(28,114,12);
   grae->SetPointError(28,2,2,3.415266,4.559819);
   grae->SetPoint(29,118,6);
   grae->SetPointError(29,2,2,2.379931,3.583642);
   grae->SetPoint(30,122,4);
   grae->SetPointError(30,2,2,1.914339,3.162753);
   grae->SetPoint(31,126,3);
   grae->SetPointError(31,2,2,1.632705,2.918186);
   grae->SetPoint(32,130,2);
   grae->SetPointError(32,2,2,1.291815,2.63786);
   grae->SetPoint(33,134,4);
   grae->SetPointError(33,2,2,1.914339,3.162753);
   grae->SetPoint(34,138,4);
   grae->SetPointError(34,2,2,1.914339,3.162753);
   grae->SetPoint(35,142,1);
   grae->SetPointError(35,2,2,0.8272462,2.299527);
   grae->SetPoint(36,146,3);
   grae->SetPointError(36,2,2,1.632705,2.918186);
   grae->SetPoint(37,150,3);
   grae->SetPointError(37,2,2,1.632705,2.918186);
   grae->SetPoint(38,154,1);
   grae->SetPointError(38,2,2,0.8272462,2.299527);
   grae->SetPoint(39,158,4);
   grae->SetPointError(39,2,2,1.914339,3.162753);
   grae->SetPoint(40,162,2);
   grae->SetPointError(40,2,2,1.291815,2.63786);
   grae->SetPoint(41,166,0);
   grae->SetPointError(41,2,2,0,1.147874);
   grae->SetPoint(42,170,1);
   grae->SetPointError(42,2,2,0.8272462,2.299527);
   grae->SetPoint(43,174,1);
   grae->SetPointError(43,2,2,0.8272462,2.299527);
   grae->SetPoint(44,178,1);
   grae->SetPointError(44,2,2,0.8272462,2.299527);
   grae->SetPoint(45,182,0);
   grae->SetPointError(45,2,2,0,1.147874);
   grae->SetPoint(46,186,0);
   grae->SetPointError(46,2,2,0,1.147874);
   grae->SetPoint(47,190,0);
   grae->SetPointError(47,2,2,0,1.147874);
   grae->SetPoint(48,194,0);
   grae->SetPointError(48,2,2,0,1.147874);
   grae->SetPoint(49,198,0);
   grae->SetPointError(49,2,2,0,1.147874);
   
   TH1 *h_T13 = new TH1F("h_T13","Histogram of T1_plot__met",100,0,220);
   h_T13->SetMinimum(0);
   h_T13->SetMaximum(541.4038);
   h_T13->SetDirectory(0);
   h_T13->SetStats(0);
   h_T13->SetMarkerStyle(8);
   h_T13->GetXaxis()->SetLabelFont(132);
   h_T13->GetXaxis()->SetLabelSize(0.05);
   h_T13->GetXaxis()->SetTitleSize(0.06);
   h_T13->GetXaxis()->SetTitleFont(132);
   h_T13->GetYaxis()->SetLabelFont(132);
   h_T13->GetYaxis()->SetLabelSize(0.05);
   h_T13->GetYaxis()->SetTitleSize(0.06);
   h_T13->GetYaxis()->SetTitleFont(132);
   h_T13->GetZaxis()->SetLabelFont(132);
   h_T13->GetZaxis()->SetLabelSize(0.05);
   h_T13->GetZaxis()->SetTitleSize(0.06);
   h_T13->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T13);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(99);
   graph->SetName("myFit_Int[jetcat]_Norm[met,jetcat]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-4,0);
   graph->SetPoint(1,-4,0.01329233);
   graph->SetPoint(2,0,0.01329233);
   graph->SetPoint(3,4,0.06653297);
   graph->SetPoint(4,8,0.2916747);
   graph->SetPoint(5,12,1.119919);
   graph->SetPoint(6,16,3.766178);
   graph->SetPoint(7,18,6.57155);
   graph->SetPoint(8,20,11.0928);
   graph->SetPoint(9,22,18.11429);
   graph->SetPoint(10,24,28.61592);
   graph->SetPoint(11,25,35.52249);
   graph->SetPoint(12,26,43.73215);
   graph->SetPoint(13,27,53.3949);
   graph->SetPoint(14,28,64.65475);
   graph->SetPoint(15,29,77.64307);
   graph->SetPoint(16,30,92.47122);
   graph->SetPoint(17,31,109.2225);
   graph->SetPoint(18,32,127.9438);
   graph->SetPoint(19,33,148.6374);
   graph->SetPoint(20,34,171.2531);
   graph->SetPoint(21,35,195.6819);
   graph->SetPoint(22,36,221.7503);
   graph->SetPoint(23,37,249.2181);
   graph->SetPoint(24,38,277.7772);
   graph->SetPoint(25,40,336.6166);
   graph->SetPoint(26,42,394.6216);
   graph->SetPoint(27,43,421.9938);
   graph->SetPoint(28,44,447.541);
   graph->SetPoint(29,45,470.7185);
   graph->SetPoint(30,46,491.0112);
   graph->SetPoint(31,47,507.9524);
   graph->SetPoint(32,48,521.1424);
   graph->SetPoint(33,49,530.2631);
   graph->SetPoint(34,49.5,533.2237);
   graph->SetPoint(35,50,535.0914);
   graph->SetPoint(36,50.5,535.8545);
   graph->SetPoint(37,51,535.4479);
   graph->SetPoint(38,51.5,533.7558);
   graph->SetPoint(39,52,530.7911);
   graph->SetPoint(40,52.5,526.5818);
   graph->SetPoint(41,53,521.1672);
   graph->SetPoint(42,53.5,514.5974);
   graph->SetPoint(43,54,506.9321);
   graph->SetPoint(44,55,488.5958);
   graph->SetPoint(45,56,466.7867);
   graph->SetPoint(46,57,442.2094);
   graph->SetPoint(47,58,415.6013);
   graph->SetPoint(48,60,359.1677);
   graph->SetPoint(49,62,302.654);
   graph->SetPoint(50,63,275.6243);
   graph->SetPoint(51,64,249.8884);
   graph->SetPoint(52,65,225.6837);
   graph->SetPoint(53,66,203.1619);
   graph->SetPoint(54,67,182.4006);
   graph->SetPoint(55,68,163.4162);
   graph->SetPoint(56,69,146.1771);
   graph->SetPoint(57,70,130.6157);
   graph->SetPoint(58,71,116.6391);
   graph->SetPoint(59,72,104.1383);
   graph->SetPoint(60,73,92.99588);
   graph->SetPoint(61,74,83.09149);
   graph->SetPoint(62,76,66.52632);
   graph->SetPoint(63,78,53.55933);
   graph->SetPoint(64,80,43.42814);
   graph->SetPoint(65,82,35.50543);
   graph->SetPoint(66,84,29.29085);
   graph->SetPoint(67,88,20.51129);
   graph->SetPoint(68,92,14.92405);
   graph->SetPoint(69,96,11.26364);
   graph->SetPoint(70,100,8.791866);
   graph->SetPoint(71,104,7.072616);
   graph->SetPoint(72,108,5.843005);
   graph->SetPoint(73,112,4.940732);
   graph->SetPoint(74,116,4.263037);
   graph->SetPoint(75,120,3.743211);
   graph->SetPoint(76,124,3.336882);
   graph->SetPoint(77,128,3.013854);
   graph->SetPoint(78,132,2.75313);
   graph->SetPoint(79,136,2.539816);
   graph->SetPoint(80,140,2.363147);
   graph->SetPoint(81,144,2.215215);
   graph->SetPoint(82,148,2.09011);
   graph->SetPoint(83,152,1.983358);
   graph->SetPoint(84,156,1.891523);
   graph->SetPoint(85,160,1.811934);
   graph->SetPoint(86,164,1.74249);
   graph->SetPoint(87,168,1.681523);
   graph->SetPoint(88,172,1.627693);
   graph->SetPoint(89,176,1.579918);
   graph->SetPoint(90,180,1.537311);
   graph->SetPoint(91,184,1.499143);
   graph->SetPoint(92,188,1.464812);
   graph->SetPoint(93,192,1.433813);
   graph->SetPoint(94,196,1.405723);
   graph->SetPoint(95,200,1.380183);
   graph->SetPoint(96,200,1.380183);
   graph->SetPoint(97,204,1.380183);
   graph->SetPoint(98,204,0);
   
   TH1 *myFit_Int[jetcat]_Norm[met,jetcat]3 = new TH1F("myFit_Int[jetcat]_Norm[met,jetcat]3","Projection of Higgs to WW",100,-24.8,224.8);
   myFit_Int[jetcat]_Norm[met,jetcat]3->SetMinimum(0);
   myFit_Int[jetcat]_Norm[met,jetcat]3->SetMaximum(589.44);
   myFit_Int[jetcat]_Norm[met,jetcat]3->SetDirectory(0);
   myFit_Int[jetcat]_Norm[met,jetcat]3->SetStats(0);
   myFit_Int[jetcat]_Norm[met,jetcat]3->SetMarkerStyle(8);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetXaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetXaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetYaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetYaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetZaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[met,jetcat]3->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[jetcat]_Norm[met,jetcat]3);
   
   graph->Draw("l");
   
   TH1 *frame_177813312 = new TH1D("frame_177813312","A RooPlot of "E_{T}^{miss}"",50,0,200);
   frame_177813312->SetMaximum(562.6472);
   frame_177813312->SetDirectory(0);
   frame_177813312->SetStats(0);
   frame_177813312->SetMarkerStyle(8);
   frame_177813312->GetXaxis()->SetTitle("missing E_{T} [GeV]");
   frame_177813312->GetXaxis()->SetLabelFont(132);
   frame_177813312->GetXaxis()->SetLabelSize(0.05);
   frame_177813312->GetXaxis()->SetTitleSize(0.06);
   frame_177813312->GetXaxis()->SetTitleFont(132);
   frame_177813312->GetYaxis()->SetTitle("Events");
   frame_177813312->GetYaxis()->SetLabelFont(132);
   frame_177813312->GetYaxis()->SetLabelSize(0.05);
   frame_177813312->GetYaxis()->SetTitleSize(0.06);
   frame_177813312->GetYaxis()->SetTitleFont(132);
   frame_177813312->GetZaxis()->SetLabelFont(132);
   frame_177813312->GetZaxis()->SetLabelSize(0.05);
   frame_177813312->GetZaxis()->SetTitleSize(0.06);
   frame_177813312->GetZaxis()->SetTitleFont(132);
   frame_177813312->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
