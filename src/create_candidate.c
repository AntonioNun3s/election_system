#include "../headers/create_candidate.h"
#include <stdio.h>
#include <stdlib.h>

void create_candidate(char* candidate, int number){
    FILE *EditFile = fopen("bin/candidates.bin", "rb+");

    if(EditFile == NULL){
        puts("nao foi possivel abrir o arquivo de votos. erro em criar um candidato");
        exit(1);
    }

    fseek(EditFile, 0, SEEK_END);

    fwrite(candidate, sizeof(char), 20, EditFile);

    fseek(EditFile, 2, SEEK_CUR);

    fwrite(&number, sizeof(int), 1, EditFile);

    fseek(EditFile, 2, SEEK_CUR);

    int starting_vote = 0;
    fwrite(&starting_vote, sizeof(int), 1, EditFile);

    fclose(EditFile);
}