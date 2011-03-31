import time
oct2bin = {'0': '000', '1': '001', '2': '010', '3': '011', '4': '100',
 '5': '101', '6': '110', '7': '111'}

def bin(n):
    if n < 0:
        return "-" + bin(-n)
    # Build list of groups of three binary digits
    s = [oct2bin[octdigit] for octdigit in ("%o" % n)]
    # Merge list to single string and remove leading zeros
    s = "".join(s).lstrip("0")
    return int(s) or "0"


def is_palin(num):
	o_num=int(str(num)[::-1])
	if num==o_num:
		return 1
	else:
		return 0

if __name__=="__main__":
	start=time.time()
	s=0
	for num in xrange(1,1000000):
		if is_palin(num):
			if is_palin(bin(num)):
				print num,
				print bin(num)
				s+=num
	print s
	print "Run time: "+str(time.time()-start)
