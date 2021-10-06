#include <bits/stdc++.h>
using namespace std; 

struct no{

	int info;
	struct no *prox;

};

typedef struct no* Fila;

void menu();
Fila cria_fila();
int vazia(Fila p);
void apaga_fila(Fila *l);
int push(Fila *l, int elem);
int pop(Fila *l, int *elem);
int le_primeiro(Fila *l, int *elem);
int le_ultimo(Fila *l, int *elem);
void imprime(Fila *l);

int main(){

	Fila p1;

	int op, p1s = 0;
	do{
		menu();
		cin >> op;

		if(op != 1 && op != 0 && p1s == 0) cout << "\nCrie a Fila primeiro!\n" << endl;
		else{

			switch(op){

				case 0:
					if (p1s == 1) apaga_fila(&p1);
					cout << "\nFim do programa!" << endl;
					break;

				case 1:
					
					if (!p1s == 1){
						p1 = cria_fila();
						cout << "\nFila criada com sucesso!\n" << endl;
						p1s = 1;
					}else
						cout << "\nFila ja foi criada!\n" << endl;
					
					break;

				case 2:
					apaga_fila(&p1);
					cout << "\nFila apaga com sucesso!\n" << endl;
					p1s = 0;

					break;

				case 3:
					apaga_fila(&p1);
					cout << "\nFila esvaziada com sucesso!\n" << endl;

					break;

				case 4:
					cout << "\nDigite o elemento: ";
					int elem;
					cin >> elem;
					if(push(&p1, elem)) cout << "\nElemento inserido com sucesso!\n" << endl;
					else				cout << "\nHouve algum erro!\n" << endl;

					break;

				case 5:
					if(pop(&p1, &elem)) cout << "\nElemento " << elem << " removido com sucesso!\n" << endl;
					else			    cout << "\nHouve algum erro!\n" << endl;

					break;

				case 6:
					imprime(&p1);

					break;

				default:
					cout << "Opcao invalida!" << endl;

			}
		}
	}while(op != 0);


}

void menu(){

	cout << "1- Criar Fila\n2- Apaga Fila\n3- Esvazia Fila\n4- Inserir Elemento" << endl;
	cout << "5- Remover Elemento\n6- Imprimir Fila\n0- Sair\nDigite a opcao: ";

}

Fila cria_fila(){

	return NULL;
}

int vazia(Fila p){

	if(p == NULL) return 1;
	else 		  return 0;

}

void apaga_fila(Fila *p){

	if(*p != NULL){

		while(*p != (*p)->prox){
			Fila aux = (*p)->prox;
			(*p)->prox = aux->prox;
			free(aux);
		}
		free(*p);
		*p = NULL;

	}

}

int push(Fila *p, int elem){

	Fila no = (Fila) malloc(sizeof(struct no));
	if(no == NULL) return 0;

	no->info = elem;

	if(vazia(*p)){
		
		no->prox = no;
		*p = no;
	
	}else if((*p)->info >= elem){
		
		no->prox = (*p)->prox;
		(*p)->prox = no;
		*p = no;
	
	}else{

		Fila aux = *p;
		while(aux->prox->info >= elem) aux = aux->prox;

		no->prox = aux->prox;
		aux->prox = no;

	}

	return 1;

}

int pop(Fila *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->prox->info;

	Fila aux = (*p)->prox;

	if(aux == *p) *p = NULL;
	else          (*p)->prox = aux->prox;

	free(aux);

	return 1;
}

int le_primeiro(Fila *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->prox->info;

	return 1;

}

int le_ultimo(Fila *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->info;

	return 1;

}

void imprime(Fila *p){

	if(vazia(*p)) cout << "\nFila vazia!\n" << endl;

	else{

		Fila temp = cria_fila();

		cout << "\nFila:" << endl;
		int i = 1, n;
		bool ok = false;
		while(pop(p, &n)){
			if(!push(&temp, n)){
				cout << "\nOcorreu algum erro!\nFilas excluidas!" << endl;
				apaga_fila(p);
				break;
			}
			if(ok) cout << " ";
			cout << n;
			i++;
			ok = true;
		} 
		
		while(pop(&temp, &n)){
			if(!push(p, n)){
				cout << "\nOcorreu algum erro!\nFilas excluidas!" << endl;
				apaga_fila(p);
				break;
			}
		}
		apaga_fila(&temp);
		cout << endl << endl;
	}

}
