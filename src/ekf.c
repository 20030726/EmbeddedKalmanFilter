#include <embedded_kalman_filter/ekf.h>

ekf_status_t ekf_ekf_init(ekf_ekf_t* model, float* state_buffer, float* covariance_buffer,
                          unsigned int dimension, float process_noise, float measurement_noise) {
    if (model == 0 || state_buffer == 0 || covariance_buffer == 0 || dimension == 0 ||
        process_noise < 0.0F || measurement_noise < 0.0F) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    model->state = state_buffer;
    model->covariance = covariance_buffer;
    model->dimension = dimension;
    model->process_noise = process_noise;
    model->measurement_noise = measurement_noise;
    return EKF_STATUS_OK;
}

ekf_status_t ekf_ekf_predict(ekf_ekf_t* model) {
    if (model == 0) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    return EKF_STATUS_NOT_IMPLEMENTED;
}

ekf_status_t ekf_ekf_update(ekf_ekf_t* model) {
    if (model == 0) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    return EKF_STATUS_NOT_IMPLEMENTED;
}
