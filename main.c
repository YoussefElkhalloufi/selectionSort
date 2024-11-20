#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;
struct Element{
  short int valeur;
  Element *e_suivant;
};


typedef struct Liste Liste;
struct Liste{
  short int longueur;
  Element *e_head;
};


Liste *initialize(){
  Liste *liste = malloc(sizeof(Liste));

  if(liste == NULL ) exit(EXIT_FAILURE);

  liste->longueur = 0;
  liste->e_head = NULL;

  return liste;
}


void append(Liste *liste, short int valeur){
  Element *element = malloc(sizeof(Element));

  if(liste == NULL || element == NULL ) exit(EXIT_FAILURE);

  element->valeur = valeur;
  element->e_suivant = NULL;

  if(liste->e_head == NULL){
    liste->e_head = element;
  }else{
    Element *elementCourant = liste->e_head;
    while(elementCourant->e_suivant != NULL){
      elementCourant = elementCourant->e_suivant;
    }
    elementCourant->e_suivant = element;
  }
  liste->longueur++;
}

void suppPval(Liste *liste, short int valeur){
  if (liste == NULL || liste->e_head == NULL) exit(EXIT_FAILURE);

  if(liste->e_head->valeur == valeur){//suppression du premier element de la liste
    Element *elementAsupprimer = liste->e_head;
    liste->e_head = liste->e_head->e_suivant;
    free(elementAsupprimer);
    liste->longueur--;
    return ;
  }

    Element *elementCourant = liste->e_head->e_suivant;
    Element *elementPrecedent = liste->e_head;

    // Recherche de l'élément à supprimer
    while (elementCourant != NULL && elementCourant->valeur != valeur) {
        elementPrecedent = elementCourant;
        elementCourant = elementCourant->e_suivant;
    }


    if (elementCourant == NULL) {//l'élément n'a pas été trouvé
      printf("Element n'est pas trouvé !!!");
      return;
    }

    // Suppression de l'élément trouvé
    elementPrecedent->e_suivant = elementCourant->e_suivant;
    free(elementCourant);
    liste->longueur--;
}


int min(Liste *liste){
  if(liste == NULL) exit(EXIT_FAILURE);

  int min = liste->e_head->valeur;
  Element *elementCourant = liste->e_head->e_suivant ;
  while(elementCourant != NULL){
    if(elementCourant->valeur < min ) min = elementCourant->valeur;
    elementCourant = elementCourant->e_suivant;
  }

  return min;

}


Liste *triInsert(Liste *liste){
  Liste *listeTriee = initialize();

  Element *elementCourant = liste->e_head;

  int longueur = liste->longueur ;
  for(int i = 0; i<longueur; i++){
    int minimum = min(liste);
    append(listeTriee, minimum);
    suppPval(liste, minimum);
  }
  return listeTriee;
}


void afficherListe(Liste *liste){
  Element *elementCourant = liste->e_head;
  while(elementCourant != NULL ){
    printf(" %d -> ",elementCourant->valeur);
    elementCourant = elementCourant->e_suivant;
  }
  printf("NULL");
}


int main(){
  Liste *liste = initialize();
  append(liste, 10);
  append(liste, 20);
  append(liste, -10);
  append(liste, -20);
  append(liste, 30);
  printf("Liste initiale :\n\t");
  afficherListe(liste);
  printf("\n");
  printf("\tLe minimum dans la liste est : %d\n", min(liste));
  printf("Suppression de l'element 20 :\n\t");
  suppPval(liste, 20);
  afficherListe(liste);
  printf("\nSuppression de l'element 100 :\n\t");
  suppPval(liste, 100);
  printf("\nListe triée :\n\t");
  afficherListe(triInsert(liste));
  printf("\n");
}
