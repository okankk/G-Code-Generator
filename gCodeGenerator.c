/*
************************************************************************
* G Code Generator
* -------------------
* Author: Okan Kaya, 
* Date: September 07th, 2020,
* Revision: 1.0 
* Tapir Lab., TLab. at Istanbul Commerce University
* Copyright: Okan Kaya, Tapir Lab., Istanbul Commerce University
************************************************************************
*/

//Include the header files in here.
#include <stdio.h> //This header file is included for standart input and output. It is used for getting input from the user and providing an output. 
#include <math.h> //This header file defines mathematical functions and parameters. In this code, pow() is used via ""math.h".

//Define the parameters as a constant.
#define RAD 100 //This expression declares the radius of the circle in a parametric way. Change this parameter!
#define Z_MIN 50 //This expression declares the depth of the engraving in Z-axis in a parametric way.
#define Z_MAX 30//This expression declares the maximum height (safe height) of the drill bit.

//Define parameters of the circle.
int x_1[RAD]; //X-axis values of the circle is kept in x_1 array.
int y_1[RAD]; //Y-axis values of the circle is kept in y_1 array.

int decision;

//Create the circle.
int gen_circ() //Generate circle function creates the circle according to the user input.
{
	for(int i = 0; i <= RAD; i++) //Radius is increased by one in order to use in the equation.
	{
		x_1[i] = i; //Domain of the function is taken directly from the counter.
		int ytemp = pow(RAD, 2) - pow(x_1[i], 2); //Circle equation is declared and used in this line. (y^2 = r^2 - x^2)
		y_1[i] = sqrt(ytemp); //Y value of the circle is simplified by taking the square root of the equation.
	}
}

//Print out the results in a .txt format as a G Code.
int print_gcode() //X and Y values of the circle is converted to G Code in this function.
{
	for(int j = 0; j <= RAD; j++) //First quarter of the circle (I. Region) is printed here.
	{
		if(j < 1) //G Code initialized in here if counter is equal to zero.
		{
			printf("G71 G90\n"); //G Code initialization have been done.
			printf("D0.2\n"); //G Code initialization have been done.
			printf("G00 X0 Y0 Z%d\n", Z_MAX); //Drill bit elevated up to the safe height.
			printf("X%d Y%d\n",x_1[j], y_1[j]); //Initial values of X and Y axis is printed.
		}
		else
		{
			printf("X%d Y%d Z-%d\n",x_1[j], y_1[j], Z_MAX); //If counter is bigger than 0 then G Code is generated from the X and Y arrays.
		}
	}
	for(int j = 0; j <= RAD; j++) //Second quarter of the circle (II. Region) is printed here.
	{
			printf("X%d Y-%d Z-%d\n",x_1[RAD - j], y_1[RAD - j], Z_MAX); // X, Y, and Z values of the circle is printed out.
	}
	for(int j = 0; j <= RAD; j++) //Third quarter of the circle (III. Region) is printed here.
	{
		printf("X-%d Y-%d Z-%d\n",x_1[j], y_1[j], Z_MAX); // X, Y, and Z values of the circle is printed out.
	}
	for (int j = 0; j <= RAD; j++) //Fourth quarter of the circle (IV. Region) is printed here.
	{
		printf("X-%d Y%d Z-%d\n",x_1[RAD - j], y_1[RAD - j], Z_MAX); // X, Y, and Z values of the circle is printed out.
		if(j == RAD)
		{
			printf("X0 Y0 Z0\n"); //Drill bit is moved back to the center.
		}
	}
}

//The main function starts here.
void main()
{	
	gen_circ(); //Circle is created.
	print_gcode(); //Result is given as an output.
}