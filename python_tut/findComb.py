# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 09:49:54 2018

@author: Atty
"""
#working only with positive values
#this is hardcoded, but the idea is okay
def findComb(val,arr,i,l):
    if val==arr[i]:
        return True
    if i == l-1:
        return False
    if val >= arr[i]:
        return findComb(val,arr,i+1,l) or findComb(val-arr[i],arr,i+1,l)
    return findComb(val,arr,i+1,l)

print(findComb(23,[3,4,6,9,23],0,4))