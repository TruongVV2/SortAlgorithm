#include"MergeSort.h"
#include"QuickSort.h"
#include"BubbleSort.h"
#include"SelectionSort.h"
#include"InsertSort.h"

int main()
{
    int arr[] = {10, 8, 5, 2, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // CMergeSort cmerge;
    // std::cout << "Print elements before sorting" << std::endl;
    // cmerge.print(arr,size);
    // cmerge.MergeSort(arr, 0, 9);
    // std::cout << "Print elements after sorting" << std::endl;
    // cmerge.print(arr,size);

    QuickSort cQuick;
    std::cout << "Print elements before sorting" << std::endl;
    cQuick.Print(arr, 5);
    cQuick.Quick(arr, 0, 4);
    std::cout << "Print elements after sorting" << std::endl;
    cQuick.Print(arr, 5);

    // BubbleSort cBub;
    // std::cout << "Print elements before sorting" << std::endl;
    // cBub.FPrint(arr, 10);
    // cBub.FBubbleSort(arr, 10);
    // std::cout << "Print elements after sorting" << std::endl;
    // cBub.FPrint(arr, 10);

    // SelectionSort cSec;
    // std::cout << "Print elements before sorting" << std::endl;
    // cSec.FPrint(arr, 10);
    // cSec.FSelectionSort(arr, 10);
    // std::cout << "Print elements after sorting" << std::endl;
    // cSec.FPrint(arr, 10);

    // InsertionSort cIntser;
    // cIntser.TurnOnBackgroundMusic();
    // std::cout << "After Turn on, name is: " << cIntser.GetNameInstance() << std::endl;
    // std::cout << "Print elements before sorting" << std::endl;
    // cIntser.FPrint(arr, 10);
    // cIntser.FInsertionSort(arr, 10);
    // std::cout << "Print elements after sorting" << std::endl;
    // cIntser.FPrint(arr, 10);
    // cIntser.TurnOffBackgroundMusic();
    // std::cout << "After Turn off, name is: " << cIntser.GetNameInstance() << std::endl;
}