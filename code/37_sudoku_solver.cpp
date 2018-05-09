class Solution {
public:
    bool isvalid(vector< vector<char>> &b, int idx){
        bool ch[3][9]={false};
        int r=idx/9;
        int c=idx%9;
        int snum=idx/9;
        int cr;
        int sr,sc;
        for(int i=0;i<9;i++){
            if(b[r][i]!='.'){
                cr=b[r][i]-'1';
                if(ch[0][cr]==false)
                    ch[0][cr]=true;
                else 
                    return false;
            }
            if(b[i][c]!='.'){
                cr=b[i][c]-'1';
                if(ch[1][cr]==false)
                    ch[1][cr]=true;
                else 
                    return false;
            }
            sr=r/3*3+i/3%3;
            sc=c/3*3+i%3;
            if(b[sr][sc]!='.'){
                cr=b[sr][sc]-'1';
                if(ch[2][cr]==false)
                    ch[2][cr]=true;
                else
                    return false;
            }
        }
        return true;
    }
    
    bool solver(vector< vector<char>> &b, int idx){
        /*
        *  1. know the condition to going deep for validation or going wide for another try
	*  2. check array in isvalide() function should be filled with true or some fixed value( not the value cr, as cr could be 0)
        */
        int r=idx/9;
        int c=idx%9;
        int check_result=false;
        if(isvalid(b,idx)==false){
            return false;
        }else{
            if(idx==80){
                return true;
            }else{
                while(idx<81&&b[idx/9][idx%9]!='.'){
                    idx++;
                }
                if(idx==81){
                    return true;
                }else{
                    for(int i=0;i<9;i++){
                        b[idx/9][idx%9]=char(i+'1');
                        // if(idx==2)
                            // printf("try: %d\n",i+1);
                        if(isvalid(b,idx)==true){
                            check_result=solver(b,idx);
                            if(check_result==true)
                                return true;
                        }                            
                        b[idx/9][idx%9]='.'; //actually need this
                    }
                    return false;
                }
            }                
        }
            
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0);
    }
};
