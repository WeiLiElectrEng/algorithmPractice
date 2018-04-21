//============================================================================
// Name        : est.cpp
// Author      : wli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>void swap_vec(T*s, T*e){
    T tmp;
    tmp=*s;
    *s=*e;
    *e=tmp;
}

template<class T>void reverse_vec(T* s, T*e){
    while(s<e){
    	swap_vec(s, e);
        s++;
        e--;
    }

}

void nextPermutation(vector<int>& nums) {
	/* Note: Indexing issue:
	 * 	1. Indexing of decremented for loop: should be
	 * 		for(int i =nums.size()-1;i>=0;i--)
	 * 		not for(int i =nums.size()-1;i>0;i--)
	 *	2. Be care of corner cases
	 *
	*/

		if(nums.size()>1) {
			int i;
			for(i=nums.size()-2;i>=0;i--){
				if(nums[i]<nums[i+1]) break;
			}


			if(i==-1) {
				reverse(nums.begin(), nums.end());
				return;
			}
			int j;
			for(j=nums.size()-1;j>=i;j--){
				if(nums[j]>nums[i]) break;
			}
			swap(nums[i], nums[j]);
			if(nums.begin()+i+1<nums.end()-1){
				reverse(nums.begin()+i+1, nums.end());
			}
		}
}

int main() {
	vector<int> nums={1,2,3};

	cout<<"next permulation\n";
	nextPermutation(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<endl;
	}



	return 0;
}

