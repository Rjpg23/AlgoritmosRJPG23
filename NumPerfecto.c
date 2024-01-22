#include <stdio.h>
#include <math.h>

// Return 1 si n es primo, 0 si no lo es.

int es_primo(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void numeros_perfectos(int NUM) {
    int cantidad = 0;
    printf("Los números perfectos entre 1 y %d son: ", NUM);
    for (int n = 2; n < 32; n++) {  // Solo se conocen números perfectos para n < 32
        long long p = pow(2, n - 1) * (pow(2, n) - 1); // Se calcula el número perfecto correspondiente al valor actual de n. Aplicando la formula 2^(n - 1) por (2^n - 1)
        if (p > NUM) break;
        if (es_primo(pow(2, n) - 1)) {
            printf("%lld ", p);
            cantidad++;
        }
    }
    printf("\nNúmeros perfectos dentro del intervalo es: %d\n", cantidad);
}

int main() {
    int NUM;
    printf("Ingrese un número: ");
    scanf("%d", &NUM);
    numeros_perfectos(NUM);
    return 0;
}








