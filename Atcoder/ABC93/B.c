#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if((b-a)/2+1>c){
    FOR(i,a,a+c){
      cout<<i<<endl;
    }
    FOR(i,b-c+1,b+1){
      cout<<i<<endl;
    }
  }
  else{
    FOR(i,a,b+1){
      cout<<i<<endl;
    }
  }
}
