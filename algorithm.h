// 作业 2
#ifndef DATA_STRUCTURE_JOB_ALGORITHM_H
#define DATA_STRUCTURE_JOB_ALGORITHM_H

// 使用自己实现的顺序表和链表
#include "sequence_table.h"

void sqTableDelete(sqTable *t,Elem target) {
    int j = 0;
    for (int i = 0; i < t->len; i++) {
        if (t->base[i] != target) {
            t->base[j] = t->base[i];
            j++;
        }
    }
    t->len = j;
}

#endif //DATA_STRUCTURE_JOB_ALGORITHM_H
