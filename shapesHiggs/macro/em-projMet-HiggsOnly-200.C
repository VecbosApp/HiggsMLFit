{
//=========Macro generated from canvas: c/fitResult
//=========  (Fri Feb 18 22:41:15 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-36.14458,-320.2553,265.0602,1681.34);
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
   
   TH1D *frame_1076b46d0__11 = new TH1D("frame_1076b46d0__11","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1076b46d0__11->SetMaximum(1581.26);
   frame_1076b46d0__11->SetDirectory(0);
   frame_1076b46d0__11->SetStats(0);
   frame_1076b46d0__11->SetMarkerStyle(8);
   frame_1076b46d0__11->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1076b46d0__11->GetXaxis()->SetLabelFont(132);
   frame_1076b46d0__11->GetXaxis()->SetLabelSize(0.05);
   frame_1076b46d0__11->GetXaxis()->SetTitleSize(0.06);
   frame_1076b46d0__11->GetXaxis()->SetTitleFont(132);
   frame_1076b46d0__11->GetYaxis()->SetTitle("Events");
   frame_1076b46d0__11->GetYaxis()->SetLabelFont(132);
   frame_1076b46d0__11->GetYaxis()->SetLabelSize(0.05);
   frame_1076b46d0__11->GetYaxis()->SetTitleSize(0.06);
   frame_1076b46d0__11->GetYaxis()->SetTitleFont(132);
   frame_1076b46d0__11->GetZaxis()->SetLabelFont(132);
   frame_1076b46d0__11->GetZaxis()->SetLabelSize(0.05);
   frame_1076b46d0__11->GetZaxis()->SetTitleSize(0.06);
   frame_1076b46d0__11->GetZaxis()->SetTitleFont(132);
   frame_1076b46d0__11->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,223);
   grae->SetPointError(0,4.166667,4.166667,14.44155,15.44155);
   grae->SetPoint(1,12.5,203);
   grae->SetPointError(1,4.166667,4.166667,13.75658,14.75658);
   grae->SetPoint(2,20.83333,249);
   grae->SetPointError(2,4.166667,4.166667,15.28765,16.28765);
   grae->SetPoint(3,29.16667,348);
   grae->SetPointError(3,4.166667,4.166667,18.16146,19.16146);
   grae->SetPoint(4,37.5,497);
   grae->SetPointError(4,4.166667,4.166667,21.7991,22.7991);
   grae->SetPoint(5,45.83333,692);
   grae->SetPointError(5,4.166667,4.166667,25.81064,26.81064);
   grae->SetPoint(6,54.16667,1011);
   grae->SetPointError(6,4.166667,4.166667,31.30016,32.30016);
   grae->SetPoint(7,62.5,1292);
   grae->SetPointError(7,4.166667,4.166667,35.44788,36.44788);
   grae->SetPoint(8,70.83333,1447);
   grae->SetPointError(8,4.166667,4.166667,37.54274,38.54274);
   grae->SetPoint(9,79.16667,1233);
   grae->SetPointError(9,4.166667,4.166667,34.61766,35.61766);
   grae->SetPoint(10,87.5,549);
   grae->SetPointError(10,4.166667,4.166667,22.93608,23.93608);
   grae->SetPoint(11,95.83333,166);
   grae->SetPointError(11,4.166667,4.166667,12.3938,13.3938);
   grae->SetPoint(12,104.1667,41);
   grae->SetPointError(12,4.166667,4.166667,6.376898,7.455185);
   grae->SetPoint(13,112.5,6);
   grae->SetPointError(13,4.166667,4.166667,2.379931,3.583642);
   grae->SetPoint(14,120.8333,8);
   grae->SetPointError(14,4.166667,4.166667,2.768386,3.945142);
   grae->SetPoint(15,129.1667,5);
   grae->SetPointError(15,4.166667,4.166667,2.159691,3.382473);
   grae->SetPoint(16,137.5,1);
   grae->SetPointError(16,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(17,145.8333,1);
   grae->SetPointError(17,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(18,154.1667,1);
   grae->SetPointError(18,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(19,162.5,0);
   grae->SetPointError(19,4.166667,4.166667,0,1.147874);
   grae->SetPoint(20,170.8333,0);
   grae->SetPointError(20,4.166667,4.166667,0,1.147874);
   grae->SetPoint(21,179.1667,1);
   grae->SetPointError(21,4.166667,4.166667,0.8272462,2.299527);
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
   grae->SetPoint(27,229.1667,1);
   grae->SetPointError(27,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(28,237.5,0);
   grae->SetPointError(28,4.166667,4.166667,0,1.147874);
   grae->SetPoint(29,245.8333,0);
   grae->SetPointError(29,4.166667,4.166667,0,1.147874);
   
   TH1F *h_T15__12 = new TH1F("h_T15__12","Histogram of T1_plot__projMet",100,0,275);
   h_T15__12->SetMinimum(0);
   h_T15__12->SetMaximum(1634.097);
   h_T15__12->SetDirectory(0);
   h_T15__12->SetStats(0);
   h_T15__12->SetMarkerStyle(8);
   h_T15__12->GetXaxis()->SetLabelFont(132);
   h_T15__12->GetXaxis()->SetLabelSize(0.05);
   h_T15__12->GetXaxis()->SetTitleSize(0.06);
   h_T15__12->GetXaxis()->SetTitleFont(132);
   h_T15__12->GetYaxis()->SetLabelFont(132);
   h_T15__12->GetYaxis()->SetLabelSize(0.05);
   h_T15__12->GetYaxis()->SetTitleSize(0.06);
   h_T15__12->GetYaxis()->SetTitleFont(132);
   h_T15__12->GetZaxis()->SetLabelFont(132);
   h_T15__12->GetZaxis()->SetLabelSize(0.05);
   h_T15__12->GetZaxis()->SetTitleSize(0.06);
   h_T15__12->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T15);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(85);
   graph->SetName("myFit_Norm[projMet]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-8.333333,0);
   graph->SetPoint(1,-8.333333,171.3318);
   graph->SetPoint(2,0,171.3318);
   graph->SetPoint(3,8.333333,201.2884);
   graph->SetPoint(4,12.5,221.1023);
   graph->SetPoint(5,16.66667,245.3122);
   graph->SetPoint(6,20.83333,275.1298);
   graph->SetPoint(7,25,312.1177);
   graph->SetPoint(8,29.16667,358.2611);
   graph->SetPoint(9,31.25,385.514);
   graph->SetPoint(10,33.33333,416.0106);
   graph->SetPoint(11,35.41667,450.1229);
   graph->SetPoint(12,37.5,488.2369);
   graph->SetPoint(13,39.58333,530.7381);
   graph->SetPoint(14,41.66667,577.9893);
   graph->SetPoint(15,43.75,630.3001);
   graph->SetPoint(16,45.83333,687.8845);
   graph->SetPoint(17,47.91667,750.8078);
   graph->SetPoint(18,50,818.9216);
   graph->SetPoint(19,52.08333,891.7907);
   graph->SetPoint(20,54.16667,968.6181);
   graph->SetPoint(21,58.33333,1128.768);
   graph->SetPoint(22,60.41667,1208.212);
   graph->SetPoint(23,62.5,1283.901);
   graph->SetPoint(24,64.58333,1352.926);
   graph->SetPoint(25,66.66667,1412.264);
   graph->SetPoint(26,67.70833,1437.387);
   graph->SetPoint(27,68.75,1459.035);
   graph->SetPoint(28,69.79167,1476.918);
   graph->SetPoint(29,70.83333,1490.788);
   graph->SetPoint(30,71.875,1500.448);
   graph->SetPoint(31,72.91667,1505.762);
   graph->SetPoint(32,73.95833,1505.962);
   graph->SetPoint(33,74.47917,1500.543);
   graph->SetPoint(34,75,1490.26);
   graph->SetPoint(35,75.52083,1475.235);
   graph->SetPoint(36,76.04167,1455.64);
   graph->SetPoint(37,76.5625,1431.701);
   graph->SetPoint(38,77.08333,1403.687);
   graph->SetPoint(39,77.60417,1371.907);
   graph->SetPoint(40,78.125,1336.701);
   graph->SetPoint(41,79.16667,1257.504);
   graph->SetPoint(42,80.20833,1169.221);
   graph->SetPoint(43,81.25,1075.055);
   graph->SetPoint(44,83.33333,881.0879);
   graph->SetPoint(45,84.375,786.4505);
   graph->SetPoint(46,85.41667,696.0746);
   graph->SetPoint(47,86.45833,611.3739);
   graph->SetPoint(48,87.5,533.2919);
   graph->SetPoint(49,88.54167,462.3509);
   graph->SetPoint(50,89.58333,398.7182);
   graph->SetPoint(51,90.625,342.2796);
   graph->SetPoint(52,91.66667,292.7117);
   graph->SetPoint(53,92.70833,249.5482);
   graph->SetPoint(54,93.75,212.2371);
   graph->SetPoint(55,94.79167,180.1862);
   graph->SetPoint(56,95.83333,152.7984);
   graph->SetPoint(57,96.875,129.4966);
   graph->SetPoint(58,97.91667,109.7404);
   graph->SetPoint(59,100,78.94045);
   graph->SetPoint(60,102.0833,57.06257);
   graph->SetPoint(61,104.1667,41.55925);
   graph->SetPoint(62,106.25,30.55839);
   graph->SetPoint(63,108.3333,22.71891);
   graph->SetPoint(64,112.5,13.02877);
   graph->SetPoint(65,116.6667,7.869465);
   graph->SetPoint(66,125,3.344105);
   graph->SetPoint(67,133.3333,1.701747);
   graph->SetPoint(68,141.6667,1.001424);
   graph->SetPoint(69,150,0.6596579);
   graph->SetPoint(70,158.3333,0.473704);
   graph->SetPoint(71,166.6667,0.3633628);
   graph->SetPoint(72,175,0.2931997);
   graph->SetPoint(73,183.3333,0.2460365);
   graph->SetPoint(74,191.6667,0.2128733);
   graph->SetPoint(75,200,0.1886777);
   graph->SetPoint(76,208.3333,0.1704767);
   graph->SetPoint(77,216.6667,0.1564303);
   graph->SetPoint(78,225,0.1453528);
   graph->SetPoint(79,233.3333,0.1364537);
   graph->SetPoint(80,241.6667,0.12919);
   graph->SetPoint(81,250,0.1231784);
   graph->SetPoint(82,250,0.1231784);
   graph->SetPoint(83,258.3333,0.1231784);
   graph->SetPoint(84,258.3333,0);
   
   TH1F *myFit_Norm[projMet]3__13 = new TH1F("myFit_Norm[projMet]3__13","Projection of Higgs to WW",100,-35,285);
   myFit_Norm[projMet]3__13->SetMinimum(0);
   myFit_Norm[projMet]3__13->SetMaximum(1656.559);
   myFit_Norm[projMet]3__13->SetDirectory(0);
   myFit_Norm[projMet]3__13->SetStats(0);
   myFit_Norm[projMet]3__13->SetMarkerStyle(8);
   myFit_Norm[projMet]3__13->GetXaxis()->SetLabelFont(132);
   myFit_Norm[projMet]3__13->GetXaxis()->SetLabelSize(0.05);
   myFit_Norm[projMet]3__13->GetXaxis()->SetTitleSize(0.06);
   myFit_Norm[projMet]3__13->GetXaxis()->SetTitleFont(132);
   myFit_Norm[projMet]3__13->GetYaxis()->SetLabelFont(132);
   myFit_Norm[projMet]3__13->GetYaxis()->SetLabelSize(0.05);
   myFit_Norm[projMet]3__13->GetYaxis()->SetTitleSize(0.06);
   myFit_Norm[projMet]3__13->GetYaxis()->SetTitleFont(132);
   myFit_Norm[projMet]3__13->GetZaxis()->SetLabelFont(132);
   myFit_Norm[projMet]3__13->GetZaxis()->SetLabelSize(0.05);
   myFit_Norm[projMet]3__13->GetZaxis()->SetTitleSize(0.06);
   myFit_Norm[projMet]3__13->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Norm[projMet]3);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,223);
   grae->SetPointError(0,4.166667,4.166667,14.44155,15.44155);
   grae->SetPoint(1,12.5,203);
   grae->SetPointError(1,4.166667,4.166667,13.75658,14.75658);
   grae->SetPoint(2,20.83333,249);
   grae->SetPointError(2,4.166667,4.166667,15.28765,16.28765);
   grae->SetPoint(3,29.16667,348);
   grae->SetPointError(3,4.166667,4.166667,18.16146,19.16146);
   grae->SetPoint(4,37.5,497);
   grae->SetPointError(4,4.166667,4.166667,21.7991,22.7991);
   grae->SetPoint(5,45.83333,692);
   grae->SetPointError(5,4.166667,4.166667,25.81064,26.81064);
   grae->SetPoint(6,54.16667,1011);
   grae->SetPointError(6,4.166667,4.166667,31.30016,32.30016);
   grae->SetPoint(7,62.5,1292);
   grae->SetPointError(7,4.166667,4.166667,35.44788,36.44788);
   grae->SetPoint(8,70.83333,1447);
   grae->SetPointError(8,4.166667,4.166667,37.54274,38.54274);
   grae->SetPoint(9,79.16667,1233);
   grae->SetPointError(9,4.166667,4.166667,34.61766,35.61766);
   grae->SetPoint(10,87.5,549);
   grae->SetPointError(10,4.166667,4.166667,22.93608,23.93608);
   grae->SetPoint(11,95.83333,166);
   grae->SetPointError(11,4.166667,4.166667,12.3938,13.3938);
   grae->SetPoint(12,104.1667,41);
   grae->SetPointError(12,4.166667,4.166667,6.376898,7.455185);
   grae->SetPoint(13,112.5,6);
   grae->SetPointError(13,4.166667,4.166667,2.379931,3.583642);
   grae->SetPoint(14,120.8333,8);
   grae->SetPointError(14,4.166667,4.166667,2.768386,3.945142);
   grae->SetPoint(15,129.1667,5);
   grae->SetPointError(15,4.166667,4.166667,2.159691,3.382473);
   grae->SetPoint(16,137.5,1);
   grae->SetPointError(16,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(17,145.8333,1);
   grae->SetPointError(17,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(18,154.1667,1);
   grae->SetPointError(18,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(19,162.5,0);
   grae->SetPointError(19,4.166667,4.166667,0,1.147874);
   grae->SetPoint(20,170.8333,0);
   grae->SetPointError(20,4.166667,4.166667,0,1.147874);
   grae->SetPoint(21,179.1667,1);
   grae->SetPointError(21,4.166667,4.166667,0.8272462,2.299527);
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
   grae->SetPoint(27,229.1667,1);
   grae->SetPointError(27,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(28,237.5,0);
   grae->SetPointError(28,4.166667,4.166667,0,1.147874);
   grae->SetPoint(29,245.8333,0);
   grae->SetPointError(29,4.166667,4.166667,0,1.147874);
   
   TH1F *h_T16__14 = new TH1F("h_T16__14","Histogram of T1_plot__projMet",100,0,275);
   h_T16__14->SetMinimum(0);
   h_T16__14->SetMaximum(1634.097);
   h_T16__14->SetDirectory(0);
   h_T16__14->SetStats(0);
   h_T16__14->SetMarkerStyle(8);
   h_T16__14->GetXaxis()->SetLabelFont(132);
   h_T16__14->GetXaxis()->SetLabelSize(0.05);
   h_T16__14->GetXaxis()->SetTitleSize(0.06);
   h_T16__14->GetXaxis()->SetTitleFont(132);
   h_T16__14->GetYaxis()->SetLabelFont(132);
   h_T16__14->GetYaxis()->SetLabelSize(0.05);
   h_T16__14->GetYaxis()->SetTitleSize(0.06);
   h_T16__14->GetYaxis()->SetTitleFont(132);
   h_T16__14->GetZaxis()->SetLabelFont(132);
   h_T16__14->GetZaxis()->SetLabelSize(0.05);
   h_T16__14->GetZaxis()->SetTitleSize(0.06);
   h_T16__14->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T16);
   
   grae->Draw("p");
   
   TH1D *frame_1076b46d0__15 = new TH1D("frame_1076b46d0__15","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1076b46d0__15->SetMaximum(1581.26);
   frame_1076b46d0__15->SetDirectory(0);
   frame_1076b46d0__15->SetStats(0);
   frame_1076b46d0__15->SetMarkerStyle(8);
   frame_1076b46d0__15->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1076b46d0__15->GetXaxis()->SetLabelFont(132);
   frame_1076b46d0__15->GetXaxis()->SetLabelSize(0.05);
   frame_1076b46d0__15->GetXaxis()->SetTitleSize(0.06);
   frame_1076b46d0__15->GetXaxis()->SetTitleFont(132);
   frame_1076b46d0__15->GetYaxis()->SetTitle("Events");
   frame_1076b46d0__15->GetYaxis()->SetLabelFont(132);
   frame_1076b46d0__15->GetYaxis()->SetLabelSize(0.05);
   frame_1076b46d0__15->GetYaxis()->SetTitleSize(0.06);
   frame_1076b46d0__15->GetYaxis()->SetTitleFont(132);
   frame_1076b46d0__15->GetZaxis()->SetLabelFont(132);
   frame_1076b46d0__15->GetZaxis()->SetLabelSize(0.05);
   frame_1076b46d0__15->GetZaxis()->SetTitleSize(0.06);
   frame_1076b46d0__15->GetZaxis()->SetTitleFont(132);
   frame_1076b46d0__15->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
