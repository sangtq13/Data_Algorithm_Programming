// Time complexity: O(n)
// Space complexity: O(n)
int maxTransaction(vector<int> transaction) {
    int sum = 0;
    int max_transaction = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 0; i < transaction.size(); ++i) {
        if (transaction[i] < 0) {
            if (sum + transaction[i] >= 0) {
                max_transaction++;
                sum += transaction[i];
                pq.push(transaction[i]);
            }
            else {
                int top = 1e9;
                if (!pq.empty()) {
                    top = pq.top();
                }
                if (top < transaction[i]) {
                    sum -= top;
                    pq.pop();
                    sum += transaction[i];
                    pq.push(transaction[i]);
                }
            }
        }
        else {
            sum += transaction[i];
            max_transaction++;
        }
    }
    
    return max_transaction;
}
