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
  ll x;
  cin>>x;
  vector<P> v(x);

  ll in;
  cin>>in;
  v[0]=P(in,0);
  FOR(i,1,x){
    cin>>in;
    if(i==1&&in>0){
      v[i]=P(in,1);
    }
    else if(v[i-1].first<0&&in>0){
      v[i]=P(in,1);
    }
    else v[i]=P(in,0);
  }
  ll res=0;
  FOR(i,0,x){
    if(v[i].second==1) res-=v[i].first;
    else res+=abs(v[i].first);
  //  cout<<res<<endl;
  }
  cout<<res<<endl;


}
