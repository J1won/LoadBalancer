
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

int Webserver::has_idle_processor() {
     //loop through array and find a server that is not filled()
     // return position of array
     //make sure to loop through whole array even if you found the 
     // idle_pos bc that's how each processor knows the time

}

bool Webserver::all_processors_empty() {
     
     //loop through array
     //if any position is filled,
     //return false immediately
}