#ifndef MPU_TAD_H
#define MPU_TAD_H

#include <stdint.h>

// Opções de sensibilidade
#define MPU_ACC_2G   2
#define MPU_ACC_4G   4
#define MPU_ACC_8G   8
#define MPU_ACC_16G  16

#define MPU_GYRO_250DPS   250
#define MPU_GYRO_500DPS   500
#define MPU_GYRO_1000DPS  1000
#define MPU_GYRO_2000DPS  2000

typedef struct mpu mpuTAD;

// Cria e libera
mpuTAD*  mpu_criar(void);
void     mpu_destruir(mpuTAD *m);

// Configurações de sensibilidade
void     mpu_set_sens_acc(mpuTAD *m, int sens_g);
int      mpu_get_sens_acc(const mpuTAD *m);
void     mpu_set_sens_gyro(mpuTAD *m, int sens_dps);
int      mpu_get_sens_gyro(const mpuTAD *m);

// Leituras brutas
void     mpu_set_raw_acc(mpuTAD *m, int16_t ax, int16_t ay, int16_t az);
void     mpu_get_raw_acc(const mpuTAD *m, int16_t *ax, int16_t *ay, int16_t *az);
void     mpu_set_raw_gyro(mpuTAD *m, int16_t rx, int16_t ry, int16_t rz);
void     mpu_get_raw_gyro(const mpuTAD *m, int16_t *rx, int16_t *ry, int16_t *rz);

// Leituras em unidades finais
float    mpu_get_acc_x(const mpuTAD *m);
float    mpu_get_acc_y(const mpuTAD *m);
float    mpu_get_acc_z(const mpuTAD *m);

float    mpu_get_gyro_x(const mpuTAD *m);
float    mpu_get_gyro_y(const mpuTAD *m);
float    mpu_get_gyro_z(const mpuTAD *m);

#endif // MPU_TAD_H
