clc;clear all;close all;
img_grey = imread('C:/Users/Atty/Desktop/desktop stuff/IP/mandrill_s.png');
%imshow(img_grey);

%performing the smoothing operation
[m,n]=size(img_grey);
img_grey=im2double(img_grey);

%using the 1/9 one
for i = 2:m-1
    for j= 2:n-1
       im_final1(i,j) = max(img_grey(i,j) , img_grey(i-1,j-1) , img_grey(i-1,j) , img_grey(i-1,j+1) , img_grey(i,j-1) , img_grey(i,j+1) , img_grey(i+1,j-1) , img_grey(i+1,j) , img_grey(i+1,j+1));
    end
end
im_final1=mat2gray(im_final1);

%using the 1/16 one
for i = 2:m-1
    for j= 2:n-1
       im_final2(i,j) = min(img_grey(i,j) , img_grey(i-1,j-1) , img_grey(i-1,j) , img_grey(i-1,j+1) , img_grey(i,j-1) , img_grey(i,j+1) , img_grey(i+1,j-1) , img_grey(i+1,j) , img_grey(i+1,j+1));
    end
end
im_final2=mat2gray(im_final2);

%using the 1/32 one
for i = 2:m-1
    for j= 2:n-1
       im_final3(i,j) = 16 * img_grey(i,j) + img_grey(i-1,j-1) + 3*img_grey(i-1,j) + img_grey(i-1,j+1) + 3*img_grey(i,j-1) + 3*img_grey(i,j+1)+ img_grey(i+1,j-1) + 3*img_grey(i+1,j)+ img_grey(i+1,j+1);
       im_final3(i,j) = im_final3(i,j) ./ 9 ;
    end
end
im_final3=mat2gray(im_final3);

    
    subplot(2,2,1),imshow(img_grey);
    title('original image');
    
    subplot(2,2,2),imshow(im_final1);
    title('1/9 image');
    
    subplot(2,2,3),imshow(im_final2);
    title('1/16 image');
    
    subplot(2,2,4),imshow(im_final3);
    title('1/32 image');