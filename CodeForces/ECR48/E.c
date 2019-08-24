#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ld,ld>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll sy,a,b;
  cin>>sy>>a>>b;
  int n;
  cin>>n;

  vector<ll> l(n),r(n);
  FOR(i,0,n){
    cin>>l[i]>>r[i];
}
  ld q=0;
  cin>>q;
  vector<P> point(q);
  ld x,y;
  FOR(i,0,q){
    cin>>x>>y;
    point[i] = make_pair(x,y);
  }

  ld resl=0,resr=0,res=0;
  FOR(i,0,q){
    x=point[i].first;
    y=point[i].second;
    //cout<<x<<y<<endl;
    res = 0;
    FOR(j,0,n){
      if(x==l[j])resl = x;
      else resl=((x-l[j])/y)*(sy-(y-(x*y/(x-l[j]))));
      if(x==r[j])resr = x;
      else resr=((x-r[j])/y)*(sy-(y-(x*y/(x-r[j]))));
      if(resl<=a) resl=a;
      if(resr<=a) resr=a;
      if(resl>=b) resl=b;
      if(resr>=b) resr=b;
      res=resr-resl+res;
      //cout<<"i="<<i<<" j="<<j<<" left="<<resl<<" right="<<resr<<endl;
    }
    cout<<res<<endl;
  }
}
