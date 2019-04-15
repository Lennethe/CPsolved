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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    cinv(v,0,n);
    vector<ll> v_zo(k);
    cinv(v_zo,0,k);

    ll one=0;
    ll zero=0;
    FOR(i,0,n){
      if(v[i] == 1) one++;
      else zero++;
    }
    ll flag=0;
    FOR(i,0,k){
      if(i%2==0) flag += v_zo[i];
    }

    ll flag_start=0;
    if(one == zero) flag_start=2;
    else if(flag == one) flag_start=1;

    ll one_sum = 1e9;
    ll zero_sum = 1e9;
    vector<ll> tmp_v = v;

    if(flag_start != 0){
      ll turn = 1;
      ll sum_x = 0;
      ll tmp_res = 0;
      FOR(i,0,k){
        ll x = v_zo[i];
        FOR(j,0,x){
          ll pos = sum_x + j;
          // 入れ替え
          if(v[pos] != turn){
            FOR(p,pos,n){
              if(v[p] == turn){
                ll val = v[p];
                v.erase(v.begin() + p);
                v.insert(v.begin() + pos, val);
                tmp_res += p-pos;
                break;
              }
            }
          }
        }
        turn = (turn + 1) % 2;
        sum_x += x;
      }
      one_sum = tmp_res;
    }
    v = tmp_v;
    if(flag_start != 1){
      ll turn = 0;
      ll sum_x = 0;
      ll tmp_res = 0;
      FOR(i,0,k){
        ll x = v_zo[i];
        FOR(j,0,x){
          ll pos = sum_x + j;
          // 入れ替え
          if(v[pos] != turn){
            FOR(p,pos,n){
              if(v[p] == turn){
                ll val = v[p];
                v.erase(v.begin() + p);
                v.insert(v.begin() + pos, val);
                tmp_res += p-pos;
                break;
              }
            }
          }
        }
        turn = (turn + 1) % 2;
        sum_x += x;
      }
      zero_sum = tmp_res;
    }
    cout<<min(one_sum, zero_sum)<<endl;

}
