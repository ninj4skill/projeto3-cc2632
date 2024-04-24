#define total 255

typedef struct{
  char nome[50];
  char sobrenome[50];
  char email[50];
  int telefone;
} Contato;

typedef void (*funcao)(Contato[], int*);

void Adicionar(Contato contatos[], int *pos);
void Deletar(Contato contatos[], int *pos);
void Listar(Contato contatos[], int *pos);
void Salvar(Contato contatos[], int *pos);
void Carregar(Contato contatos[], int *pos);

void clearBuffer();