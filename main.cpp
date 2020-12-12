#include "BloodResourceFactory.h"
#include "BloodServiceSettingsFactory.h"
#include "BloodService.h"
#include "iostream"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <thread>

using namespace std;

void reader(int);
void api_start(BloodService *);

int main(int argc, char** argv){
    auto resource_factory = make_shared<BloodResourceFactory>();
    auto setting_factory = make_shared<BloodServiceSettingsFactory>();
    BloodService service{resource_factory, setting_factory};

    //*************
    termios SerialPortSettings;

    int fd;
    fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY);

    if(fd == -1)
        cout << "Error! in opening ttyS1" << endl;
    else{
        cout << "ttyS1 opened successfuly" << endl;

        tcgetattr(fd, &SerialPortSettings);

        cfsetispeed(&SerialPortSettings, B9600);
        cfsetospeed(&SerialPortSettings, B9600);

        SerialPortSettings.c_cflag &= ~PARENB;
        SerialPortSettings.c_cflag &= ~CSTOPB;
        SerialPortSettings.c_cflag &= ~CSIZE;
        SerialPortSettings.c_cflag |= CS8;
        SerialPortSettings.c_cflag &= ~CRTSCTS;
        SerialPortSettings.c_cflag |= CREAD | CLOCAL;
        SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
        SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

        SerialPortSettings.c_oflag &= ~OPOST;

        SerialPortSettings.c_cc[VMIN] = 10;
        SerialPortSettings.c_cc[VTIME] = 0;

        if((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0)
            cout << "Error in setting attributes" << endl;
        else
            cout << "BaudRate = 9600 StopBits = 1 Parity = none" << endl;

        tcflush(fd, TCIFLUSH);

        thread t_serial(reader, fd);
        t_serial.detach();

        thread t_api(api_start, &service);
        t_api.detach();

        // string test;
        // cout << "wait for type: ";
        // cin >> test;
        // cout << "end of program " << test << endl;
        // cout << endl;
    }

    close(fd);
    //*************

    return 0;
}

void reader(int fd)
{
    char read_buffer[32];
    int bytes_read = 0;
    int i=0;

    while (true)
    {
        bytes_read = read(fd, &read_buffer, 32);

        cout << "Bytes read " << bytes_read << endl
             << endl;

        for (i = 0; i < bytes_read; i++)
        {
            //cout << "test" << endl;
            cout << read_buffer[i];
        }
        cout << endl;
    }
}

void api_start(BloodService *service){
        cout << "start API" << endl;
        service->start();
}