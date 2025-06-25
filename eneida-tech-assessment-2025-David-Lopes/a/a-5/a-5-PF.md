# Cálculo do Fator de Potência (PF)

## Conjunto de Amostras

Foram simuladas **3 fases (A, B, C)** com:
- **Frequência da rede:** 50 Hz  
- **Taxa de amostragem:** 8000 Hz  
- **Número de ciclos:** 20  

Com estes dados:
- Cada ciclo tem `8000 / 50 = 160` amostras  
- Para 20 ciclos: `20 × 160 = 3200` amostras por fase  
- Vetores simulados: `vA`, `vB`, `vC` e `iA`, `iB`, `iC`

## Lógica do Programa

O programa define `N = 3200` (número total de amostras) e implementa uma função `calculate_pf(v, i)` que percorre os vetores de tensão e corrente:

> As fórmulas matemáticas utilizadas encontram-se na pasta `resources/`.

1. A soma do produto ponto a ponto de `v · i` → potência ativa média (P)  
2. A soma dos quadrados de `v` e `i` → para calcular `Vrms` e `Irms`  
3. O fator de potência (PF) é então calculado por:  
   `PF = P / (Vrms × Irms)`

## Organização

No `main()`:
- São geradas amostras de três sinais (fases A, B e C), com harmónicas simples.
- A função `calculate_pf()` é chamada para cada fase, usando os pares tensão/corrente.
- O resultado (PF) de cada fase é impresso no final.