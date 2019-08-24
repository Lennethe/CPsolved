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
  vector<ll> v(3);
  cin>>v[0]>>v[1]>>v[2];
  sort(v.begin(),v.end());
  ll sum=0;
  sum=v[2]-v[1]+v[2]-v[0];
  if(sum%2==1) sum+=3;

  cout<<sum/2<<endl;
}
