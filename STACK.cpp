#include <bits/stdc++.h>
using namespace std; 

struct no{

	int info;
	struct no *prox;

};

typedef struct no* Pilha;

void menu();
Pilha cria_pilha();
int vazia(Pilha p);
void apaga_pilha(Pilha *l);
int push(Pilha *l, int elem);
int pop(Pilha *l, int *elem);
int le_topo(Pilha *l, int *elem);
void imprime(Pilha *l);

int main(){

	Pilha p1;

	int op, p1s = 0;
	do{
		menu();
		cin >> op;

		if(op != 1 && op != 0 && p1s == 0) cout << "\nCrie a Pilha primeiro!\n" << endl;
		else{

			switch(op){

				case 0:
					if (p1s == 1) apaga_pilha(&p1);
					cout << "\nFim do programa!" << endl;
					break;

				case 1:
					
					if (!p1s == 1){
						p1 = cria_pilha();
						cout << "\nPilha criada com sucesso!\n" << endl;
						p1s = 1;
					}else
						cout << "\nPilha ja foi criada!\n" << endl;
					
					break;

				case 2:
					apaga_pilha(&p1);
					cout << "\nPilha apaga com sucesso!\n" << endl;
					p1s = 0;

					break;

				case 3:
					apaga_pilha(&p1);
					cout << "\nPilha esvaziada com sucesso!\n" << endl;

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

	cout << "1- Criar Pilha\n2- Apaga Pilha\n3- Esvazia Pilha\n4- Inserir Elemento" << endl;
	cout << "5- Remover Elemento\n6- Imprimir Pilha\n0- Sair\nDigite a opcao: ";

}

Pilha cria_pilha(){

	return NULL;
}

int vazia(Pilha p){

	if(p == NULL) return 1;
	else 		  return 0;

}

void apaga_pilha(Pilha *p){

	if(*p != NULL){

		while(*p != NULL){
			Pilha aux = *p;
			*p = aux->prox;
			free(aux);
		}

	}

}

int push(Pilha *p, int elem){

	Pilha no = (Pilha) malloc(sizeof(struct no));
	if(no == NULL) return 0;

	no->info = elem;
	no->prox = *p;

	*p = no;

	return 1;

}

int pop(Pilha *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->info;

	Pilha aux = *p;
	*p = aux->prox;

	free(aux);

	return 1;
}

int le_topo(Pilha *p, int *elem){

	if(vazia(*p)) return 0;

	*elem = (*p)->info;

	return 1;

}

void imprime(Pilha *p){

	if(vazia(*p)) cout << "\nPilha vazia!\n" << endl;

	else{

		Pilha temp = cria_pilha();

		int n;
		while(pop(p, &n)) push(&temp, n); 

		cout << "\nPilha:" << endl;
		int i = 1;
		bool ok = false;
		while(pop(&temp, &n)){
			if(ok) cout << " ";
			cout << n;
			i++;
			ok = true;
			if(!push(p, n)){
				cout << "\nOcorreu algum erro!\nPilhas excluidas!" << endl;
				apaga_pilha(p);
				break;
			}
		}
		apaga_pilha(&temp);
		cout << endl << endl;
	}

}
