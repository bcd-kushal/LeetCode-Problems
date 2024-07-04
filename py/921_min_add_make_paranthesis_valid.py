def minAddToMakeValid(self, s: str) -> int:
        lc: int = 0
        extra: int = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                lc += 1
            else:
                if lc > 0:
                    lc -= 1
                else:
                    extra += 1
                    
        return extra + lc
