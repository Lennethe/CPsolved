//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n+2,vector<ll>(m+2,0));
    FOR(i,0,n){
      FOR(j,0,m){
        cin>>v[i+1][j+1];
      }
    }

    vector<vector<ll>> res(n+2,vector<ll>(m+2,0));
    queue<P> ans;
    FOR(i,1,n+1){
      FOR(j,1,m+1){
        if(v[i][j] == 1){
          if(v[i-1][j]*v[i][j-1]*v[i-1][j-1] == 1)res[i][j] = 1;
          if(v[i-1][j]*v[i][j+1]*v[i-1][j+1] == 1)res[i][j] = 1;
          if(v[i+1][j]*v[i][j-1]*v[i+1][j-1] == 1)res[i][j] = 1;
          if(v[i+1][j]*v[i][j+1]*v[i+1][j+1] == 1){
            res[i][j] = 1;
            ans.push(P(i,j));
          }
        }
      }
    }

    ll flag = 1;
    FOR(i,1,n+1){
      if(flag == 0)break;
      FOR(j,1,m+1){
        if(flag == 0)break;
        if(v[i][j] != res[i][j]){
          cout<<-1<<endl;
          flag = 0;
        }
      }
    }

    if(flag == 1){
      cout<<ans.size()<<endl;
      while(!ans.empty()){
        cout<<ans.front().first<<" "<<ans.front().second;
        ans.pop();
        if(!ans.empty())cout<<endl;
      }
    }
}
