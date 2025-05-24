#include <vector>
#include <deque>
#include <list>
#include <set>           // set and multiset
#include <map>           //map and multimap
#include <unordered_set> // Unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> // numeric algorithms
#include <functional>
#include <forward_list>

#include <iostream>
#include <cmath>

/*
 * Function Objects (functors)
 * - Functors expandem o conceito de função permitindo que classes se comportem como um função.
 * - É uma função inteligente que possuem capacidades além do que uma função comum pode fornecer
 * - Podem armazenar estados
 * - Podem ter tipos próprios. Dois functors podem ser de tipos diferentes, mesmo que tenham a mesma assinatura de função
 * - Introduzem o conceito de função parametrizada
 * - stl fornece alguns functors built - in: less, greater, greater_equal, less_equal, not_equal_to, logical_and, logical_not, logical_or, multiplies, minus, plus, divide, modulus, negate
 * - Lembrando que como os functors são classes eles não consegue inferir o tipo do template, portanto, é necessário fornece o tipo.
 */
/*
 * Predicado: É uma função ou functor que:
 * 1. Retorna um booleano
 * 2. Não modifica o dado
 * - Muito utilizado para comparação ou condition check
 * - Não é possivel garantir que um predicado será executado apenas uma vez por elemento, por isso é importante que o predicado seja inteiramente baseado no input que recebe e nao em quantas vezes ele está sendo executado
 */

class X
{
public:
    X(int i) {}
    void operator()(std::string str)
    {
        std::cout << "Calling functor X with parameter " << str << std::endl;
    }
    // operator std::string () const {return "X";} // type conversion function
};

void add2(int i)
{
    std::cout << i + 2 << std::endl;
}

template <int val>
void addVal(int i) { std::cout << val + i << std::endl; }

class AddValue
{
    int val;

public:
    AddValue(int j) : val(j) {}
    void operator()(int i)
    {
        std::cout << i + val << " ";
    }
};

void add(int i, int val)
{
    std::cout << i + val << " ";
}

double Pow(double x, double y)
{
    return pow(x, y);
}

bool needCopy(int x) { return (x > 20) || (x < 5); }

bool lsb_less(int x, int y) { return (x % 10) < (y % 10); }

class Lsb_less
{
public:
    bool operator()(int x, int y) { return (x % 10) < (y % 10); }
};

// Predicado
class NeedCopy
{
    bool operator()(int x) { return (x > 20) || (x < 5); }
};

int
main()
{
    X(8)("Hi");
    int val = 2;
    std::vector<int> vec = {2, 3, 4, 5};
    // for_each(vec.begin(), vec.end(), add2);
    // for_each(vec.begin(), vec.end(), addVal<2>);
    // for_each(vec.begin(), vec.end(), addVal<val>); //ERRO - template trabalha em tempo de compilação e muitas vezes a variável x pode nem ter sido instanciada ainda, por isso da erro
    for_each(vec.begin(), vec.end(), AddValue(val));
    std::cout << std::endl;

    { // built - in functors
        int x = std::multiplies<int>()(3, 4);
        if (std::not_equal_to<int>()(x, 10))
        {
            std::cout << x << std::endl;
        }
    }

    { // Parameter Binding - Funçao bind é do C++11

        std::set<int> set = {2, 3, 4, 5};
        std::vector<int> vec;

        int x = std::multiplies<int>()(3, 4);

        // Multiplies set for 10 and save in vec
        std::transform(set.begin(), set.end(),                                   // src
                       back_inserter(vec),                                       // dst
                       bind(std::multiplies<int>(), std::placeholders::_1, 10)); // functor
        // Primeiro parametro de multiplies é substituido pelos elementos de set.
        for (auto val : vec)
            std::cout << val << " ";
        std::cout << std::endl;

        for_each(vec.begin(), vec.end(), bind(add, std::placeholders::_1, 2));
        std::cout << std::endl;
    }

    {
        // Convert function to a functor
        std::set<int> set = {3, 1, 25, 7, 13};
        std::deque<int> d;
        auto f = std::function<double(double, double)>(Pow); // C++ 11
        transform(set.begin(), set.end(),
                  std::back_inserter(d),
                  bind(f, std::placeholders::_1, 2));
        for (auto val : d)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        d.clear();

        // Using built - in functors
        //  transform(set.begin(), set.end(),
        //            std::back_inserter(d),
        //            bind(std::logical_or<bool>(),
        //                 bind(std::greater<int>(), std::placeholders::_1, 20),
        //                 bind(std::less<int>(), std::placeholders::_1, 5)));

        // Using auxiliar function
        //  transform(set.begin(), set.end(),
        //            std::back_inserter(d),
        //            needCopy);

        // Using C++11 lambda
        transform(set.begin(), set.end(),
                  std::back_inserter(d),
                  [](int x)
                  { return (x > 20) || (x < 5); });
    }

    {
        // É possivel passar um segundo parametro para o container que seria um tipo de uma  função de ordenação
        std::set<int, std::less<int>> set = {3, 1, 25, 7, 12};
        // std::set<int, lsb_less> set = {3, 2, 1}; // ERRO - lsb é uma função comum, a função tem que ser um type name
        std::set<int, Lsb_less> myset = {3, 2, 1}; // Correto, pois é um functor

        for (auto val : set)
            std::cout << val << " ";
        std::cout << std::endl;
    }


    return 0;
}