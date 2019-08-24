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
    vector<vector<P>> v(n+1);

    FOR(i,0,n-1){
      ll in1,in2,c;
      cin>>in1>>in2>>c;
      v[in1].emplace_back(P(in2,c));
      v[in2].emplace_back(P(in1,c));
    }

    vector<ll> used(n+1,-1);
    deque<ll> que;
    que.push_back(1);
    used[1] = 0;
    while(!que.empty()){
      ll edge = que.front();
      que.pop_front();
      FOR(i,0,v[edge].size()){
       ll to = v[edge][i].first;
       ll co = v[edge][i].second;
        if(used[to]==-1){
          used[to] = used[edge] + co;
          que.push_back(to);
        }
      }
    }

    FOR(i,1,n+1){
      cout<<used[i]%2<<endl;
    }
}
