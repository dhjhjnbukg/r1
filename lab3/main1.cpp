#include <iostream>

int hello(int x);

int main()
{
    
    int result = hello(37);
    std::cout << result << std::endl;

    //���������� ������ ������ �.�. ������� hello �� ����������
   

    return 0;
}

//������ ��-�� ����, ��� �� ���������� hello ������ ������ ���
int hello(int x)
{
    return (x + 1);
}