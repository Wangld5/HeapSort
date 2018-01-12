#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//�������ڵ���ӽڵ��С 
void build(int arr[], int len, int index){
	int left = 2*index+1;
	int right = 2*index+2;
	int max = index;
	if(left<len && arr[left]>arr[max]) max = left;
	if(right<len && arr[right]>arr[max]) max = right;
	if(max!=index){
		swap(arr[max], arr[index]);
		build(arr, len, max);
	}
}
void heapSort(int arr[], int size){
	for(int i=size/2-1; i>=0; i--){
		build(arr, size, i);//�������ҳ�����Ԫ�� 
	}
	for(int i=size-1; i>=1; i--){
		swap(arr[0], arr[i]);//���� �������һ��Ԫ�ؽ��� 
		build(arr, i, 0);//��ʣ�µ�Ԫ�������� 
	}
}
int main(){
	int n;
	cin>>n; 
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	heapSort(arr, n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
