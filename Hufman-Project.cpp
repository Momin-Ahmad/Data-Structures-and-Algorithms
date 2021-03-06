#include<iostream>
using namespace std;
class node{								//node class
public:
	int value;
	node *next;							//next pointer
private:
};
class list{
private:
	node* head;							//head pointer
	int num;
public:
	list() :head(NULL){
	}
	void insert_at_beginning(int new_value){		//insert at beginning
		node* n = new node;
		n->value = new_value;
		n->next = head;
		head = n;

	}
	void insert_at_loc(int location, int new_value){	//insert at location
		if (head != NULL){
			node* pre = new node;
			node* cur = new node;
			node* n = new node;
			cur = head;
			for (int i = 1; i < location; i++){
				pre = cur;
				cur = cur->next;
			}
			pre->next = n;
			n->next = cur;
			n->value = new_value;
		}
	}
	void del(int location, int del_value){			//delete function
		node* pre = new node;
		node* cur = new node;
		cur = head;
		for (int i = 1; i < location; i++){
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		delete cur;
	}
	void display(){									//display function
		node* n = new node;
		n = head;
		while (n != NULL){
			cout << endl << n->value << " ";
			n = n->next;
		}
		cout << endl << endl;
		delete n;
	}
	void count(){
		num = 0;
		node* n = new node;
		n = head;
		while (n != NULL){
			num++;
			n = n->next;
		}
		cout << "The number of items in the linked list is:" << num << endl;
		delete n;
	}
	void sort(){
		node* n = new node;
		n = head;
		count();
		for (int i = 0; i < num; i++){
			for (int j = 0; j < num - i - 1; j++){
				if ((n->value)>(n->next->value) && n->next != NULL){
					int temp = n->value;
					n->value = n->next->value;
					n->next->value = temp;
					n = n->next;
					display();
				}
			}
			n = head;
		}
	}


	void menu(){					//menu for ease of use
		int prompt;
		int loc, val;
		cout << "1. insert at beginning\n2.insert at location\n3.delete at location\n4.display\n5.count\n6.sort\n7.exit" << endl;
		cin >> prompt;
		switch (prompt){
		case 1:
			cout << "Enter value:";
			cin >> val;
			this->insert_at_beginning(val);
			menu();
			break;
		case 2:
			cout << "Enter location and value separated by spaces:";
			cin >> loc >> val;
			this->insert_at_loc(loc, val);
			menu();
			break;
		case 3:
			cout << "Enter location and value separated by spaces:";
			cin >> loc >> val;
			count();
			if (loc <= num){
				this->del(loc, val);
			}
			menu();
			break;
		case 4:
			this->display();
			menu();
			break;
		case 5:
			this->count();
			menu();
			break;
		case 6:
			this->sort();
			menu();
			break;
		case 7:
			break;
		}
	}
};

class hufnode{
public:
	int weight;
	int value;
	hufnode* next;
	hufnode* left;
	hufnode* right;
};

class hufList{
private:
	hufnode* head;							//head pointer
	hufnode* root;
	int num;
public:
	hufList() :head(NULL){
	}
	void insert_at_beginning(int new_value){		//insert at beginning
		hufnode* n = new hufnode;
		n->value = new_value;
		n->next = head;
		head = n;

	}
	void del(int location, int del_value){			//delete function
		hufnode* pre = new hufnode;
		hufnode* cur = new hufnode;
		cur = head;
		for (int i = 1; i < location; i++){
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		delete cur;
	}
	void display(){									//display function
		hufnode* n = new hufnode;
		n = head;
		while (n != NULL){
			cout << endl << n->value << " ";
			n = n->next;
		}
		cout << endl << endl;
		delete n;
	}
	void count(){
		num = 0;
		hufnode* n = new hufnode;
		n = head;
		while (n != NULL){
			num++;
			n = n->next;
		}
		cout << "The number of items in the linked list is:" << num << endl;
		delete n;
	}
	void sort(){
		hufnode* n = new hufnode;
		n = head;
		count();
		for (int i = 0; i < num; i++){
			for (int j = 0; j < num - i - 1; j++){
				if ((n->value)>(n->next->value) && n->next != NULL){
					int temp = n->value;
					n->value = n->next->value;
					n->next->value = temp;
					n = n->next;
					display();
				}
			}
			n = head;
		}
	}
	void bob(){
		hufnode* n = new hufnode;
		n->value = (head->value) + (head->next->value);
		insert_at_beginning(n->value);
		this->sort();
		n->left = new hufnode;
		n->left->value = head->value;
		n->right = new hufnode;
		n->right->value = head->next->value;
		//delete head->next;
		//delete head;
		//head = n;
		head = head->next->next;
		cout << "Left value=" << n->left->value << "and right value=" << n->right->value << endl;
	}
	void menu(){					//menu for ease of use
		int prompt;
		int loc, val;
		cout << "1. insert at beginning\n2.insert at location\n3.delete at location\n4.display\n5.count\n6.sort\n7.exit" << endl;
		cin >> prompt;
		switch (prompt){
		case 1:
			cout << "Enter value:";
			cin >> val;
			this->insert_at_beginning(val);
			menu();
			break;
		case 2:
			cout << "Enter bob:" << endl;
			this->bob();
			menu();
			break;
		case 3:
			cout << "Enter location and value separated by spaces:";
			cin >> loc >> val;
			count();
			if (loc <= num){
				this->del(loc, val);
			}
			menu();
			break;
		case 4:
			this->display();
			menu();
			break;
		case 5:
			this->count();
			menu();
			break;
		case 6:
			this->sort();
			menu();
			break;
		case 7:
			break;
		}
	}
};

class huffman{
private:
	list myList;
	hufnode* root;
	int num;
public:
	void insert(int){}
};



int main(){
	hufList l;							//singly linked list
	cout << "Welcome to hufList" << endl;
	l.menu();
	system("pause");
}
