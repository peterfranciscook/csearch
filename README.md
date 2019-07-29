# csearch
Fast C-MEX for Array Lookups and Masking

Suppose you need to mask indices of a large array
```
argmin = find(x>=y, 1, 'first');
argmax = find(x<=y, 1, 'last');
maskedArray = x(argmin:argmax);
```
There is considerable time savings to the masking operation if the array is presorted (e.g. an array of serial timestamps) - the algorithm is now O(log(n)) instead of O(n). For a small array this doesn't make a big difference, but for a large one it is significant. `csearch` enables you to take advantage of this property of sorted arrays to quickly mask large arrays. If you use csearch on an unsorted array, the result is undefined. The idea is based on the implementation of bsearch.c in [torvalds/linux/lib/bsearch.c](https://github.com/torvalds/linux/blob/master/lib/bsearch.c). 

## Syntax
```
%CSEARCH Fast Lookup and Masking for Sorted Arrays
%
%   argmax = csearch(x, 'lt', y) is equivalent to MATLAB's find(x<y, 1, 'last')
%
%   argmax = csearch(x, 'le', y) is equivalent to MATLAB's find(x<=y, 1, 'last')
%
%   argmin = csearch(x, 'gt', y) is equivalent to MATLAB's find(x>y, 1, 'first')
%
%   argmin = csearch(x, 'ge', y) is equivalent to MATLAB's find(x>=y, 1, 'first')
%
%   Class Support
%   -------------
%   The input array x must be a 1D finite, real, non-sparse array of
%   the following classes: uint8, int8, uint16, int16, uint32, int32,
%   uint64, int64, single or double. 
%
%
%   Notes
%   -----
%   1. If input y is outside the range of the array x, -1 is returned
%
%   2. Input y should be the same class as x
%
%
% Peter Cook 2019
```

## Benchmarks
```
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
double precision
num = 100, 1000 repetitions
csearch: 0.01158909 s, MATLAB: 0.00262154 s
num = 1000, 1000 repetitions
csearch: 0.00299610 s, MATLAB: 0.00392571 s
num = 10000, 1000 repetitions
csearch: 0.00293305 s, MATLAB: 0.02520050 s
num = 100000, 1000 repetitions
csearch: 0.00387134 s, MATLAB: 0.13428660 s
num = 1000000, 1000 repetitions
csearch: 0.00318716 s, MATLAB: 1.07517482 s
num = 10000000, 1000 repetitions
csearch: 0.00379733 s, MATLAB: 14.31496315 s
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
single precision
num = 100, 1000 repetitions
csearch: 0.00319169 s, MATLAB: 0.00224358 s
num = 1000, 1000 repetitions
csearch: 0.00314525 s, MATLAB: 0.00392495 s
num = 10000, 1000 repetitions
csearch: 0.00310673 s, MATLAB: 0.02433735 s
num = 100000, 1000 repetitions
csearch: 0.00323587 s, MATLAB: 0.12829741 s
num = 1000000, 1000 repetitions
csearch: 0.00358551 s, MATLAB: 0.79688118 s
num = 10000000, 1000 repetitions
csearch: 0.00298553 s, MATLAB: 12.05700865 s
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
```
