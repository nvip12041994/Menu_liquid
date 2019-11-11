#include "data.h"
#include <Arduino.h>
void data::set_data_uint8_t(uint8_t id, uint8_t data = 0){
    switch (id)
    {
    case 21:
        /* code */
        K1 = data;
        break;
    case 22:
        /* code */
        k2 = data;
        break;
    case 23:
        /* code */
        K3 = data;
        break;
    case 24:
        /* code */
        Alpha = data;
        break;
    case 25:
        /* code */
        Beta = data;
        break;
    case 26:
        /* code */
        Gamma = data;
        break;
    default:
        break;
    }
}

void data::set_data_float(uint8_t id, float data = 0){
    switch (id)
    {
    case 27:
        /* code */
        Nb_Th = data;
        break;
    case 28:
        /* code */
        Nb_U = data;
        break;
    case 29:
        /* code */
        Nb_K = data;
        break;
    default:
        break;
    }
}


uint8_t data::get_data_uint8_t(uint8_t id){
    uint8_t data;
    switch (id)
    {
    case 21:
        /* code */
        data = K1;
        break;
    case 22:
        /* code */
        data = k2;
        break;
    case 23:
        /* code */
        data = K3;
        break;
    case 24:
        /* code */
        data = Alpha;
        break;
    case 25:
        /* code */
        data = Beta;
        break;
    case 26:
        /* code */
        data = Gamma;
        break;
    default:
        break;
    }
    return data;
}

float data::get_data_float(uint8_t id){
    float data;
    switch (id)
    {
    case 27:
        /* code */
        data = Nb_Th;
        break;
    case 28:
        /* code */
        data = Nb_U;
        break;
    case 29:
        /* code */
        data = Nb_K;
        break;
    default:
        break;
    }
    return data;
}