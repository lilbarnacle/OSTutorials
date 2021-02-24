/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char *input, char **tokens)
{
char *str

if ((str = strtok(input, "")) != NULL)
	if(strcmp(str,"who") != 0 && strcmp(str, "what") != 0)
		return;

if((str = strtok(NULL, "")) != NULL)
	if(strcmp(str, "is") != 0)
		return;

*tokens = strtok(NULL, "\n");
}

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players)
{
int name = 0;
int score = 0
int winner = 0

for(int i = 0; i < num_players; i++)
{
if((int) strlen(players[i].name > name)
	name = strlen(players[i].name);

	if(players[i].score > score
	{
		score = players[i].score;
		winner = i;
	}
}
printf("Scores: \n");
	for (int i = 0; i < num_players; i++)
		printf("%s: %d\n", name + 1, players[i].name, players[i].score);

printf("Winner is: %s", players[winner].name);

}

#endif /* JEOPARDY_H_ */
