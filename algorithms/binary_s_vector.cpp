//binary search cut the search space into half comparing to linear search
//log(n) running time(time complexity)
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cerr;
template <typename T>
T binary_search(vector<T> arr, T search_elem) {
    T low = 0;
    T high = arr.size() - 1;
    T mid;
    
    while(low <= high){
        mid = (low + high)/2;
        if(search_elem == arr[mid]){
            return mid;
        }else if(search_elem > arr[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1; 
}
template <typename T>
void key_found(T result, vector<T> arr, T userVal){
    if(result >= 0){
        cerr << "The number " << arr[result] << " was found at the element with index "
        << result << "\n";
    }else{
        cerr << "The number " << userVal << " was not found. " << "\n";
    }
}

int main()
{
    vector<int> arr{12, 22, 34, 47, 55, 67, 82, 98};
    int userVal = 55;
    int result0 = binary_search(arr, userVal);
    //key_found(result0, arr, userVal);
    int result0_stl = std::ranges::binary_search(arr, userVal);
    key_found(result0_stl, arr, userVal);

   vector<int> arr1{44, 23, 34, 22, 55, 47, 82, 98};
   int userVal1 = 22;
   int result1 = binary_search(arr1, userVal1);
   key_found(result1, arr1, userVal1);
}
