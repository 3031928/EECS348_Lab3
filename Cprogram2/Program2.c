/*
 * Program2.c
 *
 * Created on: Feb 9, 2023
 * 		Author: Samuel Buehler
 */

#include <stdio.h>

void combinations(int score)
{
	for (int i = 0; i <= score / 8; i++) // Account for all possibilities for the TD + 1pt FG
	{
		for (int j = 0; j <= score / 7; j++) // Account for all possibilities for the TD + 2pt conversion
		{
			for (int k = 0; k <= score / 6; k++) // Account for all possibilities for TDs
			{
				for (int l = 0; l <= score / 3; l++) // Account for all possibilities for FG
				{
					for (int m = 0; m <= score / 2; m++) // Account for all possibilities for Safeties
					{
						int value = i * 8 + j * 7 + k * 6 + l * 3 + m * 2; // Calculate the sum score of the current play rewards
						if (value == score) // If the sum value is equal to the score we're looking for...
						{
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m); // Print the combination
						}
						else if (value > score) // If the sum value is not equal to the score we're looking for...
						{
							break;
						}
					}
				}
			}
		}
	}
}

int main()
{
	int score = 2; // Start the score above the limiter.
	while (score != 0 && score != 1) // While score is not 0 or 1
	{
		printf("Enter 0 or 1 to STOP\nEnter the NFL score: "); // Print prompt
		scanf("%d", &score); // Get input, save it as score
		if (score != 0 && score != 1) // If the input is not equal to 0 or 1 ...
		{
			combinations(score); // Call the combinations function given the user inputed score.
		}
	}
	return 0;
}
