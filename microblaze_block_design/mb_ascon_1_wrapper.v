//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.2 (win64) Build 2708876 Wed Nov  6 21:40:23 MST 2019
//Date        : Wed Nov  9 11:21:48 2022
//Host        : Andrew running 64-bit major release  (build 9200)
//Command     : generate_target mb_ascon_1_wrapper.bd
//Design      : mb_ascon_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mb_ascon_1_wrapper
   (rx,
    sys_clk,
    sys_resetn,
    tx);
  input rx;
  input sys_clk;
  input sys_resetn;
  output tx;

  wire rx;
  wire sys_clk;
  wire sys_resetn;
  wire tx;

  mb_ascon_1 mb_ascon_1_i
       (.rx(rx),
        .sys_clk(sys_clk),
        .sys_resetn(sys_resetn),
        .tx(tx));
endmodule
