#include <iostream>
#include <vector>

using namespace std;

int main()
{  int row;
    cin>>row;
    vector<vector<int>> v(row,vector<int>(row));
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j== i)
            {
                v[i][j]=1;
            }
          else if(j>0 && j< i)
          {
              v[i][j]=v[i-1][j-1]+v[i-1][j];
          }
        }
    }
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<i+1;j++)
        {
          cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
