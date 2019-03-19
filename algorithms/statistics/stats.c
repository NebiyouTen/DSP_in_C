/*
 * A simple program to get the mean of a signal
 */

#include "waveforms.h"
#include <stdio.h>
#include <stdlib.h>

double calculate_mean(double *input_signal, int length);

int main(){

  double mean;
  printf("SIze of InputSignal_f32_1kHz_15kHz is %lu \n", sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(double) );
  mean = calculate_mean(InputSignal_f32_1kHz_15kHz, SIGNAL_SIZE_1);
  printf("Mean= %f \n", mean);
}

double calculate_mean(double *input_signal, int length){
  int i ;
  double mean = 0;
  for (i =0; i < length; i++)
    mean += input_signal[i];
  return mean / length;
}

double calculate_variance (double *input_signal, int length){
 int i ;
 double variance = 0; 

}
