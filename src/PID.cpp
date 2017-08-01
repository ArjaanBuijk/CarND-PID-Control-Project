#include <math.h>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  cte_previous_   = 0.0;
  cte_total_      = 0.0;
  is_initialized_ = false;
}

PID::~PID() {}

double PID::Update(double cte) {
  if (is_initialized_ == false){
    is_initialized_ = true;
    cte_previous_ = cte;
  }
  // note: delta_t is not provided, use 1.0 and tune Kd_
  double delta_t = 1.0;

  cte_total_ += cte;

  double steering = 0.0;
  steering -= Kp_ * cte;                                 // P control
  steering -= Ki_ * cte_total_;                          // I control
  steering -= Kd_ * (cte-cte_previous_)/delta_t;  // D control

  cte_previous_ = cte;

  return steering;
}


