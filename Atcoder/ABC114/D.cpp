#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
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
    map<ll,ll> mp;
    ll n;
    cin>>n;
    FOR(i,2,n+1){
      vector<ll> v = Divisors(i);
      ll div=i;
      FOR(j,1,v.size()){
        while(div%v[j]==0){
          div/=v[j];
          mp[v[j]]++;
        }
      }
    }
    mp[1]=0;
    map<ll,ll> ans;
    FORm(i,mp){
      if(i->second>=74){
        ans[75]++;
      }
      if(i->second>=24){
        ans[25]++;
      }
      if(i->second>=14){
        ans[15]++;
      }
      if(i->second>=4){
        ans[5]++;
      }
      if(i->second>=2){
        ans[3]++;
      }
//      cout<< i->first << " "<<i->second<<endl;
    }

    ll res=0;
    res+= ans[75];
    res+= ans[25] * max((ll)0,ans[3]-1);
    res+= ans[15] * max((ll)0,ans[5]-1);
    res+= (ans[5] * max((ll)0,ans[5]-1) * max((ll)0,ans[3]-2))/2;
    cout<<res<<endl;

}
