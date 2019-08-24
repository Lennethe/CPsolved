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
  vector<ll> v(n);
  cinv(v,0,n);

  ll sum=0;
  FOR(i,0,n){
    sum+=abs(v[i]);
  }
  ll mi,mina=1e9;

  ll a,b,c,d;
  a=abs(v[0]);
  b=abs(v[n-1]);
  if(n>=2){
    c=abs(v[1]);
    d=abs(v[n-2]);
    mina=std::min(c,d);
  }
  mi=std::min(a,b);
  mi=std::min(mi,mina);

  if(v[0]*v[n-1]<=0) cout<<sum<<endl;
  else if(n>=2){
    if(v[0]*v[1]<0 || v[n-1]*v[n-2]<0) cout<<sum<<endl;
    else{
      cout<<sum-mi*2<<endl;
    }
  }
}
