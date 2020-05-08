/*
 * packet.h
 *
 *  Created on: 07.05.2020
 *      Author: maxim
 */

#ifndef SRC_PACKET_PACKET_H_
#define SRC_PACKET_PACKET_H_

#include<stdint.h>

typedef enum{
	VERSION_1=1,
	VERSION_2=2,
	VERSION_3=3,
}Version_e;

typedef struct{
	uint8_t heartbeat:1;
	uint8_t request:1;
	uint8_t challenge:1;
	uint8_t challengeResponse:1;
	uint8_t exit:1;
	uint8_t RFU:1;
	uint8_t version:2;
}PacketSessionHeader_t;

typedef struct{
	PacketSessionHeader_t sessionHeader;
	uint16_t payloadLength;

}Packet_t;

void*packet_create(void);
int8_t packet_setVersionFlag(Packet_t*packet, Version_e);
Version_e packet_getVersionFlag(Packet_t*packet);
int8_t packet_setRequestFlag(Packet_t*packet);
int8_t packet_setChallengeFlag(Packet_t*packet);
int8_t packet_getChallengeFlag(Packet_t*packet);
int8_t packet_setResponseFlag(Packet_t*packet);
int8_t packet_getResponseFlag(Packet_t*packet);
int8_t packet_setExitFlag(Packet_t*packet);
int8_t packet_setHearbeatFlag(Packet_t*packet);
void packet_delete(Packet_t*packet);

#endif /* SRC_PACKET_PACKET_H_ */
