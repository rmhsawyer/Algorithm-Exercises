//Minghe Ren U84996581
#include<vector>
#include<unordered_map> 
#include<cstdint>  //For using INT16_MAX
using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int x_val, int y_val) : x(x_val), y(y_val) {}
};

/* 
	A function to find the median of three numbers
*/
float MedianOfThree(int a, int b, int c){
	return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

/* 
	A function to find the median of four numbers
*/

float MedianOfFour(int a, int b, int c, int d){
	return  (a + b + c + d - max(a, max(b, max(c, d))) - min(a, min(b, min(c, d)))) / 2.0;
}

/* 
	Find the median of two sorted vectors v1 and v2, of size n and m respectively.
    The running time of your algorithm should be better than O(n+m).
    The time complexity will be O(logn + logm)
*/
float findMedian(vector<int>& v1, vector<int>& v2) {
    static int firsttime1 ;
	int v1_size = v1.size();
	int v2_size = v2.size();

	//Make sure size of v1 is smaller than v2
	if( firsttime1 == 0  && v1_size > v2_size){
		firsttime1 = 1; 
		v1.swap(v2);
		v1_size = v1.size();
		v2_size = v2.size();	
	}
	
	//Base cases
	if(v1_size == 0){
		if(v2_size == 0){return -1;} 
		if(v2_size % 2 == 0){return (float)(v2[v2_size/2] + v2[v2_size/2-1])/2;}
		return v2[v2_size/2];
	}
	if(v1_size == 1){
		if(v2_size == 1){return (v1[0]+v2[0])/2.0;}
		if(v2_size % 2 != 0){
			float mid_of_three = MedianOfThree(v1[0], v2[v2_size/2 - 1] , v2[v2_size/2 + 1]);
			return (v2[v2_size/2]+mid_of_three)/2.0;
		}
		return MedianOfThree(v2[v2_size/2] , v2[v2_size/2 - 1] , v1[0]);
	}
	if(v1_size == 2){
		if(v2_size == 2){
			return MedianOfFour(v1[0] , v1[1] , v2[0] , v2[1]);
		}
		if(v2_size % 2 != 0){
			return MedianOfThree(v2[v2_size/2], max(v1[0], v2[v2_size/2 - 1]) , min(v1[1], v2[v2_size/2 + 1]));
		}
		return MedianOfFour(v2[v2_size/2], v2[v2_size/2 - 1], max(v1[0], v2[v2_size/2 - 2]), min(v1[1], v2[v2_size/2 + 1]));
	}

	//Iterate the function with complexity of O(logn)
	int index1 = (v1_size-1)/2;
	int index2 = (v2_size-1)/2;;
	int v1_mid = v1[index1];
	int v2_mid = v2[index2];
	if(v1_mid>v2_mid){
		vector<int> v1_half,v2_half;
		auto it1 = v1.begin();
		while(it1 != v1.begin()+v1_size/2){
			v1_half.push_back(*it1);
			it1++;
		}
		auto it2 = v2.begin()+v1_size/2+1;
		while(it2 != v2.end()){
			v2_half.push_back(*it2);
			it2++;
		}
		return findMedian(v1_half,v2_half);
	}

	vector<int> v1_half,v2_half;
	auto it1 = v1.begin() + v1_size/2 + 1;
	while(it1 != v1.end()){
			v1_half.push_back(*it1);
			it1++;
		}
	auto it2 = v2.begin();
	while(it2 != v2.begin() + v1_size/2){
			v2_half.push_back(*it2);
			it2++;
		}
	return findMedian(v1_half,v2_half);
}




/*
	Find the maximum number of points that lie one the same line on a 2D plane. 
	Time complexity O(n^2)
*/
vector<Point> maxCollinearPoints(vector<Point>& pts) {
	int NumofPoints = pts.size();
	int MaxNumber = 1;
	vector<Point> MaxPoints;
	//Construct a slope map
	unordered_map<float, vector<Point>> slopes;

	//O(n^2) complexity to compute the slope of point pairs
	for(int i = 0; i < NumofPoints; i++){
		slopes.clear();
		//For overlapping points, this won't be considerated in the problem
		int overlap = 0;
		for(int j = i+1; j < NumofPoints; j++){
			if(pts[j].x == pts[i].x && pts[j].y == pts[i].x){
				overlap++;
				continue;
			}
			//Compute the slope
			float slope = (pts[j].x == pts[i].x)? INT16_MAX : (float)(pts[j].y - pts[i].y) / (pts[j].x - pts[i].x);
			if(slopes[slope].empty())
				slopes[slope].push_back(pts[i]);
			slopes[slope].push_back(pts[j]);
		}
		MaxNumber = max(MaxNumber, overlap);
		for(auto slope : slopes){
			if(slope.second.size() + overlap >= MaxNumber){
				MaxNumber = slope.second.size() + overlap;
				MaxPoints = slope.second;
			}
		}
	}
	return MaxPoints;
	// Return appropriately in your implementation.
}
