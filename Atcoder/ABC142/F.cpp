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
    vector<vector<ll>> g(n+1);
    vector<vector<ll>> rev(n+1);
    FOR(i,0,m){
      ll in1,in2;
      cin>>in1>>in2;
      g[in1].push_back(in2);
      rev[in2].push_back(in1);
    }

    map<ll,ll> mp;
    FOR(i,1,n+1) mp[i] = 1;

    vector<ll> v(n+1);
    ll p = 0;
    ll mp_siz = mp.size();
    while(mp.size()!=0){
      ll x = 0;
      mp_siz = mp.size();
      FORm(i,mp){
        x = i->first;
        mp.erase(x);
        v[x] = mp_siz;
        break;
      }
      deque<ll> q;
      q.push_back(x);
      cout<<"hu"<<endl;
      while(!q.empty()){
        ll from = q.front();
        q.pop_front();
        FOR(i,0,g[from].size()){
          ll to = g[from][i];
          if(v[to] == 0){
            q.push_back(to);
            v[to] = mp_siz;
            mp.erase(to);
            cout<<to<<endl;
          }
          else if(v[to] == mp_siz){
            deque<ll> t;
            q = t;
            map<ll,ll> mpt;
            mp = mpt;
            p = to;
          }
        }
      }
    }
    cout<<"2"<<endl;
    map<ll,ll> ans;
    ans[to]++;
    ll f = 1;
    while(f == 1){
      f = 0;
      FOR(i,0,rev[p].size()){
        ll to = rev[p][i];
        if(v[to] == mp_siz){
          ans[to]++;
          p = to;
          if(ans.front() != ans.back()) f = 1;
          cout<<ans.front()<<" "<<ans.back()<<endl;
          break;
        }
      }
    }

    if(ans.front() != ans.back()) cout<<-1<<endl;
    else{
      ans.pop_front();
      while(!ans.empty()){
        cout<<ans.front();
        ans.pop_front();
        if(!ans.empty()){
          cout<<" ";
        }
        else cout<<endl;
      }
    }

    FOR(i,0,v.size()){
      cout<<"i = "<<i<<" "<<v[i]<<endl;
    }



}
