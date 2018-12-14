// Minghe Ren U84996581
// Some ideas refered from https://www.geeksforgeeks.org/trie-insert-and-search/
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26; // Consider only lowercase letters for this problem

struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	int val;
	TrieNode() {
		val = 0; // Default
		for (int i=0;i<ALPHABET_SIZE;i++) {
			children[i] = NULL;
		}
	}
};

class Trie {

public:
	TrieNode *root;
	int map_size; // size of the map
	int tree_size; // size of the tree
	Trie() {root = new TrieNode(); map_size = 0; tree_size = 1;}

	// Return a new Node
	struct TrieNode* newNode(void) {
		struct TrieNode *pNode = new TrieNode();
		return pNode;
	}

	/* 
		Insert (key, val) into the trie. If key is already present, update the corresponding value.
		Update map_size and tree_size accordingly. If key is already present, these numbers should not change.
	*/
	void insert(string key, int val) {
		struct TrieNode *pCrawl = root;
		for(int i =0; i< key.length(); i++){
			int index = key[i] - 'a';
			if(!pCrawl -> children[index]){
				pCrawl->children[index] = newNode();
				++tree_size;
			}

			pCrawl = pCrawl -> children[index];
		}

		pCrawl ->val = val;
		++map_size;
	}

	/*
		Search key and return the corresponding value. Return 0 if key is not present in the trie.
	*/
	int search(string key) {
		struct TrieNode *pCrawl = root;
		for(int i =0; i< key.length(); i++){
			int index = key[i] -'a';
			if(!pCrawl->children[index])
				return 0;
			pCrawl = pCrawl->children[index];
		}
		if( pCrawl != NULL)
			return pCrawl->val; // Modify the return value appropriately in your implementation
		else
			return 0;
	}

	/*
		Remove key from the trie. Update map_size and tree_size accordingly. 
		If the node corresponding to the key is a leaf node, you should remove the node. 
		If the node corresponding to the key is not a leaf node, you should update its value accordingly but should not remove the node. 
	*/
	void remove(string key) {
		struct TrieNode *pCrawl = root; 
		int parentindex;
		bool leaf = true;
		for(int i = 0;i<key.length();i++){
			int index = key[i] - 'a';
			if(!pCrawl->children[index])
				return;
			if ( i!= key.length()-1){
				pCrawl = pCrawl->children[index];
			}
			else{
				parentindex = index;
				break;
			}
		}

		for(int i=0;i<ALPHABET_SIZE;i++){
			if (pCrawl->children[parentindex]->children[i] != NULL)
			{	
				leaf =false;
			}
		}
		if(leaf){
			pCrawl->children[parentindex] = NULL;
			--map_size;
			--tree_size;
			return;
		}

		else{
			pCrawl->children[parentindex]->val =0;
			--map_size;
			return;
		}			
	}

};

