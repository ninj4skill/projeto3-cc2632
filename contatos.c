#include <stdio.h>
#include <string.h>
#include "contatos.h"
erro Adicionar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho){
  int tipo;
  printf("Qual o tipo de contato que deseja?\n 1- Pessoal\n 2- Trabalho\n");
  printf("Tipo: ");
  scanf("%d", &tipo);
  if (tipo == 1){
    if (*pospessoal >= totalpessoal){
      printf("Limite de contatos pessoais atingido");
      return MAXCONTATOS;
    }
    else{
      printf("Nome: ");
      clearBuffer();
      fgets(contatospessoal[*pospessoal].nome, 50, stdin);

contatospessoal[*pospessoal].nome[strcspn(contatospessoal[*pospessoal].nome, "\n")] = '\0';
      
      printf("Sobrenome: ");
      fgets(contatospessoal[*pospessoal].sobrenome, 50, stdin);
      contatospessoal[*pospessoal].sobrenome[strcspn(contatospessoal[*pospessoal].sobrenome,"\n")] = '\0';

      printf("Email: ");
      fgets(contatospessoal[*pospessoal].email, 50, stdin);
      contatospessoal[*pospessoal].email[strcspn(contatospessoal[*pospessoal].email, "\n")] = '\0';

      int validararroba = -1;
      for (int i = 0; i < strlen(contatospessoal[*pospessoal].email); i++){
        if(contatospessoal[*pospessoal].email[i] == '@'){
          validararroba = i;
          break;
        }
      }
      int validarponto = -1;
      if (validararroba != -1){
         for (int i = validararroba + 1; i < strlen(contatospessoal[*pospessoal].email); i++){
           if(contatospessoal[*pospessoal].email[i] =='.'){
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
      scanf("%ld",&contatospessoal[*pospessoal].telefone);
      clearBuffer();
      for (int i = 0; i < *pospessoal; i++){
        if (contatospessoal[*pospessoal].telefone == contatospessoal[i].telefone){
          printf("Telefone já cadastrado\n");
          return JACADASTRADO;
        }
      }
      *pospessoal = *pospessoal + 1;
    }
  }
  else{
    if (*postrabalho >= totaltrabalho){
      printf("Limite de contatos profissionais atingido");
      return MAXCONTATOS;
    }
    else{
      printf("Nome: ");
      clearBuffer();
      fgets(contatostrabalho[*postrabalho].nome, 50, stdin);

contatostrabalho[*postrabalho].nome[strcspn(contatostrabalho[*postrabalho].nome, "\n")] = '\0';

      printf("Sobrenome: ");
      fgets(contatostrabalho[*postrabalho].sobrenome, 50, stdin);
      contatostrabalho[*postrabalho].sobrenome[strcspn(contatostrabalho[*postrabalho].sobrenome,"\n")] = '\0';
   
      printf("Email: ");
      fgets(contatostrabalho[*postrabalho].email, 50, stdin);
      contatostrabalho[*postrabalho].email[strcspn(contatostrabalho[*postrabalho].email, "\n")] = '\0';

      int validararroba = 0;
      for (int i = 0; i < strlen(contatostrabalho[*postrabalho].email); i++){
        if(contatostrabalho[*postrabalho].email[i] == '@'){
          validararroba = i;
          break;
         }
      }
      int validarponto = 0;
      if (validararroba != 0){
        for (int i = validararroba + 1; i < strlen(contatostrabalho[*postrabalho].email); i++){
          if(contatostrabalho[*postrabalho].email[i] == '.'){
            validarponto = i;
            break;
            }
        }
     }
      if (validararroba == 0 || validarponto == 0){
        printf("Email inválido\n");
        return EMAILINVALIDO;
    }
      printf("Telefone: ");
      scanf("%ld",
        &contatostrabalho[*postrabalho].telefone);
      clearBuffer();
      for (int i = 0; i < *postrabalho; i++){
        if (contatostrabalho[*postrabalho].telefone == contatostrabalho[i].telefone){
          printf("Telefone já cadastrado\n");
          return JACADASTRADO;
      }
    }
      *postrabalho = *postrabalho + 1;
    }
  }
  return SUCESSO;
}

erro Alterar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho){
  if (*pospessoal == 0 && *postrabalho == 0){
    printf("Sem contatos para alterar\n");
    return SEMCONTATOS;
  }
  long telefonealterar;
  printf("Insira o telefone do contato que deseja alterar: ");
  scanf("%ld", &telefonealterar);
  int alterar = 0;
  for (int i = 0; i < *pospessoal; i++){
    if (contatospessoal[i].telefone == telefonealterar){
      printf("Novo nome: ");
      clearBuffer();
      fgets(contatospessoal[*pospessoal].nome, sizeof(contatospessoal[*pospessoal].nome), stdin);
      
contatospessoal[*pospessoal].nome[strcspn(contatospessoal[*pospessoal].nome, "\n")] = '\0';
      strcpy(contatospessoal[i].nome, contatospessoal[*pospessoal].nome);
      printf("Novo sobrenome: ");
      fgets(contatospessoal[*pospessoal].sobrenome, 50, stdin);
      contatospessoal[*pospessoal].sobrenome[strcspn(contatospessoal[*pospessoal].sobrenome,"\n")] = '\0';
      strcpy(contatospessoal[i].sobrenome, contatospessoal[*pospessoal].sobrenome);
      printf("Novo email: ");
      fgets(contatospessoal[*pospessoal].email, 50, stdin);
      
contatospessoal[*pospessoal].email[strcspn(contatospessoal[*pospessoal].email, "\n")] = '\0';
      int validararroba = 0;
      for (int i = 0; i < strlen(contatospessoal[*pospessoal].email); i++){
        if(contatospessoal[*pospessoal].email[i] == '@'){
          validararroba = i;
          break;
        }
      }
      int validarponto = 0;
      if (validararroba != 0){
         for (int i = validararroba + 1; i < strlen(contatospessoal[*pospessoal].email); i++){
           if(contatospessoal[*pospessoal].email[i] == '.'){
             validarponto = i;
             break;
           }
         }
      }
      if (validararroba == 0 || validarponto == 0){
        printf("Email inválido\n");
        return EMAILINVALIDO;
      }
      strcpy(contatospessoal[i].email, contatospessoal[*pospessoal].email);

      printf("Novo telefone: ");
      scanf("%ld", &contatospessoal[*pospessoal].telefone);
      clearBuffer();
      for (int j = 0; j < *pospessoal; j++){
        if (contatospessoal[*pospessoal].telefone == contatospessoal[j].telefone){
          printf("Telefone já cadastrado\n");
          return JACADASTRADO;
        }
      }
        contatospessoal[i].telefone = contatospessoal[*pospessoal].telefone;
      alterar = 1;
    }
  }
  for (int i = 0; i < *postrabalho; i++){
    if (contatostrabalho[i].telefone == telefonealterar){
      printf("Novo nome: ");
      clearBuffer();
      fgets(contatostrabalho[*postrabalho].nome, sizeof(contatostrabalho[*postrabalho].nome), stdin);
        contatostrabalho[*postrabalho].nome[strcspn(contatostrabalho[*postrabalho].nome, "\n")] = '\0';
      
      strcpy(contatostrabalho[i].nome, contatostrabalho[*postrabalho].nome);
      printf("Novo sobrenome: ");
      fgets(contatostrabalho[*postrabalho].sobrenome, 50, stdin);
      contatostrabalho[*postrabalho].sobrenome[strcspn(contatostrabalho[*postrabalho].sobrenome,"\n")] = '\0';
      
      strcpy(contatostrabalho[i].sobrenome, contatostrabalho[*postrabalho].sobrenome);
      printf("Novo email: ");
      fgets(contatostrabalho[*postrabalho].email, 50, stdin);
        contatostrabalho[*postrabalho].email[strcspn(contatostrabalho[*postrabalho].email, "\n")] = '\0';
      
      int validararroba = 0;
      for (int i = 0; i < strlen(contatostrabalho[*postrabalho].email); i++){
        if(contatostrabalho[*postrabalho].email[i] == '@'){
          validararroba = i;
          break;
        }
      }
      int validarponto = 0;
      if (validararroba != 0){
         for (int i = validararroba + 1; i < strlen(contatostrabalho[*postrabalho].email); i++){
           if(contatostrabalho[*postrabalho].email[i] ==
             '.'){
             validarponto = i;
             break;
           }
         }
      }
      if (validararroba == 0 || validarponto == 0){
        printf("Email inválido\n");
        return EMAILINVALIDO;
      }
      strcpy(contatostrabalho[i].email, contatostrabalho[*postrabalho].email);

      printf("Novo telefone: ");
      scanf("%ld", &contatostrabalho[*postrabalho].telefone);
      clearBuffer();
      for (int j = 0; j < *postrabalho; j++){
        if (contatostrabalho[*postrabalho].telefone == contatostrabalho[j].telefone){
          printf("Telefone já cadastrado\n");
          return JACADASTRADO;
        }
      }
        contatostrabalho[i].telefone = contatostrabalho[*postrabalho].telefone;
      alterar = 1;
    }
  }
  if (alterar == 0){
    printf("Contato não encontrado\n");
    return NAOENCONTRADO;
  }
  return SUCESSO;
}

erro Deletar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho){
  if (*pospessoal == 0 && *postrabalho == 0){
    printf("Sem contatos para deletar\n");
    return SEMCONTATOS;
  }
  long telefonedel;
  printf("Telefone do contato a ser deletado: ");
  scanf("%ld", &telefonedel);
  int deletar = 0;
  for (int i = 0; i < *pospessoal; i++) {
    if (contatospessoal[i].telefone == telefonedel) {
      strcpy(contatospessoal[i].nome, contatospessoal[i + 1].nome);
      strcpy(contatospessoal[i].sobrenome, contatospessoal[i + 1].sobrenome);
      strcpy(contatospessoal[i].email, contatospessoal[i + 1].email);
      contatospessoal[i].telefone = contatospessoal[i + 1].telefone;
      deletar = 1;
      }
  }
  for (int i = 0; i < *postrabalho; i++){
    if (contatostrabalho[i].telefone == telefonedel){
      strcpy(contatostrabalho[i].nome, contatostrabalho[i + 1].nome);
      strcpy(contatostrabalho[i].sobrenome, contatostrabalho[i + 1].sobrenome);
      strcpy(contatostrabalho[i].email, contatostrabalho[i + 1].email);
      contatostrabalho[i].telefone = contatostrabalho[i + 1].telefone;
      deletar = 2;
    }
  }
  if (deletar == 0){
    printf("Contato não encontrado\n");
    return NAOENCONTRADO;
  }
  else if (deletar == 1)
    *pospessoal = *pospessoal - 1;
  else
    *postrabalho = *postrabalho - 1;
  
  return SUCESSO;
}

erro Listar(Contato contatostrabalho[],Contato contatospessoal[],int *pospessoal, int *postrabalho){
  if (*pospessoal == 0 && *postrabalho == 0){
    printf("Sem contatos para listar\n");
    return SEMCONTATOS;
  }
  for (int i = 0; i < *pospessoal; i++){
    printf("Tipo: Pessoal\t");
    printf("Nome: %s\t", contatospessoal[i].nome);
    printf("Sobrenome: %s\t",
      contatospessoal[i].sobrenome);
    printf("Email: %s\t", contatospessoal[i].email);
    printf("Telefone: %ld\n",contatospessoal[i].telefone);
  }
  for (int i = 0; i < *postrabalho; i++){
    printf("Tipo: Trabalho\t");
    printf("Nome: %s\t", contatostrabalho[i].nome);
    printf("Sobrenome: %s\t",
      contatostrabalho[i].sobrenome);
    printf("Email: %s\t", contatostrabalho[i].email);
    printf("Telefone: %ld\n",contatostrabalho[i].telefone);
  }
  return SUCESSO;
}

erro Carregarpessoal(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho) {
  FILE *f = fopen("contatospessoal.bin", "rb");
  if (f == NULL){
    printf("Erro ao abrir arquivo.\n");
    return ABRIR;
  }
  int carregarpessoal = fread(contatospessoal, totalpessoal, sizeof(Contato), f);
  
  if(carregarpessoal == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }
  carregarpessoal = fread(pospessoal, sizeof(int), 1, f);
  if(carregarpessoal == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }

  if (fclose(f)) {
      return FECHAR;
  }

  return SUCESSO;
}

erro Carregartrabalho(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho) {
  FILE *f = fopen("contatostrabalho.bin", "rb");
  if (f == NULL){
    printf("Erro ao abrir arquivo.\n");
    return ABRIR;
  }
  int carregartrabalho = fread(contatostrabalho, totaltrabalho, sizeof(Contato), f);

  if(carregartrabalho == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }
  carregartrabalho = fread(postrabalho, sizeof(int), 1, f);
  if(carregartrabalho == 0){
    printf("Erro ao ler arquivo\n");
    return LER;
  }

  if (fclose(f)) {
      return FECHAR;
  }

  return SUCESSO;
}

erro Salvarpessoal(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho) {
  FILE *f = fopen("contatospessoal.bin", "wb");
  if (f == NULL){
    printf("Erro ao abrir arquivo");
    return ABRIR;
  }
  int salvarpessoal = fwrite(contatospessoal, totalpessoal, sizeof(Contato), f);
  if (salvarpessoal == 0){
    printf("Erro ao escrever no arquivo\n");
    return LER;
  }
  salvarpessoal = fwrite(pospessoal, sizeof(int), 1, f);
  if (salvarpessoal == 0){
    printf("Erro ao escrever no arquivo\n");
    return LER;
  }

  if(fclose(f)){
    return FECHAR;
  }
  return SUCESSO;
}

erro Salvartrabalho(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho) {
  FILE *f = fopen("contatostrabalho.bin", "wb");
  if (f == NULL){
    printf("Erro ao abrir arquivo");
    return ABRIR;
  }
  int salvartrabalho = fwrite(contatostrabalho, totaltrabalho, sizeof(Contato), f);
  if(salvartrabalho == 0){
    printf("Erro ao escrever no arquivo\n");
    return LER;
  }
  salvartrabalho = fwrite(postrabalho, sizeof(int), 1, f);
  if(salvartrabalho == 0){
    printf("Erro ao escrever no arquivo\n");
    return LER;
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