/*A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.*/


class Solution {
public:
    int n;
    int waysToSplit(vector<int>& nums) {
        const int mod=1e9+7;
        int i=0, left, k, j, mid, noOfWays=0, lowerRangeIndex, upperRangeIndex;
        n=nums.size();
        int sumArr[n];
        
        sumArr[0]=nums[0];
        for(i=1; i<n; i++)
        {
            sumArr[i] = sumArr[i-1] + nums[i];
        }
        
        for(i=1; i<n-1; i++)
        {
            left = sumArr[i-1];
            if(left> sumArr[n-1]-sumArr[i-1])
            {
                continue;
            }
            
            //start binary search logic
            j=i+1;
            k=n-1;
            
            lowerRangeIndex = getThresholdIndex(j, k, true, left, sumArr);
            upperRangeIndex = getThresholdIndex(j, k, false, left, sumArr);
            //cout<<"lowerRange="<<lowerRangeIndex<<" upperRange="<<upperRangeIndex<<"\n";
            if(lowerRangeIndex==-1||upperRangeIndex==-1)
            {
                continue;
            }
            noOfWays = (noOfWays + (upperRangeIndex-lowerRangeIndex+1)%mod) %mod;
        }
        return noOfWays;
    }
    
    int getThresholdIndex(int i, int j, bool isLower, int leftSum, int* sumArr)
    {
        int mid, res=-1, midSum, rightSum;
        while(i<=j)
        {
            mid =((j-i)/2)+i;
            rightSum = sumArr[n-1] - sumArr[mid-1];
            midSum = sumArr[mid-1] - leftSum;
            if( midSum>rightSum && midSum<leftSum)
            {
                break;
            }
            else if( midSum>rightSum && midSum>=leftSum)
            {
                j=mid-1;
            }
            else if(midSum<leftSum && midSum<=rightSum)
            {
                i=mid+1;
            }
            else if(midSum <= rightSum && leftSum <= midSum)
            {
                res=mid;
                if(isLower)
                {
                    j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
        }
        return res;
    }
    
};
