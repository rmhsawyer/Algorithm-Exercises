#include <iostream>
using namespace std;

/* 
 *  Function Description: Sorting method using Quicksort Method 
 *  @param *array: Array to be sorted
 *  @param low: lower bound of sorting range
 *  @oaram high: uppper bound of sorting range 
 *  @return value: None
 * 	Complexity: O(NlogN)
*/
void Quicksort(int *array, int low, int high)
{
	if(low > high)
		return;
	int first = low;
	int last = high;
	int key = array[first];
	while(first< last)
	{
		//find the first element lower than key from right
		while(first < last && array[last] >= key )
		{
			last--;
		}
		array[first] = array[last];
		//find the first element greater than key from left
		while(first < last && array[first] <= key)
		{
			first++;
		}
		array[last] = array[first];
	}

	//update key
	array[first] = key;
	Quicksort(array, low, first -1);
	Quicksort(array, first + 1, high);
}

/* 
 *  Function Description: Sorting method using Bubblesort Method 
 *  @param *array: Array to be sorted
 *  @return value: None
 * 	Complexity: O(N^2)
*/
void BubbleSort(int *array)
{	
	int temp;
	int len = sizeof(array);
	for(int i = 0; i < len -1;i++ ){
		for(int j = 0; j< len-1;j++){
			if( array[j]> array[j+1]){
				temp = array[j];
				array[j]= array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

int main()
{
	int *array = new int[5]{4,5,3,1,2};
	BubbleSort(array);
	for(int i =0; i<5; i++){
		cout<<array[i]<<" ";
	}
	cout << endl;
	delete [] array;
	array = NULL;
	return 0;
}