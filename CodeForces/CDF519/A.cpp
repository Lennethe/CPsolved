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

  ll N;
  cin>>N;
  vector<ll> v(N);
  cinv(v,0,N);

  sortAl(v);
  ll sum=0;
  FOR(i,0,N){
    sum+=v[i];
  }
  ll res=0;
  FOR(i,0,202){
    ll inst=0;
    FOR(j,0,N){
      ll x=i;
      x=max((ll)0,x-v[j]);
      inst+=x;
    }
    if(inst>sum){
      res=i;
      break;
    }
  }
  FOR(i,0,N){
    res=max(res,v[i]);
  }
  cout<<res<<endl;
}
