/*
 * A program to do simple convolution
 */

#include "../waveforms.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// function signature
void conv( double *input_signal, double *impulse_rsp, int input_len
    , int impulse_len, double *output_signal );

int main() {
    // let's write the waveforms and view using GUN plot
    FILE *wave_from_ptr, *imp_rsp_ptr, *output_signal_ptr;
    int i = 0, output_size;
    double *output_signal;
    wave_from_ptr       = fopen("waveform.dat", "w");
    imp_rsp_ptr         = fopen("imp_rsp.dat",  "w");
    output_signal_ptr   = fopen("output.dat",   "w");
    output_size   = SIGNAL_SIZE_1 + IMP_RSP_SIZE;
    output_signal = (double *) malloc( sizeof(double) * output_size  );
    conv(InputSignal_f32_1kHz_15kHz, Impulse_response, SIGNAL_SIZE_1, IMP_RSP_SIZE, output_signal);
    // if files are opened successfully, write signals to file and use GNU plot
    // to view the waveforms
    if ( wave_from_ptr && imp_rsp_ptr && output_signal_ptr)
    {
      	// write input wave from to file
      	for(i = 0; i < SIGNAL_SIZE_1; i++)
      	{
      	    fprintf(wave_from_ptr, "%f\n", InputSignal_f32_1kHz_15kHz[i]);
      	}
      	// write input wave from to file
      	for(i = 0; i < IMP_RSP_SIZE; i++)
      	{
      	    fprintf(imp_rsp_ptr, "%f\n", Impulse_response[i]);
      	}
        // write input wave from to file
      	for(i = 0; i < output_size; i++)
      	{
      	    fprintf(output_signal_ptr, "%f\n", output_signal[i]);
      	}
      	// close file ptrs
      	fclose(imp_rsp_ptr      );
      	fclose(wave_from_ptr    );
      	fclose(output_signal_ptr);
    }
    free(output_signal);
    return 0;
}

/*
 *conv():
 */
void conv( double *input_signal, double *impulse_rsp, int input_len, int impulse_len,
   double *output_signal )
{
    int len_output = input_len + impulse_len, i, j;
    for (i = 0; i < len_output; i++)
    {
        output_signal[i,j] = 0;
    }
    for (i=0; i < input_len; i++)
    {
        for (j=0; j < impulse_len; j++)
        {
            output_signal[i+j] +=  input_signal[i] * impulse_rsp[j];
        }
    }
}
