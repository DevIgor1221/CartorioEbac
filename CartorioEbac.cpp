#include <stdio.h> //BIBLIOTECA DE COMUNICAÇÃO COM USUARIO
#include <stdlib.h> //BIBLIOTECA DE ALOCALÇAO DE ESPAÇO E MEMORIA
#include <locale.h> //BIBLIOTECA DE ALOCAÇÃO DE TEXTO POR REGIÃO   
#include <string.h> //BIBLIOTECA RESPONSÁVEL POR CUIDAR DAS STRING 

int registro()//FUNÇÃO RESPONSAVEL POR CADASTRAR OS USURIOS 
{
	//INICIO CRIAÇÃO DE VARIAVEIS/STRING
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//FINAL CRIAÇÃO DE VARIAVEIS/STRING
	
	printf("Digite o CPF: ");// COLETANDO INFORMAÇÕES DO USUÁRIO
	scanf("%s", cpf);//%S REFERE-SE A STRING
	
	strcpy(arquivo, cpf); // RESPONSAVEL POR COPIAR OS VALORES DAS STRING
	
	FILE *file; // CRIA O ARQUIVO
	file = fopen(arquivo, "w"); // CRIA O ARQUIVO E O "W" SIGNIFICA ESCREVER 
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo, "a"); //ABRIR O ARQUIVO E ATUALIZAR "A" SIGNIFICA ATUALIZAR O ARQUIVO
	fprintf(file,","); //PARA SEPARAR AS INFORMAÇÕES
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file= fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado ");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf, "r"); // Ler o arquivo
	
	if(file == NULL)
	{
		printf("Arquivo não encontrado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system ("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	


}



int main()
	{
	int opcao=0; //defenindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //RESPONSAVEL POR LIMPAR A TELA
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //final do menu
		printf("Opção: ");
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); // LIMPAR A TELA
				
		switch(opcao) // INICIO DA SELEÇÃO DO MENU
		{
			case 1:
			registro(); //CHAMADA DE FUNÇÕES
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}//FIM DA SELEÇÃO
		
		
	
	
	

	}	
}
