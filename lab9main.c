/***************************************************************** 

    File: lab9main.c

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
#include <ctype.h>
#include <stdlib.h>
#define CAPACITY 1000000
#define MAX 100

void generateRandomString(char str[], int max)
{
    for (int i = 0; i < max - 1; i++) {
        char c;
        do {
            c = rand() % 128;
        } while (!isprint(c));
        str[i] = c;
    }
    str[max - 1] = '\0';
}

int countAlpha(const char str[])
{
    int total = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            total++;
        }
    }
    return total;
}

int countSame(const char s1[], const char s2[])
{
    int rc = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len1 && i < len2; i++) {
        if (tolower(s1[i]) == tolower(s2[i])) {
            rc++;
        }
    }
    return rc;
}

struct StringCollection
{
    char s1[MAX];
    char s2[MAX];
};

int combine(char str[], struct StringCollection* collection)
{
    int len1 = strlen(collection->s1);
    int len2 = strlen(collection->s2);
    if (len1 < len2 || (len1 == len2 && strcmp(collection->s1, collection->s2) < 0)) {
        strcpy(str, collection->s1);
        strcat(str, collection->s2);
    } else {
        strcpy(str, collection->s2);
        strcat(str, collection->s1);
    }
    return strlen(str);
}

int main(void)
{
    char str[CAPACITY];
    generateRandomString(str, CAPACITY);
    int numAlpha = countAlpha(str);
    printf("Number of alphabetic characters: %d\n", numAlpha);
    printf("Test 2\n");

    struct StringCollection collection1 = {"daisy", "lilac"};
    struct StringCollection collection2 = {"turtle", "dove"};
    struct StringCollection collection3;
    char temp[MAX];

    combine(temp, &collection1);
    strcpy(collection3.s1, temp);

    combine(temp, &collection2);
    strcpy(collection3.s2, temp);

    printf("collection3.s1: %s\n", collection3.s1);
    printf("collection3.s2: %s\n", collection3.s2);

    char str1[] = "apple";
    char str2[] = "Alpine";
    printf("countSame(\"%s\", \"%s\") = %d\n", str1, str2, countSame(str1, str2));

    return 0;
}
