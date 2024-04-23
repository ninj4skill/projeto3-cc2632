#include <stdio.h>
#include "contatos.h"

int main() {
  Contato contatos[total];
  int pos;
  int opcao;
  
  do{
    printf("1. Adicionar contato\n");
    printf("2. Deletar contato\n");
    printf("3. Listar contatos\n");
    printf("0. Sair\n");
    printf("Insira a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1){
      Adicionar(contatos, &pos);
    }
    if(opcao == 2){
        Deletar(contatos,&pos);
    }
  } while(opcao != 0);
  
}