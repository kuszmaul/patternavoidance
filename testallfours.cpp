#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h> 
#include <stdlib.h>
#include <bitset>
#include <vector>
#include <stdint.h>
// #include <unordered_set>
#include <queue>
#include "hashdb.h"
#include <sys/time.h>
#include "fastavoidance.h"
#include "buildinput.h"
#include "oeislocal.h"
using namespace std;

int main() {
  // Writes all pattern sets of S_4 up to trivial wilf-equivalence to setsfilename
  // For each one, computes |S_1(Pi)|, ..., |S_maxpermsize(Pi)| and writes to sequencesfilename
  // For each sequence in sequencesfilename, looks up S_minpermsize(Pi), ..., S_maxpermsize(Pi) in OEIS and writes found oeis sequences to oeismatchesfilename
  
  int maxpermsize = 10;
  int minpermsize = 5;
  string setsfilename = "testallfours.txt";
  string sequencesfilename = "out-testallfours.txt";
  string oeismatchesfilename = "out-out-testallfours.txt";
  
  ofstream setsfile;
  setsfile.open(setsfilename, std::ofstream::trunc);
  writepatternsetstofile(setsfile, 4, true);
  setsfile.close();

  ifstream setsfilein;
  setsfilein.open(setsfilename);
  ofstream sequencesfile;
  sequencesfile.open(sequencesfilename, std::ofstream::trunc);
  countavoidersfromfile(setsfilein, sequencesfile, maxpermsize, true);
  setsfilein.close();
  sequencesfile.close();

  cout<<"Building local version of OEIS..."<<endl;
  Oeis OEIS("stripped", maxpermsize - minpermsize + 1, 15); // Note: we allow sequences to start in any of positions 1, 2, ..., 15
  ifstream sequencesfilein;
  sequencesfilein.open(sequencesfilename);
  ofstream oeismatchesfile;
  oeismatchesfile.open(oeismatchesfilename, std::ofstream::trunc);
  analyzesequencefile(sequencesfilein, oeismatchesfile, minpermsize - 1, OEIS, true, true);
  sequencesfilein.close();
  oeismatchesfile.close();
}
