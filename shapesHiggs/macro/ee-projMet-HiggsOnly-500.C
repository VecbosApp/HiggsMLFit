{
//=========Macro generated from canvas: c/fitResult
//=========  (Sat Feb 19 12:38:58 2011) by ROOT version5.27/06
   TCanvas *c = new TCanvas("c", "fitResult",4,22,900,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(-36.14458,-18.01189,265.0602,94.56243);
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
   
   TH1D *frame_1070b3390__11 = new TH1D("frame_1070b3390__11","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1070b3390__11->SetMaximum(88.93371);
   frame_1070b3390__11->SetDirectory(0);
   frame_1070b3390__11->SetStats(0);
   frame_1070b3390__11->SetMarkerStyle(8);
   frame_1070b3390__11->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1070b3390__11->GetXaxis()->SetLabelFont(132);
   frame_1070b3390__11->GetXaxis()->SetLabelSize(0.05);
   frame_1070b3390__11->GetXaxis()->SetTitleSize(0.06);
   frame_1070b3390__11->GetXaxis()->SetTitleFont(132);
   frame_1070b3390__11->GetYaxis()->SetTitle("Events");
   frame_1070b3390__11->GetYaxis()->SetLabelFont(132);
   frame_1070b3390__11->GetYaxis()->SetLabelSize(0.05);
   frame_1070b3390__11->GetYaxis()->SetTitleSize(0.06);
   frame_1070b3390__11->GetYaxis()->SetTitleFont(132);
   frame_1070b3390__11->GetZaxis()->SetLabelFont(132);
   frame_1070b3390__11->GetZaxis()->SetLabelSize(0.05);
   frame_1070b3390__11->GetZaxis()->SetTitleSize(0.06);
   frame_1070b3390__11->GetZaxis()->SetTitleFont(132);
   frame_1070b3390__11->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(30);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__projMet");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.166667,75);
   grae->SetPointError(0,4.166667,4.166667,8.640903,9.698771);
   grae->SetPoint(1,12.5,74);
   grae->SetPointError(1,4.166667,4.166667,8.582844,9.641101);
   grae->SetPoint(2,20.83333,56);
   grae->SetPointError(2,4.166667,4.166667,7.4609,8.527879);
   grae->SetPoint(3,29.16667,69);
   grae->SetPointError(3,4.166667,4.166667,8.286444,9.346779);
   grae->SetPoint(4,37.5,57);
   grae->SetPointError(4,4.166667,4.166667,7.527619,8.594007);
   grae->SetPoint(5,45.83333,71);
   grae->SetPointError(5,4.166667,4.166667,8.406258,9.465736);
   grae->SetPoint(6,54.16667,59);
   grae->SetPointError(6,4.166667,4.166667,7.659312,8.724565);
   grae->SetPoint(7,62.5,70);
   grae->SetPointError(7,4.166667,4.166667,8.346566,9.406468);
   grae->SetPoint(8,70.83333,44);
   grae->SetPointError(8,4.166667,4.166667,6.60794,7.68351);
   grae->SetPoint(9,79.16667,42);
   grae->SetPointError(9,4.166667,4.166667,6.454831,7.53218);
   grae->SetPoint(10,87.5,26);
   grae->SetPointError(10,4.166667,4.166667,5.066015,6.164324);
   grae->SetPoint(11,95.83333,25);
   grae->SetPointError(11,4.166667,4.166667,4.966335,6.066589);
   grae->SetPoint(12,104.1667,20);
   grae->SetPointError(12,4.166667,4.166667,4.434448,5.546519);
   grae->SetPoint(13,112.5,13);
   grae->SetPointError(13,4.166667,4.166667,3.558662,4.697573);
   grae->SetPoint(14,120.8333,2);
   grae->SetPointError(14,4.166667,4.166667,1.291815,2.63786);
   grae->SetPoint(15,129.1667,4);
   grae->SetPointError(15,4.166667,4.166667,1.914339,3.162753);
   grae->SetPoint(16,137.5,1);
   grae->SetPointError(16,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(17,145.8333,0);
   grae->SetPointError(17,4.166667,4.166667,0,1.147874);
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
   h_T15__12->SetMaximum(93.16865);
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
   
   TGraph *graph = new TGraph(57);
   graph->SetName("myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-8.333333,0);
   graph->SetPoint(1,-8.333333,64.71843);
   graph->SetPoint(2,0,64.71843);
   graph->SetPoint(3,8.333333,64.72801);
   graph->SetPoint(4,16.66667,64.74486);
   graph->SetPoint(5,25,64.77861);
   graph->SetPoint(6,33.33333,64.86124);
   graph->SetPoint(7,41.66667,65.14521);
   graph->SetPoint(8,45.83333,65.57911);
   graph->SetPoint(9,50,66.4219);
   graph->SetPoint(10,52.08333,66.67575);
   graph->SetPoint(11,54.16667,66.53203);
   graph->SetPoint(12,56.25,66.06895);
   graph->SetPoint(13,58.33333,65.29346);
   graph->SetPoint(14,60.41667,64.21663);
   graph->SetPoint(15,62.5,62.85371);
   graph->SetPoint(16,64.58333,61.22376);
   graph->SetPoint(17,66.66667,59.34917);
   graph->SetPoint(18,68.75,57.25519);
   graph->SetPoint(19,70.83333,54.96937);
   graph->SetPoint(20,75,49.94008);
   graph->SetPoint(21,79.16667,44.50412);
   graph->SetPoint(22,83.33333,38.90215);
   graph->SetPoint(23,87.5,33.35565);
   graph->SetPoint(24,91.66667,28.05353);
   graph->SetPoint(25,95.83333,23.14346);
   graph->SetPoint(26,97.91667,20.86925);
   graph->SetPoint(27,100,18.728);
   graph->SetPoint(28,102.0833,16.72558);
   graph->SetPoint(29,104.1667,14.86541);
   graph->SetPoint(30,106.25,13.14856);
   graph->SetPoint(31,108.3333,11.57404);
   graph->SetPoint(32,110.4167,10.13905);
   graph->SetPoint(33,112.5,8.839248);
   graph->SetPoint(34,116.6667,6.621681);
   graph->SetPoint(35,120.8333,4.865682);
   graph->SetPoint(36,125,3.507047);
   graph->SetPoint(37,129.1667,2.479488);
   graph->SetPoint(38,133.3333,1.719511);
   graph->SetPoint(39,137.5,1.169689);
   graph->SetPoint(40,141.6667,0.7804742);
   graph->SetPoint(41,150,0.327946);
   graph->SetPoint(42,158.3333,0.1275665);
   graph->SetPoint(43,166.6667,0.04593685);
   graph->SetPoint(44,175,0.01531357);
   graph->SetPoint(45,183.3333,0.00472588);
   graph->SetPoint(46,191.6667,0.001350143);
   graph->SetPoint(47,200,0.000357082);
   graph->SetPoint(48,208.3333,8.742741e-05);
   graph->SetPoint(49,216.6667,1.981612e-05);
   graph->SetPoint(50,225,4.157972e-06);
   graph->SetPoint(51,233.3333,8.076746e-07);
   graph->SetPoint(52,241.6667,1.452391e-07);
   graph->SetPoint(53,250,2.417814e-08);
   graph->SetPoint(54,250,2.417814e-08);
   graph->SetPoint(55,258.3333,2.417814e-08);
   graph->SetPoint(56,258.3333,0);
   
   TH1F *myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13 = new TH1F("myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13","Projection of Higgs to WW",100,-35,285);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetMinimum(0);
   myFit_Int[deltaPhi,maxPtEle]_Norm[deltaPhi,maxPtEle,projMet]3__13->SetMaximum(73.34333);
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
   grae->SetPoint(0,4.166667,75);
   grae->SetPointError(0,4.166667,4.166667,8.640903,9.698771);
   grae->SetPoint(1,12.5,74);
   grae->SetPointError(1,4.166667,4.166667,8.582844,9.641101);
   grae->SetPoint(2,20.83333,56);
   grae->SetPointError(2,4.166667,4.166667,7.4609,8.527879);
   grae->SetPoint(3,29.16667,69);
   grae->SetPointError(3,4.166667,4.166667,8.286444,9.346779);
   grae->SetPoint(4,37.5,57);
   grae->SetPointError(4,4.166667,4.166667,7.527619,8.594007);
   grae->SetPoint(5,45.83333,71);
   grae->SetPointError(5,4.166667,4.166667,8.406258,9.465736);
   grae->SetPoint(6,54.16667,59);
   grae->SetPointError(6,4.166667,4.166667,7.659312,8.724565);
   grae->SetPoint(7,62.5,70);
   grae->SetPointError(7,4.166667,4.166667,8.346566,9.406468);
   grae->SetPoint(8,70.83333,44);
   grae->SetPointError(8,4.166667,4.166667,6.60794,7.68351);
   grae->SetPoint(9,79.16667,42);
   grae->SetPointError(9,4.166667,4.166667,6.454831,7.53218);
   grae->SetPoint(10,87.5,26);
   grae->SetPointError(10,4.166667,4.166667,5.066015,6.164324);
   grae->SetPoint(11,95.83333,25);
   grae->SetPointError(11,4.166667,4.166667,4.966335,6.066589);
   grae->SetPoint(12,104.1667,20);
   grae->SetPointError(12,4.166667,4.166667,4.434448,5.546519);
   grae->SetPoint(13,112.5,13);
   grae->SetPointError(13,4.166667,4.166667,3.558662,4.697573);
   grae->SetPoint(14,120.8333,2);
   grae->SetPointError(14,4.166667,4.166667,1.291815,2.63786);
   grae->SetPoint(15,129.1667,4);
   grae->SetPointError(15,4.166667,4.166667,1.914339,3.162753);
   grae->SetPoint(16,137.5,1);
   grae->SetPointError(16,4.166667,4.166667,0.8272462,2.299527);
   grae->SetPoint(17,145.8333,0);
   grae->SetPointError(17,4.166667,4.166667,0,1.147874);
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
   h_T16__14->SetMaximum(93.16865);
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
   
   TH1D *frame_1070b3390__15 = new TH1D("frame_1070b3390__15","A RooPlot of "E_{T}^{miss}"",30,0,250);
   frame_1070b3390__15->SetMaximum(88.93371);
   frame_1070b3390__15->SetDirectory(0);
   frame_1070b3390__15->SetStats(0);
   frame_1070b3390__15->SetMarkerStyle(8);
   frame_1070b3390__15->GetXaxis()->SetTitle("proj. missing E_{T} [GeV]");
   frame_1070b3390__15->GetXaxis()->SetLabelFont(132);
   frame_1070b3390__15->GetXaxis()->SetLabelSize(0.05);
   frame_1070b3390__15->GetXaxis()->SetTitleSize(0.06);
   frame_1070b3390__15->GetXaxis()->SetTitleFont(132);
   frame_1070b3390__15->GetYaxis()->SetTitle("Events");
   frame_1070b3390__15->GetYaxis()->SetLabelFont(132);
   frame_1070b3390__15->GetYaxis()->SetLabelSize(0.05);
   frame_1070b3390__15->GetYaxis()->SetTitleSize(0.06);
   frame_1070b3390__15->GetYaxis()->SetTitleFont(132);
   frame_1070b3390__15->GetZaxis()->SetLabelFont(132);
   frame_1070b3390__15->GetZaxis()->SetLabelSize(0.05);
   frame_1070b3390__15->GetZaxis()->SetTitleSize(0.06);
   frame_1070b3390__15->GetZaxis()->SetTitleFont(132);
   frame_1070b3390__15->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
