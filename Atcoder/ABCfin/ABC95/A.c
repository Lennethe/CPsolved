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
  string s;
  cin>>s;
  int res=700;
  if(s[0]=='o'){
    res+=100;
  }
  if(s[1]=='o'){
    res+=100;
  }
  if(s[2]=='o'){
    res+=100;
  }
  cout<<res<<endl;
}
