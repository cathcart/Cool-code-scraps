def is_palindrome(n):
        n = str(n)
        if n == n[::-1]:
                return True
        else:
                return False
 
def rev_add(n):
        n = str(n)
        n_rev = n[::-1]
        return int(n)+int(n_rev)
 
num = 0
for x in range (1,10000):
        n = x
        loops = 0
        if is_palindrome(n):   # make sure that the program enters the loop
                n = rev_add(n) # even if the number is palindromic, i.e.
                loops += 1     # 4994
        while is_palindrome(n) == False and loops < 50:
                n = rev_add(n)
                loops += 1
 
        if loops >= 50:
                num += 1
print num
