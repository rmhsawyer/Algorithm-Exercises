// Minghe Ren U84996581

#include "BST.cpp"
#include "MyBST.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(){
	int line ;
	MyBST Tree1, Tree2;
	ifstream File1("./T1.txt");
	ifstream File2("./T2.txt");
	while (File1 >> line) {
    Tree1.insert(line);
	}
	while (File2 >> line) {
    Tree2.insert(line);
	}


	vector<Rotation> rotateresult = Tree2.transform(Tree1);

	for(int i = 0;i<rotateresult.size();i++){
		string s = rotateresult[i].print();
		cout << s <<endl;
	}

	// Recover the trees
	while (File1 >> line) {
    Tree1.insert(line);
	}
	while (File2 >> line) {
    Tree2.insert(line);
	}

	return 0;

}