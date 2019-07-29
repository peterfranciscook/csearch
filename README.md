# csearch
Fast C-MEX for Array Lookups and Masking

```
%CSEARCH Fast Lookup and Masking for Sorted Arrays
%
%   argmax = csearch(x, 'lt', y) is equivalent to MATLAB's find(x<y, 1, 'last')
%
%   argmax = csearch(x, 'le', y) is equivalent to MATLAB's find(x<=y, 1, 'last')
%
%   argmin = csearch(x, 'gt', y) is equivalent to MATLAB's find(x>y, 1, 'last')
%
%   argmin = csearch(x, 'ge', y) is equivalent to MATLAB's find(x>=y, 1, 'last')
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
