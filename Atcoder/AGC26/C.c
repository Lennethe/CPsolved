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
  int N;
  cin>>N;
  string S;
  vector<int> a(N),b(N);
  cin>>S;
  ll res=0;

  FOR(i,0,N){
    a[i]=S[i];
    b[i]=S[2*N-i-1];
  }
  vector<int> key(N,0);

  vector<int> a1,a2,b1,key1;
  ll v;
  int x=0;
  FOR(i,0,pow(2,N)){
    cout<<"i="<<i<<endl;
    a1=a;
    b1=b;
    key1=key;
    v=i;
    FOR(j,0,N){
      cout<<"j="<<j<<endl;
      if(v%2==1){
        a1.erase(begin(a1)+j);
        a2.push_back(a[j]);
      }
      v=v/2;
    }
    //cout<<"here3"<<endl;
    cout<<"as"<<endl;
    FOR(j,0,N){
      if(x>(int)a1.size())break;
      if(b1[j]==a1[x]){
        x++;
        a1.erase(begin(b1)+j);
      }
    }
    cout<<"here6"<<endl;

    if(a2==b1) res++;

  }

  cout<<res<<endl;

}
