#!/usr/bin/perl

#
# SubmitGenerate.pl
# N. Danielson June 19, 2003
# E. Di Marco Oct 10, 2008
#

use Getopt::Long;


my ($nexp, $njobs, $queue, $logdir, $prefix, $interactive, $command, $release, $disklocation, $datasetdir, $higgsmass);

# Defaults...

$nexp=1;
$njobs=50;
$queue='cmsshort';
$command='src/GenerateHiggsWW2e.cc';
$interactive=0;
$directory="toys/";
$prefix="0";
$use1jet=0;
$datasetdir="null";
$higgsmass="160";

if ($#ARGV < 1) {
    print <<ENDOFTEXT;
usage: SubmitGenerate.pl [OPTIONS]

 -h, --higgsMass=INTEGER
       Specify the Higgs mass. Default=160 (GeV)

 -b, --use1jet=INTEGER
       Use 1 jet bin.  Default=0 (false)

 -n, --nexp=INTEGER
       Number of experiments to run.  Default=$nexp
 
 -j, --jobs=INTEGER
       Number of jobs to submit.  Each job will run \#exp/\#jobs experiments
       (rounded down to the nearest integer).  Default=$njobs

 -q, --queue=STRING
       Queue to submit to.  Default=$queue

 -l, --log=STRING
       Name of directory to put the log files in.  Default=<Same as directory specified by -d flag>

 -d, --disklocation=STRING
       Name of directory to put the dat files in. Default=toys

 -m, --mockfitdir=STRING
       Name of directory where the datasets are. Default=null

 -p, --prefix=STRING
       Prefix to apply to the results and log file names to distinguish ee/emu/mumu toys: 0/1/2  Default is 0(ee). 

 -i, --interactive
       Run interactively, not in batch.

 -x, --exe=STRING
       Name of command to use.  Default=$command

 -r, --release=STRING
       CMSSW release where set the ROOT environment.

example: ./SubmitGenerate.pl -r ~/releases/vecbos/CMSSW_2_1_17 -n 10000 -j 10 -q cmsshort -p 0 -b 0 -x src/GenerateHWW2e.cc -d pccmsrm21.cern.ch:/cmsrm/pc21/emanuele/data/Higgs2.1.X/toys/ [-m ~/scratch0/higgs/Offline/HiggsMLFit/datasets/]

ENDOFTEXT

   exit 0;
}

GetOptions(
           "higgsmass|h=i" => \$higgsmass,
	   "use1jet|b=i"   => \$use1jet,
	   "nexp|n=i"      => \$nexp,
	   "jobs|j=i"      => \$njobs,
	   "queue|q=s"     => \$queue,
	   "log|l=s"       => \$logdir,
           "disklocation|d=s" => \$disklocation,
	   "prefix|p=s"    => \$prefix,
	   "interactive|i" => \$interactive,
	   "exe|x=s"       => \$command,
	   "release|r=s"   => \$release,
           "datasetdir|m=s" => \$datasetdir
	   );

# If CMSSW release is not set, exit
if (! defined $release) { 
    print "release is ot set. Set with -r option. Exiting.\n";
    exit 0;
}

# If no log directory was specified, use toys/log
if (! defined $logdir) {$logdir="$directory/log"};

# Does $logdir exist?
if (! -d "$logdir") {
    print STDERR "$logdir doesn't exist.  Do you want to create it? (y/n)\n";
    my $ans = <STDIN>;
    chomp($ans);
    if( ($ans =~ /yes/i) || ($ans eq "y") ) {
	print STDERR "Creating directory $logdir\n";
	`mkdir -p $logdir`;
    } else {
	print STDERR "Exiting because directory $logdir doesn't exist\n";
	exit 0;
    }
}

$outputdir=".";

# Does $scriptdir exist?
$scriptdir = "$directory/scripts";
if (! -d "$scriptdir") {
    print STDERR "$scriptdir doesn't exist.  Do you want to create it? (y/n)\n";
    my $ans = <STDIN>;
    chomp($ans);
    if( ($ans =~ /yes/i) || ($ans eq "y") ) {
        print STDERR "Creating directory $scriptdir\n";
        `mkdir -p $scriptdir`;
    } else {
        print STDERR "Exiting because directory $scriptdir doesn't exist\n";
        exit 0;
    }
}

my $nExpPerJob=int($nexp/$njobs);
my $ntotal=$nExpPerJob*$njobs;

print <<ENDOUT;
Will run $njobs jobs with $nExpPerJob experiments per job for a total of: $ntotal experiments.
Command:                    $command    
Directory to use:           $directory  
Directory for log files:    $logdir     
Directory for output files: $outputdir
Queue:                      $queue 
Release:                    $release
ENDOUT
    ;    
my $results=`ls -1 $outputdir/results-finalstate$prefix-[0-9]*.dat 2> /dev/null`;

$currDir=`pwd`;
chomp $currDir;

# Submit the jobs...
for (my $i = 1; $i <= $njobs; $i++){

    print "Running job $i out of $njobs\n";
    my $logfile = "$logdir/results-mH$higgsmass-finalstate$prefix-$i.log";
    my $iscript = "$scriptdir/script-mH$higgsmass-finalstate$prefix-$i.csh";
    my $outfile = "$outputdir/results-mH$higgsmass-finalstate$prefix-$i.dat"; 
    my $iseed = int(rand(65536)+$i);
    open(SCRIPTFILE,">$iscript");
    print SCRIPTFILE "\#\!/bin/tcsh\n\n";
    print SCRIPTFILE "cd $release\n";
    print SCRIPTFILE "eval `scramv1 ru -csh`\n";
    print SCRIPTFILE "cp -r $currDir/toyconfig \$WORKDIR\n";
    print SCRIPTFILE "cp -r $currDir/src \$WORKDIR\n";
    if($datasetdir =~ /null/) { }
    else {
        print SCRIPTFILE "cp -r $datasetdir \$WORKDIR\n";
    }
    print SCRIPTFILE "cd \$WORKDIR\n";
    print SCRIPTFILE "mkdir toys\n";
    print SCRIPTFILE "root -b src/RooLogon.C <<EOF\n";
    print SCRIPTFILE ".L $command\n";
    print SCRIPTFILE "SetHiggsMass($higgsmass)\n";
    print SCRIPTFILE "SetFinalState($prefix)\n";
    print SCRIPTFILE "Use1Jet($use1jet)\n";
    print SCRIPTFILE "Generate($nExpPerJob,$iseed,\"$outfile\")\n";
    print SCRIPTFILE ".q\n";
    print SCRIPTFILE "EOF\n";
    print SCRIPTFILE "scp -o BatchMode=yes -o StrictHostKeyChecking=no results-*dat $disklocation\n";
    print SCRIPTFILE "scp -o BatchMode=yes -o StrictHostKeyChecking=no *root $disklocation\n";
    system("chmod 777 $iscript");
    if ($interactive==1) {
	system("source $iscript");
    } else {
	system("bsub -q $queue -o $logfile -J fs$prefix-$i < $iscript");
    }
}

print "Done.\n";
