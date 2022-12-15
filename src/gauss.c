#include <stdio.h>
#include "gauss.h"
#include <math.h>
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate( Matrix *mat, Matrix *b) {
    int k, j, n,i;
    double d;
    n=mat->r;
    for (k = 0; k < n - 1; k++) {
        int kmax = k;
        for (j = k + 1; j < n; j++)
            if ( fabs (mat->data[j][k]) > fabs(mat->data[kmax][k]) )
                kmax = j;
        if (kmax != k) {
            double *tmp = mat->data[k];
            mat->data[k] = mat->data[kmax];
            mat->data[kmax] = tmp;
            double *btmp = b->data[k];
            b->data[k] = b->data[kmax];
            b->data[kmax] = btmp;
        }
        for(j = k + 1; j < n; j++){
            if(mat->data[k][k] == 0){
                return 1;
            }
            d = mat->data[j][k] / mat->data[k][k];
            for(i = k; i < n; i++){
                mat->data[j][i] = mat->data[j][i] -d * (mat->data[k][i]);
            }
            b->data[j][0] = b->data[j][0] - d * (b->data[k][0]);
        }
    }

    return 0;
}