#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED
#include "sorting.h"
#include "inout.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rejected_number 2// ������� ����� �� �� ����������
#define min_max_number 3 //������� ������������  � ��������� ������� ���� �� �� ��� �� ���������

#define measurements_number 28//������� �����

extern clock_t Res[measurements_number];//������ ��� ���� ��������������

//��������� ������� ���������� ��� ����� ���� ��� ����� ������ ������ �������� ����
void MeasurementSelect(int inout);
void Measurementselect1Arr3D(int inout);
void MeasurementInsertExchange(int inout);
void MeasurementInsertExchangeArr3D(int inout);
void MeasurementSelect4(int inout);
void Measurementselect4Arr3D(int inout);
 // ��������� ������� ������ ���������� �� ����� � ������ �������
void OutTable();
void OutResults(float ordered, float random, float backordered);
 // �������� ������� ��� ����� ��������� ������� ����
float MeasurementProcessing();
float AverageValue;//����� ��� �����`����������  ��������� ��������� ���� ������ ���������


#endif // MEASUREMENT_H_INCLUDED
