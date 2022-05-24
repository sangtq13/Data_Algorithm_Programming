#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    int i = 0;
    
    cin >> n;

    vector<int> arr;
    int num;
    
    for (i=0; i<n; ++i){
        cin >> num;
        arr.push_back(num);
    }
    for (i=0; i<n; ++i){
        cout << arr[n-1-i] << " ";
    }
    
    return 0;
}

