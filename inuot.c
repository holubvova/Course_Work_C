#include "inout.h" // підключення інтерфейсної частини
#include <stdio.h> // підключення бібліотеки вводу/виводу
#include "CommonVector.h" // підключення інтерфейсної частини для доступу до глоабльних змінних

int number; // змінна для заповнення масива
int i, j, k; // змінні для циклів
 // функція воду масива залежно від заповнення
void inputmass(int mode){
    switch (mode){
    number = 0;
    case 1: // відсортований масив

        for (k = 0; k < P; k++ )
            for(i = 0; i < N; i++)
                for (j = 0; j < M; j++)
                    Arr3D[k][j][i] = number++;

    break;

    case 2:{ // random масив
        for (k = 0; k < P; k++ )
            for(j = 0; j < M; j++)
                for (i = 0; i < N; i++)
                    Arr3D[k][j][i] =  rand() % (P*M*N);
    break;
    }
    case 3:{ // обернено-відсортований
        number = P*N*M;
        for (k = 0; k < P; k++ )
            for(i = 0; i < N; i++)
                for (j = 0; j < M; j++)
                Arr3D[k][j][i] = number--;
    break;
    }
    }
}
 // функція введення векутору залежності від способу
void inputvector(mode){
    switch(mode){

        case 1:{ // відсортоване заповнення
            number = 0;
        for(i = 0; i < N*M; i++)
            vec[i] = number++;
        break;
        }
        case 2:{ // random заповнення
        for(i = 0; i < N*M; i++)
            vec[i] =  rand() % (M*N);
        break;
        }
        case 3:{ // обернено-відсортоване заповнення
            number = N*M;
        for(i = 0; i < N*M; i++)
            vec[i] = number--;
        break;
        }
}
}

void outmass(){ // функція для виводу трьохвимірного масива
    for (k = 0; k < P; k++ ){
        printf("section %d :\n",k);
        for(i = 0; i < M; i++){
            for (j = 0; j < N; j++)
                printf("%-d\t",Arr3D[k][i][j]);
        printf("\n");
        }
       printf("\n\n");

    }
}

void outvector(){ // функція для виведення вектору
for (i = 0; i< N*M; i++)
    printf("%d ",vec[i]);
}
/*
void DunamicMemoriesArray(){ // функція для динамічного виділенння пам`яті для масиву

    Arr3D = (int***) malloc(P*sizeof(int**));
       for (int k=0; k<P; k++)
            {   Arr3D[k] = (int**) malloc(M*sizeof(int*));
                for (int i=0; i<M; i++)
                Arr3D[k][i] = (int*) malloc(N*sizeof(int));
       }
}

void DunamicMemoriesVec(){// функція для динамічного виділенння пам`яті для вектору
     vec = (int*) malloc(M*N*sizeof(int));
}

void FreeDunamicMemoriesArray(){ //очищення віделеної пам`яті під масив
     for (int k=0; k<P; k++)
        {   for (int i=0; i<M; i++)
               free(Arr3D[k][i]);
        free(Arr3D[k]);
        }
        free(Arr3D);
}

void FreeDunamicMemoriesVec(){ // очищення виділеної пам`яті під вектор
    free(vec);
}
*/
