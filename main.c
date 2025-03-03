#include "headers/create_candidate.h"
#include "headers/reveal_winner.h"
#include "headers/get_vote.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *mostrar_candidatos = fopen("bin/candidates.bin", "rb");

    if(mostrar_candidatos == NULL){
        puts("nao foi possivel abrir o arquivo de votos");
        return 1;
    }

    int end_of_file;
    char mostrar_nome[20];
    int mostrar_numero;
    char candidato[20];
    char* vencedor;
    int numero = 0;
    int escolha = 2;
    int voto = 0;

    while(escolha){

        puts("pressione 1 para criar um candidato");
        puts("pressione 2 para votar");
        puts("pressione 3 para encerrar a votacao e mostrar os resultados");
        puts("pressione 0 para fechar o programa");

        scanf("%d", &escolha);

        switch(escolha){
            case 0:
            return 0;
            break;

            case 1:
            puts("insira o nome do candidato, aperte enter e depois insira o numero de seu partido");

            scanf("%s", candidato);
            scanf("%d", &numero);
            create_candidate(candidato, numero);

            system("cls");
            break;

            case 2:
            puts("escolha o numero de seu candidato");
            fseek(mostrar_candidatos, 0, SEEK_SET);

            while(end_of_file = fgetc(mostrar_candidatos) != EOF){

                fseek(mostrar_candidatos, -1, SEEK_CUR);
                fread(&mostrar_nome, sizeof(char), 20, mostrar_candidatos);

                fseek(mostrar_candidatos, 2, SEEK_CUR);
                fread(&mostrar_numero, sizeof(int), 1, mostrar_candidatos);

                fseek(mostrar_candidatos, 6, SEEK_CUR);
                printf("%s - %d\n", mostrar_nome, mostrar_numero);
            }

            scanf("%d", &voto);
            get_vote(voto);
            
            system("pause");
            system("cls");
            break;

            case 3:
            vencedor = reveal_winner();
            puts("o vencedor da eleicao eh");
            printf("%s\n", vencedor);
            escolha = 0;
            break;

            default:
            puts("insira uma das opcoes acima");
            break;
        }
    }
    fclose(mostrar_candidatos);
    getchar();
    puts("pressione qualquer tecla para fechar o programa");
    getchar();
    return 0;
}