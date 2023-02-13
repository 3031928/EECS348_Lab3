/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Samuel Buehler
 */

#include<stdio.h>

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void sales_report(float data[12])
{
	printf("Monthly sales report for 2022:\n");
	printf("%-11s%s\n", "Month", "Sales");
	/* For all 12 months, print the month and that month's respective sales number. */
	for(int i = 0; i < 12; i++)
		printf("%-11s$%.2f\n",months[i],data[i]);
}


void min_max_avg(float data[12])
{
	float minimum = data[0], maximum = data[0], sum = 0.0, average;
	int minMonth = 0, maxMonth = 0;

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

	printf("\nSales summary:\n");
	printf("%-16s$%-10.2f  (%s)\n", "Minimum sales:", minimum, months[minMonth]);
	printf("%-16s$%-10.2f  (%s)\n", "Maximum sales:", maximum, months[maxMonth]);
	printf("%-16s$%-10.2f\n", "Average sales:", average);
}

void six_month_avg(float data[12])
{
	printf("\nSix-Month Moving Average Report:\n");
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
}

void print_sales_descending(float data[12])
{
	printf("\nSales Report (Highest to Lowest):\n");
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
		printf("%-16s $%-11.2f\n",months[i],data[i]);
}


int main() {
	/* Scans input file data into the data array. */
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
