//
//  main.cpp
//  Mergesort
//
//  Created by Benita Alexander on 2/9/23.
//

#include <iostream>
using namespace std;


// time complexity O(nlogn) in worst case
void Merge(int *arr, int *leftarr, int left, int *rightarr, int right){
    int i,j,k;
    
    i=0;j=0;k=0;
    
    while(i<left && j<right){
        if(leftarr[i] < rightarr[j]) arr[k++]=leftarr[i++];
        else arr[k++] = rightarr[j++];
    }
    while (i<left) arr[k++]=leftarr[i++];
    while(j<right) arr[k++]=rightarr[j++];
}


void MergeSort(int arr[], int n){
    int mid, *leftArr, *rightArr;

    if(n<2) return;
    
    mid = n/2;
    
    leftArr = (int*)malloc(mid*sizeof(int));
    rightArr =(int*)malloc((n-mid)*sizeof(int));
    
    for(int i =0; i<mid;i++) leftArr[i]=arr[i];
    for(int j=mid; j<n;j++) rightArr[j-mid]=arr[j];
    
    MergeSort(leftArr,mid);
    MergeSort(rightArr,n-mid);
    
    Merge(arr, leftArr, mid, rightArr,n-mid);
    free(leftArr);
    free(rightArr);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]= {9,1,8,2,7,3,6,5,8,1,2,9,4};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    MergeSort(arr, length);

    cout<<"\n";
    for(auto temp:arr) cout<<" "<<temp<<" ";
    cout<<"\n";
    return 0;
}
