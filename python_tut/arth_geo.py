# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 08:40:57 2018

@author: Atty
"""

def arth_geo(arr):
    l = len(arr)
    i = 0
    a,g = True,True
    while i<l-2:
        if a==True and (arr[i+1] - arr[i]!=arr[i+2] - arr[i+1]):
            a = False
        if g==True and (arr[i+1] / arr[i]!=arr[i+2] / arr[i+1]):
            g = False
        i += 1
    return a,g
        
at,gt=arth_geo([1,2,3,4,5,6,7,8,9,10])
print(at," ",gt)