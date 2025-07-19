// ------------------------------------------------
// 🔸 Brute Force
// 💡 For each element, check if any element to its right is greater
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
vector<int> leadersBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) leaders.push_back(arr[i]);
    }
    return leaders;
}


// ------------------------------------------------
// 🔸 Optimal Approach (Right to Left Scan)
// 💡 Track max from the right, push leaders in reverse
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n) for output, O(1) extra space
// ------------------------------------------------
vector<int> leadersOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(arr[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
