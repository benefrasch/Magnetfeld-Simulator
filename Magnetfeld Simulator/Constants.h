const long double PI = 3.141592653589793238463; //evtl. ug. falls ungenau, mehr dezimalen benötigt

const int image_size = 1000;

const float simulation_size = 1;
const int simulation_wire_parts_count = 10000;
const float step_size = 0.005; //how dense the lines get rendered

const int sleep_time = 5; //update time in sec. also saves image every update. needs more time for larger images

//loop specific, also for coils
const float radius = 0.04;
//specific for Coils, not implementet yet
const int coil_winding_count = 10; //has to be divident of simulation_wire_parts_count, also not working properly
const float coil_total_length = 0.4;