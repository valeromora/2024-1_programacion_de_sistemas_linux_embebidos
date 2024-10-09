//leer un archivo de texto y hacer un histograma de los caracteres contenidos

#include <stdio.h>

int main() {
    // Abrir el archivo en modo de lectura
    FILE *archivo = fopen("archivo.txt", "r");

    // Verificar si se pudo abrir el archivo
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;  // Salir del programa con código de error
    }

    // Declarar e inicializar el histograma
    int histograma[128] = {0};

    // Leer cada carácter del archivo y contar su frecuencia
    int caracter;
    while ((caracter = fgetc(archivo)) != EOF) {
        histograma[caracter]++;
    }

    // Cerrar el archivo después de leer
    fclose(archivo);

    // Imprimir el histograma
    printf("Histograma de caracteres:\n");
    for (int i = 0; i < 128; i++) {
        if (histograma[i] > 0) {
            printf("'%c': %d\n", (char)i, histograma[i]);
        }
    }

    return 0;
}
