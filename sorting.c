#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include <time.h>
#include "CommonVector.h"



clock_t select1(){ //Сортування вектора методом вибору.
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


clock_t select1Arr3D(/* long int ***Arr3D*/){ //Сортування 3-вимірного масиву методом вставки наскірзно по стовпчиках.

    clock_t time_start, time_stop;
    time_start = clock();

    int  Min; //  Змінна яка слугує для пошуку мінімального числа.
    int  CurrentJmin, CurrentImin; // змінні для запам`ятовування індексів мінімального елемента для обміну.

    for( int k = 0; k < P; k++){ //
        for( int j = 0; j < N; j++){
            for( int i = 0; i < M; i++){
                //printf(" %d ", Arr3D[k][i][j]);

                 Min = Arr3D[k][i][j]; // запам`ятовування першого елемента не відсортованої частини, та пошук меншого серед інших
                 CurrentImin = i; // запам`ятовування координат Min.
                 CurrentJmin = j;

                for (int z = i + 1 ; z < M; z++){ // цикл , що  шукає мінімальний елемент по стовчику де знаходить тимчасовий мінімальний елемент
                    //printf(" %d |", Arr3D[k][z][j]);
                    if(Arr3D[k][z][j] < Min ){ //пошук в стовпчику меншого числа за Min.
                        Min = Arr3D[k][z][j]; // перезапис числа Min знайденого меншог числа , якщо таке існує.
                        CurrentJmin = j; //запам`ятовування координат нового мнімального числа.
                        CurrentImin = z;
                    }
                }
                // пошук у не відсортованій частині матриці нового ще мінімальнішого чилса ніж булдо знайдено попередньо.
                for(int p = j+1; p < N; p++){
                    for( int d = 0; d < M; d++){
                        if(Arr3D[k][d][p] < Min ){ // перезапис нового знайденого мінімальног числа дл яопдальшго обміну з останнім елеметом відсортованої частини.
                            Min = Arr3D[k][d][p];
                            CurrentJmin = p;
                            CurrentImin = d;
                        }
                    }
                }
            // обмін знайденого наменшого мінмального числаб запис його в останнє відстортовану комірку масиву.
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

    int p, g, tmp, Count, start;// додаткові змінні для обміну запам\товування елементів

    clock_t time_start, time_stop; // змінні для виміру часу роботи алгоритму
    time_start = clock(); // починає відлік початку роботи алгоритму

    for(int k = 0; k < P ;k++){ // перехід по перерізах

        for( int j = 0; j < N; j++){ //перехід по стовпчиках

            int i = 0;

            if(j == 0){ // умова для початку пошуку не враховуючі елемент матриці Arr3D[P,0,0]
                i = 1;
            }

            while (i < M){ // перехід по рядках
                    // пошук відбувається так що ми розділяємо матрицю на дві частини,1 - вектор по g стовпчику , 2- матриця з починаючи від g-1 стовпчика і до 0 стовпчика.
                    // 1- частина
                for(g = j, p = i; p >= 0; p--){  // пошук мнімального елемента в j стовпчику

                    if((p==0) && (g!=0) && (Arr3D[k][p][g] < Arr3D[k][M-1][g-1] )){ // умова що перевіряє чи обраний елемент стоїть на 0-рядку g -го стовпчика, для порівння його з M-1 елементом g-1 стовпчика якщо він менеший міняємо їх місцями.
                        tmp = Arr3D[k][p][g];
                        Arr3D[k][p][g] = Arr3D[k][M-1][g-1];
                        Arr3D[k][M-1][g-1] = tmp;
                    }else{
                        if((p!=0) && (Arr3D[k][p][g] < Arr3D[k][p-1][g])){ // умова яка перевіряє чи елемент р менший ніж р-1 у стовпчику g якщо так, міняємо.
                            tmp = Arr3D[k][p][g];
                            Arr3D[k][p][g] = Arr3D[k][p-1][g];
                            Arr3D[k][p-1][g] = tmp;
                        }
                    }
                }

                //  2- частина

                for(g = j-1; g >= 0; g--){         // цикл який робить пошук менімального елемента порівнючи його з обраним у уже відсортованій чатині масиву, починаючи з g-1 стовпчика
                    for(p = M-1; p >= 0 ; p--){

                        if((p==0) && (g!=0) && (Arr3D[k][p][g] < Arr3D[k][M-1][g-1] )){  // умова що перевіряє чи обраний елемент стоїть на 0-рядку g -го стовпчика, для порівння його з M-1 елементом g-1 стовпчика якщо він менеший міняємо їх місцями.
                            tmp = Arr3D[k][p][g];
                            Arr3D[k][p][g] = Arr3D[k][M-1][g-1];
                            Arr3D[k][M-1][g-1] = tmp;
                        }else{
                            if((p!=0) && (Arr3D[k][p][g] < Arr3D[k][p-1][g])){ // умова яка перевіряє чи елемент р менший ніж р-1 у стовпчику g якщо так, міняємо.
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

        time_stop = clock(); // час завершення роботи алгоритму
        return P*(time_stop - time_start); // повернення результату після закінчення роботи функції


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
                    // під час пошуку ми бере за мінімальний елемент перший , шукаємо серед наступних менший ніж є якщо умова виконується запам`ятовуємо його місце знаходження
                    //якщо не виконується ми перевіряємо чи він максимальний якщо так ти запам`ятовуємо його позицію
                    //при переході на нову ітерацію цикла повторюємо це знову і знову, допоки не буде відсортований весь масив і всі не пройдуть ітерації всіх циклівю
                imin = i;
                jmin = j;
                imax = i;
                jmax = j;
                    // ми розділяємо наш масив на три частини 1- вектор по j стовпчику, 2- матриця від( p = j+1) p стовпчика до M-p-1, та 3 -вектор по M - j -1;


                for(int g = i; (g < M) && (j != N-j-1) ; g++){ // порівнюємо елементи і запам`ятовуємо мінімальне і максимальне місце знаходження у стопчику j;

                    if( Arr3D[k][g][j] < Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = j;
                    }else
                        if(Arr3D[k][g][j] > Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = j;

                        }
                }

                for(int p = j+1; j < N - p - 1; p++){ //порівнюємо елементи і запам`ятовуємо мінімальне і максимальне місце знаходження в данній матриці
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

                for ( int g=0; (g < M-i) && (j != N-j-1);  g++ ){  // порівнюємо елементи і запам`ятовуємо мінімальне і максимальне місце знаходження у стопчику g;

                    if( Arr3D[k][g][N-j-1] < Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = N-j-1;
                    }else
                        if(Arr3D[k][g][N-j-1] > Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = N-j-1;

                        }
                }

                for(int g = i; (g < M-i) && (j == N-j-1 ); g++){ // данний цикл буде працювати якщо задано масив з непарною кількістю стовпців
                                                                 // порівнюємо елементи і запам\ятовуємо мінімальне і максимальне місце знаходження у стопчику j;

                  if( Arr3D[k][g][j] > Arr3D[k][imin][jmin] ){

                        imin = g;
                        jmin = j;
                    }else
                        if(Arr3D[k][g][j] < Arr3D[k][imax][jmax]){
                        imax = g;
                        jmax = j;

                        }

                }
// обмін мінімального і максимальног елемента з першим і останнім відповідно
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
