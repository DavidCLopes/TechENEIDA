#include <stdio.h>
#include <stdint.h>

// Raiz quadrada inteira (busca binária)
static int64_t int_sqrt(int64_t x) {
    int64_t low = 0, high = x, mid, res = 0;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (mid <= x/mid) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

// RMS em Q8 (resultado = valor_real * 256)
int compute_rms_fixed(const int *samples, int len) {
    int64_t sum_sq = 0;
    for (int i = 0; i < len; i++) {
        int64_t v_q8 = ((int64_t)samples[i]) << 8;  // Q8, X * 256
        sum_sq += v_q8 * v_q8;                      // fica em Q16
    }
    int64_t mean_q16 = sum_sq / len;    // media dos quadrados (Q16)
    return (int)int_sqrt(mean_q16);     // passa para Q8
}

int main(void) {
    const int samples[50] = {
        1010, 980, 1024, 990, 1005, 1018, 975, 992, 1003, 998,
        1012, 984, 1021, 995, 1008, 1015, 982, 987, 1000, 997,
        1007, 978, 1030, 993, 1002, 1022, 979, 989, 1004, 996,
        1011, 985, 1025, 994, 1006, 1016, 980, 986, 1001, 995,
        1009, 977, 1028, 991, 1000, 1020, 981, 990, 1002, 998
    };

    int rms_q8 = compute_rms_fixed(samples, 50);
    // Parte inteira e decimal do resultado Q8
    int inteiro =  rms_q8 >> 8;
    int decimal = ((rms_q8 & 0xFF) * 100 + 128) / 256;

    printf("RMS (Q8) = %d.%02d\n", inteiro, decimal);
    return 0;
}