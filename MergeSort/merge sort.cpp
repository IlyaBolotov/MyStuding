#include <iostream>

void merge(int array[], int const left, int const mid, int const right)
{
    int const OneArray = mid - left + 1;
    int const SecArray = right - mid;

    auto* leftArray = new int[OneArray],
        * rightArray = new int[SecArray];

    for (auto i = 0; i < OneArray; i++) {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < SecArray; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    auto OneArrayIndex = 0, SecArrayIndex = 0;
    int MergedArrayIndex = left;

    while (OneArrayIndex < OneArray && SecArrayIndex < SecArray) {
        if (leftArray[OneArrayIndex] <= rightArray[SecArrayIndex]) {
            array[MergedArrayIndex] = leftArray[OneArrayIndex];
            OneArrayIndex++;
        }
        else {
            array[MergedArrayIndex] = rightArray[SecArrayIndex];
            SecArrayIndex++;
        }
        MergedArrayIndex++;
    }


    while (OneArrayIndex < OneArray) {
        array[MergedArrayIndex] = leftArray[OneArrayIndex];
        OneArrayIndex++;
        MergedArrayIndex++;
    }


    while (SecArrayIndex < SecArray) {
        array[MergedArrayIndex] = rightArray[SecArrayIndex];
        SecArrayIndex++;
        MergedArrayIndex++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end) return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}



void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int arr_size;
    std::cout << "Enter array size\n";
    std::cin >> arr_size;
    int* arr = new int[arr_size];

    for (auto i = 0; i < arr_size; i++) {
        std::cout << "Enter the " << i + 1 << " number of array  ";
        std::cin >> arr[i];
    }


    std::cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    delete[] arr;
    return 0;
}
