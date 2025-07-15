// 🔹 Problem: Two Sum
// 🔗 Link: https://leetcode.com/problems/two-sum/
// 🧠 Tags: Arrays, Hashing
// ✅ Status: Solved (Brute, Optimal)

// ------------------------------------------------
// 🔸 Brute Force Approach
// 💡 Try every pair and check if sum == target
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
vector<int> twoSumBrute(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}


// ------------------------------------------------
// 🔸 Optimal Approach
// 💡 Use HashMap to store complement while iterating
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n)
// ------------------------------------------------
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i = 0; i< nums.size(); i++){
            int a = nums[i];
            int difference = target - a;
            if(mpp.find(difference) != mpp.end()){
                return {mpp[difference], i}; 
            }
           mpp[a] = i;
        }
        return {};
    }
