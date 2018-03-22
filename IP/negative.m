img = imread('C:/Users/Atty/Desktop/desktop stuff/IP/mandrill_s.png');
imshow(img);
for i = 1:size(img,1)
    for j= 1:size(img,2)
        newImg(:,:,1) = 255 - img(:,:,1);
        newImg(:,:,2) = 255 - img(:,:,2);
        newImg(:,:,3) = 255 - img(:,:,3);
    end
end
imwrite(newImg,'C:\Users\Atty\Desktop\desktop stuff\IP\file','jpg')