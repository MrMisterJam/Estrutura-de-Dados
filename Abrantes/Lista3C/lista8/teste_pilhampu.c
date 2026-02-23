#include <stdio.h>
#include "mpuTAD.h"
#include "pilhampuTAD.h"

int main(void) {
    pilhaMPU *pilha = pilha_mpu_criar();
    if (!pilha) {
        fprintf(stderr, "Erro ao criar pilha de MPUs\n");
        return 1;
    }

    // Cria e empilha 3 sensores com configurações e leituras diferentes
    for (int i = 0; i < 3; i++) {
        mpuTAD *m = mpu_criar();
        if (!m) { fprintf(stderr, "Erro ao criar MPU %d\n", i); continue; }

        // Exemplo de configuração variável
        mpu_set_sens_acc(m, (i+1) * MPU_ACC_2G);      // 2g, 4g, 6g (6g não padrão só como exemplo)
        mpu_set_sens_gyro(m, MPU_GYRO_250DPS * (i+1)); // 250, 500, 750

        // Leituras brutas de exemplo
        mpu_set_raw_acc(m, 1000 * i, 2000 * i, 3000 * i);
        mpu_set_raw_gyro(m, 10 * i, 20 * i, 30 * i);

        if (!pilha_mpu_push(pilha, m)) {
            fprintf(stderr, "Pilha cheia ao empilhar MPU %d\n", i);
            mpu_destruir(m);
        }
    }

    // Desempilha e imprime cada sensor
    while (!pilha_mpu_vazia(pilha)) {
        mpuTAD *m = pilha_mpu_pop(pilha);
        int16_t ax, ay, az, rx, ry, rz;
        mpu_get_raw_acc(m, &ax, &ay, &az);
        mpu_get_raw_gyro(m, &rx, &ry, &rz);

        printf("Sensor desempilhado:\n");
        printf("  Raw Acc: ax=%d ay=%d az=%d\n", ax, ay, az);
        printf("  Acc (g): X=%.3f Y=%.3f Z=%.3f\n",
               mpu_get_acc_x(m), mpu_get_acc_y(m), mpu_get_acc_z(m));
        printf("  Raw Gyro: rx=%d ry=%d rz=%d\n", rx, ry, rz);
        printf("  Gyro (°/s): X=%.3f Y=%.3f Z=%.3f\n\n",
               mpu_get_gyro_x(m), mpu_get_gyro_y(m), mpu_get_gyro_z(m));

        mpu_destruir(m);
    }

    pilha_mpu_destruir(pilha);
    return 0;
}
