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
  ll a,b;
  string s;
  cin>>a>>b>>s;
  string res ="Yes";
  FOR(i,0,a+b+1){
    if(i==a && s[a]!='-') res="No";

    if(i!=a){
      if(!(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||
         s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')){
           res="No";
         }
    }
  }
  cout<<res<<endl;
}
