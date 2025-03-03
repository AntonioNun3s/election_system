#include "../headers/get_vote.h"
#include <stdio.h>
#include <stdlib.h>

void get_vote(int vote){
    int check_vote = 0;
    int increment_vote = 0;
    int end_of_file;

    FILE* search_vote = fopen("bin/candidates.bin", "rb+");

    if(search_vote == NULL){
        puts("nao foi possivel abrir o arquivo de votos. erro em adicionar o voto");
        exit(1);
    }
    while(1){
        fseek(search_vote, 22, SEEK_CUR);
        fread(&check_vote, sizeof(int), 1, search_vote);
        if(check_vote == vote){
            fseek(search_vote, 2, SEEK_CUR);
            fread(&increment_vote, sizeof(int), 1, search_vote);
            break;
        }
        if(end_of_file = fgetc(search_vote) == EOF){
            puts("voto invalido");
            return;
        }
        fseek(search_vote, 5, SEEK_CUR);
    }
        puts("voto registrado com sucesso");
        
    increment_vote++;
    fseek(search_vote, -4, SEEK_CUR);
    fwrite(&increment_vote, sizeof(int), 1, search_vote);

    fclose(search_vote);
}