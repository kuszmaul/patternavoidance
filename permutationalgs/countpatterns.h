#ifndef _COUNTPATTERNS_H 
#define _COUNTPATTERNS_H // To avoid header being included twice in complilation process.

#include <assert.h>
#include <string.h>
//#include <iostream>
#include <cmath>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h> 
#include <stdlib.h>
#include <bitset>
#include <vector>
#include <stdint.h>
#include <unordered_map>
#include <queue>
#include "hashdb.h"
#include "hashmap.h"
#include <sys/time.h>
#include "perm.h"
using namespace std;

// Requires all patterns size 3 or more
// Example usage:
// string patternlist = "123 3124";
// int maxpermize = 10;
// vector < vector <int> > tally;
// vector < vector <int> > completelist;
// countpatterns(patternlist, maxpermsize, tally, completelist, false, false);
// Now tally[i][j] contains the number of permutation in S_i containing exactly j pattern-list-patterns. Range: 0 < i < maxpermsize + 1, 0 < j <= largest j such that tally[i][j] should exceed zero
// Now completelist[i][permtonum(perm)] is the number of pattern-set-hits appearing in perm, where perm \in S_i. Range 0 < i < maxsize + 1.
// If justcount, however, then completelist is not updated
// Note: patterns in patternset required to be in S_{>1}
void countpatterns(string patternlist, int maxpermsize, vector < vector <int> > & tally, vector < vector < int > > &completelist, bool verbose, bool justcount);

// used for table building software
double run_interior_experiment2(string patternlist, int maxpermsize);

#endif 
