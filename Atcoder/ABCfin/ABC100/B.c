#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int D,N;
	
	cin >> D >> N;
	if(N==100) N=N+1;
	cout << (int)pow(100,D)*N << endl;
}
