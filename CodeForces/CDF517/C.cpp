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

  ll a,b;
  cin>>a>>b;
  ll N = 100050;
  vector<ll> v0(N);
  FOR(i,1,N){
    v0[i]=i;
    v0[i]+=v0[i-1];
  }
  ll res=0;
  FOR(i,0,N){
    if(a+b<v0[i]){
      res=i-1;
      break;
    }
  }
  vector<ll> v(res);
  FOR(i,0,res){
    v[i]=1;
  }

  vector<ll> av;
  FORr(i,res-1,-1){
    if(a>i){
      a-=i+1;
      v[i]=0;
      av.push_back(i+1);
    }
  }
  cout<<av.size()<<endl;
  FOR(i,0,av.size()){
    cout<<av[i]<<" ";
  }
  cout<<endl;
  cout<<res-av.size()<<endl;
  FOR(i,0,res){
    if(v[i]==1){
      cout<<i+1<<" ";
    }
  }
  cout<<endl;
}
