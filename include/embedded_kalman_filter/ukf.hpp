#ifndef EMBEDDED_KALMAN_FILTER_UKF_HPP
#define EMBEDDED_KALMAN_FILTER_UKF_HPP

#include <embedded_kalman_filter/ukf.h>

namespace embedded_kalman_filter {

class Ukf {
public:
    Ukf(float* state_buffer, float* covariance_buffer, unsigned int dimension,
        float alpha, float beta, float kappa) {
        init_status_ = ekf_ukf_init(&model_, state_buffer, covariance_buffer, dimension, alpha, beta, kappa);
    }

    ekf_status_t status() const { return init_status_; }
    ekf_status_t predict() {
        if (init_status_ != EKF_STATUS_OK) {
            return init_status_;
        }
        return ekf_ukf_predict(&model_);
    }
    ekf_status_t update() {
        if (init_status_ != EKF_STATUS_OK) {
            return init_status_;
        }
        return ekf_ukf_update(&model_);
    }
    const ekf_ukf_t& raw() const { return model_; }

private:
    ekf_ukf_t model_{};
    ekf_status_t init_status_ = EKF_STATUS_INVALID_ARGUMENT;
};

}  // namespace embedded_kalman_filter

#endif
