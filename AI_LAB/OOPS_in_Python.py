print("Oops in Python Yay!")
# -------------------------------------------------------------
# --CLASS--
# name of Car should be capital
class Car :
    wheels = 4  # class variable
    # we can change class variables and it will be applicable to all
    # below is constructor
    def __init__(self,make,model,year,color):
        self.make = make    # instance variables
        self.model = model  # instance variables
        self.year = year    # instance variables
        self.color = color  # instance variables
    def drive(self):
        print(self.model +" is driving !")
    def stop(self):
        print(self.model +" stopped !")
# -------------------------------------------------------------
# --OBJECTS--
car1 = Car('Chevy',"corvettete",2021,"blue")
print("car1 properties : ")
print(car1.make)
print(car1.model)
print(car1.year)
print(car1.color)
car1.drive()
car1.stop()
car1 = Car('AAAA',"aaa",2022,"red")
# -------------------------------------------------------------
# --INHERITANCE--
class Animal:
    alive = True

    def eat(self):
        print("This animal is eating")

    def sleep(self):
        print("This animal is sleeping")

class Rabbit(Animal):
    def hop(self):
        print("rabbit running")
class Fish(Animal):
    def swim(self):
        print("fish swim")
class Hawk(Animal):
    def fly(self):
        print("fly hwak")
rabbit = Rabbit()
fish = Fish()
hawk = Hawk()
print(rabbit.alive)  # inheritance from Animal
print(fish.eat())  # inheritance from Animal
print(hawk.sleep())  # inheritance from Animal
rabbit.hop()
fish.swim()
hawk.fly()
# -------------------------------------------------------------
# --MULTI-LEVEL-INHERITANCE--
class Organism:
    alive = True
class Animal(Organism):
    def eat(self):
        print("eat")
class Dog(Animal):
    def bark(self):
        print("bark")
    def eat(self):
        print("dog is eating")
dog = Dog()
# print(dog)
print(dog.alive)
dog.eat()
dog.bark()
# -------------------------------------------------------------
# --MULTIPLE-INHERITANCE--
class Prey:
    def flee(self):
        print("this animal flees")
class Predator:
    def hunt(self):
        print("animal hunts")
class Rabbit(Prey):
    pass
class Hawk(Predator):
    pass
class Fish(Prey,Predator):
    pass
r = Rabbit()
h = Hawk()
f = Fish()
r.flee()
h.hunt()
f.hunt()
f.flee()
# -------------------------------------------------------------
# --METHOD OVERRIDING--
class Animal:

    def eat(self):
        print("eating")
class Rabbit(Animal):
    def eat(self):
        print("rabbit eating carrot")
rabbit = Rabbit()
rabbit.eat()
# -------------------------------------------------------------
# --METHOD CHAINING--
class Car:
    def turn_on(self):
        print("Engine Started!")
        return self
    def drive(self):
        print("You are Driving...")
        return self
    def brake(self):
        print("Brake Applied!")
        return self
    def turn_off(self):
        print("Engine Turned Off.")
        return self
car = Car()
car.turn_on().drive()
car.brake().turn_off()
print("----------")
car.turn_on()\
    .drive()\
    .brake()\
    .turn_off()
# -------------------------------------------------------------
# --SUPER FUNCTION--
# super() = function used to give access to the methods of a parent
#           class.It Returns a temporary object of a parent class when used
class Rectangle:
    def __init__(self,length,width):
        self.length = length
        self.width = width
class Square(Rectangle):
    def __init__(self,length,width):
        super().__init__(length,width)

    def area(self):
        return self.length * self.width
class Cube(Rectangle):

    def __init__(self,length,width,height):
        # self.length = length
        # self.width = width
        super().__init__(length, width)
        self.height = height

    def volume(self):
        return self.length * self.width *self.height

square = Square(3,3)
cube = Cube(4,4,4)
print(square.area())
print(cube.volume())
# -------------------------------------------------------------
# --ABSTRACT CLASS--
# prevents user from creating an object of that class
# compels a user to override abstract methods in a child class
# abstract class = contains one or more abstract class
# abstract method = method that has declaration only and no implementation
# abc = abstract base class
# from abc import ABC,abstractmethod
class Vehicle(ABC):
    # we need atleast 1 abstract method in abstract class
    @abstractmethod
    def go(self):
        pass
    @abstractmethod
    def stop(self):
        pass
class Car(Vehicle):
    def go(self):
        print("You drive car")
    def stop(self):
        print("Car stopped")
class Cycle(Vehicle):
    def go(self):
        print("Ride Cycle")
    def stop(self):
        print("Cycle stopped")
# vehicle = Vehicle() # we cannot object of ghost/abstract class
car = Car()
cycle = Cycle()
car.go()
cycle.go()
car.stop()
cycle.stop()
# -------------------------------------------------------------
# --OBJECTS AS ARGUMENTS--
class Car:
    color = None
class Cycle:
    color = None
# this function is not inside Car class
# so we have to provide that object to assign its attributes
def change_color(car,color):
    car.color = color
car1 = Car()
car2 = Car()
car3 = Car()
cycle1 = Cycle()
change_color(car1,"red")
change_color(car2,"yellow")
change_color(car3,"blue")
change_color(cycle1,"orange")
print(car1.color)
print(car2.color)
print(car3.color)
print("cycle color : "+ cycle1.color)
# -------------------------------------------------------------
# --DUCK TYPING--
# concept where class of an object is less than the methods/attributes
# class type is not checked if minimum methods/attributes are present
# if it walks like a duck , talk like a duck then its a duck
class Duck:
    def walk(self):
        print("Duck Walking")
    def talk(self):
        print("Duck talking")
class Chicken:
    def walk(self):
        print("Chicken Walking")
    def talk(self):
        print("Chicken talking")
class Cock:
    def walk(self):
        print("Cock Walking")

class Person :
    def catch(self,duck):
        duck.walk()  # if the class contains these functions it will run else gives error
        duck.talk()
        print("you caught the creature")
duck = Duck()
chicken = Chicken()
cock = Cock()
person = Person()
person.catch(duck)
person.catch(chicken)
person.catch(cock) # AttributeError: 'Cock' object has no attribute 'talk'
# -------------------------------------------------------------
# --WALRUS OPERATOR--
foods = []
while True:
    food = input("What food do you want to add ? --> ")
    if food =="quit":
        break
    foods.append(food)
print(foods)
foods = []
while food := input("What food you want ? : ") != "quit":
    foods.append(food)
print(foods)
# -------------------------------------------------------------
# --ASSIGN FUNCTION TO VARIABLES--
def hello():
    print("hello")
print(hello)
hi = hello
hi()

say = print
say("hiiiii")
say(1+1)
# -------------------------------------------------------------
# --HIGH ORDER FUNCTIONS--
# 1.accept funtion as argument
# 2.return a function
def loud(text):
    return text.upper()
def quiet(text):
    return text.lower()
def hello(func): # function that accepts function as an argument
    text = func("Hello")
    print(text)
hello(loud)
hello(quiet)

def divisor(d):
    def dividend(n):
        return n/d
    return dividend # divisor in a HOF that returns dividend function

divide = divisor(2)
print(divide)
print(divide(10))
# -------------------------------------------------------------
# --LAMDA FUNCTIONS--
# lamda parameters:expression
def double(x):
    return x*2
print(double(2))
# --------
double = lambda x : x * 2
multiply = lambda x,y:x*y
add = lambda x,y,z:x+y+z
full_name = lambda first,last: first+" "+last
age_check = lambda age : True if age>=18 else False
print(double(5))
print(multiply(4,9))
print((add(10,20,30)))
print(full_name("Aditi","Mahabole"))
print(age_check(12))
print(age_check(20))
# -------------------------------------------------------------
# --SORT--
# sort() method = used with lists
# sort() function = used with iterables
# sort method cannot be applicable to tuple ...only to lists
# ------
students = ["one","two","three","four","five","for"]
students.sort(reverse = True)
for i in students:
    print(i)
# ------
# | sorting for tuples |
students = ("one","two","three","four","five","for","apple")
# students.sort(reverse = True) # will not work
sorted_students = sorted(students,reverse=True)
for i in sorted_students:
    print(i)
# ------
# | sorting for list of tuples |
student = [("pikachu","A",60),
           ("raichu","A",65),
           ("bulbasaur","B",50),
           ("squirtule","F",25),
           ("togepi","C",35)
           ]
student.sort()
for i in student:
    print(i)
marks = lambda student: student[2]
grade = lambda student: student[1]
student.sort(key = marks)
for i in student:
    print(i)
# ------
# | sorting for tuple of tuples |
student = (("pikachu","A",60),
           ("raichu","A",65),
           ("bulbasaur","B",50),
           ("squirtule","F",25),
           ("togepi","C",35)
           )
marks = lambda student: student[2]
grade = lambda student: student[1]
# students.sort(key = age)
sorted_student = sorted(student, key = marks, reverse=True)
for i in sorted_student:
    print(i)
# -------------------------------------------------------------
# --MAP--
# map() = applies a function to each item in an iterable (list,tuple,etc)
# map(function,iterable)
store = [("shirt",20.00),
         ("pants",35.00),
         ("jacket",50.00),
         ("socks",10.00)
         ]
# 1 dollar = 62 rupees assuming
to_rupee = lambda data: (data[0],data[1]*62)
store_rupees = list(matp(to_rupee,store))
for i in store_rupees:
    print(i)
# -------------------------------------------------------------
