#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){


	int N;
	cin>>N;
	vector<int> vec(N);
	
	cin>>vec.at(0);
	int j;
	for(int i=1; i<N; i++){
		cin >>j;
		vec.at(i) = j+vec.at(i-1);
	}
	int a,b,c,d;
	int L=0,R=0;
	int res;
	int ans = vec.at(N-1);
	for(int i=1; i<N-2; i++){
		
		double inst=0;
		res = vec.at(N-1);
		for(int j=0; j<i; j++){
			inst = std::abs((double)((double)vec.at(i)/2)-vec.at(j));
			if(inst<res) {
				res=inst;
				L=j;
			}
			
		}
		
		res = vec.at(N-1);
		for(int j=i; j<N; j++){
			inst = std::abs(((double)(double)(vec.at(N-1)-vec.at(i))/2)-(vec.at(j)-vec.at(i)));
			if(inst<res) {
				res=inst;
				R=j;
			}
			
		}
		
	//cout<<"L="<<L<<" C=" << i << " R=" << R << " N=" << N << endl; 
		
		
		a=vec.at(L);
		b=vec.at(i)-vec.at(L);
		c=vec.at(R)-vec.at(i);
		d=vec.at(N-1)-vec.at(R);
		
	//cout<< a <<"," << b << "." << c<< ","<< d <<endl;
		
		int min = a;
		int max = a;
		
		if(min > b) min=b;
		if(min > c) min=c;
		if(min > d) min=d;
		if(max < b) max=b;
		if(max < c) max=c;
		if(max < d) max=d;
		
		if(ans>(max-min)) ans=max-min;
		
		
	}
	
	cout << ans << endl;
	
}
