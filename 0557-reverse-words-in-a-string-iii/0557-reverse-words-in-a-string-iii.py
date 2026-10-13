class Solution:
    def reverseWords(self, s: str) -> str:
        lt = list(s.split())
        print(lt)
        a = ""
        for i in range(len(lt)):
            ch = lt[i]
            lt[i] = ch[::-1]
            a = a+lt[i]+" "
        return (a.strip())
