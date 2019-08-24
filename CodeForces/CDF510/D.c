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
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,t;
  cin>>n>>t;
  vector<P> v(n+1,P(0,0));
  ll in;
  FOR(i,1,n+1){
    cin>>in;
    v[i]=P(in+v[i-1].first,i);
  }

  ll res=0;
  FOR(i,0,n+1){
    FOR(j,i+1,n+1){
      if(v[j].first-v[i].first<t)res++;
    }
  }
  cout<<res<<endl;


  /*
  sortAl(v);
  ll i=0,j=1;
  ll big,sma;
  ll res=0;
  while(i!=n&&j!=n){
    if(v[i].second<v[j].second){
      big=v[j].first;
      sma=v[i].first;
    }
    else{
      big=v[i].first;
      sma=v[j].first;
    }

    if(big-sma<t && j!=n){
      j++;
      res+=j-i;
    }
    else{
      i++;
    }
  }
  cout<<res<<endl;
  */
}
