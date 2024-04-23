#include <stdio.h>
#include <string.h>
#include "contatos.h"

void Adicionar(Contato contatos[], int *pos){
  if(*pos >= total){
    printf("Limite de contatos atingido\n");
    return;
  }
  printf("Nome: ");
  fgets(contatos[*pos].nome, 50, stdin);
  clearBuffer();
  printf("Sobrenome: ");
  fgets(contatos[*pos].sobrenome, 50, stdin);
  printf("Email: ");
  fgets(contatos[*pos].email, 50, stdin);
  printf("Telefone: ");
  scanf("%d", &contatos[*pos].telefone);
  *pos = *pos + 1;
  
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


