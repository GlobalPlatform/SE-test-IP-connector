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

#include <client/client_api.hpp>
#include <client/requests/command.hpp>
#include <client/requests/diag.hpp>
#include <client/requests/disconnect.hpp>
#include <client/requests/echo.hpp>
#include <client/requests/flyweight_requests.hpp>
#include <client/requests/request.hpp>
#include <constants/request_code.hpp>
#include <terminal/flyweight_terminal_factory.hpp>
#include <terminal/terminals/example_pcsc_contact.hpp>
#include "plog/include/plog/Log.h"

using namespace client;

int __cdecl main(void) {
	// config available terminal factories
//	FlyweightTerminalFactory available_terminals;
//	available_terminals.addFactory("PCSC", new PCSCFactory());
//
//	// config all requests the client can handle
//	FlyweightRequests available_requests;
//	available_requests.addRequest(REQ_COMMAND, new Command());
//	available_requests.addRequest(REQ_DIAG, new Diag());
//	available_requests.addRequest(REQ_DISCONNECT, new Disconnect());
//	available_requests.addRequest(REQ_ECHO, new Echo());

//	ClientAPI client;
//	client.initClient("./config/init.json", available_terminals, available_requests);
//	ResponsePacket response = client.loadAndListReaders();
//	LOG_DEBUG << response.response;
//	client.connectClient(0);
	return 0;
}
