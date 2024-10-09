// convertir numeros entre bases numericas para cualquier base entre la binaria y la hexagecimal

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Función para convertir un dígito hexadecimal a decimal
int hexToDecimal(char hexDigit) {
    if (isdigit(hexDigit)) {
        return hexDigit - '0';
    } else {
        return toupper(hexDigit) - 'A' + 10;
    }
}

// Función para convertir un número en una base a decimal
int toDecimal(const char *number, int base) {
    int decimal = 0;
    int power = 1;
    int length = strlen(number);

    for (int i = length - 1; i >= 0; i--) {
        int digit = (base == 16) ? hexToDecimal(number[i]) : (number[i] - '0');
        decimal += digit * power;
        power *= base;
    }

    return decimal;
}

// Función para convertir un número decimal a una base dada
void fromDecimal(int decimal, int base) {
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    char result[100];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % base;
        result[index++] = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
        decimal /= base;
    }

    // Imprimir el resultado en orden inverso
    printf("El resultado en base %d es: ", base);
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    int baseFrom, baseTo;

    // Solicitar entrada al usuario
    printf("Ingrese el número: ");
    scanf("%s", input);

    printf("Ingrese la base del número (2-16): ");
    scanf("%d", &baseFrom);

    printf("Ingrese la base a convertir (2-16): ");
    scanf("%d", &baseTo);

    // Validar bases
    if (baseFrom < 2 || baseFrom > 16 || baseTo < 2 || baseTo > 16) {
        printf("Bases no válidas. Debe estar entre 2 y 16.\n");
        return 1;
    }

    // Convertir a decimal
    int decimalNumber = toDecimal(input, baseFrom);

    // Convertir de decimal a la base deseada
    fromDecimal(decimalNumber, baseTo);

    return 0;
}
