#include <iostream>
#include <string>
#include <stack>
using namespace std;
string removeKDigits(std::string n, int k) {
    stack<char> st;
    
    for (char digit : n) {
        while (k > 0 && !st.empty() && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    
    // Remove remaining digits if necessary
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    // Construct the result
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    // Remove leading zeroes
    int i = 0;
    while (i < result.size() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);
    
    return result.empty() ? "0" : result;
}

int main() {
    int n;
    cin>>n;
    string s = to_string(n);
    int k;
    cin>>k;
    cout << removeKDigits(n, k) << endl;  // Output: "1219"
    
    return 0;
}
