#include "base.h"
#include <stdio.h>

extern ustack_t *instance;

void broadcast_packet(iface_info_t *iface, const char *packet, int len)
{
	// TODO: broadcast packet 
	fprintf(stdout, "TODO: broadcast packet.\n");
	iface_info_t *other_iface = NULL;	//定义其它端口
	list_for_each_entry(other_iface, &instance->iface_list, list) {
		if (other_iface->fd != iface->fd)
			iface_send_packet(other_iface, packet, len);
	}	
}
