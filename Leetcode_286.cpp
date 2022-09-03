class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
     int m,n;
    void wallsAndGates(vector<vector<int>> &rooms) {
        int i, j;
        queue<pair<int, int>> q; pair<int,int> currRoom;
        m=rooms.size();
        n=rooms[0].size();
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(rooms[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        while(!q.empty())
        {
            currRoom = q.front();
            i=currRoom.first; j=currRoom.second;
            if(isValidIndex(i-1,j)&& rooms[i-1][j]==INT_MAX)
            {   rooms[i-1][j]=rooms[i][j]+1;  q.push(make_pair(i-1,j));}
            if(isValidIndex(i+1,j)&& rooms[i+1][j]==2147483647)
            {   rooms[i+1][j]=rooms[i][j]+1;  q.push(make_pair(i+1,j));}
            if(isValidIndex(i,j-1)&& rooms[i][j-1]==2147483647)
            {   rooms[i][j-1]=rooms[i][j]+1;  q.push(make_pair(i,j-1));}
            if(isValidIndex(i,j+1)&& rooms[i][j+1]==2147483647)
            {   rooms[i][j+1]=rooms[i][j]+1;  q.push(make_pair(i,j+1));}
            q.pop();
        }
    }
    int isValidIndex(int i, int j)
    {
        if(i<0|| j<0|| i>=m || j>=n)    return false;
        return true;
    }
};
