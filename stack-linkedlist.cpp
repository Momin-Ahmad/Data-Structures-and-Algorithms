#include<iostream>
using namespace std;
class node{					//item of the stack
public:
	int value;
	node* next;
};
class stack{				//stack
private:
	node* top;
	unsigned int size;
public:
	stack() :top(NULL){			//constructor

	}
	bool is_empty(){			//checks for empty stack
		if (top == NULL){
			return true;
		}
		else {
			return false;
		}
	}
	void push(int num){			//adds element to top
		node* n = new node;
		n->value = num;
		n->next = top;
		top = n;
	}
	void pop(){					//pops first element of stack
		node* temp = new node;
		temp = top;
		if (!is_empty()){
			cout << "popped value:" << temp->value << endl;
			top = temp->next;
			delete temp;
		}
	}
	void display(){				//displays elements of the stack
		node* temp = new node;
		temp = top;
		cout << endl;
		while (temp != NULL){
			cout << temp->value << endl;
			temp = temp->next;
		} 
		delete temp;
	}
	void menu()				//menu for ease of use
	{
		cout << "****************Welcome to stack****************" << endl;
		int prompt;
		do{
			cout << "1.push\n2.pop\n3.display\n4.exit" << endl;
			cin >> prompt;
			switch (prompt)
			{
			case 1:
				int value;
				cout << "Enter value: ";
				fflush(stdin);
				cin >> value;
				this->push(value);
				break;
			case 2:
				this->pop();
				break;
			case 3:
				this->display();
				break;
			case 4:
				break;
			}
		} while (prompt != 4);

	}
};
int main(){
	stack myStack;			//stack object
	myStack.menu();
	system("pause");
}