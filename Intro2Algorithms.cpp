// Intro2Algorithms.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

//#include <iostream>
using namespace std;

//��C++�������ʹ��ģ�弼������һ������,��ȡ��ͬ���͵�����ĳ���
template <class T>
int getArrayLen(T& array){
	return (sizeof(array) / sizeof(array[0]));
}
//ֱ�Ӳ�������	Best:positive sequence, n; Worst:inverted sequence, n^2 ; Avg:n^2
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
	n1 = q - p + 1;//��һ���ֵĳ���
	n2 = r - q;//�ڶ����ֵĳ���
	float *L = new float[n1+1];
	float *R = new float[n2+1];
	for (i = 0;i <= n1 - 1; i++) L[i] = A[p + i];
	for (j = 0;j <= n2 - 1;j++) R[j] = A[q+j+1];//A[q+1+j-1]
	L[n1] = INFINITY;//�����ڱ���
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

	delete [] L;//deleteҪ��newҪ���ʹ��
	delete [] R;
}
//�鲢����
void merge_sort(float *A,int p,int r){//pָ����ʼ�㣬rָ����ֹ�㣬q�Ƿֽ��
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
	//insertion_sort(A,n);//ֱ�Ӳ�������
	merge_sort(A,0,n-1);//�鲢����
	for (int i=0;i<n;i++)
	{
		cout << A[i] << endl;
	}

	return 0;
}


