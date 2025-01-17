/*********************************************************************************
 Copyright 2017 GlobalPlatform, Inc.

 Licensed under the GlobalPlatform/Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 https://github.com/GlobalPlatform/SE-test-IP-connector/blob/master/Charter%20and%20Rules%20for%20the%20SE%20IP%20connector.docx

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 *********************************************************************************/

#ifndef INCLUDE_CLIENT_REQUESTS_ACTIVATE_INTERFACE_HPP_
#define INCLUDE_CLIENT_REQUESTS_ACTIVATE_INTERFACE_HPP_

#include "client/requests/request.hpp"
#include "terminal/terminals/terminal.hpp"

namespace client {

class ClientEngine;
class Activate_Interface: public IRequest {
public:
	Activate_Interface() = default;
	~Activate_Interface() = default;
	ResponsePacket run(ITerminalLayer* terminal, ClientEngine* client_engine, char unsigned command[], DWORD command_length) override;
};

}

#endif /* INCLUDE_CLIENT_REQUESTS_ACTIVATE_INTERFACE_HPP_ */
