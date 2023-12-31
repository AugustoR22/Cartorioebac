#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca  de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar ps usu�rios no sistema.
{
	// In�cio da cria��o de vari�veis/string.
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando as informa��es do usu�rio.
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
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
	 
	// In�cio da cria��o de vari�veis/string.
	char cpf[40]; 
	char conteudo[200]; 
	// Final da cria��o de vari�veis/string.
	
	printf("Digite o cpf a ser consultado: "); // Coletando as informa��es do usu�rio.
	scanf("%s",cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa read/ler
	
	if(file == NULL) // se o usu�rio fornecer uma informa��o n�o cadastrada
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // respons�vel por armazenar e fornecer as inform��es do usu�rio a ser consultado
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); // permite que o usu�rio veja as informa��es 
	
}

int deletar()
{
	// In�cio da cria��o de vari�veis/string.
	char cpf[40];
	// Final da cria��o de vari�veis/string.
	
	printf("Digite o cpf do usu�rio a ser deletado: "); // Coletando as informa��es do usu�rio.
	scanf("%s",cpf); // %s refere-se a string
	
	remove(cpf); // respons�vel por remover as informa��es do usu�rio cadastrado
	
	printf("Usu�rio deletado!\n");
	system("pause");
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa read/ler
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao=0; // definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens
	
		printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao) // inicio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta(); // chamada de fun��es
			break; 
			
			case 3:
			deletar(); // chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			system("pause");
			break;	
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} // fim da sele��o
	
  	}
}
