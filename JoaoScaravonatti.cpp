#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#define tam 1000

struct cliente{
    int codigo;
    char nome[50];
    char sexo[20];
    char dataNascimento[12];
    char cpf[12];
    char telefone[11];
    char email[100];
};

int id = 0;
int i = 0;
struct cliente clientes[tam];

void cadastrar(){
    id++;
    clientes[id].codigo = id;
    
    printf("\nColoque o nome completo: ");
    scanf(" %[^\n]s",&clientes[id].nome);

    printf("\nColoque o CPF sem formatação: ");
    scanf("%s",&clientes[id].cpf);

    printf("\nColoque o sexo (masculino/feminino): ");
    scanf("%s",&clientes[id].sexo);
	
    printf("\nColoque a data de nascimento no formato XX/XX/XXXX: ");
    scanf("%s",&clientes[id].dataNascimento);
    
    printf("\nColoque o telefone sem formatação: ");
    scanf("%s",&clientes[id].telefone);
    
    printf("\nColoque o email: ");
    scanf("%s",&clientes[id].email);
}

void excluir(int codigo){
	clientes[codigo].codigo = 0;
	strcpy(clientes[codigo].nome,"");
}

void consultarCod(int codigo){
	int verificar = 0;
	system("cls");
	if(codigo != 0){
		for(i=0;i<tam;i++){
			if(clientes[i].codigo == codigo){
				printf("\nDados do cliente n° %i\nNome: %s\nSexo: %s\nData de nascimento: %s\nCPF: %s\nTelefone: %i\nE-mail: %s\n",clientes[i].codigo,clientes[i].nome,clientes[i].sexo,clientes[i].dataNascimento,clientes[i].cpf,clientes[i].telefone,clientes[i].email);
				verificar++;
			}
		}
	} 
	if(verificar==0){
		printf("\nEsse cliente não está cadastrado!");
	}
	printf("\n_______________________________\n");
}

void consultarNome(char nome[]){
	int codigo = 0;
	system("cls");
	if(strcmp(nome,"")!=0){
		for(i=0;i<tam;i++){
			if(strcmp(nome,clientes[i].nome)==0){
				codigo = i;
				printf("\nDados do cliente n° %i\nNome: %s\nSexo: %s\nData de nascimento: %s\nCPF: %s\nTelefone: %i\nE-mail: %s\n",clientes[codigo].codigo,clientes[codigo].nome,clientes[codigo].sexo,clientes[codigo].dataNascimento,clientes[codigo].cpf,clientes[codigo].telefone,clientes[codigo].email);
				printf("\n_______________________________\n");
			}
		}	
	}
	if(codigo == 0){
		printf("\nEsse cliente não está cadastrado!\n");
	}
}
void listar(){
	system("cls");
	for(i=0;i<tam;i++){
		if(clientes[i].codigo != 0){
			printf("\nCliente de código %i: %s\n",clientes[i].codigo,clientes[i].nome);	
			printf("_______________________________\n");
		}
	}
}
void vrau(){
	clientes[1].codigo = 1;
	strcpy(clientes[1].nome,"juca silva");
	strcpy(clientes[1].sexo,"masculino");
	strcpy(clientes[1].dataNascimento,"18/01/2000");
	strcpy(clientes[1].cpf,"08816690917");
	strcpy(clientes[1].telefone,"49999743090");
	strcpy(clientes[1].email,"jvscaravonatti@gmail.com");	
	
	clientes[2].codigo = 2;
	strcpy(clientes[2].nome,"juca silva");
	strcpy(clientes[2].sexo,"masculino");
	strcpy(clientes[2].dataNascimento,"18/01/2000");
	strcpy(clientes[2].cpf,"08816690917");
	strcpy(clientes[2].telefone,"49999743090");
	strcpy(clientes[2].email,"jvscaravonatti@gmail.com");
}
void alterar(int codigo){
	char opcao[1];
	char confirm[1];
	confirm[0] = '0';
	if(codigo != 0){
		do{
			printf("\nQual informação deseja alterar?\n");
			printf("\n1 - Nome: %s\n2 - Sexo: %s\n3 - Data de nascimento: %s\n4 - CPF: %s\n5 - Telefone: %i\n6 - E-mail: %s\nSua opção: ",clientes[codigo].nome,clientes[codigo].sexo,clientes[codigo].dataNascimento,clientes[codigo].cpf,clientes[codigo].telefone,clientes[codigo].email);
			fflush(stdin);
			opcao[0] = getche();
			
			switch(opcao[0]){
				case '1':
					printf("\nColoque o novo nome: ");
					scanf(" %[^\n]s",&clientes[codigo].nome);
					break;
				case '2':
					printf("\nColoque o novo sexo: ");
					scanf("%s",clientes[codigo].sexo);
					break;
				case '3':
					printf("\nColoque a nova data de nascimento: ");
					scanf("%s",&clientes[codigo].dataNascimento);
					break;
				case '4':
					printf("\nColoque o novo CPF: ");
					scanf("%s",&clientes[codigo].cpf);
					break;
				case '5':
					printf("\nColoque o novo telefone: ");
					scanf("%s",&clientes[codigo].telefone);
					break;
				case '6':
					printf("\nColoque o novo e-mail: ");
					scanf("%s",&clientes[codigo].email);
					break;
				default:
					printf("\nOpção inválida!");
			}
			printf("\nContinuar editando? 0 para sim e 1 para não: ");
			confirm[0] = getche();
		}while(confirm[0] !='1');
		
	}
}

int main(){
	//vrau();
    setlocale(LC_ALL,"portuguese");
    
    char opcao[1];
    char flag[1];
    int param=0;
    char paramChar[50];
    char escolha[1];
    flag[0] = '0';
    printf("\nCadstro de clientes HyperSoft\n_____________________________\n");
	Sleep(500);
    do{
        printf("\n\nSelecione uma opção:\n\n");
        printf("1 - Cadastro do cliente\n");
        printf("2 - Alterar dados do cliente\n");
        printf("3 - Exclusão de cliente\n");
        printf("4 - Consultar cliente\n");
        printf("5 - Listar clientes\n");
        printf("6 - Sair\n");
        printf("Sua opção: ");
        
        fflush(stdin);
        opcao[0] = getche();
		system("cls");
        switch(opcao[0]){
        	system("cls");
            case '1':
                cadastrar();
            	break;
            case '2':
            	printf("\nInsira o código do cliente a ser alterado: ");
            	scanf("%i",&param);
				alterar(param);
           		break;
            case '3':
				printf("\nInsira o código do cliente a ser exclúido: ");
            	scanf("%i",&param);
				excluir(param);
            	break;
            case '4':
            	printf("\n1 - Consultar por nome\n2 - Consultar por código\n3 - Voltar\nSua opção: ");
            	fflush(stdin);
            	escolha[0] = getche();
            	switch(escolha[0]){
            		case '1':
            			printf("\nInsira o nome do cliente a ser consultado: ");
            			scanf(" %[^\n]s",&paramChar);
            			consultarNome(paramChar);
            			break;
            		case '2':	
						printf("\nInsira o código do cliente a ser consultado: ");
						scanf("%i",&param);
						consultarCod(param);
						break;	
					case '3':
						break;
					default:
						printf("\nOpção mal informada");
				}
            	break;
            case '5':
		listar();
            	break;
            case '6':
                printf("\nPressione 1 para sair: ");
                flag[0] = getche();
            	break;
            default:
		printf("\nEstá opção não existe\n");
            	break;
        }
    }while(flag[0] != '1');
	printf("\n\aFIM");
    return 0;
}
