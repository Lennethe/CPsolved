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

vector<string> judge(vector<string> v,ll h, ll w, ll n){
  vector<string> s;
  s=v;
  FOR(i,0,h){
    ll num=1;
    FOR(j,1,w){
      if(v[i][j]==v[i][j-1]){
        num++;
      }
      else num=1;
      if(num>=n){
        FOR(k,j+1-num,j+1){
          s[i][k]='.';
        }
      }
    }
  }

  FOR(j,0,w){
    ll num=1;
    FOR(i,1,h){
      //cout<<"i="<<i<<"j="<<j<<endl;
      if(v[i][j]==v[i-1][j]){
        num++;
      }
      else num=1;

      //cout<<num<<endl;
      if(num>=n){
        FOR(k,i+1-num,i+1){
          //cout<<k<<endl;
          s[k][j]='.';
        }
      }
      //cout<<3<<endl;
    }
  }
  return s;

}

vector<string> lack(vector<string> v, ll h, ll w, ll n){
  FOR(j,0,w){
    FORr(i,h-2,0){
      //cout<<"i="<<i<<"j="<<j<<endl;
      if(v[i][j]!='.'){
        ll x=i;
        while(v[x+1][j]=='.'){
          x++;
          if(x==h-1)break;
        }
        char c = v[i][j];
        v[i][j]='.';
        v[x][j]=c;
      }
    }
  }
  return v;
}

bool ans(vector<string> v){
  FOR(i,0,v.size()){
    FOR(j,0,v[0].size()){
      if(v[i][j]!='.') return false;
    }
  }
  return true;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll h,w,n;
  cin>>h>>w>>n;
  vector<string> v(h);
  string res = "NO";

  cinv(v,0,h);
  FOR(i,0,h){
    FOR(j,1,w){
      vector<string> v1 = v;

      char c;
      c=v1[i][j-1];
      v1[i][j-1]=v1[i][j];
      v1[i][j]=c;
      v1=lack(v1,h,w,n);
      while(v1!=judge(v1,h,w,n)){
        v1=judge(v1,h,w,n);
        v1=lack(v1,h,w,n);
      }

      if(ans(v1))res="YES";
    }
  }
  cout<<res<<endl;


}
