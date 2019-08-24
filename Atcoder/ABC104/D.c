#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=m-1; i>=(ll)n; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  string s;
  cin>>s;
  vector<vector<ll>> key = vector<vector<ll>>((ll)s.size(),vector<ll>(4,0));
  int SIZE=s.size();
  //A? C?
  FOR(i,1,(ll)s.size()){
    if(s[i-1]=='A')  key[i][0]=key[i-1][0]+1;
    else key[i][0]=key[i-1][0];
    if(s[i-1]=='?')  key[i][1]=key[i-1][1]+1;
    else key[i][1]=key[i-1][1];
  }
  FOR(i,1,(ll)s.size()){
    if(s[SIZE-i]=='C')  key[SIZE-i-1][2]=key[SIZE-i][2]+1;
    else key[SIZE-i-1][2]=key[SIZE-i][2];
    if(s[SIZE-i]=='?')  key[SIZE-i-1][3]=key[SIZE-i][3]+1;
    else key[SIZE-i-1][3]=key[SIZE-i][3];
  }

  ll z=1000000007;
  vector<ll> three(SIZE+1,1);
  three[0]=0;
  FOR(i,2,SIZE+1){
    three[i]=(three[i-1]*3)%z;
  }
  ll res=0;

  ll p,q,x,y;


  FOR(i,0,SIZE){

    if(s[i]=='B'||s[i]=='?'){
      p=key[i][0];
      q=key[i][1];
      x=key[i][2];
      y=key[i][3];

  //    cout<<p*three[q]<<" "<<q*three[q-1]<<endl;
      res=res+(p*three[q+1]%z+q*three[q]%z)*(x*three[y+1]%z+y*three[y]%z)%z;
    }
  }
cout<<res%z<<endl;
}
