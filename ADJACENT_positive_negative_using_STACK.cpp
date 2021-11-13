#include <iostream>

using namespace std;


void inserting(stack<int>& s,int temp)
{
    if(s.size()==0|| s.top() <= temp)
    {
        s.push(temp);
        return;

    }
    int val = s.top();
    s.pop();
    inserting(val);
    s.push(val);
    return;

}
void sort_it(stack<int>& s)
{
    if(s.size()==1)
    {
        return ;
    }

    int temp=s.top();
    s.pop();
    sort_it(s);
    inserting(s,temp);
    return ;

}

int main()
{
    stack<int> s;
    s.push(-5);
    s.push(-2);
    s.push(-9);
    s.push(-7);
    s.push(3);
    sort_it(s);
    while(!s.empty())
    {

        cout<<s.top()<<"|";
    }

    return 0;
}
