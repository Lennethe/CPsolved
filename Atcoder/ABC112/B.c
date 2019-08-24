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

  ll N,T;
  cin>>N>>T;

  vector<P> v(N);
  FOR(i,0,N){
    ll a,b;
    cin>>a>>b;
    v[i]=P(a,b);
  }

  ll res=1e10;

  FOR(i,0,N){
    if(v[i].second<=T){
      res=min(res,v[i].first);
    }
  }
  if(res==1e10) cout<<"TLE"<<endl;
  else{
    cout<<res<<endl;
  }
}
