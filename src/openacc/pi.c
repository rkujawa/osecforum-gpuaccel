/* gcc pi.c -fopenacc -foffload=nvptx-none -foffload="-O3" -O3 -o pi */
/* gcc pi.c -O3 -o pi */
#include <stdio.h>
#define N 2000000000
#define vl 32 

int main(void) {
        double pi = 0.0f;
        long long i;

        #pragma acc parallel vector_length(vl)
        #pragma acc loop reduction(+:pi)
        for (i = 0; i < N; i++) {
                double t = (double)((i+0.5)/N);
                pi +=4.0/(1.0+t*t);
        }

        printf("pi=%11.10f\n",pi/N);

        return 0;
}

