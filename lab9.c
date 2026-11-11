/***************************************************************** 

    File: lab9.c

    Author: [ihab yehia]
    Seneca email: [iyehia1@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab9.c lab9main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "lab9.h"

int readDataFile1(const char* name, struct DateTime records[], int maxCapacity){
    FILE *fp = fopen(name,"r");
    int i=0;
    int month;
    if(fp !=NULL){
      while(fscanf(fp, "%d,%d,%d,%d,%d\n",&month , &records[i].day, &records[i].month, &records[i].year, &records[i].hour, &records[i].minute== 5)){
        if(month==1){
           strcpy( &records[i].month, "jan");
        }
        else if(month == 2){
            strcpy( &records[i].month, "feb");
        }
         else if(month == 3){
            strcpy( &records[i].month, "march");
        }
         else if(month == 4){
            strcpy( &records[i].month, "april");
        }
         else if(month == 5){
            strcpy( &records[i].month, "may");
        }
         else if(month == 6){
            strcpy( &records[i].month, "june");
        }
         else if(month == 7){
            strcpy( &records[i].month, "july");
        }
         else if(month == 8){
            strcpy( &records[i].month, "aug");
        }
         else if(month == 9){
            strcpy( &records[i].month, "sep");
        }
         else if(month == 10){
            strcpy( &records[i].month, "oct");
        }
         else if(month == 11){
            strcpy( &records[i].month, "nov");
        }
         else if(month == 12){
            strcpy( &records[i].month, "dec");
        }
        
        i++;
      }
    }
    else{
        printf("Error opening the file.");
    }
    fclose(fp);
}

struct DateTime {
    int day;
    int month;   // 1 = Jan, 2 = Feb, ..., 12 = Dec
    int year;
    int hour;
    int minute;
};

const char* monthToString(int month) {
    switch (month) {
        case 1: return "jan";
        case 2: return "feb";
        case 3: return "mar";
        case 4: return "apr";
        case 5: return "may";
        case 6: return "jun";
        case 7: return "jul";
        case 8: return "aug";
        case 9: return "sep";
        case 10: return "oct";
        case 11: return "nov";
        case 12: return "dec";
        default: return "";
    }
}

int numMonths(const char monthName[], const struct DateTime dates[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(monthToString(dates[i].month), monthName) == 0) {
            count++;
        }
    }
    return count;
}

