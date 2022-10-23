`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/22/2022 11:33:14 AM
// Design Name: 
// Module Name: S_box
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

//Will perform logic operations rather than table look-up
//to lower power consumption on small devices
module S_box(
    //5 bit words
    input logic x0, x1, x2, x3, x4,
    output logic xOut0, xOut1, xOut2, xOut3, xOut4
    );

    always_comb
    begin
        xOut4 = (x4 ^ x3) ^ (!(x0 ^ x4)& x1);
        xOut3 = x3 ^ (!(x4 ^ x3) & (x0 ^ x4)) ^ ((x2 ^ x1) ^ (!x3 & (x4 ^ x3)));
        xOut2 = !((x2 ^ x1) ^ (!x3 & (x4 ^ x3)));
        xOut1 = x1 ^ (!(x2 ^ x1) & x3) ^ ((x0 ^ x4) ^ (!x1 & (x2 ^ x1)));
        xOut0 = (x0 ^ x4) ^ (!x1 & (x2 ^ x1)) ^ ((x4 ^ x3) ^ (!(x0 ^ x4)& x1));
    end  
endmodule
