#include"SelectionSort.h"

void SelectionSort::FSelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        //swap ar[i-1] and min
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void SelectionSort::FPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}