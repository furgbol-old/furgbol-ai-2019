#ifndef PROTOCOLOSERIAL_H
#define PROTOCOLOSERIAL_H

#include "Comando.h"
#include "Definitions.h"


enum ProtocoloSerialHeaderFlags {
    ROBOT_ID = 0, VEL_X = 1, VEL_Y = 2, VEL_THETA = 3, DIR_X = 4, DIR_Y = 5, DIR_THETA = 6,
    DRIBBLER = 7, KICK = 8
};


/**
  \class ProtocoloSerial

    \brief  Classe responsável pela organização e serialização do pacote de envio serial
  */
class ProtocoloSerial {
private:
    uint16_t pkg_id_;
    uint8_t msg_type_;
    uint8_t robot_id_;
    uint8_t velocity_x_;
    uint8_t velocity_y_;
    uint8_t velocity_theta_;
    uint8_t direction_x_;
    uint8_t direction_y_;
    uint8_t direction_theta_;
    uint8_t dribbler_;
    uint8_t kick_;

public:
    ProtocoloSerial();
    ~ProtocoloSerial();

    void serialize(std::vector<uint8_t> &buffer);

    void clear();

    //Stream to print the message
    friend std::ostream &operator <<(std::ostream &, ProtocoloSerial const &);

    //Setters
    void setRobotId(uint8_t robot_id);
    void setVelocityX(uint8_t velocity_x);
    void setVelocityY(uint8_t velocity_y);
    void setVelocityTheta(uint8_t velocity_theta);
    void setDirectionX(uint8_t direction_x);
    void setDirectionY(uint8_t direction_y);
    void setDirectionTheta(uint8_t direction_theta);
    void setDribbler(uint8_t dribbler);
    void setKick(uint8_t kick);

    //Getters
    uint16_t getPkgId();
    uint8_t getMsgType();
    uint8_t getRobotId();
    uint8_t getVelocityX();
    uint8_t getVelocityY();
    uint8_t getVelocityTheta();
    uint8_t getDirectionX();
    uint8_t getDirectionY();
    uint8_t getDirectionTheta();
    uint8_t getDribbler();
    uint8_t getKick();
};

#endif // PROTOCOLOSERIAL_H




/* ---- CÓDIGO ANTIGO ---
public:
    ProtocoloSerial();

    void setId(unsigned char _id);
    void limpaPacote();


    void setVelocidadePercentualRodas(int numRoda, unsigned char _vel);
    void setVelocidadePercentualRodas(vector <unsigned char> _vel);

    void setDirecaoRodas(int numRoda, Direcao _dir);
    void setDirecaoRodas(vector<Direcao> _dir);

    void setVelocidadePercentualDriblador(unsigned char _vel);
    void setDirecaoDriblador(Direcao _dir);

    void setTipoChute(Comando::TipoChute _tipoChute);

    void setNivelChute(unsigned char _nivelPercentual);

    void setEnableDrible(bool _enable);

    void setEnableChute(bool _enable);

    void serializa(vector <unsigned char> & buffer) const;

    friend ostream & operator<<(ostream & out, ProtocoloSerial pct);

private:
    unsigned char id;
    vector <unsigned char> velocidadePercentualRodas;
    unsigned char velocidadePercentualDriblador;
    vector <Direcao> direcaoRodas;
    Direcao direcaoDriblador;
    Comando::TipoChute tipoChute;
    unsigned char nivelChute;
    unsigned char enableChute;
    bool enableDrible;

    void printData() const;

    **PARA O MODELO CINEMATICO
    float raio;                     //Raio do Robo
    float raioDaRoda;               //Raio da roda do robo

    cv::Mat_ <float> matrizRotacao;     //Matriz para transformar o sist de coordenadas do global para o do robo
    cv::Mat_ <float> M;                 //Matriz de transformação de velocidades vx,vy,vgiro para as rodas
    cv::Mat_ <float> pInvM;             //Matriz pseudo inversa da matriz M

    static const int VEL_MAX_RODAS = 126;   //!< DESCOBRIR ESSE VALOR*/
