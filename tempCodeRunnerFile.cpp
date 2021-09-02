// `Dominoes' :
// Define reach[i] = x[i] + l[i].
// Let domino i `reach' j only if x[i] < x[j] <= reach[i]
// --> answer[domino] >= reach[i]
// --> If we have solved the problem for some suffix of dominoes, we can
//     solve for one more domino to the left, by looking at all the dominoes
//     the leftmost one reaches, and for each of them, taking the maximum of their answer.

// This gives us the recurrence :
//      dp[i] =    maximum   { dp[j] }, and reach[i] if i reaches no domino j > i.
//      	     (i reaches j)

// This is enough for an O(n^2) dynamic programming solution, but it is not fast enough.

// dp[i] requires a subarray maximum query starting at i+1, and ending at a
// position j(i) which is the largest position satisfying x[j] <= reach[i].
// For any i, j(i) can be found by a binary search in O(log(n)) time.
// The subarray maximum can be found using a `sparse table' like technique.

// For each index i, and all k <= ceil(log(n)), define r[k][i] as the maximum over all dp[i:i-1+2^k].
// To compute dp[i], we just need to find j(i), and find the largest k such that 2^k <= j(i)-i.
// Then set dp[i] = max( r[k][i+1], r[k][j(i)+1-2^k] ).
// As a base case, set dp[last] = reach[last].
// Once we have dp[i], we can update all r[k][i] by using the following recurrence :
//      r[0][i] =	       dp[i]
//      r[k][i] = {       max( r[k-1][i], r[k-1][i+2^(k-1)] ) , i+2^(k-1) is a valid index
//      	       {       r[k-1][i]			   , otherwise

// Hence for each i we can compute dp[i] in O(log(n)) time, taking overall O(nlog(n)) time.
// One can use segment trees as a black box for this task as well.
//  *insert link to segment tree tutorial here*
// It must support point updates of values and queries for maximum over a range.

// Solution :
// --------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 100000, L = 20;

// in r[k][i], we store the maximum value over dp[i : i-1+2^k], and use it to calculate dp[i-1].

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n;
  cin >> n;
  cout<<"njkk";
    long long x[N],l[N],dp[N],r[L][N];
  for(int i=0;i<n;i++) cin >> x[i] >> l[i];

  for(int i=n-1;i>=0;i--) {
    long long reach = dp[i] = x[i] + l[i];
    int lo = i, hi = n-1;
    while( lo < hi ) {
      int mid = (lo+hi+1)/2;
      if( x[mid] <= reach ) lo = mid;
      else hi = mid-1;
    }
    int lx = i+1, rx = lo;
    if(lx <= rx) {
      int lvl = 0, len = 1; for(;len+len <= rx-lx+1;len<<=1,lvl++);
      dp[i] = max( dp[i] , max( r[lvl][lx], r[lvl][rx+1-len] ) );
    }
    r[0][i] = dp[i];
    for(int lvl=1,len=1;lvl<L;lvl++,len<<=1)
      r[lvl][i] = max( r[lvl-1][i] , (i+len < n ? r[lvl-1][i+len] : 0ll) ) ;
  }
  for(int i=0;i<n;i++) cout << dp[i] << '\n';

  return 0;
}
