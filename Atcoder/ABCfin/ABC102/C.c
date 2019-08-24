#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){


	int N;
	cin>>N;
	vector<int> vec(N);
	
	long long inst;
	for(int i=0; i<N; i++){
		
		cin>>inst;
		vec.at(i) = inst - i;
	}
	

	
	
	std::sort(vec.begin(),vec.end());
	long long res=0;
	int x = (N/2);
	for(int i=0; i<N; i++){
		res= res + std::abs(vec.at(i) - vec.at(x));
	}
	
	
	
	cout<< res <<endl;
	
	
}
