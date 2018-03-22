clc;clear all;close all;
img_grey = imread('/home/nitw_viper_user/Downloads/test3_ch3.tif');
imshow(img_grey);
%performing the log transformation
[m,n]=size(img_grey);
for i = 1:m
    for j= 1:n
        val = double(img_grey(i,j));
        newImg(i,j) = 1 * power(val,5);
    end
end
figure,imshow(newImg,[]);