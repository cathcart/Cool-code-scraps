import random
import math

class Vector: 
  def __init__(self, data):
    self.data = data
  def __repr__(self):
    return repr(self.data)  
  def __add__(self, other):
    data = []
    for j in range(len(self.data)):
      data.append(self.data[j] + other.data[j])
    return Vector(data)
  def __len__(self):
    return len(self.data)
  def __rmul__(self,time):
    return self*time
  def __mul__(self,time):
    return Vector([time*self.data[i] for i in range(len(self.data))])
  def __getitem__(self,index):
    return self.data[index]

def distance(a, b):
	return math.sqrt(sum([x**2 for x in a+(-1*b)]))

def findClosestCentroids(data,centroids):
	idx = [0 for x in data]
	for i in range(len(data)):
		
		m = [distance(data[i],c) for c in centroids]
		idx[i] = m.index(min(m)) 
		#print i,idx[i]
	return idx
			
def computeCentroids(data,idx):
	d = {}
	for [i,v] in zip(idx,data):
		if i in d.keys():
			d[i] += [v]
		else:
			d[i] = [v]

	new_centroids = []
	for k in d.keys():
		new_centroids.append((1.0/len(d[k]))*reduce(lambda x,y: x+y, d[k]))

	return new_centroids
	
def J(data,idx,centroids):
	s = 0
	for i in range(len(data)):
		s += distance(data[i],centroids[idx[i]])
	return (1.0/len(data))*s	

def kmeans(K,data,iterations):

	costs = []
	for i in range(100):
		#initialise
		centroids = random.sample(data,K)
		old_centroids = centroids
		
		for it in range(iterations):
	
				#assign points to nearest centroids
			idx = findClosestCentroids(data,centroids)

			#compute new centroids
			centroids = computeCentroids(data, idx);

			if sum([distance(centroids[x],old_centroids[x]) for x in range(K)]) == 0:
				#centroids no longer moving
				break
			old_centroids = centroids

		costs.append([centroids,J(data,idx,centroids)])

	return sorted(costs,key=lambda x: x[1])[0][0]

if __name__ == "__main__":

	#load data
	data_raw = open("data").read().strip().split("\n")
	data = [Vector([float(y) for y in x.split()]) for x in data_raw]
	#print data

	print kmeans(3,data,100)
