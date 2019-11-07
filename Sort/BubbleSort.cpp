#include"BubbleSort.h"

void BubbleSort::FBubbleSort(int arr[], int n)
{
    bool swapped = false;
    for (int i = n-1; i > 0; i--) {
        swapped = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void BubbleSort::FPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}