def isSubsequence(s:str, t:str)->bool:
    if len(s)==0:
        return True
    
    if len(t)==0:
        return False
    
    i:int = 0
    for j in range(len(t)):
        if t[j]==s[i]:
            i+=1

    if i<len(s) and i==len(s):
        return True
    
    return False