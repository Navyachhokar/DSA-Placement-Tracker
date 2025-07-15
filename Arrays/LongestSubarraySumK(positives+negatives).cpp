// 🔹 Problem: Longest Subarray with Sum K (Positives & Negatives)
// 🔗 Link: https://www.geeksforgeeks.org/longest-sub-array-with-sum-k/
// 🧠 Tags: Arrays, Prefix Sum, HashMap
// ✅ Status: Solved (Brute, Optimal)

// ------------------------------------------------
// 🔸 Brute Force Approach
// 💡 Check all subarrays and compute sum
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int longestSubarrayBrute(vector<int>& nums, int k) {
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// ------------------------------------------------
// 🔸 Optimal Approach (Prefix Sum + HashMap)
// 💡 Store earliest index of a particular prefix sum
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n)
// ------------------------------------------------
int longestSubarrayWithSumK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k)
            maxLen = i + 1;

        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end())
            maxLen = max(maxLen, i - prefixSumIndex[sum - k]);

        if (prefixSumIndex.find(sum) == prefixSumIndex.end())
            prefixSumIndex[sum] = i;
    }

    return maxLen;
}
