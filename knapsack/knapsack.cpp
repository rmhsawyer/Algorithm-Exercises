#include <iostream>
using namespace std;

/* 
 *  Function Description: solve 0-1 knapsack problem 
 *  @param *Weight: Array of objects' weights
 *  @param *Value: Array of objects' values
 *  @oaram *res: Array of picking objects(bool)
 *  @param n: number of objects
 *  @param Volumn: Volumn of knapsack  
 *  @return value: highest value

 *	Transform funciton:
 *	f[i][v] = max{f[i-1][v], f[i-1][v - w[i]] + v[i]}
 *	i: when pick the ith object
 *	v: volumn of current knapsack
 *	v[i]: the value of the ith object
 *	f[i][v] = the value of knapsack with v capacity when pick the ith item
 * 	Complexity: O(N*V)
*/
int knapsack_solver_01(int *Weight, int*Value, int *res, int n, int Volumn)
{
	int value = 0;
	// Initiate transform function
	int **function = new int *[n];
	for(int i = 0; i<n ;i++){
		function[i] = new int[Volumn+1];
	}
	for(int i = 0; i < n; i++){
		for( int j = 0; j <= Volumn; j++){
			function[i][j] = 0;
		} 
	}
	// For knapsack with zero capacity
	for(int i = 0; i< n; i++){
		function[i][0] = 0;
	}
	// Choose first object or not
	for(int i = 1; i<= Volumn; i++){
		function[0][i] = (Weight[0] > i)? 0: Value[0];
	}
	// Iterate transform function
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= Volumn; j++){
			if(j >= Weight[i]){
				function[i][j] = ( function[i-1][j] > (function[i-1][j - Weight[i]] + Value[i])) ? function[i-1][j]: (function[i-1][j - Weight[i]] + Value[i]);
			}
			else{
				function[i][j] = function[i-1][j];
			}			
		}
	}
	// Print function Matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= Volumn; j++)
			cout<<function[i][j]<<" ";
		cout<< endl;
	}

	// Get highest value
	value = function[n-1][Volumn];

	// Find the array of picking objects(bool)
	int Y = n-1;
	int j = Volumn;
	while(Y){
		if(function[Y][j] == (function[Y-1][j- Weight[Y]] + Value[Y]))
		{
			res[Y] = 1;
			j = j - Weight[Y];
		}
		Y--;
	}
	if(function[0][j]){
		res[0] = 1; 
	}

	// Delete dynamic memory
	for(int i = 0; i < n;i++)
    {
        delete [] function[i];
        // Pointer to null
        function[i] = 0;
    }
	delete [] function;
    function = 0;
	return value;

}

/* 
 *  Function Description: solve 0-1 knapsack problem 
 *  @param *Weight: Array of objects' weights
 *  @param *Value: Array of objects' values
 *  @param n: number of objects
 *  @param Volumn: Volumn of knapsack  
 *  @return value: highest value

 *	Transform funciton:
 *	f[i][v] = max{f[i-1][v], f[i-1][v - w[i]] + v[i]}
 *	i: when pick the ith object
 *	v: volumn of current knapsack
 *	v[i]: the value of the ith object
 *	f[i][v] = the value of knapsack with v capacity when pick the ith item
 *  Complexity: O(N*V); Structure Complexity: O(V)
*/
int knapsack_solver_01_simple(int *Weight, int*Value, int n, int Volumn)
{
	int value = 0;
	// Initiate transform function
	int *function = new int[Volumn +1];

	for( int j = 0; j <= Volumn; j++){
		function[j] = 0;
	} 

	// Iterate transform function
	for(int i = 0; i < n; i++){
		for(int j = Volumn; j>=0; j--){
			if(j >= Weight[i]){
				function[j] = ( function[j] > (function[j - Weight[i]] + Value[i])) ? function[j]: (function[j - Weight[i]] + Value[i]);
			}			
		}
	}
	// Print function Matrix
	for(int j = 0; j <= Volumn; j++)
		cout<<function[j]<<" ";
	cout<< endl;

	// Get highest value
	value = function[Volumn];

	// Delete dynamic memory
	delete [] function;
    function = 0;
	return value;

}


/* 
 *  Function Description: solve total knapsack problem 
 *  @param *Weight: Array of objects' weights
 *  @param *Value: Array of objects' values
 *  @oaram *res: Array of picking objects(bool)
 *  @param n: number of objects
 *  @param Volumn: Volumn of knapsack  
 *  @return value: highest value

 *	Transform funciton:
 *	f[i][v] = max{f[i-1][v], f[i][v - w[i]] + v[i]}
 * 	Notes: Using f[i][v - w[i]] + v[i] instead of f[i-1][v - w[i]] + v[i] because we could still put another ith object in cunrrent level
 *	i: when pick the ith object
 *	v: volumn of current knapsack
 *	v[i]: the value of the ith object
 *	f[i][v] = the value of knapsack with v capacity when pick the ith item
*/
int knapsack_solver_total(int *Weight, int*Value, int *res, int n, int Volumn)
{
	int value = 0;
	// Initiate transform function
	int **function = new int *[n];
	for(int i = 0; i<n ;i++){
		function[i] = new int[Volumn+1];
	}
	for(int i = 0; i < n; i++){
		for( int j = 0; j <= Volumn; j++){
			function[i][j] = 0;
		} 
	}

	// Choose first object or not
	for(int i = 1; i<= Volumn; i++){
		function[0][i] = (Weight[0] > i)? 0: ((i/Weight[0])* Value[0]);
	}
	// Iterate transform function
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= Volumn; j++){
			if(j >= Weight[i]){
				function[i][j] = ( function[i-1][j] > (function[i][j - Weight[i]] + Value[i])) ? function[i-1][j]: (function[i][j - Weight[i]] + Value[i]);
			}
			else{
				function[i][j] = function[i-1][j];
			}			
		}
	}
	// Print function Matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= Volumn; j++)
			cout<<function[i][j]<<" ";
		cout<< endl;
	}

	// Get highest value
	value = function[n-1][Volumn];

	// Find the array of picking objects(bool)
	int Y = n-1;
	int j = Volumn;
	while(Y){
		if(function[Y][j] == (function[Y][j- Weight[Y]] + Value[Y]))
		{
			res[Y]++ ;
			j = j - Weight[Y];
		}
		Y--;
	}
	if(function[0][j]){
		res[0] = function[0][j]/Value[0]; 
	}

	// Delete dynamic memory
	for(int i = 0; i < n;i++)
    {
        delete [] function[i];
        // Pointer to null
        function[i] = 0;
    }
	delete [] function;
    function = 0;
	return value;

}

/* 
 *  Function Description: solve total knapsack problem 
 *  @param *Weight: Array of objects' weights
 *  @param *Value: Array of objects' values
 *  @param n: number of objects
 *  @param Volumn: Volumn of knapsack  
 *  @return value: highest value

 *	Transform funciton:
 *	f[i][v] = max{f[i-1][v], f[i][v - w[i]] + v[i]}
 * 	Notes: Using f[i][v - w[i]] + v[i] instead of f[i-1][v - w[i]] + v[i] because we could still put another ith object in cunrrent level
 *	i: when pick the ith object
 *	v: volumn of current knapsack
 *	v[i]: the value of the ith object
 *	f[i][v] = the value of knapsack with v capacity when pick the ith item
 *  Complexity: O(N*V); Structure Complexity: O(V)
*/
int knapsack_solver_total_simple(int *Weight, int*Value, int n, int Volumn)
{
	int value = 0;
	// Initiate transform function
	int *function = new int[Volumn +1];

	for( int j = 0; j <= Volumn; j++){
		function[j] = 0;
	} 

	// Iterate transform function
	for(int i = 0; i < n; i++){
		for(int j = 0; j<=Volumn; j++){
			if(j >= Weight[i]){
				function[j] = ( function[j] > (function[j - Weight[i]] + Value[i])) ? function[j]: (function[j - Weight[i]] + Value[i]);
			}			
		}
	}
	// Print function Matrix
	for(int j = 0; j <= Volumn; j++)
		cout<<function[j]<<" ";
	cout<< endl;

	// Get highest value
	value = function[Volumn];

	// Delete dynamic memory
	delete [] function;
    function = 0;
	return value;

}


int main()
{

	int n,C;
	cout<<"Enter the number of objects and knapsack capacity:"<<endl;
	while(cin >> n >> C){
		int *Weight = new int[n];
		int *Value = new int[n];
		int *res = new int[n];
		for(int i = 0; i<n; i++){
			res[i] = 0;
		}
		int i = 0;
		cout<<"Enter every single object's weight and value:"<<endl;
		while(i < n){
			cin >> Weight[i] >> Value[i];
			i++;
		}
		int value = knapsack_solver_01(Weight, Value, res, n, C);
		cout<<"Highest value is: " << value << endl;
		cout<< "The following objects are chosed: " << endl;
		for(int i = 0; i< n; i++){
			cout<< res[i]<< " ";
		}
		cout<<endl;
		delete []Weight;
        delete []Value;
        delete []res;
	}

	return 0;
}