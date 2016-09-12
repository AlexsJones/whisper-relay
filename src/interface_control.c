/*********************************************************************************
 *     File Name           :     /home/anon/Work/whisper_relay/src/interface_control.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:14]
 *     Last Modified       :     [2016-09-12 16:24]
 *     Description         :      
 **********************************************************************************/

#include "interface_control.h"
#include <jnxc_headers/jnx_check.h>
interface_control *interface_control_create(char *iface0, char *iface1, 
    char *port) {
  JNXCHECK(iface0);
  JNXCHECK(iface1);
  JNXCHECK(port);
  interface_control *i = malloc(sizeof(interface_control));
  i->iface0 = strdup(iface0);
  i->iface1 = strdup(iface1);
  i->port = strdup(port);
  return i;
}

void interface_control_destroy(interface_control **i) {

  free((*i)->port);
  free((*i)->iface0);
  free((*i)->iface1);
  free(*i);
  *i = NULL;
}
