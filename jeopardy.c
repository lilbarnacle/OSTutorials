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
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
int counter = 0;
char answer [100];
int value = 0;
char category [100];
// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
    printf("Please enter name of player" + i + ": ");
    scanf("%s", players[i]);
    }
    // initialize each of the players in the array
    //players are initialized in the for loop
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
	system("clear");

	char current_player[100] = "";
	char current_category[100] = "";
	int current value = 0;
	while(!player_exists(players, NUM_PLAYERS, current_player)
	{
	if(strcmp(current_player, "") != 0)
		printf("Player does not exist");

	printf("enter name of player that is choosing: ");
	scanf("%s", (char *) &current_player);
	}

	do {
	if(current_value != 0)
		printf("Invalid");
	printf("Please enter the category: ");
	getchar();
	fgets((char *) current_category, MAX_LEN, stdin);
	strtok(selected_category, "\n");
	printf("Please enter the value: ");
	scanf("%d", (int *) &current_value);
	} while(already_answered(current_category, current_value));
        // Execute the game until all questions are answered
	system("clear");
	display_question(current_category, current_value);
	getchar();
	fgets((char *) buffer, MAX_LEN, stdin);

	char *tokenize_answer;
	tokenize((char *) buffer, &tokenize_answer);

	if(valid_answer(current_category, current_value, tokenize_answer))
		update_score(current_player, current_valye);
	else
		printf("Incorrect");
        // Display the final results and exit
	if(all questions have been answered)
	{
		show_results(players, NUM_PLAYERS);
		break;
		//There is no function for this, so i dont know how to do it
		//I wanted to call display_categories, and if nothing showed then end the game
		//but i cant do that, so i left it like this
	}
    }
    return EXIT_SUCCESS;
}
