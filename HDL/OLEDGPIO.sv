module oled_gpio_core
   (
    input  logic clk,
    input  logic reset,
    // slot interface
    input  logic cs,
    input  logic read,
    input  logic write,
    input  logic [4:0] addr,
    input  logic [31:0] wr_data,
    output logic [31:0] rd_data,
    // external port    
    output logic oled_dc, oled_reset, oled_vbatc, oled_vddc
   );

   // declaration
   logic wr_en;
   logic D0,D1,D2,D3;

   // body
   // output buffer register
   always_ff @(posedge clk, posedge reset)
      if (reset)
         begin
            D0 <= 0;
            D1 <= 0;
            D2 <= 0;
            D3 <= 0;
         end
      else   
         if (wr_en)
         begin
            if(addr[1:0] == 2'b00)
            begin
               D0 <= wr_data[0];
            end
         
            if(addr[1:0] == 2'b01)
            begin
               D1 <= wr_data[0];
            end
         
            if(addr[1:0] == 2'b10)
            begin
               D2 <= wr_data[0];
            end         

            if(addr[1:0] == 2'b11)
            begin
               D3 <= wr_data[0];
            end           
         
         end
   // decoding logic 
   
   
   assign wr_en = cs && write;
   // slot read interface
   assign rd_data =  0;
   // external output  
   assign oled_dc = D0;
   assign oled_reset = D1;
   assign oled_vbatc = D2;
   assign oled_vddc = D3;
endmodule