# Cálculo de THD (Total Harmonic Distortion)

O THD (Total Harmonic Distortion) mede a distorção num sinal causada por harmónicos — ou seja, frequências adicionais além da frequência fundamental.  
Para identificar estes harmónicos e a sua intensidade, é usada a FFT (Transformada Rápida de Fourier), que permite perceber o quanto cada frequência contribui para a forma final do sinal.

Este tipo de análise é essencial quando se pretende avaliar a qualidade de sinais elétricos, por exemplo, em eletronica de potência.

## Implementação no Programa

> As fórmulas utilizadas estão disponíveis na pasta `resources/`.

- O programa gera sinais com 3200 amostras, correspondentes a 20 ciclos de 50 Hz amostrados a 8 kHz.
- São simuladas três fases (A, B e C), cada uma com harmónicos diferentes.
- Para cada fase, a FFT é aplicada ao sinal, e o THD é calculado com base nas componentes harmónicas encontradas.
- O resultado final representa o nível de distorção de cada fase.