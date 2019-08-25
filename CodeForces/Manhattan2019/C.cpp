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
    vector<vector<ll>> v(n,vector<ll>(n));
    FOR(i,0,4){
      FOR(j,0,4){
        v[i][j] = i*n+j;
      }
    }

    vector<vector<ll>> ans(n,vector<ll>(n));
    ll tmp = 0;
    FOR(i,0,n/4){
      FOR(j,0,n/4){
        FOR(p,0,4){
          FOR(q,0,4){
            ll x = i*4+p;
            ll y = j*4+q;
            ans[x][y] = tmp;
            tmp++;
//            ans[x][y] = v[p][q] + 16*(i*(n/4)+j);

          }
        }
      }
    }
    FOR(i,0,n){
      ll a = 0;
      ll b = 0;
      FOR(j,0,n){
        a ^= ans[i][j];
        b ^= ans[j][i];
        cout<<ans[i][j];
        if(j!=n-1)cout<<" ";
      }
      cout<<endl;
//      cout<<a<<" "<<b<<endl;
    }
}
