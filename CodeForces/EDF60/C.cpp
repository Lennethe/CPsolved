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

P move(P p, char c){

  if(c =='U')p.second++;
  if(c =='D')p.second--;
  if(c =='R')p.first++;
  if(c =='L')p.first--;
  return p;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> wind(2);

    ll s_x, s_y, g_x, g_y;
    cin>>s_x>>s_y>>g_x>>g_y;

    ll n;
    cin>>n;
    string w;
    cin>>w;

    ll u=0,d=0,r=0,l=0;
    FOR(i,0,n){
      if(w[i] == 'U') u++;
      if(w[i] == 'D') d++;
      if(w[i] == 'R') r++;
      if(w[i] == 'L') l++;
    }
    wind[0] = u-d;
    wind[1] = r-l;

    bool goal = true;
    if(abs(wind[1]) + abs(wind[0]) == n){
      goal = false;
      ll x = g_x - s_x;
      ll y = g_y - s_y;
      if(wind[1]>0){
        if(y >= -x || y>= x) goal = true;
      }
      if(wind[0]>0){
        if(y<=x && y>=-x) goal = true;
      }
      if(wind[1]<0) {
        if(y<=-x || y<=x) goal = true;
      }
      if(wind[0]<0){
        if(y<=-x && y>=x) goal = true;
      }
    }

    if(goal){
      // udrl
      vector<P> ruld_max;
      vector<P> ruld_one;
      ll x[4] = {1,0,-1,0};
      ll y[4] = {0,1,0,-1};
      FOR(i,0,4){
        P max_p = P(0,0);
        P tmp_p = P(0,0);
        FOR(j,0,w.size()){
          tmp_p = move(tmp_p, w[j]);
          ll tx = tmp_p.first;
          ll ty = tmp_p.second;
          if(tx*x[i] + ty*y[i] > max_p.first*x[i] + max_p.second*y[i]) max_p = tmp_p;
        }
        ruld_max.push_back(max_p);
        ruld_one.push_back(tmp_p);
      }


    }
    else{
      cout<<-1<<endl;
    }
}
