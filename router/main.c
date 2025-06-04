#include <stdio.h>

int ascii_to_int(char ascii_char) {
  return ascii_char -= 48;
}

int ip_string_parser(char *ip_string, int str_length) {
  
    unsigned int ip_addr = 0;
    unsigned char octet = 0;

    // Loops trough the IP address
    for (int i=0, j=0; i < str_length; i++, j++) {
    
      char decimal;
      char base;
      char power;

      if (ip_string[i] == '.' || i+1 == str_length) { // Hits if new octet, or at end of IP
        
        // Gets the octets value in Binary and stores it in octet
        while (j) {

          decimal = ascii_to_int(ip_string[i-j]);

          base = 10;
          power = 1;
          for (int i=0; i < j-1; i++) {
            power = power * base;
          }

          octet += decimal*power;

          j--;
        }

        // Adds the octet to the IP and bitshifts it 1 octet(8bits) to the left
        ip_addr += octet;

        if (i+1 != str_length) {
          ip_addr = ip_addr << 8;
        }
    

        // Resets j and octet
        octet = 0;
        j = -1;
      } 
    }

  return ip_addr;
}

// 11111111.00000000.00000000.00000000
// 11000000.10101000.00000001.00001010

// 11000000 = 192

// 00000000.11111111.00000000.00000000
// 11000000.10101000.00000001.00001010

//          10101000 = 168


int main() {
  char ip_string[] = "192.168.1.10";
  int ip_addr = ip_string_parser(ip_string, sizeof(ip_string));

  ip_to_string(ip_addr);
  return 0;
}