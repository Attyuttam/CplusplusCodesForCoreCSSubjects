clc;clear all; close all;
arr = [1,2,3;4,5,6;7,8,9]
[m,n]=size(arr);
for i=1:m
    for j=1:n
        a(i,j)=1*power(arr(i,j),2);
    end
end