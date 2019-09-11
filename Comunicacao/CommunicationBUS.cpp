#include "CommunicationBUS.h"

#define NUM_MAX_ROBOS 12

CommunicationBUS::CommunicationBUS()
{
    pacoteIaMonitorador = NULL;
    pacoteSerial.resize(NUM_MAX_ROBOS,NULL);
    pacoteSim.resize(NUM_MAX_ROBOS,NULL);
}

CommunicationBUS::~CommunicationBUS()
{
    delete pacoteIaMonitorador;

    for(uint i = 0; i< NUM_MAX_ROBOS; i++){
        if(pacoteSerial[i] != NULL)
            delete pacoteSerial[i];

        if(pacoteSim[i] != NULL)
            delete pacoteSim[i];
    }
}

void CommunicationBUS::setPacoteRobo(int id, const furgbol::io::F180SerialMessage & protocoloSerial)
{
    pacoteSerial[id] = new furgbol::io::F180SerialMessage;
    *pacoteSerial[id] = protocoloSerial;
}

void CommunicationBUS::limparPacoteRobo(int id)
{
    delete pacoteSerial[id];
    delete pacoteSim[id];
}

void CommunicationBUS::setPacoteRobo(int id, const grSim_Packet & pacoteGrSim)
{
    pacoteSim[id] = new grSim_Packet;
    *pacoteSim[id] = pacoteGrSim;

}

void CommunicationBUS::carregaPacoteMonitorador(const AIDataManagerPackage &_pacoteIaMonitorador)
{
    pacoteIaMonitorador = new AIDataManagerPackage;
    *pacoteIaMonitorador = _pacoteIaMonitorador;
}

furgbol::io::SerialMessage* CommunicationBUS::getPacoteSerial(int id)
{
    furgbol::io::SerialMessage* pacote = NULL;   /// aloca um espaco para o pacote a ser retirado do buffer

    if( pacoteSerial[id] != NULL){    /// se o pacote nao for nulo retira do buffer realmete ( delta)
        pacote = new furgbol::io::F180SerialMessage;
        *pacote = *pacoteSerial[id];
        delete pacoteSerial[id];
        pacoteSerial[id] = NULL;
    }

    return pacote;
}

grSim_Packet* CommunicationBUS::getPacoteSimulador(int id)
{
    /// retorna o pacote e apaga ele do vetor
    grSim_Packet* pacote = NULL;   /// aloca um espaco para o pacote a ser retirado do buffer

    if( pacoteSim[id] != NULL){ /// se o pacote nao for nulo retira do buffer realmete ( delta)
        pacote = new grSim_Packet;
        *pacote = *(pacoteSim[id]);
        delete pacoteSim[id];
        pacoteSim[id] = NULL;
    }

    return pacote;
}

AIDataManagerPackage* CommunicationBUS::getPacoteMonitorador()
{
    AIDataManagerPackage* pacote = NULL;

    if(pacoteIaMonitorador != NULL){
        pacote = new AIDataManagerPackage;
        *pacote = *pacoteIaMonitorador;

        delete pacoteIaMonitorador;
        pacoteIaMonitorador = NULL;
    }

    return pacote;
}
