

#ifndef REQUEST_H
#define REQUEST_H

#include <string>  
using namespace std;

// generates random ipv4 addresses and times for each request
class Request{
public:
     // constructor 
          // generate random IP address and process time
     Request();
     
     //functions that return ip_in, ip_out, and process_time
     string get_IP_in();
     string get_IP_out();
     int get_process_time();


private:
     string IP_in;
     string IP_out;
     int process_time;

     string rand_IP();


};

#endif
