`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2022 11:09:50 AM
// Design Name: 
// Module Name: ASCON_FAST_TOP
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


module ASCON_FAST_TOP(
    input logic io_data,
    input logic key_reg[127:0],
    input logic round_const
    );
    
    //state regs
    logic [63:0] stateReg [3:0];
    
    
    
    S_Box_Parallel #(.N(64)) SBOX (
        .p0(),
        .p1(),
        .p2(),
        .p3(),
        .p4(),
        .t0(),
        .t1(),
        .t2(),
        .t3(),
        .t4()
    );
        
    Linear_Diffusion #(.BITS(64))DiffLayer (
        .x0(),
        .x1(),
        .x2(),
        .x3(),
        .x4(),
        .t0(),
        .t1(),
        .t2(),
        .t3(),
        .t4()
    );
    
endmodule
