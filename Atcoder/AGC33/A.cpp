//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> v(h,vector<ll>(w,-1));
    deque<P> que;
    FOR(i,0,h){
      string s;
      cin>>s;
      FOR(j,0,w){
        if(s[j] == '#'){
          que.push_back(P(i,j));
          v[i][j] = 0;
        }
      }
    }

    while(!que.empty()){
      ll row = que.front().first;
      ll clm = que.front().second;
      que.pop_front();
      if(v[min(row+1,h-1)][clm] == -1){
        v[min(row+1,h-1)][clm] = v[row][clm] + 1;
        que.push_back(P(min(row+1,h-1), clm));
      }
      if(v[max(row-1,(ll)0)][clm] == -1){
        v[max(row-1,(ll)0)][clm] = v[row][clm] + 1;
        que.push_back(P(max(row-1,(ll)0), clm));
      }
      if(v[row][min(clm+1,w-1)] == -1){
        v[row][min(clm+1,w-1)] = v[row][clm] + 1;
        que.push_back(P(row, clm+1));
      }
      if(v[row][max(clm-1,(ll)0)] == -1){
        v[row][max(clm-1,(ll)0)] = v[row][clm] + 1;
        que.push_back(P(row, clm-1));
      }
    }

    ll ans = 0;
    FOR(i,0,h){
      FOR(j,0,w){
        ans = max(ans,v[i][j]);
      }
    }
    cout<<ans<<endl;
}
