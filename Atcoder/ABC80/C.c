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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<end
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N;
  cin>>N;
  //VEC2(v,N,1024);
  VEC2(F,N,10);
  VEC2(P,N,11);

  FOR(i,0,N) FOR(j,0,10) cin>>F[i][j];
  FOR(i,0,N) FOR(j,0,11) cin>>P[i][j];

  ll inst=0;
  ll res=-1e15;
  ll sum=0;
  FOR(i,1,1024){
    vector<ll> key(N,0);
    ll po=i;
    FOR(j,0,N){
      po=i;
      inst=0;
      FOR(k,0,10){
        if(po%2==1)inst+=F[j][k];
        po/=2;
      }
      key[j]=P[j][inst];
    }
    sum=0;
    FOR(j,0,N)sum+=key[j];
    res=max(res,sum);
  }

  cout<<res<<endl;
}
