#include <stdio.h>
#include <string.h>
#include "contatos.h"
erro Adicionar(Contato contatos[], int *pos){
  if(*pos >= total){
    printf("Limite de contatos atingido\n");
    return MAXCONTATOS;
  }
  printf("Nome: ");
  clearBuffer();
  fgets(contatos[*pos].nome, sizeof(contatos[*pos].nome), stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

  printf("Sobrenome: ");
  fgets(contatos[*pos].sobrenome, 50, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome,"\n")] = '\0';

  printf("Email: ");
  fgets(contatos[*pos].email, 50, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

  int validararroba = -1;
  for (int i = 0; i < strlen(contatos[*pos].email); i++){
    if(contatos[*pos].email[i] == '@'){
      validararroba = i;
      break;
    }
  }
  int validarponto = -1;
  if (validararroba != -1){
     for (int i = validararroba + 1; i < strlen(contatos[*pos].email); i++){
       if(contatos[*pos].email[i] == '.'){
         validarponto = i;
         break;
       }
     }
  }
  if (validararroba == -1 || validarponto == -1){
    printf("Email inválido\n");
    return EMAILINVALIDO;
  }

  printf("Telefone: ");
  scanf("%ld", &contatos[*pos].telefone);
  clearBuffer();
  
   for (int i = 0; i < *pos; i++){
    if (contatos[*pos].telefone == contatos[i].telefone){
      printf("Telefone já cadastrado\n");
      return JACADASTRADO;
    }
  }

  *pos = *pos + 1;
  return SUCESSO;
}

erro Deletar(Contato contatos[], int *pos){
  if(*pos == 0){
    printf("Sem contatos para deletar\n");
    return SEMCONTATOS;
  }
  long telefonedel;
  printf("Telefone do contato a ser deletado: ");
  scanf("%ld", &telefonedel);
  int deletar = 0;
  for (int i = 0; i < *pos; i++) {
    if (contatos[i].telefone == telefonedel) {
      strcpy(contatos[i].nome, contatos[i + 1].nome);
      strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
      strcpy(contatos[i].email, contatos[i + 1].email);
      contatos[i].telefone = contatos[i + 1].telefone;
      deletar = 1;
      }
  }
  if (deletar == 0){
    printf("Contato não encontrado\n");
    return NAOENCONTRADO;
  }
  *pos = *pos - 1;
  return SUCESSO;
}

erro Listar(Contato contatos[], int *pos){
  if(*pos == 0){
    printf("Sem contatos para listar\n");
    return SEMCONTATOS;
  }
  for (int i = 0; i < *pos; i++){
    printf("Nome: %s\t", contatos[i].nome);
    printf("Sobrenome: %s\t", contatos[i].sobrenome);
    printf("Email: %s\t", contatos[i].email);
    printf("Telefone: %ld\n", contatos[i].telefone);
  }
  return SUCESSO;
}

erro Carregar(Contato contatos[], int *pos) {
  FILE *f = fopen("contatos.bin", "rb");
  if (f == NULL){
    printf("Erro ao abrir arquivo.\n");
    return ABRIR;
  }
  int carregar = fread(contatos, total, sizeof(Contato), f);
  if(carregar == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }
  carregar = fread(pos,1,sizeof(int),f);
  if(carregar == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }
  if(fclose(f)){
    return FECHAR;
  }
  return SUCESSO;
}

erro Salvar(Contato contatos[], int *pos) {
  FILE *f = fopen("contatos.bin", "wb");
  if (f == NULL){
    printf("Erro ao abrir arquivo");
    return ABRIR;
  }
  int salvar = fwrite(contatos, total, sizeof(Contato), f);
  if(salvar == 0){
    printf("Erro ao escrever no arquivo");
    return ESCREVER;
  }
  salvar = fwrite(pos,1,sizeof(int),f);
  if(salvar == 0){
    printf("Erro ao escrever no arquivo");
    return ESCREVER;
  }
  if(fclose(f)){
    return FECHAR;
  }
  return SUCESSO;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}