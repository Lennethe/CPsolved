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
  int t;
  cin>>t;
  string s;

  string res="YES";
  vector<ll> v(t);
  vector<string> k(t);
  FOR(i,0,t){
    cin>>v[i]>>k[i];
  }
  FOR(i,0,t){
    res="YES";
    FOR(j,0,v[i]){
      if(!(abs(k[i][j]-k[i][v[i]-j-1])==2||k[i][j]-k[i][v[i]-j-1]==0)) res="NO";
    }
    cout<<res<<endl;
  }
}
