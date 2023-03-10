// GIVEN PROBLEM
// Consider a card splitting exercise, which is as detailed here: You have 10 cards numbered 1 to 10
// and have to divide them into two piles so that: The sum of the first pile is as close as possible to 36 and
// the product of all in the second pile is as close as possible to 360. Solve this logic problem using GA.
// ---------------------------------------------------------
//LOGIC :
// I made a Card Structure  which contains strings sum_nums, it contains random numbers of which sum is calculated
// then we have mul_nums this is a string for which muliplication in calulated in this i took first 4 as random ans last i joined 10 withth e string
//because if we want 360 to 10 will be helpfull in multiplication
//then we have fitness value
// fitness is calculated by subtracting the calculated sum with Actual SUM that is 36 
//similar for mul-MUL MUL= 360
//so lesser the value will be better and closer it is to 36 and 360 
//so we cummuatively stored fitness val that is sum_err + mul_err , best one would be 0 + 0 that is exact ans
//after that 2 point crossover is done,which i think should not be done as values could be repeated in genere
//as supppose sum_num = 45789 , mul_nums = 123610 
//ans suppose other individaul has sum_nums = 95487 so while 2 point crossover offsrping me have identical geness like 45487 here
//4 4 which is illegal ... i am just telling you that you can change sum_nums with mul_nums 2 point crossover
// or you can you any other method
//so this was the intution
// ---------------------------------------------------------
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define POP 30
#define LEN 10
#define SUM 36
#define MUL 360
// ---------------------------------------------------------
struct Card
{
    string sum_nums;
    string mul_nums;
    float rank;
};
// ---------------------------------------------------------
//check repeated card numbers 
bool if_repeated(string s, char c)
{
    for(auto i : s) if(i==c) return true;
    return false;
}
//----------------------------------------------------------
//generating random numbers
int random_num(int start,int end)
{
    int range = end-start;
    int num = start + rand()%(range+1);
 
    return num;
}
// ---------------------------------------------------------
// creating pop for sum 
string create_sum_nums()
{
    string temp;
    while(true)
    {
        if(temp.size() == LEN/2)
        {
            break;
        }
        int num = random_num(1,LEN);
        if(char(num+48) == 58) continue;
        bool repeat = if_repeated(temp ,(char)(num + 48));
        if(repeat == false) temp += (char)(num  + 48);
    }
    // cout<<"create sum nums good "<<endl;
    return temp;
}
// ---------------------------------------------------------
//creating pop for multiplication 
string create_mul_nums(string sum_nums)
{
    string temp;
    while(true)
    {
        if(temp.size() == LEN/2 - 1)
        {
            break;
        }
        int num = random_num(1,LEN);
        if(char(num+48) == 58) continue;
        bool repeat = if_repeated(temp ,(char)(num  + 48));
        bool in_sum_nums = if_repeated(sum_nums ,(char)(num + 48));
        if(repeat == false && in_sum_nums == false) temp += (char)(num + 48);
    }
    temp +="10"; // adding number 10 to num caz it will lead to 360
    return temp;
}
// ---------------------------------------------------------
//calculating fitness function 
double fitness(string sums, string muls)
{
    int total_sum = 0;
    int total_mul = 1;
    for(int i=0;i<sums.size();i++)
    {
        total_sum+=int(sums[i]);
    }
    for(int i=0;i<4;i++)
    {
        total_mul*=int(muls[i]);
    }
    total_mul*=10; // multiplying last number ie 10
    //fitness value may vary
    //lesser the difference bw target and calculated better is the solution
    int sum_error = abs(total_sum - SUM);
    int mul_error = abs(total_mul - MUL);
    float fit = sum_error + mul_error;
    //closer to 0 best fit value
    return fit;
}
bool less_fitness(struct Card c1,struct Card c2)
{
    return c1.rank<c2.rank;
}
//two point cross over
string two_point_crossover(string s1,string s2)
{
    int point1 = 1;
    int point2 = 3;
    string temp = "";
    for(int i=0;i<s1.size();i++)
    {
        if(i>=point1 && i<=point2)
        {
            temp+=s2[i];
        }
        else
        temp+=s1[i];
    }
    return temp;
    
}
int main()
{
    vector<struct Card> card_population;
    struct Card single_card;
    for(int i=0;i<POP;i++)
    {
        single_card.sum_nums = create_sum_nums();
        single_card.mul_nums = create_mul_nums(single_card.sum_nums);
        single_card.rank = fitness(single_card.sum_nums,single_card.mul_nums);
        card_population.push_back(single_card);
    }
    //just added one of the correct answer 
    struct Card special_card;
    special_card.sum_nums = "45789";
    special_card.mul_nums = "123610";
    special_card.rank = fitness(special_card.sum_nums,special_card.mul_nums);
    card_population.push_back(special_card);
    
    cout<<"Initial Card Population"<<endl;
    for(int i=0;i<POP;i++)
    {
        cout<<"Gene "<<i+1<<endl;
        cout<<"sum_nums : "<<card_population[i].sum_nums<<endl;
        cout<<"mul_nums : "<<card_population[i].mul_nums<<endl;
        cout<<"fitness  : "<<card_population[i].rank<<endl;
        cout<<"----------------------------"<<endl;
    }
    int l = 10;
    while(l--)
    {
        sort(card_population.begin(),card_population.end(),less_fitness);
        cout<<"Sorted Card Population"<<endl;
        for(int i=0;i<card_population.size();i++)
        {
            cout<<"Gene "<<i+1<<endl;
            cout<<"sum_nums : "<<card_population[i].sum_nums<<endl;
            cout<<"mul_nums : "<<card_population[i].mul_nums<<endl;
            cout<<"fitness  : "<<card_population[i].rank<<endl;
            cout<<"----------------------------"<<endl;
        }
        vector<struct Card> new_pop;
        for(int i=0;i<10;i++)
        {
            struct Card card_offspring1;
            card_offspring1.sum_nums = two_point_crossover(
                card_population[i].sum_nums,
                card_population[i+1].sum_nums);
            card_offspring1.mul_nums = two_point_crossover(
                card_population[i].mul_nums,
                card_population[i+1].mul_nums);
            card_offspring1.rank = fitness(
                card_offspring1.sum_nums,
                card_offspring1.mul_nums);
            // -----------------------------------------
            struct Card card_offspring2;
            card_offspring2.sum_nums = two_point_crossover(
                card_population[i+1].sum_nums,
                card_population[i].sum_nums
                );
            card_offspring2.mul_nums = two_point_crossover(
                card_population[i+1].mul_nums,
                card_population[i].mul_nums
                );
            card_offspring2.rank = fitness(
                card_offspring2.sum_nums,
                card_offspring2.mul_nums);
            if(card_offspring1.rank < card_population[i].rank || card_offspring1.rank < card_population[i+1].rank )
            {
                new_pop.push_back(card_offspring1);
            }
            if(card_offspring2.rank <card_population[i].rank || card_offspring2.rank < card_population[i+1].rank )
            {
                new_pop.push_back(card_offspring2);
            }
        }
        card_population = new_pop;
        cout<<endl;
        cout<<"--Generation--"<<endl;
        for(int i=0;i<card_population.size();i++)
        {
            cout<<"Gene "<<i+1<<endl;
            cout<<"sum_nums : "<<card_population[i].sum_nums<<endl;
            cout<<"mul_nums : "<<card_population[i].mul_nums<<endl;
            cout<<"fitness  : "<<card_population[i].rank<<endl;
            cout<<"----------------------------"<<endl;
        }
    }
    return 0;
}
// ---------------------------------------------------------
