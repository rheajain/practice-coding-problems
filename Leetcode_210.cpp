class Solution {
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> dependancyList(numCourses);
        int i,j;
        vector<bool> visited(numCourses, false);
        unordered_set<int> inPathVisited;
        for(i=0; i<prerequisites.size(); i++)
        {
            dependancyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(i=0; i<numCourses; i++)
        {
            if(!dfs(i, dependancyList, visited, inPathVisited))
                return vector<int>();
        }
        vector<int> ans;
        for(i=res.size()-1; i>=0; i--)
            ans.push_back(res[i]);
        return ans;
    }
    int dfs(int i, vector<list<int>>& dependancyList, vector<bool>& visited, unordered_set<int> inPathVisited)
    {
        if(inPathVisited.find(i)!=inPathVisited.end())  return false;
        if(visited[i])  return true;
        visited[i]=true;
        inPathVisited.insert(i);
        for(auto node=dependancyList[i].begin(); node!=dependancyList[i].end(); node++ )
            if(!dfs(*node, dependancyList, visited, inPathVisited))
                return false;
        res.push_back(i);
        return true;
    }
};
