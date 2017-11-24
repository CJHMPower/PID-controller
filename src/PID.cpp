#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
     p_error=0.0;
     i_error=0.0;
     d_error=0.0;
     Kp=Kp_;
     Ki=Ki_;
     Kd=Kd_;
     last_p_error=0;
     total_err=0;
     is_initialize=true;
}

void PID::UpdateError(double cte) {
     d_error=cte-last_p_error;
     p_error=cte;
     i_error+=cte;
     last_p_error=p_error;
     total_err+=cte*cte;
     
}

double PID::TotalError() {
       return -Kp*p_error-Ki*i_error-Kd*d_error;
}

