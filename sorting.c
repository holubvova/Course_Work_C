#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include <time.h>
#include "CommonVector.h"



clock_t select1(){ //���������� ������� ������� ������.
    int  Min, imin;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int S = 0; S <  N*M-1; S++){
        Min = vec[S]; imin = S;
        for(int i = S + 1; i <  N*M; i++ )
            if(vec[i]<Min){
                Min = vec[i];
                imin = i;
            }
        vec[imin] = vec[S];
        vec [S] = Min;

    }
    time_stop = clock();
      return P*(time_stop - time_start);
}


clock_t select1Arr3D(/* long int ***Arr3D*/){ //���������� 3-�������� ������ ������� ������� �������� �� ����������.

    clock_t time_start, time_stop;
    time_start = clock();

    int  Min; //  ����� ��� ����� ��� ������ ���������� �����.
    int  CurrentJmin, CurrentImin; // ���� ��� �����`���������� ������� ���������� �������� ��� �����.

    for( int k = 0; k < P; k++){ //
        for( int j = 0; j < N; j++){
            for( int i = 0; i < M; i++){
                //printf(" %d ", Arr3D[k][i][j]);

                 Min = Arr3D[k][i][j]; // �����`���������� ������� �������� �� ����������� �������, �� ����� ������� ����� �����
                 CurrentImin = i; // �����`���������� ��������� Min.
                 CurrentJmin = j;

                for (int z = i + 1 ; z < M; z++){ // ���� , ��  ���� ��������� ������� �� �������� �� ��������� ���������� ��������� �������
                    //printf(" %d |", Arr3D[k][z][j]);
                    if(Arr3D[k][z][j] < Min ){ //����� � ��������� ������� ����� �� Min.
                        Min = Arr3D[k][z][j]; // ��������� ����� Min ���������� ������ ����� , ���� ���� ����.
                        CurrentJmin = j; //�����`���������� ��������� ������ ���������� �����.
                        CurrentImin = z;
                    }
                }
                // ����� � �� ����������� ������ ������� ������ �� ����������� ����� �� ����� �������� ����������.
                for(int p = j+1; p < N; p++){
                    for( int d = 0; d < M; d++){
                        if(Arr3D[k][d][p] < Min ){ // ��������� ������ ���������� ��������� ����� �� ���������� ����� � ������� �������� ����������� �������.
                            Min = Arr3D[k][d][p];
                            CurrentJmin = p;
                            CurrentImin = d;
                        }
                    }
                }
            // ���� ���������� ��������� ���������� ������ ����� ���� � ������ ������������ ������ ������.
                Arr3D[k][CurrentImin][CurrentJmin] = Arr3D[k][i][j];
                Arr3D[k][i][j] = Min;
            }
        }

    }

    time_stop = clock();
    return time_stop - time_start;
}

clock_t InsertExchange(){

    int j, tmp;

    clock_t time_start, time_stop;
    time_start = clock();

    for(int i = 1; i <  N*M ; i++){
        j = i ;
        while ( j > 0 && vec[j] < vec[j-1]){
            tmp = vec[j] ;
            vec[j] = vec [j-1];
            vec[j-1] = tmp;
            j = j - 1;
        }
    }

    time_stop = clock();
    return P*(time_stop - time_start);

}

clock_t InsertExchangeArr3D(){

    int p, g, tmp, Count, start;// �������� ���� ��� ����� �����\��������� ��������

    clock_t time_start, time_stop; // ���� ��� ����� ���� ������ ���������
    time_start = clock(); // ������ ���� ������� ������ ���������

    for(int k = 0; k < P ;k++){ // ������� �� ��������

        for( int j = 0; j < N; j++){ //������� �� ����������

            int i = 0;

            if(j == 0){ // ����� ��� ������� ������ �� ���������� ������� ������� Arr3D[P,0,0]
                i = 1;
            }

            while (i < M){ // ������� �� ������
                    // ����� ���������� ��� �� �� ��������� ������� �� �� �������,1 - ������ �� g ��������� , 2- ������� � ��������� �� g-1 ��������� � �� 0 ���������.
                    // 1- �������
                for(g = j, p = i; p >= 0; p--){  // ����� ���������� �������� � j ���������

                    if((p==0) && (g!=0) && (Arr3D[k][p][g] < Arr3D[k][M-1][g-1] )){ // ����� �� �������� �� ������� ������� ����� �� 0-����� g -�� ���������, ��� ������� ���� � M-1 ��������� g-1 ��������� ���� �� ������� ������ �� ������.
                        tmp = Arr3D[k][p][g];
                        Arr3D[k][p][g] = Arr3D[k][M-1][g-1];
                        Arr3D[k][M-1][g-1] = tmp;
                    }else{
                        if((p!=0) && (Arr3D[k][p][g] < Arr3D[k][p-1][g])){ // ����� ��� �������� �� ������� � ������ �� �-1 � ��������� g ���� ���, ������.
                            tmp = Arr3D[k][p][g];
                            Arr3D[k][p][g] = Arr3D[k][p-1][g];
                            Arr3D[k][p-1][g] = tmp;
                        }
                    }
                }

                //  2- �������

                for(g = j-1; g >= 0; g--){         // ���� ���� ������ ����� ����������� �������� �������� ���� � ������� � ��� ����������� ����� ������, ��������� � g-1 ���������
                    for(p = M-1; p >= 0 ; p--){

                        if((p==0) && (g!=0) && (Arr3D[k][p][g] < Arr3D[k][M-1][g-1] )){  // ����� �� �������� �� ������� ������� ����� �� 0-����� g -�� ���������, ��� ������� ���� � M-1 ��������� g-1 ��������� ���� �� ������� ������ �� ������.
                            tmp = Arr3D[k][p][g];
                            Arr3D[k][p][g] = Arr3D[k][M-1][g-1];
                            Arr3D[k][M-1][g-1] = tmp;
                        }else{
                            if((p!=0) && (Arr3D[k][p][g] < Arr3D[k][p-1][g])){ // ����� ��� �������� �� ������� � ������ �� �-1 � ��������� g ���� ���, ������.
                                tmp = Arr3D[k][p][g];
                                Arr3D[k][p][g] = Arr3D[k][p-1][g];
                                Arr3D[k][p-1][g] = tmp;
                            }
                        }
                    }


                }
                i++;
            }
        }
    }

        time_stop = clock(); // ��� ���������� ������ ���������
        return P*(time_stop - time_start); // ���������� ���������� ���� ��������� ������ �������


}

clock_t Select4(){
    int L, R, imin, imax, tmp;

    L = 0 ;
    R = N*M - 1;

    clock_t time_start, time_stop;
    time_start = clock();

    while( L < R ){

        imin = L;
        imax = L;
        for(int i = L + 1; i < R + 1; i++){

            if( vec[i] < vec[imin] ) imin = i;
            else
                if(vec[i] > vec[imax]) imax = i;
        }


        tmp = vec[imin];
        vec[imin] = vec[L];
        vec[L] = tmp;
        if( imax == L){
            tmp = vec[imin];
            vec[imin] = vec[R];
            vec[R] = tmp;
        }else{
            tmp = vec[imax];
            vec[imax] = vec[R];
            vec[R] = tmp;
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

 clock_t select4Arr3D(){

    int imin, imax, jmin, jmax, tmp;
    imin = 0; imax = 0; jmax = 0; jmin = 0;
    int i, j;

    clock_t time_start, time_stop;
    time_start = clock();

    for (int k = 0; k < P; k++){
        for ( j = 0; j <= N/2; j++){
            for ( i = 0; i < M; i++){
                    // �� ��� ������ �� ���� �� ��������� ������� ������ , ������ ����� ��������� ������ �� � ���� ����� ���������� �����`������� ���� ���� �����������
                    //���� �� ���������� �� ���������� �� �� ������������ ���� ��� �� �����`������� ���� �������
                    //��� ������� �� ���� �������� ����� ���������� �� ����� � �����, ������ �� ���� ������������ ���� ����� � �� �� �������� �������� ��� ������
                imin = i;
                jmin = j;
                imax = i;
                jmax = j;
                    // �� ��������� ��� ����� �� ��� ������� 1- ������ �� j ���������, 2- ������� ��( p = j+1) p ��������� �� M-p-1, �� 3 -������ �� M - j -1;


                for(int g = i; (g < M) && (j != N-j-1) ; g++){ // ��������� �������� � �����`������� �������� � ����������� ���� ����������� � �������� j;

                    if( Arr3D[k][g][j] < Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = j;
                    }else
                        if(Arr3D[k][g][j] > Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = j;

                        }
                }

                for(int p = j+1; j < N - p - 1; p++){ //��������� �������� � �����`������� �������� � ����������� ���� ����������� � ����� �������
                    for(int g = 0; g < M; g++){
                        if( Arr3D[k][g][p] < Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = p;
                    }else
                        if(Arr3D[k][g][p] > Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = p;

                        }
                    }
                }

                for ( int g=0; (g < M-i) && (j != N-j-1);  g++ ){  // ��������� �������� � �����`������� �������� � ����������� ���� ����������� � �������� g;

                    if( Arr3D[k][g][N-j-1] < Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = N-j-1;
                    }else
                        if(Arr3D[k][g][N-j-1] > Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = N-j-1;

                        }
                }

                for(int g = i; (g < M-i) && (j == N-j-1 ); g++){ // ������ ���� ���� ��������� ���� ������ ����� � �������� ������� ��������
                                                                 // ��������� �������� � �����\������� �������� � ����������� ���� ����������� � �������� j;

                  if( Arr3D[k][g][j] > Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = j;
                    }else
                        if(Arr3D[k][g][j] < Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = j;

                        }

                }
// ���� ���������� � ������������ �������� � ������ � ������� ��������
                tmp = Arr3D[k][imin][jmin];
                Arr3D[k][imin][jmin] = Arr3D[k][i][j];
                Arr3D[k][i][j] = tmp;

                if((imax == i)&&(jmax == j)){
                    tmp = Arr3D[k][imin][jmin];
                    Arr3D[k][imin][jmin] = Arr3D[k][M-1-i][N-1-j];
                    Arr3D[k][M-1-i][N-1-j] = tmp;
                }else{
                    tmp = Arr3D[k][imax][jmax];
                    Arr3D[k][imax][jmax] = Arr3D[k][M-1-i][N-1-j];
                    Arr3D[k][M-1-i][N-1-j] = tmp;
                }
            }
        }
    }
     time_stop = clock();
     return time_stop - time_start;

}
