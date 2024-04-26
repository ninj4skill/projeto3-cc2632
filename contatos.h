#define total 255

typedef struct{
  char nome[50];
  char sobrenome[50];
  char email[50];
  long telefone;
} Contato;
typedef enum{SUCESSO, MAXCONTATOS, SEMCONTATOS, NAOENCONTRADO, ABRIR, FECHAR, ESCREVER, LER}erro;
typedef erro (*funcao)(Contato[], int*);

erro Adicionar(Contato contatos[], int *pos);
erro Deletar(Contato contatos[], int *pos);
erro Listar(Contato contatos[], int *pos);
erro Salvar(Contato contatos[], int *pos);
erro Carregar(Contato contatos[], int *pos);
void clearBuffer();