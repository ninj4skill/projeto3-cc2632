#include <stdio.h>
#include "contatos.h"

int main() {
  funcao funcionalidades[] = {Adicionar, Deletar, Listar, Carregar, Salvar};
  Contato contatos[total];
  int pos;
  int opcao;
 
  do{
    printf("\t\tMENU\n");
    printf("1. Adicionar contato\n");
    printf("2. Deletar contato\n");
    printf("3. Listar contatos\n");
    printf("4. Carregar contatos\n");
    printf("5. Salvar contatos\n");
    printf("0. Sair\n");
    printf("Insira a opcao desejada: ");
    scanf("%d", &opcao);
    if(opcao > 5){
      printf("Opção inválida\n");
    }
    else if (opcao > 0){
      funcionalidades[opcao - 1](contatos, &pos);
    }
    else {
      printf("Saindo...\n");
      
    }
  } while(opcao != 0);
  
}