#include "MergeSort.h"

void CMergeSort::MergeSort(int a[], int l, int r)
{
    if (r > l) {
        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Sort(a, l, mid, r);
    }
}

void CMergeSort::Sort(int a[], int l, int m, int r)
{
    // get size of two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;
    // instance two temporary subarrays
    int l1[n1];
    int l2[n2];
    // copy element from original array to temporary subarrays
    for (int i = 0; i < n1; i++) {
        l1[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++) {
        l2[j] = a[m + 1 + j];
    }

    // instance new index for copy elements from two temporary subarrays to original array
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (l1[i] < l2[j]) {
            a[k] = l1[i];
            i++;
        } else {
            a[k] = l2[j];
            j++;
        }
        k++;
    }

    // copy remain elements in subarrays
    while (i < n1) {
        a[k] = l1[i];
        k++;
        i++;
    }

    while (j < n2) {
        a[k] = l2[j];
        k++;
        j++;
    }
    std::cout << "l is: " << l << std::endl;
    std::cout << "m is: " << m << std::endl;
    std::cout << "r is: " << r << std::endl;
    print(a, 10);
}

void CMergeSort::print(int a[], int size)
{
    std::cout << "Print elements of array!" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << std::endl;
    }
}