img = imread('1.jpg');
img_of = imread('1M.jpg');
img01 = im2double(imresize(img, [600, 800]));
img02 = im2double(imresize(img_of, [600, 800]));
K1 = imlincomb(0.5, img01, 0.5, img02);
K2 = img01;
for H=1:600
   for W=1:800
      if img02(H,W,1) > 0.9
         K2(H,W,:) = img02(H,W,:);
      end
   end
end
figure, imshow(K1);
figure, imshow(K2);