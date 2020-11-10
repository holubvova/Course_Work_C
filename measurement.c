#include "measurement.h" // підключення інтерфейсної частини
#include "inout.h" // підключення інтерфейсної частини для доступу джо заповненя масиву
#define measurements_number 28 // кількість запусків обробки алгоритмів для знацденння середнього значення

#define rejected_number 2 // кількість вимірів які ми не враховуємо при обчислення середньоггтзначенння часу
#define min_max_number 3 // кількість вимірів які ми не враховуємо при обчисленні середнього значенння часу

int inout; // змінна  для визначення запуску конкретного алгритма з конкретним заповннням

clock_t Res[measurements_number]; // масив для збереження часу кожного з вимірів
// функції визначенння часу роботи коджного алгоритмак за різними випадками відсортованості

void MeasurementSelect(int inout){
    for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputvector(1); // заповнення впорядковано
        Res[i] = select1(); // запис результату до масиву
        break;}
        case 2:{
        inputvector(2); //заповнення невпорядковано
        Res[i] = select1(); // запис результату до масиву значень
        break; }
        case 3:{
        inputvector(3);//заповнення обернено-відсортовано
        Res[i] = select1();//запис результату до масиву значень
        break;

        }
    }
}
}

void Measurementselect1Arr3D(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputmass(1); // заповнення впорядковано
        Res[i] = select1Arr3D(); // запис результатів до масиву значень
        break;}
        case 2:{
        inputmass(2);// заповнення невпорядкованого масиву

        Res[i] = select1Arr3D(); // запис результатів до масиву значень
        break; }
        case 3:{
        inputmass(3); // заповнення обернено-відсортовано
        Res[i] = select1Arr3D(); // запис резульатів до масиву значень
        break;

        }
    }
}
}
void  MeasurementInsertExchange(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputvector(1); // заповнення відсортоване
        Res[i] = InsertExchange();
        break;}
        case 2:{
        inputvector(2); // заповнення невідсортоване
        Res[i] = InsertExchange();
        break; }
        case 3:{
        inputvector(3); // заповнення обернено-відсортовано
        Res[i] = InsertExchange();
        break;
        }
       }
}
}

void MeasurementInsertExchangeArr3D(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputmass(1); // заповнення відсотоване
        Res[i] = InsertExchangeArr3D();
        break;}
        case 2:{
        inputmass(2); // заповнення невідсортоване
        Res[i] = InsertExchangeArr3D();
        break; }
        case 3:{
        inputmass(3); // заповнення обернено-відсортоване
        Res[i] = InsertExchangeArr3D();
        break;

            }
        }
    }
}

void  MeasurementSelect4(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputvector(1); // заповнення відсортоване
        Res[i] =  Select4();
        break;}
        case 2:{
        inputvector(2); // заповнення невідсортоване
        Res[i] = Select4();
        break; }
        case 3:{
        inputvector(3); // заповненння обернено- відсортоване
        Res[i] =  Select4();
        break;
            }
        }
    }
}
void  Measurementselect4Arr3D(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputmass(1); // заповнення відсортоване
        Res[i] = select4Arr3D();
        break;}
        case 2:{
        inputmass(2); // заповнення невідсотоване
        Res[i] = select4Arr3D();
        break; }
        case 3:{
        inputmass(3); // заповнення оберненно-відсортоване
        Res[i] = select4Arr3D();
        break;
            }
        }
    }
}


// функція для визначення середнього значенння часу робити кожного алгоритма

float MeasurementProcessing(){
    long int  Sum;
    AverageValue = 0;
    clock_t buf;
	int L = rejected_number, R = measurements_number - 1;
	int k = rejected_number;
	for (int j=0; j < min_max_number; j++) {
		for (int i = L; i < R; i++)	{
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		R = k;
		for (int i = R - 1; i >= L; i--) {
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		L = k + 1;
	}


    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
           Sum = Sum + Res[i];
    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);


/* !!!!! Пустий printf потрібен для правильного повернення результату */
    printf("");
/* !!!!! */
    printf("",AverageValue);//printf потрібен для правильного повернення результату
    return AverageValue;
}

void OutTable()
{
// Усереднений результат вимірів буде виведено на екран у портібну позицію
    printf("\t Ordered \t Random \t BackOrdered \n");}

void OutResults(float ord, float rand, float backord){//процедура виводу результатів на екран
    printf("\t %7.2f \t %7.2f \t %7.2f \n",ord , rand ,backord);
    printf("\n\n");
}




