
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
     queue<Request> requests_q; //queue of requests

     //ask for # servers
     //ask for time to run
     cout << "Number of servers: ";
     cin >> servers;
     cout << "Time to run: "; //how long to run the load balancer
     cin >> time;

     //create an initial queue of server*2
     for (int i = 0; i < servers*2; i++) {
          Request r;
          requests_q.push(r);
     }

     //manage the time
     //for (int curr_time = 0; curr_time < t; curr_time++) {

          // if there is empty server:
               //pop and send request to server


          // exit when time is done OR (queue is empty AND all requests complete)
          //if( requests_q.empty() && no processor is holding a request)
     //}

     


     return 0;
}