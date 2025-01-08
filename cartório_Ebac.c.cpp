#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de string


/////////////////////////////
//funções do sistema

int registrar() //cadastro de usuarios
{ 

  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
  
  
  printf("Buscando ficha para registro\n");
  system("pause");
  system("cls");
  
  //variáveis usadas
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  int continuar=0; 
  
  printf("Digite o CPF para cadastro: "); //coletando informação
  scanf("%s", cpf); 
  
  strcpy(arquivo, cpf); //copiar valores
  
  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //abre e escreve um arquivo novo
  fprintf(file,cpf); //salva o valor da variavel
  fclose(file); //fecha o arquivo
  
  file = fopen(arquivo, "a"); //alterando arquivo ja criado
  fprintf(file,","); //adicionando uma virgula entre as informações
  fclose(file);
  
  printf("Digite o nome para cadastro: ");
  scanf("%s", nome);
  
  file = fopen(arquivo, "a");//alterando arquivo ja criado
  fprintf(file, nome); //adicionando a variavel 'nome' ao banco de dados
  fclose(file);
  
  file = fopen(arquivo, "a");//alterando arquivo ja criado
  fprintf(file,",");//adicionando uma virgula entre as informações
  fclose(file);
  
  printf("Digite o sobrenome para cadastro: ");
  scanf("%s", sobrenome); 
  
  file = fopen(arquivo, "a");//alterando arquivo ja criado
  fprintf(file, sobrenome); //adicionando a variavel 'sobrenome' ao banco de dados
  fclose(file);  
   
  file = fopen(arquivo, "a");//alterando arquivo ja criado
  fprintf(file,",");//adicionando uma virgula entre as informações
  fclose(file);   
  
  printf("Digite o cargo correspondente: ");
  scanf("%s", cargo);
  
  file = fopen(arquivo, "a");
  fprintf(file, cargo); //adicionando a variavel 'cargo' ao banco de dados
  fclose(file);
  
  printf("\n\n\tDados salvos.\n\n"); //mensagem de saída
  
  printf("Deseja fazer outro registro?\n"); //caminho pós registro
  printf("1- Sim \n");
  printf("2- Não \n\n");
  scanf("%d", &continuar); //armazenando a escolha do usuario
  
  switch(continuar)
  {
  	case 1:
  		registrar();
  		break;
  		
  	case 2:
  		system("pause");
  		system("cls");
  		break;
  }
  
}
//---------------
int consultar()
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Abrindo registros da EBAC\n\n");
	system("pause");	
	system("cls");
	
	//variáveis usadas
	char cpf[40];
	char conteudo[200];
	
	printf("Qual CPF deseja consultar?\n\t"); //coletando informação
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo documentos salvos no banco de dados
	
	if(file == NULL)
	{
		printf("\n\n Este CPF não está registrado.\n\n"); //caso não ache o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("CPF encontrado. Aqui está o registro: \n"); //ao achar o arquivo, traz as informações contidas nele
    	printf("%s", conteudo);
	    printf("\n\n");

	}
	
	system("pause");
}
//---------------
int deletar()
{
   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//variáveis usadas
   char cpf[40];
   char conteudo[200];
   int confirmacao=0;
   
   printf("Informe qual registro deseja excluir informando o CPF: \n\t"); //coletando informações
   scanf("%s",cpf);
   printf("\n\n");
   system("pause");	
   
   FILE *file;
   file = fopen(cpf, "r");
   
   while(fgets(conteudo, 200, file) != NULL)
	{
		printf("CPF encontrado. Aqui está o registro: \n"); //ao achar o arquivo, traz as informações contidas nele
    	printf("%s", conteudo);
	    printf("\n\n");
	}
   
   printf("Deseja deletar mesmo assim?\n"); //confirmação de remoção de CPF
   printf("\t1- sim \n");
   printf("\t2- não\n");
   scanf("%d", &confirmacao);
   
   switch(confirmacao)
   {
   	  case 1:
   	    remove(cpf); //remove o CPF
   	    printf("O registro foi deletado!\n\n");
   	    system("pause");
   	    break;
   	  	
   	  case 2:
		printf("\tCPF não deletado\n"); //cancela a ação de deletar
		printf("\tO registro permanece intacto\n\n");
		system("pause");
   }
   
   
   
   if(file == NULL) //caso não encontre o CPF
   {
   	  printf("\tO CPF não se encontra no sistema.\n");
   }
   
}
/////////////////////////////
//Função principal

int main()
{
	//variáveis usadas
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf(" -- Bem vindo aos Registros EBAC --\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite sua senha\n\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao==0)
	{
		
		for(laco=1;laco=1;) //laço de repetição
	{

		system("cls");

	 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf(" -- Bem vindo aos Registros EBAC --\n\n"); //inicio do menu
 	 	printf("\t    Menu Principal\n");
	 	printf("\tQual opção você deseja?\n\n");
	 	printf("1- Registrar aluno\n");	
	 	printf("2- Consultar registros\n");
	 	printf("3- Deletar registro\n"); 
	 	printf("4- Sair do sistema\n\n");
	 	printf("opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
	 	system("cls");
	 
	 	switch(opcao) //seleção de acordo com a escolha do usuário
	 	{
	 		case 1:
	 			registrar();
	 			break;
	 		
	 		case 2:
	 			consultar();
	 			break;
	 		
	 		case 3:
			 	deletar();
		 	    break;
		
			case 4:
				printf("Obrigado por usar o sistema!\n");
				return 0;
				break;
		     
			default:
				printf("o número inserido não corresponte a uma opção!\n");
				printf("Por favor digite um número do menu");
				system("pause");
				break;
		 }//switch case
	
  	  }//for	
		
	} //if
	

   else
   	{
   		printf("senha incorreta!");
	   }
	
} //fim


