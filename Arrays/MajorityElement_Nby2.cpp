// 🔹 Problem: Majority Element (> n/2 times)
// 🔗 Link: https://leetcode.com/problems/majority-element/
// 🧠 Tags: Arrays, HashMap, Boyer-Moore Algorithm
// ✅ Status: Solved (Brute, Better, Optimal)

// ------------------------------------------------
// 🔸 Brute Force Approach
// 💡 Count frequency of each element using 2 loops
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int majorityElementBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > n / 2)
            return nums[i];
    }
    return -1;
}

// ------------------------------------------------
// 🔸 Better Approach (HashMap)
// 💡 Store frequencies using a map
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n)
// ------------------------------------------------
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > (nums.size()/2)){
                return it.first;
            }
        }
       return -1; 
    }
       
// ------------------------------------------------
// 🔸 Optimal Approach (Boyer-Moore Voting Algorithm)
// 💡 Candidate & count logic
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int majorityElement(vector<int>& nums) {
        int element;
        int count = 0;

        for(int i = 0; i< nums.size(); i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
            
        }
        return element;
        
        
    }
