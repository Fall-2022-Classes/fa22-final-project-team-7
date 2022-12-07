module gradient_src (
   input logic [1:0] size,
   input  logic clk,
   input logic [2:0] rgb,
   input  logic [10:0] x, y,    
   output logic [11:0] gradient_rgb 
   );

   
   logic [3:0] horizontal, vertical;
   logic [3:0] r, g, b;
   logic [11:0] reg_d1_reg, reg_d2_reg;
   

   assign horizontal = x[8:5];    
   assign vertical = y[8:5];
   
   always_comb 
begin
        if(size == 2'b00)
        begin
            if(rgb == 3'b000)
            begin
                r = horizontal;
                g = horizontal;
                b = horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b001)
            begin
                r = horizontal;
                g = horizontal;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b010)
            begin
                r = horizontal;
                g = 4'b1111;
                b = horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b011)
            begin
                r = horizontal;
                g = 4'b1111;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b100)
            begin
                r = 4'b1111;
                g = horizontal;
                b = horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b101)
            begin
                r = 4'b1111;
                g = horizontal;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b110)
            begin
                r = 4'b1111;
                g = 4'b1111;
                b = horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b111)
            begin
                r = ~horizontal;
                g = ~horizontal;
                b = ~horizontal;
                if(x >511)
                begin
                    r = 4'b0000;
                    g = 4'b0000;
                    b = 4'b0000;
                end
            end
        end        

        if(size == 2'b01)
        begin
            if(rgb == 3'b000)
            begin
                r = vertical;
                g = vertical;
                b = vertical;
            end
            
            if(rgb == 3'b001)
            begin
                r = vertical;
                g = vertical;
                b = 4'b1111;
            end
            
            if(rgb == 3'b010)
            begin
                r = vertical;
                g = 4'b1111;
                b = vertical;
            end
            
            if(rgb == 3'b011)
            begin
                r = vertical;
                g = 4'b1111;
                b = 4'b1111;
            end
            
            if(rgb == 3'b100)
            begin
                r = 4'b1111;
                g = vertical;
                b = vertical;
            end
            
            if(rgb == 3'b101)
            begin
                r = 4'b1111;
                g = vertical;
                b = 4'b1111;
            end
            
            if(rgb == 3'b110)
            begin
                r = 4'b1111;
                g = 4'b1111;
                b = vertical;
            end
            
            if(rgb == 3'b111)
            begin
                r = ~vertical;
                g = ~vertical;
                b = ~vertical;
            end
        end  


        if(size == 2'b10)
        begin
            if(rgb == 3'b000)
            begin
                r = ~horizontal;
                g = ~horizontal;
                b = ~horizontal;
                if(x >511)
                begin
                    r = 4'b0000;
                    g = 4'b0000;
                    b = 4'b0000;
                end
            end
            
            if(rgb == 3'b001)
            begin
                r = ~horizontal;
                g = ~horizontal;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b0000;
                    g = 4'b0000;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b010)
            begin
                r = ~horizontal;
                g = 4'b1111;
                b = ~horizontal;
                if(x >511)
                begin
                    r = 4'b0000;
                    g = 4'b1111;
                    b = 4'b0000;
                end
            end
            
            if(rgb == 3'b011)
            begin
                r = ~horizontal;
                g = 4'b1111;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b0000;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b100)
            begin
                r = 4'b1111;
                g = ~horizontal;
                b = ~horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b0000;
                    b = 4'b0000;
                end
            end
            
            if(rgb == 3'b101)
            begin
                r = 4'b1111;
                g = ~horizontal;
                b = 4'b1111;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b0000;
                    b = 4'b1111;
                end
            end
            
            if(rgb == 3'b110)
            begin
                r = 4'b1111;
                g = 4'b1111;
                b = ~horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b0000;
                end
            end
            
            if(rgb == 3'b111)
            begin
                r = horizontal;
                g = horizontal;
                b = horizontal;
                if(x >511)
                begin
                    r = 4'b1111;
                    g = 4'b1111;
                    b = 4'b1111;
                end
            end
        end  


        if(size == 2'b11)
        begin
            if(rgb == 3'b000)
            begin
                r = ~vertical;
                g = ~vertical;
                b = ~vertical;
            end
            
            if(rgb == 3'b001)
            begin
                r = ~vertical;
                g = ~vertical;
                b = 4'b1111;
            end
            
            if(rgb == 3'b010)
            begin
                r = ~vertical;
                g = 4'b1111;
                b = ~vertical;
            end
            
            if(rgb == 3'b011)
            begin
                r = ~vertical;
                g = 4'b1111;
                b = 4'b1111;
            end
            
            if(rgb == 3'b100)
            begin
                r = 4'b1111;
                g = ~vertical;
                b = ~vertical;
            end
            
            if(rgb == 3'b101)
            begin
                r = 4'b1111;
                g = ~vertical;
                b = 4'b1111;
            end
            
            if(rgb == 3'b110)
            begin
                r = 4'b1111;
                g = 4'b1111;
                b = ~vertical;
            end
            
            if(rgb == 3'b111)
            begin
                r = vertical;
                g = vertical;
                b = vertical;
            end
    end         
   end  
   // output with 2-stage delay line
   always_ff @(posedge clk) begin
      reg_d1_reg <= {r, g, b};
      reg_d2_reg <= reg_d1_reg;
   end
   assign gradient_rgb = reg_d2_reg;
endmodule