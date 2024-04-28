class Solution {
    fun solution(arr1: IntArray, arr2: IntArray): Int {
        var answer: Int = 0
        
        if (arr1.size > arr2.size) {
            return 1
        } else if (arr2.size > arr1.size) {
            return -1
        } else {
            var sum1 = 0
            var sum2 = 0
            arr1.forEach{ it ->
            sum1+=it
            }
            arr2.forEach{ it ->
                sum2+=it
            }
            if (sum1 == sum2) {
                return 0
            } else if (sum1 > sum2) {
                return 1
            } else {
                return -1
            }
        }
        
    }
}