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
  ll n;
  cin>>n;
  vector<P> v(2*n);
  ll in;
  FOR(i,0,2*n){
    cin>>in;
    v[i]=P(in,i/n+1);
  }
  sortAlr(v);
  ll A=0,B=0;
  FOR(i,0,2*n){
    if(i%2==0){
      if(v[i].second==1)A+=v[i].first;
    }
    else{
      if(v[i].second==2)B+=v[i].first;
    }
  }
  cout<<A-B<<endl;
}
