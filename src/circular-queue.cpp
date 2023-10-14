//============================================================================
// Name        : queue.cpp
// Author      : haitruong-tech
// Version     : 0.0.1
// Copyright   : MIT
// Description : basic circular queue using static array
//============================================================================

#include <iostream>
using namespace std;

class Queue{
private:
	int front;
	int rear;
	int arr[5];

public:
	Queue() {
		front = -1;
		rear = -1;
		for (int i = 0; i < 5; i++) {
			arr[i] = 0;
		}
	}

	bool isEmpty() {
		return rear == -1 && front == -1;
	}

	bool isFull() {
		return (rear + 1) % 5 == front;
	}

	void enqueue(int value) {
		if (isFull()) {
			cout << "Queue is Full\n";
			return;
		}
		if (isEmpty()) {
			front = 0;
		}
		rear = (rear + 1) % 5;
		arr[rear] = value;
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty\n";
			return INT_MIN;
		}
		int value = arr[front];
		arr[front] = 0;
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front = (front + 1) % 5;
		}
		return value;
	}

	int count() {
		return isEmpty() ? 0 : rear - front + 1;
	}

	void display() {
		if (front == -1) {
			return;
		}
		for (int i = front; i < 5; i++) {
			cout << arr[i] << "\n";
		}
		for (int i = 0; i < front; i++) {
			cout << arr[i] << "\n";
		}
	}
};

int main() {
	Queue q1;
	int option, value;

	do {
		cout << "What operation do you want to perform? Select Option number. Enter 0 to exit\n";
		cout << "1. Enqueue() \n";
		cout << "2. Dequeue() \n";
		cout << "3. isEmpty() \n";
		cout << "4. isFull() \n";
		cout << "5. count() \n";
		cout << "6. display() \n\n";

		cin >> option;

		switch(option) {
		case 0:
			break;
		case 1:
			cout << "\n\n=====Enqueue operation=====\n";
			cout << "Enter the value you want to enqueue: ";
			cin >> value;
			q1.enqueue(value);
			break;
		case 2:
			cout << "\n\n=====Dequeue operation=====\n";
			cout << "Value " << q1.dequeue() << " is dequeued\n";
			break;
		case 3:
			cout << "\n\n=====Check IsEmpty operation=====\n";
			if (q1.isEmpty()) cout << "Queue is Empty. \n";
			else cout << "Queue is not Empty. \n";
			break;
		case 4:
			cout << "\n\n=====Check IsFull operation=====\n";
			if (q1.isFull()) cout << "Queue is Full. \n";
			else cout << "Queue is not Full. \n";
			break;
		case 5:
			cout << "\n\n=====Count operation=====\n";
			cout << "There are " << q1.count() << " values in the queue\n";
			break;
		case 6:
			cout << "\n\n=====Display operation=====\n";
			q1.display();
			break;
		default:
			cout << "Can not find option " << option << "\n";
		}
	} while (option != 0);

	return 0;
}
