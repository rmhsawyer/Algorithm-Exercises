//Minghe Ren U84996581

#include <iostream>
using namespace std;


/*
 *  Function Description: Find a integer that appears once in a array using XOR
 *    In the test example, each other integers appear twice. We can use XOR method for:
 *    integer1 ^ interger1 = 0;
 *    integer2 ^ 0 = integer2;
 *    Reference: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
 *  @param arr[]: Array to be sorted
 *  @param arr_size: array size
 *  @return value: integer appear once
 *     Complexity: O(N)
 */
int findSingle(int arr[], int arr_size)
{
    int result = arr[0];
    for(int i = 1; i< arr_size; i++){
        //Perform XOR
        result = result ^ arr[i];
    }
    
    return result;
}

/*
 *  Function Description: Find a integer that appears once in a array
 *  @param arr[]: Array to be sorted
 *  @param arr_size: array size
 *  @return value: integer appear once
 *     Complexity: O(N^2)
 */
int findSingle1(int arr[], int arr_size){
    
    int count;
    for(int i = 0; i< arr_size; i++){
        count = 0;
        for(int j = i+1; j< arr_size; j++){
            if(arr[i] == arr[j])
                count ++;
        }
        if(count == 0)
            return arr[i];
    }
    return -1;
}


int main(int argc, char **argv)
{
  int arr[] = {1, 7, 54, 4, 2, 54, 1, 7, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "The integer that occurs only once is " << findSingle(arr, n) << ".\n";
  return 0;
}
