/*********************************************************************************
 *     File Name           :     /home/anon/Work/whisper_relay/src/interface_control.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 16:14]
 *     Last Modified       :     [2016-09-13 15:47]
 *     Description         :      
 **********************************************************************************/
#include <stdio.h>
#include <string.h>
#include "interface_control.h"
#include <jnxc_headers/jnx_log.h>
#include <jnxc_headers/jnx_check.h>
#include <jnxc_headers/jnx_udp_socket.h>
interface_control *interface_control_create() {
  interface_control *i = malloc(sizeof(interface_control));
  i->interface_hash = jnx_hash_create(2048);   
  return i;
}
void interface_control_destroy_definition(interface_definition **d) {
  
  interface_definition *id = *d;
  jnx_socket_udp_listener_destroy(&(*id).iface_listener);
  free(id->port);
  free(id->name);
  free(*d);
  *d = NULL;
}
void interface_control_destroy(interface_control **i) {

  //destroy interface definitions
  const jnx_char **key_array;
  jnx_int32 l = jnx_hash_get_keys((*i)->interface_hash, &key_array);
  int c;
  for(c=0;c<l; ++c) {
    const char *key = key_array[c];
    interface_definition *d = jnx_hash_delete_value((*i)->interface_hash,(char*)
        key);
    interface_control_destroy_definition(&d);

  }

  jnx_hash_destroy(&(*i)->interface_hash);
  free(key_array);
  free(*i);
  *i = NULL;
}
void listener_callback (const jnx_uint8 *payload, jnx_size bytes_read, void *args) {

  JNXLOG(LDEBUG,"Incoming message %s\n",payload);

} 
interface_definition *interface_control_create_definition(char *iface, char *port,
    unsigned int family) {

  interface_definition *i = malloc(sizeof(interface_definition));
  i->port = strdup(port);
  i->name = strdup(iface);
  i->iface_listener = jnx_socket_udp_listener_create(port,family,iface);
  i->iface_listener_callback = listener_callback;  
  JNXLOG(LDEBUG,"Created interface (%s) listener\n",iface);
  return i;
}
void interface_control_create_interface_definitions(interface_control *i, 
    const char *iface_str, char *port, unsigned int family) {

  char *pch = strtok((char*)iface_str," ");
  while(pch != NULL) {
    char *iface_name = pch;
    JNXLOG(LDEBUG,"Found interface name: %s",iface_name);

      interface_definition *iface_d = interface_control_create_definition(iface_name, 
          port, family);
     
      JNXLOG(LDEBUG,"Hashing key %s\n",iface_name);
      jnx_hash_put(i->interface_hash, (const char*)iface_name,iface_d);
      
    pch = strtok(NULL," ");
  }


}
void interface_control_tick(interface_control *i) {

  const jnx_char **key_array;
  jnx_int32 l = jnx_hash_get_keys(i->interface_hash, &key_array);
  int c;
  for(c=0;c<l; ++c) {
    const char *key = key_array[c];
    interface_definition *d = jnx_hash_get(i->interface_hash,(char*)
        key);
    jnx_socket_udp_listener_tick(d->iface_listener,d->iface_listener_callback,
        NULL);
  }
  free(key_array);
}
