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

ll MOD = 1e9+7;

template <typename T>
T mypow(T a, T b) {
  if (b == 0) return 1;
  T tmp = mypow(a, b / 2);
  if (b % 2)
    return (((tmp * tmp) % MOD) * a) % MOD;
  else
    return (tmp * tmp) % MOD;
}


template <typename T>
T ext_gcd(T a, T b, T&x, T&y){
  if(b==0){
    x=1;y=0;return a;
  }
  T q=a/b;
  T g=ext_gcd(b,a-q*b,x,y);
  T z=x-q*y;
  x=y;y=z;
  return g;
}

// aは割る言、mがmod
template <typename T>
T invmod(T a, T m){
  T x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}

ll solve(ll n, ll a){
    ll up = 1;
    ll down = 1;
    FOR(i,1,a+1){
        down = down*i%MOD;
        up = up*(n-i+1)%MOD;
    }
    return up * invmod(down, MOD)%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans = mypow((ll)2,n) - 1;
    
    ans -= solve(n,a) + solve(n,b);
    ans = (ans+MOD+MOD)%MOD;
    cout<<ans<<endl;
}