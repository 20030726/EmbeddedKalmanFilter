#include <embedded_kalman_filter/kf.h>

ekf_status_t ekf_kf_init(ekf_kf_t* model, float initial_state, float initial_covariance,
                         float process_noise, float measurement_noise) {
    if (model == 0 || initial_covariance < 0.0F || process_noise < 0.0F || measurement_noise < 0.0F) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    model->state = initial_state;
    model->covariance = initial_covariance;
    model->process_noise = process_noise;
    model->measurement_noise = measurement_noise;
    return EKF_STATUS_OK;
}

ekf_status_t ekf_kf_predict(ekf_kf_t* model, float control_input) {
    if (model == 0) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    model->state += control_input;
    model->covariance += model->process_noise;
    return EKF_STATUS_OK;
}

ekf_status_t ekf_kf_update(ekf_kf_t* model, float measurement) {
    float innovation_covariance;
    float kalman_gain;

    if (model == 0) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    innovation_covariance = model->covariance + model->measurement_noise;
    if (innovation_covariance <= 0.0F) {
        return EKF_STATUS_INVALID_ARGUMENT;
    }

    kalman_gain = model->covariance / innovation_covariance;
    model->state += kalman_gain * (measurement - model->state);
    model->covariance = (1.0F - kalman_gain) * model->covariance;
    return EKF_STATUS_OK;
}
