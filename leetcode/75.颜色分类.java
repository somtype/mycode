/*
 * @lc app=leetcode.cn id=75 lang=java
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
		int i0, i1;
		i0 = i1 = 0;
		for(int i = 0; i < nums.length; ++i){
			if(nums[i] == 1){
				int temp = nums[i1];
				nums[i1] = nums[i];
				nums[i] = temp;
				++i1;
			}
			else if(nums[i] == 0){
				int temp = nums[i0];
				nums[i0] = nums[i];
				nums[i] = temp;
				if(i0 < i1){
				temp = nums[i1];
				nums[i1] = nums[i];
				nums[i] = temp;
				}
				++i0;
				++i1;
			}
		}
	}
}
// @lc code=end

