# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 18:13:53 2018

@author: Atty
"""

def ABCheck(str):
    l = int(len(str))
    i = 0
    while i<(l-4):
        if str[i]=='a' and str[i+4]=='b':
            return "true"
        i+=1
    return "false"
print(ABCheck("lane borrowed"))