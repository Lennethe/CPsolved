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
  ll in;
  cin>>in;

  int flag9=1;
  int res=0;
  while(in/10>0){
    if(in%10!=9)flag9=0;
    res += 9;
    in =in/10;
  }
  if(flag9==1){
    res += in;
  }
  else res += in - 1;

  cout<<res<<endl;
}
