#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

stack<int> s;
int main() {
    int m, id = 0, n, flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        while (id < m) {
            ++id;
            s.push(id);
        }
        if (s.empty() || s.top() != m) {
            flag = 0;
        }
        s.pop();
    }
    cout << (flag == 1 ? "YES" : "NO") << endl;
    return 0;
}
