#include <stdio.h>
#include "contatos.h"

int main() {
  funcao funcionalidades[] = {Adicionar, Alterar, Deletar, Listar, Carregarpessoal, Salvarpessoal, Carregartrabalho, Salvartrabalho};
  Contato contatospessoal[totalpessoal];
  Contato contatostrabalho[totaltrabalho];
  int pospessoal;
  int postrabalho;
  int opcao;

  do{
    printf("\t\tMENU\n");
    printf("1. Adicionar contato\n");
    printf("2. Alterar contato\n");
    printf("3. Deletar contato\n");
    printf("4. Listar contatos\n");
    printf("5. Carregar contatos\n");
    printf("6. Salvar contatos\n");
    printf("0. Sair\n");
    printf("Insira a opcao desejada: ");
    scanf("%d", &opcao);
    if(opcao > 6){
      printf("Opção inválida\n");
    }
    else if (opcao > 0 && opcao < 5){
      funcionalidades[opcao - 1](contatostrabalho, contatospessoal, &pospessoal, &postrabalho);
    }
    else if (opcao == 5){
      funcionalidades[4](contatostrabalho, contatospessoal, &pospessoal, &postrabalho);
      funcionalidades[6](contatostrabalho, contatospessoal, &pospessoal, &postrabalho);
    }
    else if (opcao == 6){
      funcionalidades[5](contatostrabalho, contatospessoal, &pospessoal, &postrabalho);
      funcionalidades[7](contatostrabalho, contatospessoal, &pospessoal, &postrabalho);
    }
    else {
      printf("Saindo...\n");

    }
  } while(opcao != 0);

}