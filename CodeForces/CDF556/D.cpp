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

    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<deque<pair<char, ll>>> r(4);
    vector<ll> error(4);
    map<char,map<ll,ll>> mp;

    FOR(i,0,n){
      mp[s[i]][i] = 1;
    }

    FOR(i,0,q){
//      FOR(j,0,n){
//        cout<<mp[s[j]][j];
//      }
//      cout<<endl;
      char c;
      cin>>c;
      if(c == '-'){
        ll in;
        cin>>in;
        //non-emptyなので
        if(error[in] == 0){
          char tmp_c = r[in].back().first;
          ll tmp_l = r[in].back().second;
          mp[tmp_c][tmp_l] = 1;
          r[in].pop_back();
          if(error[1]+error[2]+error[3] == 0)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
        }
        else{
          error[in]--;
          if(error[1]+error[2]+error[3] == 0) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
        }
//        r[in].push_back();
      }
      else{
        ll in1;
        char in2;
        cin>>in1>>in2;

        if(error[in1] == 0){
          ll po = -1;
          if(!r[in1].empty()) po = r[in1].back().second;
          ll f = -1;
  //        cout<<" po "<<po<<endl;
          FORm(j, mp[in2]){
  //          cout<<j->first<<endl;
            if(j->first > po && j-> second == 1){
              f = j->first;
              break;
            }
          }
          //あるかどうかを探す

          if(f == -1){
            cout<<"NO"<<endl;
            error[in1]++;
          }
          else{
            r[in1].push_back(make_pair(in2, f));
            mp[in2][f] = 0;
            if(error[1]+error[2]+error[3] == 0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
          }
        }
        else{
          cout<<"NO"<<endl;
          error[in1]++;
        }
      }
    }


}
