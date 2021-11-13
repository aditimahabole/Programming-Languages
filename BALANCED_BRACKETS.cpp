#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string d) : data(d), next(NULL) {}
};
class Stack
{
public:
    Node *head;
    ///////THIS IS A CONSTRUCTOR//////
    Stack()
    {
        head=NULL;
    }
    void push(string data)
    {
        if (!head) //CHECKING IF HEAD = NULL OR NOT WE CAN WRITE THIS AS if(head!=NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }
/////////PROVIDES THE TOP VALUE//////////
    string top()
    {
        return head->data;
    }
///////////////DELTES TOP ELEMENT/////////
    void pop()
    {
        if (!head)
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }
//////////GIVES TRUE FALSE VALUE IF STACK EMPTY OR NOT//////////
    bool empty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
//////////FUNTION FOR CALCULATING VALUE////////////
int bracket_marks(string S)
{
    Stack s;
    int i = 0;
    int num = 0;
    while (i < S.length()) //S.length IS LENGTH OF STRING
    {
        if (S[i] == '<')
        {
            s.push("<"); // IF WE GET THIS CHAR THEN SIMPLY PUSH IF NOT GO TO ELSE
        }

        else // THIS PART WILL ONLY WORK WHEN S[i] ='>'
        {
            if (s.top() == "<") //CHECK IF TOP ELEMENT IS '< 'OR NOT IF YES THEN POP IT AND PUSH 1 SO THIS WILL IMPLY THAT WE GOT <>
                                          // AND THATS WHY WE ARE PUSING 1 AS <>=1
            {
                s.pop();
                s.push("1");//PUSHED 1 IN STRING FORMAT
            }
            else
            {
                int ct = 0;//COUNT VARIABLE
                while (s.top() != "<") //////COUNT TILL WE GET '<' IN STACK
                {
                    ct += stoi(s.top());// stoi IS STRING FUNTION THAT CONVERTS STRING TO INTGER
                    s.pop();                 //WE ARE USING stoi SO THAT WE CAN ADD NUMBERS AS STRING CANNOT BE ADDED
                                                  // THEN WE ARE POPING
                }
                s.pop();
                s.push(to_string(3 * ct)); //THEN MULTIPLYING THAT INTEGER TO 3 AND PSUING BACK TO STACK IN FORM OF STRING
                                                         // AS STACK IS OF CHAR TYPE (to_string) IS STRING FUNCTION //CONVERTS INTEGER TO STRING
            }
        }
        i++;
    }
    while (!s.empty())//AT THIS STAGE ONLY NUMBER WILL BE THERE IN STACK IN STRING FORMAT
    {
        num += stoi(s.top()); // ADDING NUMBERS BY FIRST CONVERTING STRING TO INTGER
        s.pop();
    }
    return num;// RETURNING THE INTEGER VALUE
}
int main()
{
    //WE ARE USING LINK LIST TO STORE CHARATER OF STRING
    string S1=" <><><>" ;
    cout <<bracket_marks(S1)<<endl;
    cout<<endl;
    string S2="<><>";
     cout <<bracket_marks(S2)<<endl;
     cout<<endl;
     string S3="<<>>";
     cout <<bracket_marks(S3)<<endl;
     cout<<endl;
      string S4="<<><>>";
     cout <<bracket_marks(S4)<< endl;
     cout<<endl;
      string S5="<<<>>>";
     cout <<bracket_marks(S5)<<endl;
     cout<<endl;
     return 0;
}
