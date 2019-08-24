#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  string s;
  cin>>s;
  int flag=0;
  if(s[0]=='A'){
    FOR(i,2,(int)s.size()-1){
      if(s[i]=='C') flag++;
    }
  }
  FOR(i,0,(int)s.size()){
    if(s[i]=='A'||s[i]=='C'||('a'<=s[i]&&s[i]<='z')){
    }
    else flag=2;
  }

  if(flag==1) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}
