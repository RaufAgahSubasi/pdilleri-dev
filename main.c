#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Matris boyutlari */
    int rows = 3;
    int cols = 4;

    /* Eleman boyutu (byte) */
    int elemSize = sizeof(int);

    /* Tek parça bellek ayirma (row-major) */
    int *base = (int *)malloc(rows * cols * elemSize);
    if (base == NULL) {
        printf("Bellek ayirma hatasi!\n");
        return 1;
    }

    /* Matris doldurma (A[i][j] YOK!) */
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int offset = i * cols + j;
            *(base + offset) = i * 10 + j;
        }
    }

    /* Erisilecek indisler */
    int r, c;
    printf("Matris boyutu: %d x %d\n", rows, cols);
    printf("Erisilecek indisleri gir (i j): ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("HATA: Indis sinir disi!\n");
        free(base);
        return 1;
    }

    /* ROW-MAJOR ADRES HESAPLAMA */
    int offset = r * cols + c;
    int *elemAddr = base + offset;

    printf("\n--- SONUC ---\n");
    printf("Base address        : %p\n", (void *)base);
    printf("Hesaplanan adres    : %p\n", (void *)elemAddr);
    printf("Eleman degeri       : %d\n", *elemAddr);

    /* Elemani guncelleme */
    int newValue;
    printf("\nYeni deger gir: ");
    scanf("%d", &newValue);

    *elemAddr = newValue;

    printf("Guncellenmis deger  : %d\n", *elemAddr);
    printf("Adres (degismedi)   : %p\n", (void *)elemAddr);

    free(base);
    return 0;
}
