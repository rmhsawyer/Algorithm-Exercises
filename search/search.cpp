#include <ctime>
#include <iostream> 
#include <stdlib.h>
#include <stddef.h>
#include <cmath>
#include <fstream>
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
 *  Function Description: Search using Linear Method 
 *  @param array[]: Array to be sorted
 *  @param length: length of array
 *  @param key: value to find
 *  @param &count: count the times of searching
 *  @return value: index of the finding result
 * 	Complexity: O(N)
*/
int LinearSearch(int array[], int key ,int length, int  &count)
{
	count = 0;
	int i;
	for(i = 0; i < length; i++){
		count++;
		if(array[i] == key){
			return i;
		}
	}
	return -1;
}


/* 
 *  Function Description: Search using Binary Method 
 *  @param array[]: Array to be sorted
 *  @param length: length of array
 *  @param key: value to find
 *  @param &count: count the times of searching
 *  @return value: index of the finding result
 * 	Complexity: O(logN)
*/
int BinarySearch(int array[], int key, int length, int &count)
{	
	Quicksort(array,0,length-1);
	count = 0;
	int low = 0;
	int high = length-1;
	int mid;
	while(low <= high){
		mid = (low + high)/2;
		count++;
		if(key == array[mid])
			break;
		else if(key < array[mid])
			high = mid -1;
		else
			low = mid +1;
	}

	return mid;
}


/* 
 *  Function Description: Search using Dictionary Method 
 *  @param array[]: Array to be sorted
 *  @param length: length of array
 *  @param key: value to find
 *  @param &count: count the times of searching
 *  @return value: index of the finding result
 * 	Complexity: O(log(logN))
*/
int DictionarySearch(int array[], int key,int length, int &count)
{
	Quicksort(array,0,length-1);
	count = 0;
	int low = 0;
	int high = length-1;
	double fraction;
	int mid;
	while(low <= high){
		count++;
		fraction = double(key - array[low])/ double(array[high] - array[low]);
		mid = fraction * (high - low) + low;
		if(key == array[mid]){
			break;
		}
		else if(key < array[mid]){
			high = mid -1;
		}
		else{
			low = mid +1;
		}
	}
	return mid;
}


int main(int argc, char const *argv[])
{	
	int const Nsize = 1000;
	int *array = new int[Nsize];
	// Counters 
  	int BinCount; // counter for binary search. 
  	int LinCount; // counter for linear search. 
 	int DctCount; // counter for dictionary search.
	int i;
	/*
	time_t time(time_t *time);
	This returns the current calendar time of the system 
	in number of seconds elapsed  since January 1, 1970. 
	If the system has no time, .1 is returned.
	*/
	int time_seconds = time(0);
	srand(time_seconds%100); // seed the random number generator.
	for(i = 0; i < Nsize; i++)
	{
	  array[i] =  rand()%Nsize;	
	}

 	ofstream file;
	file.open("Search_timing.dat");


	// Randomly choose an element to search for.
	int find = array[rand()%Nsize] ;

	// First, search with a linear search. A linear search doesn't depend
	// on a array being sorted.
	cout << "Searching for key = "<< find << endl;
	i = LinearSearch(array,find ,Nsize, LinCount);

	// Print the number of iterations compared to the average.
	cout <<" Linear search found at  "<< i << 
	" with " <<LinCount << " iterations  compared to Nsize/2 " << Nsize/2 << endl;


	file <<" Linear search found at  "<< i << 
	" with " <<LinCount << " iterations  compared to Nsize/2 " << Nsize/2 << endl;

	//Perform a binary search. 
	i = BinarySearch(array,find ,Nsize, BinCount); 

	// Print the number of iterations compared to the average.
	cout <<" Binary  search found at  "<< i <<
	" with " <<BinCount << " iterations  compared to log2(Nsize) " << log(Nsize)/log(2) << endl;
	file <<" Binary  search found at  "<< i <<
	" with " <<BinCount << " iterations  compared to log2(Nsize) " << log(Nsize)/log(2) << endl;

	// Perform a dictionary search. 
	i = DictionarySearch(array,find ,Nsize, DctCount);  

	// Print the number of iterations compared to the average.
	cout <<" Dictionary   found at  "<< i << 
	" with " <<DctCount << " iterations compared to log2(log2(Nsize)  " << log(log(Nsize)/log(2))/log(2) <<  endl; 
	file <<" Dictionary   found at  "<< i << 
	" with " <<DctCount << " iterations compared to log2(log2(Nsize)  " << log(log(Nsize)/log(2))/log(2) <<  endl; 

	file.close();


	// Free the allocated memory.
	delete [] array;
	array = NULL;


	return 0;
}