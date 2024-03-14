#include "Span.hpp"
#include <iostream>
#include <cmath>

// int main(void)
// {
// 	Span sp2 = Span(105);
//     srand(time(NULL));
// 	try {
//         sp2.addNumber(1);
//         sp2.addNumber(2);
//         sp2.addNumber(11);
//         std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
//         std::cout << "longest span: " << sp2.longestSpan() << std::endl;
//         sp2.addNumber(1);
//         sp2.addNumber(111);
//         std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
//         std::cout << "longest span: " << sp2.longestSpan() << std::endl;
//         std::cout << "=======================================================" << std::endl;
//         std::vector<int> v(100);
//         for (int i = 1; i < 100; i++)
//         {
//             if (i % 3 == 0)
//                 v[i] = i;
//             else
//                 v[i] = rand();
//         }
//         sp2.SpanFill(v.begin(), v.end());
//         std::cout << "last: " << v.back() << std::endl;
//         std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
//         std::cout << "longest span: " << sp2.longestSpan() << std::endl;
//         std::cout << "=======================================================" << std::endl;
//         sp2.addNumber(1);
//     }
//     catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }
//     return 0;
// }


int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
