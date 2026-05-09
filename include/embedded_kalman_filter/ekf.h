#ifndef EMBEDDED_KALMAN_FILTER_EKF_H
#define EMBEDDED_KALMAN_FILTER_EKF_H

#include <embedded_kalman_filter/status.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ekf_ekf {
    float* state;
    float* covariance;
    unsigned int dimension;
    float process_noise;
    float measurement_noise;
} ekf_ekf_t;

ekf_status_t ekf_ekf_init(ekf_ekf_t* model, float* state_buffer, float* covariance_buffer,
                          unsigned int dimension, float process_noise, float measurement_noise);
ekf_status_t ekf_ekf_predict(ekf_ekf_t* model);
ekf_status_t ekf_ekf_update(ekf_ekf_t* model);

#ifdef __cplusplus
}
#endif

#endif
