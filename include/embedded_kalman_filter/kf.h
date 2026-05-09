#ifndef EMBEDDED_KALMAN_FILTER_KF_H
#define EMBEDDED_KALMAN_FILTER_KF_H

#include <embedded_kalman_filter/status.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ekf_kf {
    float state;
    float covariance;
    float process_noise;
    float measurement_noise;
} ekf_kf_t;

ekf_status_t ekf_kf_init(ekf_kf_t* model, float initial_state, float initial_covariance,
                         float process_noise, float measurement_noise);
ekf_status_t ekf_kf_predict(ekf_kf_t* model, float control_input);
ekf_status_t ekf_kf_update(ekf_kf_t* model, float measurement);

#ifdef __cplusplus
}
#endif

#endif
