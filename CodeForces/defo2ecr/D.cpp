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
  ll n,T;
  cin>>n>>T;
  vector<ll> v(n);
  cinv(v,0,n);
  ll sum=0,mi=1e6;
  FOR(i,0,n){
    sum+=v[i];
    mi=min(mi,v[i]);
  }
  ll res=0;
  ll dis=0;

  while(mi<=T){
    if(sum>T){
      FOR(i,0,v.size()){
        //cout<<i<<endl;
        if(T>=v[i]){
          T-=v[i];
          res++;
        }
        else{
          sum-=v[i];
          v[i]=0;
          dis++;
          i--;
        }
      }

      res-=dis;
    }
    else if(sum<=T){
      res+=T/sum*(n-dis);
      T=T%sum;
    }
    //cout<<T<<endl;
  }
  cout<<res<<endl;

}
