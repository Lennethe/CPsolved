#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll n,Q;
  cin>>n>>Q;
  //vector<vector<ll>> v = vector<vector<ll>>(n,vector<ll>(n,0));
  //vector<P> q(Q);
  ll a,b;
  ll res=0;

  FOR(i,0,Q){
    cin>>a>>b;
    res=0;
    if((a+b)%2==1) res=res+(n*n+1)/2;
    res += (b+1)/2 + (a-1)*n/2  ;
    if(n%2==1&&a%2==0&&b%2==0) res++;

    cout<<res<<endl;
  }
}
