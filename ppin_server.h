//==========================================================================================================
// demo_server.h - Defines a TCP command-line server
//==========================================================================================================
#pragma once
#include "cmd_server_base.h"



class CMainServer : public CCmdServerBase
{
public:

    // Default constructor
    CMainServer() : CCmdServerBase() {}

    // This gets called when a client connects to the server socket
    void    on_client_connect();

protected:

    // Whenever a command arrives, this will be called to handle it
    void    handle_command();

    // These are the handlers for each specific command
    bool    handle_add();
    bool    handle_sub();
    bool    handle_mul();
    bool    handle_help();

};