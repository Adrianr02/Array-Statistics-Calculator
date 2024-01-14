/*This program asks the user to input a set of elements
into an array that hold 7 elements.Then the code
records the values add them all up to yeild the sum.
The code then takes the sum and calcualtes the avg.
The code gets the smallest value as well as its location
and then displays it to the user.

Dictionary of Variables:

arrSize = set number of elements
tsum = total sum of elements
avg = avg of the sum of elements
snum = smallest element in array
postion = postion of the smallest element
value = store the value of the current position
nextvalue = stores a value to compare with value
to get the smallest value in the array

Input:
	7 elements chosen by user

Output:
	sum of array
	avgerage of array
	smallest value of array
	smallest value location

Process:
	The program takes the inputted 7 element
	values from the user and stores it.
	The program then takes the values and displays
	them to the user. These values are then added
	up to yeild the sum. The sum is displayed and
	the average of the array is found with the sum
	and displayed to the user. The program then takes
	the smallest value of the array and location
	of the value and displays it to the user.


Written by:Adrian Ramdhanee
Target:         gcc
*/

#include <stdio.h>
#include <stdlib.h>

#define arrSize 7

//declaration of recursive functions
int sum(int arr[], int postion);
int smallest(int arr[],int postion);
int findSPostion(int arr[], int postion, int snum);

//displays to the user the sum,avg,smalles,smallest
//location of the array
int main(void)
{

    int arr[arrSize], sposition = 0;
    //prompts user to input the 7 elements
    printf("Please enter the elements of array X:\n\n");
    //stores the user inputted values
    for(int i = 0; i < arrSize; i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe values of the array:\n");
    //runs the recursive functions in main
    int tsum = sum(arr,0),avg = tsum/arrSize, snum = smallest(arr,0),postion = findSPostion(arr,0,snum);
    printf("\nSum:%d\n",tsum);
    printf("Average:%d\n", avg);
    printf("Smallest:%d\n", snum);
    printf("Smallest Location: %d\n",postion+1);
    return 0;
}
//find sum of the array
int sum(int arr[], int postion)
{
    //this is where the recursive function is being called
    int value = arr[postion];
    printf("%d ", arr[postion++]);
    //this if statment compares postion with arrSize
    if(postion < arrSize)
    {
      value += sum(arr,postion);
    }

        return value;
}

//this recursive function gets the smallest value in the array
int smallest(int arr[],int postion)
{

    int value = arr[postion++];
    //the if statment compares postion to the size of the array
    if(postion < arrSize)
    {
        int nextValue = smallest(arr,postion);
        //this nested if statement compares value to next value where next value is the recursive function
        if(value > nextValue)
        {
            value = nextValue;
        }
    }
    return value;
}

int findSPostion(int arr[], int postion, int snum)
{
    //if the array postion does not = to the smallest number
    if(arr[postion] != snum)
    {
        //postion is assigned the location of the smallest number
        postion = findSPostion(arr,++postion,snum);
    }
    return postion;
}

