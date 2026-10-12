class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        arr = [0]*26
        for i in range(len(s)):
            si = ord(s[i]) - 97
            ti = ord(t[i]) - 97
            arr[si]+=1
            arr[ti]-=1
        
        for i in arr:
            if(i!=0):
                return False
        return True
        