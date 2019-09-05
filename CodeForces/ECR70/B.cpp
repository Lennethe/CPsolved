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
    ll out= 100;
    vector<vector<vector<ll>>> v(10, vector<vector<ll>>(10, vector<ll>(10,out)));
    FOR(i,0,10){
      FOR(j,0,10){
        //iとjは行列
        FOR(k,0,10){
          FOR(l,0,10){
            if(l+k==0) continue;
            ll x = (i*k + j*l)%10;
            v[i][j][x] = min(v[i][j][x], l+k);
            v[j][i][x] = min(v[i][j][x], l+k);
          }
        }
      }
    }
    string s;
    cin>>s;
    while(false){
      ll in1,in2,in3;
      cin>>in1>>in2>>in3;
      ll res = v[in1][in2][in3];
      cout<<res<<endl;
    }
    vector<vector<ll>> ans(10,vector<ll>(10,0));
    FOR(i,1,s.size()){
      ll a = s[i] - '0' + 10;
      ll b = s[i-1] - '0';
      ll dif = (a-b)%10;
      FOR(j,0,10){
        FOR(k,0,10){
          if(v[j][k][dif] == out){
            ans[j][k] = -1;
          }

          if(ans[j][k] != -1){
            ans[j][k] += max(v[j][k][dif] - 1, (ll)0);
          }
        }
      }
    }

    FOR(i,0,10){
      FOR(j,0,10){
        cout<<ans[i][j];
        if(j != 9)cout<<" ";
      }
      cout<<endl;
    }
}
