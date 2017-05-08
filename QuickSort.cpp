#include <vector>
#include <iostream>

template <typename T>
void quick_sort (std::vector<T> & array, size_t left_idx, size_t right_idx)
{
    size_t pivot_idx = (left_idx + right_idx)/2;
    size_t i=left_idx, j=right_idx;

    T  pivot = array[pivot_idx];
    
    while (i<=j)
    {
        while (array[i]<pivot)
            ++i;
    
        while (array[j]>pivot)
            --j;

        if (i<=j) {
            std::swap (array[i], array[j]);
            i++; j--;
        }
    }    
    
    if (left_idx < j)  quick_sort<T>(array, left_idx, j);
    if (i < right_idx)   quick_sort<T>(array, i, right_idx);

}


int main()
{

    std::vector<int> arr {1, 12, 5, 26, 7, 14, 3, 7, 2};

    std::cout <<"Before quick sort\n";
    for (const int &x : arr)
        std::cout << x << " ";
    
    quick_sort<int> (arr, 0, arr.size()-1);

    std::cout <<"\nAfter quick sort\n";    
    for (const int &x : arr)
        std::cout << x << " ";

    std::cout << "\n";
}
