/*********************************************************************************
 *     File Name           :     src/main.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 15:18]
 *     Last Modified       :     [2016-09-13 15:31]
 *     Description         :      
 **********************************************************************************/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <jnxc_headers/jnx_types.h>
#include <signal.h>
#include "interface_control.h"

interface_control *controller;

void signal_handler(int sig) {

  if(controller) {
    interface_control_destroy(&controller);
  }
  exit(0);
}
void show_help(void) {
  printf("======================================\n");
  printf("Hopper allows you to share packets across interfaces\n");
  printf("--iface Takes multiple device names (e.g. --iface \"wlan0 eth0 eth1\")\n");
  printf("OPTIONAL --port PORT_NUM (e.g. --port 8080)\n");
  printf("======================================\n");
}
int main(int argc, char **argv) {

  if (signal(SIGINT, signal_handler) == SIG_ERR)
    printf("\ncan't catch SIGINT\n");
  if (signal(SIGSTOP, signal_handler) == SIG_ERR)
    printf("\ncan't catch SIGINT\n");
  
  
  int opt_index =0,c=0;

  jnx_char *iface = NULL, *port = (jnx_char*)"8080";

  static struct option long_opts[] = {
    {"help", no_argument, 0, 'h' },
    {"iface", required_argument, 0, 'i' },
    {"port", optional_argument, 0, 'p'}
  };

  while(((c = getopt_long(argc, argv,"i:",
            long_opts, &opt_index))) != -1) {

    switch(c) {
      case 'h':
        show_help();
        break;
      case 'i':
        iface = optarg;
        break;
      case 'p':
        port = optarg;
        break;
    }
  }
  if(!iface) {
    show_help();
    exit(0);
  }

  controller = interface_control_create();

  interface_control_create_interface_definitions(controller, iface,port, AF_INET);

  while(1) {
    
    interface_control_tick(controller);

    sleep(.25);
  }


  if(controller)
    interface_control_destroy(&controller);
  
  return 0;
}
