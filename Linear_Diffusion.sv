`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/22/2022 12:51:17 PM
// Design Name: 
// Module Name: Linear_Diffusion
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Linear_Diffusion
#(parameter BITS = 64)(
    //64-bit words
    input logic [BITS-1:0] x0, x1, x2, x3, x4,
    output logic [BITS-1:0] t0, t1, t2, t3, t4
    );
    
    always_comb
    begin
        t0 = x0 ^ (x0 >> 19) ^ (x0 >> 18);
        t1 = x1 ^ (x1 >> 61) ^ (x1 >> 39);
        t2 = x2 ^ (x2 >> 1) ^ (x2 >> 6);
        t3 = x3 ^ (x3 >> 10) ^ (x3 >> 17);
        t4 = x4 ^ (x4 >> 7) ^ (x4 >> 41);
    end 
endmodule
