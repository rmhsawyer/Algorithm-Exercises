// Minghe Ren U84996581
// Some ideas refered from https://www.geeksforgeeks.org/archives/18212 
#include <vector>
#include <list>

using namespace std;

class Problem2b {

public:

	// The idea is to build a Directed Graph to represent the dependencies. 
	// If there is a cycle in the graph, jobs can't be done
	int NumOfVertex;
	list<int> *adjacency;

	// Constructor
	Problem2b(int V){ 
	    NumOfVertex = V; 
	    adjacency = new list<int>[V]; 
	} 
  
  	// Adding Edge
	void AddEdge(int v1, int v2 ){ 
	    adjacency[v1].push_back(v2);
	} 

	// Detect if there is a cycle in graph.
	// Reference from https://www.geeksforgeeks.org/archives/18212 
	bool DetectCycle(){ 
	    bool *visited = new bool[NumOfVertex]; 
	    bool *recStack = new bool[NumOfVertex]; 
	    for(int i = 0; i < NumOfVertex; i++){ 
	        visited[i] = false; 
	        recStack[i] = false; 
	    } 
	    for(int i = 0; i < NumOfVertex; i++){
	        if(DFS(i, visited, recStack)) 
	            return true; 
	    }
	    return false; 
	} 
	// Reference from https://www.geeksforgeeks.org/archives/18212 
	bool DFS(int v, bool visited[], bool *recStack) 
	{ 
	    if(visited[v] == false){  
	        visited[v] = true; 
	        recStack[v] = true; 
	        for(list<int>::iterator i = adjacency[v].begin(); i != adjacency[v].end(); ++i){ 
	            if(!visited[*i] && DFS(*i, visited, recStack)) 
	                return true; 
	            else if (recStack[*i]) 
	                return true; 
	        } 
	    } 
	    recStack[v] = false; 
	    return false; 
	}


    bool canFinish(int numJobs, vector<pair<int, int>>& dependencies) {
    	// For some easy cases
    	if(numJobs ==0 && numJobs ==1)
    		return true;
    	if(numJobs == 2){
    		if(dependencies[0].first == dependencies[1].second && dependencies[0].second == dependencies[1].first)
    			return false;
    		else
    			return true;
    	}
    	Problem2b graph(numJobs); 
    	for(int i=0;i < dependencies.size();i++){
    		graph.AddEdge(dependencies[i].first,dependencies[i].second);
    	}
    	if(graph.DetectCycle())
        	return false; // Modify the return value appropriately in your implementation   
        else
        	return true; 
    }
    
    // Helper methods here
    
};