/*********************************************************************************
 *     File Name           :     /home/anon/Work/whisper_relay/src/interface_control.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:14]
 *     Last Modified       :     [2016-09-13 11:13]
 *     Description         :      
 **********************************************************************************/
#include <stdio.h>
#include <string.h>
#include "interface_control.h"
#include <jnxc_headers/jnx_log.h>
#include <jnxc_headers/jnx_check.h>
interface_control *interface_control_create() {
  interface_control *i = malloc(sizeof(interface_control));
  return i;
}

void interface_control_destroy(interface_control **i) {
  free(*i);
  *i = NULL;
}
void interface_control_create_interface_definitions(interface_control *i, 
    const char *iface_str) {

  char *pch = strtok((char*)iface_str," ");
  while(pch != NULL) {
    
    char *iface_name = pch;
    JNXLOG(LDEBUG,"Found interface name: %s",iface_name);
    pch = strtok(NULL," ");
  }


}
