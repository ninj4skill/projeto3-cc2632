#define totalpessoal 255
#define totaltrabalho 255

typedef struct{
  char nome[50];
  char sobrenome[50];
  char email[50];
  long telefone;
} Contato;

typedef enum{SUCESSO, MAXCONTATOS, SEMCONTATOS, EMAILINVALIDO, JACADASTRADO, NAOENCONTRADO, ABRIR, FECHAR, ESCREVER, LER}erro;
typedef erro (*funcao)(Contato[],Contato[], int*, int*);

erro Adicionar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Alterar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Deletar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Listar(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Salvarpessoal(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Salvartrabalho(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Carregarpessoal(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
erro Carregartrabalho(Contato contatostrabalho[],Contato contatospessoal[], int *pospessoal, int *postrabalho);
void clearBuffer();