#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N,M;
  cin>>N>>M;
  vector<P> v(M);
  ll a,b;
  FOR(i,0,M){
    cin>>a>>b;
    v[i]=make_pair(a,b);
  }
  sort(v.begin(),v.end());

  int posi=0;
  int res=1;
  FOR(i,1,M){
    if(v[posi].second<=v[i].first){
      posi=i;
      res++;
      //cout<<i<<endl;
    }
    if(v[posi].second>=v[i].second){
      posi=i;
    }
  }
  cout<<res<<endl;
}
