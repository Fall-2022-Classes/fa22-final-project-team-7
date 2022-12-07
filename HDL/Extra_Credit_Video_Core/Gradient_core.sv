module gradient_core (
   input  logic clk, reset,
   // frame counter
   input  logic [10:0] x, y,
   // video slot interface
   input  logic cs,      
   input  logic write,  
   input  logic [13:0] addr,    
   input  logic [31:0] wr_data,
   // stream interface
   input  logic [11:0] si_rgb,
   output logic [11:0] so_rgb
);

   // delaration
   logic wr_en;
   logic bypass_reg;
   logic [11:0] gradient_rgb;
   logic [1:0] size;
   
   logic [2:0] rgb;
   // body
   // instantiate bar generator
   gradient_src gradient_src_unit 
      (.clk(clk), .x(x), .y(y), .gradient_rgb(gradient_rgb), .rgb(rgb), .size(size));
   // register  
   always_ff @(posedge clk, posedge reset)
      if (reset)
         bypass_reg <= 1;
      else if (wr_en)
      begin
         if(addr[1:0] == 2'b00)
         begin
            bypass_reg <= wr_data[0];
         end
         if(addr[1:0] == 2'b01)
         begin
            rgb <= wr_data[2:0];
         end
         if(addr[1:0] == 2'b10)
         begin
            size <= wr_data[1:0];
         end
      end
   // decoding 
   assign wr_en = write & cs;
   //  blending: bypass mux 
   assign so_rgb = bypass_reg ? si_rgb : gradient_rgb;
endmodule