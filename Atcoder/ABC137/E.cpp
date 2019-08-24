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
    ll n,m,p;
    cin>>n>>m>>p;
    vector<vector<P>> g(n+1);
    vector<vector<P>> gg(n+1);
    FOR(i,0,m){
      ll a,b,c;
      cin>>a>>b>>c;
      g[a].emplace_back(P(b, c-p));
      gg[b].emplace_back(P(a,c-p));
    }
    vector<ll> used_s(n+1);
    vector<ll> used_g(n+1);

    queue<ll> q;
    q.push(1);
    used_s[1] = 1;
    while(!q.empty()){
      ll po = q.front();
      q.pop();
      FOR(i,0,g[po].size()){
        ll to = g[po][i].first;
        if(used_s[to] == 0){
          used_s[to] = 1;
          q.push(to);
        }
      }
    }

    q.push(n);
    used_g[n] = 1;
    while(!q.empty()){
      ll po = q.front();
      q.pop();
      FOR(i,0,gg[po].size()){
        ll to = gg[po][i].first;
        if(used_g[to] == 0){
          used_g[to] = 1;
          q.push(to);
        }
      }
    }
    FOR(i,0,n+1){
      if(used_g[i]*used_s[i] == 0){
        g[i] = vector<P>(0);
      }
    }



    queue<ll> que;
    vector<ll> score(n+1,-1e7);
    que.push(1);
    score[1] = 0;
    ll time = 0;
    while(!que.empty()){
      time++;
      if(time > 1e7)break;
      ll po=que.front();
      que.pop();

      FOR(i,0,g[po].size()){
        time++;
        ll to = g[po][i].first;
        ll cost = g[po][i].second;
        if(score[to]<score[po] + cost){
          score[to] = score[po]+cost;
          que.push(to);
        }
      }
    }
    if(time>=1e7)cout<<-1<<endl;
    else cout<<max(score[n],(ll)0)<<endl;

}
