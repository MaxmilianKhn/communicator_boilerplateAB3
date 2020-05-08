/*
 * communicator.c
 *
 *  Created on: 07.05.2020
 *      Author: maxim
 */
#include "communicator.h"
#include "../packet/packet.h"
#include <stdio.h>

static void cbNetworkReceive(uint8_t *pBuffer, uint32_t len);

int8_t communicator_connect(Server_e server) {

	int serverPort;
	char serverIP[15];
	sprintf(serverIP,"%d.%d.%d.%d",(server>>24)&0xFF,(server>>16)&0xFF,(server>>8)&0xFF,server&0xFF);
	switch (server) {
	case TEST_SERVER:
		serverPort = 7;
		break;
	default:
		return -3;
	}

	if (!network_init(cbNetworkReceive)) {
		return -1;
	}
	if (!network_connect(serverIP, serverPort)) {
		return -2;
	}
	return 0;
}

static void cbNetworkReceive(uint8_t *pBuffer, uint32_t len) {
	printf("Packet received with len=%d.\r\n", len);
}
void communicator_sendTestPacket(void){
	uint8_t test[]={1,2,3};
	network_send(test,3);
}
int8_t communicator_createSession(void){
	Packet_t*packet=(Packet_t*)packet_create();
	if(packet==NULL){
		return -1;
	}
	else if(packet_setVersionFlag(packet,VERSION_1)!=0){
		return -2;
	}
	else if(packet_setRequestFlag(packet)!=0){
		return -3;
	}
	network_send(packet,sizeof(Packet_t));
	packet_delete(packet);
	return 0;
}
