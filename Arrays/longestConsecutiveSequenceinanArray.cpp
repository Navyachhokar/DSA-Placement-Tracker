// ------------------------------------------------
// 🔸 Brute Force
// 💡 For each element, check if next consecutive elements exist
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int longestConsecutiveBrute(vector<int>& nums) {
    int n = nums.size(), longest = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i], count = 1;
        while (find(nums.begin(), nums.end(), x + 1) != nums.end()) {
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}


// ------------------------------------------------
// 🔸 Optimal Approach (HashSet)
// 💡 Only start counting when current num is sequence start
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n)
// ------------------------------------------------
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st) {
        if (!st.count(num - 1)) {
            int currNum = num;
            int count = 1;

            while (st.count(currNum + 1)) {
                currNum += 1;
                count += 1;
            }

            longest = max(longest, count);
        }
    }
    return longest;
}
