//
// Created by zhuanxu on 2018/11/4.
//
int printf(const char *format, ...);

void func1(int i) {
    printf("%d\n", i);
}

int main() {
    static int static_var = 85;
    static int static_var2;

    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);

    return a;
}