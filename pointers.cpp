#include <iostream>
#include <climits>

int main()
{

    int variable = 5;
    int *pointerVariable = &variable;

    std::cout << "Wartość zmiennej x to:     " << variable << std::endl;
    std::cout << "Wskaznik zmiennej x to:     " << pointerVariable << std::endl<<std::endl;

    std::cout << "Dereferencja wskaznika zminnej x to:  " << *pointerVariable << std::endl;

    std::cout << "Wielkość zajmowanych danych to:"<<std::endl;
    std::cout << "Wielkość zmiennej x:          " << sizeof(variable) <<std::endl;
    std::cout << "Wielkość wskaznika na x:      " << sizeof(pointerVariable) <<std::endl;

    std::cout << "MAX dla int w GCC x86_64 Linux: " << INT_MAX<<std::endl;

    return 0;
}