#! /bin/sh

# usage: ./mergeToys toyresultsdir

toydir=$1

rm -f $toydir/ee/merged_ee.dat
touch $toydir/ee/merged_ee.dat
cat $toydir/ee/results-*dat >> $toydir/ee/merged_ee.dat

rm -f $toydir/mm/merged_mm.dat
touch $toydir/mm/merged_mm.dat
cat $toydir/mm/results-*dat >> $toydir/mm/merged_mm.dat

rm -f $toydir/em/merged_em.dat
touch $toydir/em/merged_em.dat
cat $toydir/em/results-*dat >> $toydir/em/merged_em.dat



