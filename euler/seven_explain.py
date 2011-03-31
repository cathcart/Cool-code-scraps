from math import sqrt
def sieveOfErat(end):  
  #The array doesn't need to include even numbers  
  lng = ((end/2)-1+end%2)  
'''divide the range into two (get rid of all even numbers), subtract 1, get rid of final number and then add modulo 2 of the final number. if it's even it won't be added :)'''
  # Create array and assume all numbers in array are prime  
  sieve = [True]*(lng+1)  

  # In the following code, you're going to see some funky  
  # bit shifting and stuff, this is just transforming i and j  
  # so that they represent the proper elements in the array.  
  # The transforming is not optimal, and the number of  
  # operations involved can be reduced.  

  # Only go up to square root of the end  
  for i in range(int(sqrt(end)) >> 1): #>>1 means bit shift to the right by one space
#shifting to the right is the same as dividing by powers of two 

    # Skip numbers that aren’t marked as prime  
    if sieve[i]:  

    # Unmark all multiples of i, starting at i**2  
    	for j in range( (i*(i + 3) << 1) + 3, lng, (i << 1) + 3):  
      		sieve[j] = False  

  # Don't forget 2!  
  primes = [2]  

  # Gather all the primes into a list, leaving out the composite numbers  
  primes.extend([(i << 1) + 3 for i in range(lng) if sieve[i]])  

  return primes

print len(sieveOfErat(160000))
print sieveOfErat(160000)[10000]
