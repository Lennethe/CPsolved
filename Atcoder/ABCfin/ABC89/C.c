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
  ll N;
  ll M=0,A=0,R=0,C=0,H=0;
  cin>>N;
  string s;
  FOR(i,0,N){
    cin>>s;
    if(s[0]=='M') M++;
    if(s[0]=='A') A++;
    if(s[0]=='R') R++;
    if(s[0]=='C') C++;
    if(s[0]=='H') H++;
  }
  cout<<M*A*(R+C+H)+ A*R*(C+H) + A*C*H+ R*C*H + M*R*(C+H) + M*C*H<<endl;
}
