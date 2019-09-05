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
    ll n,x;
    cin>>n>>x;
    vector<P> v(x+1,P(-1,-1));
    FOR(i,1,n+1){
      ll in;
      cin>>in;
      if(v[in].first == -1)v[in] = P(i,i);
      else v[in].second = i;
    }

    ll left = 1;
    ll tmp = -2;
    FOR(i,1,n+1){
      if(v[i].first>tmp){
        left++;
        tmp = v[i].second;
      }
      else if(v[i].first == -1) left++;
      else break;
    }
    tmp = x+1;
    ll right = 1;
    FORr(i,1,n){
      if(v[i].first == -1){
        right++;
      }
      else if(v[i].second<tmp){
        right++;
        tmp = v[i].first;
      }
      else break;
    }

    v.emplace_back(P(1e9,1e9));
    ll ans=0;
//    cout<<right<<endl;
    FOR(i,0,left){
      while(v[i].second>v[x+2-right].first){
        right--;
      }
//      cout<<right<<endl;
      ans+=right;
    }

    cout<<ans<<endl;



}
