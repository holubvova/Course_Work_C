#include <stdio.h> // ���������� �������� ����� / ������
#include "CommonVector.h" // ���������� ������ � ����������� ��������� ����������� �� �����
#include "menu.h"// ����������� ����������� �������
#include "Sorting.h" // ��������� ������ ����������
#include "Measurement.h" // ���������� ������ ����������� ����
#include "inout.h"
// ������� ��� ���������� ������ �� ������� ����� �������
void TestSelect1Vec(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N); // ���������� �� ����� ������ ������
    printf("test select1 (ordered, vector)\n"); //���� �� ����� ����� ���������� ������
    inputvector(1);
    outvector();
    select1();
    printf("\nsorting:\n"); // ������������� �� ����������� ������� � �� �����������
    outvector();
    printf("\ntest select1 (random, vector)\n"); // ���� �� ����� ����� ���������� ������
    inputvector(2);
    outvector();
    select1();
    printf("\nsorting:\n"); // ������������ �� ����������� � �� ������������ �������
    outvector();
    printf("\ntest select1 (backordered, vector)\n"); // ���� �� ���� ����� ��������� ������
    inputvector(3);
    outvector();
    select1();
    printf("\nsorting:\n"); // ������������ �� �����������  � �� ����������� �������� ������
    outvector();

}

void TestInsertExchangeVec(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
    printf("test InsertExchange (ordered, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(1);
    outvector();
    InsertExchange();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();
    printf("\ntest InsertExchange (random, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(2);
    outvector();
    InsertExchange();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();
    printf("\ntest InsertExchange (backordered, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(3);
    outvector();
    InsertExchange();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();

}
void TestSelect4Vec(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
    printf("test Select4 (ordered, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(1);
    outvector();
    Select4();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();
    printf("\nSelect4 (random, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(2);
    outvector();
    Select4();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();
    printf("\nSelect4 (backordered, vector)\n");// ���� �� ����� ����� ���������� ������
    inputvector(3);
    outvector();
    Select4();
    printf("\nsorting:\n");// ������������� �� ����������� ������� � �� �����������
    outvector();

}

void TestSelect1Array(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
    printf("test Select1 (ordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(1);
    outmass();
    select1Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test Select1 (random, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(2);
    outmass();
    select1Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test Select1 (backordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(3);
    outmass();
    select1Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();

}
void TestSelect4Array(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
    printf("test Select4 (ordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(1);
    outmass();
    select4Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test Select4 (random, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(2);
    outmass();
    select4Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test Select4 (backordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(3);
    outmass();
    select4Arr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();

}

void TestInsertExchangeArray(){

    printf("Sizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
    printf("test InsertExchange (ordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(1);
    outmass();
    InsertExchangeArr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test InsertExchange (random, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(2);
    outmass();
    InsertExchangeArr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();
    printf("test InsertExchange (backordered, array)\n");// ���� �� ����� ����� ���������� ������
    inputmass(3);
    outmass();
    InsertExchangeArr3D();
    printf("\nAfter sorting :\n");// ������������� �� ����������� ������� � �� �����������
    outmass();

}

void timemeasurement() {//����� ����� ���� � ����

	do {
	system("cls");
	int mode;
	printf("Time measurement\nSizes of array: P=%d M=%d N=%d\n",P,M,N);// ���������� �� ����� ������ ������
	printf("\nChoose sorting:\n");
	printf("1.Select1(vector)\n2.InsertExchange(vector)\n");
	printf("3. Select4 (vector)\n4. select1(array)\n");
	printf("5.InsertExchange(array)\n6.Select4(array)\n");
	printf("7.Pack mode(vector)\n8.Pack mode(array)\n");
	printf("\nPlease input the number of menu(0-back):");
	scanf("%d", &mode);
	switch (mode)//���� ������ ����
	{

		case 0: return; break;
		case 1:{

			system("cls");
            printf("Select1(vector)\n"); // ���� �� ����� ����� ���������
			OutTable();
            MeasurementSelect(1);
			ordered = MeasurementProcessing();
			MeasurementSelect(2);
            random = MeasurementProcessing();
            MeasurementSelect(3);
            backordered = MeasurementProcessing();
            OutResults(ordered,random,backordered);
			printf("\nPress Enter for back");
			_getch();

			break;}
        case 2:{

			system("cls");
			 printf("InsertExchange(vector)\n"); // ���� �� ����� ����� ���������
			OutTable();
			MeasurementInsertExchange(1);
			ordered = MeasurementProcessing();
			MeasurementInsertExchange(2);
            random = MeasurementProcessing();
            MeasurementInsertExchange(3);
            backordered = MeasurementProcessing();
			OutResults(ordered,random,backordered);
			printf("\nPress Enter for back");
			_getch();

			break;}
		case 3:{

			system("cls");
			  printf("Select4(vector)\n");// ���� �� ����� ����� ���������
			OutTable();
			MeasurementSelect4(1);
			ordered = MeasurementProcessing();
			MeasurementSelect4(2);
            random = MeasurementProcessing();
            MeasurementSelect4(3);
            backordered = MeasurementProcessing();
            OutResults(ordered,random,backordered);
			printf("\nPress Enter for back");
			_getch();

			break;}
        case 4:{

			system("cls");
			 printf("Select11(array)\n");// ���� �� ����� ����� ���������
			OutTable();
			Measurementselect1Arr3D(1);
			ordered = MeasurementProcessing();
			Measurementselect1Arr3D(2);
            random = MeasurementProcessing();
            Measurementselect1Arr3D(3);
            backordered = MeasurementProcessing();
            OutResults(ordered,random,backordered);
			printf("\nPress Enter for back");
			_getch();

			break;}
        case 5:{

			system("cls");
			 printf("InsertExchange(array)\n");// ���� �� ����� ����� ���������
			OutTable();
			MeasurementInsertExchangeArr3D(1);
			ordered = MeasurementProcessing();
			MeasurementInsertExchangeArr3D(2);
            random = MeasurementProcessing();
            MeasurementInsertExchangeArr3D(3);
            backordered = MeasurementProcessing();
            OutResults(ordered,random,backordered);
			printf("\nPress Enter for back");
			_getch();

			break;}
        case 6:{

            system("cls");
             printf("Select4(array)\n");// ���� �� ����� ����� ���������
            OutTable();
            Measurementselect4Arr3D(1);
            ordered = MeasurementProcessing();
            Measurementselect4Arr3D(2);
            random = MeasurementProcessing();
            Measurementselect4Arr3D(3);
            backordered = MeasurementProcessing();
            OutResults(ordered,random,backordered);
            printf("\nPress Enter for back");
            _getch();

            break;
        }
        case 7 :{

            printf("\t\t");
            OutTable();
            printf("Select1(vector)");// ���� �� ����� ����� ���������
            MeasurementSelect(1);
			ordered = MeasurementProcessing();
			MeasurementSelect(2);
            random = MeasurementProcessing();
            MeasurementSelect(3);
            backordered = MeasurementProcessing();
               printf("\t");
            OutResults(ordered,random,backordered);
            printf("InsertExchange(vector)");// ���� �� ����� ����� ���������
            MeasurementInsertExchange(1);
			ordered = MeasurementProcessing();
			MeasurementInsertExchange(2);
            random = MeasurementProcessing();
            MeasurementInsertExchange(3);
            backordered = MeasurementProcessing();

			OutResults(ordered,random,backordered);
            printf("Select4(vector)");// ���� �� ����� ����� ���������
            MeasurementSelect4(1);
			ordered = MeasurementProcessing();
			MeasurementSelect4(2);
            random = MeasurementProcessing();
            MeasurementSelect4(3);
            backordered = MeasurementProcessing();
            printf("\t");
            OutResults(ordered,random,backordered);
            _getch();

            break;
        }
        case 8:{
            srand(time(NULL));
            printf("\t\t");
            OutTable();
            Measurementselect1Arr3D(1);
			ordered = MeasurementProcessing();
			Measurementselect1Arr3D(2);
            random = MeasurementProcessing();
            Measurementselect1Arr3D(3);
            backordered = MeasurementProcessing();
            printf("Select1(array)");// ���� �� ����� ����� ���������
             printf("\t");
            OutResults(ordered,random,backordered);

			MeasurementInsertExchangeArr3D(1);
			ordered = MeasurementProcessing();
			MeasurementInsertExchangeArr3D(2);
            random = MeasurementProcessing();
            MeasurementInsertExchangeArr3D(3);
            backordered = MeasurementProcessing();
            printf("InsertExchange(array)");// ���� �� ����� ����� ���������
            OutResults(ordered,random,backordered);

            Measurementselect4Arr3D(1);
            ordered = MeasurementProcessing();
            Measurementselect4Arr3D(2);
            random = MeasurementProcessing();
            Measurementselect4Arr3D(3);
            backordered = MeasurementProcessing();
             printf("Select4(array)");// ���� �� ����� ����� ���������
              printf("\t");
            OutResults(ordered,random,backordered);

            _getch();_getch();

            break;
        }
		default:{
		printf("Please input CORRECT number (Enter)");
		_getch();
		break;}
		}
	} while (1);
}

void testsorting() {//����� ���� ��� ���������� ���������� � ������ ���� �� �����
	do {
		system("cls");
		int mode;
	printf("Test sortings\nSizes of array: P=%d M=%d N=%d\n",P,M,N);
	printf("\nChoose sorting:\n");
	printf("1.Select1(vector)\n2.InsertExchange(vector)\n");
	printf("3. Select4 (vector)\n4. select1(array)\n");
	printf("5.InsertExchange(array)\n6.Select4(array)\n");
    printf("\nPlease input the number of menu(0-back):");
        scanf("%d", &mode);
        switch (mode)//���� ���� ����������
		{
		case 0: return; break;
		case 1:
			TestSelect1Vec();
			_getch();
			break;
		case 2:
			TestInsertExchangeVec();
			_getch();
			break;
		case 3:
			TestSelect4Vec();
			_getch();
			break;
		case 4:
			TestSelect1Array();
			_getch();
			break;
		case 5:
			TestInsertExchangeArray();
			_getch();
			break;
		case 6:
			TestSelect4Array();
			_getch();
			break;

		default:
			printf("Please input CORRECT number (Enter)");
			_getch();
			break;
		}
	} while (1);
}

void menu(){//���� � ������� ���������� ���� � ���������� ���������
	do {
	system("cls");
	printf("Course work #146\n\n");
	printf("Choose mode:\n1- time measurement\n");
    printf("2-testing sorting\n3-exit:\n");
	int vote;
		scanf("%d", &vote);
		switch (vote)//���� ������ � ���� ������
		{
		case 1: timemeasurement(); break;
		case 2: testsorting(); break;
		case 3: return;
		default:
			printf("Please input CORRECT number (Press Enter)");
			_getch();
			break;
		}
	} while (1);
}

