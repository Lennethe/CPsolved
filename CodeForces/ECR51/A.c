#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
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

  ll N;
  cin>>N;

  vector<string> v(N);
  cinv(v,0,N);
  ll s1a,s1A,s1;
  FOR(i,0,N){
    s1a=0;
    s1A=0;
    s1=0;
    FOR(j,0,v[i].size()){
      if('a'<=v[i][j]&&v[i][j]<='z') s1a++;
      if('A'<=v[i][j]&&v[i][j]<='Z') s1A++;
      if('0'<=v[i][j]&&v[i][j]<='9') s1++;
    //  cout<<s1a<<" "<<s1A<<" "<<s1<<endl;
    }
    if(s1a==0&&s1A==0){
      v[i][0]='a';
      v[i][1]='A';
    }
    else if(s1a==0&&s1==0){
      v[i][0]='a';
      v[i][1]='1';
    }
    else if(s1==0&&s1A==0){
      v[i][0]='A';
      v[i][1]='1';
      //cout<<v[i]<<endl;
    }
    else if(s1a==0){
      if(s1A==1 && 'A'<=v[i][0]&&v[i][0]<='Z'){
        v[i][1]='a';
      }
      else if(s1==1 && '0'<=v[i][0]&&v[i][0]<='9'){
        v[i][1]='a';
      }
      else v[i][0]='a';
    }
    else if(s1A==0){
      if(s1a==1 && 'a'<=v[i][0]&&v[i][0]<='z'){
        v[i][1]='A';
      }
      else if(s1==1 && '0'<=v[i][0]&&v[i][0]<='9'){
        v[i][1]='A';
      }
      else v[i][0]='A';
    }
    else if(s1==0){
      if(s1A==1 && 'A'<=v[i][0]&&v[i][0]<='Z'){
        v[i][1]='1';
      }
      else if(s1a==1 && 'a'<=v[i][0]&&v[i][0]<='z'){
        v[i][1]='1';
      }
      else v[i][0]='1';
    }
    cout<<v[i]<<endl;
  }

}
