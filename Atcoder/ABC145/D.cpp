//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

const int MOD = 1e9 + 7;

// a^b O(log b)
template <typename T>
T mypow(T a, T b) {
  if (b == 0) return 1;
  T tmp = mypow(a, b / 2);
  if (b % 2)
    return (((tmp * tmp) % MOD) * a) % MOD;
  else
    return (tmp * tmp) % MOD;
}

// nCk O(n + klogMOD)
long long comb(int n, int k) {
  long long res = 1;
  k = std::min(n - k, k);
  for (int i = n - k + 1; i <= n; i++) res = (res * i) % MOD;
  for (int i = 1; i <= k; i++)
    res = (res *
           mypow(static_cast<long long>(i), static_cast<long long>(MOD - 2))) %
          MOD;
  return res;
}

// nHk = n+k-1 C k
long long H(int n, int k) { return comb(n + k - 1, k); }

// v[i][j] := iCj
std::vector<std::vector<long long>> comb2(int n) {
  std::vector<std::vector<long long>> v(n + 1,
                                        std::vector<long long>(n + 1, 0));
  for (int i = 0; i < (int)v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < (int)v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
      v[j][k] %= MOD;
    }
  }
  return v;
}

long long comb3(int n, int k) {
  static bool initiated = false;
  static std::vector<long long> fact(200010, 1), inv(200010, 1);
  if (!initiated) {
    initiated = true;
    for (int i = 2; i <= 200000; i++) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = mypow(fact[i], (long long)MOD - 2);
    }
  }
  if (k < 0 || n < k) {
    return 0;
  }
  long long ret = fact[n] * inv[k] % MOD;
  ret = ret * inv[n - k] % MOD;
  return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,y;
    cin>>x>>y;
    ll a = (x+y)/3;
    ll tx = x-a, ty = y-a;
    ll ans = comb(tx+ty, tx);
    if((x+y)%3!=0 || tx<0 || ty<0) cout<<0<<endl;
    else{
        cout<<ans<<endl;
    }

}