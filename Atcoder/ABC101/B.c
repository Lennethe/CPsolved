#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main(){
	int N, Sn,m;
	
	Sn=0;

	cin>>N;
	m=N;
	while(10<=N){
		Sn=Sn+N%10;
		N=N/10;
	}
	
	Sn = Sn+N;
	
	
	if(m%Sn==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
}
