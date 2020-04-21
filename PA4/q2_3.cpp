#include<iostream>
#include<climits>
#include"MinHeap.h"
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    MinHeap h(11);
    for(unsigned int i = 0 ; i < n ; ++i){
    	h.insertKey(arr[i]);
    }
	for(unsigned int j = 0 ; j < k-1 ; j++){
		h.extractMin();
	}
    return h.getMin();
}

int main(){
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int* arr = new int[n];
    cout << "Enter n integers space separated: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Kth Smallest Integer: " << kthSmallest(arr, n, k) << endl;
    return 0;
}
