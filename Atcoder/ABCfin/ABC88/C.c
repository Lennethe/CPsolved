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
  ll a,b,c,d,e,f,g,h,i;
  cin>>a>>b>>c
     >>d>>e>>f
    >>g>>h>>i;
  if(c-b==f-e && f-e==i-h && b-a==e-d && e-d==h-g) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
