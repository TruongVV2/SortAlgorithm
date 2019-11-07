#include"InsertSort.h"

void InsertionSort::FInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
            int temp = arr[i];

            int j = i-1;
            /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
            while (j >= 0 && arr[j] > temp) 
            {  
                arr[j + 1] = arr[j];  
                j = j - 1;  
            }  
            arr[j + 1] = temp;  
    }
}

void InsertionSort::FPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}

void InsertionSort::TurnOnBackgroundMusic()
{
    Singleton::getInstance("TruongVi")->TurnOnBackgroundMusic();
}

void InsertionSort::TurnOffBackgroundMusic()
{
    Singleton::getInstance("Van")->TurnOffBackgroundMusic();
}

std::string InsertionSort::GetNameInstance()
{
    return Singleton::getInstance("")->getName();
}