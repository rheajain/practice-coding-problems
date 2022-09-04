#include <list>
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string res;
    string alienOrder(vector<string> &words) {
        unordered_map<char,list<char>> adjacencyList;
        unordered_set<char> visited, visitedInPath, allLetters;
        int n=words.size(), i,j, k;
        //build adjacency list
        for(i=1; i<n; i++) {
            j=0;
            while(j<words[i-1].size() && j<words[i].size() && words[i-1][j] == words[i][j]){
                if(allLetters.find(words[i][j])==allLetters.end())
                    allLetters.insert(words[i][j]);
                j++;
            }
            if(j<words[i-1].size() && j<words[i].size()) {
                //add relation to the adjacencyList
                adjacencyList[words[i-1][j]].push_back(words[i][j]);
            }
            else {
                if(words[i-1].size()>words[i].size())
                {
                    return "";
                }
            }
            k=j;
            while(j<words[i-1].size())
            {
                if(allLetters.find(words[i-1][j])==allLetters.end())
                    allLetters.insert(words[i-1][j]);
                j++;
            }
            while(k<words[i].size())
            {
                if(allLetters.find(words[i][k])==allLetters.end())
                    allLetters.insert(words[i][k]);
                k++;
            }
        }
        //traverse the graph
        for(i='z'; i>='a'; i--)
        {
            if(allLetters.find((char)i)!=allLetters.end())
                if(!topologicalSortI(i, adjacencyList, visited, visitedInPath))
                    return "";
        }
        return res;
    }
    bool topologicalSortI(char c, unordered_map<char,list<char>>& adjacencyList, unordered_set<char>& visited, unordered_set<char> visitedInPath)
    {
        if(visitedInPath.find(c)!=visitedInPath.end())  {return false;}
        if(visited.find(c)!=visited.end())  return true;
        visited.insert(c);
        visitedInPath.insert(c);
        for(auto node=adjacencyList[c].begin(); node!=adjacencyList[c].end(); node++)
            if(!topologicalSortI(*node, adjacencyList, visited, visitedInPath))
                return false;
        res.insert(0, 1, c);
        return true;
    }
};
