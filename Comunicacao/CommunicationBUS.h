#ifndef BARRAMENTOCOMUNICACAO_H
#define BARRAMENTOCOMUNICACAO_H

#include "furgbol-core/io/f180_serial_message.h"
#include "grSim-proto/grSim_Packet.pb.h"
#include "furgbol-core/furgbol-proto/messages_ai_data_manager.pb.h"
#include "Utils/Definitions.h"

class CommunicationBUS
{
private:
    std::vector<furgbol::io::F180SerialMessage*> pacoteSerial;  ///< vetor de pacotes contendo um para cada robo para enviar aos robos
    std::vector<grSim_Packet*> pacoteSim; ///< vetor de pacotes contendo um para cada robo para enviar ao simulador
    AIDataManagerPackage* pacoteIaMonitorador; ///< Pacote que sera enviado para ser monitorado no gerente de dados

public:
    CommunicationBUS();
    ~CommunicationBUS();

    void setPacoteRobo(int id, const furgbol::io::F180SerialMessage&);
    void limparPacoteRobo(int id);
    void setPacoteRobo(int id, const grSim_Packet&);
    void carregaPacoteMonitorador(const AIDataManagerPackage& _pacoteIaMonitorador); ///< Carrega apenas se a monitoracao estiver habilitada

    furgbol::io::F180SerialMessage* getPacoteSerial(int id);
    grSim_Packet* getPacoteSimulador(int id);
    AIDataManagerPackage* getPacoteMonitorador();
};

#endif // BARRAMENTOCOMUNICACAO_H
