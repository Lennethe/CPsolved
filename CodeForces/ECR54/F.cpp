#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

bool check(ll a, ll b, ll k){
  ll big = max(a,b);
  ll small = min(a,b);
  if(big-k > small*k) return false;
  return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> x(n);
    vector<ll> y(n);
    cinv(x,0,n);
    cinv(y,0,n);
    ll sumx=0;
    ll sumy=0;
    FOR(i,0,n){
      sumx+=x[i];
      sumy+=y[i];
    }

    bool f=true;
    FOR(i,0,n){
      if(f){
        f = check(x[i],y[i],k);
      }
    }
    if(f){
      f = check(sumx,sumy,k);
    }
    //cout<<f<<endl;
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //cout<<check(11,4,2)<<endl;
    //cout<<check(7,4,2)<<endl;
}
