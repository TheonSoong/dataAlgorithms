#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define maxSize 1000

class Stack {
private:
    int data[maxSize];
    int top;
public:
    Stack() {
        top = -1;
        memset(data, 0, sizeof(data));
    }

    int Size() {
        return top + 1;
    }

    bool Empty() {
        if (-1 == top) {
            return true;
        }
        else {
            return false;
        }
    }

    int Top() {
        if (-1 == top) {
            exit(-1);
        }
        else {
            return data[top];
        }
    }

    void Push(int item) {
        if (top == maxSize - 1) {
            exit(-1);
        }
        else {
            data[++top] = item;
        }
    }

    int Pop() {
        if (-1 == top) {
            exit(-1);
        }
        else {
            return data[top--];
        }
    }
};


int main() {
    int m, n, k;
    cin >> m >> n >> k; //m represents stack size; n respresents the number of push sequences; k represents test pop sequence.
       
    for (int i = 0; i < k; ++i) {
        vector<int> vctInt(n + 1);
        for (int j = 1; j <= n; ++j) {
			cin >> vctInt[j];
        }

		int idx = 1;
        Stack s;
        for (int j = 1; j <= n; j++) {  //input sequence 1, 2, 3, 4, 5, 6, ..., n
            s.Push(j);  //always push to stack.
            if (s.Size() > m)
                break;

            while (!s.Empty() && s.Top() == vctInt[idx]) {
                s.Pop();    //match Input and Output.
                idx++;
            }
        }

        if (idx == n + 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}