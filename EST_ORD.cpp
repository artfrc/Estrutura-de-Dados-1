#include <bits/stdc++.h>
#define MAX 10

using namespace std; 

struct no{

	int info[MAX];
	int tam;

};

typedef struct no* Lista;

void menu();
Lista cria_lista();
int cheia(Lista l);
void esvazia_lista(Lista l);
void apaga_lista(Lista l);
int insere(Lista l, int elem);
int remove(Lista l, int elem);
int get_elem_pos(Lista l, int pos, int *elem);
void imprime(Lista l);

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
					if (l1s == 1) apaga_lista(l1);
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
					apaga_lista(l1);
					cout << "\nLista apaga com sucesso!\n" << endl;
					l1s = 0;

					break;

				case 3:
					esvazia_lista(l1);
					cout << "\nLista esvaziada com sucesso!\n" << endl;

					break;

				case 4:
					cout << "\nDigite o elemento: ";
					int elem;
					cin >> elem;
					if(insere(l1, elem)) cout << "\nElemento inserido com sucesso!\n" << endl;
					else				  cout << "\nHouve algum erro!\n" << endl;

					break;

				case 5:
					cout << "\nDigite o elemento: ";
					cin >> elem;
					if(remove(l1, elem)) cout << "\nElemento removido com sucesso!\n" << endl;
					else				  cout << "\nHouve algum erro!\n" << endl;

					break;

				case 6:
					imprime(l1);

					break;

				default:
					cout << "Opcao invalida!" << endl;

			}
		}
	}while(op != 0);


}

void menu(){

	cout << "1- Criar Lista\n2- Apaga Lista\n3- Esvazia Lista\n4- Inserir Elemento" << endl;
	cout << "5- Remover Elemento\n6- Imprimir Lista\n0- Sair\nDigite a opcao: ";

}

Lista cria_lista(){

	Lista l = (Lista) malloc(sizeof(struct no));
	if(l != NULL){
		l->tam = 0;
	}

	return l;

}

int cheia(Lista l){

	if(l->tam == MAX) return 1;
	else 			  return 0;

}

int vazia(Lista l){

	if(l->tam == 0) return 1;
	else 		    return 0;

}

void esvazia_lista(Lista l){

	if(l != NULL) l->tam = 0;

}

void apaga_lista(Lista l){

	if(l != NULL){

		free(l);
		l = NULL;

	}

}

int insere(Lista l, int elem){

	if(l == NULL || cheia(l)) return 0;

	int i = 0;
	while(i < l->tam && l->info[i] < elem) i++;

	for(int j = l->tam; j > i; --j) l->info[j] = l->info[j-1];

	l->info[i] = elem;

	(l->tam)++;

	return 1;

}

int remove(Lista l, int elem){

	if(l == NULL || vazia(l)) return 0;

	int i = 0;
	while(i < l->tam && l->info[i] != elem) i++;

	if(i == l->tam) return 0;

	for( ; i < l->tam-1; i++) l->info[i] = l->info[i+1];

	(l->tam)--;

	return 1;
}

int get_elem_pos(Lista l, int pos, int *elem){

	if(l == NULL || pos < 1 || pos > l->tam || vazia(l)) return 0;

	*elem = l->info[pos-1];

	return 1;

}

void imprime(Lista l){

	if(vazia(l)) cout << "\nLista vazia!\n" << endl;

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
