#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

#include <stdio.h>
// ���������  ������� ��� �������� ���`��
void DunamicMemoriesArray();
void DunamicMemoriesVec();
// ��������� ������� ��� �������� ���`��
void FreeDunamicMemoriesArray();
void FreeDunamicMemoriesVec();
// ��������� ������� ���������� ������ �� ���������
void inputmass(int mode);
void inputvector(int mode);
void outmass();
void outvector();
//����� ��� ���������� �������� ������
//int mode;

#endif // INOUT_H_INCLUDED
