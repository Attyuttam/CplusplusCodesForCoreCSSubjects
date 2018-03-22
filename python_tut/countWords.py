# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 18:22:47 2018

@author: Atty
"""

def countWords(str):
    
    str=str.strip(" ")
    str+=" ";
    l = len(str)
    i =0 
    count =0 
    while i <l :
        if str[i]==" ":
            count+=1
        i+=1
    return count
print(countWords("there are too many people here  "))