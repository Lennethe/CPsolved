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
  string a,b;
  string res = "No";
  char q;
  cin>>a>>b;
  FOR(i,0,a.size()+1){
    q=a[0];
    a.erase(a.begin());
    a.push_back(q);
    if(a==b) res="Yes";
  }
  cout<<res<<endl;
}
