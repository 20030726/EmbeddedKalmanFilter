#ifndef EMBEDDED_KALMAN_FILTER_KF_HPP
#define EMBEDDED_KALMAN_FILTER_KF_HPP

#include <embedded_kalman_filter/kf.h>

namespace embedded_kalman_filter {

class Kf {
public:
    Kf(float initial_state, float initial_covariance, float process_noise, float measurement_noise) {
        ekf_kf_init(&model_, initial_state, initial_covariance, process_noise, measurement_noise);
    }

    ekf_status_t predict(float control_input) { return ekf_kf_predict(&model_, control_input); }
    ekf_status_t update(float measurement) { return ekf_kf_update(&model_, measurement); }
    const ekf_kf_t& raw() const { return model_; }

private:
    ekf_kf_t model_{};
};

}  // namespace embedded_kalman_filter

#endif
