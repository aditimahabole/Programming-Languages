# -----------------------------------------------
# BASIC PYTHON SYNTAX 
import time
# -----------------------------------------------
# --math--
import math
pi = 3.14
po = -3.4
print(round(pi))
print(math.ceil(pi))
print(math.floor(pi))
print(abs(po))
print(pow(pi,2))
print(math.sqrt(196))
a=1
b=2
c=3
d=4
print(max(a,b,c,d,10))
print(min(-2,-1,a,b))
# -----------------------------------------------
# --string methods --
name = "aditiiii@"
print(name)
print(len(name))
print(name.find("i"))
print(name.capitalize())
print(name.isdigit())
print(name.isalpha())
print(name.count("i"))
print(name.replace("i","7"))
# -----------------------------------------------
# --string slice --
# [start:stop:step]
name = "aditi mahabole"
first_name = name[0:5:3]
print(first_name)
reverse = name[::-1]
print(reverse)
# slice()
website = "http://google.com"
wiki = "http://wiki.com"
sli= slice(7)
print(website[sli])
print(wiki[sli])
print(sli)
# http://
# http://
# slice(None, 7, None)
l = len(wiki)
sl = slice(7,l)
print(wiki[sl])
print(sl)
# -----------------------------------------------
# --while loops -> unlimited--
name = ""
while len(name) == 0 or (name[0] == ' '):
    name = input("enter your name : ")
print("hello " + name)
# --for loops -> limited--
for i in range(10):
    print(i)
for i in range(40,45):
    print(i)
for i in "Aditi mahabole":
    print(i)
for sec in range(3,0,-1):
    print(sec)
    time.sleep(1)
print("happy new year !!!!")
# -----------------------------------------------
# --nested loops--
row = int(input("Rows : "))
col = int(input("Cols : "))
symbol = input("Symbol to use : ")
for i in range(row):
    for j in range(col):
        print(symbol , end = "")
        # prevent moving down to next line
    print()
# -----------------------------------------------
# --loop control statements--
# break
# continue
# pass
while True:
    name = input("enter name")
    if name != "":
        break
phone_num = "123-234-456"
for i in phone_num:
    if i == "-":
        continue
    print(i)
for i in range(1 , 21):
    if(i == 13):
        pass
    else:
        print(i)
# -----------------------------------------------
# --lists--
food = ["pizza", "burger", "fries"]
print(food)
food[0]="kadai paneer"
for x in food:
    print((x))
food.append("momos")
for x in food:
    print((x))
food.remove("burger")
for x in food:
    print((x))
food.pop() # delete last element
food.insert(5,"chilli chicken")
food.insert(5,"pasta roll")
food.append("spring rolls")
food.sort()
food.clear()
for x in food:
    print((x))
lis = [1,"2",2.0]
print(lis)
# -----------------------------------------------
# --tuples--
student = ("bro",21,"male")
print(student.count(21))
print(student.index("male"))
for x in student:
    print(x)
if "bro" in student:
    print("hi bro")
# -----------------------------------------------
# --sets--
box = {"fork","spoon","knife","knife","salt"}
box1 = {"bowl","plate","cup","salt","fork"}
for x in box:
    print(x)
print("--------")
# box.add("napkin")
# box.remove("fork")
for x in box:
    print(x)
print("--------")
# box.update(box1)
for x in box:
    print(x)
print("--------")
dinner = box.union(box1)
for x in dinner:
    print(x)
print("--------")
print(box.difference(box1))
print(box.intersection(box1))
# -----------------------------------------------
# --dictionary--
capitals = {'Usa':"washington DC",
            "india":"New delhi",
            "china":"Beijing"}
print(capitals["germany"]) # this will give error
print(capitals.get('germany')) # safer way
print(capitals.get('Usa'))
print(capitals.get('USA'))
print(capitals.keys())
print(capitals.values())
print(capitals.items())
for key, val in capitals.items():
    print(key + "-->" +val)
print("--------")
capitals.update({"Gernamy":"berlin"})
for key, val in capitals.items():
    print(key + "-->" +val)
print("--------")
capitals.update({'Usa':"LA"})
for key, val in capitals.items():
    print(key + "-->" +val)
print("--------")
capitals.pop("china")
for key, val in capitals.items():
    print(key + "-->" +val)
# -----------------------------------------------
# --index operator--
# [] = give access to a sequence's elemnt (str,list,tuples')
name = "aditi mahabole"
if(name[0].islower()):
    name = name.capitalize()
print(name)
first = name[0:5].upper()
print(first)
# -----------------------------------------------
# --function--
def repeat():
    print("hello")
    return 0
print(repeat())
# -----------------------------------------------
# --keyword arguments--
def hello(f,m,l):
    print("hello " + f + " " + m + " " + l)
hello(l = "Mahabole",f= "Aditi",m = "Kiran")
# -----------------------------------------------
# --*args--
parameter that will pack all arguments into a tuple
def add(*what):
    sum = 0
    # what[0] = 0 #cant do this caz tuple cannot be changed
    # so type cast it into list
    what = list(what)
    what[0] = 20
    for i in what:
        sum+=i
    return sum
print(add(1,2,3,4,5,6,10))
# -----------------------------------------------
# --**kwargs--
# parameter will unpack all arguments into a dictionary
def hello(**kwargs):
    print("hey "+kwargs['first'] + " " + kwargs['middle'] + " "+kwargs['last'])
    for key,val in kwargs.items():
        print(key+" ---> "+val)
    for key,val in kwargs.items():
        print(val,end=" ")
hello(title = "Ms.",first="Aditi",middle="Kiran",last="mahabole")
# -----------------------------------------------
# --str.format()--
animal = "cow"
item = "moon"
print("The {} jumped over the {}".format(animal,item))
first_name = input("Your first name ? ")
last_name = input("Your Last name ?")
print("Hello {} {}".format(first_name,last_name))
print("Hello {1} {0}".format(first_name,last_name))
print("Hello {first_name} {last_name}".format(first_name = "Molshree",last_name = "Sharma"))
name = "alibaba"
print("hello {}.and chalis chor".format(name));
print("hello {:10}.and chalis chor".format(name));
print("hello {:<10}.and chalis chor".format(name)); # left align
print("hello {:>10}.and chalis chor".format(name)); # right align
print("hello {:^10}.and chalis chor".format(name)); # center align
num = 3.14159
num1 = 15
num2 = 12345678
phone = 9582348585
print("pi is {:.2f}".format(num))
print("pi is {:.3f}".format(num))
print("pi is {:,}".format(num1)) # :, will add , at 1000s place
print("pi is {:,}".format(num2))
print("commas at 1000s place {:,}".format(phone))
print("binary {:b}".format(num1))
print("octal {:o}".format(num1))
print("hexa {:x}".format(num1))
print("scientific notation {:e}".format(num1))
temp = "{:b}".format(num1)
print(int(temp))
temp = int(temp) + 1
print("your",temp)
# -----------------------------------------------
--random--
import random
x = random.randint(1,10)
y = random.random()
my = ['stone','paper','scissors']
z = random.choice(my)
print(z)
cards = [1,2,3,4,5,6,7,8,9,"J","Q","K","A"]
random.shuffle(cards)
print(cards)
random.shuffle(cards)
print(cards)
random.shuffle(cards)
print(cards)
# -----------------------------------------------
# --exception handling--
n = int(input("enter numerator : "))
d = int(input("enter denominator : "))
ans = n/d
# if d = 0 then error will occur so to avoid we use try exception
print(ans)
try:
    n = int(input("enter numerator : "))
    d = int(input("enter denominator : "))
    ans = n / d
except ZeroDivisionError as z:
    print(z)
    print("you cant divide by 0")
except ValueError as v:
    print(v)
    print("Enter a number please")
except Exception as e:
    print(e)
    print("something went wrong")
else:
    print(ans)
finally:
    print("always execute")
# -----------------------------------------------
# --operating-system--
import os
path1 = "C:\\Users\\ADITI KIRAN MAHABOLE\\Desktop\\Python\\text.txt"
if(os.path.exists(path1)):
    print("located")
    if os.path.isfile(path1):
        print("file hai")
    if os.path.isdir(path1):
        print("dir hai")
else:
    print("not located")
# -----------------------------------------------
# --reading file--
file_path = "C:\\Users\\ADITI KIRAN MAHABOLE\\Desktop\\Python\\text.txt"
try:
    with open(file_path) as file:
        print(file.read())
    print(file.closed)
except FileNotFoundError:
    print("file does not exist :(")
# -----------------------------------------------
# --writing file--
file_path = "C:\\Users\\ADITI KIRAN MAHABOLE\\Desktop\\Python\\text.txt"
text = "Have a nice day!"
text2 = input("Write something")
with open(file_path,'w') as file:
    file.write(text)
with open(file_path,'a') as file:
    file.write(text2)
#  --copying file in python --
import shutil
shutil.copyfile('text.txt','copy.txt')
# -----------------------------------------------
