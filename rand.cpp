#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "rand.h"
#include "main.h"

double *rand_bit;
double NUM_rand_bit;
void Bit_gen_memory_allocation(void)
{
	rand_bit = (double *)malloc(NUM_rand_bit* sizeof(double));
}

void Rand_gen(void)
{
	int i;
//	int histo_i[100]={0};
//	int j;
//	FILE *fp_rand_bit;

	/************************************************************
	*               	 data part generation	
	************************************************************/

	for(i = 0 ; i < NUM_rand_bit ; i++) {
		rand_bit[i] = (double)rand()/RAND_MAX;			// information bit generation
		
/*		// Histogram을 그리기 위한 part.
		j = (int)(rand_bit[i]*100);
		histo_i[j]++;
*/
//		if(i<5) printf("[%d] %lf \n", i, rand_bit[i]);

	}
	

	/************************************************************
	*                          Output   
	************************************************************/

//	printf("%d \t%lf \n", 1, rand_bit[1]);
/*	fp_rand_bit = fopen("rand_bit.txt", "w");
	for(i = 0; i < NUM_rand_bit; i++) {
		fprintf(fp_rand_bit, "%d \t%lf \n", i, rand_bit[i]);
//		printf("[%d] %d \n", i, rand_bit[i]);
	}

		fprintf(fp_rand_bit, "\n\n\n HISTOGRAM Indicators \n");

	for(i = 0; i < 100; i++) {
		fprintf(fp_rand_bit, "%d \t%d \n", i, histo_i[i]);
//		printf("[%d] %d \n", i, rand_bit[i]);
	}

	fclose(fp_rand_bit);
*/

}

void Exp_Rand_gen(double *exp_rand_bit, double Lambda) 
{
	int i;
//	int j;
//	double bin_dur;
//	int histo_exp[100]={0};
//	double exp_rand_MAX=0;
//	FILE *fp_exp_rand_bit;

	/************************************************************
	*                	 data part generation	
	************************************************************/

	Rand_gen();

	for(i = 0 ; i < NUM_rand_bit ; i++) {

		// rand_bit가 0이면 무한대로 가버리는 에러가 생긴다. 
		if(rand_bit[i] == 0)
			exp_rand_bit[i] =  -(1./Lambda)*log(1-0.11111111);
		else
			exp_rand_bit[i] = -(1./Lambda)*log(1.-rand_bit[i]);
		
		//exp_rand_MAX의 최대값을 구한다. histogram을 그리기 위한 tool이다. 
/*		if(exp_rand_MAX < exp_rand_bit[i])
			exp_rand_MAX = exp_rand_bit[i];
*/

//		if(i<5) printf("[%d] %lf \n", i, rand_bit[i]);
//		if(i<5) printf("randb [%d] %lf \n", i, exp_rand_bit[i]);

	}
	
	// histogram을 위한 bin_duration
//	bin_dur = exp_rand_MAX/100;


/*	// histogram을 그리는 함수
	for(i = 0 ; i < NUM_rand_bit ; i++) {	
		
		j = (int)(exp_rand_bit[i]*(1/bin_dur));
		histo_exp[j]++;
	}
*/	

//	printf("exp_rand_MAX =  %lf \n", 1, exp_rand_MAX);

	/********************************************************
	*                       Output   
	********************************************************/
/*
	fp_exp_rand_bit = fopen("exp_rand_bit.txt", "w");
	for(i = 0; i < NUM_rand_bit; i++) {
		fprintf(fp_exp_rand_bit, "%d \t%lf \n", i, exp_rand_bit[i]);
	}

		fprintf(fp_exp_rand_bit, "\n\n\n HISTOGRAM Indicators \n");

	for(i = 0; i < 100; i++) {
		fprintf(fp_exp_rand_bit, "%d \t%d \n", i, histo_exp[i]);
	}

	fclose(fp_exp_rand_bit);
*/

}


double Exp_Rand_gen1(double Lambda) 
{
	double exp_rand_bit;

	/************************************************************
	*                	 data part generation	
	************************************************************/

	Rand_gen();

		// rand_bit가 0이면 무한대로 가버리는 에러가 생긴다. 
	if(rand_bit[0] == 0)
		exp_rand_bit =  -(1./Lambda)*log(1-0.11111111);
	else if(rand_bit[0] ==1)
		exp_rand_bit =  0;
	else
		exp_rand_bit = -(1./Lambda)*log(1.-rand_bit[0]);	
	return exp_rand_bit;
}
/********************************************************
* Memory_free, Initialization, etc.
********************************************************/

void Bit_gen(int * bit_stream, int stream_size) 
{
	int i;
	
	for(i=0; i<stream_size; i++) 
	{
		bit_stream[i] = rand()%2;
	}
}

void Bit_gen_memory_free(void) 
{
	free(rand_bit);
}
