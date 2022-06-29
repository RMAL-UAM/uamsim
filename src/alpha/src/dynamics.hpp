const int n = 12; // number of states
const int m = 4; // number of control inputs

/*
eg. x1 = [x, y, z] (n = 3)
x1, x2, x3, x4 are vectors forming state vector
*/

class state
{
private:
  /* data */
public:
  state(double[n]);
  double state_data[n];
  ~state();
};

state::state(double data[n])
{
}

state::~state()
{
}

state operator* (const state& x, double y){
  double data[n];
  return state(data);
} 

state operator+ (const state& x, const state& y){
  double data[n];
  return state(data);
} 

class control
{
private:
  /* data */
public:
  control(double[m]);
  ~control();
};

control::control(double data[m])
{
}

control::~control()
{
}

state dx_compute(state x, control u);
void rk4(std::vector<state> x_list, std::vector<state> dx_list, control u_cur, double Ts, double t);