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
  ll n,k;
  cin>>n>>k;
  ll x=1+2*k;
  ll size=(n+x-1)/x;
  cout<<size<<endl;

  vector<ll> v(size,1);
  FOR(i,1,size){
    v[i]=v[i-1]+x;
  }
  ll ad=max(((n-1)%x)-k,(ll)0);
  FOR(i,0,size){
    v[i]+=ad;
  }

  FOR(i,0,size){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
