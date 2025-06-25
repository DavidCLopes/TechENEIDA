#include <stdio.h>
#include <math.h>

// Número de amostras (20 ciclos de 50 Hz a 8 kHz) 8000/50 = 160 -> 160 * 20 = 3200
#define N 3200
#define PI 3.14159265358979323846

// Calcula o fator de potência (PF)
double calculate_pf(const double v[N], const double i[N])
{
    double sum_vi = 0.0, sum_v2 = 0.0, sum_i2 = 0.0;

    // Formulas na pasta resources
    for (int n = 0; n < N; ++n)
    {
        sum_vi += v[n] * i[n]; // soma de v[n]*i[n]
        sum_v2 += v[n] * v[n]; // soma de v[n]^2
        sum_i2 += i[n] * i[n]; // soma de i[n]^2
    }
    double P = sum_vi / N;   
    double Vrms = sqrt(sum_v2 / N);
    double Irms = sqrt(sum_i2 / N);

    // Evita divisão por zero
    if (Vrms == 0.0 || Irms == 0.0)
        return 0.0;

    return P / (Vrms * Irms);
}

int main(void)
{
    static double vA[N], iA[N];
    static double vB[N], iB[N];
    static double vC[N], iC[N];

    // Dados simulados
    for (int n = 0; n < N; ++n)
    {
        double t = n / 8000.0; // Tempo em seg
        vA[n] = 325.0 * sin(2 * PI * 50 * t);
        iA[n] = 10.0 * sin(2 * PI * 50 * t - PI / 6);
        vB[n] = 325.0 * sin(2 * PI * 50 * t - 2 * PI / 3);
        iB[n] = 10.0 * sin(2 * PI * 50 * t - 2 * PI / 3 - PI / 4);
        vC[n] = 325.0 * sin(2 * PI * 50 * t + 2 * PI / 3);
        iC[n] = 10.0 * sin(2 * PI * 50 * t + 2 * PI / 3 + PI / 3);
    }

    // FP para cada fase
    double pfA = calculate_pf(vA, iA);
    double pfB = calculate_pf(vB, iB);
    double pfC = calculate_pf(vC, iC);

    printf("PF Fase A: %.4f\n", pfA);
    printf("PF Fase B: %.4f\n", pfB);
    printf("PF Fase C: %.4f\n", pfC);

    return 0;
}
