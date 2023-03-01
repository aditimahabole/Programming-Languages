# __https://youtu.be/4XZoVQOt-0I__
import random 
import math
def fun(x,y,z):
    return x+y+z -25
def fitness(x,y,z):
    ans = fun(x,y,z)
    # ranking
    if(ans == 0):
        return 99 #very good
    else: 
        return abs(1/ans)
        # return math.floor(abs(1/ans))
        #smaller the denominator bigger the result
        #we will get a high number when sorting and higer is better
#generate solutions 
sol = []
for s in range(50):
    # sol.append((random.uniform(0,10000),random.uniform(0,10000),random.uniform(0,10000)))
    sol.append((random.randint(0,50),random.randint(0,50),random.randint(0,50)))
print("----1st 5 solutions are  ---- ")
for i in range(0,5):
    print(sol[i])
print("----Ranked Solutions ---- ")
for i in range(10):
    ranked_sols = []
    for s in sol:
        ranked_sols.append((fitness(s[0],s[1],s[2]),s))
    ranked_sols.sort()
    ranked_sols.reverse()
    print(f"=== Gen {i} best solutions ===")
    for m in range(0,3):
        print("%.2f" %ranked_sols[m][0])
        print(ranked_sols[m][1])
        print("-------------------------")
        
    if ranked_sols[0][0]>99:
        break
    
    best_sols = ranked_sols[0:5]
    elements = []
    for ele in best_sols:
        elements.append(ele[1][0])
        elements.append(ele[1][1])
        elements.append(ele[1][2])
    new_gen = []
    for i in range(100):
       e1 = random.choice(elements) *random.uniform(0.99,1.01)
       e2 = random.choice(elements) *random.uniform(0.99,1.01)
       e3 = random.choice(elements) *random.uniform(0.99,1.01)
       
       new_gen.append((e1,e2,e3))
    sol = new_gen
    
        
        
    
    
        
    
    
