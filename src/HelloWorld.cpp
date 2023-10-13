//============================================================================
// Name        : HelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int top;
	int arr[5];

public:
	Stack() {
		top = -1;
		for (int i = 0; i < 5; i++) {
			arr[i] = 0;
		}
	}

	bool isEmpty() {
		if (top == -1) return true;
		return false;
	}

	bool isFull() {
		if (top == 4) return true;
		return false;
	}

	void push(int value) {
		if (isFull()) {
			cout << "Stack overflow\n";
			return;
		}
		top++;
		arr[top] = value;
	}

	int pop() {
		if (isEmpty()) {
			cout << "Stack underflow\n";
			return 0;
		}
		int popValue = arr[top];
		arr[top] = 0;
		top--;
		return popValue;
	}

	int count() {
		return top + 1;
	}

	int peek(int pos) {
		if (pos < 0 || pos > top) {
			return 0;
		}
		return arr[pos];
	}

	void change(int pos, int value) {
		if (pos < 0 || pos > top) {
			return;
		}
		arr[pos] = value;
		cout << "Value changed at the location " << pos << "\n";
	}

	void display() {
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << "\n";
		}
	}
};

int main() {
	Stack s1;
	int option, position, value;

	do {
		cout << "What operation do you want to perform? Select Option number. Enter 0 to exit\n";
		cout << "1. Push \n";
		cout << "2. Pop \n";
		cout << "3. isEmpty() \n";
		cout << "4. isFull() \n";
		cout << "5. peek() \n";
		cout << "6. count() \n";
		cout << "7. change() \n";
		cout << "8. display() \n\n";

		cin >> option;

		switch(option) {
		case 0:
			break;
		case 1:
			cout << "Enter an item to push in a stack: ";
			cin >> value;
			s1.push(value);
			break;
		case 2:
			cout << "Popped value: " << s1.pop() << "\n";
			break;
		case 3:
			if (s1.isEmpty()) cout << "Stack is Empty \n";
			else cout << "Stack is not Empty \n";
			break;
		case 4:
			if (s1.isFull()) cout << "Stack is Full \n";
			else cout << "Stack is not Full \n";
			break;
		case 5:
			cout << "Enter the position you want to peak: ";
			cin >> position;
			cout << "Peeked value: " << s1.peek(position) << "\n";
			break;
		case 6:
			cout << "Stack has " << s1.count() << "items \n";
			break;
		case 7:
			cout << "Position: ";
			cin >> position;
			cout << "Value: ";
			cin >> value;
			s1.change(position, value);
			break;
		case 8:
			s1.display();
			break;
		default:
			cout << "Can not find option " << option << "\n";
		}
	} while (option != 0);

	return 0;
}
