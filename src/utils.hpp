//
// Created by patrick on 06.05.17.
//

#ifndef PID_UTILS_HPP
#define PID_UTILS_HPP

double Clip(double value, double lower, double upper){
    if(value < lower){
        return lower;
    } else if(value > upper){
        return upper;
    }
}

#endif //PID_UTILS_HPP
