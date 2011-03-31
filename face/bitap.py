def bitap_search(text,pattern):
	m=len(pattern)
	result=range(m+1)
	
	result[0]=1
	for k in range(1,m+1):
		result[k]=0
	for i in range(len(text)):
		k_range=range(m)
		k_range.reverse()
		print k_range
		for k in k_range:
			if text[i]==pattern[k-1]:
				result[k]=result[k-1]
			if result[m]:
				ans=(text+i-m)+1
				break
	return result

if __name__=="__main__":
	print bitap_search("one","one")			
