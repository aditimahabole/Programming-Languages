////////////////////////////////chunnu//////////////////////////////////////////
#include <iostream>

using namespace std;

int main()
{
    int R;
    cout<<"enter money"<<endl;
    cin>>R;
    int q;
    int sum;
    if(R%2==0)
    {
        sum=R+(R/2 )-1;
        cout<<sum;

    }
    else if(R%2==1)
    {
        q=R/3;
        if(((R-1)/2)%2==1)
        {
            sum=R+q+q/3+1;
            cout<<sum;
        }
        else
        {
            sum=R+q+q/3;
            cout<<sum;
        }
    }

    return 0;
}
//////////////////////////////////////////munnu////////////////////
#include <iostream>

using namespace std;

int main()
{
    int q;
    cout<<"enter money"<<endl;
    cin>>q;
    int r=0;

    int count=0;
    int sum=0;
    cout<<"total number of chocolates:"<<endl;
    while(q!=0)
    {
        sum+=q;
        r+=q%3;
        q=q/3;

    }
  sum+= r/3;

    {
        cout<<sum;
    }


    return 0;
}
