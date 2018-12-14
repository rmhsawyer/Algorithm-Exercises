#include <bits/stdc++.h> 
#include "trie.h"
#include <string>
#include <iostream>
using namespace std;

int main(){


	Trie tree;
	string key1 = "trying";
	string key2 = "apple";
	int value2 = 5;
	int value = 10;
	tree.insert(key1, value);
	int find = tree.search(key1);
	tree.insert(key2, value2);
	cout<< tree.map_size << " ," << tree.tree_size <<endl;

	tree.remove(key1);
	cout<< tree.map_size << " ," << tree.tree_size <<endl;
	find = tree.search(key2);
	cout<< find<<endl;

	return 0;
}