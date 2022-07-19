/*Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
Example-
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0; i<s.size(); i++)
        {
            res += expandCenter(i, i, s);
            res += expandCenter(i, i+1, s);
        }
        return res;
    }
    int expandCenter(int lo, int hi, string s)
    {
        int noOfPalindromes =0;
        while(lo>=0 && hi<=s.size()-1 && s[lo]==s[hi])
        {
            lo--;
            hi++;
            noOfPalindromes++;
        }
        return noOfPalindromes;
    }
};
