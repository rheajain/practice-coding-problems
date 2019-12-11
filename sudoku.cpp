//9x9 sudoku solver (brute force!)

bool checkRow(int i, int k, vector<vector<char>> &A){
    char c= '0'+ k;
    for(int l=0; l<9; l++){
        if(A[i][l]==c){
            return false;
        } 
    }
    return true;
}

bool checkCol(int j, int k, vector<vector<char>> &A){
    char c= '0'+ k;
    for(int l=0; l<9; l++){
        if(A[l][j]==c){
            return false;
        } 
    }
    return true;
}

bool checkBox(int i, int j, int k, vector<vector<char>> &A){
    char c= '0'+ k;
    int x = (i/3)*3;
    int y = (j/3)*3;
    int xm= x+3, ym=y+3, l;
    for(x; x<xm; x++){
        for(l=y; l<ym; l++){
            if(A[x][l]==c){
                return false;
            }
        } 
    }
    return true;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    cout<<"sa";
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i, j, x, y, k;
    bool found;
    vector<int> si, sj;
    //cout<<"size="<<A.size();
    for(i=0; i<A.size(); i++){
        for(j=0; j<A.size(); j++){
            //cout<<"For i="<<i<<" j="<<j<<endl;
            if(A[i][j]=='.'){
                found = false;
                for(k=1; k<=9; k++){
                    //cout<<"i="<<i<<" j="<<j<<endl;
                    if(checkRow(i, k, A) && checkCol(j, k, A) && checkBox(i, j, k, A)){
                        //push in stack
                        si.push_back(i);
                        sj.push_back(j);
                        found = true;
                        //cout<<"i="<<i<<" j="<<j<<endl;
                        A[i][j]='0'+k;
                        //cout<<"A["<<i<<"]"<<"["<<j<<"]="<<A[i][j]<<endl;
                    }
                }
                if(!found){
                    //pop stack and increment
                    do {
                        //if(si.size()>0 && sj.size()>0){
                            x=si[si.size()-1];
                            y=sj[sj.size()-1];
                            
                            if(A[x][y]!='9'){
                                A[x][y]=A[x][y]+1;
                                i=x;
                                j=y;
                                //cout<<"Replaced i="<<i<<" j="<<j<<endl;
                                break;
                            } else{
                                si.pop_back(); sj.pop_back();
                                A[x][y]='.';
                            }
                        // } else{
                        //     //cout<<"At i="<<i<<" j="<<j<<" shit went down!"<<endl;
                        //     break;
                        // }
                    } while(1);
                }
            }
        }
    }
}
