/* This program reads the data from the cellulolytic_biofilms_simulation output
 and produces a file where the data is organized in rows and columns. The 
 formatted data is represented in the (x,y) ordered form. The first number in 
 the (1,1) place is the total number of data points.
 The first row represents the x-value of the data points and the first column
 represents the y-values. This type of formatting is compatible with the required 
 format for the gnuplot to produce a heat-map-type plot.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//****************************************************************IMPORTANT INITIALIZATIONS*********************************************************|
//Check the below variables and make sure they match the input data before running the code.                                                        |
//**************************************************************************************************************************************************|
const double DOM_LEN=1.0; // Initialize the length of the simulated domain                                                                                                                                      
const int NUM1=16; // Initialize the number of cells in both x and y direction. It is assumed that these are equal. i.e. the coarsest grid
const int NUM2=4096; // The finest grid
const int NUM3=601;                                 
const int NUM_CHARS=100; //Initialize the size of buffer array based on the number of characters the input data have plus the NUL character '\0'.        
//**************************************************************************************************************************************************|
//**************************************************************************************************************************************************|

int main() {
	int i, j, n;
	FILE *f_in, *f_out;
	char buff[NUM_CHARS]; // Declaration of an array that saves the input data point
	double x; // x data points
	double dx; // increments along the x axis
	
	for (n=NUM1; n<=NUM2; n*=2) {
		sprintf(buff, "Biomass_density_Nx1=%d", n);
		f_in = fopen (buff, "r"); // Open the input file
		sprintf(buff, "formatted_Biomass_density_Nx1=%d", n);
		f_out = fopen (buff, "w"); // open the output file
	
		dx = DOM_LEN/ (double) n; // Initialize the value of the increment for x values
		x = dx/2.0; // Initialize the first x value
	
		fprintf(f_out, "%d ", n*NUM3); // Save the first data to the output file which is the total number of points
		for (i=0; i<n; i++) {
			fprintf(f_out, "%f ", x); // Print the x-values in the first row
			x += dx; // Increment x
			} // This for-loop saves the x cooardinates to the file (after the total number of points from above) in the first row
		fprintf(f_out, "\n"); // Add newline after the loop is finished 
	
		for (i=0; i<NUM3; i++) {
			for (j=0; j<n+1; j++) {
				fscanf(f_in, "%s", buff);
				fprintf(f_out, "%s ", buff); // y-values or time points are printed in the first column
			}
			fprintf(f_out, "\n"); // Add newline each time loop through j is performed (go to the next row)
		}
	
		fclose(f_in); // Close the input file
		fclose(f_out); // Close the output file
	}
	
	return 0;
}
