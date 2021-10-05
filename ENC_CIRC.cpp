#include <bits/stdc++.h>
using namespace std; 

struct no{

	int info;
	struct no* prox;

};

typedef struct no* Lista;

void menu();
Lista cria_lista();
int vazia(Lista l);
void apaga_lista(Lista *l);
int insere_fim(Lista *l, int elem);
int remove(Lista *l, int elem);
int get_elem_pos(Lista *l, int pos, int *elem);
void imprime(Lista *l);

int main(){

	Lista l1;

	int op, l1s = 0;
	do{
		menu();
		cin >> op;

		if(op != 1 && op != 0 && l1s == 0) cout << "\nCrie a lista primeiro!\n" << endl;
		else{

			switch(op){

				case 0:
					if (l1s == 1) apaga_lista(&l1);
					cout << "\nFim do programa!" << endl;
					break;

				case 1:
					
					if (!l1s == 1){
						l1 = cria_lista();
						cout << "\nLista criada com sucesso!\n" << endl;
						l1s = 1;
					}else
						cout << "\nLista ja foi criada!\n" << endl;
					
					break;

				case 2:
					apaga_lista(&l1);
					cout << "\nLista apaga com sucesso!\n" << endl;
					l1s = 0;

					break;

				case 3:
					cout << "\nDigite o elemento: ";
					int elem;
					cin >> elem;
					if(insere_fim(&l1, elem)) cout << "\nElemento inserido com sucesso!\n" << endl;
					else				  cout << "\nHouve algum erro!\n" << endl;

					break;

				case 4:
					cout << "\nDigite o elemento: ";
					//int elem;
					cin >> elem;
					if(remove(&l1, elem)) cout << "\nElemento removido com sucesso!\n" << endl;
					else				  cout << "\nHouve algum erro!\n" << endl;

					break;

				case 5:
					imprime(&l1);

					break;

				default:
					cout << "Opcao invalida!" << endl;

			}
		}
	}while(op != 0);


}

void menu(){

	cout << "1- Criar Lista\n2- Apaga/Esvazia Lista\n3- Inserir Elemento" << endl;
	cout << "4- Remover Elemento\n5- Imprimir Lista\n0- Sair\nDigite a opcao: ";

}

Lista cria_lista(){

	return NULL;

}

int vazia(Lista l){

	if(l == NULL) return 1;
	else 		  return 0;

}

void apaga_lista(Lista *l){

	if(*l != NULL){

		Lista aux = (*l)->prox;
		while((*l)->prox != *l){
			(*l)->prox = aux->prox;
			free(aux);
			aux = (*l)->prox;
		}
		free(*l);
		*l = NULL;

	}

}

int insere_fim(Lista *l, int elem){

	Lista no = (Lista) malloc(sizeof(struct no));
	if (no == NULL) return 0;

	no->info = elem;

	if(vazia(*l)) no->prox = no;

	else{
		no->prox = (*l)->prox;
		(*l)->prox = no;
	}

	*l = no;

	return 1;

}

int remove(Lista *l, int elem){

	if(vazia(*l)) return 0;

	Lista aux = (*l)->prox;

	if(aux->info == elem) (*l)->prox = aux->prox;
	else{

		while(aux->prox != (*l)->prox && aux->prox->info != elem) aux = aux->prox;

		if(aux->prox->info != elem) return 0;

		Lista aux1 = aux;
		aux = aux->prox;
		aux1->prox = aux->prox;
	
		if(aux == *l) *l = aux1;

	}

	if(aux->prox == aux) *l = NULL;

	free(aux);

	return 1;
}

int get_elem_pos(Lista *l, int pos, int *elem){

	if(pos < 1 || vazia(*l)) return 0;

	Lista aux = (*l)->prox;
	
	if(pos == 1) *elem = aux->info;

	while(aux->prox != (*l)->prox && pos > 1){
		aux = aux->prox;
		pos--;
	}

	if(pos > 1) return 0;

	*elem = aux->info;

	return 1;

}

void imprime(Lista *l){

	if(vazia(*l)) cout << "\nLista vazia!\n" << endl;

	else{

		cout << "\nLista:" << endl;
		int i = 1, n;
		bool ok = false;
		while(get_elem_pos(l, i, &n)){
			if(ok) cout << " ";
			cout << n;
			i++;
			ok = true;
		}
		cout << endl << endl;
	}

}
