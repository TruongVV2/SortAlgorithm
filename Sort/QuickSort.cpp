#include"QuickSort.h"

void QuickSort::Quick(int a[], int l, int r)
{
    if (l < r) {
        int pivot = Partition(a, l, r);
        Quick(a, l, pivot - 1);
        Quick(a, pivot + 1, r);
    }
}

int QuickSort::Partition(int a[], int l, int r)
{
    // get pivot value
    int pi = a[r];

    // index lower
    int i = l;

    // sort smaller than pivot to right side
    for (int j = l; j < r; j++) {
        if (a[j] < pi) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            // move index to next index
            i++;
        }
    }

    std::cout << "i: " << i << std::endl;
    // swap pivot and value at position i
    a[r] = a[i];
    a[i] = pi;
    Print(a, 5);
    return i;
}

void QuickSort::Print(int a[], int size)
{
    std::cout << "Print quickSort!" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << std::endl;
    }
}