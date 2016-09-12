/*********************************************************************************
 *     File Name           :     src/interface_control.h
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:11]
 *     Last Modified       :     [2016-09-12 16:31]
 *     Description         :      
 **********************************************************************************/

#ifndef __INTERFACE_CONTROL_H__
#define __INTERFACE_CONTROL_H__
#include <stdlib.h>
#include <jnxc_headers/jnx_udp_socket.h>

typedef struct interface_control {

  char *port;
  char *iface0;
  char *iface1;
  jnx_udp_listener *iface0_listener;
  jnx_udp_listener *iface1_listener;
}interface_control;

interface_control *interface_control_create(char *iface0, char *iface1, 
    char *port);

void interface_control_destroy(interface_control **i);
#endif
