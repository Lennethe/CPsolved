#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll H,W,D;
  cin>>H>>W>>D;
  vector<P> v(H*W+1);

  ll in;
  FOR(i,0,H){
    FOR(j,0,W){
      cin>>in;
      v[in]=P(i,j);
    }
  }

  vector<ll> key(H*W+1,0);
  ll x;
  FOR(i,D,H*W+1){
    key[i]=abs(v[i].first-v[i-D].first)+abs(v[i].second-v[i-D].second);
  }
  FOR(i,0,D){
    x=0;
    while(i+x+D<H*W+1){
      key[i+x+D]+=key[i+x];
      x+=D;
    }
  }

  ll Q;
  cin>>Q;
  //FOR(i,0,H*W+1){
  //  cout<<key[i]<<" ";
  //}
  //cout<<endl;
  vector<ll> av(Q),bv(Q);
  FOR(i,0,Q){
    cin>>av[i]>>bv[i];
  }
  FOR(i,0,Q){
    cout<<key[bv[i]]-key[av[i]]<<endl;
  }
}
