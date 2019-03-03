#include <stack>
#include <string>
#include <iostream>

int
main ()
{
        std::string line;
        std::cin >> line;

        std::stack<std::string> stack;
        for (auto i = line.begin(); i != line.end(); ++i) {
                if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
                        std::string s1 = stack.top();
                        stack.pop();
                        std::string s2 = stack.top();
                        stack.pop();
                        stack.push("(" + s2 + *i + s1 + ')');
                } else {
                        stack.push((std::string)"" + *i);
                }
        }
        std::cout << stack.top() << std::endl;
}