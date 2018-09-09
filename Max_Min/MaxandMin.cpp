#include <stddef.h>
#include <iostream>
using namespace std;

/* 
 *  Function Description: Find max and min of an array
 *  @param *a: Array to be performed
 *  @param size: size of array
 *  @return value: None
 * 	Complexity: O(3*[N/2]); 3 means compare 3 times 
*/
void FindMaxandMin(int *a, int size){
	//Init some randon values
	int max = -1000;
	int min = 1000;
	//Find max and min at same time
	for(int i = 0; i<size && i+1<size; i+=2)
	{
		if(a[i]<a[i+1])
		{
			if(a[i]<min){
				min = a[i];
			}
			if(a[i+1]>max){
				max = a[i+1];
			}
		}
		else
		{
			if(a[i+1]< min){
				min = a[i+1];
			}
			if(a[i] > max){
				max = a[i];
			}
		}
	}

	// For last element
	if(size % 2 != 0){
		if(a[size -1] < min){
			min = a[size-1];
		}
		if(a[size-1] > max){
			max = a[size-1];
		}
	}
	cout<< "The minimum value is: "<< min <<endl;
	cout<< "The maximum value is: "<< max <<endl;

}


int main(int argc, char*argv[]){

	int *array = new int[9]{4, 5, 6,3, 5,9, 8,1,11};
	int length = 9;
	cout<<length;
	FindMaxandMin(array,length);

	delete []array;
	array =NULL;
	return 0;

}