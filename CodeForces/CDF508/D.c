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
  ll x;
  cin>>x;
  vector<ll> v(x);
  cinv(v,0,x);
  ll res=0;
  ll resa=0;

  FOR(i,1,x-1){
    res+=abs(v[i]);
  }
  res+=v[0]+abs(v[x-1]);
  resa+=v[x-1]+abs(v[0]);
  ll a=res;
  resa=res;
  if(x>=2){
    if(v[1]>0)res-=v[1]*2;
    if(v[x-2]>0)resa-=v[x-2]*2;
  }
  if(v[0]*v[x-1]<0)cout<<a<<endl;
  else cout<<max(res,resa)<<endl;
}
