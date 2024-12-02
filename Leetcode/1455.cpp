class Solution {
    fun isPrefixOfWord(sentence: String, searchWord: String): Int {
        var ret: Int = -1

        val strs: List<String> = sentence.split(" ")
        run loop@ {
            strs.forEachIndexed { i, str -> 
                if (str.startsWith(searchWord)) {
                    ret = i + 1
                    return@loop
                }
            }
        }

        return ret
    }
}