#include "../headers/reveal_winner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reveal_winner(){

    FILE* openFile = fopen("bin/candidates.bin", "rb");

    if(openFile == NULL){
        puts("nao foi possivel abrir o arquivo de votos. erro em revelar o vencedor");
        exit(1);
    }

    int end_of_file;
    int biggest_vote = 0;
    int temp_vote = 0;
    char quantity_of_votes[5];
    char* winner = malloc(sizeof(char) * 36);

    while(end_of_file = fgetc(openFile) != EOF){
        fseek(openFile, 27, SEEK_CUR);
        fread(&temp_vote, sizeof(int), 1, openFile);
        if(temp_vote > biggest_vote){
            biggest_vote = temp_vote;
        }

    }
    fseek(openFile, 0, SEEK_SET);
    while(1){
        fseek(openFile, 28, SEEK_CUR);
        fread(&temp_vote, sizeof(int), 1, openFile);
        if(temp_vote == biggest_vote){
            fseek(openFile, -32, SEEK_CUR);
            fread(winner, sizeof(char), 20, openFile);
            break;
        }
    }
    fclose(openFile);

    FILE* delete_content = fopen("bin/candidates.bin", "wb");

    if(openFile == NULL){
        puts("nao foi possivel abrir o arquivo de votos");
        exit(1);
    }

    fclose(delete_content);

    sprintf(quantity_of_votes, "%d", biggest_vote);

    strcat(winner, " com ");
    strcat(winner, quantity_of_votes);
    strcat(winner, " votos");

    return winner;
}