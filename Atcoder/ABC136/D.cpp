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
    string s;
    cin>>s;
    vector<P> pos(s.size(),P(-1,0));
    vector<ll> v(s.size());
    FOR(i,0,s.size()-1)if(s[i] == 'R' && s[i+1] == 'L'){
      pos[i] = P(i,0);
      pos[i+1] = P(i+1,1);
    }
    FORr(i,0,s.size()-2){
      if(s[i]=='R' && s[i+1] == 'R'){
        if(pos[i+1].second == 0) pos[i]=P(pos[i+1].first+1,1);
        else pos[i] = P(pos[i+1].first-1,0);
      }
    }
    FOR(i,0,s.size()-1){
      if(s[i]=='L' && s[i+1] == 'L'){
        if(pos[i].second == 0) pos[i+1]=P(pos[i].first+1,1);
        else pos[i+1] = P(pos[i].first-1,0);
      }
    }

    FOR(i,0,s.size()){
      v[pos[i].first]++;
    }
    FOR(i,0,s.size()){
      cout<<v[i];
      if(i != s.size()-1) cout<<" ";
      else cout<<endl;
    }
}
