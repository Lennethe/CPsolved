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

    ll h,w;
    cin>>h>>w;
    vector<string> v(h);
    FOR(i,0,h)cin>>v[i];

    vector<vector<ll>> vh(h,vector<ll>(w,0));
    vector<vector<ll>> vw(h,vector<ll>(w,0));

    FOR(i,0,h){
      FOR(j,0,w){
        if(v[i][j] == '.'){
          vh[i][j] = 1;
          vw[i][j] = 1;
        }
      }
    }

    FOR(i,1,h){
      FOR(j,0,w){
        if(vh[i][j] != 0)vh[i][j] += vh[i-1][j];
      }
    }

    FORr(i,0,h-2){
      FOR(j,0,w){
        if(vh[i][j] != 0)vh[i][j] = max(vh[i+1][j],vh[i][j]);
      }
    }

    FOR(i,0,h){
      FOR(j,1,w){
        if(vw[i][j] != 0)vw[i][j] += vw[i][j-1];
      }
    }

    FOR(i,0,h){
      FORr(j,0,w-2){
        if(vw[i][j] != 0)vw[i][j] = max(vw[i][j+1],vw[i][j]);
      }
    }

    ll ans = 0;
    FOR(i,0,h){
      FOR(j,0,w){
        ans = max(ans, vh[i][j] + vw[i][j] - 1);
      }
    }
    cout<<ans<<endl;





}
