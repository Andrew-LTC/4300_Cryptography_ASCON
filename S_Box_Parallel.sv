`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2022 11:27:41 AM
// Design Name: 
// Module Name: S_Box_Parallel
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


module S_Box_Parallel
#(parameter N = 1)(
    input logic [N-1:0] p0,p1,p2,p3,p4,
    output logic [N-1:0] t0,t1,t2,t3,t4 
    );
    
    // 1-bit word S-Box iterations
    generate
        genvar i;
        for(i=0;i<N;i=i+1)
        begin: SBOX
            S_box(
            .x0(p0[i]),
            .x1(p1[i]),
            .x2(p2[i]),
            .x3(p3[i]),
            .x4(p4[i]),
            .xOut0(t0[i]),
            .xOut1(t1[i]),
            .xOut2(t2[i]),
            .xOut3(t3[i]),
            .xOut4(t4[i])
            );
        end
    endgenerate
endmodule
