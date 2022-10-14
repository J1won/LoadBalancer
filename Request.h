

#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <string>  
using namespace std;

/// @brief Request class generates values of a random request.

class Request{
public:
     /**
     * Generate a random IPv4 address and processing time.
     * @brief Default constructor.
     */
     Request();

     /**
     * @brief Get in IP address of request.
     * @return String of the IP address.
     */
     string get_IP_in();

     /**
     * @brief Get out IP address of request.
     * @return String of the IP address.
     */
     string get_IP_out();

     /**
     * @brief Get processing time of request.
     * @return Integer of the processing time.
     */
     int get_process_time();
     void dec_time();

private:
     /**
     * The IP in address, IP out address, and processing time of request.
     */
     string IP_in;
     string IP_out;
     int process_time;
     
     string rand_IP();


};

#endif
