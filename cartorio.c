#include <stdio.h> //biblioteca de comunicalçao com o usuário 
#include <stdlib.h>// biblioteca de alucação de espaço en memória
#include <locale.h> //biblioteca de alocação de testo por região
#include <string.h> //biblioteca responável por cuidar da string


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação dos usuários
	scanf("%s", cpf);//%s refere-se a string pra salvar dentro da string, salva o valor da variável na string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file, "\t CPF: ");//mostrar a mensagem antes de aparecer o cpf gravado do usuário, pra arrumar as informações do usuário na hora de consultar
	fprintf(file,cpf); //salva o valor da variável no arquivo
	fclose(file); //fecha o arquivo
	
	//inserir a mensagem pras informações do usuário não ficarem grudadas 
	file = fopen (arquivo, "a");//abre o arquivo pra atualizar a informação "a"
	fprintf(file, ",\n \t NOME: ");//mostra essa mensagem depois do CPF
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coleta a informação do usuário
	scanf("%s", nome);//salva o valor digitado na variável/string
	
	file = fopen(arquivo, "a");//abre o arquivo pra ataulizar
	fprintf(file,nome);//salva o conteúdo da variável "nome" dentro do arquivo
	fclose(file);//fecha o arquivo
	
	//Arrumando as informações do usuário
	file = fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file,",\n \t SOBRENOME: ");//mostra essa mensagem depois do nome
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta a informação "sobrenome" do usuário
	scanf("%s", sobrenome);//salva na string
	
	file = fopen(arquivo, "a");//abre o arquio pra atualizar
	fprintf(file, sobrenome);//salva a variáel "sobrenome" dentro do arquivo
	fclose(file);//fecha o arquivo 
	
	//Arrumando as informações do usuário
	file =fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file, ",\n \t CARGO: ");//mostra essa mensagem depois do sobrenome
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informação do usuário
	scanf("%s", cargo);//salva na variável/string
	
	file = fopen(arquivo, "a");//abre o arquivo pra atualizar
	fprintf(file,cargo);//coloca as informações, que é o cargo, dentro do arquivo
	fprintf(file, ".\n\n");//espaço pra ficar visualmente mais agradável
	fclose(file);//fecha o arquivo
	
	system("pause");//pause pra conseguir visualizar
}

int consulta()//Função responsável por consultar os usuários cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40];//criando o arquivo cpf novamente pra poder consultar os valores
	char conteudo[200];//armazenando esses valores na variável pra trazer os dados do cpf pra nós
	
	printf("Digite o CPF a ser consultado: ");//Coletando a informação do cpf que vai ser consultado
	scanf("%s", cpf);//salva a informção dentro da string cpf
	
	FILE *file;//acessar a parte do arquivo
	file = fopen(cpf, "r");//abrir o arquivo cpf e ler esse arquivo, r de ready
	
		if(file == NULL)//Se o valor do cpf digitado for nulo aparece a mensagem:
		{
			printf("Não foi possível abrir o arquivo, não localizado!. \n");
		}
	
		printf("Essas são as informações do usuário: \n\n");
		
		while(fgets(conteudo, 200, file)!= NULL)//Função pra salvar dentro da vairável conteúdo os 200 caracteres que estão dentro do arquivo, com um laço de repetição "while"
		{
			printf("%s", conteudo);
		}
	
		system("pause");//pause pra conseguir visualizar
	
}

int deletar()//Função responsável por deletar os dados dos usuários
{
	char cpf[40];//criando o arquivo cpf novamente pra poder consultar os valores
	
	printf("Digite o CPF do usuário a ser deletado: \n\n\t");//coletando a informação do cpf que vai ser deletado
	scanf("%s", cpf);//salva na string o cpf digitado
	
	remove(cpf);//exclui o cpf
	
	FILE *file;//acessa o arquivo
	file = fopen(cpf,"r");//abre o arquivo cpf e le esse arquivo
	
	if(file == NULL)//caso o arquivo for nulo, não existir, aparece a mensagen:
	{
		printf("\nO usuário não se encontra no sistema!. \n\n");
		system("pause");//pause pra conseguir visualizar a mensagem
	}
	else//Se o cpf foi encontrado e já foi deletado aparece a mensagem:
	{
		printf("\nO usuário já foi deletado do sistema!. \n\n");
		system("pause");//pause pra conseguir visualizar a mensagem
	}
}

int main()//Função principal
{
	int opcao=0; //Definindo variáveis 
	
	int laco=1;//cria a variável pra chamar o "for"
	for(laco=1;laco=1;)//Volta pra tela do menu sem encerrar o programa
	{
		
		
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
		
		printf("### Cartório da EBAC ###\n\n");//Início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		system("cls");
		
				switch(opcao)
			{
				 //Inicio da seleção do menu
		
			case 1:
				registro();//chamada de funções
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
			
			default:
				printf ("Essa opção não está disponível\n");
				system("pause");
				break; //Fim da seleção
			}
	
	}
}
