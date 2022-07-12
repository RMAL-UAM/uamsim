#include <functional>
#include <memory>
#include <vector>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <gazebo/physics/PhysicsTypes.hh>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"
#include <rosgraph_msgs/msg/clock.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <tf2/LinearMath/Quaternion.h>

class PluginNode : public rclcpp::Node
{
public:
    PluginNode();
    // ~PluginNode();

private:
    rclcpp::Subscription<rosgraph_msgs::msg::Clock>::SharedPtr clk_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twst_subscriber_;

    void clk_update(const rosgraph_msgs::msg::Clock::SharedPtr time) const;
    void pose_update(const geometry_msgs::msg::PoseStamped::SharedPtr pose) const;
    void twist_update(const geometry_msgs::msg::Twist::SharedPtr twst) const;
};

class WPose
{
private:
public:
    WPose(){
        this->position(3);
    }
    std::vector<double> position;
    std::vector<double> orientation;

    WPose operator + (WPose const x)
    {
        WPose z;
        z.position = x.position + this->position;

    }
};

namespace current
{
    double time = 0.0;

    WPose pose();
}