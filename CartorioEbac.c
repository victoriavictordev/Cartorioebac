#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel por cuidar das string

int registro() // Funcao responsavel por cadastrar os usuarios no sistema
{ 
    // inicia criacao de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criacao de variaveis
    
    printf("Digite o CPF a ser cadastrado:"); //coletando informacao do usuario
    scanf("%s", cpf); // %s refere-se a strings
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
    
    FILE *file; // cria arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo,"a"); // 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose (file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    system ("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    { 
        printf("N�o foi possivel abrir o arquivo, n�o foi localizado!. \n");
	}	

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio:");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
    
    system("pause");
    
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%",cpf);
	
	remove(cpf);
	
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if(file== NULL)
	 {
	 	printf("O usuario nao se encontra no sistema!.\n");
	 	system("pause");
	 	
	 }

	
	
}

int main()
    {
	int opcao=0; // definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;) // p voltar sempre ao inicio do programa
	{
	    
		system("cls"); // responsavel por limpar a tela
	    
	    setlocale(LC_ALL, "Portuguese");
	
	    printf("### Cart�rio da EBAC ### \n\n");
	    printf("Escolha a op��o desejada do menu:\n\n ");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: ");
	
	    scanf("%d",&opcao);
	
	    system("cls"); //cmd p deletar a tela
	    
	    switch(opcao)
	    {
	    	case 1: //iniciar op�ao
	        registro(); // chamada de funcoes
            break; //encerrar opcao
            
            case 2:
            consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� disponivel!\n");
			system ("pause");
			break;
			// fim de selecao
	   	}
	
    	
	}
}
