// ------------------------------------------------
// 🔸 Brute Force
// 💡 Store positives and negatives, then interleave
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n)
// ------------------------------------------------
vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pos=0,neg=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }


// ------------------------------------------------
// 🔸 Optimal Approach (Two Pointers - Direct Placement)
// 💡 Place positive at even index, negative at odd
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(n) [since output needs new array]
// ------------------------------------------------
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int posIdx = 0, negIdx = 1;

    for (int num : nums) {
        if (num > 0) {
            result[posIdx] = num;
            posIdx += 2;
        } else {
            result[negIdx] = num;
            negIdx += 2;
        }
    }

    return result;
}
