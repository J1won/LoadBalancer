#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <string>   
using namespace std;


//takes the request and processes for given time and empties when done.
class Webserver{
public:
     //constructor accepts amount of servers
          // allocate array with server amount of space
          // creates server/processor <server> amount of times
          // and add to the array
     Webserver();

     // deallocate array
     ~Webserver();

     // accept a request() and give to idle processor
     void request_to_server(Request r, int idle_pos); //return out_ip_address

     // find position of idle processor
     int has_idle_processor();

     //all servers empty()
     bool all_processors_empty();

private:
};
#endif

