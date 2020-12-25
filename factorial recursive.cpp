#include<iostream>
#include<time.h>				//time library
using namespace std;
int factorial(int x);			
int main(){
	int n = 1000;
	clock_t start, end;			//clock objects
	start = clock();
	cout << factorial(n) << endl;		//function call
	end = clock();
	cout << start << " " << end << endl;
	cout << "time taken = " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
}
int factorial(int x){			//recursive factorial
	if (x == 0||x==1){
		return 1;
	}
	else{
		return (x*factorial(x - 1));
	}
}