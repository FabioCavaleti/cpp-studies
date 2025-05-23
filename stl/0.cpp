#include <iostream>

#define space() std::cout << "\n\n...\n\n";

// Function template
template <typename T>
T square(T x)
{
    return x * x;
}

// class template
template <typename T>
class BoVector
{
    T arr[1000];
    int size;

public:
    BoVector() : size(0) {}
    void push(T x) { arr[size] = x; size++; }
    void print() const { for (int i = 0; i < size; i++) { std::cout << arr[i] << std::endl; } }
    T get(int i) const { return arr[i]; }
    int getSize() const { return size; }
};

template<typename T>
BoVector<T> operator*(const BoVector<T> &rhs1, BoVector<T> &rhs2)
{
    BoVector<T> ret;
    for (int i = 0; i <rhs1.getSize(); i++)
    {
        ret.push(rhs1.get(i) * rhs2.get(i));
    }
    return ret;
}

int main()
{
    {
        std::cout << square<int>(5) << std::endl;
        std::cout << square<double>(5.5) << std::endl;
        std::cout << "Code bloat: quando voce utilza uma funçõa com template, o compilador gera uma cópia da função para cada tipo que chama e utiliza a função. Isso pode sobrecarregar o compliador aumentando o tempo de compilação, tamanho do arquivo binário e o desempenho geral da aplicação." << std::endl;
    }
    space();
    {
        BoVector<int> bv;
        bv.push(2);
        bv.push(5);
        bv.push(8);
        bv.print();
        std::cout << "OBS: function template consegue inferir o tipo T apenas com o parametro enviado na função, mas um template de classe precisa que seu tipo seja EXPLICITAMENTE DEFINIDO" << std::endl;
        std::cout << "Print squared bv: " << std::endl;
        square(bv).print();
        
    }
    space();
    return 0;
}