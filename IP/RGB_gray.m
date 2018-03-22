clc;clear all;close all;
img = imread('C:\Users\Atty\Desktop\desktop stuff\IP\mandrill_s.png');
figure,imshow(img);
R = img(:,:,1)
G = img(:,:,2)
B = img(:,:,3)
[k1 k2]=size(R);
for i = 1:k1
    for j= 1:k2
        newImg(i,j) = (0.2989*R(i,j)) + (0.5870*G(i,j)) + (0.114*B(i,j));
    end
end

imwrite(newImg,'C:\Users\Atty\Desktop\desktop stuff\IP\file','jpg');