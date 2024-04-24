#include <stdio.h>
#include <string.h>
#include "contatos.h"
void Adicionar(Contato contatos[], int *pos){
  if(*pos >= total){
    printf("Limite de contatos atingido\n");
    return;
  }
  printf("Nome: ");
  clearBuffer();
  fgets(contatos[*pos].nome, sizeof(contatos[*pos].nome), stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';
  
  printf("Sobrenome: ");
  fgets(contatos[*pos].sobrenome, 50, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';
  

  printf("Email: ");
  fgets(contatos[*pos].email, 50, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';
  
  printf("Telefone: ");
  scanf("%d", &contatos[*pos].telefone);
  
  clearBuffer();

  *pos = *pos + 1;

  
  
}

void Deletar(Contato contatos[], int *pos){
  int telefonedel;
  printf("Telefone do contato a ser deletado: ");
  scanf("%d", &telefonedel);
  for (int i = 0; i < *pos; i++) {
    if (contatos[i].telefone == telefonedel) {
        strcpy(contatos[i].nome, contatos[i + 1].nome);
        strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
        strcpy(contatos[i].email, contatos[i + 1].email);
        contatos[i].telefone = contatos[i + 1].telefone;
        
      }
    else{
      printf("Contato nao encontrado\n");
    }
  }
  *pos = *pos - 1;
}

void Listar(Contato contatos[], int *pos){
  for (int i = 0; i < *pos; i++){
    printf("Nome: %s\t", contatos[i].nome);
    printf("Sobrenome: %s\t", contatos[i].sobrenome);
    printf("Email: %s\t", contatos[i].email);
    printf("Telefone: %d\n", contatos[i].telefone);
  }
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


