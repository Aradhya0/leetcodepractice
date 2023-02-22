class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        mem = {}
        words_set = set(words)
   
        def check( aWord):
            if len(aWord)==1: return False
            if aWord in mem:
                return mem[aWord]
            mem[aWord] = False
            for i in range(1, len(aWord)):
                prefix,suffix =aWord[:i],aWord[i:]
                if prefix in words_set and (suffix in words_set or check(suffix)):
                    mem[aWord] = True
                    break
            return mem[aWord]
          
        return [w for w in words if check(w)]
