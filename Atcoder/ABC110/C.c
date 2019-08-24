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
  string x,y;
  cin>>x>>y;
  vector<pair<char,ll>> vx(x.size());
  vector<pair<char,ll>> vy(y.size());

  FOR(i,0,x.size()){
    vx[i]=make_pair(x[i],i);
    vy[i]=make_pair(y[i],i);
  }

  vector<pair<char,ll>> vxs(x.size());
  vector<pair<char,ll>> vys(y.size());
  vxs=vx;
  vys=vy;
  sortAl(vxs);
  sortAl(vys);
  string res="Yes";
  FOR(i,1,x.size()){
    ll x1=vxs[i].second;
    ll x2=vxs[i-1].second;
    ll y1=vys[i].second;
    ll y2=vys[i-1].second;

    if(vxs[i].first==vxs[i-1].first&&
       vy[x1].first!=vy[x2].first)res="No";
    if(vys[i].first==vys[i-1].first&&
       vx[y1].first!=vx[y2].first)res="No";

  }
  cout<<res<<endl;


}
