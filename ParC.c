#include <stdio.h>
#include <unistd.h> 
#include <sys/io.h> 
#define PortAddress (0x0378)
  int main()
    {
      int number; 
      printf("Enter the value for the pins you'd like to activate.");
      scanf("%d", &number);
      if (ioperm(PortAddress, 1, 1)) 
       {
          printf("ioperm(%x) failed. Are you root?", PortAddress);
          return 1;
        }
      outb(number, PortAddress);
      return 0;
    }
