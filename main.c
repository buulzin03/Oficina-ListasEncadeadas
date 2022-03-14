#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <C:\Users\Caio\Desktop\Ed1\TrabalhoLista\colecaolista.c>



typedef struct _oficina_{
    char produto[20];
    float preco;
    int idproduto;

}oficina;


int cmpchar(void *elm1, void *elm2){
    oficina *d;
    char texto[20];

    d= (oficina*)elm1;
    strcpy(texto,(char*)elm2);
        if(strcasecmp(texto,d->produto)==0){
            return 1;
        }else{
            return 0;
        }
}

int cmpfloat(void *elm1, void *elm2){
    oficina *d;
    float *pont;

    d= (oficina*)elm2;
    pont =(float*)elm1;
        if(*pont == d->preco){
            return 1;
        }else{
            return 0;
        }
}


int cmp(void *elm1, void *elm2){
    oficina *d ;
    int *pont;

    d = (oficina*)elm2;
    pont=(int*)elm1;
        if(* pont == d->idproduto){
            return 1;
        }else{
            return 0;
        }

}

int main(void){

SLList *l;
oficina *tmp;

int opc=0;

l = sllCreate();

 while(opc!=6){
        system("cls");
        printf("BEM VINDO AO ESTOQUE DA OFICINA\n\n");
        printf("1-CADASTRAR PRODUTO\n");
        printf("2-LISTAR PRODUTOS\n");
        printf("3-REMOVER PRODUTO\n");
        printf("4-BUSCAR PRODUTO POR TIPO\n");
        printf("5-DESTRUIR ESTOQUE\n");
        printf("6-SAIR\n\nDIGITE UMA OPCAO: ");
        scanf("%d",&opc);
        fflush(stdin);
        switch(opc){
        case 1:
            system("cls");
            tmp = (oficina*)malloc(sizeof(oficina));
            if(tmp!=NULL){
                printf("DIGITE O NOME DO PRODUTO: ");
                fgets(tmp->produto,19,stdin);
                fflush(stdin);

                printf("\nDIGITE O ID PARA SER USADO NO PRODUTO: ");
                scanf("%d",&tmp->idproduto);
                fflush(stdin);

                printf("\nDIGITE O PRECO DO PRODUTO: ");
                scanf("%f",&tmp->preco);
                fflush(stdin);

                sllInsertFirst(l,(void*)tmp);
            }

            system("cls");
            break;
        case 2:
            system("cls");
            SLNode *spec;

            int i;
            if(l->first==NULL){
                printf("\nNENHUM PRODUTO CADASTRADO\n\n\n\n");
            }
            if(l->first!=NULL){
                spec = l->first;
                //tmp = (oficina*)spec->data;
                while(spec!=NULL){
                    tmp = (oficina*)spec->data;
                    printf("Produto: %s idproduto: %d preco: %.2f \n",tmp->produto,tmp->idproduto,tmp->preco);
                    spec = spec->next;
                }
            }
            system("pause");

            break;

        case 3:
            system("cls");
            char nomeproduto[15];
            float precoproduto;
            int idproduto1;

            char tipobusca1[4];
            printf("INFORME SE DESEJA REMOVER PELO NOME DO PRODUTO(1), ID(2) OU PRECO(3): ");
            fgets(tipobusca1,2,stdin);


            if(strcmp(tipobusca1,"1")==0 ){
                printf("INFORME O NOME DO PRODUTO: ");
                fflush(stdin);
                fgets(nomeproduto,14,stdin);
                tmp = (oficina*)sllRemoveSpec(l, (void*)&nomeproduto, cmpchar);
                if(tmp!=NULL){
                    printf("\n\nPRODUTO REMOVIDO\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                }
            }else if(strcmp(tipobusca1,"2")==0){
                printf("INFORME O ID DO PRODUTO: ");
                scanf("%d",&idproduto1);
                tmp = (oficina*)sllRemoveSpec(l, (void*)&idproduto1, cmp);
                if(tmp!=NULL){
                    printf("\n\nPRODUTO REMOVIDO\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                }
            }else if(strcmp(tipobusca1,"3")==0){
                printf("INFORME O PRECO DO PRODUTO: ");
                scanf("%f",&precoproduto);
                tmp = (oficina*)sllRemoveSpec(l, (void*)&precoproduto, cmpfloat);
                if(tmp!=NULL){
                    printf("\n\nPRODUTO REMOVIDO\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            printf("INFORME SE DESEJA BUSCAR PELO PRODUTO(1), ID(2) OU PRECO(3): ");
            int idproduto;
            char produtonome[20];
            float precoproduto2;
            char opbusca[4];


            fgets(opbusca,2,stdin);
            if(strcmp(opbusca,"1")==0){
                fflush(stdin);
                printf("INFORME O NOME DO PRODUTO: ");
                fgets(produtonome,19,stdin);


                tmp = (oficina*)sllQuery(l, (void*)&produtonome,cmpchar);
                    if(tmp!=NULL){
                        printf("\n\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                    }

            }else if(strcmp(opbusca,"2")==0){
                printf("INFORME O ID DO PRODUTO: ");
                scanf("%d",&idproduto);


                tmp = (oficina*)sllQuery(l, (void*)&idproduto, cmp);
                    if(tmp!=NULL){
                    printf("\n\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                    }
            }
            else if(strcmp(opbusca,"3")==0){
                printf("INFORME O PRECO DO PRODUTO: ");
                scanf("%f",&precoproduto2);
                tmp = (oficina*)sllQuery(l, (void*)&precoproduto2, cmpfloat);
                if(tmp!=NULL){
                    printf("\n\nPRODUTO: %s \nID: %d \nPRECO: %.2f \n",tmp->produto, tmp->idproduto, tmp->preco);
                }
            }

            system("pause");
            break;
        case 5:
            sllDestroy(l);
        default:
            printf("OPCAO INVALIDA");

        }


    }


free(l);

}
