#include <stdio.h>
#include <math.h>

// Número de amostras (20 ciclos de 50 Hz a 8 kHz) 8000/50 = 160 -> 160 * 20 = 3200
#define N 3200
#define PI 3.14159265358979323846

void calculate_thd(const float x[], float *thd)
{
    float X1 = 0.0f;  // |X₁|
    float sum_harmonics_squared = 0.0f;
    int k1_bin = 20;  // bin da fundamental (50*3200/8000 = 20)

    for (int h = 1; h <= 5; ++h)  // de 1 a 5
    {
        float Rek = 0.0f, Imk = 0.0f;
        int k = h * k1_bin;
        for (int n = 0; n < N; ++n)
        {
            float angle = 2.0f * PI * k * n / N;
            Rek += x[n] * cosf(angle);
            Imk -= x[n] * sinf(angle);
        }
        Rek /= N;
        Imk /= N;
        float Xk = sqrtf(Rek * Rek + Imk * Imk);  // |Xₖ|

        if (h == 1)
            X1 = Xk;
        else
            sum_harmonics_squared += Xk * Xk;
    }

    *thd = (X1 > 0.0f)
               ? sqrtf(sum_harmonics_squared) / X1
               : 0.0f;
}

int main(void)
{
    static float A[N], B[N], C[N];
    float thdA, thdB, thdC;

    // Dados simulados
    for (int n = 0; n < N; ++n)
    {
        float t = n / 8000.0f;
        A[n] = sinf(2 * PI * 50 * t) + 0.5f * sinf(2 * PI * 150 * t);
        B[n] = sinf(2 * PI * 50 * t - 2 * PI / 3) + 0.3f * sinf(2 * PI * 250 * t - 2 * PI / 3);
        C[n] = sinf(2 * PI * 50 * t + 2 * PI / 3);
    }

    // Calculo do THD para cada fase
    calculate_thd(A, &thdA);
    calculate_thd(B, &thdB);
    calculate_thd(C, &thdC);

    printf("THD Fase A: %.2f%%\n", thdA * 100.0f);
    printf("THD Fase B: %.2f%%\n", thdB * 100.0f);
    printf("THD Fase C: %.2f%%\n", thdC * 100.0f);

    return 0;
}