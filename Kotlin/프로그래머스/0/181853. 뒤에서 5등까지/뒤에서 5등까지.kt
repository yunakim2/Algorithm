class Solution {
    fun solution(num_list: IntArray): IntArray {
       num_list.sort()
       // num_list.slice(0 .. 4).toIntArray()
       return num_list.sliceArray(IntRange(0, 4))
    }
}