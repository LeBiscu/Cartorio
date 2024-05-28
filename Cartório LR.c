#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca das strings

int registro()
   {
   	setlocale(LC_ALL, "portuguese");
   	
   	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadatrado :");
	scanf("%s", cpf);//varre tudo oq o usuario digitar e salva onde pedir. ¨s%¨de string.
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file;//cria arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
   }

int consultar()
   {
   	setlocale(LC_ALL, "portuguese");
   	
   	char cpf[40];
   	char conteudo[200];
   	
   	printf("Digite o CPF a ser consultado:");
   	scanf("%s",cpf);
   	
   	FILE *file;   //file é o arquivo ja existente no computador 
   	file = fopen(cpf,"r"); //o r é read ler em ingles, para o programa ler o arquivo cpf
   	
   	if(file == NULL)// os iguais sao para comparação
    {
    	printf("Esse usuário não foi encontrado\n");
		   }   	
		   
		   while(fgets(conteudo, 200, file)!=NULL)	// while é laço de repetição( enquanto). f é sempre arquivo.(esta salvando na variavel os 200 que estao dentro do arquivo).
		   
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s",conteudo);
			printf("\n\n");
		}
		
		system("pause");
   }
   
int deletar()
   {
   	
   	char cpf[40];
   	
   	printf("Digite o usuário a ser deletado:");
   	scanf("%s",cpf);
   	
   	remove(cpf);
   	
   	FILE *file;//procurar um arquivo
   	file = fopen(cpf,"r");// abriu(fopen) o arquivo e leu ("r") o arquivo cpf
   	
   	if(file == NULL)
   	{
   		printf("Esse usuário não foi encontrado.\n");
   		system("pause");
	   }
	   
   }   
   
int main()
{	  

int opcao=0;
int x=1;

    for(x=1;x=1;)
    
    {
	
	system("cls");

	setlocale(LC_ALL, "portuguese");
	printf("Cartório LR\n\n");
	printf("escolha a opção desejada\n\n");
	printf("\t1-Registrar nomes\n");
    printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	
	scanf("%d",&opcao);
	
	system("cls"); 
	
	switch(opcao)
	{
	
	case 1:
	registro(); 
	system("pause");
	break;
		 
	case 2:
	consultar();
    system("pause");
	break;
	
	case 3:
    deletar();
	system("pause");
	break;
	
	default	:
	printf("Essa opção não existe\n");
    system("pause");
    break;
		 
   }
	
   }
}


