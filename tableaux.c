#include <stdio.h>
#include <stdlib.h>


void triParSelection(int arr[], int taille){

    for(int i = 0; i<taille; i++){

        int min_idx = i ; //supposons que le premier element est le minimum

        for(int j = i+1; j< taille; j++){

            if(arr[j] < arr[min_idx]) min_idx = j; // si l'element est plus petit que le premier element
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void afficher(int arr[], int n){

    for(int i = 0; i<n; i++){
        printf("\t%d:\t%d\n", i, arr[i]);
    }
}



int main(){

    int arr[] = {89,34,90,12,-12,19,44,38};
    int taille = sizeof(arr) / sizeof(arr[0]);

    printf("Affichage du tableau avant le tri :\n");
    afficher(arr,taille);

    triParSelection(arr,taille);

    printf("\nAffichage du tableau apres le tri :\n");
    afficher(arr, taille);


    return 0;
}
