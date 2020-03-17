localparam BND1_CH = 128;
localparam BND1_BW_A = 6;
localparam BND1_BW_B = 16;
localparam BND1_RSHIFT = 8;
localparam BND1_BW_IN = 16;
localparam BND1_BW_OUT = 16;
localparam BND1_MAXVAL = -1;
reg [BND1_CH-1:0][BND1_BW_A-1:0] bnd1_a = { 6'h0a, 6'h0b, 6'h0c, 6'h0d, 6'h10, 6'h09, 6'h10, 6'h12, 6'h11, 6'h0c, 6'h0e, 6'h0b, 6'h13, 6'h0b, 6'h0b, 6'h0c, 6'h08, 6'h0d, 6'h0d, 6'h0f, 6'h0b, 6'h0d, 6'h0d, 6'h0e, 6'h0e, 6'h0e, 6'h08, 6'h0e, 6'h10, 6'h0c, 6'h0e, 6'h0e, 6'h0c, 6'h0d, 6'h0a, 6'h0d, 6'h0d, 6'h0a, 6'h0d, 6'h0d, 6'h0b, 6'h0c, 6'h0b, 6'h0d, 6'h0d, 6'h0c, 6'h0f, 6'h08, 6'h0d, 6'h0c, 6'h0e, 6'h0b, 6'h0f, 6'h10, 6'h0c, 6'h0d, 6'h0d, 6'h10, 6'h0e, 6'h0c, 6'h0d, 6'h0b, 6'h0a, 6'h0f, 6'h0e, 6'h0a, 6'h0d, 6'h0c, 6'h0d, 6'h0b, 6'h0e, 6'h0f, 6'h0d, 6'h10, 6'h0e, 6'h0d, 6'h0b, 6'h0c, 6'h11, 6'h0d, 6'h0a, 6'h0e, 6'h11, 6'h0d, 6'h0b, 6'h10, 6'h0a, 6'h0c, 6'h09, 6'h0a, 6'h0c, 6'h0c, 6'h0c, 6'h0a, 6'h0c, 6'h13, 6'h09, 6'h0f, 6'h0c, 6'h0a, 6'h0b, 6'h0a, 6'h0a, 6'h0c, 6'h12, 6'h0a, 6'h0b, 6'h0d, 6'h0d, 6'h0b, 6'h0c, 6'h0d, 6'h0b, 6'h0d, 6'h0c, 6'h0b, 6'h09, 6'h0c, 6'h0c, 6'h0d, 6'h0e, 6'h0e, 6'h0a, 6'h0b, 6'h0d, 6'h0a, 6'h0d, 6'h0d };
reg [BND1_CH-1:0][BND1_BW_B-1:0] bnd1_b = { 16'h5015, 16'hb298, 16'h08f5, 16'h2c6f, 16'h060a, 16'h4865, 16'hd728, 16'h0d5d, 16'h2fc1, 16'h1d83, 16'h0701, 16'hc9f1, 16'hee14, 16'hd29a, 16'hf166, 16'hd881, 16'h482b, 16'h2671, 16'he70f, 16'h4044, 16'heb2b, 16'hb2aa, 16'hd9b7, 16'he426, 16'hea72, 16'he4d3, 16'hdf93, 16'h0759, 16'h010d, 16'hc530, 16'h2d0f, 16'h0e1b, 16'hdd79, 16'he455, 16'h384a, 16'h285e, 16'hd878, 16'he170, 16'hce03, 16'he97c, 16'h3a4f, 16'hd806, 16'he12e, 16'h381a, 16'hfdb0, 16'hf625, 16'h0012, 16'h42c2, 16'hf223, 16'h07ec, 16'hf14c, 16'h1a37, 16'haee2, 16'he068, 16'hc803, 16'h0904, 16'h0eba, 16'h220f, 16'h3133, 16'he936, 16'hf142, 16'hba22, 16'h5e96, 16'h00a3, 16'h2189, 16'he505, 16'h0fa4, 16'h12f3, 16'h37ad, 16'h30fa, 16'he1aa, 16'hfa86, 16'hdc0a, 16'hf4d5, 16'h2b94, 16'h4734, 16'hfd19, 16'hdd3b, 16'h2b96, 16'hce0c, 16'h4360, 16'h302a, 16'hfa56, 16'hdc49, 16'hf985, 16'h2647, 16'h2304, 16'he757, 16'h4e73, 16'h3e35, 16'hec30, 16'h00f3, 16'h446f, 16'h3963, 16'he015, 16'hce47, 16'h29ef, 16'h0c8e, 16'h2f7c, 16'h31b3, 16'hf544, 16'h1dfc, 16'h489e, 16'hd828, 16'h3072, 16'h0c93, 16'h0d1d, 16'h3024, 16'hd29c, 16'h1014, 16'h2b15, 16'h21aa, 16'h2667, 16'hec77, 16'hcd48, 16'hd64a, 16'hd3fd, 16'hd5f2, 16'h5077, 16'h0ed1, 16'hdaea, 16'h00a2, 16'h3d98, 16'h0e8f, 16'hce7c, 16'he551, 16'h245c, 16'he926 };