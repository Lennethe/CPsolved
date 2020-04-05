//O(√N)
//1からnまでの約数
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
