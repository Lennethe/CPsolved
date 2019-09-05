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

//計算量はsqrt(N)
template<typename T>
vector<T> Divisors(T n)
{
    vector<T> result;

    T boundary = sqrt(n);

    for (T i = 1; i <= boundary; i++) {
        if (n % i == 0) {
            result.push_back(i);
            if(i != (n / i) && i * i != n)
                result.push_back(n/i);
        }
    }
    sort(result.begin(),result.end());
    return result;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    cin>>q;
    vector<ll> v(1e5);
    FOR(i,1,1e5){
      v[i+1] += v[i] + i;
    }
    FOR(i,0,q){
      ll n;
      cin>>n;
      ll a,b,c;
      a=1;
      b=2;
      c=1;
      FORr(i,1,1e5-1){
        if(v[i]<=n && n%v[i] == 0){
  //        cout<<v[i]<<" "<<i<<endl;
          ll tmp = n/v[i];
          b = i;
          a = tmp;
          break;
        }

      }
//      cout<<a<<b<<c<<endl;
      FOR(i,0,a){
        cout<<1;
      }
      FOR(i,0,b){
        cout<<3;
      }
      FOR(i,0,c){
        cout<<7;
      }
      cout<<endl;


    }
}
