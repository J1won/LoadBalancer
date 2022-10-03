
//holds a queue of requests and keeps track of time

#include <iostream>
#include <queue>
#include "Webserver.h"
#include "Request.h"
using namespace std;

int main() {

     int servers = 0;
     int time = 0;
     int idle_pos = -1;
     Request curr_req;
     queue<Request> requests_q; //queue of requests

     //ask for # servers
     //ask for time to run
     cout << "Number of servers: ";
     cin >> servers;
     cout << "Time to run: "; //how long to run the load balancer
     cin >> time;

     Webserver wb(servers);

     //create an initial queue of server*2
     for (int i = 0; i < servers*2; i++) {
          Request r;
          requests_q.push(r);
     }

     //manage the time
     for (int curr_time = 0; curr_time < time; curr_time++) {
          // simulate requests added at random times
          if (rand() % 2 > 0) {
               Request r;
               requests_q.push(r);
          }

          //if idle server, pop and send request to server
          idle_pos = wb.has_idle_processor();
          if (idle_pos != -1 && !requests_q.empty()){
               curr_req = requests_q.front();
               wb.request_to_server(curr_req, idle_pos);
               requests_q.pop();

               cout << "At " << curr_time << " " << wb.get_name(idle_pos) << " is processing request from ";
               cout << curr_req.get_IP_in() << " to " << curr_req.get_IP_out() << endl; // << " for " << curr_req.get_process_time() <<" clockcycles" << endl;
          }

          //exit when time is done OR (queue is empty AND all requests complete)
          if( requests_q.empty() && wb.all_processors_empty())
               break;
     }
     return 0;
}