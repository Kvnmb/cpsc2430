// Kevin Bui
// lab4.cpp
// 5/19/22
// Purpose: To create a min heap and implement basic heap operations
// Input: integers to build the heap
// Processing: recursion, heapify, percolate, swap
// Output: outputs root of heap, modifies heap through deletion and insertion

#include <iostream>
using namespace std;
const int HEAP_MAX_SIZE = 1000;
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
            cout << "\nEmpty heap\n";
            return;
        }
        swap(0, size); // swaps root with last element
        heapArr[size] = 100000; // set last node to high number, which will not mess up percolate down comparisons
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
};

// in your main function, test your implementations. For example,  
int main() {
    MinHeap mh;
    mh.insert(4);
    mh.insert(8);
    mh.insert(1);
    mh.insert(7);
    mh.insert(3);

    // display heap
mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7
    // deleteMin
    mh.deleteMin();
mh.heapDisplay();  // the output should be: 3, 7, 4, 8
    // extractMin
cout << endl << mh.extractMin() << endl;   // the output should be: 3
    // heapSize
    cout << endl << mh.heapSize() << endl;   // the output should be: 4

    return 0;
}