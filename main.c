#include <stdio.h>
#include <limits.h>

 
int matrixChainOrder(int p[], int n) {
    int m[n][n]; // memorization array
    for (int i = 1; i < n; i++) {
        m[i][i] = 0; //initializing 0 to array
    }
    for (int L = 2; L < n; L++) {  // bottom- up approch
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //calculating
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    int p[n+2];
    for (int i = 0; i < n; i++) {  // making the gien dimensions in one arry
        int r, c;
        scanf("%d %d", &r, &c);
        p[i] = r;
        if (i+1 == n) {
            p[i+1] = c;
        }
    }
   /* for (int i = 0; i <= n; i++) {
     //   printf("%d ", p[i]);  
}*/
int min =  matrixChainOrder(p, n+1);
printf("%d", min);

}
