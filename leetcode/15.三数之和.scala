/*
 * @lc app=leetcode.cn id=15 lang=scala
 *
 * [15] 三数之和
 */

// @lc code=start
object Solution {
    def threeSum(nums: Array[Int]): List[List[Int]] = {
        var res:List[List[Int]] = List()
        val sortedNums = nums.sorted
        for(i <- sortedNums.indices){
            if(i > 0 && sortedNums(i) == sortedNums(i - 1)){}
            else{
                var pnt_left = i + 1
                var pnt_right = sortedNums.length - 1
                while(pnt_left < pnt_right){
                    val num_left = sortedNums(pnt_left)
                    val num_right = sortedNums(pnt_right)
                    val tmpres = sortedNums(i) + num_left + num_right
                    if(tmpres == 0){
                        res +:= List(sortedNums(i),num_left,num_right)
                        pnt_left += 1
                        while(pnt_left < pnt_right && sortedNums(pnt_left) == num_left)
                            pnt_left += 1
                    }
                    else if(tmpres < 0){
                        pnt_left += 1
                    }
                    else{
                        pnt_right -= 1
                    }
                }
            }
        }
        res
    }
}
// @lc code=end

