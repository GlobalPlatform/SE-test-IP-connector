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

#ifndef TERMINAL_TERMINALS_TERMINAL_PCSC_CONTACTLESS_IDENTIV_H_
#define TERMINAL_TERMINALS_TERMINAL_PCSC_CONTACTLESS_IDENTIV_H_

#define DEFAULT_BUFLEN 1024 * 64

#define TYPE_A 0x00
#define TYPE_B 0x01
#define TYPE_AB (TYPE_A || TYPE_B)
#define TYPE_F 0x60
#define TYPE_AF 0x19
#define TYPE_BF 0x1A
#define TYPE_ABF 0x1B

#define RET_OK 0;
#define ERR_CMD_GET_TYPE -1;
#define ERR_RET_GET_TYPE -2;
#define ERR_CMD_SET_TYPE -3;
#define ERR_RET_SET_TYPE -4;
#define ERR_CMD_GET_FIELD_STATE -5;
#define ERR_RET_GET_FIELD_STATE -6;
#define ERR_CMD_SET_FIELD_STATE -7;
#define ERR_RET_SET_FIELD_STATE -8;
#define ERR_CARD_RECONNECT -9;



#include "terminal/terminals/terminal.hpp"
#include "constants/response_packet.hpp"

#include <map>
#include <string>
#include <winscard.h>

namespace client {

class ExampleTerminalPCSCContactless_IDENTIV: public ITerminalLayer {
private:
	std::string current_reader_;
	SCARDCONTEXT hContext_;
	LPTSTR mszReaders_;
	SCARDHANDLE hCard_;
	DWORD dwReaders_, dwActiveProtocol_, dwRecvLength_;
	SCARD_IO_REQUEST pioSendPci_;
	BYTE pbRecvBuffer_[DEFAULT_BUFLEN];
	BYTE currentPollingType_;
public:
	ExampleTerminalPCSCContactless_IDENTIV() = default;
	~ExampleTerminalPCSCContactless_IDENTIV();
	ResponsePacket init() override;
	ResponsePacket loadAndListReaders() override;
	ResponsePacket connect(const char* reader) override;
	ResponsePacket sendCommand(unsigned char command[], unsigned long int command_length) override;
	ResponsePacket sendTypeA(unsigned char command[], unsigned long int command_length) override;
	ResponsePacket sendTypeB(unsigned char command[], unsigned long int command_length) override;
	ResponsePacket sendTypeF(unsigned char command[], unsigned long int command_length) override;
	ResponsePacket diag() override;
	ResponsePacket disconnect() override;
	ResponsePacket deactivate_Interface() override;
	ResponsePacket isAlive() override;
	ResponsePacket restart() override;
	ResponsePacket coldReset() override;
	ResponsePacket warmReset() override;
	ResponsePacket powerOFFField() override;
	ResponsePacket powerONField() override;
	ResponsePacket pollTypeA() override;
	ResponsePacket pollTypeB() override;
	ResponsePacket pollTypeF() override;
	ResponsePacket pollTypeAllTypes() override;
	ResponsePacket getNotifications() override;
	ResponsePacket clearNotifications() override;
	ResponsePacket automaticInterfaceSwitching() override;
	ResponsePacket activate_Interface() override;
private:
	ResponsePacket handleErrorResponse(std::string context_message, LONG error);
	ResponsePacket retrieveAtr(BYTE* bAttr, DWORD* cByte);
	int sendEscapeCommand(unsigned char* command, unsigned long int* command_length);
	int sendInternalCommand(unsigned char* command, unsigned long int* command_length);
	int switchPollingType(byte pollingType);
	int powerFieldState();
	int getType();
	std::string errorToString(LONG error);
	LONG handleRetry();
	ResponsePacket disconnect_HW();
	ResponsePacket reconnect_HW();
	int reset_Field();

};

} /* namespace client */

#endif /* TERMINAL_TERMINALS_TERMINAL_PCSC_CONTACTLESS_IDENTIV_H_ */
