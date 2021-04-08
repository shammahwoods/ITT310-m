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
int * getComfy(void);
int isNumeric(char str[]);
int * getWeather1(void);



int main(void) {

	// Local variable definition.

	struct Data {
		int shirt;
		int pant;
		int comfiness;
		int tempType;
		int temp1;
		int temp2;
		int result;
		int tempDiff;
	} data;

	union Info {
		int* temperature;
		int* comfortability;
	} info;

	struct PastClothes {
		int shirtType;
		int pantsType;
	} pastClothes;

	// Calling the functions
	info.temperature = getWeather1();
	pastClothes.shirtType = getShirt();
	pastClothes.pantsType = getPants();
	
	// Setting calculation variables
	data.temp1 = info.temperature[1];
	data.temp2 = info.temperature[2];
	
	// Printing the results of all the functions
	printf("\nNice work, this is what you entered:\n");

	if (pastClothes.shirtType == 5) {
		printf("Short sleeve shirt\n");
		data.shirt = 25;
	}
	else {
		printf("Long sleeve shirt\n");
		data.shirt = -25;
	}
	if (pastClothes.pantsType == 5) {
		printf("Shorts\n");
		data.pant = 25;
	}
	else {
		printf("Pants\n");
		data.pant = -25;
	}
	printf("Yesterday's temperature was %dF\n", info.temperature[1]);
	printf("Today's temperature is %dF\n", info.temperature[2]);
	
	// Calling the last data input function to determine comfiness and determine if user was too hot or too cold.
	info.comfortability = getComfy();
	printf("Okay, your comfortability score is...");

	/* Setting data variables for calculation (WIP)
	data.result = 50;
	data.comfiness = info.comfortability[1];
	data.tempType = info.comfortability[2];
	

	//data.comfiness = data.comfiness * 0.2;


	// Calculating the recommendation (Work in progress)
	if (data.temp1 > data.temp2)
		data.tempDiff = data.temp1 - data.temp2;
	else
		data.tempDiff = data.temp2 - data.temp1;
	data.result = data.result + data.shirt + data.pant;
	data.result = data.result + (data.tempDiff * data.tempType);

	
	if (data.result >= 80)
		printf("\nThis means you should probably wear pants and a long sleeve shirt.");
	else if (data.result >= 35 && data.result < 80)
		printf("\nThis means you should probably wear pants and a short sleeve shirt.");
	else if (data.result <= 34)
		printf("\nThis means you should probably wear shorts and a short sleeve shirt.");
	*/
}

//This function determines how comfortable the user was in their clothing on the prior day
int* getComfy(void) {

	// Local variable definition.
	char comfyInput[9];
	int isNum = 0;
	int isValid = 0;
	static int comfy[3];
	char hotCold[9];
	

	printf("\nOn a scale of 1-10, How comfortable were you in your clothing yesterday? ");

	/*
	*	This loop takes input on how comfortable the user is, tests to make sure it is numeric, and then 
	*	tests to see if the input is between 1 and 10
	*/
	while (isNum == 0) {
		fgets(comfyInput, 9, stdin);
		isNum = isNumeric(comfyInput);

		if (isNum == 1){
			comfy[1] = atoi(comfyInput);
			if (comfy[1] > 10 || comfy[1] < 1) {
				printf("Try again: ");
				isNum = 0;
			}
		}

	}
	printf("Were you too hot or too cold? Type H for hot, C for cold: ");
	// This loops takes an input H, or C, and returns either -20, or 20, which the main function will intepret as hot or cold.
	while (isValid == 0) {
		fgets(hotCold, 2, stdin);

		if (strcmp(hotCold, "H") == 0) {
			isValid = 1;
			comfy[2] = 0.25;
		}
		else if (strcmp(hotCold, "C") == 0) {
			isValid = 1;
			comfy[2] = 1.75;
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