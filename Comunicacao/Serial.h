#ifndef SERIAL_H
#define SERIAL_H

#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>

#include <ProtocoloSerial.h>

class Serial {
private:
    boost::asio::streambuf buf_;
    boost::asio::io_service io_service_;
    boost::asio::streambuf::const_buffers_type buffer_;
    boost::asio::serial_port serial_port_;

    std::vector<unsigned char> buffer_to_send_;

public:
    Serial(std::string serial_port_name);
    ~Serial();

    void send(ProtocoloSerial message_to_send);
};
#endif //SERIAL_H



/* --- CÓDIGO ANTIGO ---
public:
    Serial();
    ~Serial();
    void setDispositivo(std::string _dispositivo);
    bool open();
    void close();
    bool write(const vector <unsigned char> & pacote);
    bool write(const ProtocoloSerial & pacote);

private:
    bool configurar();

    boost::asio::io_service io;
    boost::asio::serial_port serial;

    std::string dispositivo;
    vector<unsigned char> buf;

    int baud_rate;
*/
