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
string multiply(string num1, string num2);
int mtable[10][10]=
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,6,7,8,9},
	{0,2,4,6,8,0,2,4,6,8},
	{0,3,6,9,2,5,8,1,4,7},
	{0,4,8,2,6,0,4,8,2,6},
	{0,5,0,5,0,5,0,5,0,5},
	{0,6,2,8,4,0,6,2,8,4},
	{0,7,4,1,8,5,2,9,6,3},
	{0,8,6,4,2,0,8,6,4,2},
	{0,9,8,7,6,5,4,3,2,1},
	};
int ctable[10][10]=
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1},
	{0,0,0,0,1,1,1,2,2,2},
	{0,0,0,1,1,2,2,2,3,3},
	{0,0,1,1,2,2,3,3,4,4},
	{0,0,1,1,2,3,3,4,4,5},
	{0,0,1,2,2,3,4,4,5,6},
	{0,0,1,2,3,4,4,5,6,7},
	{0,0,1,2,3,4,5,6,7,8},
	};

int main() {
//**********************************
// Generate multiplication table
//**********************************
//	printf("int mtable[10][10]= \n");
//	printf("{\n");
//	for(int i=0;i<10;i++){
//		printf("{");
//		for(int j=0;j<10;j++){
//			if(j<9)
//				printf("%d,",i*j%10 );
//			else
//				printf("%d",i*j%10);
//		}
//		printf("},\n");
//	}
//	printf("};\n");
//
//	printf("int ctable[10][10]= \n");
//	printf("{\n");
//	for(int i=0;i<10;i++){
//		printf("{");
//		for(int j=0;j<10;j++){
//			if(j<9)
//				printf("%d,", i*j/10);
//			else
//				printf("%d", i*j/10);
//		}
//		printf("},\n");
//	}
//	printf("};\n");
	string n1="9133",n2="0";
	string res=multiply(n1,n2);
	cout<<res<<endl;
	return 0;
}

string multiply(string num1, string num2) {
	/*
	 * 1. Calculate m and c digit firstly and then fill in data
	 * 2. Take care of the last carry digit
	 */
		int digm,digc;
		vector<int> sum(num1.size()+num2.size(),0);
		string res;

		for(int i=0;i<int(num1.size());i++){
			int a=num1.at(num1.size()-1-i)-'0';
			digc=0;
			for(int j=0;j<int(num2.size());j++){
				int b=num2.at(num2.size()-1-j)-'0';
				digm=(mtable[a][b]+digc+sum[i+j])%10;
				digc=ctable[a][b]+(mtable[a][b]+digc+sum[i+j])/10;
				sum[i+j]=digm;
			}
			//printf("%d, %d\n", sum.size(), i+num2.size());
			sum[i+num2.size()]=digc;
		}

		bool zero_flag=true;
		for(int i=0;i<int(sum.size());i++){
			if(zero_flag&&sum[sum.size()-1-i]==0){
				zero_flag=true;
			}else{
				zero_flag=false;
			}
			if(zero_flag==false)
				res.push_back(char(sum[sum.size()-1-i]+'0'));
		}
		if(zero_flag==true)
			res="0";
		return res;
}

