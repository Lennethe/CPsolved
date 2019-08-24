#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N;
	cin>>N;
	int n= pow(2,N);
	vector<int> vec(n);
	vector<int> res(n,0);
	
	
	for(int i=0; i<n; i++){
		cin>>vec.at(i);
	}
	
	
	vector<vector<int>> vec1 = vector<vector<int>> (n,vector<int>(n,0));
	
	for(int i=0; i<n;i++){
		for(int j=i+1; j<n; j++){
			
			if(res.at(i|j)<vec.at(i)+vec.at(j))res.at(i|j)=vec.at(i)+vec.at(j);
			
			
			
		}
	}
	int max=0;
	int a;
	for(int i=1; i<n; i++){
		a=res.at(i);
		if(max>a) {
			cout<<max<<endl;
		}
		else {
			max=a;
			cout<<a<<endl;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			cout<<i|j;
		}
		cout<<endl;
	}
	
	
}
