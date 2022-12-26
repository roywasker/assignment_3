#ifndef _MY_MAT_H_
#define _MY_MAT_H_

/*
The function receives a string from the standard input and stores it in the string s. 
The function will return the amount of characters actually received.
*/
int newgetlinen(char s[]);


/*
The function receives a string from the standard input and saves it in the string w.
The function will return the amount of characters actually received.
*/
int getword(char w[]);

/*
The function receives two strings str1 - str 2 and checks if str2 is contained in str1. 
The function will return 1 if yes and 0 if not.
*/
int substring( char * str1, char * str2);


/*
The function will receive two strings s t and a number n . 
The function will check if it is possible to get from the string S to the string t By omitting n characters.
The program will return 1 if it can be omitted, for identical strings and the number 0 The program will return 1 only if the two strings are the same
*/
int similar (char *s, char *t, int n);

/*
The function receives the desired string for search, captures the lines of text, and prints the lines in which the string appears.
*/
void print_lines(char * str);

/*
The function receives the desired string for the search, picks up the words of the text 
and prints the words similar to the search string up to the omission of one letter from the words that appear in the text
*/
void print_similar_words(char * str);


#endif