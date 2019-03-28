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

#ifndef TERMINAL_TERMINALS_TERMINAL_PCSC_H_
#define TERMINAL_TERMINALS_TERMINAL_PCSC_H_

#define DEFAULT_BUFLEN 1024 * 64

#include <map>
#include <winscard.h>

#include "terminal.h"
#include "../../constants/response_packet.h"

namespace client {

class TerminalPCSC: public ITerminalLayer {
private:
	SCARDCONTEXT hContext;
	LPTSTR mszReaders;
	SCARDHANDLE hCard;
	DWORD dwReaders, dwActiveProtocol, dwRecvLength;
	SCARD_IO_REQUEST pioSendPci;
	BYTE pbRecvBuffer[DEFAULT_BUFLEN];
public:
	TerminalPCSC() {};
	~TerminalPCSC();
	ResponsePacket init();
	ResponsePacket loadAndListReaders();
	ResponsePacket connect(const char* reader);
	ResponsePacket sendCommand(unsigned char command[], unsigned long int command_length);
	ResponsePacket sendTypeA(unsigned char command[],  unsigned long int command_length);
	ResponsePacket sendTypeB(unsigned char command[],  unsigned long int command_length);
	ResponsePacket sendTypeF(unsigned char command[],  unsigned long int command_length);
	ResponsePacket diag();
	ResponsePacket disconnect();
	ResponsePacket isAlive();
	ResponsePacket restart();
	ResponsePacket coldReset();
	ResponsePacket warmReset();
	ResponsePacket powerOFFField();
	ResponsePacket powerONField();
	ResponsePacket handleErrorResponse(std::string context_message, LONG error);
	std::string errorToString(LONG error);
};

} /* namespace client */

#endif /* TERMINAL_TERMINALS_TERMINAL_PCSC_H_ */
