#include <math.h>
#include <stdio.h>
#include "gauss.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate( Matrix *mat, Matrix *b){
    int k, j, n, i, imax;
    double d;
    n=mat->r;

    for(k = 0; k < n; k++){
        imax=k;
        for(j = k + 1; j < n; j++) {
            if (fabs(mat->data[j][k]) > fabs(mat->data[imax][k])) {
                imax = j;
            }
        }
        if (imax != k) {
            double *tmp = mat->data[k];
            mat->data[k] = mat->data[imax];
            mat->data[imax] = tmp;

            double *btmp = b->data[k];
            b->data[k] = b->data[imax];
            b->data[imax] = btmp;
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
