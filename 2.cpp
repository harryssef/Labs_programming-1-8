#include "2.h"

class queue {
private:
	int size;
	string* queArray;
	int front;
	int rear;
	int nItems;

public:
	queue() {
		cout << "Default constructor" << endl;
	}

	queue(const queue& other) {
		cout << "Copy constructor" << endl;
		this->size = other.size;
		this->front = other.front;
		this->rear = other.rear;
		this->nItems = other.nItems;

		this->queArray = new string[other.size];
		for (int i = 0; i < other.size; i++) {
			this->queArray[i] = other.queArray[i];
		}
	}


	queue(int scale) {
		size = scale;
		queArray = new string[size];
		front = 0;
		rear = -1;
		nItems = 0;
	}

	void insert(string item) {
		if (rear == size - 1) {
			rear = -1;
			nItems = 0;
		}
		queArray[++rear] = item;
		nItems++;
	}

	string remove() {
		string temp = queArray[front++];
		if (front == size) {
			front = 0;
		}
		nItems--;
		return temp;
	}

	string peekFront() {
		return queArray[front];
	}

	string peekRear() {
		return queArray[rear];
	}

	bool isEmpty() {
		return (nItems == 0);
	}

	int amount() {
		return nItems;
	}

	void print() {
		if (nItems == 0) {
			cout << "Queue is empty" << endl;
			return;
		}
		if (front > rear) {
			int j = front;
			while (j != size) {
				cout << queArray[j] << endl;
				j++;
			}
			j = 0;
			while (j <= rear) {
				cout << queArray[j] << endl;
				j++;
			}
		}
		else if (front < rear) {
			for (int i = front; i <= rear; i++) {
				cout << queArray[i] << endl;
			}
		}
		else if (nItems == 1) {
			cout << queArray[front];
		}
		cout << endl;
		return;
	}

	~queue() {
		cout << "Destructor" << endl;
		delete[] queArray;
	}
};



int main() {
	int rate;
	cout << "Enter the number of items in the queue: " << endl;
	cin >> rate;

	queue MyQueue(rate);

	int choice;

	int choice1;

	bool check = true;

	string items;


	while (check) {
		cout << "Pick function number: " << endl;
		cout << "1 - insert" << endl;
		cout << "2 - remove" << endl;
		cout << "3 - peekFront" << endl;
		cout << "4 - peekRear" << endl;
		cout << "5 - isEmpty" << endl;
		cout << "6 - amount" << endl;
		cout << "7 - print" << endl << endl;
		
		cin >> choice;
		if (choice >= 1 && choice <= 7) {
			switch (choice) {
			case 1:
			{
				cin >> items;
				MyQueue.insert(items);
			}
			break;

			case 2:
			{
				string result = MyQueue.remove();
				cout << result << endl;
			}
			break;

			case 3:
			{
				string result1 = MyQueue.peekFront();
				cout << result1 << endl;
			}
			break;

			case 4:
			{
				string result2 = MyQueue.peekRear();
				cout << result2 << endl;
			}
			break;

			case 5:
			{
				int result3 = MyQueue.isEmpty();
				cout << result3 << endl;
			}
			break;

			case 6:
			{
				int result4 = MyQueue.amount();
				cout << result4 << endl;
			}
			break;

			case 7:
			{
				MyQueue.print();
			}
			break;

			}
		}
		else {
			cout << "Please, enter a valid function number" << endl << endl;
			continue;
		}



		cout << "Do you want to continue work with queue?" << endl;
		cout << "Enter 1, if yes and enter 0, if no" << endl;

		cin >> choice1;

		if (choice1 == 1) {
			continue;
		}
		else if (choice1 == 0) {
			break;
		}
		else {
			cout << "Error" << endl;
			break;
		}
		
	}

	return 0;
}