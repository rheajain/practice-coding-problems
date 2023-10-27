// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0, cons, next;
        for(auto x:nums)
        {
            s.insert(x);
        }
        for(auto x:nums)
        {
            cons=1;
            if(s.find(x-1)==s.end()) //check if number is the start of a sequence, only then check length
            {
                next = x+1;
                while(s.find(next)!= s.end())
                {
                    next++;
                    cons++;
                }
            }
            ans = cons>ans ? cons : ans;
        }
        return ans;
    }
};
