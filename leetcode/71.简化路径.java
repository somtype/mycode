/*
 * @lc app=leetcode.cn id=71 lang=java
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
    public String simplifyPath(String path) {
		Stack<String> stack = new Stack();
		StringBuilder result = new StringBuilder();
		for(String sub : path.split("/")){
			if(sub.equals("..") && !stack.empty()){
				stack.pop();
			}
			else if(!"..".contains(sub)){
				stack.push(sub);
			}
		}
		for(String sub : stack){
			result.append("/" + sub);
		}
		return result.length() == 0 ? "/" : result.toString();
    }
}
// @lc code=end

