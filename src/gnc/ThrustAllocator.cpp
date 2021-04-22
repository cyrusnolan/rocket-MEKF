#include "gnc/ThrustAllocator.hpp"

void ThrustAllocator(Vector3d &T_des, Vector3d &M_des, EngineActuation &actuation) {
  Vector3d T_body; // Thrust in the body frame
  Vector3d T_gimbal; // Thrust in the gimbal frame
  Vector3d nhat;
  double theta;

  T_gimbal << 0, 0, T_des.norm();
  double T_x = -M_des(1, 0) / vprop::l;
  double T_y = M_des(0, 0) / vprop::l;
  double T_z = sqrt(pow(T_des.norm(), 2) - pow(T_x,2) - pow(T_y,2));
  T_body << T_x, T_y, T_z;

  nhat = cross(T_gimbal, T_body);
  nhat.normalize();
  theta = acos(dot(T_gimbal, T_body) / pow(T_des.norm(), 2));

  actuation.throttle = T_des.norm();
  actuation.axis = nhat;
  actuation.angle = theta;
}