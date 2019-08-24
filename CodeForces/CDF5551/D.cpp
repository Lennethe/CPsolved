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
    ll n;
    cin>>n;
    map<ll,ll> mp;
    vector<ll> v(n+1);

    FOR(i,0,n){
      ll x;
      cin>>x;
      mp[x] = 1;
      v[x] = 1;
    }
    vector<ll> stack(n);
    deque<ll> que;
    FOR(i,0,n){
      ll in;
      cin>>in;
      stack[i] = in;
      que.push_back(in);
    }

    //そのまま適当に入れれる場合
    ll siz = n-que.back();
    FOR(i,0,siz){
      ll p = 0;
      FORm(j,mp){
        p = j->first;
        if(p == 0) continue;
        que.push_back(p);
        mp.erase(p);
        break;
      }
      ll h = que.front();
      mp[h] = 1;
      que.pop_front();
    }
    ll f = 0;
    FOR(i,0,n){
      if(que.front() != i+1) f = 1;
      que.pop_front();
    }
    if(f == 0)cout<<siz<<endl;
    else{
      ll tmp = n+1;
      ll po = 0;
      FORr(i,0,n-1){
        tmp--;
        if(stack[i] != 0)tmp = min(tmp,stack[i]);
        if(tmp == 0){
          po = i+1;
          break;
        }
      }
      cout<<po+n+1<<endl;
    }

}
