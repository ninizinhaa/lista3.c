#include <stdio.h>
#include <string.h>


int obterValor(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}


int converterRomanoParaInteiro(char *romano) {
    int res = 0;

    for (int i = 0; romano[i] != '\0'; i++) {
        int valAtual = obterValor(romano[i]);

        if (romano[i + 1] != '\0') {
            int valProximo = obterValor(romano[i + 1]);

            if (valAtual >= valProximo) {
                res = res + valAtual;
            } else {
                res = res + valProximo - valAtual;
                i++;
            }
        } else {
            res = res + valAtual;
        }
    }

    return res;
}

void decimalParaBinario(int dec) {
    int bin[1000];
    int i = 0;

    while (dec > 0) {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

void decimalParaHexadecimal(int dec) {
    char hexNum[20];
    int index = 0;

    while (dec > 0) {
        int resto = dec % 16;

        if (resto < 10) {
            hexNum[index] = resto + 48;
        } else {
            hexNum[index] = resto + 87;
        }

        index++;
        dec = dec / 16;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexNum[i]);
    }

    printf("\n");
}

int main() {
    char romano[20];
    scanf("%s", romano);
    int resultado = converterRomanoParaInteiro(romano);
    printf("%s na base 2: ", romano);
    decimalParaBinario(resultado);
    printf("%s na base 10: %d\n", romano, resultado);
    printf("%s na base 16: ", romano);
    decimalParaHexadecimal(resultado);

    return 0;
}