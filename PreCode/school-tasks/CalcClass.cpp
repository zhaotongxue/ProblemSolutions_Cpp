#include "CalcClass.h"

 double CalcClass::calcMidNum(double intArray[]){
	double temp=0;
	for (int i = 0; i < 6;i++){// sizeof(intArray) / sizeof(double); i++) {
		for (int j = 0; j < i; j++) {
			if (intArray[i] > intArray[j]) {
				temp = intArray[i];
				intArray[i] = intArray[j];
				intArray[j] = temp;
			}
		}
	}
	return (intArray[3] + intArray[2]) / 2;
}
