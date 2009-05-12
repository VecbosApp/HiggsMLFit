void makeBinningFile() {

  float UltraFineRegion_Min = 0.0;
  float UltraFineRegion_Max = 100.;
  float FineRegion_Max = 400.;
  float LargeRegion_Max = 5000.;

  int nBinsUltraFineRegion = 10;
  int nBinsFineRegion = 10;
  int nBinsLargeRegion = 3;

  float ultraFineStep = (UltraFineRegion_Max - UltraFineRegion_Min)/float(nBinsUltraFineRegion);
  float fineStep = (FineRegion_Max - UltraFineRegion_Max)/float(nBinsFineRegion);
  float largeStep = (LargeRegion_Max - FineRegion_Max)/float(nBinsLargeRegion);

  ofstream myfile;
  myfile.open ("binning.txt");

  for(float x = UltraFineRegion_Min; x<UltraFineRegion_Max; x+=ultraFineStep) {
    for(float y = UltraFineRegion_Min; y<UltraFineRegion_Max; y+=ultraFineStep) {
      myfile << x << "\t" << x+ultraFineStep << "\t" << y << "\t" << y+ultraFineStep << endl;
    }
  }

  for(float x = UltraFineRegion_Max; x<FineRegion_Max; x+=fineStep) {
    for(float y = UltraFineRegion_Max; y<FineRegion_Max; y+=fineStep) {
      myfile << x << "\t" << x+fineStep << "\t" << y << "\t" << y+fineStep << endl;
    }
  }

  for(float x = FineRegion_Max; x<LargeRegion_Max; x+=largeStep) {
    for(float y = FineRegion_Max; y<LargeRegion_Max; y+=largeStep) {
      myfile << x << "\t" << x+largeStep << "\t" << y << "\t" << y+largeStep << endl;
    }
  }

  myfile.close();

  return;

}
