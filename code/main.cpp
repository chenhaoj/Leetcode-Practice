#include<iostream>
#include<vector>
#include"tools.h"
#include"insertSort.cpp"
#include"binaryInsertSort.cpp"
#include"shellSort.cpp"
#include"selectSort.cpp"
#include"heapSort.cpp"
#include"bubbleSort.cpp"
#include"quickSort.cpp"
#include"mergeSort.cpp"
#include"radixSort.cpp"

void cout_vector(std::vector<int> &nums) {
    for(int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void sort() {
    std::vector<int> nums{1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    // std::vector<int> temp(nums.size());
    std::cout << "please select one sort algorithm and type the number of it: \n"
         << "1:sort() " << std::endl
         << "2:insert_sort()" << std::endl
         << "3:binary_insert_sort()" << std::endl
         << "4:shell_sort()" << std::endl
         << "5:select_sort()" << std::endl
         << "6:heap_sort()" << std::endl
         << "7:bubble_sort()" << std::endl
         << "8:quick_sort()" << std::endl
         << "9:merge_sort()" << std::endl
         << "10:radix_sort()" << std::endl;
    // binary_insert_sort(nums);
    int serial;
    std::cin >> serial;
    switch (serial) {
    case 2:
        std::cout << "insert_sort result: ";
        insert_sort(nums);
        break;
    case 3:
        std::cout << "binary_insert_sort result: ";
        binary_insert_sort(nums);
        break;
    case 4:
        std::cout << "shell_sock result: ";
        shell_sort(nums);
        break;
    case 5:
        std::cout << "select_sort result: ";
        select_sort(nums);
        break;
    case 6:
        std::cout << "heap_sort result: ";
        heap_sort(nums);
        break;
    case 7:
        std::cout << "bubble_sort result: ";
        bubble_sort(nums);
        break;
    case 8:
        std::cout << "quick_sort result: ";
        quick_sort(nums, 0, nums.size()-1);
        break;
    case 9:
        std::cout << "merge_sort result: ";
        merge(nums, 0, nums.size());
        break;
    case 10:
        std::cout << "radix_sort result: ";
        radix_sort(nums);
        break;
    default:
        std::cout << "wrong num for function select.";
        break;
    }
    cout_vector(nums);
};

int main(void) {
    sort();
    return 0;
}