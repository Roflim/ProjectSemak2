// client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char Buffer[7] = { 0 };
	void* context = zmq_ctx_new();
	void* requester = zmq_socket(context, ZMQ_REQ);
	zmq_connect(requester, "tcp://localhost:5555");
	zmq_send(requester, "12345", 5, 0);
	zmq_recv(requester, &Buffer, 7, 0);
	printf_s("%s\n", Buffer, 7);

	for (;; zmq_sleep(0.5)) {
		char result[20] = { 0 };
		char Mass[100] = { 0 };
		printf(">");
		gets_s(Mass, 100);
		zmq_send(requester, Mass, 100, 0);
		zmq_recv(requester, &result, 20, 0);
		printf_s("%s\n", result);
		printf("\n");
	}

	zmq_close(requester);
	zmq_ctx_destroy(context);
	return 0;
}