/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

//Setting a global array for the questions, that way the array can be accessed in the different functions
question questions[12];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    
    //Creating all the info for each question:
    question programming1 = { 
    .category = "programming", 
    .question = "A type of programming that creates \"objects\" and manipulates those objects.\n", 
    .answer = "What is object oriented programming", 
    .value = 200, 
    .answered = false
    };
    question programming2 = { 
    .category = "programming", 
    .question = "A data type that stores true/false (full name).\n", 
    .answer = "What is boolean", 
    .value = 400, 
    .answered = false
    };
    question programming3 = { 
    .category = "programming", 
    .question = "A programming structure that typically begins with \"while\" or \"for\".\n", 
    .answer = "What is a loop", 
    .value = 600, 
    .answered = false
    };
    question programming4 = { 
    .category = "programming", 
    .question = "A data type that typically stores values from -32,768 to 32,767 (full name).\n", 
    .answer = "What is integer", 
    .value = 800, 
    .answered = false
    };
    
    question algorithms1 = { 
    .category = "algorithms", 
    .question = "This function describes a time complexity that runs in linear time (worst case).\n", 
    .answer = "What is O(n)", 
    .value = 200, 
    .answered = false
    };
    question algorithms2 = { 
    .category = "algorithms", 
    .question = "Named after its speed, this sorting algorithm sorts in O(n log n) time (average case).\n", 
    .answer = "What is quicksort", 
    .value = 400, 
    .answered = false
    };
    question algorithms3 = { 
    .category = "algorithms", 
    .question = "The process of a program calling its own code.\n", 
    .answer = "What is recursion", 
    .value = 600, 
    .answered = false
    };
    question algorithms4 = { 
    .category = "algorithms", 
    .question = "An algorithm that makes a locally optimal choice at each stage, but does not usually produce an optimal solution.\n", 
    .answer = "What is a greedy algorithm", 
    .value = 800, 
    .answered = false
    };
    
    question databases1 = { 
    .category = "databases", 
    .question = "A standard database language the stands for \"Structured Query Language\".\n", 
    .answer = "What is SQL", 
    .value = 200, 
    .answered = false
    };
    question databases2 = { 
    .category = "databases", 
    .question = "The way to SELECT all fields in a given table.\n", 
    .answer = "What is SELECT *", 
    .value = 400, 
    .answered = false
    };
    question databases3 = { 
    .category = "databases", 
    .question = "A KEY that uniquely indentifies each record in a table. A table can only have one of these KEYs.\n", 
    .answer = "What is a PRIMARY KEY", 
    .value = 600, 
    .answered = false
    };
    question databases4 = { 
    .category = "databases", 
    .question = "This SQL wildcard represents \"zero or more characters\".\n", 
    .answer = "What is %", 
    .value = 800, 
    .answered = false
    };

    //assigning all the above questions into the questions array    
    questions[0] = programming1;
    questions[1] = programming2;
    questions[2] = programming3;
    questions[3] = programming4;
    questions[4] = algorithms1;
    questions[5] = algorithms2;
    questions[6] = algorithms3;
    questions[7] = algorithms4;
    questions[8] = databases1;
    questions[9] = databases2;
    questions[10] = databases3;
    questions[11] = databases4;

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    //iterates through the questions array
    for(int i = 0; i < 12; i++){
    
    //if the question is unanswered, print it
    if(questions[i].answered == false){
    
    printf("%s category, %d dollar question.\n", questions[i].category, questions[i].value);
    
    } 
    
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

    //iterates through the array to find the matching question
    for(int i = 0; i < 12; i++){
    
    //if the question matches the above parameters, print question
    if(*questions[i].category == *category && questions[i].value == value){
    
    printf("%s", questions[i].question);
    } 
    
    }
    
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    //iterates through the array to find the matching question
    for(int i = 0; i < 12; i++){
    
    //if the question matches the above parameters, continue
    if(*questions[i].category == *category && questions[i].value == value){
    
    //comparison to see if player's answer matches the correct answer
    int result = strcmp(answer, questions[i].answer);
    
    //if answer matches the question, then set "answered" to true, then return true
    if(result == 0){
    questions[i].answered = true;
    printf("Your answer was correct!\n");
    return true;
    }
    
    } 
    
    }
    //If answer is wrong, return false
    printf("Your answer was incorrect...\n");
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    //iterates through the array to find the matching question
    for(int i = 0; i < 12; i++){
    
    //if the question matches the above parameters, continue
    if(*questions[i].category == *category && questions[i].value == value){
    
    //if matching question is answered, return true
    if(questions[i].answered == true){
    printf("This question was already answered.\n");
    return true;
    }
    
    } 
    
    }

    //if the matching question is not answered, return false
    printf("This question has not been answered yet.\n");
    return false;
}
