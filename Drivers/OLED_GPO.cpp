#include "OLED_GPO.h"


OLEDGpoCore::OLEDGpoCore(uint32_t core_base_addr) {
   base_addr = core_base_addr;
   wr_data = 0;
}

OLEDGpoCore::~OLEDGpoCore() {
}


void OLEDGpoCore::write_oled(uint32_t data,uint32_t command ) {
   wr_data = data;
   io_write(base_addr, command, wr_data);
}



