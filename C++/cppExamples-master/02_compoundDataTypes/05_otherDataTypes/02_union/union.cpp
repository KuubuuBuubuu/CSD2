#include <iostream>

/*
* The following unions are helping in endian-independent communication
*/

union ns {
  unsigned char array[2];
  int16_t num;
};

union nl {
  unsigned char array[4];
  int32_t num;
};

union nf {
  unsigned char array[4];
  float num;
};

int main() {
  ns netshort;
  nl netlong;
  nf netfloat;
  /*
   * union with 2 bytes and int16_t
   */
  netshort.num = 4;
  printf("\n---- union with 2 bytes and int16_t ----\n");
  printf("netshort.num contains: %i\n", netshort.num);
  printf("printing netshort.array bytes seperately:\n");
  for (int i = 0; i < 4; i++) {
    //print netshort bytes
    printf("\tnetshort.array[%d] = %02X\n", i, (unsigned char)netshort.array[i]);
  }
  printf("if we print these bytes as int16_t, we get: %i\n", *(int16_t *)&netshort.array);

  /*
  * union with 4 bytes and int32_t
  */
  netlong.num = 8888;
  printf("\n---- union with 4 bytes and int32_t ----\n");
  printf("printing netlong.array bytes seperately:\n");
  printf("netlong.num contains: %i\n", netlong.num);
  for (int i = 0; i < 4; i++) {
    //print netlong bytes
    printf("\tnetlong.array[%d] = %02X\n", i, (unsigned char)netlong.array[i]);
  }
  printf("if we print these bytes as int32_t, we get: %i\n", *(int32_t *)&netlong.array);


/*
 * union with 4 bytes and float
 */
  netfloat.num = 1.77;
  printf("\n---- union with 4 bytes and float ----\n");
  printf("printing netfloat.array bytes seperately:\n");
  printf("netfloat.num contains: %f\n", netfloat.num);
  for (int i = 0; i < 4; i++) {
    //print netfloat bytes
    printf("\tnetfloat.array[%d] = %02X\n", i, (unsigned char)netfloat.array[i]);
    //copy netfloat bytes to netlong
    netlong.array[i] = netfloat.array[i];
  }
  printf("if we print these bytes as float, we get: %f\n", *(float *)&netfloat.array);

  /*
   * printing float bytes as int32_t
   */
  printf("\n---- 4 bytes filled with float printed as int32_t ----\n");
  printf("if we print these bytes as int, we get: %i\n", *(int32_t *)&netfloat.array);
  printf("After copying the netfloat bytes to netlong, netlong.num contains: %i\n", netlong.num);

  //end programm
  return 0;
}
