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

    ll t;
    cin>>t;
    FOR(i,0,t){
      ll n,a,b;
      cin>>n>>a>>b;
      string s;
      cin>>s;
      ll cost = b;
      ll at = 0;
      ll bt = 1;
      char c = '0';
      FOR(i,0,n){
        if(c != s[i]){
          cost += a;
          at++;
          if(c == '1'){
            cost += b;
            bt++;
          }
        }
        if(s[i] == '0') cost += a+b;
        else cost += a + 2*b;
        if(s[i] == '0'){
          at++;
          bt++;
        }
        else{
          at += 1;
          bt += 2;
        }
        c = s[i];
      }
//      cout<<at<<" "<<bt<<endl;
//      cout<<cost<<endl;

      ll po = 0;
      FOR(i,0,n){
        if(s[i] == '1'){
          if(po == 0) po=i;
          else{
            ll dif = i-po;
            po = i;
            if(dif == 1)continue;
            cost -= max((ll)0, 2*a - (dif-2)*b);
//            cout<<i<<" "<<2*a - (dif-2)*b<<endl;

          }
        }
      }
      cout<<cost<<endl;
    }
}
