#include <iostream>
#include <cstring>
#include <queue>
using std::cin;
using std::cout;
using std::string;
using std::queue;

queue<char> q;
int main() {
    char *str = (char *)malloc(20);
    cin >> str;
    int flag = 1;
    int len = strlen(str);
    for (int i = len - 2; i >= 0; i--) {
        q.push(str[i]);
    }
    for (int i = 0; i < len - 1; i++) {
        if (str[i] != q.front()) {
            flag = 0;
        } 
        q.pop();
        
    }
    cout << (flag == 1 ? "true" : "false");
    free(str);
    return 0;
}
