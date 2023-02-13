/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Samuel
 */

#include<stdio.h>

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void sales_report(float data[12])
{
	printf("Monthly sales report for 2022:\n");
	printf("%-11s%s\n", "Month", "Sales");
	for(int i = 0; i < 12; i++)
	{
		printf("%-11s", months[i]);
		printf("$%.2f\n", data[i]);
	}
	printf("\n");
}


void min_max_avg(float data[12])
{
	float minimum = data[0];
	int minMonth = 0;
	float maximum = data[0];
	int maxMonth = 0;
	float sum = 0.0;
	float average;

	// Find minimum and minMonth
	for (int i = 0; i < 12; i++)
	{
		if (data[i] < minimum)
		{
			minimum = data[i];
			minMonth = i;
		}
		if (data[i] > maximum)
		{
			maximum = data[i];
			maxMonth = i;
		}
	}

	// Find average
	for (int i = 0; i < 12; i++)
		sum += data[i];
	average = sum/12;


	printf("Sales summary:\n");
	printf("%-16s$%-10.2f  (%s)\n", "Minimum sales:", minimum, months[minMonth]);
	printf("%-16s$%-10.2f  (%s)\n", "Maximum sales:", maximum, months[maxMonth]);
	printf("%-16s$%-10.2f", "Average sales:", average);
	printf("\n\n");
}

void six_month_avg(float data[12])
{
	printf("Six-Month Moving Average Report:\n");
	for (int i = 0; i <= 6; i++)
	{
		printf("%-11s-  %-11s", months[i], months[i+5]);
		float sum = 0.0;
		float avg;
		for (int j = i; j < i+6; j++)
			sum += data[j];
		avg = sum/6;
		printf("$%.2f\n", avg);
	}
	printf("\n");
}

void print_sales_descending(float data[12])
{
	//float dataCopy[12];
	printf("Sales Report (Highest to Lowest):\n");
	printf("%-16s %-11s\n", "Month", "Sales");

	for (int i = 0; i < 12; ++i)
	{
		for (int j = i + 1; j < 12; ++j)
		{
			if (data[i] < data[j])
			{
				float a = data[i];
				char *b = months[i];
				data[i] = data[j];
				months[i] = months[j];
				data[j] = a;
				months[j] = b;
			}
		}
	}

	for (int i = 0; i < 12; ++i)
	{
		printf("%-16s $%-11.2f\n",months[i],data[i]);
	}

}


int main() {
	FILE *fp;
	fp = fopen("input.txt","r");
	float data[12];

	fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}
	for(int i = 0; i < 12; i++)
		fscanf(fp, "%f", &data[i]);
	fclose(fp);
	sales_report(data);
	min_max_avg(data);
	six_month_avg(data);
	print_sales_descending(data);
}
