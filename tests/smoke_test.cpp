#include <cassert>

#include <embedded_kalman_filter/ekf.h>
#include <embedded_kalman_filter/ekf.hpp>
#include <embedded_kalman_filter/kf.h>
#include <embedded_kalman_filter/kf.hpp>
#include <embedded_kalman_filter/ukf.h>
#include <embedded_kalman_filter/ukf.hpp>

static void test_c_kf() {
    ekf_kf_t model{};
    assert(ekf_kf_init(nullptr, 0.0F, 1.0F, 0.1F, 0.2F) == EKF_STATUS_INVALID_ARGUMENT);
    assert(ekf_kf_init(&model, 0.0F, 1.0F, 0.1F, 0.2F) == EKF_STATUS_OK);
    assert(ekf_kf_predict(&model, 1.0F) == EKF_STATUS_OK);
    assert(ekf_kf_update(&model, 1.2F) == EKF_STATUS_OK);
}

static void test_c_ekf() {
    float state[2] = {0.0F, 0.0F};
    float covariance[4] = {1.0F, 0.0F, 0.0F, 1.0F};
    ekf_ekf_t model{};

    assert(ekf_ekf_init(&model, state, covariance, 0, 0.1F, 0.2F) == EKF_STATUS_INVALID_ARGUMENT);
    assert(ekf_ekf_init(&model, state, covariance, 2, 0.1F, 0.2F) == EKF_STATUS_OK);
    assert(ekf_ekf_predict(&model) == EKF_STATUS_NOT_IMPLEMENTED);
}

static void test_c_ukf() {
    float state[2] = {0.0F, 0.0F};
    float covariance[4] = {1.0F, 0.0F, 0.0F, 1.0F};
    ekf_ukf_t model{};

    assert(ekf_ukf_init(&model, state, covariance, 2, 1.0F, 2.0F, 0.0F) == EKF_STATUS_OK);
    assert(ekf_ukf_update(&model) == EKF_STATUS_NOT_IMPLEMENTED);
}

static void test_cpp_wrappers() {
    embedded_kalman_filter::Kf kf(0.0F, 1.0F, 0.1F, 0.2F);
    assert(kf.predict(0.5F) == EKF_STATUS_OK);
    assert(kf.update(0.7F) == EKF_STATUS_OK);

    float state[2] = {0.0F, 0.0F};
    float covariance[4] = {1.0F, 0.0F, 0.0F, 1.0F};
    embedded_kalman_filter::Ekf ekf(state, covariance, 2, 0.1F, 0.2F);
    embedded_kalman_filter::Ukf ukf(state, covariance, 2, 1.0F, 2.0F, 0.0F);
    assert(ekf.predict() == EKF_STATUS_NOT_IMPLEMENTED);
    assert(ukf.predict() == EKF_STATUS_NOT_IMPLEMENTED);
}

int main() {
    test_c_kf();
    test_c_ekf();
    test_c_ukf();
    test_cpp_wrappers();
    return 0;
}
