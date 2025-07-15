// 🔹 Problem: Longest Subarray with Sum K (Only Positives)
// 🔗 Link: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
// 🧠 Tags: Arrays, Sliding Window
// ✅ Status: Solved (Brute, Optimal)

// ------------------------------------------------
// 🔸 Brute Force Approach
// 💡 Try every subarray and check its sum
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int longestSubarrayBrute(vector<int>& nums, int k) {
    int n = nums.size(), maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// ------------------------------------------------
// 🔸 Optimal Approach (Sliding Window)
// 💡 Expand window while sum <= k, shrink when sum > k
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int longestSubarrayWithSumK(vector<int>& nums, int k) {
    int left = 0, right = 0, sum = 0, maxLen = 0;

    while (right < nums.size()) {
        sum += nums[right];

        while (sum > k) {
            sum -= nums[left];
            left++;
        }

        if (sum == k)
            maxLen = max(maxLen, right - left + 1);

        right++;
    }

    return maxLen;
}
