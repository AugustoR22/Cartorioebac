#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca  de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar ps usuários no sistema.
{
	// Início da criação de variáveis/string.
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string.
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando as informações do usuário.
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,","); // coloca "," para seperar os dados cadastrados
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado; ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado; ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	 
	// Início da criação de variáveis/string.
	char cpf[40]; 
	char conteudo[200]; 
	// Final da criação de variáveis/string.
	
	printf("Digite o cpf a ser consultado: "); // Coletando as informações do usuário.
	scanf("%s",cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa read/ler
	
	if(file == NULL) // se o usuário fornecer uma informação não cadastrada
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // responsável por armazenar e fornecer as informções do usuário a ser consultado
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); // permite que o usuário veja as informações 
	
}

int deletar()
{
	// Início da criação de variáveis/string.
	char cpf[40];
	// Final da criação de variáveis/string.
	
	printf("Digite o cpf do usuário a ser deletado: "); // Coletando as informações do usuário.
	scanf("%s",cpf); // %s refere-se a string
	
	remove(cpf); // responsável por remover as informações do usuário cadastrado
	
	printf("Usuário deletado!\n");
	system("pause");
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa read/ler
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	
		printf("### Cartório da EBAC ### \n\n"); //início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao) // inicio da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta(); // chamada de funções
			break; 
			
			case 3:
			deletar(); // chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} // fim da seleção
	
  	}
}
