# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 08:26:21 2018

@author: Atty
"""

def palin(i_str):
    i_str=i_str.lower()
    temp="".join(reversed(i_str))
    
    if temp==i_str:
        return True
    return False
print(palin("malayalam"))