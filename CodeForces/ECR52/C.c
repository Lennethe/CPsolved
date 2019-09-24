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

  ll n,k;
  cin>>n>>k;
  vector<ll> v(n);
  cinv(v,0,n);
  sortAlr(v);
  ll res=0;
  ll j=0;
  ll cost=0;
  FORr(i,v[0],v[n-1]-1){
    while(v[j+1]==i){
      j++;
    }
    if(j==n-1)break;
    if(cost+(j+1)>k){
      cost=j+1;
      res++;
    }
    else{
      cost+=j+1;
    }
    //cout<<"i="<<i<<" "<<cost<<endl;
  }
  if(cost!=0)res++;

  cout<<res<<endl;
}