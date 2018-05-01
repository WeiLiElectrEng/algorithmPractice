// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
bool isValidSudoku(vector<vector<char>> &board);
int main() {
        printf("hello\n");
        return 0;

}

bool isValidSudoku(vector<vector<char>> &board){
        /*  Be careful the condition to check valid for each element
        *   lut[i][dig]==0&&lut[9+j][dig]==0&&lut[k][dig]==0
        */
        int lut[9*3][9]={0};
        int dig=0,k=18;
        for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                        k=18+i/3*3+j/3;
                        if(board[i][j]!='.')
                        {
                                dig=board[i][j]-'1';
                                if(lut[i][dig]==0&&
                                   lut[9+j][dig]==0&&
                                   lut[k][dig]==0)
                                {
                                        lut[i][dig]=1;
                                        lut[9+j][dig]=1;
                                        lut[k][dig]=1;
                                }else{

                                        return false;
                                }
                        }
                }
        }

        return true;


}

~
~
~
~
~

