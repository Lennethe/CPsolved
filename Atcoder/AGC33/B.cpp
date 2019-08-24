//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h,w,n,sr,sc;
    cin>>h>>w>>n>>sr>>sc;
    string s,t;

    cin>>s>>t;
    map<ll,ll> po_mp;
    string ans = "YES";
    po_mp['D'] = sr;
    po_mp['U'] = sr;
    po_mp['L'] = sc;
    po_mp['R'] = sc;



    FOR(i,0,n){
      if(s[i] == 'D')po_mp['D']++;
      if(s[i] == 'U')po_mp['U']--;
      if(s[i] == 'L')po_mp['L']--;
      if(s[i] == 'R')po_mp['R']++;

      if(po_mp['U'] < 1)ans = "NO";
      if(po_mp['D'] > h)ans = "NO";
      if(po_mp['L'] < 1)ans = "NO";
      if(po_mp['R'] > w)ans = "NO";


      if(t[i] == 'D')po_mp['U'] = min(h, po_mp['U']+1);
      if(t[i] == 'U')po_mp['D'] = max((ll)1, po_mp['D']-1);
      if(t[i] == 'R')po_mp['L'] = min(w, po_mp['L']+1);
      if(t[i] == 'L')po_mp['R'] = max((ll)1, po_mp['R']-1);



/*      s_mp[s[i]]++;
      t_mp[t[i]]++;

      if(s_mp['U'] - t_mp['D'] > u){
        ans = "NO";
      }
      if(s_mp['D'] - t_mp['U'] > d){
        ans = "NO";
      }
      if(s_mp['R'] - t_mp['L'] > r){
        ans = "NO";
      }
      if(s_mp['L'] - t_mp['R'] > l){
        ans = "NO";
      }
*/
  }
    cout<<ans<<endl;


}
