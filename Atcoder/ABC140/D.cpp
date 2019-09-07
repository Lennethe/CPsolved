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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s.push_back('q');
    char c = 'w';
    vector<ll> lv,rv;
    ll l=0,r=0;
    ll tmp = 0;
    FOR(i,0,n+1){
      if(c != s[i]){
        if(c == 'L'){
          lv.push_back(2);
          l+=tmp;
        }
        else if(c == 'R'){
          rv.push_back(2);
          r+=tmp;
        }
        c = s[i];
        tmp = 0;
      }
      else tmp++;
    }
    if(s[0] == 'L' && s[n-1] == 'L'){
      lv[0]--;
      lv[1]--;
    }
    if(s[0] == 'L' && s[n-1] == 'R'){
      lv[0]--;
      rv[0]--;
    }
    if(s[0] == 'R' && s[n-1] == 'L'){
      lv[0]--;
      rv[0]--;
    }
    if(s[0] == 'R' && s[n-1] == 'R'){
      rv[0]--;
      rv[1]--;
    }

    ll ls = 0;
    ll rs = 0;
    sortAlr(lv);
    sortAlr(rv);
    FOR(i,0,min(m,(ll)lv.size()))ls += lv[i];
    FOR(i,0,min(m,(ll)rv.size()))rs += rv[i];
    if(lv.size() + rv.size() == 1)l--;
    cout<<max(ls,rs) + l+r<<endl;
//    cout<<l<<" "<<r<<" "<<ls<<" "<<rs<<" "<<lv.size()<<" "<<rv.size()<<endl;


}
