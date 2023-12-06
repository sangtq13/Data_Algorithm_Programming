// Time complexity: O(n)
// Space complexity: O(n)

int best_value[10] = {0};
int max_value = 0;
int bestSumHelper(std::unordered_map<int, std::vector<int>>& m, vector<int>& values, const int& current_node) {
    int n = m[current_node].size();
    if (n == 0) return max(values[current_node], 0);
    int max_branch = 0;
    for (int i = 0; i < n; ++i) {
        best_value[i] = bestSumHelper(m, values, m[current_node][i]);
        if (best_value[i] > max_branch) {
            max_branch = best_value[i];
        }
    }
    
    int max_current = max(values[current_node] + max_branch, values[current_node]);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            max_value = max(max_value, best_value[i] + best_value[j] + values[current_node]);
        }
    }
    max_value = max(max_value, values[current_node]);
    return max(max_current, 0);
}

int bestSumAnyTreePath(vector<int> parent, vector<int> values) {
    std::unordered_map<int, std::vector<int>> m;
    for (int i = 0; i < parent.size(); ++i) {
        m[parent[i]].push_back(i);
    }
    bestSumHelper(m, values, 0);
    
    return max_value;
}

int main()
{
    vector<int> parent = {-1,0,1,2,0};
    vector<int> values = {-2,10,10,-3,10};
    int m = bestSumAnyTreePath(parent, values);
    for (int i = 0; i < 5; ++i) {
        cout << best_value[i] << endl;
    }
    cout << m << endl;
}
