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

    ll n;
    ll sx,sy,gx,gy;
    cin>>n>>sx>>sy>>gx>>gy;
    VEC2(v,n,n);
    FOR(i,0,n){
      string s;
      cin>>s;
      FOR(j,0,n){
        v[i][j] = s[j] - '0';
      }
    }

    VEC2(sf,n,n);
    VEC2(gf,n,n);

    vector<P> sv;
    vector<P> gv;

    queue<P> que;
    que.push(P(sx-1,sy-1));
    while(!que.empty()){
      P p = que.front();
      que.pop();
//      cout<<"("<<p.first<<","<<p.second<<")"<<" ";
      sv.push_back(p);
      ll r = p.first;
      ll c = p.second;
      ll rl = max((ll)0,r-1);
      ll rr = min(n-1,r+1);
      ll cu = max((ll)0,c-1);
      ll cd = min(n-1,c+1);
      if(v[r][cu] == 0 && sf[r][cu] == 0){
        sf[r][cu] = 1;
        que.push(P(r,cu));
      }
      if(v[r][cd] == 0 && sf[r][cd] == 0){
        sf[r][cd] = 1;
        que.push(P(r,cd));
      }
      if(v[rl][c] == 0 && sf[rl][c] == 0){
        sf[rl][c] = 1;
        que.push(P(rl,c));
      }
      if(v[rr][c] == 0 && sf[rr][c] == 0){
        sf[rr][c] = 1;
        que.push(P(rr,c));
      }
    }

    que.push(P(gx-1,gy-1));
    while(!que.empty()){
      P p = que.front();
      que.pop();
//      cout<<"("<<p.first<<","<<p.second<<")"<<" ";
      gv.push_back(p);
      ll r = p.first;
      ll c = p.second;
      ll rl = max((ll)0,r-1);
      ll rr = min(n-1,r+1);
      ll cu = max((ll)0,c-1);
      ll cd = min(n-1,c+1);
      if(v[r][cu] == 0 && gf[r][cu] == 0){
        gf[r][cu] = 1;
        que.push(P(r,cu));
      }
      if(v[r][cd] == 0 && gf[r][cd] == 0){
        gf[r][cd] = 1;
        que.push(P(r,cd));
      }
      if(v[rl][c] == 0 && gf[rl][c] == 0){
        gf[rl][c] = 1;
        que.push(P(rl,c));
      }
      if(v[rr][c] == 0 && gf[rr][c] == 0){
        gf[rr][c] = 1;
        que.push(P(rr,c));
      }
    }

    ll res = 1e10;
    FOR(i,0,sv.size()){
      FOR(j,0,gv.size()){
        ll svx = sv[i].first;
        ll svy = sv[i].second;
        ll gvx = gv[j].first;
        ll gvy = gv[j].second;
        res = min(res,(svx-gvx)*(svx-gvx) + (svy-gvy)*(svy-gvy) )  ;
//        cout<<svx<<" "<<gvx<<" "<<svy<<" "<<gvy<<endl;
      }
    }


    cout<<res<<endl;

}
