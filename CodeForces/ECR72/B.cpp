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
    ll t;
    cin>>t;
    FOR(i,0,t){
      ll n,hp;
      cin>>n>>hp;
      ll max_dam=0,dam=0;
      FOR(i,0,n){
        ll a,b;
        cin>>a>>b;
        max_dam = max(max_dam,a);
        dam = max(dam, a-b);
      }
      if(hp<=max_dam)cout<<1<<endl;
      else if(dam<=0) cout<<-1<<endl;
      else cout<<1 + (hp - max_dam + dam - 1)/dam<<endl;
    }
}
