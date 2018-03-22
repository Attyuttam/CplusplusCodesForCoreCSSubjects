# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 08:47:48 2018

@author: Atty
"""
def findMaxFreq(word):
    w_freq = {}
    for letter in list(word):
        try:
            w_freq[letter] += 1
        except:
            w_freq[letter] = 1
    i=0
    max=0
    for i in w_freq:
        if w_freq[i]>max:
            max=w_freq[i]
   
    return max

def maxFreq(inp_str):
    inp_str.lower()
    i_str_arr=inp_str.split()
    mf_temp = 0
    mf = 0
    mf_word = ""
    
    for w in i_str_arr:
        mf_temp = findMaxFreq(w)
        if mf_temp>mf:
            mf = mf_temp
            mf_word = w
    return mf_word
wrd=maxFreq("Yo mama thaaaaat is my dawg")
print(wrd)