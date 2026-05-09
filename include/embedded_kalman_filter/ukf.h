#ifndef EMBEDDED_KALMAN_FILTER_UKF_H
#define EMBEDDED_KALMAN_FILTER_UKF_H

#include <embedded_kalman_filter/status.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ekf_ukf {
    float* state;
    float* covariance;
    unsigned int dimension;
    float alpha;
    float beta;
    float kappa;
} ekf_ukf_t;

ekf_status_t ekf_ukf_init(ekf_ukf_t* model, float* state_buffer, float* covariance_buffer,
                          unsigned int dimension, float alpha, float beta, float kappa);
ekf_status_t ekf_ukf_predict(ekf_ukf_t* model);
ekf_status_t ekf_ukf_update(ekf_ukf_t* model);

#ifdef __cplusplus
}
#endif

#endif
