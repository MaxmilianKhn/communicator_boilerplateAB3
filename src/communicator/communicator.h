/*
 * communicator.h
 *
 *  Created on: 07.05.2020
 *      Author: maxim
 */

#ifndef SRC_COMMUNICATOR_COMMUNICATOR_H_
#define SRC_COMMUNICATOR_COMMUNICATOR_H_

#include "../network/network.h"
#include <stdint.h>

typedef enum{
	TEST_SERVER=(195<<24)+(34<<16)+(89<<8)+241,
	MAIN_SERVER,
}Server_e;

int8_t communicator_connect(Server_e server);
void communicator_sendTestPacket(void);
int8_t communicator_createSession(void);

#endif /* SRC_COMMUNICATOR_COMMUNICATOR_H_ */
