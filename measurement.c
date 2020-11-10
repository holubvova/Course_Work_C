#include "measurement.h" // ���������� ����������� �������
#include "inout.h" // ���������� ����������� ������� ��� ������� ��� ��������� ������
#define measurements_number 28 // ������� ������� ������� ��������� ��� ���������� ���������� ��������

#define rejected_number 2 // ������� ����� �� �� �� ��������� ��� ���������� �������������������� ����
#define min_max_number 3 // ������� ����� �� �� �� ��������� ��� ��������� ���������� ��������� ����

int inout; // �����  ��� ���������� ������� ����������� �������� � ���������� ����������

clock_t Res[measurements_number]; // ����� ��� ���������� ���� ������� � �����
// ������� ����������� ���� ������ �������� ���������� �� ������ ��������� �������������

void MeasurementSelect(int inout){
    for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputvector(1); // ���������� ������������
        Res[i] = select1(); // ����� ���������� �� ������
        break;}
        case 2:{
        inputvector(2); //���������� ��������������
        Res[i] = select1(); // ����� ���������� �� ������ �������
        break; }
        case 3:{
        inputvector(3);//���������� ��������-�����������
        Res[i] = select1();//����� ���������� �� ������ �������
        break;

        }
    }
}
}

void Measurementselect1Arr3D(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputmass(1); // ���������� ������������
        Res[i] = select1Arr3D(); // ����� ���������� �� ������ �������
        break;}
        case 2:{
        inputmass(2);// ���������� ���������������� ������

        Res[i] = select1Arr3D(); // ����� ���������� �� ������ �������
        break; }
        case 3:{
        inputmass(3); // ���������� ��������-�����������
        Res[i] = select1Arr3D(); // ����� ��������� �� ������ �������
        break;

        }
    }
}
}
void  MeasurementInsertExchange(int inout){
     for ( int i = 0; i < measurements_number; i++){
        switch (inout) {
        case 1 :{
        inputvector(1); // ���������� �����������
        Res[i] = InsertExchange();
        break;}
        case 2:{
        inputvector(2); // ���������� �������������
        Res[i] = InsertExchange();
        break; }
        case 3:{
        inputvector(3); // ���������� ��������-�����������
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
        inputmass(1); // ���������� ����������
        Res[i] = InsertExchangeArr3D();
        break;}
        case 2:{
        inputmass(2); // ���������� �������������
        Res[i] = InsertExchangeArr3D();
        break; }
        case 3:{
        inputmass(3); // ���������� ��������-�����������
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
        inputvector(1); // ���������� �����������
        Res[i] =  Select4();
        break;}
        case 2:{
        inputvector(2); // ���������� �������������
        Res[i] = Select4();
        break; }
        case 3:{
        inputvector(3); // ����������� ��������- �����������
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
        inputmass(1); // ���������� �����������
        Res[i] = select4Arr3D();
        break;}
        case 2:{
        inputmass(2); // ���������� ������������
        Res[i] = select4Arr3D();
        break; }
        case 3:{
        inputmass(3); // ���������� ���������-�����������
        Res[i] = select4Arr3D();
        break;
            }
        }
    }
}


// ������� ��� ���������� ���������� ��������� ���� ������ ������� ���������

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


/* !!!!! ������ printf ������� ��� ����������� ���������� ���������� */
    printf("");
/* !!!!! */
    printf("",AverageValue);//printf ������� ��� ����������� ���������� ����������
    return AverageValue;
}

void OutTable()
{
// ����������� ��������� ����� ���� �������� �� ����� � ������� �������
    printf("\t Ordered \t Random \t BackOrdered \n");}

void OutResults(float ord, float rand, float backord){//��������� ������ ���������� �� �����
    printf("\t %7.2f \t %7.2f \t %7.2f \n",ord , rand ,backord);
    printf("\n\n");
}




