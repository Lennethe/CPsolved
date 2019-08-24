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
    vector<ll> lin;
    vector<ll> out;
    FORm(i,mp){
      ll x = i->second;
      ll key = i->first;
      cout<<key<<" "<<x<<endl;
      if(x%2==0){
        FOR(i,0,x/2){
          out.push_back(key);
        }
      }
      else{
        odd += x;
        FOR(i,0,x){
          lin.push_back(key);
        }
      }
    }


    if((n-odd)%2==0){
      cout<<"YES"<<endl;

      ll siz = out.size();
      FOR(i,0,(n-odd)/2){
        lin.push_back(out[siz-1-i]);
        lin.push_back(out[siz-1-i]);
      }
      siz = lin.size();
      FOR(i,0,(odd-n)){
        out.push_back(lin[siz-1-i]);
      }

      VEC2(mat,n,n);
      FOR(i,0,n){
        mat[i][i] = lin[i];
      }
      ll pos=0;
      FOR(i,0,n){
        FOR(j,0,i){
          mat[i][j] = out[pos];
          mat[j][i] = out[pos];
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
