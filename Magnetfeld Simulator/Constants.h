static const long double mu0 = 1.25663706212e-06; //magnetische Feldkonstante
const long double PI = 3.141592653589793238463; //evtl. ug. falls ungenau, mehr dezimalen benötigt

static const float simulation_size_x = 1;
static const float simulation_size_y = 1;
static const float simulation_size_z = 1;

static const int image_size_x = 2000;
static const int image_size_y = 2000;

static const float Current = 100;

static const int simulation_wire_parts_count = 100;
static const float radius = 0.04;
static const int coil_winding_count = 20; //has to be divident of simulation_wire_parts_count
static const float coil_total_length = 0.4;
static const float step_size = 0.001;