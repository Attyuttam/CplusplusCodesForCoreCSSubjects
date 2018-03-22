# -*- coding: utf-8 -*-
"""
Created on Wed Jan 17 20:41:47 2018

@author: Atty
"""
def findMax(arr):
    i=0
    maxv = arr[0]
    minv = arr[0]
    maxpos = 0
    minpos = 0
    while i<len(arr):
        if arr[i]>maxv:
            maxv=arr[i]
            maxpos=i
        if arr[i]<minv:
            minv=arr[i]
            minpos=i
        i += 1
        
    return minpos,maxpos
def sec_great_low(arr):
    if len(arr)<=2:
        print("the array has two or less elements")
        return
    minpos,maxpos=findMax(arr)    
    arr=list(arr)
    del(arr[minpos])
    del(arr[maxpos])
    minpos,maxpos=findMax(arr)   

    
    print('second minimum element: ',arr[minpos],'second maximum element: ',arr[maxpos])    
sec_great_low([5,4])