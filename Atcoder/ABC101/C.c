#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N,K;
	
	cin >> N >> K;
	
	vector<int> A(N);
	
	for(int i=0; i<N; i++){
		cin >> A.at(i) ;
	}
	
	
	
	int m=0;
	m = A.size();
	
	std::sort(A.begin(), A.end());
	
	int p=1;
	int q=0;
	while(A.at(0)==A.at(p)){
		p++;
		q++;
	}
	m=m-q-1;
	
	K=K-1;
	
	int res=0;
	while(m>0) {
		m=m-K;
		res++;
	}
	cout<<res<<endl;
}
