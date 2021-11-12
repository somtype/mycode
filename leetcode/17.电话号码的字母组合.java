/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.35%)
 * Likes:    1581
 * Dislikes: 0
 * Total Accepted:    354.6K
 * Total Submissions: 618.3K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> combinations = new ArrayList<String>();
        if(digits.length() == 0){
            return combinations;
        }
        Map<Character, String> map = Map.of('2',"abc", '3',"def", '4',"ghi",
                                            '5',"jkl", '6',"mno", '7',"pqrs",
                                            '8',"tuv", '9',"wxyz"
        );
        dfs(combinations, map, digits, 0, new StringBuffer());
        return combinations;
    }
    private void dfs(List<String> combinations, Map<Character, String> map, String digits, int depth, StringBuffer combination){
        if(depth == digits.length()){
            combinations.add(combination.toString());
            return;
        }
        else{
            String letters = map.get(digits.charAt(depth));
            for(int i = 0; i < letters.length(); i++){
                combination.append(letters.charAt(i));
                dfs(combinations, map, digits, depth + 1, combination);
                combination.deleteCharAt(depth);
            }
        }
    }
}
// @lc code=end

