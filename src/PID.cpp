#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = 0.1;
  i_error = 0.001;
  d_error = 0.1;

}

void PID::UpdateError(double cte) {
  // d_error is difference between old cte (p_error) and the new cte
  d_error = (cte - p_error);
  // p_error is set to new cte
  p_error = cte;
  // i_error is the sum of all the ctes to this point
  i_error += cte;
}

double PID::TotalError() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}

