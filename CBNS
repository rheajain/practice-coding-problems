// Generate Constrained Boolean Number System

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char** addCBNSnumbersForNdigits (int n, char ***cbns, int size[]){
    
    char newArray = NULL;
    int maxSizeOfArray ;//= 2*(sizeof(cbns[n-2])/sizeof(cbns[n-2][0]));
    maxSizeOfArray = 2*size[n-2];
    
    int sizeOfPrevArray = size[n-2];// sizeof(cbns[n-2])/sizeof(cbns[n-2][0]);
    
    char **tempArray = (char **) malloc(sizeof(char *) * maxSizeOfArray);
    int j=0;
    char arrayOfOne[] = {'1', '\0'};
    char arrayOfZero[] = {'0', '\0'};
    //Once for 0
        for(int i=0; i<sizeOfPrevArray; i++){
            
            
            if(cbns[n-2][i][0]=='1') {
                
                //add all nos with padding 0 at the beginning
                tempArray[j] = (char *) malloc (sizeof(char) * (n+1));
                strcpy(tempArray[j], arrayOfZero);
                strcat(tempArray[j++], cbns[n-2][i]);
               
            } else{//digit is 0
                
            }
        }
    //Once for 1
        
        for(int i=0; i<sizeOfPrevArray; i++){
            if(cbns[n-2][i][0]=='1') {
                //add all nos with padding 0 at the beginning
                tempArray[j] = (char *) malloc (sizeof(char) * (n+1));
              
                strcpy(tempArray[j], arrayOfOne);
                strcat(tempArray[j++], cbns[n-2][i]);
                
            } else{//digit is 0
                //add all nos with padding 1 at the beginning
                tempArray[j] = (char *) malloc (sizeof(char) * (n+1));
                strcpy(tempArray[j], arrayOfOne);
                strcat(tempArray[j++], cbns[n-2][i]);
                
            }
        }
    tempArray[j] = NULL;
    size[n-1]=j;
    return tempArray;
}
void exploreCBNSforNdigits (int n, char ***cbns){
    //int maxSizeOfArray = 2*(sizeof(cbns[n-2])/sizeof(cbns[n-2][0]));   //sizeof(int)
    //int maxSizeOfArray = 2* cbns[n-2].size();
    /*for(int i=0; i<cbns[n-2].size(); i++){
        if(cbns[n-2][i]%(10^(n-2))==1){
            
        } else{//digit is 0
        
        }*/
}

int main()
{
  /*std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
  cout<<"rhea";*/
 
  int n;
  char ***cbns;
  cin>>n;
  cbns = (char ***) malloc(n*sizeof(char **));
 
  
  
  //Preparing base case
  cbns[0] = (char **) malloc(2*sizeof(char *));
  
  char e[]= {'0', '\0'};
  cbns[0][0] = e;
  
  char d[] = {'1', '\0'};
  cbns[0][1] = d;
  char** arr;
  
  //cbns[0][1][] = '1';
  int size[100];
  size[0]=2;
  for(int i=2; i<=n; i++){
      
      arr = addCBNSnumbersForNdigits(i, cbns, size);
      cbns[i-1] = arr;
      
  }
  cout<<size[n-1];
  
 
}
