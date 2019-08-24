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
  ll N,X;
  cin>>N>>X;

  vector<P> v(N);
  ll in;
  FOR(i,0,N){
    cin>>in;
    v[i]=P(in,0);
  }
  FOR(i,0,N){
    ll k=X/(2*v[i].first);

    v[i].second=k+2;
  }
  ll res=0;
  ll a=0;
  FOR(i,0,N){
    a=0;
    res+=v[N-1-i].first+X;
    a++;
    while(a<v[N-2-i].second){
      res+=(v[N-1-i].first-v[N-2-i].first)*(a+1)*(a+1)+X;
      a++;
      i++;
      if(i==N-1)break;
    }
    res+=v[N-1-i].first*(a+1)*(a+1)+X;

  }
  res--;
  cout<<res<<endl;
  /*
  FOR(i,0,N){
    cout<<v[i].first<<" "<<v[i].second<<endl;
  }
  cout<<endl;
  */
}
