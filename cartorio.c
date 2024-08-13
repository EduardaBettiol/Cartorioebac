#include <stdio.h> //biblioteca de comunical�ao com o usu�rio 
#include <stdlib.h>// biblioteca de aluca��o de espa�o en mem�ria
#include <locale.h> //biblioteca de aloca��o de testo por regi�o
#include <string.h> //biblioteca respon�vel por cuidar da string


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o dos usu�rios
	scanf("%s", cpf);//%s refere-se a string pra salvar dentro da string, salva o valor da vari�vel na string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file, "\t CPF: ");//mostrar a mensagem antes de aparecer o cpf gravado do usu�rio, pra arrumar as informa��es do usu�rio na hora de consultar
	fprintf(file,cpf); //salva o valor da vari�vel no arquivo
	fclose(file); //fecha o arquivo
	
	//inserir a mensagem pras informa��es do usu�rio n�o ficarem grudadas 
	file = fopen (arquivo, "a");//abre o arquivo pra atualizar a informa��o "a"
	fprintf(file, ",\n \t NOME: ");//mostra essa mensagem depois do CPF
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coleta a informa��o do usu�rio
	scanf("%s", nome);//salva o valor digitado na vari�vel/string
	
	file = fopen(arquivo, "a");//abre o arquivo pra ataulizar
	fprintf(file,nome);//salva o conte�do da vari�vel "nome" dentro do arquivo
	fclose(file);//fecha o arquivo
	
	//Arrumando as informa��es do usu�rio
	file = fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file,",\n \t SOBRENOME: ");//mostra essa mensagem depois do nome
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta a informa��o "sobrenome" do usu�rio
	scanf("%s", sobrenome);//salva na string
	
	file = fopen(arquivo, "a");//abre o arquio pra atualizar
	fprintf(file, sobrenome);//salva a vari�el "sobrenome" dentro do arquivo
	fclose(file);//fecha o arquivo 
	
	//Arrumando as informa��es do usu�rio
	file =fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file, ",\n \t CARGO: ");//mostra essa mensagem depois do sobrenome
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informa��o do usu�rio
	scanf("%s", cargo);//salva na vari�vel/string
	
	file = fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file,cargo);//coloca as informa��es, que � o cargo, dentro do arquivo
	fprintf(file, ".\n\n");//espa�o pra ficar visualmente mais agrad�vel
	fclose(file);//fecha o arquivo
	
	system("pause");//pause pra conseguir visualizar
}

int consulta()//Fun��o respons�vel por consultar os usu�rios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40];//criando o arquivo cpf novamente pra poder consultar os valores
	char conteudo[200];//armazenando esses valores na vari�vel pra trazer os dados do cpf pra n�s
	
	printf("Digite o CPF a ser consultado: ");//Coletando a informa��o do cpf que vai ser consultado
	scanf("%s", cpf);//salva a inform��o dentro da string cpf
	
	FILE *file;//acessar a parte do arquivo
	file = fopen(cpf, "r");//abrir o arquivo cpf e ler esse arquivo, r de ready
	
		if(file == NULL)//Se o valor do cpf digitado for nulo aparece a mensagem:
		{
			printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
		}
	
		printf("Essas s�o as informa��es do usu�rio: \n\n");
		
		while(fgets(conteudo, 200, file)!= NULL)//Fun��o pra salvar dentro da vair�vel conte�do os 200 caracteres que est�o dentro do arquivo, com um la�o de repeti��o "while"
		{
			printf("%s", conteudo);
		}
	
		system("pause");//pause pra conseguir visualizar
	
}

int deletar()//Fun��o respons�vel por deletar os dados dos usu�rios
{
	char cpf[40];//criando o arquivo cpf novamente pra poder consultar os valores
	
	printf("Digite o CPF do usu�rio a ser deletado: \n\n\t");//coletando a informa��o do cpf que vai ser deletado
	scanf("%s", cpf);//salva na string o cpf digitado
	
	remove(cpf);//exclui o cpf
	
	FILE *file;//acessa o arquivo
	file = fopen(cpf,"r");//abre o arquivo cpf e le esse arquivo
	
	if(file == NULL)//caso o arquivo for nulo, n�o existir, aparece a mensagen:
	{
		printf("\nO usu�rio n�o se encontra no sistema!. \n\n");
		system("pause");//pause pra conseguir visualizar a mensagem
	}
	else//Se o cpf foi encontrado e j� foi deletado aparece a mensagem:
	{
		printf("\nO usu�rio j� foi deletado do sistema!. \n\n");
		system("pause");//pause pra conseguir visualizar a mensagem
	}
}

int main()//Fun��o principal
{
	int opcao=0; //Definindo vari�veis 
	
	int laco=1;//cria a vari�vel pra chamar o "for"
	for(laco=1;laco=1;)//Volta pra tela do menu sem encerrar o programa
	{
		
		
		system("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
		
		printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		system("cls");
		
				switch(opcao)
			{
				 //Inicio da sele��o do menu
		
			case 1:
				registro();//chamada de fun��es
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
			
			default:
				printf ("Essa op��o n�o est� dispon�vel\n");
				system("pause");
				break; //Fim da sele��o
			}
	
	}
}
