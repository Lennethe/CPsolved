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
    vector<priority_queue<ll>> v(1e5+1);
    priority_queue<P> que;
    ll ans=0;
    FOR(i,0,n){
      ll in1,in2;
      cin>>in1>>in2;
      v[in1].push(in2);
    }

    FOR(i,1,m+1){
      if(!v[i].empty()){
        que.push(P(v[i].top(), i));
        v[i].pop();
      }

      if(!que.empty()){
        P p = que.top();
        que.pop();
        ans += p.first;
//        cout<<"i = "<<i<<" "<<p.first<<endl;
        ll po = p.second;
        if(!v[po].empty()){
          que.push(P(v[po].top(), po));
          v[po].pop();
        }
      }
    }
    cout<<ans<<endl;
}
