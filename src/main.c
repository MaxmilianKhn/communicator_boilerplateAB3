#include "input/input_service.h"
#include "windows.h"
#include <stdio.h>
#include "communicator/communicator.h"


static void cbInputHandler(InputKeyMask_t);

static bool gRunning = true;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	input_service_init(cbInputHandler);

	if(communicator_connect(TEST_SERVER)!=0){
		printf("Fehler");
	}

	while(gRunning) {
		Sleep(1000);
	}
	printf("Exiting...");
	return 0;
}



static void cbInputHandler(InputKeyMask_t m) {
	printf("Input event: %d.\r\n", m);
	if(m&INPUT_KEY_MASK_KEY_DOWN);
	if(m&INPUT_KEY_MASK_KEY_ESC)gRunning=false;
	if(m&INPUT_KEY_MASK_KEY_LEFT);
	if(m&INPUT_KEY_MASK_KEY_RIGHT);
	if(m&INPUT_KEY_MASK_KEY_SPACE)communicator_sendTestPacket();
	if(m&INPUT_KEY_MASK_KEY_UP);
}
