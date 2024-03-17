#include "ExtendedArray.h"
using namespace std;
ExtendedArray::ExtendedArray(int arrL)
{
    this->numArray = new int[arrL];
    this->arrayLen = arrL;
}

int ExtendedArray::getAt(int i)
{
    if(i < this->itemCount && i >=0){
        return this->numArray[i];
    }
    cout << "Wrong index" << endl;
    return 0;
}


void ExtendedArray::setAt(int att) {
    if (this->itemCount >= this->arrayLen) {
        int newLen = this->arrayLen * 2;
        int* newArray = new int[newLen];

        for (int i = 0; i < this->itemCount; ++i) {
            newArray[i] = this->numArray[i];
        }
        
        newArray[this->itemCount] = att;
        this->itemCount++;

        delete[] this->numArray;
        
        this->arrayLen = newLen;
        this->numArray = newArray;
    } else {
        this->numArray[this->itemCount] = att;
        this->itemCount++;
    }
}

void ExtendedArray::printArr()
{
    for (int i = 0; i < this->getCount(); i++) {
        cout << this->getAt(i) << " ";
    }
    cout << endl;
    return;
}

ExtendedArray *ExtendedArray::merge(ExtendedArray *array)
{
    int newLen = array->itemCount + this->itemCount;
    ExtendedArray * newArray = new ExtendedArray(newLen);

    for(int i = 0;i<this->itemCount;i++){
        newArray->setAt(this->numArray[i]);
    }

    for(int i = 0;i<array->itemCount;i++){
        newArray->setAt(array->numArray[i]);
    }


    return newArray;
}

ExtendedArray *ExtendedArray::intersect(ExtendedArray *array)
{
    bool isLonger = array->itemCount > this->itemCount;
    int newLen = isLonger ? this->itemCount:array->itemCount;
    int longerArr = isLonger ? array->itemCount:this->itemCount;
    ExtendedArray * newArray = new ExtendedArray(newLen);

    int * sharedItems = new int[newLen];

    for(int i = 0;i<newLen;i++){
        for(int j = 0;j<longerArr;j++){
                if(this->numArray[i] == array->numArray[j]){
                    newArray->setAt(this->numArray[i]);
                    break;
                }
        }
    }


    return newArray;
}

void ExtendedArray::fillWithRandomNumbers(int min, int max)
{
    std::vector<int> numbers;
    for (int i = min; i <= max; ++i) {
        numbers.push_back(i);
    }

    // Shuffle the sequence
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    for (int i = 0; i < this->arrayLen; ++i) {
        this->setAt(numbers[i]);
    }
}



int ExtendedArray::getCount()
{
    return this->itemCount;
}

ExtendedArray::~ExtendedArray()
{

}