#pragma once
namespace FlightComputer {
static constexpr double dt = 0.01;
}
namespace vprop {
static constexpr double m_dry = 1.0;
static constexpr double m_fuel = 1.0;
static constexpr double l = 0.5;
static constexpr double I1 = 0.1;
static constexpr double I2 = 0.1;
static constexpr double I3 = 0.1;
static constexpr double Isp = 250.0;
static constexpr double T_max = 50.0;
static constexpr double T_min = 1.0;
static constexpr double theta_max = 0.261799388;
} // namespace vprop

namespace environment {
static constexpr double g = 9.81;
static constexpr double g0 = 9.81;
} // namespace environment

namespace Attitude {
static constexpr double K_p = 10.0;
static constexpr double K_i = 0;
static constexpr double K_d = 1.0;
} // namespace Attitude
namespace Position {
static constexpr double K_p = 0.01;
static constexpr double K_i = 0;
static constexpr double K_d = 1.0;
} // namespace Position