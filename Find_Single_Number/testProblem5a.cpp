/**
 ** Created by Wenchao Li
 **/

#include "findSingle.h"
#include <iostream>
using namespace std;

int main()
{
  int arr[] = {1, 7, 54, 4, 2, 54, 1, 7, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "The integer that occurs only once is " << findSingle(arr, n) << ".\n";
  return 0;
}
