/*********************************************************************************
 *     File Name           :     src/main.c
 *     Created By          :     anon
 *     Creation Date       :     [2016-09-12 15:18]
 *     Last Modified       :     [2016-09-12 16:09]
 *     Description         :      
 **********************************************************************************/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <jnxc_headers/jnx_types.h>
void show_help(void) {
  printf("======================================\n");
  printf("Hopper allows you to share packets across interfaces\n");
  printf("--iface0 NAME1 --iface1 NAME2\n");
  printf("======================================\n");
}
int main(int argc, char **argv) {

  int opt_index =0,c=0;

  jnx_char *iface0 = NULL, *iface1 = NULL, *port = (jnx_char*)"8080";

  static struct option long_opts[] = {
    {"help", no_argument, 0, 'h' },
    {"iface0", required_argument, 0, 'i' },
    {"iface1", required_argument, 0,'j'},
    {"port", optional_argument, 0, 'p'}
  };

  while(((c = getopt_long(argc, argv,"hi:j:p:",
            long_opts, &opt_index))) != -1) {

    switch(c) {
      case 'h':
        show_help();
        break;
      case 'i':
        iface0 = optarg;
        break;
      case 'j':
        iface1 = optarg;
        break;
      case 'p':
        port = optarg;
        break;
    }
  }
  if(!iface0 && !iface1) {
    show_help();
    exit(0);
  }


  while(1) {

    sleep(.25);
  }

  return 0;
}
