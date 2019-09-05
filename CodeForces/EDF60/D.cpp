#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll s_x,s_y,g_x,g_y;
    cin>>s_x>>s_y>>g_x>>g_y;
    ll n;
    string s;
    cin>>n>>s;

    ll lb=0, ub=1e18;
    map<char,ll> mp_x;
    map<char,ll> mp_y;
    mp_y['U'] = 1;
    mp_y['D'] = -1;
    mp_x['R'] = 1;
    mp_x['L'] = -1;
    ll wind_x=0, wind_y=0;
    FOR(i,0,n){
      wind_x += mp_x[s[i]];
      wind_y += mp_y[s[i]];
    }
//    cout<<wind_x<< " "<<wind_y<<endl;

    while(ub-lb>1){
      ll mid = (ub+lb)/2;
      ll rest = mid%n;
      ll quot = mid/n;
      ll tmp_sx = s_x;
      ll tmp_sy = s_y;
      tmp_sx += wind_x*quot;
      tmp_sy += wind_y*quot;
      FOR(i,0,rest){
        tmp_sx += mp_x[s[i]];
        tmp_sy += mp_y[s[i]];
      }

      if(abs(g_x - tmp_sx) + abs(g_y - tmp_sy) <= mid)ub = mid;
      else lb = mid;
      cerr<<lb << " "<< ub<<endl;
    }


    if(lb>1e17){
      cout<<-1<<endl;
    }
    else{
      cout<<ub<<endl;
    }
  }
