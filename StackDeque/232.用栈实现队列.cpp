#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


class MyQueue
{
public:
    stack<int> sIn;
    stack<int> sOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        sIn.push(x);
    }

    int pop()
    {
        int res = this->peek();
        sOut.pop();
        return res;
    }

    int peek()
    {
        if (sOut.empty())
        {
            while (!sIn.empty())
            {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
        return sOut.top();
    }

    bool empty()
    {
        return sIn.empty() && sOut.empty();
    }
};

int main()
{
    stack<int> A;
    A.push(1);
    A.push(2);
    int b = A.top();
    cout << "b: " << b << endl;
    cout << "A.size() = " << A.size() << endl;
    A.pop();
    cout << "After pop, A.size() = " << A.size() << endl;

    return 0;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */