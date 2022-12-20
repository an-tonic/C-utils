#pragma once
#include <iostream>

using namespace std;

#define MAX_SIZE 10

template <typename T>


struct Queue {
	T _data[MAX_SIZE];

	int _front = 0;
	int _back = 0;

	bool isEmpty() {
		return _front == _back;
	}

	bool isFull() {
		return _back == MAX_SIZE;
	}

	void enqueue(T x) {
		if (!isFull()) {
			_back++;
			_data[_back - 1] = x;

		}
	}

	T dequeue() {
		_front++;
		return _data[_front - 1];

	}

	void print() {
		for (int i = _front; i < _back; i++) {
			cout << _data[i] << " ";
		}
	}

};
