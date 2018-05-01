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
#include <stack>
using namespace std;
vector<int> searchRange(vector<int> &nums,int target);
int main() {
        vector<int> in={1,1,1,1};
//        vector<int> in={0,1,2,3,3,3,4,5,6,7};
        for(auto it=in.begin(); it<in.end();it++)
                cout<<*it<<", ";
        cout<<endl;
        int input_target;
        cin>>input_target;
        vector<int> res;
        res=searchRange(in,input_target);
        for(auto it=res.begin(); it<res.end();it++)
                cout<<"res: "<<*it<<endl;

        return 0;

}

vector<int> searchRange(vector<int> &nums,int target){
		/*
		 * Be careful the left/right end
		 * 	To find right end : [ ); Initialized with: 0, array_len
		 * 	To find left end: ( ]; Initialized with: -1, array_len-1
		 */
        int l=0,h=nums.size();
        int m=l+(h-l)/2;
        int hres,lres;
        vector<int> res;
        if(nums.empty()){
                res.push_back(-1);
                res.push_back(-1);
                return res;
        }

        // find right end
        while(l+1<h){
                m=l+(h-l)/2;
                if(nums[m]>target)
                        h=m;
                else
                        l=m;
        }
        if(nums[m]==target)
                hres=m;
        else if(nums[l]==target)
                hres=l;
        else
                hres=-1;

        // find left end
        l=-1;
        h=nums.size()-1;
        while(l+1<h){
                m=l+(h-l)/2;
                if(nums[m]<target)
                        l=m;
                else
                        h=m;
                //printf("%d, %d, %d\n",l,m,h);
        }
        if(nums[m]==target)
                lres=m;
        else if(nums[h]==target)
                lres=h;
        else
                lres=-1;
        //printf("lres: %d, hres: %d\n", lres, hres);
        if(lres<0&&hres>=0)
                lres=hres;
        if(hres<0&&lres>=0)
                hres=lres;
        res.push_back(lres);
        res.push_back(hres);
        return res;

}


