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
  ll N,K;
  cin>>N>>K;
  ll res=0;
  FOR(i,K+1,N+1){
    res+=N/i*(i-K);
    //cout<<res<<" ";
    if(K==0) res+=N%i-K;
    else if(N%i>=K)res+=N%i-K+1;

    //cout<<res<<endl;
  }
  cout<<res<<endl;
}
