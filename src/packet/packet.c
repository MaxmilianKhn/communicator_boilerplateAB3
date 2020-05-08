/*
 * packet.c
 *
 *  Created on: 07.05.2020
 *      Author: maxim
 */
#include"packet.h"
#include<stdlib.h>

void*packet_create(void){
	return calloc(1,sizeof(Packet_t));
}
int8_t packet_setVersionFlag(Packet_t*packet,Version_e version){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.version=version;
	return 0;
}
Version_e packet_getVersionFlag(Packet_t*packet){
	return (packet==NULL)?-1:packet->sessionHeader.version;
}
int8_t packet_setRequestFlag(Packet_t*packet){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.request=1;
	return 0;
}
int8_t packet_setChallengeFlag(Packet_t*packet){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.challenge=1;
	return 0;
}
int8_t packet_getChallengeFlag(Packet_t*packet){
	return (packet==NULL)?-1:packet->sessionHeader.challenge;
}
int8_t packet_setResponseFlag(Packet_t*packet){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.challengeResponse=1;
	return 0;
}
int8_t packet_getResponseFlag(Packet_t*packet){
	return(packet==NULL)?-1:packet->sessionHeader.challengeResponse;
}
int8_t packet_setExitFlag(Packet_t*packet){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.exit=1;
	return 0;
}
int8_t packet_setHearbeatFlag(Packet_t*packet){
	if(packet==NULL){
		return -1;
	}
	packet->sessionHeader.heartbeat=1;
	return 0;
}
void packet_delete(Packet_t*packet){
	free(packet);
}
