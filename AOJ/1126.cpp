#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

// a>b なら 1 a=B なら 0 a<b なら-1
int strint_cmp(string a, string b){
  if(a == b){
    return 0;
  }
  else{
    ll siz = a.size();
    FOR(i,0,siz){
      if(a[i]<b[i]) return -1;
      if(a[i]>b[i]) return 1;
    }
  }
  return 0;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll w,h;
  cin>>w>>h;

  while(w!=0){
    vector<string> sv(h+1,"");
    FOR(i,0,w+1){
      sv[0].push_back('.');
    }
    FOR(i,1,h+1){
      string s;
      cin>>s;
      sv[i].push_back('.');
      FOR(j,0,w){
        sv[i].push_back(s[j]);
      }
    }
    vector<vector<pair<ll,string>>> dp = vector<vector<pair<ll,string>>>(h+1,vector<pair<ll,string>>(w+1,pair<ll,string>(0,"")));

    FOR(i,1,h+1){
      FOR(j,1,w+1){
        if('0' <= sv[i][j] && sv[i][j] <= '9'){
          pair<ll,string> p;
          if(dp[i-1][j].first<dp[i][j-1].first){
            p = dp[i][j-1];
          }
          else if(dp[i][j-1].first<dp[i-1][j].first){
            p = dp[i-1][j];
          }
          else if(dp[i-1][j].first == 0){
            p = make_pair(0,"");
          }
          else{
            string a = dp[i-1][j].second;
            string b = dp[i][j-1].second;
            if(strint_cmp(a,b) > 0) p = dp[i-1][j];
            else p = dp[i][j-1];
          }
          if(sv[i][j] == '0' && dp[i][j-1].first == 0 && dp[i-1][j].first == 0){

          }
          else{
            p.first++;
            p.second += sv[i][j];
          }
          dp[i][j] = p;
        }
      }
    }

    ll max_size = 0;
    FOR(i,0,h+1){
      FOR(j,0,w+1){
        max_size = max(max_size,dp[i][j].first);
      }
    }

    vector<string> ans;
    FOR(i,0,h+1){
      FOR(j,0,w+1){
        if(dp[i][j].first == max_size){
          ans.push_back(dp[i][j].second);
        }
      }
    }

    sortAlr(ans);
    cout<<ans[0]<<endl;
    cin>>w>>h;
  }


}
