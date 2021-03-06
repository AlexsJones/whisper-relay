/*********************************************************************************
 *     File Name           :     src/interface_control.h
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:11]
 *     Last Modified       :     [2016-09-13 14:50]
 *     Description         :      
 **********************************************************************************/

#ifndef __INTERFACE_CONTROL_H__
#define __INTERFACE_CONTROL_H__
#include <stdlib.h>
#include <jnxc_headers/jnx_udp_socket.h>
#include <jnxc_headers/jnx_hash.h>
typedef struct interface_definition {
  char *port;
  char *name;
  jnx_udp_listener *iface_listener;
  jnx_udp_listener_callback iface_listener_callback;
} interface_definition;

typedef struct interface_control {
 jnx_hashmap *interface_hash; 
}interface_control;

interface_control *interface_control_create();

void interface_control_create_interface_definitions(interface_control *i, 
    const char *iface_str, char *port, unsigned int family);

void interface_control_tick(interface_control *i);

void interface_control_destroy(interface_control **i);
#endif
