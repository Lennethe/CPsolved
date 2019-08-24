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
  int A,B;
  cin>>A>>B;
  string s;
  int res=0;
  FOR(i,A,B+1){
    s=std::to_string(i);

    if(s[0]==s[4]&&s[1]==s[3]){
      res++;
    }

  }
  cout<<res<<endl;
  //cout<<s<<endl;
}
