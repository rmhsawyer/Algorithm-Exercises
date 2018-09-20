//Minghe Ren U84996581

#include <string>
#include <iostream>
using namespace std;

/* 
 *  Function Description: A program that outputs the kth (k>0) digit in this sequence (0,1,2,3,4,5,6,7,8,9,10,11,12...)
 *  @param k: kth digit
 *  @return value: the result kth digit
 * 	Complexity: O(2N)
*/
int kthDigit(int k)
{
	//The number of numbers in sequence
	int Number = 1000;
	int *sequence = new int [Number];
	string stringsequence,temp_string;
	int i;
	for(i = 0; i<Number;i++){
		sequence[i] = i;
	}
	for(i = 0; i<Number;i++){
		temp_string = to_string(sequence[i]);
        //Hypenate string
		stringsequence = stringsequence + temp_string;
	}
	//The ASCII number of '0' is 48. So we should minus by 48 and then convert to int 
	return int(stringsequence[k-1]-48);
}


int main(int argc,char ** argv){
	int index;
	cout<< "Please enter the ith number you want to print:";
	cin>>index;
	cout<<kthDigit(index)<<endl;
	return 0;
}
