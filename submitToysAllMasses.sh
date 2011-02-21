#! /bin/sh

toydir=$1

for i in 120 130 140 150 160 170 200 210 220 230 250 300 400 500 600
do
  echo "SUBMITTING TOYS FOR MH = $i GEV/C^2...\n"
  masstoydir="${toydir}/mh${i}"
  ./SubmitGenerate.pl -r ~/scratch0/higgs/CMSSW_3_5_8 -n 1000 -j 10 -q 8nh -h $i -p 0 -b 0 -x src/GenerateHWW2l2nu.cc -d pccmsrm21.cern.ch:$masstoydir
done
