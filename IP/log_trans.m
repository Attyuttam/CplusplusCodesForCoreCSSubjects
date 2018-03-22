clc;clear all;close all;
img_grey = imread('C:/Users/Atty/Desktop/desktop stuff/IP/mandrill_s.png');
imshow(img_grey);
%performing the log transformation
[m,n]=size(img_grey);
for i = 1:m
    for j= 1:n
        val = double(img_grey(i,j));
        newImg(i,j) = uint8(0.1 *log10(1+val));
    end
end
%figure,imshow(newImg);