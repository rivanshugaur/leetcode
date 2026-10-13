class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        st = ""
        for ch in s:
            if(ch in vowels):
                st+=ch
        st = st[::-1]
        i = 0
        j = 0
        s = list(s)
        while(i<len(s) and j<len(st)):
            if(s[i] in vowels):
                s[i]=st[j]
                j+=1
            i+=1


        return "".join(s)
        