# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 18:19:10 2018

@author: Atty
"""

def countVowel(str):
    l = len(str)
    i = 0
    count = 0 
    while i < l:
        if(str[i]=='a' or str[i]=='e' or str[i]=='i' or str[i]=='o' or str[i]=='u'or str[i]=='A' or str[i]=='E' or str[i]=='I' or str[i]=='O' or str[i]=='U'):
            count += 1
        i+=1
    return count
print (countVowel("hello world"))