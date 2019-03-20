/*
 * A simple program to get the mean of a signal
 */

#include "waveforms.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calculate_mean(double *input_signal, int length);
double calculate_variance (double *input_signal, int length, int basel_correction);
double calculate_std (double *input_signal, int length, int basel_correction);

int main(){

  double mean, variance, std;
  printf("SIze of InputSignal_f32_1kHz_15kHz is %lu \n", sizeof(InputSignal_f32_1kHz_15kHz)/sizeof(double) );
  mean = calculate_mean(InputSignal_f32_1kHz_15kHz, SIGNAL_SIZE_1);
  printf("Mean= %f \n", mean);
  variance = calculate_variance(InputSignal_f32_1kHz_15kHz,SIGNAL_SIZE_1, 1);
  printf("Variance= %f \n", variance);
  std = calculate_std(InputSignal_f32_1kHz_15kHz,SIGNAL_SIZE_1, 1);
  printf("STD= %f \n", std);
}

double calculate_mean(double *input_signal, int length){
  int i ;
  double mean = 0;
  for (i =0; i < length; i++)
    mean += input_signal[i];
  return mean / length;
}

double calculate_variance (double *input_signal, int length, int basel_correction){

 int i ;
 double variance = 0, mean;

 mean = calculate_mean(input_signal, length);

 for (i=0; i<length; i++){

   variance += pow(input_signal[i] - mean,2);

 }

 if (basel_correction)
  length = length -1;
 return variance / length ;

}

double calculate_std (double *input_signal, int length, int basel_correction){

  return pow(calculate_variance(input_signal,length, basel_correction), 0.5);

}
