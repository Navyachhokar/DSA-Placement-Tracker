// 🔹 Problem: Maximum Subarray Sum (Kadane's Algorithm)
// 🔗 Link: https://leetcode.com/problems/maximum-subarray/
// 🧠 Tags: Arrays, Kadane’s Algorithm, Dynamic Programming
// ✅ Status: Solved (Brute, Better, Optimal)

// ------------------------------------------------
// 🔸 Brute Force Approach
// 💡 Check all subarrays and track the max sum
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            long long sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                maxi = max(sum, maxi);
            }      
        }
        return maxi;
    }
};

// ------------------------------------------------
// 🔸 Better Approach (Prefix Sum)
// 💡 Precompute prefix sums and check all subarrays
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(n) [prefix array]
// ------------------------------------------------

int maxSubArrayBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + nums[i];

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currSum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}


// ------------------------------------------------
// 🔸 Optimal Approach (Kadane’s Algorithm)
// 💡 Keep track of local maximum and reset if negative
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN;
         long long sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
                sum += nums[i];
                maxi = max(sum, maxi);
                if(sum<0) sum = 0;  
        }
        return maxi;
    }
