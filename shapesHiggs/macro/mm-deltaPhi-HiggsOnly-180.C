{
//=========Macro generated from canvas: c/fitResult
//=========  (Tue Feb  9 15:30:50 2010) by ROOT version5.22/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,22,600,300);
   gStyle->SetOptStat(0);
   c->Range(-26.0241,-90.94976,190.8434,477.4863);
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
   
   TH1 *frame_161409448 = new TH1D("frame_161409448","A RooPlot of "#Delta#phi"",20,0,180);
   frame_161409448->SetMaximum(449.0645);
   frame_161409448->SetDirectory(0);
   frame_161409448->SetStats(0);
   frame_161409448->SetMarkerStyle(8);
   frame_161409448->GetXaxis()->SetTitle("#Delta #phi [#circ]");
   frame_161409448->GetXaxis()->SetLabelFont(132);
   frame_161409448->GetXaxis()->SetLabelSize(0.05);
   frame_161409448->GetXaxis()->SetTitleSize(0.06);
   frame_161409448->GetXaxis()->SetTitleFont(132);
   frame_161409448->GetYaxis()->SetTitle("Events");
   frame_161409448->GetYaxis()->SetLabelFont(132);
   frame_161409448->GetYaxis()->SetLabelSize(0.05);
   frame_161409448->GetYaxis()->SetTitleSize(0.06);
   frame_161409448->GetYaxis()->SetTitleFont(132);
   frame_161409448->GetZaxis()->SetLabelFont(132);
   frame_161409448->GetZaxis()->SetLabelSize(0.05);
   frame_161409448->GetZaxis()->SetTitleSize(0.06);
   frame_161409448->GetZaxis()->SetTitleFont(132);
   frame_161409448->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,4.5,313);
   grae->SetPointError(0,4.5,4.5,17.19887,18.19887);
   grae->SetPoint(1,13.5,317);
   grae->SetPointError(1,4.5,4.5,17.31151,18.31151);
   grae->SetPoint(2,22.5,407);
   grae->SetPointError(2,4.5,4.5,19.68044,20.68044);
   grae->SetPoint(3,31.5,385);
   grae->SetPointError(3,4.5,4.5,19.12779,20.12779);
   grae->SetPoint(4,40.5,407);
   grae->SetPointError(4,4.5,4.5,19.68044,20.68044);
   grae->SetPoint(5,49.5,389);
   grae->SetPointError(5,4.5,4.5,19.22942,20.22942);
   grae->SetPoint(6,58.5,359);
   grae->SetPointError(6,4.5,4.5,18.45389,19.45389);
   grae->SetPoint(7,67.5,318);
   grae->SetPointError(7,4.5,4.5,17.33956,18.33956);
   grae->SetPoint(8,76.5,231);
   grae->SetPointError(8,4.5,4.5,14.70691,15.70691);
   grae->SetPoint(9,85.5,184);
   grae->SetPointError(9,4.5,4.5,13.07387,14.07387);
   grae->SetPoint(10,94.5,124);
   grae->SetPointError(10,4.5,4.5,10.64675,11.64675);
   grae->SetPoint(11,103.5,99);
   grae->SetPointError(11,4.5,4.5,9.933044,10.9834);
   grae->SetPoint(12,112.5,71);
   grae->SetPointError(12,4.5,4.5,8.406258,9.465736);
   grae->SetPoint(13,121.5,47);
   grae->SetPointError(13,4.5,4.5,6.831172,7.904289);
   grae->SetPoint(14,130.5,36);
   grae->SetPointError(14,4.5,4.5,5.971996,7.055545);
   grae->SetPoint(15,139.5,24);
   grae->SetPointError(15,4.5,4.5,4.864612,5.966932);
   grae->SetPoint(16,148.5,16);
   grae->SetPointError(16,4.5,4.5,3.957801,5.083066);
   grae->SetPoint(17,157.5,14);
   grae->SetPointError(17,4.5,4.5,3.6965,4.830381);
   grae->SetPoint(18,166.5,9);
   grae->SetPointError(18,4.5,4.5,2.943461,4.110204);
   grae->SetPoint(19,175.5,19);
   grae->SetPointError(19,4.5,4.5,4.320219,5.435196);
   
   TH1 *h_T11 = new TH1F("h_T11","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T11->SetMinimum(0);
   h_T11->SetMaximum(469.8428);
   h_T11->SetDirectory(0);
   h_T11->SetStats(0);
   h_T11->SetMarkerStyle(8);
   h_T11->GetXaxis()->SetLabelFont(132);
   h_T11->GetXaxis()->SetLabelSize(0.05);
   h_T11->GetXaxis()->SetTitleSize(0.06);
   h_T11->GetXaxis()->SetTitleFont(132);
   h_T11->GetYaxis()->SetLabelFont(132);
   h_T11->GetYaxis()->SetLabelSize(0.05);
   h_T11->GetYaxis()->SetTitleSize(0.06);
   h_T11->GetYaxis()->SetTitleFont(132);
   h_T11->GetZaxis()->SetLabelFont(132);
   h_T11->GetZaxis()->SetLabelSize(0.05);
   h_T11->GetZaxis()->SetTitleSize(0.06);
   h_T11->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(h_T11);
   
   grae->Draw("p");
   
   TGraph *graph = new TGraph(47);
   graph->SetName("myFit_Int[jetcat]_Norm[deltaPhi,jetcat]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-9,0);
   graph->SetPoint(1,-9,288.1415);
   graph->SetPoint(2,0,288.1415);
   graph->SetPoint(3,4.5,307.6347);
   graph->SetPoint(4,9,326.2219);
   graph->SetPoint(5,13.5,343.5758);
   graph->SetPoint(6,18,359.3755);
   graph->SetPoint(7,22.5,373.3171);
   graph->SetPoint(8,27,385.1234);
   graph->SetPoint(9,31.5,394.553);
   graph->SetPoint(10,36,401.4092);
   graph->SetPoint(11,40.5,405.5466);
   graph->SetPoint(12,45,406.8732);
   graph->SetPoint(13,47.25,405.5139);
   graph->SetPoint(14,49.5,401.769);
   graph->SetPoint(15,51.75,395.7277);
   graph->SetPoint(16,54,387.5315);
   graph->SetPoint(17,56.25,377.3675);
   graph->SetPoint(18,58.5,365.4597);
   graph->SetPoint(19,60.75,352.0592);
   graph->SetPoint(20,63,337.4341);
   graph->SetPoint(21,67.5,305.6062);
   graph->SetPoint(22,72,272.0892);
   graph->SetPoint(23,76.5,238.7184);
   graph->SetPoint(24,81,206.9108);
   graph->SetPoint(25,85.5,177.6248);
   graph->SetPoint(26,87.75,164.109);
   graph->SetPoint(27,90,151.3951);
   graph->SetPoint(28,92.25,139.4967);
   graph->SetPoint(29,94.5,128.412);
   graph->SetPoint(30,99,108.6163);
   graph->SetPoint(31,103.5,91.78818);
   graph->SetPoint(32,108,77.62112);
   graph->SetPoint(33,112.5,65.77543);
   graph->SetPoint(34,117,55.91422);
   graph->SetPoint(35,121.5,47.72458);
   graph->SetPoint(36,126,40.92804);
   graph->SetPoint(37,130.5,35.28407);
   graph->SetPoint(38,135,30.58916);
   graph->SetPoint(39,144,23.39764);
   graph->SetPoint(40,153,18.32639);
   graph->SetPoint(41,162,14.68999);
   graph->SetPoint(42,171,12.03488);
   graph->SetPoint(43,180,10.06036);
   graph->SetPoint(44,180,10.06036);
   graph->SetPoint(45,189,10.06036);
   graph->SetPoint(46,189,0);
   
   TH1 *myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1 = new TH1F("myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1","Projection of Higgs to WW",100,-28.8,208.8);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetMinimum(0);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetMaximum(447.5606);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetDirectory(0);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetStats(0);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetMarkerStyle(8);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetXaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetXaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetXaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetXaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetYaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetYaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetYaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetYaxis()->SetTitleFont(132);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetZaxis()->SetLabelFont(132);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetZaxis()->SetLabelSize(0.05);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetZaxis()->SetTitleSize(0.06);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1);
   
   graph->Draw("l");
   
   TH1 *frame_161409448 = new TH1D("frame_161409448","A RooPlot of "#Delta#phi"",20,0,180);
   frame_161409448->SetMaximum(449.0645);
   frame_161409448->SetDirectory(0);
   frame_161409448->SetStats(0);
   frame_161409448->SetMarkerStyle(8);
   frame_161409448->GetXaxis()->SetTitle("#Delta #phi [#circ]");
   frame_161409448->GetXaxis()->SetLabelFont(132);
   frame_161409448->GetXaxis()->SetLabelSize(0.05);
   frame_161409448->GetXaxis()->SetTitleSize(0.06);
   frame_161409448->GetXaxis()->SetTitleFont(132);
   frame_161409448->GetYaxis()->SetTitle("Events");
   frame_161409448->GetYaxis()->SetLabelFont(132);
   frame_161409448->GetYaxis()->SetLabelSize(0.05);
   frame_161409448->GetYaxis()->SetTitleSize(0.06);
   frame_161409448->GetYaxis()->SetTitleFont(132);
   frame_161409448->GetZaxis()->SetLabelFont(132);
   frame_161409448->GetZaxis()->SetLabelSize(0.05);
   frame_161409448->GetZaxis()->SetTitleSize(0.06);
   frame_161409448->GetZaxis()->SetTitleFont(132);
   frame_161409448->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
