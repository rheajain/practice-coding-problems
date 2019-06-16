//No two zeros can be placed next to each other
//Input- no of digits
//Output- no of possible numbers that can be represented by those many digits

#include <iostream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;

int main()
{
 
  int n;
  cin>>n;
  
  vector<vector<int>> arr(n+1,vector<int>(2));
  
  arr[0][0] = 0;
  arr[0][1] = 0;
  arr[1][0] = 1;
  arr[1][1] = 1;
  
  for(int j=2; j<=n; j++){
      arr[j][0] = arr[j-1][1];
      arr[j][1] = arr[j-1][1] + arr[j-1][0];
  }
  
  cout<<arr[n][0]+arr[n][1];
 
}
