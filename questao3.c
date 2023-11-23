#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehDigito(char c) {
    return (c >= '0' && c <= '9');
}

void paraMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int verificarPermissao(char placa[], char dia[]) {
    int tamanho = strlen(placa);

    char ultimoCaractere = placa[tamanho - 1];
    int digito = ultimoCaractere - '0';

    if ((strcmp(dia, "segunda-feira") == 0 && (digito == 0 || digito == 1)) ||
        (strcmp(dia, "terca-feira") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(dia, "quarta-feira") == 0 && (digito == 4 || digito == 5)) ||
        (strcmp(dia, "quinta-feira") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(dia, "sexta-feira") == 0 && (digito == 8 || digito == 9))) {
        return 0; // Não autorizado
    } else {
        return 1; // Autorizado para outros casos
    }
}

int main() {
    char placa[20];
    char dia[20];

    scanf("%19s", placa);
    scanf("%19s", dia);

    if (!((strlen(placa) == 7 || strlen(placa) == 8) &&
          (isalpha((unsigned char)placa[0]) && isalpha((unsigned char)placa[1]) && isalpha((unsigned char)placa[2]) &&
           ehDigito(placa[strlen(placa) - 1])))) {
        printf("Placa invalida\n");
        if (strcmp(dia, "SEGUNDA-FEIRA") != 0 &&
            strcmp(dia, "TERCA-FEIRA") != 0 &&
            strcmp(dia, "QUARTA-FEIRA") != 0 &&
            strcmp(dia, "QUINTA-FEIRA") != 0 &&
            strcmp(dia, "SEXTA-FEIRA") != 0 &&
            strcmp(dia, "SABADO") != 0 &&
            strcmp(dia, "DOMINGO") != 0) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (strcmp(dia, "SEGUNDA-FEIRA") != 0 &&
        strcmp(dia, "TERCA-FEIRA") != 0 &&
        strcmp(dia, "QUARTA-FEIRA") != 0 &&
        strcmp(dia, "QUINTA-FEIRA") != 0 &&
        strcmp(dia, "SEXTA-FEIRA") != 0 &&
        strcmp(dia, "SABADO") != 0 &&
        strcmp(dia, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    paraMinusculas(dia);

    int autorizado = verificarPermissao(placa, dia);

    if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (autorizado) {
        printf("%s pode circular %s\n", placa, dia);
    } else {
        printf("%s nao pode circular %s\n", placa, dia);
    }

    return 0;
}
