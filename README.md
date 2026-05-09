# EmbeddedKalmanFilter

C/C++ scaffold for an embedded Kalman filter library.

## Current modules

- KF (Kalman Filter)
- EKF (Extended Kalman Filter)
- UKF (Unscented Kalman Filter)

## Repository structure

- `include/embedded_kalman_filter`: public C/C++ headers
- `src`: C implementations
- `tests`: smoke tests

## Build and test

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Notes

- KF has a basic working predict/update flow for 1D state.
- EKF and UKF interfaces are scaffolded; predict/update are placeholders returning `EKF_STATUS_NOT_IMPLEMENTED` for upcoming implementation.
