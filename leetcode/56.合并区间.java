/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

// @lc code=start
class MyComparator implements Comparator<int[]> {
	public int compare(int[] a, int[] b){
		return a[0] - b[0];
	}
}
class Solution {
	public int[][] merge(int[][] intervals) {
		Arrays.sort(intervals, new MyComparator());	
		List<int[]> resultList = new ArrayList<int[]>();
		for(int i = 0; i < intervals.length; ++i){
			int left = intervals[i][0], right = intervals[i][1];
			if(resultList.size() == 0 || resultList.get(resultList.size()-1)[1] < left){
				resultList.add(new int[]{left,right});
			}
			else{
				int[] pre = resultList.get(resultList.size()-1);
                pre[1] = Math.max(pre[1], right);
			}
		}
		return resultList.toArray(new int[resultList.size()][2]);
	}
}
// @lc code=end

