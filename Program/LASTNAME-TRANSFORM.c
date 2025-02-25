/*    
	Do NOT forget to include your name and section below.
	
	lASTNAME, FIRSTNAME: ____________________        SECTION: _____
	
	DO NOT define a main() function in this file.  The main() function definition is already 
	given in the accompanying main.c file.
	
	Note that if you compile JUST this file only, you will get an error that says "undefined
	reference to WinMain" (for DEVCPP users).  
	
	You'll have to include this file first in main.c via #include, and then it is the main.c 
	that you you should compile to produce the main.exe file.
	
    Violation of any of the RESTRICTIONS or non-compliance with the specifications will result to point deductions. 
*/


/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transform.h"   // make sure that you read & understand the contents of this header file

/*
	RESTRICTION: Do not use any string library function not discussed in our class or Course Notes.  
	You are limited to using only four string functions, specifically: 
	
			strlen(), strcpy(), strcat() and strcmp()  
	
	A solution that does not comply with this restriction will be considered an incorrect solution, 
	and therefore, the score for the required function will be zero.
*/

/*
	You may define any number of helper functions that you deem necessary below this comment.
	You are free to decide on the function return type, name, and parametrization of your helper functions.
*/


/*
	TO DO #1: implement Search() as described in the problem specs.
	
	creature is the search key
    MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].	
*/
int 
Search(String creature, String MasterList[], int n)
{ 
  int i, val;
  for(i = 0; i < n; i++){
    val = strcmp(creature, MasterList[i]);
    if(val == 0){
      return i;
    }
  }
	return -1;  // Do NOT forget to return a value. You'll need to change 888.
}


/*
	TO DO #2: implement Spawn() as described in the problem specs.
	
	creature is the string to be stored in the Matrix with the specified row and column indices.
*/
int
Spawn(String creature,  int row, int col, String Matrix[][COLSIZE])
{
  if(Matrix[row][col][0] == '\0'){
    strcpy(Matrix[row][col], creature);
    return 1;
  }
  else{
    return 0;
  }
}


/*
	TO DO #3: implement GetMatrixScore() as described in the problem specs.
	
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].	
*/
int GetMatrixScore(String Matrix[][COLSIZE], String MasterList[], int n)
{
  int counter = 0;
  int i, j, index; 
  for(i = 0; i < ROWSIZE; i++){
    for(j = 0; j < COLSIZE; j++){
      if(Matrix[i][j][0]!='\0'){
        index = Search(Matrix[i][j], MasterList, n);
        counter += (int)pow(2, index);
      }
    }
  }
	return counter;  // Do NOT forget to return a value. You'll need to change 888.
}


/*
	TO DO #4: implement FrequencyCount() as described in the problem specs.

	FC is the 1D array of counters.  Assume that the elements of FC are initialized to 0 prior to calling this function.
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].
*/
void 
FrequencyCount(int FC[], String Matrix[][COLSIZE], String MasterList[], int n)
{
	int i, j, index;

  for(i = 0; i < ROWSIZE; i++){
    for(j = 0; j < COLSIZE; j++){
      if(Matrix[i][j][0]!='\0'){
        index = Search(Matrix[i][j], MasterList, n);
        FC[index]++;
    }
  }
}
}

/*
	TO DO #5: implement Merge() as described in the problem specs.
	
	row1 and col1 are the indices of the 1st creature
	row2 and col2 are the indices of the 2nd creature
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].
*/
int 
Merge(int row1, int col1, int row2, int col2, String Matrix[][COLSIZE], String MasterList[], int n)
{
  int i1, i2;
  if(Matrix[row1][col1][0] != '\0' && Matrix[row2][col2][0] != '\0'){
    i1 = Search(Matrix[row1][col1], MasterList, n);
    i2 = Search(Matrix[row2][col2], MasterList, n);
    if(i1 == i2){
      if(i1 == 11){
        return 2;
      }
      else{
        strcpy(Matrix[row1][col1], MasterList[i1 + 1]);
        Matrix[row2][col2][0] = '\0';
        return 1;
      } }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
	
}


/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  

    The main() is in the accompanying main.c source file.
    
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/

