#include<stdio.h>
#include<stdlib.h>

//Implementation of interface
int* int_add(int *x, int *y) {
    int *c = (int *)malloc(sizeof(int));
    *c = *(int*)x + *(int*)y;
    return c;
}

//Implementation of interface
float* float_add(float *x, float *y) {
    float *c = (float*)malloc(sizeof(float));
    *c = *(float*)x + *(float*)y;
    return c;
}

//Operation Interface
void* do_operation(void* (*op)(void*, void*), void* x, void* y) {
    return op(x, y);
}

void main(void) {

    int a = 1;
    int b = 2;                                               
    int *c;
    c = do_operation(int_add, &a, &b);
    printf("%d\n",*c);
    free(c);

    float x = 1.1;                                               
    float y = 2.2;                                               
    float *z;
    z = do_operation(float_add, &x, &y);
    printf("%f\n",*z);
    free(z);
}
