#include <bits/stdc++.h>

using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int>& arr,int l,int h){
    int pivot = arr[l];
    int i=l, j=h;

    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j)swap(&arr[l],&arr[j]);
    }while(i<j);

    swap(&arr[l],&arr[j]);
    return j;
}

void QuickSort(vector<int>& arr,int l, int h){
    int j;
    if(l<h){
        j = partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main(){
    vector<int> A = {99,11,13,7,8,9,15,1,18,25};
    int n = 10;
    cout << "Before Sorting" << endl;
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    QuickSort(A,0,n);
    cout << "After Sorting" << endl;
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
}