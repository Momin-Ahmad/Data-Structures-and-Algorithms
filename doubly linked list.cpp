#include<iostream>
using namespace std;
class node{								//node class
private:
public:
	int value;
	node *next;							//next pointer
	node *back;							//back pointer

};
class list{
private:
	node* head;							//head pointer
	node* tail;							//tail pointer
	int num;
public:
	list() :head(NULL), tail(NULL){
	}
	void insert_at_end(int new_value){
		node* n = new node;
		n->value = new_value;
		if (head == 0 && tail == 0)			//empty list
		{
			n->next = n;
			n->back = n;
			head = n;
			tail = n;
		}
		else if (head == tail &&head != 0)		//one element in the list
		{
			tail->next = n;
			n->next = head;
			head->back = n;
			n->back = tail;
			tail = n;
		}
		else
		{
			tail->next = n;
			n->next = head;
			head->back = n;
			n->back = tail;
			tail = n;
		}
	}
	void sort(){							//sorting function
		int num = count();					//ascending order
		node* n = new node;
		n = head;
		float temp;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if ((n->value) >((n->next)->value))
				{
					temp = n->value;
					n->value = (n->next)->value;
					(n->next)->value = temp;
				}
				n = n->next;
			}
			n = head;
		}
		this->display();
	}
	int count(){							//counting function
		num = 0;
		node* n = new node;
		n = head;
		while (n != tail){
			num++;
			n = n->next;
		}
		num++;
		return num;
	}
	void average(){							//average function
		int num = count();
		int sum = 0;
		node* n = new node;
		n = head;
		for (int i = 0; i < num; i++)
		{
			sum += n->value;
			n = n->next;
		}
		int average = sum / num;
		cout << "The average is " << average << endl;
		cout << "After inserting average value to the list:" << endl;
		this->insert_at_end(average);
		this->sort();
		this->display();
	}
	void display(){						//display function
		node* n = new node;
		n = head;
		while (n != tail)
		{
			cout << n->value << " ";
			n = n->next;
		}
		cout << tail->value;
		cout << endl << endl;
	}
	void menu(){					//menu for ease of use
		int prompt;
		int loc, val;
		cout << "\t\t\t1.insert at end\n\t\t\t2.sort\n\t\t\t3.average\n\t\t\t4.display\n\t\t\t5.count\n\t\t\t6.exit" << endl;
		cout << "\t\t\t\t                      *******************" << endl;
		cin >> prompt;
		switch (prompt){
		case 1:
			cout << "Enter value:";
			cin >> val;
			this->insert_at_end(val);
			menu();
			break;
		case 2:
			cout << "After sorting:";
			this->sort();
			menu();
			break;
		case 3:
			this->average();
			menu();
			break;
		case 4:
			this->display();
			menu();
			break;
		case 5:
			cout << "The number of elements in the list is " << this->count() << endl;
			menu();
			break;
		}
	}

};
int main(){
	list l;						//circular doubly linked list
	cout << "\t\t\t\t*******************Welcome to linked list*******************" << endl;
	l.menu();
	system("pause");
}
