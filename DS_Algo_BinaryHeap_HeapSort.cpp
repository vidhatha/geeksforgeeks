#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MinHeap
{
    int no_of_elem; //no of elements
    int max_size;
    vector<int> minheaparr;
    
    public:
    MinHeap(int max_size);
    int parent(int c);
    int left_child(int p);
    int right_child(int p);
    void insertKey(int element);
    void bubble_up(int element);
    int extract_min();
    void heapify(int element);
    void deleteKey(int arrindex);
    void displayHeap();
    
    void heapsort();
};

MinHeap::MinHeap(int max) 
{
    no_of_elem = 0;
    max_size = max;
    minheaparr.resize(max_size);
}

int MinHeap::parent(int c)
{
    if(c==0)
        return -1;
    
    return (c-1)/2;
}

int MinHeap::left_child(int p)
{
    return 2*p+1;
}

int MinHeap::right_child(int p)
{
    return 2*p+2;
}
void MinHeap::bubble_up(int arrindex)
{
    if(parent(arrindex) == -1)
        return;
        
    int p = parent(arrindex);
    
    int c = arrindex;
    if(minheaparr[c]<minheaparr[p])
    {
        int temp = minheaparr[c];
        minheaparr[c] = minheaparr[p];
        minheaparr[p] = temp;
        bubble_up(p);
    }
}

void MinHeap::insertKey(int element)
{
    if(no_of_elem == max_size-1) {
        cout<<"Heap OverFlow"<<endl;
        return;
    }
    
    //add element at the end
    minheaparr[no_of_elem] = element;
    //Increment no of elements
    no_of_elem++;
    bubble_up(no_of_elem-1);
}



int MinHeap::extract_min()
{
    if(no_of_elem == 0) {
        cout<<"Heap UnderFlow"<<endl;
        return -1;
    }
    //Index starts at 0
    if(no_of_elem == 1) 
    {
        int min = minheaparr[0];
        no_of_elem--;
        return min;
    }

    int min = minheaparr[0];
    minheaparr[0] = minheaparr[no_of_elem-1];
    no_of_elem--;
    heapify(0);
    
    return min;
}

void MinHeap::heapify(int p)
{
    int l = left_child(p);
    int r = right_child(p);
    int smallest = p;
    if((l<no_of_elem) && (minheaparr[l] < minheaparr[smallest]))
        smallest = l;
    if((r<no_of_elem) && (minheaparr[r] < minheaparr[smallest]))
        smallest = r;
    if(smallest != p)
    {
        //swap smallest with p
        int temp = minheaparr[smallest];
        minheaparr[smallest] = minheaparr[p];
        minheaparr[p] = temp;
        
        heapify(smallest);
    }
        
}
void MinHeap::deleteKey(int arrindex) 
{
    minheaparr[arrindex] = -1;
    bubble_up(arrindex);
    extract_min();
}

void MinHeap::heapsort()
{
    int count = no_of_elem;
    for(int i=0;i<count;i++)
    {
        cout<<extract_min()<<" ";
    }
    cout<<endl;
}
void MinHeap::displayHeap()
{
    for(int i=0;i<no_of_elem;i++) {
        cout<<minheaparr[i]<<" ";
    }
    cout<<endl;
}
// Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.displayHeap();
    h.insertKey(2);
    h.displayHeap();
    //h.deleteKey(1);
    //h.displayHeap();
    h.insertKey(15);
    h.displayHeap();
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.displayHeap();
    cout<<"heapsort: "<<endl;
    h.heapsort();
    //h.displayHeap();
    //cout << "Extract MIN: "<<h.extract_min() << " "<<endl;
    //h.displayHeap();
    //cout << "Extract MIN: "<<h.extract_min() << " "<<endl;
    //h.displayHeap();
    //cout << h.getMin() << " ";
    //h.decreaseKey(2, 1);
    //cout << h.getMin();
    return 0;
}
