#include <stdio.h>
#include <cmath>

void update(int* a, int* b) {
    // Complete this function    
    auto t = *a + *b;
    auto h = (*a) - (*b);
    *a = t;
    *b = abs(h);
}

int main() {
    int a, b;
    int* pa = &a, * pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
