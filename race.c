#include "abdrive.h"
#include "simpletools.h"
#include <stdio.h>
#include "ping.h"


int irRight;

void turn(float factor){
    drive_speed((120+factor)/1.2,(120-factor)/1.2);
}

float calculate_factor(int errorValue, int derivative){
    return (3*errorValue + 0.5*derivative);
}



calculate_distance(int *irLeft){
    *irLeft = 0;
    
    for(int dacVal = 0; dacVal < 160; dacVal += 8)
    {
        dac_ctr(26, 0, dacVal);
        freqout(11, 1, 38000);
        *irLeft += input(10);
        
    }
}



int main()

{
    low(26);
    low(27);
    
    int approx_deriv = 0;
    int errorval = 0;
    float factor;
    
    
    
    while(1)
        
    {
        
        calculate_distance(&irLeft);
        pause(50);
        int temp = errorval;
        errorval = 15-irLeft;
        approx_deriv = errorval - temp;
        factor = calculate_factor(errorval, approx_deriv);
        old_structure = add(factor, old_structure);
        turn(factor);
        
        //if (ping_cm(8) < 15){
        //    drive_goto(12,-12);
        //}
    }
        
}


