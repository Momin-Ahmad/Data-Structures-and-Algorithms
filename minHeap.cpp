#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//Heap class
//We will be implementing a min Heap
class minHeap{
private:
	//vector is used since it is more flexible than an array
	vector<int> arr;
	
public:
	minHeap()
	{

		arr.push_back(0);
		
	}
	//sets values of the vector
	void setValues(){
		int capacity;
		cout << "Enter number of elements:";
		cin >> capacity;
		for (int i = 1; i <= capacity; i++){
			int val;
			cout << "Enter value #" << i << ":";
			cin >> val;			
			arr.push_back(val);
		}
	}
	//inserts values to the vector one by one and maintains heap order
	void insert(int key){
		arr.push_back(key);
		int i = arr.size() - 1;
		while (i != 1 && arr[getParent(i)] > arr[i]){
			int temp = arr[getParent(i)];
			arr[getParent(i)] = arr[i];
			arr[i] = temp;
			i = getParent(i);
		}
	}
	//returns left child index
	int getLeft(int i){
		return 2 * i;
	}
	//returns right child index
	int getRight(int i){
		return 2 * i + 1;
	}
	//returns parent index
	int getParent(int i){
		return i / 2;
	}
	//returns minimum/top element
	void top(){
		cout << "The minimum value in the heap is:" << arr[1] << endl;
	}
	//checks whether the heap is empty
	bool isEmpty(){
		if (arr.size() == 1){
			return true;
		}
		else{
			return false;
		}
	}
	//tells size of heap
	void size(){
		cout << "The size of the heap is:" << arr.size() - 1 << endl;
	}
	//tells height of heap
	void height(){
		cout << "The height of the tree is:" << ceil(log2(arr.size()) - 1) << endl;
	}
	//displays the heap values
	void display(){
		for (unsigned int i = 1; i <= arr.size()-1; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//sorts the vector
	void sort(){
		for (unsigned int i = 1; i <= arr.size() - 1; i++){
			for (unsigned int j = 1; j <= arr.size() - 2; j++){
				if (arr[j] > arr[j + 1]){
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			display();
		}
	}
//menu for ease of use
	void menu(){
		int prompt;
		cout << "1.setvalues\n2.insert value\n3.display\n4.sort\n5.exit" << endl;
		cout << "\t\t\t\t                      *******************" << endl;
		cin >> prompt;
		switch (prompt){
		case 1:
			this->setValues();
			menu();
			break;
		case 2:
			int val;
			cout << "Enter value to be inserted:";
			cin >> val;
			this->insert(val);
			menu();
			break;
		case 3:
			this->display();
			menu();
			break;
		case 4:
			this->sort();
			menu();
			break;
		case 5:
			break;
		default:
			break;
		}
	}
};
//main function
int main(){
	minHeap myHeap;
	myHeap.insert(12);
	myHeap.insert(5);
	myHeap.insert(11);
	myHeap.insert(3);
	myHeap.insert(10);
	myHeap.insert(6);
	myHeap.insert(9);
	myHeap.insert(4);
	myHeap.insert(8);
	myHeap.insert(1);
	myHeap.insert(7);
	myHeap.insert(2);
	myHeap.display();
	myHeap.height();
	myHeap.isEmpty();
	myHeap.size();
	myHeap.top();
	//myHeap.menu();
	system("pause");
}