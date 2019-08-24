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
    ll n;
    cin>>n;
    map<char, deque<ll>> left;
    map<char, deque<ll>> right;
    string a,b;
    cin>>a>>b;
    //ll left_hatena=0;
    //ll right_hatena=0;
    FOR(i,0,n){
      left[a[i]].push_back(i+1);
      //else left_hatena++;
      right[b[i]].push_back(i+1);
      //else right_hatena++;
    }
    deque<P> ans;

    FORm(i,left){
      char key = i->first;
      if(key == '?') continue;
      while(!(i->second.empty())){
        if(!right[key].empty()){
          P p = P(left[key].front(), right[key].front());
          right[key].pop_front();
          left[key].pop_front();
          ans.push_back(p);
        }
        else break;
      }
    }
    FORm(i,left){
      char key = i->first;
      if(key == '?')continue;
      while(!(i->second.empty())){
        if(!right['?'].empty()){
          P p = P(left[key].front(), right['?'].front());
          right['?'].pop_front();
          left[key].pop_front();
          ans.push_back(p);
        }
        else break;
      }
    }
    FORm(i,right){
      char key = i->first;
      while(!(i->second.empty())){
        if(!left['?'].empty()){
          P p = P(left['?'].front(), right[key].front());
          right[key].pop_front();
          left['?'].pop_front();
          ans.push_back(p);
        }
        else break;
      }
    }


    cout<<ans.size()<<endl;
    while(!ans.empty()){
      cout<<ans.front().first<<" "<<ans.front().second<<endl;
      ans.pop_front();
    }

}
