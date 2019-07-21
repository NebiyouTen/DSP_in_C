/*
 * A program to do simple running diff and runnign sum
 */

#include "../waveforms.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// function signatures
void running_sum ( double *input_signal, int input_len, double *output_signal );
void running_diff( double *input_signal, int input_len, double *output_signal );

int main() {
    // let's write the waveforms and view using GUN plot
    FILE *output_signal_ptr;
    double *output_signal;
    int i;
    output_signal_ptr   = fopen("running_sum.dat",   "w");
    output_signal = (double *) malloc( sizeof(double) * SIGNAL_SIZE_1  );
    running_sum(InputSignal_f32_1kHz_15kHz, SIGNAL_SIZE_1, output_signal);
    // if files are opened successfully, write signals to file and use GNU plot
    // to view the waveforms
    if ( output_signal_ptr )
    {
      	// write input wave from to file
      	for(i = 0; i < SIGNAL_SIZE_1; i++)
      	{
      	    fprintf(output_signal_ptr, "%f\n", output_signal[i]);
      	}
      	// close file ptrs
      	fclose(output_signal_ptr);
    }
    free(output_signal);
    return 0;
}

/*
 * running_sum():
 */
void running_sum ( double *input_signal, int input_len, double *output_signal )
{
    int i;
    output_signal[0] = input_signal[0];
    for (i = 1; i<input_len; i++)
    {
        output_signal[i] = output_signal[i-1] + input_signal[i];
    }
}

/*
 * running_diff():
 */
void running_diff( double *input_signal, int input_len, double *output_signal )
{
    int i;
    for (i = 1; i<input_len; i++)
    {
        output_signal[i] = input_signal[i] - input_signal[i-1];
    }
}
