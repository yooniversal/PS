class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ret = []

        for i, firstWord in enumerate(words):
            for j, secondWord in enumerate(words):
                if i >= j:
                    continue
                
                tmpFirstWord, tmpSecondWord = firstWord, secondWord
                if len(firstWord) > len(secondWord):
                    tmpFirstWord, tmpSecondWord = secondWord, firstWord
                
                if tmpFirstWord in tmpSecondWord:
                    ret.append(tmpFirstWord)

        return list(set(ret))