#include<iostream>
#include<time.h>				//time library
using namespace std;
int fibonacci(int x);			//recursive fibonacci
int main(){
	int n = 40;
	clock_t start, end;			//clock objects
	start = clock();
	cout << fibonacci(n) << endl;	//function call
	end = clock();
	cout << start << " " << end << endl;
	cout << "time taken = " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
}
int fibonacci(int x){			//recursive function
	if (x == 1 || x == 2){
		return 1;
	}
	else{
		return (fibonacci(x - 1) + fibonacci(x - 2));
	}
}