#include <bits/stdc++.h>
using namespace std; 

struct no{

	int info;
	struct no *prox;

};

typedef struct no* Deque;

void menu();
Deque cria_deque();
int vazia(Deque p);
void apaga_deque(Deque *l);
int insere_ini(Deque *l, int elem);
int insere_fim(Deque *p, int elem);
int remove_ini(Deque *l, int *elem);
int remove_fim(Deque *l, int *elem);
int le_primeiro(Deque *l, int *elem);
int le_ultimo(Deque *l, int *elem);
void imprime(Deque *l);

int main(){

	Deque p1;

	int op, p1s = 0;
	do{
		menu();
		cin >> op;

		if(op != 1 && op != 0 && p1s == 0) cout << "\nCrie a Deque primeiro!\n" << endl;
		else{

			switch(op){

				case 0:
					if (p1s == 1) apaga_deque(&p1);
					cout << "\nFim do programa!" << endl;
					break;

				case 1:
					
					if (!p1s == 1){
						p1 = cria_deque();
						cout << "\nDeque criada com sucesso!\n" << endl;
						p1s = 1;
					}else
						cout << "\nDeque ja foi criada!\n" << endl;
					
					break;

				case 2:
					apaga_deque(&p1);
					cout << "\nDeque apaga com sucesso!\n" << endl;
					p1s = 0;

					break;

				case 3:
					apaga_deque(&p1);
					cout << "\nDeque esvaziada com sucesso!\n" << endl;

					break;

				case 4:
					cout << "\nDigite o elemento: ";
					int elem;
					cin >> elem;
					if(insere_ini(&p1, elem)) cout << "\nElemento inserido com sucesso!\n" << endl;
					else				      cout << "\nHouve algum erro!\n" << endl;

					break;

				case 5:
					cout << "\nDigite o elemento: ";
					cin >> elem;
					if(insere_fim(&p1, elem)) cout << "\nElemento inserido com sucesso!\n" << endl;
					else				      cout << "\nHouve algum erro!\n" << endl;

					break;

				case 6:
					if(remove_ini(&p1, &elem)) cout << "\nElemento " << elem << " removido com sucesso!\n" << endl;
					else			           cout << "\nHouve algum erro!\n" << endl;

					break;

				case 7:
					if(remove_fim(&p1, &elem)) cout << "\nElemento " << elem << " removido com sucesso!\n" << endl;
					else			           cout << "\nHouve algum erro!\n" << endl;

					break;

				case 8:
					imprime(&p1);

					break;

				default:
					cout << "Opcao invalida!" << endl;

			}
		}
	}while(op != 0);


}

void menu(){

	cout << "1- Criar Deque\n2- Apaga Deque\n3- Esvazia Deque\n4- Inserir Inicio\n5- Inserir Fim" << endl;
	cout << "6- Remover Inicio\n7- Remover Final\n8- Imprimir Deque\n0- Sair\nDigite a opcao: ";

}

Deque cria_deque(){

	return NULL;
}

int vazia(Deque p){

	if(p == NULL) return 1;
	else 		  return 0;

}

void apaga_deque(Deque *p){

	if(*p != NULL){

		while(*p != (*p)->prox){
			Deque aux = (*p)->prox;
			(*p)->prox = aux->prox;
			free(aux);
		}
		free(*p);
		*p = NULL;

	}

}

int insere_ini(Deque *p, int elem){

	Deque no = (Deque) malloc(sizeof(struct no));
	if(no == NULL) return 0;

	no->info = elem;

	if(vazia(*p)){
	
		no->prox = no;
		*p = no;
	
	}else{
	
		no->prox = (*p)->prox;
		(*p)->prox = no;
	
	}

	return 1;

}

int insere_fim(Deque *p, int elem){

	Deque no = (Deque) malloc(sizeof(struct no));
	if(no == NULL) return 0;

	no->info = elem;

	if(vazia(*p)) no->prox = no;
	else{

		no->prox = (*p)->prox;
		(*p)->prox = no;
	
	}

	*p = no;

	return 1;

}

int remove_ini(Deque *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->prox->info;

	Deque aux = (*p)->prox;

	if(aux == *p) *p = NULL;
	else          (*p)->prox = aux->prox;

	free(aux);

	return 1;
}

int remove_fim(Deque *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->info;

	Deque aux = *p;

	if(aux->prox == *p) *p = NULL;
	else{

		while(aux->prox != *p) aux = aux->prox;

		aux->prox = (*p)->prox;
		Deque aux1 = aux;
		aux = *p;
		*p = aux1;

	}

	free(aux);

	return 1;
}

int le_primeiro(Deque *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->prox->info;

	return 1;

}

int le_ultimo(Deque *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->info;

	return 1;

}

void imprime(Deque *p){

	if(vazia(*p)) cout << "\nDeque vazia!\n" << endl;

	else{

		Deque temp = cria_deque();

		cout << "\nDeque:" << endl;
		int i = 1, n;
		bool ok = false;
		while(remove_ini(p, &n)){
			if(!insere_ini(&temp, n)){
				cout << "\nOcorreu algum erro!\nDeques excluidas!" << endl;
				apaga_deque(p);
				break;
			}
			if(ok) cout << " ";
			cout << n;
			i++;
			ok = true;
		} 
		
		while(remove_ini(&temp, &n)){
			if(!insere_ini(p, n)){
				cout << "\nOcorreu algum erro!\nDeques excluidas!" << endl;
				apaga_deque(p);
				break;
			}
		}
		apaga_deque(&temp);
		cout << endl << endl;
	}

}
