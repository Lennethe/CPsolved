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
  ll N=1e4+1;
  vector<ll> v(N);
  ll inst;
  FOR(i,0,N){
    inst=i;
    FOR(j,0,5){
      v[i]+=inst%10;
      inst/=10;
    }
  }

  ll X,A,B;
  cin>>X>>A>>B;
  ll res=0;
  FOR(i,1,X+1){
    if(A<=v[i]&&v[i]<=B) res+=i;
  }
  cout<<res<<endl;
}
