/*********************************************************************************
 *     File Name           :     /home/anon/Work/whisper_relay/src/interface_control.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:14]
 *     Last Modified       :     [2016-09-13 09:46]
 *     Description         :      
 **********************************************************************************/

#include "interface_control.h"
#include <jnxc_headers/jnx_check.h>
interface_control *interface_control_create() {
  interface_control *i = malloc(sizeof(interface_control));
  return i;
}

void interface_control_destroy(interface_control **i) {

  free(*i);
  *i = NULL;
}
