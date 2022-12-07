#ifndef OLED_GPIO_H_INCLUDED
#define OLED_GPIO_H_INCLUDED

#include "chu_init.h"


class OLEDGpoCore {
public:
   /**
    * register map
    *
    */
   enum {
      DATA_REG = 0
   };

   OLEDGpoCore(uint32_t core_base_addr);
   ~OLEDGpoCore();


   void write_oled(uint32_t data,uint32_t command );

private:
   uint32_t base_addr;
   uint32_t wr_data;      // same as GPO core data reg

};
#endif
