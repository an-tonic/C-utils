#pragma once
#include <iostream>

using namespace std;

#define MAX_SIZE 10


template <typename T>

struct Stack {
    T _data[MAX_SIZE];
    unsigned int _top = 0;

    bool isEmpty() {
        return _top == 0;
    };

    bool isFull() {
        return _top == MAX_SIZE;
    };

    void reset() {
        _top = 0;
    }

    void print() {
        for (int i = _top - 1; i >= 0; i--) {
            cout << _data[i] << endl;
        }
        cout << endl;
    }

    void push(T a) {
        if (!isFull()) {
            _data[_top] = a;
            _top++;
        }
    }

    void pop() {
        if (!isEmpty()) {
            _top--;
        }
    }

    T top() {
        if (!isEmpty()) {
            return _data[_top - 1];
        }
    }

};


