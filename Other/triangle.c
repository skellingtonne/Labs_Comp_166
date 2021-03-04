#include <stdio.h>
#include <stdlib.h>
void secretFunction(const int sr, const int er, const int sc, const int ec) {
    for (int r = sr; r < er; r++) {
        for (int c = sc; c < ec; c++) {
            printf("%4d", r * c);
        }
        printf("\n");
    }
}
int main(void) {
    int x=-3,y=5;
    char c = 2;
    double p=1.0,z=3.0;
    printf("%d",!x&&y);
    //printf("%i",sizeof(int));
    return EXIT_SUCCESS;
}