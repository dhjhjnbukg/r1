#include <iostream>

int hello(int x);

int main()
{
    
    int result = hello(37);
    std::cout << result << std::endl;

    //компилятор выдаст ошибку т.к. функция hello не определена
   

    return 0;
}

//однако из-за того, что мы определили hello ошибок больше нет
int hello(int x)
{
    return (x + 1);
}