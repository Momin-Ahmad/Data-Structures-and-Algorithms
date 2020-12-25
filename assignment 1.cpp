#include<iostream>
#include<time.h>
using namespace std;
int main(){
	int n = 100;
	{
		clock_t start, end;
		int sum = 0;
		start = clock();
		for (int i = 0; i < n; i++){
			sum++;
		}
		end = clock();
		cout << "Fragment #1" << endl;
		cout << "n = " << n << endl;
		cout << "start: " << start << " end: " << end << endl;
		cout << "Time elapsed = " << double(end - start) / CLOCKS_PER_SEC << endl << endl;
	}
	{
	clock_t start, end;
	int sum = 0;
	start = clock();
	for (int i = 0; i < n; i+=2){
		sum++;
	}
	end = clock();
	cout << "Fragment #2" << endl;
	cout << "n = " << n << endl;
	cout << "start: " << start << " end: " << end << endl;
	cout << "Time elapsed = " << double(end - start) / CLOCKS_PER_SEC << endl << endl;
}
	{
	clock_t start, end;
	int sum = 0;
	start = clock();
	for (int i = 0; i < n; i++){
		sum++;
	}
	for (int j = 0; j < n; j++){
		sum++;
	}
	end = clock();
	cout << "Fragment #3" << endl;
	cout << "n = " << n << endl;
	cout << "start: " << start << " end: " << end << endl;
	cout << "Time elapsed = " << double(end - start) / CLOCKS_PER_SEC << endl << endl;
}
	{
	clock_t start, end;
	int sum = 0;
	start = clock();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n*n; j++){
			for (int k = 0; k < j; k++){
				sum++;
			}
		}
	}
	end = clock();
	cout << "Fragment #4" << endl;
	cout << "n = " << n << endl;
	cout << "start: " << start << " end: " << end << endl;
	cout << "Time elapsed = " << double(end - start) / CLOCKS_PER_SEC << endl << endl;
}
	system("pause");
}
