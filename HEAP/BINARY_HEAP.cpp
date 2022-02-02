// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;
void swap(int*x,int*y);

class MIN_HEAP
{
    int* arr;
    int cap;
    int heap_size;
    public:
    MIN_HEAP(int cap);
    void MIN_HEAPIFY(int);
    int parent(int i)
    {
        return (i - 1)/2;
    }
    int left(int i)
    {
        return (2*i + 1);
    }
    int right(int i)
    {
        return (2*i + 2);
    }
    int EXTRACT_MIN();
    void DECREASE_KEY(int i,int new_val);
    int GET_MIN()
    {
        return arr[0];
    }
    void DELETE_KEY(int i);
    void INSERT_KEY(int k);
    
};

MIN_HEAP::MIN_HEAP(int cap1)
{
    heap_size=0;
    cap=cap1;
    arr = new int[cap1];
}
void MIN_HEAP::INSERT_KEY(int k)
{
    cout<<"_____________________________"<<endl;
    cout<<"INSIDE INSERT_KEY -->"<<endl;
    if(heap_size==cap)
    {
        cout<<"OverFlow:Cannot Insert!"<<endl;
        return;
    }
    heap_size++;//heapsize increased
    int i=heap_size - 1;//i is the last place 
    arr[i]=k;
    
    while(i!=0 && arr[parent(i)]>arr[i])
    {
        //agar parent bada huaa inserted value se to swap karo
        cout<<"Swap funtion called -->"<<endl;
        cout<<"arr[i] = "<<arr[i]<<" i = "<<i<<endl;
        cout<<"arr[parent(i)] = "<<arr[parent(i)]<<" i = "<<parent(i)<<endl;
        swap(&arr[i],&arr[parent(i)]);
        cout<<"now i = parent(i) : "<<parent(i)<<endl;
        i=parent(i);
    }
    cout<<"_____________________________"<<endl;
}
void MIN_HEAP::DECREASE_KEY(int i,int new_val)
{
    cout<<"_____________________________"<<endl;
    cout<<"INSIDE DECREASE_KEY -->"<<endl;
    cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    cout<<"new_val = "<<new_val<<endl;
    arr[i]=new_val;
    while(i!=0 && arr[parent(i)]>arr[i])
    {
        cout<<"Swap funtion called -->"<<endl;
        cout<<"arr[i] = "<<arr[i]<<" i = "<<i<<endl;
        cout<<"arr[parent(i)] = "<<arr[parent(i)]<<" i = "<<parent(i)<<endl;
        
        swap(&arr[i],&arr[parent(i)]);
        cout<<"now i = parent(i) : "<<parent(i)<<endl;
        i=parent(i);
    }
    cout<<"_____________________________"<<endl;
}
int MIN_HEAP::EXTRACT_MIN()
{
    cout<<"_____________________________"<<endl;
    cout<<"INSIDE EXTRACT_MIN -->"<<endl;
    if(heap_size<=0)
    {
        return INT_MAX;
    }
    if(heap_size==1)
    {
        heap_size--;
        return arr[0];
    }
    
    int root=arr[0];
    cout<<"root = arr[0] : "<<root<<endl;
    arr[0]=arr[heap_size - 1];//last element 0th pos me daaldiya
    cout<<"arr[0] = arr[heap_size - 1] : "<<arr[0]<<endl;
    cout<<"heap_size before : "<<heap_size<<endl;
    heap_size--;//arr ka size kam kar diya
    cout<<"heap_size after : "<<heap_size<<endl;
    cout<<"MIN_HEAPIFY CALLED : "<<endl;
    MIN_HEAPIFY(0);//min heapify bula liya
    cout<<"root returned : "<<root<<endl;
    cout<<"_____________________________"<<endl;
    return root;
}
void MIN_HEAP::DELETE_KEY(int i)
{
    cout<<"_____________________________"<<endl;
    cout<<"INSIDE DELETE_KEY -->"<<endl;
    cout<<"DECREASE_KEY CALLED -->"<<endl;
    DECREASE_KEY(i,INT_MIN);
    cout<<"EXTRACT_MIN CALLED -->"<<endl;
    EXTRACT_MIN();
    cout<<"_____________________________"<<endl;
}
void MIN_HEAP::MIN_HEAPIFY(int i)
{
    int l=left(i);
    int r=right(i);
    int smallest =i;
    if(l<heap_size && arr[l]<arr[i])
    {
        smallest=l;
    }
    if(r<heap_size && arr[r]<arr[smallest])
    {
        smallest=r;
    }
    if(smallest !=i)
    {
        swap(&arr[i],&arr[smallest]);
        MIN_HEAPIFY(smallest);
    }
}

void swap(int *x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main() {
   MIN_HEAP h(10);
   h.INSERT_KEY(3);
   h.INSERT_KEY(1);
   h.INSERT_KEY(2);
   h.INSERT_KEY(4);
   h.INSERT_KEY(0);
   h.DELETE_KEY(3);
  
   

    return 0;
}
/*
/tmp/sCdP03GxJv.o
_____________________________
INSIDE INSERT_KEY -->
_____________________________
_____________________________
INSIDE INSERT_KEY -->
Swap funtion called -->
arr[i] = 1 i = 1
arr[parent(i)] = 3 i = 0
now i = parent(i) : 0
_____________________________
_____________________________
INSIDE INSERT_KEY -->
_____________________________
_____________________________
INSIDE INSERT_KEY -->
_____________________________
_____________________________
INSIDE INSERT_KEY -->
Swap funtion called -->
arr[i] = 0 i = 4
arr[parent(i)] = 3 i = 1
now i = parent(i) : 1
Swap funtion called -->
arr[i] = 0 i = 1
arr[parent(i)] = 1 i = 0
now i = parent(i) : 0
_____________________________
_____________________________
INSIDE DELETE_KEY -->
DECREASE_KEY CALLED -->
_____________________________
INSIDE DECREASE_KEY -->
arr[3] = 4
new_val = -2147483648
Swap funtion called -->
arr[i] = -2147483648 i = 3
arr[parent(i)] = 1 i = 1
now i = parent(i) : 1
Swap funtion called -->
arr[i] = -2147483648 i = 1
arr[parent(i)] = 0 i = 0
now i = parent(i) : 0
_____________________________
EXTRACT_MIN CALLED -->
_____________________________
INSIDE EXTRACT_MIN -->
root = arr[0] : -2147483648
arr[0] = arr[heap_size - 1] : 3
heap_size before : 5
heap_size after : 4
MIN_HEAPIFY CALLED : 
root returned : -2147483648
_____________________________
_____________________________
*/
