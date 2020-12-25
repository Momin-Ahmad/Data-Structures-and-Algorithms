#include<iostream>
#include<time.h>				//time library
using namespace std;
int factorial(int x);
int main(){
	int n = 5;
	clock_t start, end;			//clock objects
	start = clock();
	cout << factorial(n) << endl;
	end = clock();
	cout << start << " " << end << endl;
	cout << "time taken = " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
}
int factorial(int x){			//iterative factorial
	int ans = 1;
	while (x > 0){
		ans = ans*x ;
		x--;
	}
	return ans;
}