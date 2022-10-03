#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <string>   
using namespace std;

struct processor {
     int curr_req_throughput;
     string curr_req_inIP;
     string curr_req_outIP;
     char name;

     //has name attribute
     //hold info about request
     processor(char n) : name(n) {
          curr_req_throughput = 0;
          curr_req_inIP = "";
          curr_req_outIP = "";
     }
     //each time the processor is checked,
     //the curr_req_throughput decrements.
     //curr_req_throughput = 0 means it is empty;
     bool is_filled() {
          curr_req_throughput--;
          return curr_req_throughput > 0;
     }

};


//takes the request and processes for given time and empties when done.
class Webserver{
public:
     //constructor accepts amount of servers
          // allocate array with server amount of space
          // creates server/processor <server> amount of times
          // and add to the array
     Webserver(int servers);

     // deallocate array
     ~Webserver();

     // accept a request() and give to idle processor
     void request_to_server(Request r, int idle_pos); //return out_ip_address

     // find position of idle processor
     int has_idle_processor();

     //all servers empty()
     bool all_processors_empty();

private:
     processor *serverCollection;
     int arr_sz;
};
#endif

