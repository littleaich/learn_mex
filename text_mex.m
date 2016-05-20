clear all; close all; clc;

% large_number = 100;
% a = 1:large_number*large_number;
% a = reshape(a,[large_number, large_number]);
% disp(a);
a = 1:12;
a = reshape(a, [3,4]);
disp(a);
tic;
printMatrix_mex(a);
toc;
% tic;
% for i=1:large_number
%     for j=1:large_number
%         a(i,j)
%     end
% end
% toc;

