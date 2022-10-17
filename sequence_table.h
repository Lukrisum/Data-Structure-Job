#ifndef SEQUENCE_TABLE
#define SEQUENCE_TABLE

#include <stdio.h>
#include <malloc.h>

// 定义存储类型
typedef int Elem;

typedef struct SqTable {
    int *base;  // 基地址
    int len;    // 长度
    int size;   // 总空间
} sqTable;

// 初始化
#define Size 5

sqTable initSqTable() {
    sqTable t;

    // 分配存储空间，并捕捉错误
    t.base = (int *) malloc(Size * sizeof(Elem));
    if (!t.base) {
        printf("initialize failed\n");
        exit(0);
    }
    t.len = 0;
    t.size = Size;
    return t;
}

// 销毁
void destroy(sqTable t) {
    // 释放动态分配的内存
    free(t.base);
}

// 插入
sqTable add(sqTable t, Elem elem, int target) {

    printf("%d\n", t.len);

    // 检查插入位置是否合法
    if (target > t.len || target < 0) {
        printf("invalid insertion position\n");
        return t;
    }

    // 判断并分配多余存储空间，并捕捉错误
    if (t.len == t.size) {
        t.base = (int *) realloc(t.base, (t.size + 1) * sizeof(Elem));
        if (!t.base) {
            printf("storage space allocation failed\n");
            return t;
        }
        t.size += 1;
    }

    // 从插入位置开始逐个后移
    for (int i = t.len - 1; i >= target; i--) {
        t.base[i + 1] = t.base[i];
    }

    // 插入元素
    t.base[target] = elem;

    // 插入完成，长度加一
    t.len++;
    return t;
}

// 删除
sqTable delete(sqTable t, int target) {

    // 判断合法性
    if (target > t.len || target < 0) {
        printf("invalid target index\n");
        return t;
    }

    // 重新分配空间，并捕捉错误
    t.base = (int *) realloc(t.base, (t.size - 1) * sizeof(Elem));

    return t;
}

// 查找
int find(sqTable t, Elem elem) {

    g// 顺序查找
    for (int i = t.len; i >= 0; i--) {
        if (elem == t.base[i]) {
            return i;
        }
    }

    return -1;
}

// 修改
sqTable modify(sqTable t, int targetIndex, Elem targetElem) {

    // 检验操作合法性
    if (targetIndex > t.len || targetIndex < 0) {
        printf("invalid modification position\n");
        return t;
    }

    // 修改
    t.base[targetIndex] = targetElem;
    return t;
}

# endif