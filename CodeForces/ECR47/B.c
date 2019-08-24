#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin>>s;
  int pos0=0;
  int flag2=0;
  for(int i=0; i<(int)s.size(); i++){
    if((s[i]=='2'||i==(int)s.size()-1)&&flag2==0) {
      flag2=1;
      pos0=i;
      std::sort(s.begin(),s.begin()+i+1);
    }
    else if(flag2==1&&s[i]=='1'){
      s.erase(s.begin()+i);
      s.insert(s.begin()+pos0,'1');
      pos0++;
    }
  }

  cout<<s<<endl;
}
