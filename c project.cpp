#include <stdio.h>
#include <math.h>


void partial_fraction(double *A, double *B) {
    
    double a = 1.0, b = 2.0, c = 5.0;  
    double s1 = 1.0, s2 = 2.0;         

    
    *A = (c - s2 * (b - s2 * a)) / (s1 - s2);
    *B = (c - s1 * (b - s1 * a)) / (s2 - s1);
}


void inverse_laplace(double A, double B, double t, double *result) {
    *result = A * exp(t) + B * exp(2 * t); // A * e^t + B * e^(2t)
}

int main() {
    double A, B;      
    double t, result;  

    partial_fraction(&A, &B); 

    
    printf("A = %lf, B = %lf\n", A, B);

    
    for (t = 0.0; t <= 5.0; t += 0.5) {
        inverse_laplace(A, B, t, &result); 
        printf("t = %.2lf, Result = %lf\n", t, result); 
    }

    return 0;
}

