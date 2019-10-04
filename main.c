//
//  main.c
//  SevenSegmentConverter
//
//  Created by Adrian Bao on 11/03/2017.
//  Copyright © 2017 Adrian Bao. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define SEG_DIGIT_HEIGHT 3
#define MAX_CHAR_SPACE (MAX_DIGITS * 4)

/* Declarations */
void header(void);
void display_prompt(void);
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
void terminationMessage(void);
void get_digits(void);

/*
 * Uses the following seven-segment format
 *
 *    _0_
 *  5|_6_|1
 *  4|___|2
 *     3
 *
 */

const int segments[10][7] = {
    /* From the diagram above: 0 - 9 distributed as...
     * Each array accounts for which segment is on or off for each respective number
    { 0 1 2 3 4 5 6 }                                                         */
    { 1,1,1,1,1,1,0 }, // 0
    { 0,1,1,0,0,0,0 }, // 1
    { 1,1,0,1,1,0,1 }, // 2
    { 1,1,1,1,0,0,1 }, // 3
    { 0,1,1,0,0,1,1 }, // 4
    { 1,0,1,1,0,1,1 }, // 5
    { 1,0,1,1,1,1,1 }, // 6
    { 1,1,1,0,0,0,0 }, // 7
    { 1,1,1,1,1,1,1 }, // 8
    { 1,1,1,0,0,1,1 }  // 9
};

/* Character array of 4 rows (character height) and MAX_DIGITS*4 columns for the width and space */
char digits[3][MAX_CHAR_SPACE];

int main() {
    
    header();

    display_prompt();
    clear_digits_array();
    get_digits();
    print_digits_array();

    terminationMessage();
    return 0;
    
}

void header(void) {
    printf("-----------------------------------------\n");
    printf("Seven Segment Converter \n");
    printf("-----------------------------------------\n");
    printf("This program will convert an entered integer into its 7-segment equivalent\n");
    printf("(Note: Will ignore special characters, letters, and any numbers passing 10 digits)\n");
}

void display_prompt(void) {
    printf("\nEnter a number (Maximum of %d digits): ", MAX_DIGITS);
}

void clear_digits_array(void) {
    for (int row = 0; row < SEG_DIGIT_HEIGHT; row++) {
        for (int col = 0; col < MAX_CHAR_SPACE; col++) {
            digits[row][col] = ' ';
        }
    }
    
}

void get_digits(void) {
    char ch;
    int position = 0;
    // Gets input and processes until user presses enter or positions are filled in array.
    while ((ch = getchar()) != '\n' && position < (MAX_CHAR_SPACE)) {
        
        // isdigit() function ensures it will ignore any invalid input (i.e. special chars, letters, strings...)
        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += 4; // Position incremented to give space for next 7-segment digit
        }
        
    }
}

void process_digit(int digit, int position) {
    // Accounts for the 7 segments that must display for each number
    for (int i = 0; i < 7; i++) {
        
        // Uses positional assignment to correctly place the bar in the correct location of the 7 segment digit
        if (segments[digit][i]) {
            switch (i) {
                case 0: digits[0][1 + position] = '_';
                    break;
                case 1: digits[1][2 + position] = '|';
                    break;
                case 2: digits[2][2 + position] = '|';
                    break;
                case 3: digits[2][1 + position] = '_';
                    break;
                case 4: digits[2][0 + position] = '|';
                    break;
                case 5: digits[1][0 + position] = '|';
                    break;
                case 6: digits[1][1 + position] = '_';
                    break;
            }
        }
    }
}

void print_digits_array(void) {
    for (int row = 0; row < SEG_DIGIT_HEIGHT; row++) {
        for (int col = 0; col < MAX_CHAR_SPACE; col++) {
            printf("%c", digits[row][col]);
        }
        printf("\n");
    }
    
}

void terminationMessage(void) {
    printf("\n\n--- Program Complete ---\n\n");
}

