#include<iostream>
using namespace std;


void heapifymax(int arr[],int size,int lar);
void heapifymin(int arr[],int size,int small);
void buildMaxHeap(int arr[], int size){
    for(int i = size/2; i > 0; i--){
        heapifymax(arr, size, i);
    }
}
void buildMinHeap(int arr[], int size){
    for(int i = size/2; i > 0; i--){
        heapifymin(arr, size, i);
    }
}
void heapifymax(int arr[], int size, int lar){
    int largest = lar;
    int left = 2*lar;
    int right = 2*lar + 1;

    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != lar){
        swap(arr[lar],arr[largest]);
        heapifymax(arr,size,largest);
    }
}
void heapsortincreasing(int arr[], int size){
    buildMaxHeap(arr,size);
    int temp = size;
    while(temp > 1){
        swap(arr[temp],arr[1]);
        temp--;
        heapifymax(arr,temp,1);
    }
}


void heapifymin(int arr[], int size, int small){
    buildMinHeap(arr,size);
    
    int smallest = small;
    int left = 2*smallest;
    int right = 2*smallest + 1;

    if(left <= size && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <= size && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != small){
        swap(arr[small],arr[smallest]);
        heapifymin(arr,size,smallest);
    }
}

void heapsortdecreasing(int arr[], int n){
    int temp = n;

    while(temp > 1){
        swap(arr[temp],arr[1]);
        temp--;
        heapifymin(arr,temp,1);
    }
}

int main(){
    int arr1[100];
    arr1[0]=-1;
    int idx = 1;
    int num;
    cout<<"enter number of elements : ";
    cin>>num;
    for(int i = 1 ; i <= num; i++){
        cin>>arr1[i];
    }
    idx = num;
    cout<<endl;
    cout<<"before performing the op..";
    for(int i = 1 ; i<= idx ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    int choice;
    cout<<"which operation you want to perform with the heap ? "<<endl;
    cout<<" 1. Heapsort (INCREASING ) 2. Heapsort(DECREASING ) ??"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        heapsortincreasing(arr1,idx);
        break;
    case 2:
        heapsortdecreasing(arr1,idx);
        break;
    }
    cout<<"after preforming op : ";
    for(int i = 1 ; i <= idx ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

}