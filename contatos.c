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

void Deletar(Contato contatos[], int *pos){
  int telefonedel;
  printf("Telefone do contato a ser deletado: ");
  scanf("%d", &telefonedel);
  for (int i = 0; i < *pos; i++) {
    if (contatos[i].telefone == telefonedel) {
      for (int x = i; x < *pos - 1; x++) {
        strcpy(contatos[x].nome, contatos[x + 1].nome);
        strcpy(contatos[x].sobrenome, contatos[x + 1].sobrenome);
        strcpy(contatos[x].email, contatos[x + 1].email);
        contatos[x].telefone = contatos[x + 1].telefone;
        }
      }
    else{
      printf("Contato nao encontrado\n");
    }
  }
  *pos = *pos - 1;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


