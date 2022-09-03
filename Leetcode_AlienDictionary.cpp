class Solution{
    public:
    string res;
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,list<char>> adjacencyList;
        unordered_set<char> visited, visitedInPath, allLetters;
        int n=N, i,j, k;
        //build adjacency list
        for(i=1; i<n; i++) {
            j=0;
            while(j<dict[i-1].size() && j<dict[i].size() && dict[i-1][j] == dict[i][j]){
                if(allLetters.find(dict[i][j])==allLetters.end())
                    allLetters.insert(dict[i][j]);
                j++;
            }
            if(j<dict[i-1].size() && j<dict[i].size()) {
                //add relation to the adjacencyList
                adjacencyList[dict[i-1][j]].push_back(dict[i][j]);
                    //cout<<"Adding to adjacency list "<<words[i-1][j]<<"->"<<words[i][j]; 
            }
            k=j;
            while(j<dict[i-1].size())
            {
                if(allLetters.find(dict[i-1][j])==allLetters.end())
                    allLetters.insert(dict[i-1][j]);
                j++;
            }
            while(k<dict[i].size())
            {
                if(allLetters.find(dict[i][k])==allLetters.end())
                    allLetters.insert(dict[i][k]);
                k++;
            }
        }
        //traverse the graph
        for(auto c=allLetters.begin(); c!=allLetters.end(); c++)
            topologicalSortI(*c, adjacencyList, visited, visitedInPath);
        return res;
    }
    void topologicalSortI(char c, unordered_map<char,list<char>>& adjacencyList, unordered_set<char>& visited, unordered_set<char>& visitedInPath)
    {
        if(visitedInPath.find(c)!=visitedInPath.end())  return ;
        if(visited.find(c)!=visited.end())  return;
        for(auto node=adjacencyList[c].begin(); node!=adjacencyList[c].end(); node++)
            topologicalSortI(*node, adjacencyList, visited, visitedInPath);
        //cout<<"\nAdding "<<c;
        res.insert(0, 1, c);
        visited.insert(c);
        visitedInPath.insert(c);
    }
};
