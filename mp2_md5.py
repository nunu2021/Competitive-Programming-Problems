import hashlib
from itertools import combinations_with_replacement
import urllib.parse
ss = "'='"
characters = ''
for i in range(32, 127):
    characters += chr(i)
print(characters)
fin = ss.encode('utf-16')

max_length = 15

for r in range(1, max_length+1):
    for combo in combinations_with_replacement(characters, r=r):
        st = ''.join(combo)   
        result = hashlib.md5(st.encode( 'utf-8'))
        if(ss in urllib.parse.unquote(result.digest()) 
        #    or ss1 in urllib.parse.unquote(result.digest()) 
        #      or ss2 in urllib.parse.unquote(result.digest()) 
        #        or ss3 in urllib.parse.unquote(result.digest()) 
        #          or ss4 in urllib.parse.unquote(result.digest()) 
        #            or ss5 in urllib.parse.unquote(result.digest()) 
        #             or ss6 in urllib.parse.unquote(result.digest()) 
                    ):
            print(st, result.digest().decode("utf-8",errors='replace'))     
        # else:
        #     print(urllib.parse.unquote(result.digest()), result.digest())                    
# !:=nt
# Answer: =Es