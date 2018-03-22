# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 17:54:57 2018

@author: Atty
"""

def Time_convert(num):
    hours=(int)(num/60)
    minutes=num % 60
    print(hours," ",minutes)
Time_convert(200)