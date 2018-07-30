//============================================================================
// Name        : testc.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
bool isMatch(string s, string p) {
	/* *******************************************************
	 * 1. Initial state of dp[0][j]
	 * 2. when p[j]==*, it has three states: None, 1 or more than 1
	 * *******************************************************
	 */
    size_t ss=s.size(),sp=p.size();
    if(ss==0&&sp==0){// When both strings are empty: true
        return true;
    }else if(ss!=0 && sp==0){ //When only p is empty: false
        return false;
    }else if(ss==0&&sp!=0){
        for(size_t i =0;i<sp;i++){
            if(p[i]!='*'){
                return false;
            }
        }
        return true;
    }else{
        bool dp[ss+1][sp+1]={false};
        memset(dp,0,(ss+1)*(sp+1)*sizeof(bool));
        for(size_t j=0;j<sp;j++){

            if(p[j]=='*'){
                if(j==0){
                    dp[0][0]=true;
                    dp[0][1]=true;
                }else{
                    dp[0][j+1]=dp[0][j];
                }
            }else{
                dp[0][j+1]=false;
            }

        }
        for(size_t i=0;i<ss;i++){
            for(size_t j=0;j<sp;j++){
                if(i==0&&j==0){
                    //Initialization state
                    if(s[0]==p[0]||p[0]=='?'||p[0]=='*'){
                        dp[1][1]=true;
                    }
					else{
							dp[i+1][j+1]=false;
						}
                }else{
                    if(s[i]==p[j]||p[j]=='?'){
                        dp[i+1][j+1]=dp[i][j];
                    }else if(p[j]=='*'){
                            dp[i+1][j+1]=dp[i][j+1]||dp[i][j]||dp[i+1][j];//This corresponds 3 cases: 1). Equals s[i-1]+s[i], 2). Equals s[i], 3). Does not equal any
                    }else{
                        dp[i+1][j+1]=false;
                    }
                }
            }
        }
        return dp[ss][sp];
    }
    return false;
}

int jump(vector<int> & nums){
	int idx=0;
	int step=0;
	int sn=nums.size(),curr_max=0;
	while(idx<sn-1){
		curr_max=0;
		for(int i =0;i<nums[idx];i++){
			if(curr_max<i+nums[idx+i]){
				curr_max=i+nums[idx+i];
				step=step+1;
				idx=idx+i;
			}
		}
	}
	return step;
}


//int jump(vector<int> & nums){
//	//Recursive version
//
//	if(nums.empty())
//		return 0;
//
//	int curr_step=0,min_step=0;
//	for(int i =0;i<nums[0];i++){
//		vector<int> sub_array(nums.begin()+i, nums.begin()+nums.size());
//		curr_step=jump(sub_array);
//		if(min_step > curr_step){
//			min_step=curr_step;
//		}
//	}
//	return min_step+1;
//}
int main() {
//	string s="a";
//	string p="**a";

//	string s="aa";
//	string p="*";

	string s="abc";
	string p="a*b*c";
	int res=isMatch(s,p);
	printf("results: %d\n",res);
	return 0;
}

