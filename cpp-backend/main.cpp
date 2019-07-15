#include <dlib/server.h>
#include <iostream>
#include <sstream>
#include <string>

#include "checkers-dylib.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace dlib;
using namespace std;

class web_server : public server_http {
    const std::string on_request(const incoming_things& incoming,
                                 outgoing_things& outgoing) {
        ostringstream sout;

        outgoing.headers["Access-Control-Allow-Origin"] = "*";
        outgoing.headers["Access-Control-Allow-Methods"] = "POST, GET";
        outgoing.headers["Access-Control-Allow-Headers"] =
            incoming.headers["Access-Control-Request-Headers"];
        if (incoming.request_type == "OPTIONS") return "";

        /*
        cout << "incoming path: " << incoming.path << endl;
        cout << "incoming request type: " << incoming.request_type << endl;
        cout << "incoming content type: " << incoming.content_type << endl;
        cout << "incoming protocol: " << incoming.protocol << endl;
        cout << "incoming body: " << incoming.body << endl;

        cout << "incoming headers:" << endl;
        int i = 0;
        for (const auto& pr : incoming.headers)
            cout << i++ << ", " << pr.first << ": " << pr.second << endl;

        cout << endl;
        */

        // cout << incoming.body << endl;

        string js_str = incoming.body;
        json js = json::parse(js_str); 
        string str = js["board"]; 

        // std::cout << js_str << std::endl; 
        // std::cout << str << std::endl; 

        char player = str.back();
        // str.pop_back();
        for (auto& i : str) {
            if (i == '0') i = '_';
            else if (i == '1') i = 'b';
            else if (i == '2') i = 'w';
            else if (i == '3') i = 'B';
            else if (i == '4') i = 'W';
        }
        string ret = checkers_process(str, player);

        cout << str << " " << ret << endl; 

        // return "haha";
        return ret;
    }
};

int main() {
    try {
        // create an instance of our web server
        web_server our_web_server;

        // make it listen on port 5000
        our_web_server.set_listening_port(22345);
        // Tell the server to begin accepting connections.
        our_web_server.start_async();

        cout << "Press enter to end this program" << endl;
        cin.get();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}