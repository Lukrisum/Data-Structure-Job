#include "algorithm.h"

/**
 * 测试：
 * 作业 2
 * @return void
 */
int main() {
    system("chcp 65001");

    // 算法演示
    sqTable t = initSqTable();

    // 初始化顺序表
    for (int i = 0; i < 5; ++i) {
        sqTable temp = add(t, i, i);
        t = temp;
    }

    // 打印：删除前
    for (int i = 0; i < t.len; ++i) {
        printf("顺序表第%d位数是%d\n", i, t.base[i]);
    }

    // 定义指针
    sqTable *p = &t;

    // 调用删除算法
    sqTableDelete(p, 2);

    // 打印：删除后
    for (int i = 0; i < t.len; ++i) {
        printf("顺序表第%d位数是%d\n", i, t.base[i]);
    }

    return 0;
}