#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

typedef enum {
    NUMBER,
    OPERATOR
} ENUM_DATA_TYPE;

typedef struct {
    ENUM_DATA_TYPE dt;
    int value;
} Node;

int precede(int opr1, int opr2) {
    int rank1, rank2;
    if(opr1 == '+' || opr1== '-') {
        rank1 = 1;
    } else {
        rank1 = 2;
    }
    if (opr2 == '+' || opr2 == '-') {
        rank2 = 1;
    } else {
        rank2 = 2;
    }
    return rank1 > rank2;
}

int operate(int opr1, int a, int b) {
    switch(opr1) {
        case '+':return a + b;
        case '-':return b - a;
        case '*':return a * b;
        case '/':return b / a;
    }
    return 0;
}

stack<Node> s;
int main() {
    char *buffer = (char *)malloc(22);
    cin >> buffer;
    Node data_node;
    int pre_num = 0;
    Node *pre_str = (Node *)malloc(sizeof(Node) * 22);
    while (*buffer) {
        if (isdigit(buffer[0])) {
            data_node.dt = NUMBER;
            data_node.value = buffer[0] - '0';
            pre_str[pre_num++] = data_node;
        } else {
            if (!s.empty() && !precede(buffer[0], s.top().value)) {
                data_node = s.top();
                s.pop();
                pre_str[pre_num++] = data_node;
            }
            data_node.dt = OPERATOR;
            data_node.value = buffer[0];
            s.push(data_node);
        }
        ++buffer;
    }
    while (!s.empty()) {
        data_node = s.top();
        s.pop();
        pre_str[pre_num++] = data_node;
    }
    int a, b;
    for (int i = 0; i < pre_num; i++) {
        if (pre_str[i].dt == NUMBER) {
            s.push(pre_str[i]);
        } else {
            a = s.top().value;
            s.pop();
            b = s.top().value;
            s.pop();
            data_node.dt = NUMBER;
            data_node.value = operate(pre_str[i].value, a, b);
            s.push(data_node);
        }
    }
    cout << s.top().value ;
    free(pre_str);
    return 0;
}
