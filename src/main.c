/*********************************************************************************
 *     File Name           :     src/main.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 15:18]
 *     Last Modified       :     [2016-09-13 09:53]
 *     Description         :      
 **********************************************************************************/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <jnxc_headers/jnx_types.h>
#include <signal.h>
void signal_handler(int sig) {


}
void show_help(void) {
  printf("======================================\n");
  printf("Hopper allows you to share packets across interfaces\n");
  printf("--iface IFACE1_NAME IFACE2_NAME (e.g. --iface wlan0 eth0 eth1)\n");
  printf("OPTIONAL --port PORT_NUM (e.g. --port 8080)\n");
  printf("======================================\n");
}
int main(int argc, char **argv) {

  if (signal(SIGINT, signal_handler) == SIG_ERR)
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


  while(1) {

    sleep(.25);
  }



  return 0;
}
