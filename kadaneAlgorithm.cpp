#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// using std::vector;
// using std::max;

/*
 * Q: Find a non-empty subarray with the largest sum.
 */

 /* Method 1 - bruteforce 
  * Time complexity - O(n^2)
  */
 int bruteforce(vector<int>& nums) {
 	int maxsum = nums[0];
 	for(int i = 0; i < nums.size(); i++){
 		int cursum = 0;
 		for(int j = i; j < nums.size(); j++){
 			cursum += nums[j];
 			maxsum = max(maxsum, cursum);
 		}
 	}
 	return maxsum;
 }

 /* Method 2 - kadane's algorithm */
 int kadane(vector<int>& nums) {
 	int maxsum = nums[0], cursum = 0;
 	for(int i = 0; i < nums.size(); i++){
 		//cursum = max(cursum, 0);
 		cursum += nums[i];
 		if(cursum < 0)
 			cursum = 0;
 		maxsum = max(maxsum, cursum);
 		
 	}
 	return maxsum;
 }

  /* Method 3 - sliding window */
 vector<int> slidingwindow(vector<int>& nums) {
 	int maxsum = nums[0], cursum = 0;
 	int L = 0, R = 0, maxL = 0, maxR = 0;
 	for(int R = 0; R < nums.size(); R++){
 		if(cursum < 0){
 			cursum = 0;
 			L = R;
 		}
 		cursum += nums[R];
 		if(cursum > maxsum){
 			maxsum = cursum;
 			maxR = R;
 			maxL = L;
 		}
 	}
 	return vector<int>{maxL, maxR};
 }

 int main() {
 	vector<int> nums = {4, -1 , 2, -7, 3, 4};
 	cout << "bruteforce " << bruteforce(nums) << endl;
 	cout << "kadane " << kadane(nums) << endl;
 	cout << "slidingwindow " << endl;
 	vector<int> ret = slidingwindow(nums);
 	for(int n : ret)
 		cout << n << " ";
 	cout << endl;
 }