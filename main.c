#include <stdio.h>
#include "contatos.h"

int main() {
  //funcao funcionalidades[] = {Adicionar, Deletar, Listar, Salvar, Carregar};
  Contato contatos[total];
  int pos;
  int opcao;
  Carregar(contatos, &pos);
  
  do{
    printf("\t\tMENU\n");
    printf("1. Adicionar contato\n");
    printf("2. Deletar contato\n");
    printf("3. Listar contatos\n");
    printf("0. Sair\n");
    printf("Insira a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1){
      Adicionar(contatos, &pos);
    }
    else if (opcao == 2){
      Deletar(contatos, &pos);
    }
    else if (opcao == 3){
      Listar(contatos, &pos);
    }
    else if (opcao == 0){
      printf("Saindo...\n");
      Salvar(contatos, &pos);
    }
  } while(opcao != 0);
  
}