#include <iostream>
#include <stack>

using namespace std;
void insert_sorted(stack<int> &s, int ele)
{
    int temp;
    if (s.empty() || ele > s.top())
    {
        s.push(ele);
        return;
    }

    temp = s.top();
    s.pop();
    insert_sorted(s, ele);
    s.push(temp);
}
void sort_stack(stack<int> &s)
{
    int temp;

    if (!s.empty())
    {
        temp = s.top();
        s.pop();
        sort_stack(s);
        insert_sorted(s, temp);
    }
}
void display(stack<int> s)
{

    while (!s.empty())
    {
        cout << s.top() << " | ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(7);
    s.push(9);
    s.push(1);
    cout<<"UNSORTED STACK:"<<endl;
    display(s);
    cout<<endl;
    sort_stack(s);
    cout << "SORTED STACK USING RECURSSION:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " | ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
