//============================================================================
// Name        : test_delete.cpp
// Author      : WLi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <complex>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

int bsearch(vector<int> &nums,  int l, int h, int target);
int search(vector<int>& nums, int target);
int main() {
	const std::complex<double> ii(0, 1);
	std::complex<float> phase_comp;
	phase_comp=std::exp(ii*M_PI);
	cout<<phase_comp<<endl;


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

//	vector<int> in={4,5,6,7,0,1,2};
//	vector<int> in={0,1,2,3,4,5,6,7};
	vector<int> in={1};
	int input_target;
	cin>>input_target;
	int res;
//	res=bsearch(in, 0,in.size(), input_target);
//	printf("search results: %d\n", res);
	res=search(in, input_target);
	printf("search results: %d\n", res);
	return 0;
}

int bsearch(vector<int> &nums, int l, int h, int target){
	int h_orig=h;
	int m=l+(h-l)/2;

	while(l+1<h){
		m=l+(h-l)/2;
		if(nums[m]>target)
			h=m;
		else if(nums[m]<target)
			l=m;
		else
			break;

	}
//	printf("%d, %d, %d\n", l,m,h);
	if(nums[l]==target) return l;
	else if(nums[m]==target) return m;
	else if(nums[h]==target&&h<h_orig) return h;
	else return -1;
}



int search(vector<int>& nums, int target) {
	/*
	 * Be care of:
	 * 		1. Condition of pivot search to make sure the remaining space always contains target value
	 * 		2. For bsearch if the updating is as shown in line 47/49, it means that the final space will be like [k, k+1] or k;
	 * 		It requires one more step check to decide which element contains target value.
	 */

	if(nums.size()==0) return -1;
	int l=0,h=nums.size();
	int m=l+(h-l)/2;
	while(l+1<h){
		m=l+(h-l)/2;
		if(nums[m]<nums[l])
			h=m;
		else
			l=m;
	}

	int res=-1;
	if(l<(int)nums.size()-1){
		// There exits pivot.
		if(target>=nums[0]&&target<=nums[l]){
			res=bsearch(nums,0,l+1,target);
		}else{
			res=bsearch(nums,l+1, nums.size(),target);
		}
	}else{
		// There is no pivot.
		res=bsearch(nums, 0,nums.size(), target);
	}

	return res;

}

