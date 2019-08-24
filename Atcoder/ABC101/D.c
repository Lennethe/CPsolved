#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int sumDigit(int N){
	int Sn=0;

	while(10<=N){
		Sn=Sn+N%10;
		N=N/10;
	}
	Sn=Sn+N;

	return Sn;

}

int main(){

	double K;
	cin >> K;

	int num=0;


	for(int i=1; i<10 && num<K ; i++){

		cout<< i << endl;
		num++;
	}
	for(int i=19; i<100 && num<K ; i=i+10){

		cout<< i << endl;
		num++;
	}
	for(int i=199; i<2000 && num<K ; i=i+100){

		cout<< i << endl;
		num++;
	}
	for(int i=1999; i<10000 && num<K ; i=i+1000){

		cout<< i << endl;
		num++;
	}



	for(int i=9; i<K; i=i+10 ){


		cout<< "i = " << i << " then " << (double)i/sumDigit(i) << endl;
	}

}
