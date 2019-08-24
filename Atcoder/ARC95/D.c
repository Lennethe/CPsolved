#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int comb(int n, int r){
	int res = 1;
	for(int i=0; i<r; i++){
		res = res*(n-i)/(i+1);
	}
	return res;
}


int main(){
	
	int n;
	cin >> n ;
	
	vector<int> vec(n);
	for(int i=0; i<n; i++){
		cin >> vec.at(i);
	}
	std::sort(vec.begin(), vec.end());
	
	
	int resa = 0;
	int resb = 0;
	
	resa = n-1;
	
	int inst = vec.at(n-1);
	for(int i=0; i<n; i++){
		if(inst >= std::abs(vec.at(n-1)/2 - vec.at(i))) {
			inst=std::abs(vec.at(n-1)/2 - vec.at(i));
			if(i != resa)resb=i;
		}
	}
	
	cout << vec.at(resa) << " " <<  vec.at(resb) << endl;
	
}
