//Minghe Ren U84996581
#include <iostream>
#include <vector>
using namespace std;

/* 
 *  Function Description: A program that accepts an integer array nums and returns the sum 
 						  closest to 333 by adding up three integers in this array.
 *  @param nums: integer vector
 *  @return value: closest sum to 333
 * 	Complexity: O(N^2)
*/
int sumTo333(vector<int> nums){
	int result;
	//Temporal Closest
	int Closest = 10000;
    //Sort
	sort(nums.begin(),nums.end());
	int size = nums.size();
	for(int i = 0; i< size;i++)
	{
        //Vector Left
		int j = i+1;
        //Vector right
		int k = size-1;
		while(j<k)
		{
			int sum = nums[i]+nums[j]+nums[k];
			int closeness = abs(sum -333);
			if(sum == 333)
				return sum;
			else
				if(closeness < Closest){
					Closest = closeness;
					result = sum;
				}
                //From left
				if(sum	< 333)
					j++;
                //From right
				else
					k--;
		}
	}
	return result;
}



int main(int argc,char ** argv){
	
	vector<int> nums;
	nums.push_back(20);
	nums.push_back(120);
	nums.push_back(200);
	nums.push_back(5);

	cout<<sumTo333(nums)<<endl;

	return 0;
}
