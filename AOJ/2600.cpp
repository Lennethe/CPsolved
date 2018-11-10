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

  ll N,W,H;
  cin>>N>>W>>H;
  vector<ll> vx(W+1),vy(H+1);
  FOR(i,0,N){
    ll a,b,c;
    cin>>a>>b>>c;
    ll l=max((ll)0,a-c),r=min(W,a+c);
    vx[l]++,vx[r]--;
    l=max((ll)0,b-c),r=min(H,b+c);
    vy[l]++,vy[r]--;
  }

  ll fx=0,fy=0;
  FOR(i,1,W){
    vx[i]+=vx[i-1];
  }
  FOR(i,1,H){
    vy[i]+=vy[i-1];
  }

  FOR(i,0,W){
    if(vx[i]==0)fx=1;
  }
  FOR(i,0,H){
    if(vy[i]==0)fy=1;
  }



  if(fx*fy==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
