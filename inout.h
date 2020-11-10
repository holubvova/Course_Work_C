#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

#include <stdio.h>
// прототипи  функції для виділення пам`яті
void DunamicMemoriesArray();
void DunamicMemoriesVec();
// прототипи функції для очищення пам`яті
void FreeDunamicMemoriesArray();
void FreeDunamicMemoriesVec();
// прототипи функції заповнення масиву та виведення
void inputmass(int mode);
void inputvector(int mode);
void outmass();
void outvector();
//змінна для визначення запоення масиву
//int mode;

#endif // INOUT_H_INCLUDED
