#include<iostream>

class binarySearch
{
    public:
        int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int search(int arr[], int firstPos, int lastPos, int input);

};

int binarySearch::search(int arr[], int firstPos, int lastPos, int input)
{
    // get size of array
    int size = (lastPos - firstPos) + 1;
    // get middle element
    int mid = firstPos + size/2;
    // compare mid with input
    if (arr[mid] == input) {
        return mid;
    } else if (arr[mid] > input) {
        if (mid == firstPos) {
            std::cout << "can not find the input" << std::endl;
            return - 1;
        }
        return search(arr, firstPos, mid - 1, input);
    } else {
        if (mid == lastPos) {
            std::cout << "can not find the input" << std::endl;
            return -1;
        }
        return search(arr, mid + 1, lastPos, input);
    }
}

int main()
{
    binarySearch biSearch;
    int index = biSearch.search(biSearch.arr, 0, 8, 10);
    std::cout << "index is: " << index << std::endl;
}