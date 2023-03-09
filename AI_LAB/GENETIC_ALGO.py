// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ----------------------------------------------
struct Solution 
{
    double rank,x,y,z;
    void fitness()
    {
        double ans = (6*x +  -y +pow(z,200)) - 25;
        ans == 0 ? rank = 9999: rank = abs(1/ans);
        // cout<<"Rank Calculated : "<<rank<<endl;
        // more value lead to zero
    }
};
// ----------------------------------------------
int main()
{
    //----------------------------------------------------
    // create random solutions 
    random_device device;
    uniform_real_distribution<double> uniform(-100,100);
    vector<Solution> solutions;
    // 100000
    const int NUM = 10000;
    for( int i = 0;i<NUM;i++)
    solutions.push_back(Solution{0,
    uniform(device), //x
    uniform(device), //y
    uniform(device)  //z
    //values initialized between -10000 to 10000
    });
    //----------------------------------------------------
    while(true){
    // run fitness function
    cout<<"------Calculation Fitness------"<<endl;
    for(auto &s:solutions) s.fitness();
    //----------------------------------------------------
    //sorting based on fitness
    sort(solutions.begin(),solutions.end(),
    [](const auto& lhs,const auto&rhs)
    {
        return lhs.rank >rhs.rank;
    }
    );
    //----------------------------------------------------
    // print top solutions
    cout<<"------Top Solutions------"<<endl;
    for(int i=0;i<=5;i++)
    {
        cout<<"Rank : "<<solutions[i].rank<<endl;
        cout<<"x : "<<solutions[i].x<<endl;
        cout<<"y : "<<solutions[i].y<<endl;
        cout<<"z : "<<solutions[i].z<<endl;
    }
    //----------------------------------------------------
    //Take top solutions
    const int SAMPLE_SIZE = 50;
    vector<Solution>sample;
    // copy top 1000 solutions to sample
    for(int i=0;i<SAMPLE_SIZE;i++)
    {
        sample.push_back(solutions[i]);
    }
    // discarding other population
    solutions.clear();
    //----------------------------------------------------
    // Mutate top solutions
    uniform_real_distribution<double>m(0.99,1.01);
    // mutate by atmost 1 percent
    cout<<"------Doing Mutation------"<<endl;
    for(int i=0;i<sample.size();i++)
    {
        sample[i].x *= m(device);
        sample[i].y *= m(device);
        sample[i].z *= m(device);
        // changing values by 1 percent
    }
    //----------------------------------------------------
    //Cross Over 
    uniform_int_distribution<int> cross(0,SAMPLE_SIZE - 1);
    cout<<"------Doing CrossOver------"<<endl;
    for(int i=0;i<NUM;i++)
    {
        solutions.push_back(Solution{
            0,
            sample[cross(device)].x,
            sample[cross(device)].y,
            sample[cross(device)].z
        });
    }
    }
    cout<<"yay"<<endl;
    return 0;
}
