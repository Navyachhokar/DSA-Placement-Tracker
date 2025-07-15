// 🔹 Problem: Sort an array of 0s, 1s and 2s
// 🔗 Link: https://leetcode.com/problems/sort-colors/
// 🧠 Tags: [Arrays, Two-Pointer, In-place Sorting]
// ✅ Status: Solved ( Better, Optimal)


// ------------------------------------------------
// 🔸 Better Approach 
// 💡 Logic: [maintain the count of 0, 1, and 2 and then overwrite the array]
// 🕒 Time Complexity: O(2N)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){ // O(N)
            if(nums[i] == 0){
                cnt0++;
            } 
            else if(nums[i] == 1){
                cnt1++;
            } 
            else {
                cnt2++;
            }
        }
        for(int i = 0; i<cnt0; i++){                
            nums[i] = 0;                            
        }
        for(int i = cnt0; i<cnt0+cnt1; i++){
            nums[i] = 1;
        }
        for(int i = cnt0+cnt1; i<n; i++){
            nums[i] = 2;
        } // above three for loops ends up having n operation so T.C = O(N)
    } // overall T.C = O(N) + O(N);


// ------------------------------------------------
// 🔸 Optimal Approach
// 🧠 Concept: Dutch National Flag Algorithm
// 🕒 Time Complexity: O(N)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
void sortcolors(vector<int>& nums) {
        int n = nums.size();
        int mid = 0;
        int low = 0;
        int high = n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else{
                mid++;
            }
        }
    }

