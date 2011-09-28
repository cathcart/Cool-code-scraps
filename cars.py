#import modules python 2.5* and scipy and atlas
from scipy.integrate import quad
from math import log
from math import exp
from numpy import inf

def func_inner(y):
  return (1-exp(-y))/y

def int_inner(x):
  return quad(func_inner,0,x)[0]

print quad(lambda x: exp(-2*int_inner(x)),0,inf)[0]
