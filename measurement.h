#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
#include "sorting.h"
#include "inout.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rejected_number 2// кількість вимірів які ми неврахоуємо
#define min_max_number 3 //кількість максимальних  і мінімальних значень часу які ми теж не враховуємо

#define measurements_number 28//кількість вимірів

extern clock_t Res[measurements_number];//вектор для часів впорядкованого

//прототипи функції сортування для виміру часу щоб надалі знайти середнє значення часу
void MeasurementSelect(int inout);
void Measurementselect1Arr3D(int inout);
void MeasurementInsertExchange(int inout);
void MeasurementInsertExchangeArr3D(int inout);
void MeasurementSelect4(int inout);
void Measurementselect4Arr3D(int inout);
 // прототипи функцій виводу результатів на екран у вигляді таблиці
void OutTable();
void OutResults(float ordered, float random, float backordered);
 // прототип функції для виміру середього значеня часу
float MeasurementProcessing();
float AverageValue;//змінна для запам`ятовування  середньог значенння часу роботи алгоритму


#endif // MEASUREMENT_H_INCLUDED
