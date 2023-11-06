#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

const int HEAP_MAX_SIZE = 100000;

int partition(int[], int, int);
void swap(int[], int, int);
void quickSort(int [], int, int);
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);
void heapSort(int arr[], int size);

class MinHeap {
private:
    int heapArr[HEAP_MAX_SIZE];
    int size;
    void swap(int x, int y) {  
        // private swap has access to array, only need indexes
        int temp = heapArr[x];
        heapArr[x] = heapArr[y];
        heapArr[y] = temp;

    }

    void percolateUp(int index) {
        // compares element with parent, base case
        if((heapArr[index] > heapArr[(index - 1)/ 2]) || index == 0){
            return;
        }
        else{ // swaps element with parent to percolate up
            swap(index, (index - 1)/2);
            percolateUp((index - 1)/2);
        }
    }

    void percolateDown(int index) {
        int left, right;

        left = (2 * index) + 1; // sets indexes
        right = (2 * index) + 2;

        if((heapArr[index] < heapArr[left] && heapArr[index] < heapArr[right]) // base case
        || index > size){
            return;
        }
        else if(heapArr[left] < heapArr[right] && heapArr[left] < heapArr[index] && left <= size){
            // swap with left child
            swap(index, left);
            percolateDown(left);
        }
        else if(heapArr[right] < heapArr[left] && heapArr[right] < heapArr[index] && right <= size){
            // swap with right child
            swap(index, right);
            percolateDown(right);
        }
    }
public:
    MinHeap() { size = -1; } // constructor

    void insert(int element) { // inserts new element
    size++; // adds size to heap
    heapArr[size] = element; // sets array element
    percolateUp(size);

    }
    void deleteMin() { // deletes element
        if(size == -1){
            return;
        }
        swap(0, size); // swaps root with last element
        heapArr[size] = 1000000; // set last node to high number, which will not mess up percolate down comparisons
        size--;
        percolateDown(0);
    }
    int extractMin() { // returns the root
        if(size == -1){
            cout << "\n\nEmpty heap\n";
            return -1;
        }
        return heapArr[0];
    }
    int heapSize() { // returns size
        return size + 1;
    }
    void heapDisplay() { // displays nodes in first breath traversal
    for(int x = 0; x <= size; x++){
        cout << heapArr[x] << " ";
    }
    cout << "\n";
    }

    bool isEmpty()
    {
        if(size == -1){
            return true;
        }
        return false;
    }
};

int main()
{
    int size[] = {10,100,1000,10000};
    for(int i = 0; i < 4; i ++){
        int *unsortedArray = new int[size[i]]; 
        cout << "\nThe current array size is: " << size[i] << endl;

        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }

        auto start = high_resolution_clock::now();
        
        heapSort(unsortedArray, size[i]);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << duration.count() << endl;

        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }

        start = high_resolution_clock::now();
        
        mergeSort(unsortedArray, 0, size[i] - 1);

        stop = high_resolution_clock::now();

        duration = duration_cast<nanoseconds>(stop - start);

        cout << duration.count() << endl;

        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }

        start = high_resolution_clock::now();
        
        quickSort(unsortedArray, 0, size[i] - 1);
        
        stop = high_resolution_clock::now();

        duration = duration_cast<nanoseconds>(stop - start);

        cout << duration.count() << endl;

        delete [] unsortedArray;
    }

    return 0;
} 


int partition(int a[], int i, int j) {
    // partition data items in a[i..j]
    int p = a[i]; // p is the pivot, the ith item
    int m = i; // initially S1 and S2 are empty
    for (int k = i + 1; k <= j; k++) { //process unknown region
    if (a[k] <= p) {  // case 2: put a[k] to S1
        m++;
        swap(a, k, m);
    } else {  // case 1: put a[k] to S2. 
    // Q: Do you even need to write anything here? 
    } 
    }
    swap(a, m, i); // put the pivot at the right place
    return m;    // return the pivot’s final position
}

void swap(int a[], int b, int c){
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

void quickSort(int a[], int i, int j)
{
    if(i < j){
        int pivotIndex = partition(a, i, j);
        quickSort(a, i, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, j);
    }
}

void mergeSort(int arr[], int start, int end){
    if(start < end){
        int middle = (start + end)/2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void merge(int arr[], int start, int middle, int end){
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int *left = new int[leftSize];
    int *right = new int[rightSize];
    
    for(int x = 0; x < leftSize; x++){
        left[x] = arr[start + x];
    }

    for(int x = 0; x < rightSize; x++){
        right[x] = arr[middle + x + 1];
    }
    
    int leftIndex = 0, rightIndex = 0, mainIndex = start;
    while(leftIndex < leftSize && rightIndex < rightSize){
        if(left[leftIndex] <= right[rightIndex]){
            arr[mainIndex] = left[leftIndex];
            leftIndex++;
        }else{
            arr[mainIndex] = right[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }
    while(leftIndex < leftSize){
        arr[mainIndex] = left[leftIndex];
        leftIndex++;
        mainIndex++;
    }

    while(rightIndex < rightSize){
        arr[mainIndex] = right[rightIndex];
        rightIndex++;
        mainIndex++;
    }

    delete [] left;
    delete [] right;
}




void heapSort(int arr[], int size)
{
    MinHeap heap;
    for(int x = 0; x < size; x++){
        heap.insert(arr[x]);
    }
    int count = 0;

    while(!heap.isEmpty()){
        arr[count] = heap.extractMin();
        heap.deleteMin();
        count++;
    }
}