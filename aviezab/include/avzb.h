#ifndef AVZB_H
#define AVZB_H
#include <instant.h>

extern uint16_t PORT;

static bool str_to_uint16(const char *str, uint16_t *res) {
  char *end;
  errno = 0;
  intmax_t val = strtoimax(str, &end, 10);
  if (errno == ERANGE || val < 0 || val > UINT16_MAX || end == str ||
      *end != '\0')
    return false;
  *res = (uint16_t)val;
  return true;
}

int argparser(int argcc, char *argvv[], char *IP_ADDD) {
  if (argcc < 2) {
    printf("Argument is too few. Exiting...\n");
    return 1;
  }
  if (argcc == 2) {
    printf("Port is not defined, using default port %hu\n", PORT);
    return 0;
  }
  if (argcc == 3) {
    // uint16_t portx = (uint16_t)atoi(argvv[2]);
    str_to_uint16(argvv[2], &PORT);
    // memset(&PORTT, portx, sizeof(portx));
    strncpy(IP_ADDD, argvv[1], strlen(argvv[1]));
    printf("argvv --> IP_ADDD %s --> %s\n", argvv[1], IP_ADDD);
    printf("argvv --> PORTT   %s --> %hu\n", argvv[2], PORT);
    // printf("Server is running on %s %d\n", IP_ADDD, PORTT);
    return 0;
  }
  return 0;
}

#endif