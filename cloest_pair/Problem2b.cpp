#include "closest(1).h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int main() {

	Point pts[] = {{2, 3}, {15, 30}, {40, 25}, {6, 1}, {12, 8}, {3, 4},{5,6},{10,10}};
	int n = sizeof(pts) / sizeof(pts[0]); 
	pair<Point, Point> p = findClosestPairOptimal(pts, n);

	cout << "The closest pair of points is: " << p.first.toString() << " and " << p.second.toString() << endl;
	// cout << "The distance betwee them is: " << to_string(pairDist(p.first, p.second)) << endl;

	return 0;
}