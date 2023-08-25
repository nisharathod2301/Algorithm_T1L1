// C++ code for k largest/ smallest elements in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find k largest array element
void kSmallest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int> pq;
	for(int i = 0; i<K; i++){
	    pq.push(v[i]);
	}
	for(int i = K; i < N; i++){
	    if(pq.top()>v[i]){
	        pq.pop();
	        pq.push(v[i]);
	    }
	}
	cout << pq.top();
}



// driver program
int main()
{
	// Given array
	vector<int> arr
		= { 11, 8, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
	// Size of array
	int n = arr.size();
	int k = 3;
	cout << k << "rd smallest elements are : ";
	kSmallest(arr, n, k);
// 	cout << k << " smallest elements are : ";
// 	kSmalest(arr, n, k);
}

// This code is contributed by Pushpesh Raj.
