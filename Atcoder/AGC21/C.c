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
  ll N,M,A,B;
  cin>>N>>M>>A>>B;

  ll area = N*M;
  ll tile = A*2+B*2;

  vector<vector<char>> v = vector<vector<char>>(N,vector<char>(M,'a'))
  if(N%2==0 && M%2==0){
    if(area>=tile && A%2==0 && B%2==0){
      A = A/2;
      B = B/2;
      FOR(i,0,N/2-1){
        FOR(j,0,M/2-1){

          if(A>0){
            v[2*i][2*j] = '<';
            v[2*i+1][2*j] = '<';
            v[2*i][2*j+1] = '>';
            v[2*i+1][2*j+1] = '>';
            A--;
          }
          else{
            v[2*i][2*j] = '^';
            v[2*i+1][2*j] = '<';
            v[2*i][2*j+1] = '>';
            v[2*i+1][2*j+1] = '>';
          }
        }
      }
    }
    else cout<<"NO"<<endl;
  }
  else if(N%2==1 && M%2==0){
    if(area==tile && A%2 ==M/2 && A>=M/2 && B%2==0){

    }
    else cout<<"NO"<<endl;
  }
  else if(N%2==0 && M%2==1){
    if(area==tile && B%2 ==M/2 && B>=M/2 && A%2==0){

    }
  }
  else if(N%2==1 && M%2==1){
    cout<<"NO"<<endl;
  }
}
