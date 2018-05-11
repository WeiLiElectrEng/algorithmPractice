//============================================================================
// Name        : testc.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int firstMissingPositive(vector<int>& nums);
int main() {
	vector<int> in={2};
	int res;
	res=firstMissingPositive(in);
	printf("res: %d\n",res);

	return 0;
}

int firstMissingPositive(vector<int>& nums) {
	/*
	 * 1. empty array
	 * 2. User 1 based sorting is easier
	 */
	if(nums.empty())
		return 1;
    int res=0,tmp;

    for(int i=0;i<int(nums.size());i++){
    	while(nums[i]>0&&nums[i]<=int(nums.size())){
    		if(nums[nums[i]-1]==nums[i])
    			break;
    		else{
    			tmp=nums[nums[i]-1];
    			nums[nums[i]-1]=nums[i];
    			nums[i]=tmp;
    		}
    	}
    }

    int i;
    for( i=0;i<int(nums.size());i++){
    	if(nums[i]!=i+1){
			res=i+1;
			return res;
		}
    }

   res=nums[nums.size()-1]+1;
   return res;
}

