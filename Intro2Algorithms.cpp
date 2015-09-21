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
//直接插入排序	Best:positive sequence, n; Worst:inverted sequence, n^2 ; Avg:n^2
void insertion_sort(float *A,int n){
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
}
void Merge(float *A,int p, int q, int r){
	int n1,n2,i,j,k;
	n1 = q - p + 1;//第一部分的长度
	n2 = r - q;//第二部分的长度
	float *L = new float[n1+1];
	float *R = new float[n2+1];
	for (i = 0;i <= n1 - 1; i++) L[i] = A[p + i];
	for (j = 0;j <= n2 - 1;j++) R[j] = A[q+j+1];//A[q+1+j-1]
	L[n1] = INFINITY;//两张哨兵牌
	R[n2] = INFINITY;
	for (i = 0, j = 0,k = p;k<=r;k++)
	{
		if (L[i]<=R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}

	delete [] L;//delete要和new要配对使用
	delete [] R;
}
//归并排序
void merge_sort(float *A,int p,int r){//p指向起始点，r指向终止点，q是分解点
	int q;
	if (p<r){
		q = (p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		Merge(A,p,q,r);
	}
}
int main(){
	
	float A[] = {1,3,5,2,4,6,1.3,3.5,5.2,2.4,4.6};
	int  n = getArrayLen(A);
	//insertion_sort(A,n);//直接插入排序
	merge_sort(A,0,n-1);//归并排序
	for (int i=0;i<n;i++)
	{
		cout << A[i] << endl;
	}

	return 0;
}


