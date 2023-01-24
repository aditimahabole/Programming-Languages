# -------------------------------------------------------------------------------------------------
# EXERCISES
# 1. Define a function max() that takes two numbers as arguments and returns the largest of them. Use
# the if-then-else construct available in Python.

# 2. Define a function max_of_three() that takes three numbers as arguments and returns the largest of
# them.

# 3. Define a function that computes the length of a given list or string.

# 4. Write a function that takes a character (i.e. a string of length 1) and returns True if it is a
# vowel, False otherwise.

# 5. Write a function translate() that will translate a text into "rövarspråket" (Swedish for "robber's
# language"). That is, double every consonant and place an occurrence of "o" in between. For
# example, translate("this is fun")should return the string "tothohisos isos fofunon".

# 6. Define a function sum() and a function multiply() that sums and multiplies (respectively) all the
# numbers in a list of numbers. For example, sum([1, 2, 3, 4]) should return 10, and multiply([1, 2, 3,
# 4]) should return 24.

# 7. Define a function reverse() that computes the reversal of a string. For example, reverse("I am
# testing") should return the string "gnitset ma I".

# 8. Define a function is_palindrome() that recognizes palindromes (i.e. words that look the same written
# backwards). For example, is_palindrome("radar") should return True.

# 9. Define a procedure histogram() that takes a list of integers and prints a histogram to the screen. For
# example,histogram([4, 9, 7]) should print the following:
# ****
# *********
# *******

# 10. Write a program to compute the number of characters, words and lines in a file.

# 11. Write function to compute gcd, lcm of two numbers.

# 12. Find the sum of all the primes below 10000. Each new term in the Fibonacci sequence is generated
# by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be: 1, 2, 3, 5, 8, 13,
# 21, 34, 55, 89,...

# 13. Write a program to implement Merge sort.

# 14. Write a program to perform multiplication of two square matrices

# 15. Write a function ball_collide that takes two balls as parameters and computes if they are colliding.
# Your function should return a Boolean representing whether or not the balls are colliding.
# Hint: Represent a ball on a plane as a tuple of (x, y, r), r being the radius If (distance between two balls
# centers) <= (sum of their radii) then (they are colliding)

# --------------------------------------------------------------------------------------------------
# Q1
def returnmax(num1, num2):
    if (num1 > num2):
        print('The greater number is ', num1)
    elif (num2 > num1):
        print('the Greater number is ', num2)
    else:
        print('The numbers are equal')
def Main():
    n1 = int(input('Enter your first number'))
    n2 = int(input('Enter your second number'))
    returnmax(n1, n2)
if __name__ == '__main__':
    Main()
# ------------------------------------------
# Q2
def max_of_three(num1, num2, num3):
    if (num1 == num3 and num1 == num2):
        print('the numbers are equal')
    elif (num1 >= num2 and num1 >= num3):
        print('the greatest numer is ', num1)
    elif (num2 >= num1 and num2 >= num3):
        print('the greatest number is ', num2)
    elif (num3 >= num1 and num3 >= num2):
        print('the greatest number is ', num3)
if __name__ == "__main__":
    n1 = int(input('number 1'))
    n2 = int(input('number 2'))
    n3 = int(input('number 3'))
    max_of_three(n1, n2, n3)
# ------------------------------------------
# Q3
# ------------------------------------------
# Q4
def is_vowel(c):
    if(c == 'a' or c =='e' or c =='i' or c =='o' or c =='u' or c =='A' or c =='E' or c =='I' or c =='O' or c =='U'):
        return True
    return False
word = input("Enter something : ")
for i in word:
    print(i + " is a vowel ? " , is_vowel(i))
# ------------------------------------------
# Q5
def translate(word):
    new_word = ""
    for c in word:
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' or c==' '):
            new_word+=c

        else:
            new_word+=c+"o"+c
    return new_word
word = input("Enter a word : ")
print("Translated word is : "+translate(word))
# ------------------------------------------
# Q6
def sum(arr):
    sum = 0
    if len(arr) == 0: return 0
    for i in arr:
        sum+=int(i)
    return sum
def multiply(arr):
    mul = 1
    if len(arr) == 0: return 0
    for i in arr:
        mul*=i
    return mul
flag = 1
arr = []
print("To quit write e")
while(flag):
    flag = input("Wanna add ? ")
    if(flag == 'e'):
        break
    else:
        arr.append(int(flag))
print("Sum of Numbers : ",sum(arr))
# print("Multiplication of Numbers : ",multiply(arr))
# ------------------------------------------
# Q7
def reversal(word):
    return word[len(word)::-1]
word = input("Enter something buddy : ")
print(reversal(word))
# ------------------------------------------
# Q8
def is_palindrome(word):
    i=0
    j=len(word) - 1
    while(i<=j):
        if(word[i]!=word[j]):
            return False
        i+=1
        j-=1
    return True
word = input("Enter a word : ")
print("Lets check is the given word is palindrome or not --> ",is_palindrome(word))
word = input("Enter a word : ")
print("Lets check is the given word is palindrome or not --> ",is_palindrome(word))
# ------------------------------------------
# Q9
def histogram(arr):
    for i in arr:
        print("*"*i)
flag = 1
arr=[]
print("To quit write e")
while(flag):
    flag = input("Enter value : ")
    if flag == 'e':
        break
    else:
        arr.append(int(flag))
histogram(arr)
# ------------------------------------------
# Q10
file__IO ="LAB1.txt"
with open(file__IO, 'r') as f:
    data = f.read()
    print(data)
    line = data.splitlines()
    print(line)
    words = data.split()
    print(words)
    spaces = data.split(" ")
    charc = (len(data) - len(spaces))
print('\n Line number ::', len(line), '\n Words number ::', len(words), '\n Spaces ::', len(spaces), '\n Characters ::', (len(data)-len(spaces)))
# ------------------------------------------
# Q11
def gcd(a,b):
    if a==b:
        return a
    i = max(a,b)-1
    while(i>0):
        if(a%i == 0 and b%i == 0):
            return i
        i-=1
    return 1
def lcm(a,b):
    return (a*b)/gcd(a,b)
a = int(input( "First Number : "))
b = int(input("Second Number : "))
print("GCD of two given numbers is : ",gcd(a,b))
print("LCM of two given numbers is : ",lcm(a,b))
# ------------------------------------------
# Q12
def is_prime(num):
    if(num == 2 or num ==3 or num == 5 or num ==7 ):
        return True
    for i in range(2,num):
        if num%i == 0:
            return False
    return True
#------------------
def sum_prime(num):
    sum = 0
    for i in range(2,num):
        if is_prime(i) == True:
            sum+= i
    return sum
# #------------------
def fibonacci(num):
    arr=list()
    arr.append(1)
    arr.append(1)
    for i in range(2,num+1):
        arr.append(arr[i-1]+arr[i-2])
    return arr
num = int(input("Enter a number : "))
print("Fibonacci series till given num is : \n",fibonacci(num))
num1 = int(input("Enter a another number : "))
print("Sum of prime numbers till given num is : ",sum_prime(num1))
# ------------------------------------------
# Q13
# compiling broken parts
def merge_sort_compile(arr,start,mid,end):
    n1 = mid - start +1
    n2 = end - mid
    temp1 = [0]*(n1)
    temp2 = [0]*(n2)
    for i in range(0,n1):
        temp1[i] = arr[start + i]
    for j in range(0,n2):
        temp2[j] = arr[mid + 1 + j]
    i = 0
    j = 0
    it = start
    while i<n1 and j<n2:
        if temp1[i] <= temp2[j]:
            arr[it] = temp1[i]
            i+=1
        else:
            arr[it] = temp2[j]
            j += 1
        it+=1
    while i<n1:
        arr[it]=temp1[i]
        i+=1
        it+=1
    while j<n2:
        arr[it]=temp2[j]
        j+=1
        it+=1
# break into halves
def merge_sort_breakdown(arr,start,end):
    if(start< end ):
        mid = start + (end - start)//2
        merge_sort_breakdown(arr,start,mid)
        merge_sort_breakdown(arr,mid+1,end)
        merge_sort_compile(arr,start,mid,end)
flag = 1
arr = list()
print("To exit enter 0 ")
while(flag ):
    flag = int(input("Enter number to add : "))
    if flag == 0:
        break
    arr.append(flag)
print("Before Merge Sort : ",arr)
m = int(len(arr)) - 1
merge_sort_breakdown(arr,0,m)
print("After Merge Sort : ",arr)
# nlogn
# ------------------------------------------
# Q14
print("Keep in mind that to multiply col of Matrix should be equal to Row of Matrix 2")
row = 0
col = -1
row1 = 0
col1 =0
while(col!=row1):
    row = int(input("Enter number of rows for matrix 1: "))
    col = int(input("Enter number of columns for matrix 1 : "))
    row1 = int(input("Enter number of rows for matrix 2: "))
    col1 = int(input("Enter number of columns for matrix 2 : "))
    if col != row1 : print("Wrong input! do it again")

matrix1 = []
matrix2 = []
print("Enter entries row wise for Matrix 1 : ")
for i in range(row):
    temp = []
    for j in range(col):
        temp.append(int(input("Enter number for row " + str(i) + " : ")))
    matrix1.append(temp)
print("Enter entries row wise for Matrix 2 : ")
for i in range(row1):
    temp = []
    for j in range(col1):
        temp.append(int(input("Enter number for row " + str(i) + " : ")))
    matrix2.append(temp)
print("Matrix 1 : \n",matrix1)
print("Matrix 1 : \n",matrix2)
result_matrix = [[0]*row]*col1
for i in range(row):
    for j in range(col1):
        for k in range(row1):
            result_matrix[i][j]+= matrix1[i][k] * matrix2[k][j]
print("Matrix Multiplication Result : \n",result_matrix)
# ------------------------------------------
# Q15
import math
def are_colliding(ball1,ball2):
    diff_x = ball1[0] - ball2[0]
    diff_y = ball1[1] - ball2[1]
    value = (diff_x**2) + (diff_y**2)
    distance = math.sqrt(value)
    radi_distance = ball1[2]+ball2[2]
    if(distance<=radi_distance):return True
    else:return False
x1 = int(input("x coordinate of Ball 1 : "))
y1 = int(input("y coordinate of Ball 1 : "))
r1 = int(input("Radius of Ball 1 : "))
x2 = int(input("x coordinate of Ball 2 : "))
y2 = int(input("y coordinate of Ball 2 : "))
r2 = int(input("Radius of Ball 2 : "))
ball1 = (x1,y1,r1)
ball2 = (x2,y2,r2)
print("Are Ball 1 and Ball 2 colliding ? -->",are_colliding(ball1,ball2))
# ------------------------------------------
