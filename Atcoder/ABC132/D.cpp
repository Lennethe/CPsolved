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

ll ext_gcd(ll a, ll b, ll&x, ll&y){
  if(b==0){
    x=1;y=0;return a;
  }
  ll q=a/b;
  ll g=ext_gcd(b,a-q*b,x,y);
  ll z=x-q*y;
  x=y;y=z;
  return g;
}

// aは割る言、mがmod
ll invmod(ll a, ll m){
  ll x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}

ll mod_comb(ll n, ll r, ll mod){
  ll ans = 1;
  FOR(i,0,r){
    ans = ans*(n-i)%mod;
    ans = ans*invmod(i+1,mod)%mod;
  }
  return ans%mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    n -= k;
    ll MOD = 1e9+7;
    FOR(i,1,k+1){
      ll x = mod_comb(n+1,i,MOD);
      ll y = mod_comb(k-1,i-1,MOD);
//      cout<<x<<" "<<y<<endl;
      cout<<x*y%MOD<<endl;
    }
}
