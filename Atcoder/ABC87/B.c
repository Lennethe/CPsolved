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
  ll A,B,C,X;
  cin>>A>>B>>C>>X;
  ll res=0;
  FOR(i,0,A+1){
    FOR(j,0,B+1){
      FOR(k,0,C+1){
        if(i*500+j*100+k*50==X) res++;
      }
    }
  }
  cout<<res<<endl;
}
