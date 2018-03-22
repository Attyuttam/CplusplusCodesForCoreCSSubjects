clc;clear all;close all;
v = 0;
for noi =2 : 4
     if noi == 1
         img = imread('/home/nitw_viper_user/Downloads/he1.tif');
     end
     if noi == 2
        img = imread('/home/nitw_viper_user/Downloads/he8.tif');
    end
    if noi == 3
        img = imread('/home/nitw_viper_user/Downloads/he7.tif');
    end
    if noi == 4
        img = imread('/home/nitw_viper_user/Downloads/he6.tif');
    end
    [k1 k2]=size(img);

    %initialization 
    for i =1:256
        pix(i)=i-1;
        new_pixel_val(i) = 0 ;
        pixel_val(i) = 0 ;
        s(i) = 0;
        n(i) = 0; 
    end
    %calculating the frequency 
    for i = 1:k1
        for j= 1:k2
            pixel_val(img(i,j)+1) = pixel_val(img(i,j)+1) + 1;
        end
    end
    %calculating the cumulative values
    n(1) = pixel_val(1);
    for i =2:256
        n(i) = n(i-1) + pixel_val(i);
    end
    %calculate the value of 's'
    for i =1:256
        s(i) = floor((255/(k1*k2)) * n(i));
    end
    %creating the new image
    for i = 1:k1
      for j= 1:k2
        newImg(i,j) = s(img(i,j)+1);
      end
    end

    for i = 1:k1
        for j= 1:k2
            new_pixel_val(newImg(i,j)+1) = new_pixel_val(newImg(i,j)+1) + 1;
        end
    end
    
   newImg=mat2gray(newImg)
    v = v +1 ;
    subplot(5,4,v),imshow(img);
    title('original image');
    v = v + 1;
    subplot(5,4,v),imshow(newImg);
    title('result image');
    v = v + 1;
    subplot(5,4,v),plot(pix,pixel_val);
    title('histogram of original image');
    v = v + 1;
    subplot(5,4,v),plot(pix,new_pixel_val);
    title('histogram of result image');
end