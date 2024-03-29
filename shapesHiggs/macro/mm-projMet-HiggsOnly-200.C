{
//=========Macro generated from canvas: c/fitResult
//=========  (Fri Feb 18 14:59:16 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-36.14458,-171.9199,265.0602,902.5796);
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
   
   TH1D *frame_105887b20__11 = new TH1D("frame_105887b20__11","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_105887b20__11->SetMaximum(848.8546);
   frame_105887b20__11->SetDirectory(0);
   frame_105887b20__11->SetStats(0);
   frame_105887b20__11->SetMarkerStyle(8);
   frame_105887b20__11->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_105887b20__11->GetXaxis()->SetLabelFont(132);
   frame_105887b20__11->GetXaxis()->SetLabelSize(0.05);
   frame_105887b20__11->GetXaxis()->SetTitleSize(0.06);
   frame_105887b20__11->GetXaxis()->SetTitleFont(132);
   frame_105887b20__11->GetYaxis()->SetTitle("Events");
   frame_105887b20__11->GetYaxis()->SetLabelFont(132);
   frame_105887b20__11->GetYaxis()->SetLabelSize(0.05);
   frame_105887b20__11->GetYaxis()->SetTitleSize(0.06);
   frame_105887b20__11->GetYaxis()->SetTitleFont(132);
   frame_105887b20__11->GetZaxis()->SetLabelFont(132);
   frame_105887b20__11->GetZaxis()->SetLabelSize(0.05);
   frame_105887b20__11->GetZaxis()->SetTitleSize(0.06);
   frame_105887b20__11->GetZaxis()->SetTitleFont(132);
   frame_105887b20__11->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,63);
   grae->SetPointError(0,4.166667,4.166667,7.916129,8.979274);
   grae->SetPoint(1,12.5,94);
   grae->SetPointError(1,4.166667,4.166667,9.678086,10.72977);
   grae->SetPoint(2,20.83333,112);
   grae->SetPointError(2,4.166667,4.166667,10.09481,11.09481);
   grae->SetPoint(3,29.16667,146);
   grae->SetPointError(3,4.166667,4.166667,11.59339,12.59339);
   grae->SetPoint(4,37.5,229);
   grae->SetPointError(4,4.166667,4.166667,14.641,15.641);
   grae->SetPoint(5,45.83333,307);
   grae->SetPointError(5,4.166667,4.166667,17.02855,18.02855);
   grae->SetPoint(6,54.16667,475);
   grae->SetPointError(6,4.166667,4.166667,21.30023,22.30023);
   grae->SetPoint(7,62.5,612);
   grae->SetPointError(7,4.166667,4.166667,24.24369,25.24369);
   grae->SetPoint(8,70.83333,780);
   grae->SetPointError(8,4.166667,4.166667,27.43296,28.43296);
   grae->SetPoint(9,79.16667,646);
   grae->SetPointError(9,4.166667,4.166667,24.92145,25.92145);
   grae->SetPoint(10,87.5,328);
   grae->SetPointError(10,4.166667,4.166667,17.61767,18.61767);
   grae->SetPoint(11,95.83333,103);
   grae->SetPointError(11,4.166667,4.166667,9.661201,10.6612);
   grae->SetPoint(12,104.1667,20);
   grae->SetPointError(12,4.166667,4.166667,4.434448,5.546519);
   grae->SetPoint(13,112.5,6);
   grae->SetPointError(13,4.166667,4.166667,2.379931,3.583642);
   grae->SetPoint(14,120.8333,3);
   grae->SetPointError(14,4.166667,4.166667,1.632705,2.918186);
   grae->SetPoint(15,129.1667,1);
   grae->SetPointError(15,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(16,137.5,0);
   grae->SetPointError(16,4.166667,4.166667,0,1.147874);
   grae->SetPoint(17,145.8333,2);
   grae->SetPointError(17,4.166667,4.166667,1.291815,2.63786);
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
   
   TH1F *h_T15__12 = new TH1F("h_T15__12","Histogram of T1_plot__projMet",100,0,275);
   h_T15__12->SetMinimum(0);
   h_T15__12->SetMaximum(889.2763);
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
   graph->SetName("myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-8.333333,0);
   graph->SetPoint(1,-8.333333,64.8184);
   graph->SetPoint(2,0,64.8184);
   graph->SetPoint(3,8.333333,78.0331);
   graph->SetPoint(4,12.5,86.90457);
   graph->SetPoint(5,16.66667,97.86958);
   graph->SetPoint(6,20.83333,111.5445);
   graph->SetPoint(7,25,128.7406);
   graph->SetPoint(8,29.16667,150.5123);
   graph->SetPoint(9,31.25,163.5208);
   graph->SetPoint(10,33.33333,178.1987);
   graph->SetPoint(11,35.41667,194.7586);
   graph->SetPoint(12,37.5,213.4268);
   graph->SetPoint(13,39.58333,234.4374);
   graph->SetPoint(14,41.66667,258.0214);
   graph->SetPoint(15,43.75,284.3919);
   graph->SetPoint(16,45.83333,313.7223);
   graph->SetPoint(17,47.91667,346.1182);
   graph->SetPoint(18,50,381.5813);
   graph->SetPoint(19,52.08333,419.9673);
   graph->SetPoint(20,54.16667,460.9407);
   graph->SetPoint(21,58.33333,548.094);
   graph->SetPoint(22,62.5,635.1667);
   graph->SetPoint(23,64.58333,675.0636);
   graph->SetPoint(24,66.66667,710.2642);
   graph->SetPoint(25,67.70833,725.5631);
   graph->SetPoint(26,68.75,739.0562);
   graph->SetPoint(27,69.79167,750.5594);
   graph->SetPoint(28,70.83333,759.9109);
   graph->SetPoint(29,71.875,766.9756);
   graph->SetPoint(30,72.91667,771.6494);
   graph->SetPoint(31,73.95833,773.8624);
   graph->SetPoint(32,74.47917,773.9896);
   graph->SetPoint(33,75,772.2589);
   graph->SetPoint(34,75.52083,768.1591);
   graph->SetPoint(35,76.04167,761.735);
   graph->SetPoint(36,76.5625,753.0559);
   graph->SetPoint(37,77.08333,742.2145);
   graph->SetPoint(38,77.60417,729.3249);
   graph->SetPoint(39,78.125,714.5207);
   graph->SetPoint(40,78.64583,697.9517);
   graph->SetPoint(41,79.16667,679.7818);
   graph->SetPoint(42,80.20833,639.3454);
   graph->SetPoint(43,81.25,594.6817);
   graph->SetPoint(44,83.33333,498.6003);
   graph->SetPoint(45,85.41667,402.3808);
   graph->SetPoint(46,86.45833,356.8804);
   graph->SetPoint(47,87.5,314.1096);
   graph->SetPoint(48,88.54167,274.54);
   graph->SetPoint(49,89.58333,238.4471);
   graph->SetPoint(50,90.625,205.9383);
   graph->SetPoint(51,91.66667,176.9843);
   graph->SetPoint(52,92.70833,151.4514);
   graph->SetPoint(53,93.75,129.1321);
   graph->SetPoint(54,94.79167,109.7712);
   graph->SetPoint(55,95.83333,93.08869);
   graph->SetPoint(56,96.875,78.79651);
   graph->SetPoint(57,97.91667,66.61203);
   graph->SetPoint(58,98.95833,56.26697);
   graph->SetPoint(59,100,47.5132);
   graph->SetPoint(60,102.0833,33.90455);
   graph->SetPoint(61,104.1667,24.27823);
   graph->SetPoint(62,106.25,17.48998);
   graph->SetPoint(63,108.3333,12.70139);
   graph->SetPoint(64,112.5,6.901921);
   graph->SetPoint(65,116.6667,3.926434);
   graph->SetPoint(66,125,1.471485);
   graph->SetPoint(67,133.3333,0.6638038);
   graph->SetPoint(68,141.6667,0.3507409);
   graph->SetPoint(69,150,0.2105474);
   graph->SetPoint(70,158.3333,0.1397527);
   graph->SetPoint(71,166.6667,0.1003336);
   graph->SetPoint(72,175,0.07658189);
   graph->SetPoint(73,183.3333,0.06132644);
   graph->SetPoint(74,191.6667,0.05100492);
   graph->SetPoint(75,200,0.04371702);
   graph->SetPoint(76,208.3333,0.03838591);
   graph->SetPoint(77,216.6667,0.03436919);
   graph->SetPoint(78,225,0.03126638);
   graph->SetPoint(79,233.3333,0.0288181);
   graph->SetPoint(80,241.6667,0.02685074);
   graph->SetPoint(81,250,0.02524472);
   graph->SetPoint(82,250,0.02524472);
   graph->SetPoint(83,258.3333,0.02524472);
   graph->SetPoint(84,258.3333,0);
   
   TH1F *myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13 = new TH1F("myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13","Projection of Higgs to WW",100,-35,285);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetMinimum(0);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetMaximum(851.3885);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetDirectory(0);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetStats(0);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetMarkerStyle(8);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetXaxis()->SetLabelFont(132);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetXaxis()->SetTitleFont(132);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetYaxis()->SetLabelFont(132);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetYaxis()->SetTitleFont(132);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetZaxis()->SetLabelFont(132);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3);
   
   graph->Draw("l");
   
   grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,63);
   grae->SetPointError(0,4.166667,4.166667,7.916129,8.979274);
   grae->SetPoint(1,12.5,94);
   grae->SetPointError(1,4.166667,4.166667,9.678086,10.72977);
   grae->SetPoint(2,20.83333,112);
   grae->SetPointError(2,4.166667,4.166667,10.09481,11.09481);
   grae->SetPoint(3,29.16667,146);
   grae->SetPointError(3,4.166667,4.166667,11.59339,12.59339);
   grae->SetPoint(4,37.5,229);
   grae->SetPointError(4,4.166667,4.166667,14.641,15.641);
   grae->SetPoint(5,45.83333,307);
   grae->SetPointError(5,4.166667,4.166667,17.02855,18.02855);
   grae->SetPoint(6,54.16667,475);
   grae->SetPointError(6,4.166667,4.166667,21.30023,22.30023);
   grae->SetPoint(7,62.5,612);
   grae->SetPointError(7,4.166667,4.166667,24.24369,25.24369);
   grae->SetPoint(8,70.83333,780);
   grae->SetPointError(8,4.166667,4.166667,27.43296,28.43296);
   grae->SetPoint(9,79.16667,646);
   grae->SetPointError(9,4.166667,4.166667,24.92145,25.92145);
   grae->SetPoint(10,87.5,328);
   grae->SetPointError(10,4.166667,4.166667,17.61767,18.61767);
   grae->SetPoint(11,95.83333,103);
   grae->SetPointError(11,4.166667,4.166667,9.661201,10.6612);
   grae->SetPoint(12,104.1667,20);
   grae->SetPointError(12,4.166667,4.166667,4.434448,5.546519);
   grae->SetPoint(13,112.5,6);
   grae->SetPointError(13,4.166667,4.166667,2.379931,3.583642);
   grae->SetPoint(14,120.8333,3);
   grae->SetPointError(14,4.166667,4.166667,1.632705,2.918186);
   grae->SetPoint(15,129.1667,1);
   grae->SetPointError(15,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(16,137.5,0);
   grae->SetPointError(16,4.166667,4.166667,0,1.147874);
   grae->SetPoint(17,145.8333,2);
   grae->SetPointError(17,4.166667,4.166667,1.291815,2.63786);
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
   
   TH1F *h_T16__14 = new TH1F("h_T16__14","Histogram of T1_plot__projMet",100,0,275);
   h_T16__14->SetMinimum(0);
   h_T16__14->SetMaximum(889.2763);
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
   
   TH1D *frame_105887b20__15 = new TH1D("frame_105887b20__15","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_105887b20__15->SetMaximum(848.8546);
   frame_105887b20__15->SetDirectory(0);
   frame_105887b20__15->SetStats(0);
   frame_105887b20__15->SetMarkerStyle(8);
   frame_105887b20__15->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_105887b20__15->GetXaxis()->SetLabelFont(132);
   frame_105887b20__15->GetXaxis()->SetLabelSize(0.05);
   frame_105887b20__15->GetXaxis()->SetTitleSize(0.06);
   frame_105887b20__15->GetXaxis()->SetTitleFont(132);
   frame_105887b20__15->GetYaxis()->SetTitle("Events");
   frame_105887b20__15->GetYaxis()->SetLabelFont(132);
   frame_105887b20__15->GetYaxis()->SetLabelSize(0.05);
   frame_105887b20__15->GetYaxis()->SetTitleSize(0.06);
   frame_105887b20__15->GetYaxis()->SetTitleFont(132);
   frame_105887b20__15->GetZaxis()->SetLabelFont(132);
   frame_105887b20__15->GetZaxis()->SetLabelSize(0.05);
   frame_105887b20__15->GetZaxis()->SetTitleSize(0.06);
   frame_105887b20__15->GetZaxis()->SetTitleFont(132);
   frame_105887b20__15->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
