clear all; close all; clc;

% function [desc] = extractHog2D(img, cellSize, blockSize, numBins, ...
%    blockOverlap, orientationSigned)
%%% Input parameter
% img = 2-D image of type uint8 / single / double
% cellSize = size of cells in pixels
% blockSize = size of blocks in units of cells
% numBins = number of histogram bins without signs
% orientationSigned = false =>> dimension of histogram == numBins
%                     true => dimension of histogram == 2*numBins - 1
% blockOverlap = number of ovarlapping cells between adjacent blocks

%%% Output parameter
% desc = set of descriptors 

% structure specifying default hog2D parameters
hogParams.cellSize = 8;
hogParams.blockSize = 2;
hogParams.numBins = 9;
hogParams.blockOverlap = 2; % both dimensions
hogParams.orientationSigned = true;


% check input arguments
% switch nargin
%     case 1
%         error('No input argument is passed, at least 1 argument is needed');
%     case 2
%         hogParams.cellSize = cellSize;
%     case 3
%         hogParams.cellSize = cellSize;
%         hogParams.blockSize = blockSize;
%     case 4
%         hogParams.cellSize = cellSize;
%         hogParams.blockSize = blockSize;
%         hogParams.numBins = numBins;
%     case 5
%         hogParams.cellSize = cellSize;
%         hogParams.blockSize = blockSize;
%         hogParams.numBins = numBins;
%         hogParams.blockOverlap = blockOverlap;
%     case 6
%         hogParams.cellSize = cellSize;
%         hogParams.blockSize = blockSize;
%         hogParams.numBins = numBins;
%         hogParams.blockOverlap = blockOverlap;
%         hogParams.orientationSigned = orientationSigned;
%     otherwise
%         error('Too many input arguemnts');
% end

img = imread('cameraman.tif');

% checking image type - uint8/single/double
assert(isa(img,'uint8') || isa(img,'single') || isa(img,'double'), ...
    'Image must be of type uint8/single/double');


img = im2single(img);
[grad_x, grad_y] = imgradientxy(img); % horizontal and vertical gradient
[desc] = calcHog2D(img, grad_x, grad_y, hogParams);
    
