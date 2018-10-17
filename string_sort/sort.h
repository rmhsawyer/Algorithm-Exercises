//Minghe Ren U84996581
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

const int NumofChar = 26;

struct ele{
	int count;
	int index;
};

void Quicksort(ele array[], int low, int high);

string sortByFreq(string s) {

	ele element[NumofChar];
	int charcount[NumofChar] ={0};
	string sorted_string = "";
	for(int i = 0; i< s.length(); i++){
		charcount[s[i] - 'a']++;
	}

	for(int i = 0;i < NumofChar;i++){
		element[i].index = i;
		element[i].count = charcount[i];
	}


	Quicksort(element, 0, NumofChar-1);
	//concatenate string
	for(int i = 0;i<NumofChar;i++){
		for(int j=0;j<element[i].count;j++){
			sorted_string += char('a' +element[i].index);
		}
	}

	return sorted_string;
}

//Stable Quick sort 
void Quicksort(ele array[], int low, int high)
{
	if(low <high)
	{
		int first = low;
		int last = high;
		for(int i = low;i< high;i++){
			if(array[i].count < array[last].count){
				int temp_count = array[first].count; 
				int temp_index = array[first].index;
				array[first].count = array[i].count; 
				array[first].index = array[i].index;
				array[i].count = temp_count;
				array[i].index =temp_index;
				first++;
			}
		}

		int temp_count = array[last].count; 
		int temp_index = array[last].index;
		array[last].count = array[first].count; 
		array[last].index = array[first].index;
		array[first].count = temp_count;
		array[first].index =temp_index;

		Quicksort(array,  low, first -1);
		Quicksort(array, first+1,  high);

	}

}


/*
	Auxillary/utility functions, if you need to implement any, go here.
*/
