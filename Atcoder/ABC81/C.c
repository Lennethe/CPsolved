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
  ll N,K;
  cin>>N>>K;
  vector<ll> v(N);
  vector<ll> key;
  cinv(v,0,N);
  sortAl(v);
  ll inst=-1;
  FOR(i,1,N){
    if(v[i]!=v[i-1]){
      key.push_back(i-1-inst);
      inst=i-1;
    }
  }
  key.push_back(N-1-inst);
  sortAlr(key);
  ll res=0;
  FOR(i,K,key.size()){
    res+=key[i];
  }
  cout<<res<<endl;
}
