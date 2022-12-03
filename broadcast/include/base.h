#ifndef __BASE_H__
#define __BASE_H__

#include "types.h"
#include "ether.h"
#include "list.h"

#include <arpa/inet.h>

typedef struct {
	struct list_head iface_list;	//接口链表
	int nifs;						//gds中fd的个数
	struct pollfd *fds;				//文件描述符的数组
} ustack_t;

extern ustack_t *instance;

typedef struct {
	struct list_head list;

	int fd;
	int index;
	u8	mac[ETH_ALEN];
	char name[16];
} iface_info_t;

void init_ustack();
iface_info_t *fd_to_iface(int fd);
void iface_send_packet(iface_info_t *iface, const char *packet, int len);

void broadcast_packet(iface_info_t *iface, const char *packet, int len);

#endif
