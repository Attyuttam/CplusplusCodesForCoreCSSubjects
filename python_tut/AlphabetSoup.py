# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 18:00:14 2018

@author: Atty
"""

def AlphabetSoup (str):
    return sorted(list(str))
output_str=""
recieved=AlphabetSoup("hello");
for letter in recieved:
    output_str += letter
print(output_str)