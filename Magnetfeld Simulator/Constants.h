const long double PI = 3.141592653589793238463; //evtl. ug. falls ungenau, mehr dezimalen benötigt

const int image_size = 20000;

const float simulation_size = 1;
const int simulation_wire_parts_count = 2000;
const float step_size = 0.0005; //how dense the lines get rendered

//loop specific, also for coils
const float radius = 0.04;
//specific for Coils, not implementet yet
const int coil_winding_count = 4; //has to be divident of simulation_wire_parts_count
const float coil_total_length = 0.4;