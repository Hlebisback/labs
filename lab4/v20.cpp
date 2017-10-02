/*
    ����������� ������ �4
    ������ 20

    �����: Oleksii Filonenko <filalex77@gmail.com>
*/


#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <ctime>
#include <clocale>
#include "v20.h"
using namespace std;


const int SIZE = 200;


void handleSequenceEnd(int &currentSequenceCount,
                       int &currentSequenceSum,
                       int &currentSequenceStart,
                       int &finalSequenceStart,
                       int &finalSequenceCount,
                       double &finalSequenceAverage,
                       double &currentSequenceAverage,
                       int i = -1) {
    if (currentSequenceCount > 1) {
        cout << "seq end";
        if (i != -1) {
            cout << " on " << i - 1;
        }
        cout << "\n";
        currentSequenceAverage = (double) abs(currentSequenceSum / currentSequenceCount);
        if (currentSequenceAverage > finalSequenceAverage && currentSequenceCount > finalSequenceCount) {
            finalSequenceStart = currentSequenceStart;
            finalSequenceCount = currentSequenceCount;
            finalSequenceAverage = currentSequenceAverage;
        }
        currentSequenceCount = currentSequenceStart = 0;
    }
}

int main() {
    /* ����������� */
    srand(time(0));

    int A[SIZE],
        currentSequenceSum   = 0,
        currentSequenceStart = 0,
        currentSequenceCount = 0,
        finalSequenceStart   = 0,
        finalSequenceCount   = 0;
    double currentSequenceAverage = 0,
           finalSequenceAverage   = 0;

    /* ���������� ������ */
    cout << "Array: ";
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 101 - 50;  // [-50; 50]
        cout << A[i] << ' ';
    }

    /* ������� ������ */
    cout << "\n\nSTART\n\n";

    for (int i = 1; i < SIZE; i++) {
        if (A[i] < 0 && A[i - 1] < 0) {
            /* ������� �� ���� ��������� ������� ��'��� */

                /* �������� ����������� */
                if (currentSequenceCount == 0) {  // ������� �����������
                    currentSequenceCount = 2;
                    currentSequenceStart = i - 1;
                    currentSequenceSum = A[i - 1] + A[i];
                    cout << "seq start on " << currentSequenceStart << "\n";
                } else {  // ����������� ��� ��������
                    currentSequenceCount++;
                    currentSequenceSum += A[i];
                }

        }
        
        else {
            /* ������� ����'�����: �������� � ���������� ����������� */
            handleSequenceEnd(currentSequenceCount, currentSequenceSum,
                              currentSequenceStart, finalSequenceStart,
                              finalSequenceCount, finalSequenceAverage,
                              currentSequenceAverage, i);
        }
    }

    /* ���������� ������� ������� ����������� */
    handleSequenceEnd(currentSequenceCount, currentSequenceSum,
                      currentSequenceStart, finalSequenceStart,
                      finalSequenceCount, finalSequenceAverage,
                      currentSequenceAverage);

    /* ʳ���� ������� ������, ���� ���������� */
    cout << "\nEND\n\nSeq: ";
    for (int i = finalSequenceStart; i < finalSequenceStart + finalSequenceCount; i++) {
        cout << A[i] << ' ';
    }
    cout << "\nAverage: " << -finalSequenceAverage << "\n";

    system("pause");
    return 0;
}