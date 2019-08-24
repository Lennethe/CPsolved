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

  ll n;
  cin>>n;
  map<ll,P> mp;

  FOR(i,0,n){
    FOR(j,0,n){
      ll in;
      cin>>in;
      mp[in]=P(i,j);
    }
  }
  vector<ll> knight(n*n-1,1e8);
  vector<ll> bishop(n*n-1,1e8);
  vector<ll> rook(n*n-1,2);
  FOR(i,0,n*n-1){
    ll x1,y1,x2,y2;
    x1=mp[i+1].first;
    y1=mp[i+1].second;
    x2=mp[i+2].first;
    y2=mp[i+2].second;
    if(abs(x1-x2)+abs(y1-y2)==3)knight[i]=1;
    if(x1+y1==x2+y2)bishop[i]=1;
    else if((x1+y1)%2==(x1+y2)%2) bishop[i]=2;
    if(x1==x2||y1==y2)rook[i]=1;
  }
  /*
  FOR(i,0,n*n-1){
    if(knight(i+1)==1){
      knight(i+1)+=knight(i);
      knight(i)=0;
    }
    if(bishop(i+1)==1){
      bishop(i+1)+=bishop(i);
      bishop(i)=0;
    }

  }
  sortAlr(knight);
  sortAlr(bishop);
  */

    ll k=0,b=0,r=0;
    ll kf=0,bf=0,rf=0;
    ll res=0;
    ll resf=0;
  FOR(i,0,n*n-1){
    k=res+knight[i]+kf;
    b=res+bishop[i]+bf;
    r=res+rook[i]+rf;
    res=min(k,b);
    res=min(res,r);
    ll flag=0;
    if(res==k){
      flag+=kf;
      kf=0;
    }
    else kf=1;
    if(res==b){
      flag+=bf;
      bf=0;
    }
    else bf=1;
    if(res==r){
      flag+=rf;
      rf=0;
    }
    else rf=1;
    flag=min(flag,(ll)1);
    resf+=flag;

  }
  cout<<res<<" "<<resf<<endl;


}
