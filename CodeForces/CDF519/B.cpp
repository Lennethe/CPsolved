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

  ll N;
  cin>>N;
  vector<ll> v(N);
  cinv(v,0,N);
  /*
  vector<P> p(N);
  p[0]=P(v[0],0);
  FOR(i,1,N){
    p[i]=P(v[i]-v[i-1],i);
  }
  */
  FORr(i,N-1,0){
    v[i]=v[i]-v[i-1];
  }
  FOR(i,0,N){
    cout<<v[i]<<endl;
  }


  ll pos=0;
  FOR(i,1,N){
    if(v[pos]==v[i]){
      pos++;
    }
    else pos=0;
  }
  pos=N-pos;
  ll x=pos;
  vector<ll> res;
  while(pos<N){
    res.push_back(pos);
    pos+=x;
  }
  res.push_back(N);

  cout<<res.size()<<endl;
  FOR(i,0,res.size()){
    cout<<res[i]<<" ";
  }
  cout<<endl;
}
