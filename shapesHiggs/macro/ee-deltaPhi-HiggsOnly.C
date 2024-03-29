{
//=========Macro generated from canvas: c/fitResult
//=========  (Tue Nov  3 18:14:23 2009) by ROOT version5.22/00a
   TCanvas *c = new TCanvas("c", "fitResult",0,22,600,300);
   gStyle->SetOptStat(0);
   c->Range(-26.0241,-0.1238405,190.8434,0.6501628);
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
   
   TH1 *frame_188452408 = new TH1D("frame_188452408","A RooPlot of "#Delta#phi"",13,0,180);
   frame_188452408->SetMaximum(0.6114626);
   frame_188452408->SetDirectory(0);
   frame_188452408->SetStats(0);
   frame_188452408->SetMarkerStyle(8);
   frame_188452408->GetXaxis()->SetTitle("#Delta #phi [#circ]");
   frame_188452408->GetXaxis()->SetLabelFont(132);
   frame_188452408->GetXaxis()->SetLabelSize(0.05);
   frame_188452408->GetXaxis()->SetTitleSize(0.06);
   frame_188452408->GetXaxis()->SetTitleFont(132);
   frame_188452408->GetYaxis()->SetTitle("Events");
   frame_188452408->GetYaxis()->SetLabelFont(132);
   frame_188452408->GetYaxis()->SetLabelSize(0.05);
   frame_188452408->GetYaxis()->SetTitleSize(0.06);
   frame_188452408->GetYaxis()->SetTitleFont(132);
   frame_188452408->GetZaxis()->SetLabelFont(132);
   frame_188452408->GetZaxis()->SetLabelSize(0.05);
   frame_188452408->GetZaxis()->SetTitleSize(0.06);
   frame_188452408->GetZaxis()->SetTitleFont(132);
   frame_188452408->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(13);
   grae->SetName("h_T1");
   grae->SetTitle("Histogram of T1_plot__deltaPhi");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(8);
   grae->SetPoint(0,6.923077,0.3541787);
   grae->SetPointError(0,6.923077,6.923077,0.02398797,0.02398797);
   grae->SetPoint(1,20.76923,0.5377661);
   grae->SetPointError(1,6.923077,6.923077,0.02955828,0.02955828);
   grae->SetPoint(2,34.61538,0.5523879);
   grae->SetPointError(2,6.923077,6.923077,0.02995743,0.02995743);
   grae->SetPoint(3,48.46154,0.4467851);
   grae->SetPointError(3,6.923077,6.923077,0.0269421,0.0269421);
   grae->SetPoint(4,62.30769,0.3882968);
   grae->SetPointError(4,6.923077,6.923077,0.02511679,0.02511679);
   grae->SetPoint(5,76.15385,0.2989398);
   grae->SetPointError(5,6.923077,6.923077,0.0220381,0.0220381);
   grae->SetPoint(6,90,0.2290788);
   grae->SetPointError(6,6.923077,6.923077,0.01929189,0.01929189);
   grae->SetPoint(7,103.8462,0.19821);
   grae->SetPointError(7,6.923077,6.923077,0.01794507,0.01794507);
   grae->SetPoint(8,117.6923,0.108853);
   grae->SetPointError(8,6.923077,6.923077,0.0132985,0.0132985);
   grae->SetPoint(9,131.5385,0.08610756);
   grae->SetPointError(9,6.923077,6.923077,0.01182778,0.01182778);
   grae->SetPoint(10,145.3846,0.08123354);
   grae->SetPointError(10,6.923077,6.923077,0.01148815,0.01148815);
   grae->SetPoint(11,159.2308,0.04386609);
   grae->SetPointError(11,6.923077,6.923077,0.008442033,0.008442033);
   grae->SetPoint(12,173.0769,0.04224142);
   grae->SetPointError(12,6.923077,6.923077,0.008284224,0.008284224);
   
   TH1 *h_T11 = new TH1F("h_T11","Histogram of T1_plot__deltaPhi",100,0,198);
   h_T11->SetMinimum(0);
   h_T11->SetMaximum(0.6371841);
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
   
   TGraph *graph = new TGraph(54);
   graph->SetName("myFit_Int[jetcat]_Norm[deltaPhi,jetcat]");
   graph->SetTitle("Projection of Higgs to WW");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(8);
   graph->SetPoint(0,-13.84615,0);
   graph->SetPoint(1,-13.84615,0.3170116);
   graph->SetPoint(2,0,0.3170116);
   graph->SetPoint(3,1.730769,0.3218169);
   graph->SetPoint(4,3.461538,0.32775);
   graph->SetPoint(5,5.192308,0.3351609);
   graph->SetPoint(6,6.923077,0.344526);
   graph->SetPoint(7,8.653846,0.3564904);
   graph->SetPoint(8,10.38462,0.3719086);
   graph->SetPoint(9,11.25,0.3812396);
   graph->SetPoint(10,12.11538,0.3918461);
   graph->SetPoint(11,12.98077,0.4038723);
   graph->SetPoint(12,13.84615,0.4174415);
   graph->SetPoint(13,14.71154,0.4326249);
   graph->SetPoint(14,15.57692,0.4493963);
   graph->SetPoint(15,17.30769,0.4867162);
   graph->SetPoint(16,19.03846,0.5246322);
   graph->SetPoint(17,19.90385,0.5409051);
   graph->SetPoint(18,20.33654,0.5477094);
   graph->SetPoint(19,20.76923,0.5533721);
   graph->SetPoint(20,21.20192,0.5577256);
   graph->SetPoint(21,21.63462,0.5606341);
   graph->SetPoint(22,22.06731,0.5620033);
   graph->SetPoint(23,22.5,0.5620988);
   graph->SetPoint(24,24.23077,0.5615645);
   graph->SetPoint(25,27.69231,0.5580809);
   graph->SetPoint(26,31.15385,0.5514552);
   graph->SetPoint(27,34.61538,0.5418451);
   graph->SetPoint(28,38.07692,0.5294741);
   graph->SetPoint(29,41.53846,0.5146209);
   graph->SetPoint(30,45,0.4976068);
   graph->SetPoint(31,48.46154,0.4787818);
   graph->SetPoint(32,51.92308,0.4585105);
   graph->SetPoint(33,55.38462,0.4371588);
   graph->SetPoint(34,69.23077,0.3476884);
   graph->SetPoint(35,76.15385,0.3043966);
   graph->SetPoint(36,83.07692,0.2641405);
   graph->SetPoint(37,90,0.2277466);
   graph->SetPoint(38,93.46154,0.2111223);
   graph->SetPoint(39,96.92308,0.1955638);
   graph->SetPoint(40,103.8462,0.1675878);
   graph->SetPoint(41,110.7692,0.1435812);
   graph->SetPoint(42,117.6923,0.1231742);
   graph->SetPoint(43,124.6154,0.1059397);
   graph->SetPoint(44,131.5385,0.0914438);
   graph->SetPoint(45,138.4615,0.07927688);
   graph->SetPoint(46,145.3846,0.06906962);
   graph->SetPoint(47,152.3077,0.06049936);
   graph->SetPoint(48,159.2308,0.05329029);
   graph->SetPoint(49,166.1538,0.04721023);
   graph->SetPoint(50,180,0.03769687);
   graph->SetPoint(51,180,0.03769687);
   graph->SetPoint(52,193.8462,0.03769687);
   graph->SetPoint(53,193.8462,0);
   
   TH1 *myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1 = new TH1F("myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1","Projection of Higgs to WW",100,-34.61538,214.6154);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetMinimum(0);
   myFit_Int[jetcat]_Norm[deltaPhi,jetcat]1->SetMaximum(0.6183086);
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
   
   TH1 *frame_188452408 = new TH1D("frame_188452408","A RooPlot of "#Delta#phi"",13,0,180);
   frame_188452408->SetMaximum(0.6114626);
   frame_188452408->SetDirectory(0);
   frame_188452408->SetStats(0);
   frame_188452408->SetMarkerStyle(8);
   frame_188452408->GetXaxis()->SetTitle("#Delta #phi [#circ]");
   frame_188452408->GetXaxis()->SetLabelFont(132);
   frame_188452408->GetXaxis()->SetLabelSize(0.05);
   frame_188452408->GetXaxis()->SetTitleSize(0.06);
   frame_188452408->GetXaxis()->SetTitleFont(132);
   frame_188452408->GetYaxis()->SetTitle("Events");
   frame_188452408->GetYaxis()->SetLabelFont(132);
   frame_188452408->GetYaxis()->SetLabelSize(0.05);
   frame_188452408->GetYaxis()->SetTitleSize(0.06);
   frame_188452408->GetYaxis()->SetTitleFont(132);
   frame_188452408->GetZaxis()->SetLabelFont(132);
   frame_188452408->GetZaxis()->SetLabelSize(0.05);
   frame_188452408->GetZaxis()->SetTitleSize(0.06);
   frame_188452408->GetZaxis()->SetTitleFont(132);
   frame_188452408->Draw("AXISSAME");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
