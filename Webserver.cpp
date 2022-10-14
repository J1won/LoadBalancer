#include <iostream>
#include "Webserver.h"

Webserver::Webserver(int servers) {
     arr_sz = servers;
     serverCollection = (struct processor *)malloc(sizeof(struct processor) * arr_sz);

     //create <servers> many processor instances add to array
     for (int j = 0; j < arr_sz; j++) {
          processor p(char(65+j));
          serverCollection[j] = p;
     }
}

Webserver::~Webserver() {
     free(serverCollection);
}

void Webserver::request_to_server(Request r, int idle_pos) {
     serverCollection[idle_pos].curr_req_inIP = r.get_IP_in();
     serverCollection[idle_pos].curr_req_outIP = r.get_IP_out();
     serverCollection[idle_pos].curr_req_throughput = r.get_process_time();
}

int Webserver::has_idle_processor(int curr_time) {
     //loop through array and find a server that is not filled()
     // return position of array
     //make sure to loop through whole array even if you found the 
     // idle_pos bc that's how each processor knows the time

     int idle_pos = -1;
     for(int i = 0; i < arr_sz; i++) {
          if(!serverCollection[i].is_filled()) {
               cout << "At " << curr_time << " " << serverCollection[i].name << " is processing request from ";
               cout << serverCollection[idle_pos].curr_req_inIP << " to " << serverCollection[idle_pos].curr_req_outIP << endl; // << " for " << curr_req.get_process_time() <<" clockcycles" << endl;
          }
               idle_pos = i;
     }
     return idle_pos;

}

bool Webserver::all_processors_empty() {
     //loop through array
     //if any position is filled,
     //return false immediately

     for (int i = 0; i < arr_sz; i++) {
          if (serverCollection[i].is_filled())
               return false;
     }
     return true;
}

char Webserver::get_name(int p) {
     return serverCollection[p].name;
}

