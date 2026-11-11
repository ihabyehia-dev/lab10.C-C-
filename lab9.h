/***************************************************************** 

    File: lab9.h

    Author: [ihab yehia]
    Seneca email: [iyehia1@myseneca.ca]

	The function prototypes for every function you write go
	into the header file.  You do not need to modify this file
        
***************************************************************/

/*this struct is used by all functions in lab 8.  We typically declare structs in 
.h files so that it can be included in all files that need to use the struct*/

#define STRINGMAX 10
struct DateTime
{
	int day;
	char month[STRINGMAX+1];
	int year;
	int hour;
	int minute;
};

int readDataFile1(const char* name, struct DateTime records[], int maxCapacity);
int numMonths(const char monthName[], const struct DateTime dates[], int size);
/* Add the function prototypes for the lab9 problems to this file.  
 below this comment  You can copy these from the lab specifications. */
