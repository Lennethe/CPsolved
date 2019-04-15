#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,t,l,b;
  cin>>n>>t>>l>>b;

  while(n!=0){
    vector<ld> board1(n+1);
    vector<ld> board2(n+1);
    vector<ld> board_keep(n+1);
    vector<ld> lose(l);
    vector<ld> back(b);
    FOR(i,0,l){
      cin>>lose[i];
    }
    FOR(i,0,b){
      cin>>back[i];
    }
    board1[0] = 1;

    FOR(a,0,t){

      FOR(i,0,n){
        FOR(j,1,7){
          ll pos = i+j;
          if(pos>=n+1){
            pos = n+1 - (pos-n) - 1;
          }
          board2[pos] += board1[i]/6.0;
        }
      }
      board2[n] += board1[n];

      FOR(i,0,n+1){
        board1[i] = board_keep[i];
        board_keep[i] = 0;
      }
      FOR(i,0,l){
        board_keep[lose[i]] = board2[lose[i]];
        board2[lose[i]] = 0;
      }
      FOR(i,0,b){
        board2[0] += board2[back[i]];
        board2[back[i]] = 0;
      }
      FOR(i,0,n+1){
        board1[i] += board2[i];
        board2[i] = 0;
      }
      //cout<<"t = "<<a<<endl;
      //FOR(i,0,n+1){
      //  cout<<board1[i]<<" ";
      //}
      //cout<<endl;
      //FOR(i,0,n+1){
      //  cout<<board_keep[i]<<" ";
      //}
      //cout<<endl;

    }

    ld sum=0;
    FOR(i,0,n+1){
      sum += board1[i]+board_keep[i];
    //  cout<<board1[i]+board_keep[i]<<" ";
    }
    //cout<<endl;
    //cout<<sum<<" "<<board1[n]<<endl;
    ld res = board1[n]/sum;
    cout(10)<<res<<endl;
    cin>>n>>t>>l>>b;
  }

}
