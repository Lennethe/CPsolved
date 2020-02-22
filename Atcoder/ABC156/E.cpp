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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll MOD = 1e9+7;
    vector<ll> fac(1e5+2);
    fac[0] = 1;
    fac[1] = 1;
    FOR(i,2,1e5+2){
        fac[i] = fac[i-1]*i%MOD;
    }
    k = min(n-1,k);
    k++;

    int a = n-1;
    int b = k;
    int c = n-k;
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<endl;

    cout<<fac[a+b]*invmod(fac[a],MOD)%MOD * invmod(fac[b], MOD)%MOD<<endl;
    cout<<fac[a + c]%MOD * invmod(fac[a], MOD)%MOD * invmod(fac[c], MOD)%MOD<<endl;
    ll ans = fac[a+b]*invmod(fac[a],MOD)%MOD * invmod(fac[b], MOD)%MOD * fac[a + c]%MOD * invmod(fac[a], MOD)%MOD * invmod(fac[c], MOD)%MOD;
    cout<<ans<<endl;
}