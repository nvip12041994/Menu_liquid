#include <Arduino.h>
class calculate;
class data {
    friend calculate;
private:
    uint8_t tb; // thoi gian dem phong
    uint8_t td1;
    uint8_t td2;
    uint8_t td3;
    uint8_t B_Th;
    uint8_t B_U;
    uint8_t B_K;
    float Nb_Th = 0;//
    float Nb_U = 0;//
    float Nb_K = 0;//
    uint8_t C1_Th;
    uint8_t C1_U;
    uint8_t C1_K;
    float Nb1_Th;
    float Nb1_U;
    float Nb1_K;
    uint8_t C2_Th;
    uint8_t C2_U;
    uint8_t C2_K;
    float Nb2_Th;
    float Nb2_U;
    float Nb2_K;
    uint8_t C3_Th;
    uint8_t C3_U;
    uint8_t C3_K;
    float Nb3_Th;
    float Nb3_U;
    float Nb3_K;
    float eTh;
    float eU;
    float eK;
    uint8_t K1 = 0; //
    uint8_t k2 = 0; //
    uint8_t K3 = 0; //
    uint8_t Alpha = 0; //
    uint8_t Beta = 0;//
    uint8_t Gamma = 0;//
public:
    void set_data_uint8_t(uint8_t id, uint8_t data = 0);
    void set_data_float(uint8_t id, float data = 0);
    uint8_t get_data_uint8_t(uint8_t id);
    float get_data_float(uint8_t id);
};

class calculate {
    public:
    void test();
};