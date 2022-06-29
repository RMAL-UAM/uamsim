struct Euler
{
    double roll;
    double pitch;
    double yaw;
};

class state
{
private:
  /* data */
public:
  state(double[4][3]);
  double state_data[4][3];
  ~state();
};

state::state(double data[4][3])
{
}

state::~state()
{
}

state operator* (const state& x, double y){
  double data[4][3];
  return state(data);
} 

state operator+ (const state& x, const state& y){
  double data[4][3];
  return state(data);
} 

class control
{
private:
  /* data */
public:
  control(double[4]);
  ~control();
};

control::control(double data[4])
{
}

control::~control()
{
}