#identify which rank each hand falls into
#compare the two players ranks
#if they're the same compare highness of rank

'''
   1 * High Card: Highest value card.
   2 * One Pair: Two cards of the same value.[match card value]
   3 * Two Pairs: Two different pairs.[match card value]
   4 * Three of a Kind: Three cards of the same value.[match card value]
   5 * Straight: All cards are consecutive values.[consecutive]
   6 * Flush: All cards of the same suit.[match suit]
   7 * Full House: Three of a kind and a pair.[match card value]
   8 * Four of a Kind: Four cards of the same value.[match card value]
   9 * Straight Flush: All cards are consecutive values of same suit.[consecutive,suit]
  10 * Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.[consecutive,suit]

'''
def match(hand):#1pair,2pairs,three of a kind,full house, four of a kind
	l=[x[0] for x in hand]
	d={}
	for i in l:
		d[i]=l.count(i)	
	print d
	result=filter(lambda x: d[x]>1,d.keys())
	print result
	if len(result)==1:
		print [result[0],d[result[0]]]
	#result=filter(lambda x: x>1,d.values())#number of pairs
	#print result	

def consecutive(hand):
	return []

def hand_rank(hand):#return value in the formate [rank,highest card in numberical format(if applicable, or 0 if not)]
	values={"T":10,"J":11,"Q":12,"K":13,"A":14}
	for i in range(2,10):
		values[str(i)]=i
	#test for multiples
	
	m=match(hand)
	if m==[]:
		c=consecutive(hand)
		if c==[]:
			#highest card
			print sorted(hand, key=lambda x:values[x[0]])[-1]#prints highest card
	
	
	#just do high card for now
'''
	m=0
	values={"T":10,"J":11,"Q":12,"K":13,"A":14}
	for card in hand:
		num=card[0]
		if num.isdigit():
			num=int(num)
		else:
			num=values[num]
		if num>m:
			m=num
	return m'''

def ans():
	#i="8C TS KC 9H 4S 7D 2S 5D 3S AC"
	i="5C TD 4D AC 5C 7C 5H 8D TD KS"
	H=i.split()
	hand_rank(H[:5])
	'''values={"T":10,"J":11,"Q":12,"K":13,"A":14}
	for i in range(2,10):
		values[str(i)]=i
	t=sorted(H[:5], key=lambda x:values[x[0]])
	match(t)'''


if __name__=="__main__":
	ans()
