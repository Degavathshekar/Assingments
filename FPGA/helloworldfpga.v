/*Program for blinking LED
January 16,2021
Code by G V V Sharma
Released under GNU GPL
*/

//declaring the blink module
module helloworldfpga(
    input wire rst,
    output reg[15:0]counter,    
    output wire redled
);
    wire clk;

    qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
        .Sys_Clk0 (clk),
    );

    reg[23:0]    delay;
    reg          led;
always@(posedge clk) begin
delay = delay+1;
if(delay>2000000)
begin
	if(rst)
		counter = 16'b0000000000000000;
	else 
		counter = counter+1;
led = counter[15]|counter[14];
delay = 24'b0;
led = counter;

 
end
end
//    assign blueled = led;	//If you want to change led colour to blue, 
assign redled =led; //If you want to change led colour to red, 
endmodule
//end of the module
