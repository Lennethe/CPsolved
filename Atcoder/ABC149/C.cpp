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

std::vector<int> sieve_of_eratosthenes(int n) {
  std::vector<int> primes(n);
  for (int i = 2; i < n; ++i) primes[i] = i;
  for (int i = 2; i * i < n; ++i)
    if (primes[i]){
      for (int j = i * i; j < n; j += i) primes[j] = 0;
    }
  return primes;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v = sieve_of_eratosthenes(2e5);
    ll x;
    cin>>x;
    FOR(i,x,2e5){
        if(v[i] != 0){
            cout<<i<<endl;
            break;
        }
    }
}