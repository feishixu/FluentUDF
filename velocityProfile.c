// 1. 入口速度是位置的函数，以抛物线形入口为例：

#include "udf.h"
#include "math.h"
DEFINE_PROFILE(inlet_x_velocity, thread, position)
{
    real x[ND_ND];              
    real y;
    face_t f;
    begin_f_loop(f, thread)
    {
    	F_CENTROID(x,f,thread);
    	y = x[1];
    	F_PROFILE(f, thread, position) = 1.5*1.0*4.0/0.1681*y*(0.41-y);
    }
    end_f_loop(f, thread)
}



// 2.入口速度是时间的函数：

#include "udf.h"
#include "math.h"
DEFINE_PROFILE(unsteady_velocity, thread, position)
{
    face_t f;
    begin_f_loop(f, thread)
    {
	real t = RP_Get_Real("flow-time");
	F_PROFILE(f, thread, position) = 0.0333*t/sqrt(t*t+0.0001);
    }
    end_f_loop(f, thread)
}
