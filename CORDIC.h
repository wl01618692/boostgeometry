//
// Created by zhangjiayuan on 23-7-14.
//

#ifndef BOOSTGEOMETRY_CORDIC_H
#define BOOSTGEOMETRY_CORDIC_H

//The file cordic.h holds definitions for the data types and constant valuse

#include "cordic.h"

//The cordic_phase array holds the angle for the current rotation
THETA_TYPE cordic_phase[NUM_ITERATIONS] = {
        45, 26.56, 14.036, 7.125
        3.576, 1.790, 0.895, ...
};

// 60
void
cordic(THETA_TYPE theta, COS_SIN_TYPE &s, COS_SIN_TYPE &c)
{
    //Set the initial vector that we will rotate
    //current_cos = I;current = Q
    COS_SIN_TYPE current_cos = 0.0;
    COS_SIN_TYPE current_sin = 0.0;

    //Factor is the 2^(-L) value
    COS_SIN_TYPE factor = 1.0;

    //This loop iteratively rotates the initial vector to find the
    //sine and cosine value corresponding to the input theta angle
    for(int j = 0; j < NUM_ITERATIONS; j++){
        //Determine if we are rotating by a positive or negative angle
        int sigma = (theta < 0) ? -1 : 1;

        //Save the current_cos,so that it can be used in the sine calculation
        COS_SIN_TYPE temp_cos = current_cos;

        //Perform the rotation
        current_cos = current_cos - current_sin * sigma * factor; /// multiplication
        current_sin = current_sin + temp_cos * sigma * factor; /// multiplication

        //Determine the new theta
        theta = theta - sigma * cordic_phase[j]; /// multiplication

        //Calculata next 2^(-L) value
        factor = factor >> 1;
    }

    //Set the final sine and cosine values
    s = current_sin;
    c = current_cos;
}



// The cordic phase array holds the angle for the current rotation
// cordic_phase[0] =˜ 0.785
// cordic_phase[1] =˜ 0.463

void cordic(THETA_TYPE theta, COS_SIN_TYPE &s, COS_SIN_TYPE &c)
{
    // Set the initial vector that we will rotate
    // current cos = I; current sin = Q
    COS_SIN_TYPE current_cos = 0.5;
    COS_SIN_TYPE current_sin = 0.0;

    // This loop iteratively rotates the initial vector to ﬁnd the
    // sine and cosine values corresponding to the input theta angle
    for (int j = 0; j < NUM_ITERATIONS; j++) {
        // Multiply previous iteration by 2ˆ(−j). This is equivalent to
        // a right shift by j on a ﬁxed−point number.
        COS_SIN_TYPE cos_shift = current_cos >> j;
        COS_SIN_TYPE sin_shift = current_sin >> j;

        // Determine if we are rotating by a positive or negative angle
        if(theta >= 0) {
            // Perform the rotation
            current_cos = current_cos − sin_shift;
            current_sin = current_sin + cos_shift;

            // Determine the new theta theta = theta − cordic_phase[j];
        } else {
            // Perform the rotation
            current_cos = current_cos + sin_shift;
            current_sin = current_sin − cos_shift;

            // Determine the new theta
            theta = theta + cordic_phase[j];
        }
    }
    // Set the ﬁnal sine and cosine values
    s = current_sin;
    c = current_cos;
}


#endif //BOOSTGEOMETRY_CORDIC_H
