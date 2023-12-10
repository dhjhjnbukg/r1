#include "dynamicArray.h"
#include <cassert>
#include <span>

//создание динамического массива
DynamicArray createDynamicArrayWithCapacity(int capacity)
{
    DynamicArray newArray;
    newArray.values = new int[capacity];
    newArray.length = 0;
    newArray.capacity = capacity;
    return newArray;
}

//создание динамического массива с дефолтной размерностью
DynamicArray createDynamicArrayWithDefaultCapacity()
{
    return createDynamicArrayWithCapacity(4);
}

//добавление элементов, увеличивая размер если надо
void addElementToArray(DynamicArray* arr, int value)
{
    if (arr->length + 1 >= arr->capacity)
    {
        arr->capacity *= 2;
        int* newValues = new int[arr->capacity];

        for (int i = 0; i < arr->length; i++)
        {
            newValues[i] = arr->values[i];
        }

        delete[] arr->values;
        arr->values = newValues;
    }

    arr->values[arr->length] = value;
    arr->length += 1;
}

//взятие элемента из массива по индексу
int getElementAtIndex(const DynamicArray* arr, int index)
{
    assert(index >= 0 && index < arr->length);
    return arr->values[index];
}

//возвращение span
std::span<int> getCurrentSpan(const DynamicArray* arr)
{
    return std::span<int>(arr->values, arr->length);
}

//освобождение памяти, выделенной под массив
void destroyMemory(DynamicArray* arr)
{
    arr->capacity = 1;
    arr->length = 0;
    delete[] arr->values;
}