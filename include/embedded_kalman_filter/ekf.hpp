#ifndef EMBEDDED_KALMAN_FILTER_EKF_HPP
#define EMBEDDED_KALMAN_FILTER_EKF_HPP

#include <embedded_kalman_filter/ekf.h>

namespace embedded_kalman_filter {

class Ekf {
public:
    Ekf(float* state_buffer, float* covariance_buffer, unsigned int dimension,
        float process_noise, float measurement_noise) {
        ekf_ekf_init(&model_, state_buffer, covariance_buffer, dimension, process_noise, measurement_noise);
    }

    ekf_status_t predict() { return ekf_ekf_predict(&model_); }
    ekf_status_t update() { return ekf_ekf_update(&model_); }
    const ekf_ekf_t& raw() const { return model_; }

private:
    ekf_ekf_t model_{};
};

}  // namespace embedded_kalman_filter

#endif
