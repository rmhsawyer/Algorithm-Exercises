//Minghe Ren U84996581
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int x_val, int y_val) : x(x_val), y(y_val) {}
	string toString() {return "(" + to_string(x) + ',' + to_string(y) + ")";}
};

struct DistancePoint{
	int index1,index2;
	float distance;
};



/***************************    Function Definition    *****************************/

float pairDist(Point p1, Point p2);
float min(float a,float b);
DistancePoint compare(Point pts[], int n);
DistancePoint closestDist(Point pts[],int  n);
void Quicksort1(Point array[], int low, int high);
void Quicksort2(vector<Point>& array, int low, int high);
pair<Point, Point> findClosestPairOptimal(Point pts[], int n);
pair<Point, Point> findClosestPair(Point pts[], int n) ;


//Basic Algorithm to find the pair with cloest distance using bubble sort
pair<Point, Point> findClosestPair(Point pts[], int n) {
	
	if(n==0 || n==1){
		Point a(std::numeric_limits< int >::min(),std::numeric_limits< int >::min());
		Point b(std::numeric_limits< int >::min(),std::numeric_limits< int >::min());
		return make_pair(a,b);
	}

	Point R[n/2],L[n/2];
	int i,j;
	for( i = 0;i<n-1;i++){
		for( j = 0;j<n-1-i;j++){
			if(pts[j].x > pts[j+1].x){
				int temp_X,temp_Y;
				temp_X = pts[j].x;
				temp_Y = pts[j].y;
				pts[j].x = pts[j+1].x;
				pts[j].y = pts[j+1].y;
				pts[j+1].x = temp_X;
				pts[j+1].y = temp_Y;
			}
		}
	}


	int x = pts[n/2-1].x;
	for (i = 0;i< n/2; i++){
		L[i].x = pts[i].x;
		L[i].y = pts[i].y;
	}
	j = 0;
	for (i = n/2;i< n; i++){
		R[j].x = pts[i].x;
		R[j].y = pts[i].y;
		j++;
	}

	DistancePoint LD = closestDist(L,n/2);
	DistancePoint RD = closestDist(R,n/2);
	float d;
	int index1,index2;
	bool Left = false;
	if(LD.distance<=RD.distance)
	{
		d = LD.distance;
		index1 = LD.index1;
		index2 = LD.index2;
		Left = true;
	}
	else{
		d = RD.distance;
		index1 = RD.index1;
		index2 = RD.index2;
	}


	vector<Point> Ysort;
	for( i = 0;i<n;i++){
		if( float(x)-d< float(pts[i].x) &&  float(pts[i].x)< float(x)+d)
		{
			Ysort.push_back(pts[i]);
		}
	}

	for( i = 0;i<Ysort.size();i++){
		for( j = 0;j<Ysort.size()-1-i;j++){
			if(Ysort[j].y > Ysort[j+1].y){
				int temp_X,temp_Y;
				temp_X = Ysort[j].x;
				temp_Y = Ysort[j].y;
				Ysort[j].x = Ysort[j+1].x;
				Ysort[j].y = Ysort[j+1].y;
				Ysort[j+1].x = temp_X;
				Ysort[j+1].y = temp_Y;
			}
		}
	}

  	float min =d;
  	int index3,index4;
  	for(i = 0;i<Ysort.size();i++){
  		for (int j = i+1; j < Ysort.size() && (Ysort[j].y - Ysort[i].y) < min; ++j) 
            if (pairDist(Ysort[i],Ysort[j]) < min){
            	min = pairDist(Ysort[i], Ysort[j]); 
            	index3 = i;
            	index4 = j;
            } 
                
  	}
  	if(d <= min && Left)
  		return make_pair(L[LD.index1], L[LD.index2]) ;
  	if(d <= min && !Left)
  		return make_pair(R[RD.index1], L[RD.index2]) ;
  	else
  		return make_pair(Ysort[index3],Ysort[index4]);
  	
}

//Optimal Algorithm to find the pair with cloest distance using quick sort. Complexity: O(nlogn)
pair<Point, Point> findClosestPairOptimal(Point pts[], int n) {

	if(n==0 || n==1){
		Point a(std::numeric_limits< int >::min(),std::numeric_limits< int >::min());
		Point b(std::numeric_limits< int >::min(),std::numeric_limits< int >::min());
		return make_pair(a,b);
	}

	Point R[n/2],L[n/2];
	int i,j;

	Quicksort1(pts, 0, n-1);
	int x = pts[n/2-1].x;
	for (i = 0;i< n/2; i++){
		L[i].x = pts[i].x;
		L[i].y = pts[i].y;
	}
	j = 0;
	for (i = n/2;i< n; i++){
		R[j].x = pts[i].x;
		R[j].y = pts[i].y;
		j++;
	}

	DistancePoint LD = closestDist(L,n/2);
	DistancePoint RD = closestDist(R,n/2);
	float d;
	int index1,index2;
	bool Left = false;
	if(LD.distance<=RD.distance)
	{
		d = LD.distance;
		index1 = LD.index1;
		index2 = LD.index2;
		Left = true;
	}
	else{
		d = RD.distance;
		index1 = RD.index1;
		index2 = RD.index2;
	}


	vector<Point> Ysort;
	for( i = 0;i<n;i++){
		if( float(x)-d< float(pts[i].x) &&  float(pts[i].x)< float(x)+d)
		{
			Ysort.push_back(pts[i]);
		}
	}


	Quicksort2(Ysort, 0 ,Ysort.size()-1);
  	float min =d;
  	int index3,index4;
  	for(i = 0;i<Ysort.size();i++){
  		for (int j = i+1; j < Ysort.size() && (Ysort[j].y - Ysort[i].y) < min; ++j) 
            if (pairDist(Ysort[i],Ysort[j]) < min){
            	min = pairDist(Ysort[i], Ysort[j]); 
            	index3 = i;
            	index4 = j;
            } 
                
  	}
  	if(d <= min && Left)
  		return make_pair(L[LD.index1], L[LD.index2]) ;
  	if(d <= min && !Left)
  		return make_pair(R[RD.index1], L[RD.index2]) ;
  	else
  		return make_pair(Ysort[index3],Ysort[index4]);
  	
}




// A utility function to compute the distance between two points 
float pairDist(Point p1, Point p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ); 
} 

// Return minimum of two numbers
float min(float a,float b)
{
	if(a>=b)
		return b;
	else 
		return a;
}

// Naive Comparison of distance of points 
DistancePoint compare(Point pts[], int n)
{
	DistancePoint temppoint;
	temppoint.distance = 1000000000;
	for(int i =0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(pairDist(pts[i],pts[j]) < temppoint.distance)
			{
				temppoint.index1 = i;
				temppoint.index2 = j;
				temppoint.distance = pairDist(pts[i],pts[j]);
			}
		}
	}
	// cout<<temppoint.index1<<" "<<temppoint.index2<<" here"<<endl;
	// cout<<temppoint.distance<<" here"<<endl;
	return temppoint;
}

// Recursive function to find the cloest points  
DistancePoint closestDist(Point pts[],int  n){
	DistancePoint dl,dr,closest;
	if (n <= 3){
		 return compare(pts,n);
	}
	else{
		int mid = n/2;
		dl = closestDist(pts,n/2);
		dr = closestDist(pts+mid,n-mid);
		if(dl.distance>=dr.distance)
			closest = dr;
		else
			closest =dl;
		return closest;
	}
}


// Use this function to sort x
void Quicksort1(Point array[], int low, int high)
{
	if(low <high)
	{
		int first = low;
		int last = high;
		for(int i = low;i< high;i++){
			if(array[i].x < array[last].x){
				int temp_x = array[first].x; 
				int temp_y = array[first].y;
				array[first].x = array[i].x; 
				array[first].y = array[i].y;
				array[i].x = temp_x;
				array[i].y =temp_y;
				first++;
			}
		}

		int temp_x = array[last].x; 
		int temp_y = array[last].y;
		array[last].x = array[first].x; 
		array[last].y = array[first].y;
		array[first].x = temp_x;
		array[first].y =temp_y;

		Quicksort1(array,  low, first -1);
		Quicksort1(array, first+1,  high);

	}

}

// Use this function to sort y
void Quicksort2(vector<Point>& array, int low, int high)
{
	if(low <high)
	{
		int first = low;
		int last = high;
		for(int i = low;i< high;i++){
			if(array[i].y < array[last].y){
				int temp_x = array[first].x; 
				int temp_y = array[first].y;
				array[first].x = array[i].x; 
				array[first].y = array[i].y;
				array[i].x = temp_x;
				array[i].y =temp_y;
				first++;
			}
		}

		int temp_x = array[last].x; 
		int temp_y = array[last].y;
		array[last].x = array[first].x; 
		array[last].y = array[first].y;
		array[first].x = temp_x;
		array[first].y =temp_y;

		Quicksort2(array,  low, first -1);
		Quicksort2(array, first+1,  high);

	}

}

