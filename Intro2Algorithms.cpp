// Intro2Algorithms.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//#include <iostream>
using namespace std;

//在C++中则可以使用模板技术定义一个函数,获取不同类型的数组的长度
template <class T>
int getArrayLen(T& array){
	return (sizeof(array) / sizeof(array[0]));
}
//Best:positive sequence, n; Worst:inverted sequence, n^2 ; Avg:n^2
float* insertion_sort(float A[],int n){
	float key = 0;
	int i = 0;
	//cout << n <<endl;
	for (int j=0;j<=n-1;j++){
		key = A[j];
		i = j - 1;
		while(i>0&&A[i]>key){
			A[i+1] = A[i];
			i -= 1;
		}
		A[i+1] = key;	
	}
	return A;//array can't be return, but a pointer can be used
}
int main(){
	
	float A[] = {1,3,5,2,4,6};
	int  n = getArrayLen(A);
	float *B = insertion_sort(A,n);
	//cout << typeid(B).name() << endl;//check var types
	for (int i=0;i<n;i++)
	{
		cout << B[i] << endl;
	}
	

	return 0;
	
}


