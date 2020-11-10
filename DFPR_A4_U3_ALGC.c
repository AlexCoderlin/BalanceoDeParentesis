/*
* Por: Alejandro Gonzalez Colin
* Ingenieria en Desarrollo de Sofotware
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct nodo { // Definimos estrucutra de nodos.
    char simbolo;
    struct nodo *sig;
};

struct nodo *top=NULL; // Inicializamos y asignamos valor al nodo top (que es variable global).

/*-- Funcion de insercion de nodo en pila --*/
void push(char x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->simbolo = x;
    if (top == NULL){
        top = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = top;
        top = nuevo;
    }
}

/*-- Funcion de extraccion de nodo en pila --*/
char pop(){
    if (top != NULL){
        char in = top->simbolo;
        struct nodo *bor = top;
        top = top->sig;
        free(bor);
        return in;
    }
    else{
        return -1;
    }
}

/*-- Funcion de liberar toda la pila --*/
void liberar(){
    struct nodo *reco = top;
    struct nodo *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

/*-- Funcion para validar si parentesis estan balanceados --*/
int balanceado(char *formula){
    int i;
    for (i=0;i<strlen(formula);i++){
        if (formula[i]=='('){
            push(formula[i]);
        }
        else{
            if (formula[i]==')'){
                if (pop()!='('){
                }
            }
        }
    }
    if (top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/*-- Funcion principal --*/
int main(){
    char formula[100];
    
    printf("\n\t Desarrollado con <3 por Alejandro Gonzalez Colin\n\n");
    printf("Ingrese cadena con parentesis:");
    gets(formula);  
    
    if (balanceado(formula)){
        printf("La cadena tiene parentesis balanceados");
    }
    else{
        printf("La cadena NO tiene parentesis balanceados");
    }
    liberar();
    getch();
    return 0;
}