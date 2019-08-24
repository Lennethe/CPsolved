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
  int N;
  vector<int> even={2,10,3,9,4,8,6,12};
  vector<int> odd={6,2,10,3,9,4,8,12};
  cin>>N;
  if(N==3){
    cout<<2<<" "<<5<<" "<<63<<endl;
  }
  else if(N%2==1){
    FOR(i,0,N){
      cout<<odd[i%8]+12*(i/8)<<" ";
    }
    cout<<endl;
  }
  else {
    FOR(i,0,N){
      cout<<even[i%8]+12*(i/8)<<" ";
    }
    cout<<endl;
  }

}
