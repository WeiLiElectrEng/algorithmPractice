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
#include <limits.h>
using namespace std;
int trap(vector<int>& height);
int main() {
	vector<int> in={0,1,0,2,1,0,1,3,2,1,2,1}	;
	int res=trap(in);
	printf("trap: %d\n",res);
	return 0;
}

int trap(vector<int>& height) {
	/*
	 * 1. Be care input size equals to 1 or 0
	 * 2. Find each value's left larget and right largest to do something...
	 */
		vector<int> h=height;
		if(h.size()==1&&h.size()==0)
			return 0;

		int res=0;
		int left_max_tmp=h[0],right_max_tmp=h[h.size()-1];
		vector<int> left_max,right_max;

		left_max.push_back(h[0]);
		for(int i =1;i<int(h.size());i++){
			if(left_max_tmp<h[i]){
				left_max_tmp=h[i];
			}
			left_max.push_back(left_max_tmp);
		}

	//	printf("left_max: \n");
	//	for(auto const&v: left_max){
	//		printf("%d, ",v);
	//	}

		right_max.push_back(h[h.size()-1]);
		for(int i=int(h.size())-2;i>=0;i--){
			if(right_max_tmp<h[i]){
				right_max_tmp=h[i];
			}
			right_max.push_back(right_max_tmp);
		}
	//	printf("\n right_max \n");
	//	for(auto const&v: right_max){
	//			printf("%d, ",v);
	//	}
	//	printf("\n");



		for(int i=1;i<int(h.size())-1;i++){
			if(left_max[i]<right_max[int(h.size())-1-i]){
				res+=left_max[i]-h[i];
			}else{
				res+=right_max[int(h.size())-1-i]-h[i];
			}
		}
		return res;
}

