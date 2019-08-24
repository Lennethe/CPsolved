#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int m,n;
  cin>>m>>n;
  vector<int> vecg(m);
  vector<int> vecc(n);

  for(int i=0; i<m; i++){
    cin>>vecg.at(i);
  }
  for(int i=0; i<n; i++){
    cin>>vecc.at(i);
  }

  int res=0;

  for(int i=0; i<m && res<n; i++){
    if(vecg.at(i)<=vecc.at(res)){
      res++;
    }
    //cout<<"we"<<res<<endl;
  }
  cout<<res<<endl;
}
