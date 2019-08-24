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

    ll n;
    cin>>n;
    ll left=0,right=1;
    ll size = 1;
    ll two = 1;
    while(left>n || right<n){
      two*=-2;
      if(size%2 == 1){
        right += two;
        left = right + two + 1;
      }
      else{
        left += two;
        right = left + two - 1;
      }
      size++;
    }

    while(size>1){
      if(left<=n && n<=right){
        n -= two;
        cout<<"1";
      }
      else{
        cout<<"0";
      }

      if(size%2 == 0){
        right -= two;
        left = right + (two/2 + 1);
      }
      else{
        left -= two;
        right = left + (two/2 - 1);
      }
      two/=-2;
      size--;
    }
    if(n <= 1)cout<<n;
    cout<<endl;

}
