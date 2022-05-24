#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> count;
    deque<int> dq;
    for (int i=0; i<n; ++i){
        if (dq.empty()){
            dq.push_back(arr[i]);
            count.push_back(1);
        }
        else {
            int s = 1;
            for(auto it=dq.rbegin(); it!=dq.rend(); ++it){
                if (arr[i]>=*it){
                    dq.pop_back();
                    s += count.back();
                    count.pop_back();
                }
                else {
                    break;
                }
            }
            dq.push_back(arr[i]);
            count.push_back(s);
        }
        if (i >= k-1){
            int m = dq.front();
            count[0] -= 1;
            if (count[0] == 0){
                dq.pop_front();
                count.pop_front();
            }
            cout << m << " ";
        }
    }
    cout << "\n";
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

