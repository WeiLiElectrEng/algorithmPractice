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
vector< vector<int>> dfs(vector<int> &c, int lev, int target);
vector< vector<int>> combinationSum(vector<int>& candidates, int target);

int main() {
	vector<int> c={2,3,5};
	vector<vector<int> > res=combinationSum(c, 8);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			printf("%d, ",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
vector< vector<int>> dfs(vector<int> &c, int lev, int target){
	/*
	 * 1. index with different loop should be correct like in line 45: res_tmp[j].push_back(c[i]);
	 * 2. Draw a diagram to show the parameter passing procedure.
	 * 3. Key point for DFS search:
	 * 	  3.1  A for loop to transverse the child nodes of one
	 * 	  3.2  A search depth indicator should be pasased into each dfs
	 * 	  3.3  Think carefully the child nodes and depth of each searching.
	 */
	vector< vector<int>> res, res_tmp;
	vector<int> tmp;
	for(int i=lev;i<int(c.size());i++){
		if(c[i]==target){ // find current
			tmp.push_back(c[i]);
			res.push_back(tmp);
		}else if(c[i]<target){ // still can't find but there is possibility
			res_tmp=dfs(c,i,target-c[i]);
			if(!res_tmp.empty()){
				for(int j=0;j<int(res_tmp.size());j++){
					res_tmp[j].push_back(c[i]);
					res.push_back(res_tmp[j]);
				}
			}
		}
	}
	return res;
}
vector< vector<int>> combinationSum(vector<int>& candidates, int target) {
   vector< vector<int>> res;
   sort(candidates.begin(), candidates.end());
   res=dfs(candidates,0,target);
   return res;
}

