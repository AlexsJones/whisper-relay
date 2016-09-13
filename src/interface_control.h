/*********************************************************************************
 *     File Name           :     src/interface_control.h
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:11]
 *     Last Modified       :     [2016-09-13 09:46]
 *     Description         :      
 **********************************************************************************/

#ifndef __INTERFACE_CONTROL_H__
#define __INTERFACE_CONTROL_H__
#include <stdlib.h>
#include <jnxc_headers/jnx_udp_socket.h>


typedef struct interface_definition {
  char *port;
  char *name;
  jnx_udp_listener *iface_listener;
  jnx_udp_listener_callback iface_listener_callback;
} interface_definition;

typedef struct interface_control {
  
}interface_control;

interface_control *interface_control_create();

void interface_control_destroy(interface_control **i);
#endif
