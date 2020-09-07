<!---
/*
*****************************************************************
* G Code Generator
* -------------------
* Author: Okan Kaya, 
* Date: September 07th, 2020,
* Revision: 1.0 
* Tapir Lab., TLab. at Istanbul Commerce University
* Copyright: Okan Kaya, Tapir Lab., Istanbul Commerce University
*****************************************************************
*/
-->
# G-Code Generator #

## Table of contents
* [Summary](#summary)
* [Sample Input](#sample-input)
* [Sample Output](#sample-output)

## Summary
gCodeGenerator produces G code for a circle in a given diameter. The input of the program is the radius of the circle to be converted to the G code. The output of the program is the G code of the circle as a text file. After initialization of the G code, each point is represented in a XPOSITION YPOSITION ZPOSITION format. (e.g. X10 Y10 Z10)
	
## Sample Input
The input of the program can be given in the source code. After including the headers, in the part where parameters are declared, RAD variable can be changed according to the requirements of the user.

## Sample Output
Output of the program is a text file that contains the G Code of the circle. Output example for the program when RAD = 10 is;

```
G71 G90
D0.2
G00 X0 Y0 Z30
X0 Y10
X1 Y9 Z-30
X2 Y9 Z-30
X3 Y9 Z-30
X4 Y9 Z-30
X5 Y8 Z-30
X6 Y8 Z-30
X7 Y7 Z-30
X8 Y6 Z-30
X9 Y4 Z-30
X10 Y0 Z-30
X10 Y-0 Z-30
X9 Y-4 Z-30
X8 Y-6 Z-30
X7 Y-7 Z-30
X6 Y-8 Z-30
X5 Y-8 Z-30
X4 Y-9 Z-30
X3 Y-9 Z-30
X2 Y-9 Z-30
X1 Y-9 Z-30
X0 Y-10 Z-30
X-0 Y-10 Z-30
X-1 Y-9 Z-30
X-2 Y-9 Z-30
X-3 Y-9 Z-30
X-4 Y-9 Z-30
X-5 Y-8 Z-30
X-6 Y-8 Z-30
X-7 Y-7 Z-30
X-8 Y-6 Z-30
X-9 Y-4 Z-30
X-10 Y-0 Z-30
X-10 Y0 Z-30
X-9 Y4 Z-30
X-8 Y6 Z-30
X-7 Y7 Z-30
X-6 Y8 Z-30
X-5 Y8 Z-30
X-4 Y9 Z-30
X-3 Y9 Z-30
X-2 Y9 Z-30
X-1 Y9 Z-30
X-0 Y10 Z-30
X0 Y0 Z0
```
