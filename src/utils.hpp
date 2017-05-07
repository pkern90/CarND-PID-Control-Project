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

double Sigmoid(double value, double lower, double upper){
    double range = upper - lower;
    return range / (1 + exp(-value)) + lower;
}

#endif //PID_UTILS_HPP
