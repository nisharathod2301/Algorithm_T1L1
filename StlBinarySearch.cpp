#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[6] = {1,4,5,3,9,11};
    sort(arr, arr+6);
    bool ans = binary_search(arr, arr+6, 9);
    //Retuns True if element is found else returns false
    cout<<ans;
    return 0;
}
