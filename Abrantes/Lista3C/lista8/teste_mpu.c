#include <stdio.h>
#include "mpuTAD.h"

int main(void) {
    mpuTAD *m = mpu_criar();
    if (!m) {
        fprintf(stderr, "Erro ao alocar MPU\n");
        return 1;
    }

    // Exemplo: configurar ±8g e ±1000°/s
    mpu_set_sens_acc(m, MPU_ACC_8G);
    mpu_set_sens_gyro(m, MPU_GYRO_1000DPS);

    // Inserir leituras brutas
    // Ex.: ax = 4096 => 1g, rx = 32.8 ≈ 1°/s
    mpu_set_raw_acc(m, 4096, 0, 0);
    mpu_set_raw_gyro(m, 32, 0, 0);

    // Recuperar e mostrar
    int16_t ax, ay, az, rx, ry, rz;
    mpu_get_raw_acc(m, &ax, &ay, &az);
    mpu_get_raw_gyro(m, &rx, &ry, &rz);

    printf("Raw accel: ax=%d ay=%d az=%d\n", ax, ay, az);
    printf("Raw gyro:  rx=%d ry=%d rz=%d\n", rx, ry, rz);

    printf("Aceleração (g): X=%.3f Y=%.3f Z=%.3f\n",
           mpu_get_acc_x(m),
           mpu_get_acc_y(m),
           mpu_get_acc_z(m));

    printf("Rotação (°/s): X=%.3f Y=%.3f Z=%.3f\n",
           mpu_get_gyro_x(m),
           mpu_get_gyro_y(m),
           mpu_get_gyro_z(m));

    mpu_destruir(m);
    return 0;
}
