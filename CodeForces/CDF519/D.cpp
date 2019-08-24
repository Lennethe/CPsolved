#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,m;
  cin>>n>>m;
  VEC2(v,m,n);
  FOR(i,0,m){
    FOR(j,0,n){
      cin>>v[i][j];
    }
  }
  map<P,ll> mp;
  FOR(i,0,m){
    FOR(j,1,n){
      mp[P(v[i][j-1],v[i][j])]++;
    }
  }
  ll res=n;
  FORm(i,mp){
    if(i->second==m)res++;
  }
  cout<<res<<endl;

}
