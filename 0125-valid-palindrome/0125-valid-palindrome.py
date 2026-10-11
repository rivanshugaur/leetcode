class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ""
        for ch in s:
            if(ch.isalnum()):
                st+=ch.lower()
        temp = st
        i = 0
        j = len(temp)-1
        print(temp)
        while(i<j):
            if(temp[i]==temp[j]):
                i+=1
                j-=1
            else:
                return False
        
        return True
        