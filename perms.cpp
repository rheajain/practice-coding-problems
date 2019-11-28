#include <iostream>
#include<vector>
using namespace std;

int r =0;
void addPerms(char c, int n){
    if(n==1){
        r++;
    } else if(c=='a'){
        addPerms('e', n-1);
    }else if(c=='e'){
        addPerms('o', n-1);
        addPerms('u', n-1);
    }else if(c=='i'){
        addPerms('a', n-1);
        addPerms('e', n-1);
        addPerms('o', n-1);
        addPerms('u', n-1);
    }else if(c=='o'){
        addPerms('i', n-1);
    }else if(c=='u'){
        addPerms('a', n-1);
        addPerms('e', n-1);
    }
}
int getPerms(char c, int n, vector<int> &a, vector<int> &e, vector<int> &i, vector<int> &o, vector<int> &u){
    int m=0;
    switch ('c'){
    case 'a': if(a[n]!=0){
                return a[n];
            }
            break;
    case 'e': if(e[n]!=0){
                return e[n];
            }
            break;
    case 'i': if(i[n]!=0){
                return i[n];
            }
            break;
    case 'o': if(o[n]!=0){
                return o[n];
            }
            break;
    case 'u': if(u[n]!=0){
                return u[n];
            }
            break;
            
    }
    if(n==1){
        m=1;
    } else if(c=='a'){
        m += getPerms('e', n-1, a, e, i, o, u);
    }else if(c=='e'){
        m+=getPerms('o', n-1, a, e, i, o, u);
        m+=getPerms('u', n-1, a, e, i, o, u);
    }else if(c=='i'){
        m+=getPerms('a', n-1, a, e, i, o, u);
        m+=getPerms('e', n-1, a, e, i, o, u);
        m+=getPerms('o', n-1, a, e, i, o, u);
        m+=getPerms('u', n-1, a, e, i, o, u);
    }else if(c=='o'){
        m+=getPerms('i', n-1, a, e, i, o, u);
    }else if(c=='u'){
        m+=getPerms('a', n-1, a, e, i, o, u);
        m+=getPerms('e', n-1, a, e, i, o, u);
    }
    switch ('c'){
    case 'a': a[n] = m;
            break;
    case 'e': e[n] = m;
            break;
    case 'i': i[n] = m;
            break;
    case 'o': o[n] = m;
            break;
    case 'u': u[n] = m;
            break;
    }
    return m;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int ans=0;
	std::vector<int> a(n,0);
	std::vector<int> e(n,0);
	std::vector<int> i(n,0);
	std::vector<int> o(n,0);
	std::vector<int> u(n,0);
  
  //plain recursion- O(n)=n!
	addPerms('a', n);
	addPerms('e', n);
	addPerms('i', n);
	addPerms('o', n);
	addPerms('u', n);
	cout<<r;
	
  //recursion with memoization :)
 	ans+= getPerms('a', n, a, e, i, o, u);
 	ans+= getPerms('e', n, a, e, i, o, u);
 	ans+= getPerms('i', n, a, e, i, o, u);
 	ans+= getPerms('o', n, a, e, i, o, u);
 	ans+= getPerms('u', n, a, e, i, o, u);
 	cout<<ans;
	return 0;
	
}
