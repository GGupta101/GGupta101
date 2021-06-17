`timescale 1ns/1ps

//The input clock is used to increment a 17 bit counter.
//With a 50 MHz input clock, the main counter will roll
//over about 381 times a second.

//The output CLOCK_1 divides the main clock by 5 to 
//produce a clock pulse 76 times a second.

//The output CLOCK_2 divides the main clock by 11 to
//produce a clock pulse 35 times a second.

//The default values of 5 and 11 are configurable
//from 1 to 255.

module clock_counter(
    input CLOCK_50,
	 output reg CLOCK_1 = 1'b0,
	 output reg CLOCK_2 = 1'b0	 
    );
	 
	 //Default reset values of the counters.
	 localparam CLK_1 = 8'd5;
	 localparam CLK_2 = 8'd11;
	 
	 reg [16:0]main_counter = 17'h00000; 
	 reg main_out = 1'b0;
	 
	 reg [7:0]clk1_counter = 8'h00;
	 reg [7:0]clk2_counter = 8'h00;
	 
	 //Main counter control.
	 always @(posedge CLOCK_50) begin
	     main_counter <= main_counter + 1'b1;
	 
	     //Strobe output 381 times a second.
	     if(main_counter == 17'h1FFFF) begin
		      main_out <= 1'b1;
		  end	  
		  else begin
		      main_out <= 1'b0;
		  end
	 end
	 
	 //CLOCK_1 control
	 always @(posedge CLOCK_50) begin
	     if(main_out == 1'b1) begin
		      clk1_counter <= clk1_counter + 1'b1;
		  end
		  
		  //Strobe output of CLOCK_1.
		  if(clk1_counter == (CLK_1 - 1'b1)) begin
		      CLOCK_1 <= 1'b1;
				clk1_counter <= 8'h00;
	     end
		  
		  else begin
		      CLOCK_1 <= 1'b0;
		  end
	 end
	 
	 //CLOCK_2 control
	 always @(posedge CLOCK_50) begin
	     if(main_out == 1'b1) begin
		      clk2_counter <= clk2_counter + 1'b1;
		  end	
		 
		  //Strobe output of CLOCK_2.
		  if(clk2_counter == (CLK_2 - 1'b1)) begin
		      CLOCK_2 <= 1'b1;
				clk2_counter <= 8'h00;
	     end
		  
		  else begin
		      CLOCK_2 <= 1'b0;
		  end 
	 end
endmodule
