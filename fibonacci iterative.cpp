#include<iostream>
#include<time.h>			//time library
using namespace std;
int fibonacci(int x);		
int main(){
	cout << "Fibonacci Series" << endl;
	int n = 1000000;
	clock_t start, end;		//clock objects
	start = clock();
	cout << fibonacci(n) << endl;		//function call
	end = clock();
	cout << start << " " << end << endl;
	cout << "time taken = " << (double)(end-start) << endl;
	cout << "time taken = " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
}
int fibonacci(int x){			//iterative fibonacci
	int a = 0;
	int b = 1;
	int sum = 0;
	while (x >0){
		sum = a + b;
		a = b;
		b = sum;
		x--;
	}
	return b;
}