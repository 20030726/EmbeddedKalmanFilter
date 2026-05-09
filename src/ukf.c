#include <stddef.h>
#include <embedded_kalman_filter/ukf.h>

ekf_status_t ekf_ukf_init(ekf_ukf_t* model, float* state_buffer, float* covariance_buffer,
                          unsigned int dimension, float alpha, float beta, float kappa) {
    if (model == NULL || state_buffer == NULL || covariance_buffer == NULL || dimension == 0U) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    model->state = state_buffer;
    model->covariance = covariance_buffer;
    model->dimension = dimension;
    model->alpha = alpha;
    model->beta = beta;
    model->kappa = kappa;
    return EKF_STATUS_OK;
}

ekf_status_t ekf_ukf_predict(ekf_ukf_t* model) {
    if (model == NULL) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    return EKF_STATUS_NOT_IMPLEMENTED;
}

ekf_status_t ekf_ukf_update(ekf_ukf_t* model) {
    if (model == NULL) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    return EKF_STATUS_NOT_IMPLEMENTED;
}
