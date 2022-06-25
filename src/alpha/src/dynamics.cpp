#include <cstdio>
#include "dynamics.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"

#include "rosgraph_msgs/msg/clock.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"

/*
Important warning [DO NOT REMOVE UNTIL NO LONGER APPLICABLE]
  For topic /uam/pose
    Twist messages are being used to publish pose data due to Isaac Sim's constraints.
      rot_euler - published as angular speed
      tf_3d - published as linear speed
*/

class SimNode : public rclcpp::Node{
  public:
    SimNode() : Node("uam_sim_node",
                    rclcpp::NodeOptions()
                        .allow_undeclared_parameters(true)
                        .automatically_declare_parameters_from_overrides(true)){

      RCLCPP_INFO(get_logger(), "Initializing node.\n");

      clk_publisher_ = this->create_publisher<rosgraph_msgs::msg::Clock>("clock", 10);
      pose_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("uam/pose", 10);
      twst_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("uam/twist", 10);

      this->get_parameter_or("sim_end_time", this->t_final_secs, rclcpp::Parameter("sim_end_time", 1000));
      this->get_parameter_or("sim_step_size", this->t_step_secs, rclcpp::Parameter("sim_step_size", 0.1));
      this->set_parameter(rclcpp::Parameter("use_sim_time", true));
    }

    void publish_time(rosgraph_msgs::msg::Clock& time){
      clk_publisher_->publish(time);
    }

    void publish_state(geometry_msgs::msg::Twist& pose, geometry_msgs::msg::Twist& twist){
      pose_publisher_->publish(pose);
      twst_publisher_->publish(twist);
    }

    rclcpp::Parameter t_final_secs;
    rclcpp::Parameter t_step_secs;

  private:
    rclcpp::Publisher<rosgraph_msgs::msg::Clock>::SharedPtr clk_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pose_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twst_publisher_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimNode>();

  double t_cur = 0;
  double t_final = node->t_final_secs.as_int();
  double t_step = node->t_step_secs.as_double();
  int t_factor = 1;

  // RCLCPP_INFO(rclcpp::get_logger("Hello"), "1!\n");

  rclcpp::Rate loop_rate((int) t_factor/((double)t_step));

  RCLCPP_INFO(rclcpp::get_logger("SIM_INFO"), "Starting Simulation with frequency %f Hz\n", (int) t_factor/((double)t_step));


  rosgraph_msgs::msg::Clock t_msg;
  geometry_msgs::msg::Twist pose_msg;
  geometry_msgs::msg::Twist twist_msg;

  Euler uam_euler;
  geometry_msgs::msg::Point uam_pt;

  uam_euler.pitch = 45;
  uam_pt.z = 0;

  while (rclcpp::ok() && t_cur < t_final) {
            RCLCPP_INFO(rclcpp::get_logger("Tick"), "%f\n", t_cur);
            
            t_msg.clock.sec = floor(t_cur);
            t_msg.clock.nanosec = (int) ((t_cur - floor(t_cur))*1000000000);
            node->publish_time(t_msg);

            uam_pt.x = 0;
            uam_pt.y = 0;
            uam_pt.z += 1;

            uam_euler.pitch = 0;
            uam_euler.roll = 0;
            uam_euler.yaw = 0;

            pose_msg.angular.x = uam_euler.yaw;
            pose_msg.angular.y = uam_euler.pitch;
            pose_msg.angular.z = uam_euler.roll;

            pose_msg.linear.x = uam_pt.x;
            pose_msg.linear.y = uam_pt.y;
            pose_msg.linear.z = uam_pt.z;

            node->publish_state(pose_msg, twist_msg);
            
            rclcpp::spin_some(node);
            loop_rate.sleep();
            t_cur += t_step;
 }

  rclcpp::shutdown();
  return 0;
}
