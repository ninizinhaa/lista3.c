#include <stdio.h>
#include <math.h>

double calcularNovoMontante(double invest, double juros, int meses) {
    double montante;
    montante = invest * (1 + juros) * ((pow((1 + juros), meses) - 1) / juros);
    return montante;
}

int main() {
    double invest, juros;
    int meses;

    scanf("%d", &meses);
    scanf("%lf", &invest);
    scanf("%lf", &juros);

    for (int mesAtual = 1; mesAtual <= meses; mesAtual++) {
        double novoMontante = calcularNovoMontante(invest, juros, mesAtual);
        printf("Montante ao fim do mes %1d: R$ %.2f\n", mesAtual, novoMontante);
    }

    return 0;
}