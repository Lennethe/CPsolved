#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
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
    map<ll,ll> mp;
    FOR(i,0,n*n){
      ll in;
      cin>>in;
      mp[in]++;
    }
    ll odd=0;
    ll odd_sum=0;
    vector<ll> lin;
    vector<ll> out;
    map<ll,ll> odd_mp;
    FORm(i,mp){
      ll x = i->second;
      ll key = i->first;
      cout<<key<<" "<<x<<endl;
      if(x%2==0){
        FOR(j,0,x/2){
          out.push_back(key);
        }
      }
      else{
        odd += 1;
        odd_sum += x;
        odd_mp[key] = x;
        lin.push_back(key);
      }
    }
    FORm(i,odd_mp){
      ll x = i->second;
      ll key = i-> first;
      FOR(j,0,x-1){
        lin.push_back(key);
      }
    }




    if((n%2==0 && odd == 0) || (n%2==1 && (n-odd)%2==0)  ){
      cout<<"YES"<<endl;

      ll siz = out.size();
      VEC2(mat,n,n);
      if(n%2==1){
        FOR(i,0,(n-odd)/2){
          lin.push_back(out[siz-1-i]);
          lin.push_back(out[siz-1-i]);
        }
        siz = lin.size();
        FOR(i,0,(odd-n)){
          out.push_back(lin[siz-1-i]);
        }
        FOR(i,0,n){
          ll mid = (n/2)+1;
          mat[i][mid] = lin[i];
        }

      }
      ll pos=0;
      FOR(i,0,n){
        FOR(j,0,n/2){
          mat[i][j] = out[pos];
          mat[i][n-j-1] = out[pos];
          pos++;
        }
      }
      FOR(i,0,n){
        FOR(j,0,n){
          cout<<mat[i][j]<<" ";
        }
        cout<<endl;
      }
    }
    else cout<<"NO"<<endl;

}
