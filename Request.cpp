
#include "Request.h"

Request::Request() {
     IP_in = rand_IP();
     IP_out = rand_IP();
     process_time = rand() % 150+70;
}
string Request::get_IP_in() {
     return IP_in;
}
string Request::get_IP_out() {
     return IP_out;
}
int Request::get_process_time() {
     return process_time;
}
void Request::dec_time() {
     cout << "what" <<endl;
     process_time = process_time-1;
     cout << "is" <<endl;
}

string Request::rand_IP() {
     string a = to_string( rand() % 256 );
     string b = to_string( rand() % 256 );
     string c = to_string( rand() % 256 );
     string d = to_string( rand() % 256 );
     return a+"."+b+"."+c+"."+d;
}


