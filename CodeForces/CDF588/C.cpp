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

    ll n,k;
    cin>>n>>k;
    vector<P> v(k);
    FOR(i,0,k){
      ll in1,in2;
      cin>>in1>>in2;
      v[i] = P(in1,in2);
    }
    vector<vector<ll>> tmp(8,vector<ll>(8,0));
    ll res = 0;
    FOR(a,1,7){
      FOR(b,1,7){
        FOR(c,1,7){
          FOR(d,1,7){
            FOR(e,1,7){
              FOR(f,1,7){
                FOR(g,1,7){
                  ll x,y;
                  vector<vector<ll>> ans = tmp;
                  FOR(i,0,k){
                    x = v[i].first;
                    y = v[i].second;
                    if(x == 1) x = a;
                    else if(x == 2) x = b;
                    else if(x == 3) x = c;
                    else if(x == 4) x = d;
                    else if(x == 5) x = e;
                    else if(x == 6) x = f;
                    else if(x == 7) x = g;
                    if(y == 1) y = a;
                    else if(y == 2) y = b;
                    else if(y == 3) y = c;
                    else if(y == 4) y = d;
                    else if(y == 5) y = e;
                    else if(y == 6) y = f;
                    else if(y == 7) y = g;
                    ans[min(x,y)][max(x,y)] = 1;
                  }
                 ll t = 0;
                 FOR(i,0,8){
                   FOR(j,0,8){
                     t += ans[i][j];
                   }
                 }
                 res = max(res,t);
                }
              }
            }
          }
        }
      }
    }
    cout<<res<<endl;
}
