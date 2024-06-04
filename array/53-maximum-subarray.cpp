/*
 * Given an integer array nums, find the subarray
 * with the largest sum, and return its sum.
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int maxsum = INT_MIN, sum = 0;
    	for(int n:nums){
            if(sum < 0){
    			sum = 0;
    		}
    		sum += n;
    		maxsum = max(maxsum, sum);
    	}
    	return maxsum;
    }
};