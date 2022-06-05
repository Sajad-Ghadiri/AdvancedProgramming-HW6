#ifndef Q1_H
#define Q1_H
#include<cmath>

namespace q1
{

template <typename T , typename Func>
double gradient_descent (T init_val , T step_size , Func func=Func{})
{   
        T init {init_val } ;          // starting point
        T func_init_val {func(init)} ; // function value at starting point

        // derivative of function at calculating it at starting point
        T derivative{step_size * ((func(init_val) - func(init_val - 0.00001)) / 0.00001)}; 

    //////////// while loop to converge the algorith and reach the minimum of function
    while(std::abs(derivative) > 0.00001)
    {
        //// where is the starting point is important 
        /// because we move forward ord backward depends on the sign of derivative
        if( func_init_val > func(init + step_size) )
        {
            init = init + step_size ;
        }
        else if( func_init_val > func(init - step_size) )
        {
            init = init - step_size ;
        }
        else { break ;}
        //// update the value of function at starting point
        derivative = step_size * ((func(init) - func(init - 0.00001)) / 0.00001) ;
        func_init_val = func(init) ;
    }
    return init ;
}

}



#endif //Q1_H