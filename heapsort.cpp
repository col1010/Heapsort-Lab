#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

template<class T>
void heapsort(T *array, size_t arraylength);
template<class T>
void compare_to_children(T *array, size_t arraylength, size_t idx);
template<class T>
void remove_root(T *array, size_t arraylength);
template<class T>
void printArr(T *array, size_t arraylength);

int main() {

    int arr[13] = {0,4,3,5,6,54,76,23,1,25,100,32,53};
    cout << "\n Array 1 before sorting: ";
    printArr(arr, 13);
    cout << "\n";
    heapsort(arr, 13);
    cout << " Array 1 after sorting: ";
    printArr(arr, 13);
    cout << "\n\n";


    string arr2[13] = {"hi", "seth", "control", "cs-311", "car", "lcsc", "grades", "computer", "good morning", "monitor", "xylophone", "science", "squirrel"};
    cout << " Array 2 before sorting: ";
    printArr(arr2, 13);
    cout << "\n";
    heapsort(arr2, 13);
    cout << " Array 2 after sorting: ";
    printArr(arr2, 13);
    cout << "\n\n";

    return 0;
}

template<class T>
void heapsort(T *array, size_t arraylength) {

    for (size_t i = arraylength - 1; i != SIZE_MAX; i--) { // while i has not underflowed to the max value of size_t
        compare_to_children(array, arraylength, i);
    }

    // now that the heap is valid, do the sorting

    while (arraylength > 0) {
        remove_root(array, arraylength--); // remove the root, re-validate the heap, and decrement the array length to allow space for sorted elements
    }
}

template <class T>
void remove_root(T *array, size_t arraylength) {

    T largest = array[0]; // set largest to the root value
    array[0] = array[arraylength - 1]; // set the root to be the rightmost element
    compare_to_children(array, arraylength - 1, 0); // make the heap valid while ignoring the sorted section of the array
    array[arraylength -1] = largest; // insert the sorted element to the correct position in the array

}

template<class T>
void compare_to_children(T *array, size_t arraylength, size_t idx) {

    T tmp;

    while (idx < arraylength) {

        size_t left_child_idx = idx * 2 + 1;
        size_t right_child_idx = idx * 2 + 2;
        size_t greater_child_idx;

        if (left_child_idx >= arraylength) // if there is no left child (it is out of bounds), return
            return;

        // determine largest child
        T curr = array[idx];
        T left_child = array[left_child_idx];
        T right_child = array[right_child_idx];
        

        if (array[left_child_idx] > array[right_child_idx])
            greater_child_idx = left_child_idx;
        else
            greater_child_idx = right_child_idx;


        if (array[greater_child_idx] > array[idx]) { // if the greatest child is greater than the parent
            // swap
            tmp = array[greater_child_idx];
            array[greater_child_idx] = array[idx];
            array[idx] = tmp;
        }
        idx = greater_child_idx; // move to what was just swapped
    } 

}

template<class T>
void printArr(T *array, size_t arraylength) {
    if (arraylength == 0) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < arraylength; i++) {
        cout << array[i] << ", ";
    }
    cout << "\b\b]";
}
