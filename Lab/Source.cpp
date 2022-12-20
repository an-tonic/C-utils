#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <chrono>
#include "Stack.h"
#include "Queue.h"
#include "Queue2stacks.h"
#include "List.h";


using namespace std;

using namespace std::chrono;

#define ARRAY_SIZE 1000000
#define KEYS_SIZE 1000
#define MIN 0
#define MAX 10000
#define MAX_SIZE 100


int random(int min, int max) {
    return min + int((max - min + 1) * rand() / (RAND_MAX + 1.0));
}

void createRandomArray(int*& t, int n, int l, int h) {
    t = new int[n];

    for (int i = 0; i < n; i++) {
        t[i] = random(l, h);
    }
}

void printArray(int t[], int n) {
    for (int i = 0; i <= n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int linearSearch(int t[], int l, int r, int key)
{
    //iteratively check from the element at position l to r
    //if the key is found return it
    for (int i = l; i <= r; i++) {
        if (t[i] == key)
            return i;
    }
    // Key not found 
    return -1;
}

int linearSearchR(int t[], int l, int r, int key) {

    //Check if you reached the end of the array
    //if yes, return -1
    if (l > r) {
        return -1;
    }
    // Otherwise, check if key is present at the l position
    //return it if it is found
    if (t[l] == key) {
        return l;
    }
    // call the function again by omitting the item you checked above
    linearSearch(t, l + 1, r, key);
    
}

int binarySearch(int t[], int l, int r, int key){
    int mid;
    //check if you have not reach the end of the array
    //if not
        // Find the mid
    while (l <= r) {
        mid = l + (r - l) / 2;

        if (t[mid] == key) {
            return mid;
        }
        if (t[mid] < key) {
            r = mid - 1;

        }
        else l = mid + 1;

    }
    return -1;
}

int binarySearchR(int t[], int l, int r, int key) {
    //check if you are at the end of the array
    //if not
        // Find  mid

        // Check if key is present at the mid
        //return it if it does


        // Check if the key lies in between l and mid
        // if yes, recursively call binary search with the elements between l and mid

        // Otherwise, the key lies in between and mid and r
        // Recursively call binary search with the elements between mid and r

    // if the key is not found, return -1
    
    int mid = l + (r - l) / 2;

    if (t[mid] == key) {
        return mid;
    }
    if (t[mid] < key) { 
       
        binarySearchR(t, l, mid - 1, key);
    }
    else binarySearchR(t, mid+1, r, key);
}

int ternarySearch(int t[], int l, int r, int key)
{
    int mid1, mid2;

    //check if you have not reach the end of the array
    //if not
        // Find the mid
    while (l <= r) {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;


        if (t[mid1] == key) {
            return mid1;
        }
        else if (t[mid2] == key) {
            return mid2;
        }

        if (t[mid1] > key) {
            r = mid1 - 1;

        }
        else if (t[mid2] < key) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;

        }

    }
    return -1;
    //check if you are at the end of the array
    //if not

        // Find  mid1 and mid2         

        // Check if key is present at any mid and return it

        // check where the key lies and iteratively repeat
        // The key lies in between l and mid1
        //adjust r accordingly

        // The key lies in between mid2 and r 
        // adjust l accordingly

        // The key lies in between mid1 and mid2 
        // adjust both l and r accordingly

    // if the key is not found, return -1
    return 0;
}

int ternarySearchR(int t[], int l, int r, int key)
{
    //check if you are at the end of the array
    //if not

        // Find  mid1 and mid2 

        // Check if key is present at any mid and return it

        // check where the key lies and recursively repeat
        // The key lies in between l and mid1 

        // The key lies in between mid2 and r 

        // The key lies in between mid1 and mid2 


    // if the key is not found, return -1
    return 0;
}




typedef struct Coordinates {
    int row; int col;
    char direction = 'U';
};

typedef struct MazeProblem {
    int** maze;
    int rows;
    int columns;
    Coordinates start;
    Coordinates finish;
};

void int2Binary(unsigned int x) {
    Stack<int> s;

    while (x > 1) {
        s.push(x % 2);
        x = x / 2;
    }
    s.push(x);

    while (!s.isEmpty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    
}

bool match(char a, char b) {
    return ((a == '(' && b == ')') ||
        (a == '{' && b == '}') ||
        (a == '[' && b == ']'));
}

bool isBalanced(string statement) {
    Stack<char> s;
    for (char ch : statement) {

        if (!(ch == '(' || ch == '[' || ch == '{' || ch == '}' || ch == ']' || ch == ')')) {
            continue;
        }


        else if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (match(s.top(), ch)) {
                s.pop();
            }
            else {
                return false;
            }
        }

    }
    

}

string reversePolishNotation(string s)
{

    return "j";
}

bool match(Coordinates& a, Coordinates& b) {
    return (a.row == b.row && a.col == b.col);
}

void printMaze(int** maze, int rows, int columns) {

}

MazeProblem* loadMaze(string filename) {
    MazeProblem* problem = new MazeProblem();

    ifstream file(filename);

    file >> problem->rows;
    file >> problem->columns;

    file >> problem->start.row;
    file >> problem->start.col;
    problem->start.direction = 'S';

    file >> problem->finish.row;
    file >> problem->finish.col;
    problem->finish.direction = 'F';

    problem->maze = new int* [problem->rows];
    for (int i = 0; i < problem->rows; i++) {
        problem->maze[i] = new int[problem->columns];
    }
    for (int i = 0; i < problem->rows; i++) {
        for (int j = 0; j < problem->columns; j++) {
            file >> problem->maze[i][j];
        }
    }
    return problem;
}

void solveMaze(MazeProblem* problem, bool debug = false) {
    Stack<Coordinates> s;
    Coordinates pos;

    s.push(problem->start);
    


    while (!s.isEmpty()) {
        pos = s.top();
        problem->maze[pos.row][pos.col] = 2;

        if (match(pos, problem->finish)) {
            cout << "Found the solution";
            return;
        }
        
        else if (pos.row + 1 < problem->rows && problem->maze[pos.row+1][pos.col] == 1){
             Coordinates newC = { pos.row + 1, pos.col,'U' };
             s.push(newC);
        }
        else if (pos.col + 1 < problem->columns && problem->maze[pos.row][pos.col + 1] == 1) {
             Coordinates newC = { pos.row, pos.col + 1,'R' };
             s.push(newC);
        }
        else if (pos.col - 1 >= 0 && problem->maze[pos.row][pos.col - 1] == 1) {
             Coordinates newC = { pos.row, pos.col - 1,'L' };
             s.push(newC);
        }
        else if (pos.row - 1 >= 0 && problem->maze[pos.row-1][pos.col] == 1) {
             Coordinates newC = { pos.row - 1, pos.col,'L' };
             s.push(newC);
        }
        else {
            problem->maze[pos.row][pos.col] = 0;
            s.pop();
            continue;
        }
    }
    cout << "The path was not found";

}






int main()
{
    //srand(123456);
    //int* keys;
    //createRandomArray(keys, KEYS_SIZE, MIN, MAX);
    //int* array = NULL;
    ////temp var to store the position of the element we search
    //int keypos = -1;
    //high_resolution_clock::time_point start, finish;
    //duration<double> duration;
    ////initialize array with random numbers
    //createRandomArray(array, ARRAY_SIZE, MIN, MAX);
    ////time linear search iterative
    //start = high_resolution_clock::now();
    //for (int keyIndex = 0; keyIndex < KEYS_SIZE; keyIndex++) {
    //    keypos = linearSearch(array, 0, ARRAY_SIZE - 1, keys[keyIndex]);
    //}
    //finish = high_resolution_clock::now();
    //duration = finish - start;
    //cout << duration.count() << "\n";
    //Uncomment the sections you want to check

    
  /*  cout << 8 << " to binary is "; int2Binary(8); cout << endl;
    cout << 11 << " to binary is "; int2Binary(11); cout << endl;
    cout << 13 << " to binary is "; int2Binary(13); cout << endl;
    cout << 17 << " to binary is "; int2Binary(17); cout << endl;*/
    

    
  /*  string test1 = "{ [ ] }";
    string test2 = "( [ { } { } [ ] ) )";
    string test3 = "( [ ] { ( ) } )";

    std::cout << test1 << " is " << (isBalanced(test1) ? "" : " NOT ") << " balanced\n";
    std::cout << test2 << " is " << (isBalanced(test2) ? "" : " NOT ") << " balanced\n";
    std::cout << test3 << " is " << (isBalanced(test3) ? "" : " NOT ") << " balanced\n";
    */

    
  /*  Queue2Stacks<int> queue2stacks;

    for (int i = 1; i <=5; i++) {
        queue2stacks.enqueue(i);
    }
    cout<<queue2stacks.dequeue()<<endl;
    queue2stacks.enqueue(6);

    for (int i = 1; i <= 6; i++) {
        cout << queue2stacks.dequeue() << endl;
    }*/
    

    /*
    string test1 = "a + b";                 //ab+
    string test2 = "(a + b)*c";             //ab+c*
    string test3 = "a + (b*c)";             //abc*+
    string test4 = "a*b + c*d";             //ab*cd*+
    string test5 = "a - ((b+c) * (d+e))";   //abc+de+*-
    string test6 = "a+b*(c^d-e)^(f+g*h)-i"; //abcd^e-fgh*+^*+i-

    cout.width(50); cout << left << test1 << right << reversePolishNotation(test1) << "\n";
    cout.width(50); cout << left << test2 << right << reversePolishNotation(test2) << "\n";
    cout.width(50); cout << left << test3 << right << reversePolishNotation(test3) << "\n";
    cout.width(50); cout << left << test4 << right << reversePolishNotation(test4) << "\n";
    cout.width(50); cout << left << test5 << right << reversePolishNotation(test5) << "\n";
    cout.width(50); cout << left << test6 << right << reversePolishNotation(test6) << "\n";
    */

    
   /* MazeProblem* problem;

    problem = loadMaze("maze6_6.dat");
    solveMaze(problem);

    problem = loadMaze("maze6_7.dat");
    solveMaze(problem);

    problem = loadMaze("maze10_16.dat");
    solveMaze(problem);*/
    
  


}