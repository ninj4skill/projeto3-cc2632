# Projeto em C - Lista de contatos

Código feito na linguaguem C para gerenciar uma lista de contatos com funcionalidades para adicionar, deletar e listar os contatos, além de ser capaz de salvar e carregar um arquivo binário com os contatos. Todas as funcionalidades estão em forma de função no código.

# Objetivo

O objetivo do projeto é a crição deum código em C que permita o usuário gerenciar uma lista de contatos, podendo adicionar novos contatos com um limite de 255, deletar um contato de acordo com o telefone de tal contato, listar todos os contatos, salvar os contatos em um arquivo binário e carregar esse arquivo binário que possui os contatos para que haja uma persistência dos dados e eles não sejam apagados apos o desligamento do programa.

# Funcionalidades

Adicionar contato: Adiciona um novo contato à lista de contatos, contanto que o limite de 255 não tenha sida atingido. A criação de um contato consiste no usuário colocando um nome, sobrenome, email e telefone, dados que estarão ligados a esse novo contato.

Deletar contato: Permite o usuário deletar um contato usando o telefone como o identificador. Caso nenhum contato com tal telefone seja encontrado o usuário receberá uma mensagem dizendo que nenhum contato foi encontrado.

Listar contatos: Permite o usuário listar todos os contatos existentes na lista.

Salvar contatos: Permite o usuário salvar os contatos da lista em um arquivo binário contatos.bin para que os dados não sejam perdidos.

Carregar contatos: Permite o suário carregar o arquivo contatos.bin para que os contatos presentes nesse arquivo sejam colocados devolta na lista.

# Compilar e executar

Para compilar e executar o cógigo no codespace é preciso:

1 - Clonar o projeto para o seu computador usando git clone <URL-do-repositorio>

2 - Navegar para o dietório usando cd <nome-do-repositorio>

3 - Compilar o programa usando o compilador gcc

4 - Apos compilador executar o programa usando ./a.out
