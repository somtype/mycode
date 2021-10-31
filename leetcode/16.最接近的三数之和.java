/*
 * @lc app=leetcode.cn id=16 lang=java
 *
 * [16] 最接近的三数之和
 * 凑出a, b, c使a + b + c 与 target 最接近
 */

// @lc code=start
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int a, b, c;
        int closest = nums[0] + nums[1] + nums[2];
        Arrays.sort(nums);
        for(a = 0; a < nums.length - 2; a++){
            b = a + 1;
            c = nums.length - 1;
            while(b < c){
                int thissum = nums[a] + nums[b] + nums[c];
                int thisGap = Math.abs(thissum - target);
                int cloGap = Math.abs(closest - target);
                if(thisGap == 0 || cloGap == 0){
                    return target;
                }
                else {
                    if(thisGap < cloGap){
                        closest = nums[a] + nums[b] + nums[c];
                    }
                    if(thissum > target){
                        c--;
                    }
                    else{
                        b++;
                    }
                }
            }
        }
        return closest;
    }
}
// @lc code=end

