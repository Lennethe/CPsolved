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
  int N;
  cin>>N;

  int t,a,b;
  string  res ="Yes";
  cin>>t>>a>>b;
  int pt,pa,pb;
  if(t<a+b) res="No";
  pt=t;
  pa=a;
  pb=b;
  FOR(i,1,N){
    cin>>t>>a>>b;
    if((t-pt-abs(a-pa)+abs(b-pb))<0) res="No";
    if((t-pt-abs(a-pa)+abs(b-pb))%2==1) res="No";
    pt=t;
    pa=a;
    pb=b;
  }
  cout<<res<<endl;
}
