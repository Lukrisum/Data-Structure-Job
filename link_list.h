#ifndef LINK_LIST
#define LINK_LIST

#include<stdio.h>
#include <malloc.h>

typedef int Elem;

typedef struct LinkList {
    Elem elem; // 数据域
    struct LinkList *next; // 指针域
} linkList;

// 创建
linkList *initLinkList() {
    linkList *p = (linkList *) malloc(sizeof(linkList)); // 创建头节点
    if (!p) {
        printf("initialize failed\n");
        exit(0);
    }
    return p;
}

// 插入
linkList *insert(linkList *p, Elem elem, int target) {
    linkList *temp = p;

    // 检查插入位置合法性
    for (int i = 0; i < target; ++i) {
        if (temp == NULL) {
            printf("invalid insertion position\n");
            return p;
        }
        temp = temp->next;
    }

    linkList *c = (linkList *) malloc(sizeof(linkList));
    if (!c) {
        printf("storage space allocation failed\n");
        exit(0);
    }

    c->elem = elem;
    temp->next = c;
    return p;
}

// 删除
linkList *del(linkList *p, int target) {
    linkList *temp = p;
    for (int i = 0; i < target; ++i) {
        if (temp == NULL) {
            printf("invalid delete position\n");
            return p;
        }
        temp = temp->next;
    }
    linkList *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

// 定位
int findIndex(linkList *p, Elem target) {
    linkList *temp = p;
    int i = 1;

    // 遍历
    while (temp->next) {
        temp = temp->next;
        if (temp->elem == target) {
            return i;
        }
    }
    return -1;
}

#endif