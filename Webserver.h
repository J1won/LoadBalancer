#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <string>   
using namespace std;

/// @brief Processor struct holds and drops a request

struct processor {
     /**
     * The time, IP in, and IP out of the current request.
     */
     int curr_req_throughput;
     string curr_req_inIP;
     string curr_req_outIP;

     /**
     * The name of the processor.
     */
     char name;

     /**
     * Assign the given name to the processor and initialize the Request values.
     * @brief Default constructor.
     * @param n Name of the processor
     */
     processor(char n) : name(n) {
          curr_req_throughput = 0;
          curr_req_inIP = "";
          curr_req_outIP = "";
     }

     /**
     * @brief Return if the processor is filled and decrement the Request time to keep track of the processing time.
     * @return true if the request time is not done.
     * @return false if the request time is done.
     */
     bool is_filled() {
          curr_req_throughput--;
          return curr_req_throughput > 0;
     }

};

///@brief Webserver class accepts a request and sends it to a processor
class Webserver{
     
public:
     /**
     * Create specified amount of Processors and add to dynamic array
     * @brief Default constructor.
     * @param servers The size of serverCollection
     */
     Webserver(int servers);


     /**
     * @brief Frees the space allocated to array
     */
     ~Webserver();

     /**
     * @brief Accept a request and insert into empty processor.
     */
     void request_to_server(Request r, int idle_pos);

     /**
     * @brief Returns position the next empty server.
     * @return Integer of idle processor location.
     * @return -1 if there is no idle processor.
     */
     int has_idle_processor();

     /**
     * @brief Checks if all processors are empty.
     * @return true if all processors are empty.
     * @return false if any processor has a request.
     */
     bool all_processors_empty();

     /**
     * @brief Get name of the processor.
     * @param p Position of the processor.
     * @return Character identifying the processor.
     */
     char get_name(int p);

private:
     /**
     * Dynamic array that holds the processors.
     */
     processor *serverCollection;

     /**
     * Size of dynamic array.
     */
     int arr_sz;
};
#endif

