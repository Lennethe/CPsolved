#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  string s;
  cin>>s;
  int SIZE = 26;
  vector<int> key(SIZE,0);

  FOR(i,0,SIZE){
    key[s[i]-'a']=1;
  }
  int pre=0;
  char q='z';
  if((int)s.size()<SIZE){
    FOR(i,0,SIZE){
      if(key[i]==0){
        cout<<s<<(char)('a'+i)<<endl;
        break;
      }
    }
  }
  else{
    if(s=="zyxwvutsrqponmlkjihgfedcba") cout<<-1<<endl;
    else{
      FORr(i,SIZE-2,-1){
        if(s[i]<s[i+1]){
          pre=i;
          break;
        }
      }
      FOR(i,pre,SIZE){
        if(s[pre]<s[i]&&s[i]<q){
          q=s[i];
        }
      }
      FOR(i,0,pre){
        cout<<s[i];
      }
      cout<<q<<endl;
    }
  }

}
