#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

/*
Currently untitled milestone project

Goal of program is to help user decide what clothing to wear
based on comfortability in previous temperatures compared to current ones.

Created by Ezra Woods
*/

//Function declaration
int getShirt(void);
int getPants();
int getComfy(void);
int isNumeric(char str[]);
int * getWeather1(void);



int main(void) {

	// Local variable definition.
	int* temperature;
	int shirtType;
	int pantsType;
	int comfortability;

	// Calling the functions
	temperature = getWeather1();
	shirtType = getShirt();
	pantsType = getPants();
	
	
	// Printing the results of all the functions
	printf("\nNice work, this is what you entered:\n");

	if (shirtType == 5)
		printf("Short sleeve shirt\n");
	else
		printf("Long sleeve shirt\n");

	if (pantsType == 5)
		printf("Shorts\n");
	else
		printf("Pants\n");

	printf("Yesterday's temperature was %dF\n", temperature[1]);
	printf("Today's temperature is %dF\n", temperature[2]);
	
	comfortability = getComfy();
	printf("Okay, if you were that comfy yesterday, today you should wear...");
	
}

//This function determines how comfortable the user was in their clothing on the prior day
int getComfy(void) {

	// Local variable definition.
	char comfyInput[9];
	int isNum = 0;
	int comfy = 0;


	printf("\nOn a scale of 1-10, How comfortable were you in your clothing yesterday? ");

	/*
	*	This loop takes input on how comfortable the user is, tests to make sure it is numeric, and then 
	*	tests to see if the input is between 1 and 10
	*/
	while (isNum == 0) {
		fgets(comfyInput, 9, stdin);
		isNum = isNumeric(comfyInput);

		if (isNum == 1){
			comfy = atoi(comfyInput);
			if (comfy > 10 || comfy < 1) {
				printf("Try again: ");
				isNum = 0;
			}
		}

	}
		

	
	return comfy;
}

//This function determines whether the user was wearing a long sleeve or short sleeve shirt.
int getShirt(void) {

	// Local variable definition
	int isValid = 0;
	char shirtType[2];
	int shirt = 0;

	printf("What type of shirt were you wearing yesterday? Enter L for long sleeve, S for short sleeve: ");

	// This loops takes an input L, or S, and returns either 5, or 10, which the main function will convert to long sleeve or short sleeve
	while (isValid == 0) {
		fgets(shirtType, 2, stdin);

		if (strcmp(shirtType, "L") == 0) {
			isValid = 1;
			shirt = 10;
		}
		else if (strcmp(shirtType, "S") == 0) {
			isValid = 1;
			shirt = 5;
		}
		
	}
	
	return shirt;

}


//This function determines whether the user was wearing pants or shorts.
int getPants(void) {

	// Local variable definition
	int isValid = 0;
	char pantsType[2];
	int pants = 0;

	printf("What type of pants were you wearing yesterday? Enter P for pants, S for shorts: ");

	// This loops takes an input L, or S, and returns either 5, or 10, which the main function will convert to long sleeve or short sleeve
	while (isValid == 0) {
		fgets(pantsType, 2, stdin);

		if (strcmp(pantsType, "P") == 0) {
			isValid = 1;
			pants = 10;
		}
		else if (strcmp(pantsType, "S") == 0) {
			isValid = 1;
			pants = 5;
		}

	}

	return pants;

}


/*
This function gets the weather temperature from the user and confirms that it is a numeric
value before sending it back to main as variable prevTemp.
*/
int* getWeather1(void) {

	// Local variable definition.
	char tempInput[9];
	int isNum = 0;
	int temp;
	int i;
	static int temperature[4];


	printf("What was the temperature in fahrenheit yesterday? ");

	// This loop repeats to get both yesterdays temperature, and the temperature of the current day.
	for (i = 1; i < 3; ++i) {
		/*
		 *	This loop takes weather info in the form input from the user and tests to make sure it is an integer.
		 *	The string input by the user is then converted into an int (prevTemp), which is applied to the array (temperature).
		 */
		while (isNum == 0) {
			if (i == 2)
				printf("And what is the temperature today? ");
			fgets(tempInput, 9, stdin);
			isNum = isNumeric(tempInput);
			if (isNum == 0)
				printf("Try again: ");

			temp = atoi(tempInput);
			if (temp > 130 || temp < -100) {
				printf("Try again: ");
				isNum = 0;
			}

		}
		temperature[i] = temp;
		isNum = 0;

	}
	return temperature;
}



/*
This function checks to see if a string inputted by the stdin is numeric or not.
It was created to prevent the while loop in function getInfo from looping if characters were entered.
*/
int isNumeric(char str[]){

	// Local variable definition.
	int i;
	i = 0;
	
	// Checks if each value in the string is an integer, returns 0 if not.
	for (i = 0; str[i] != '\0'; ++i) {

		if (isdigit(str[i]) == 0)
			return 0;
		else
			return 1;
	}
}