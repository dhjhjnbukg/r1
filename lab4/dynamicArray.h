#pragma once

#include <span>
//объявленик всех функций и структуры
struct DynamicArray
{
    int* values;
    int length;
    int capacity;
};


DynamicArray createDynamicArrayWithCapacity(int capacity);
DynamicArray createDynamicArrayWithDefaultCapacity();

void addElementToArray(DynamicArray* arr, int value);
int getElementAtIndex(const DynamicArray* arr, int index);
std::span<int> getCurrentSpan(const DynamicArray* arr);
void destroyMemory(DynamicArray* arr);