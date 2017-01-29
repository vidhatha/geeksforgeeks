#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

class MinHeap
{
    int no_of_elem; //no of elements
    int max_size;
    vector<long> minheaparr;
    
    public:
    MinHeap();
    int parent(int c);
    int left_child(int p);
    int right_child(int p);
    void heapify(int element,int k);
    void displayHeap();
    int kthLargestElem(int k);
};

MinHeap::MinHeap() 
{
    minheaparr.push_back(12);
    minheaparr.push_back(3);
    minheaparr.push_back(5);
    minheaparr.push_back(7);
    minheaparr.push_back(1);
    
    no_of_elem = minheaparr.size();
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


void MinHeap::heapify(int p,int k)
{
    cout<<"heapify"<<endl;
    displayHeap();
    int l = left_child(p);
    int r = right_child(p);
    int smallest = p;
    if((l<k) && (minheaparr[l] < minheaparr[smallest]))
        smallest = l;
    if((r<k) && (minheaparr[r] < minheaparr[smallest]))
        smallest = r;
    if(smallest != p)
    {
        //swap smallest with p
        int temp = minheaparr[smallest];
        minheaparr[smallest] = minheaparr[p];
        minheaparr[p] = temp;
        
        heapify(smallest,k);
    }
        
}

void MinHeap::displayHeap()
{
    for(int i=0;i<minheaparr.size();i++)
        cout<<minheaparr[i]<<" ";
    cout<<endl;
}

int MinHeap::kthLargestElem(int k) {
    
    //heapify 1st k elements
    for(int i=k/2-1;i>=0;i--) {
        heapify(i,k);
    }

    for(int i=k;i<minheaparr.size();i++) {
        int root= minheaparr[0];
        if(minheaparr[i]>root) {
            minheaparr[0]=minheaparr[i];
            heapify(0,k);
        }
    }
    
    return minheaparr[0];
}

// Driver program to test above methods
int main()
{
	MinHeap mh;
	int k = 1;
	cout << k<<"'th largest element is " << mh.kthLargestElem(k);
	return 0;
}
