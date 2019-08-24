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
  ll n,m;
  cin>>n>>m;
  vector<ll> v(n);
  cinv(v,0,n);
  ll sum=m;
  ll max=0;

  FOR(i,0,n){
    max=std::max(v[i],max);
    sum+=v[i];
  }

  if(sum%n!=0){
    sum/=n;
    sum++;
  }
  else sum/=n;

  FOR(i,0,n){
    if(sum<v[i]){
      sum=v[i];
    }
  }
  cout<<sum<<" "<<max+m<<endl;
}
