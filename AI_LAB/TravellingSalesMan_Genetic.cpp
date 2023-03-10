// ---------------------------------------------------------
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define V 5
#define START 0
#define POP_SIZE 10
#define GENES ABCDE
// ---------------------------------------------------------
struct individual
{
    string gnome;
    int fitness;
};
// ---------------------------------------------------------
//generating random number among Vertex 
int generate_random_number(int start , int end)
{
    int range = end - start;
    int num = start + rand()% range;
    return num ;
}
// ---------------------------------------------------------
//checking if repeated value generated or not from above func
bool repeat(string s, char c)
{
    for(int i=0;i<s.size();i++) if(s[i] == c) return true;
    return false;
}
// ---------------------------------------------------------
//---creating genome---
string create_gnome()
{
    
    string gnome = "0";
    while(true)
    {
        if(gnome.size() == V)
        {
            gnome+=gnome[0];
            cout<<"gnome created : "<<gnome<<endl;
            break;
        }
        int temp = generate_random_number(1,V);
        if(repeat(gnome, char(temp + 48)) == false)
        {
            gnome +=char(temp + 48);
        }
    }
    cout<<"create gnome done"<<endl;
    return gnome;
}
// ---------------------------------------------------------
// calculating fitness value 
int cal_fitness(string gnome)
{
    int map[V][V] =
    {
        { 0, 2, INT_MAX, 12, 5 },
        { 2, 0, 4, 8, INT_MAX },
        { INT_MAX, 4, 0, 3, 3 },
        { 12, 8, 3, 0, 10 },
        { 5, INT_MAX, 3, 10, 0 }
     }; 
     int fit =0;
     // 0->1->2->3->4->0
     for(int i = 0;i<gnome.size() - 1;i++)
     {
         if(map[gnome[i] - 48][gnome[i + 1] - 48] == INT_MAX)
         return INT_MAX;
         fit+=map[gnome[i] - 48][gnome[i+1]-48];
     }
     return fit;
}
// ---------------------------------------------------------
//sorting function 
bool less_value(struct individual i1,struct individual i2)
{
    return i1.fitness<i2.fitness;
}
// ---------------------------------------------------------
//mutate gene using swapping
string mutate_gene(string gnome)
{
    while(true)
    {
        int index1 = generate_random_number(1,V);
        int index2 = generate_random_number(1,V);
        if(index1!=index2)
        {
            char temp     = gnome[index1];
            gnome[index1] = gnome[index2];
            gnome[index2] = temp;
            break;
        }
    }
    return gnome;
}
// ---------------------------------------------------------
//cooling down temp
int cooldown(int temp)
{
    return (90*temp)/100;
}
// ---------------------------------------------------------
//travelling sales man 
void TSP(int map[V][V])
{
    //------------------------------------------------
    int gen_num = 1;
    int gen_loops = 5;
    vector<struct individual> population;
    struct individual temp;
    //------------------------------------------------
    //----Population-----
    for(int i=0;i<POP_SIZE;i++)
    {
        temp.gnome = create_gnome();
        temp.fitness = cal_fitness(temp.gnome);
        population.push_back(temp);
    }
    //------------------------------------------------
    //printing initial population 
    cout<<"--Initial Population--"<<endl;
    cout<<"Gnome      |    Fitness"<<endl;
    for(int i=0;i<POP_SIZE;i++)
    {
        cout<<population[i].gnome<<"          "<<population [i].fitness<<endl;
    }
    cout<<endl;
    //------------------------------------------------
    bool found = false;
    int temperature = 10000;
    while(temperature> 1000 && gen_num<=gen_loops)
    {//--> while loop start
    
    //sorting popupation lesser length more the fitness
    sort(population.begin(),population.end(),less_value);
    cout<<"--Sorted Population--"<<endl;
    cout<<"Gnome      |    Fitness"<<endl;
    for(int i=0;i<POP_SIZE;i++)
    {
        cout<<population[i].gnome<<"          "<<population [i].fitness<<endl;
    }
    cout<<endl;
    //------------------------------------------------
    //taking best fit values in new_pop
    vector<struct individual>new_population;
    for(int i=0;i<POP_SIZE;i++)
    {//for --> start
        struct individual i1 = population[i];
        //mutating till we get good fitness than prev parent
        while(true)
        { //-->
            string mutated_gene = mutate_gene(i1.gnome);//swaping
            struct individual new_gnome;
            new_gnome.gnome = mutated_gene;
            new_gnome.fitness = cal_fitness(new_gnome.gnome);
            if(new_gnome.fitness<=population[i].fitness)
            {
                new_population.push_back(new_gnome);
                break;
            }
            else 
            {
                //accepting if propb is above threshold
                float p = pow(2.7,
                -1*(
                    (float)
                    (new_gnome.fitness - population[i].fitness)/
                    temperature
                    )
                );
                if(p>0.5)
                {
                    new_population.push_back(new_gnome);
                    break;
                }
            }
        } //<--
    }// for <-- end
    
    //cooling temperature
    temperature = cooldown(temperature);
    population = new_population;
    cout<<"--Generation--"<<endl;
    cout<<"Gnome      |    Fitness"<<endl;
    for(int i=0;i<POP_SIZE;i++)
    {
        cout<<population[i].gnome<<"          "<<population [i].fitness<<endl;
    }
    cout<<endl;
    gen_num++;
    
    } // <--while loop end
    cout<<"TSP working"<<endl;
}
// ---------------------------------------------------------
int main()
{
    int map[V][V] =
    {
        { 0, 2, INT_MAX, 12, 5 },
        { 2, 0, 4, 8, INT_MAX },
        { INT_MAX, 4, 0, 3, 3 },
        { 12, 8, 3, 0, 10 },
        { 5, INT_MAX, 3, 10, 0 }
     };
     TSP(map);
    cout<<"yay"<<endl;
    return 0;
}
// ---------------------------------------------------------
