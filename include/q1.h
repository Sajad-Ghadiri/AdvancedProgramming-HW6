#ifndef Q1_H
#define Q1_H
#include<cmath>

namespace q1
{

template <typename T , typename Func>
double gradient_descent (T init_val , T step_size , Func func=Func{})
{
        T init {init_val } ;
        T func_init_val {func(init)} ;
        T derivative{step_size * ((func(init_val) - func(init_val - 0.001)) / 0.001)};

    while(std::abs(derivative) > 0.000001)
    {

        if( func_init_val > func(init + step_size) )
        {
            init = init + step_size ;
        }
        else if( func_init_val > func(init - step_size) )
        {
            init = init - step_size ;
        }

        else { break ;}

        derivative = step_size * ((func(init) - func(init - 0.001)) / 0.001) ;
        func_init_val = func(init) ;
        

    }

    return init ;
}

}



#endif //Q1_H