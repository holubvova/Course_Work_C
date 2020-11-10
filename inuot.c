#include "inout.h" // ���������� ����������� �������
#include <stdio.h> // ���������� �������� �����/������
#include "CommonVector.h" // ���������� ����������� ������� ��� ������� �� ���������� ������

int number; // ����� ��� ���������� ������
int i, j, k; // ���� ��� �����
 // ������� ���� ������ ������� �� ����������
void inputmass(int mode){
    switch (mode){
    number = 0;
    case 1: // ������������ �����

        for (k = 0; k < P; k++ )
            for(i = 0; i < N; i++)
                for (j = 0; j < M; j++)
                    Arr3D[k][j][i] = number++;

    break;

    case 2:{ // random �����
        for (k = 0; k < P; k++ )
            for(j = 0; j < M; j++)
                for (i = 0; i < N; i++)
                    Arr3D[k][j][i] =  rand() % (P*M*N);
    break;
    }
    case 3:{ // ��������-������������
        number = P*N*M;
        for (k = 0; k < P; k++ )
            for(i = 0; i < N; i++)
                for (j = 0; j < M; j++)
                Arr3D[k][j][i] = number--;
    break;
    }
    }
}
 // ������� �������� �������� ��������� �� �������
void inputvector(mode){
    switch(mode){

        case 1:{ // ����������� ����������
            number = 0;
        for(i = 0; i < N*M; i++)
            vec[i] = number++;
        break;
        }
        case 2:{ // random ����������
        for(i = 0; i < N*M; i++)
            vec[i] =  rand() % (M*N);
        break;
        }
        case 3:{ // ��������-����������� ����������
            number = N*M;
        for(i = 0; i < N*M; i++)
            vec[i] = number--;
        break;
        }
}
}

void outmass(){ // ������� ��� ������ ������������� ������
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

void outvector(){ // ������� ��� ��������� �������
for (i = 0; i< N*M; i++)
    printf("%d ",vec[i]);
}
/*
void DunamicMemoriesArray(){ // ������� ��� ���������� ��������� ���`�� ��� ������

    Arr3D = (int***) malloc(P*sizeof(int**));
       for (int k=0; k<P; k++)
            {   Arr3D[k] = (int**) malloc(M*sizeof(int*));
                for (int i=0; i<M; i++)
                Arr3D[k][i] = (int*) malloc(N*sizeof(int));
       }
}

void DunamicMemoriesVec(){// ������� ��� ���������� ��������� ���`�� ��� �������
     vec = (int*) malloc(M*N*sizeof(int));
}

void FreeDunamicMemoriesArray(){ //�������� ������� ���`�� �� �����
     for (int k=0; k<P; k++)
        {   for (int i=0; i<M; i++)
               free(Arr3D[k][i]);
        free(Arr3D[k]);
        }
        free(Arr3D);
}

void FreeDunamicMemoriesVec(){ // �������� ������� ���`�� �� ������
    free(vec);
}
*/
