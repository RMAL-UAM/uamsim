#include "ros_kinematic.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace current
{
    double time = 0.0;
    std::vector<double> position;
    std::vector<double> orientation;

    std::vector<float> linear_v;
    std::vector<float> angular_v;

    // WPose pose();
};

namespace gazebo
{
    class ModelPush : public ModelPlugin
    {
    public:
        /// A pointer to the GazeboROS node.
        gazebo_ros::Node::SharedPtr ros_node_;

        /// Subscriber to command velocities
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;

        /// Odometry publisher
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odometry_pub_;

        /// Connection to event called at every world iteration.
        gazebo::event::ConnectionPtr update_connection_;

        rclcpp::Subscription<rosgraph_msgs::msg::Clock>::SharedPtr clk_subscriber_;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr  publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

        rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twst_subscriber_;
        

        

        void Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf)
        {

            this->model = _model;
            // Initialize ROS node
            this->ros_node_ = gazebo_ros::Node::Get(_sdf);
            // Get QoS profiles
            const gazebo_ros::QoS &qos = this->ros_node_->get_qos();
            RCLCPP_WARN(this->ros_node_->get_logger(),"LOAAAAADIIIINGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
            
            clk_subscriber_ = this->ros_node_->create_subscription<rosgraph_msgs::msg::Clock>("clock", 10, std::bind(&ModelPush::clk_update, this, std::placeholders::_1));

            pose_subscriber_ = this->ros_node_->create_subscription<geometry_msgs::msg::PoseStamped>("uam/pose",
                                                                                          10,
                                                                                          std::bind(&ModelPush::pose_update, this, std::placeholders::_1));
            twst_subscriber_ = this->ros_node_->create_subscription<geometry_msgs::msg::Twist>("uam/twist",
                                                                                    10,
                                                                                    std::bind(&ModelPush::twist_update, this, std::placeholders::_1));

            // publisher_ = this->ros_node_->create_publisher<std_msgs::msg::String>("gazebo_topic", 10);
            // timer_ = this->ros_node_->create_wall_timer(500ms, std::bind(&ModelPush::timer_callback, this));
            // subscription_ = this->ros_node_->create_subscription<std_msgs::msg::String>("gazebo_topic", 10, std::bind(&ModelPush::topic_callback, this, std::placeholders::_1));

            this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&ModelPush::OnUpdate, this));

        }

        // Called by the world update start event
    public:
        void OnUpdate()
        {

            this->model->GetJoint("prop1")->SetVelocity(0, 10);
            this->model->GetJoint("prop2")->SetVelocity(0, 10);
            this->model->GetJoint("prop3")->SetVelocity(0, 10);
            this->model->GetJoint("prop4")->SetVelocity(0, 10);
            this->model->GetJoint("inter")->SetVelocity(0, 0);

            this->model->GetJoint("manip_base")->SetVelocity(0, 0);
            this->model->GetJoint("end")->SetVelocity(0, 0);

            this->model->GetLink("base_link")->SetLinearVel({0, 0, 0.1});
            this->model->GetLink("base_link")->SetAngularVel({0, 0, 0});
            // this->model->GetLink("base_link")->SetVelocity(0, 1.0);

            // BASE LINK
            // current::pose_here = this->model->GetLink("base_link")->WorldInertialPose();
            // current::pose_here - current::pose;
        }

        void clk_update(const rosgraph_msgs::msg::Clock::SharedPtr time) const
        {
            // current::time = time->clock.sec;
            // RCLCPP_WARN(this->ros_node_->get_logger(),std::to_string(current::time));
        }

        void pose_update(const geometry_msgs::msg::PoseStamped::SharedPtr pose) const
        {
            current::position[0] = pose->pose.position.x;
            current::position[1] = pose->pose.position.y;
            current::position[2] = pose->pose.position.z;

            current::orientation[0] = pose->pose.orientation.x;
            current::orientation[1] = pose->pose.orientation.y;
            current::orientation[2] = pose->pose.orientation.z;
            current::orientation[3] = pose->pose.orientation.w;
        }

        void twist_update(const geometry_msgs::msg::Twist::SharedPtr twst) const
        {

            /*
            current::linear_v[0] = twst->linear.x;
            current::linear_v[1] = twst->linear.y;
            current::linear_v[2] = twst->linear.z;

            current::angular_v[0] = twst->angular.x;
            current::angular_v[1] = twst->angular.y;
            current::angular_v[2] = twst->angular.z;
            */
            RCLCPP_INFO(this->ros_node_->get_logger(), "I heard something");
            RCLCPP_INFO(this->ros_node_->get_logger(), "I heard: '%f'", twst->linear.x);
        }
        void timer_callback()
        {
            auto message = std_msgs::msg::String();
            message.data = "Hello, world! ";
            RCLCPP_INFO(this->ros_node_->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        }

        void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
        {
            RCLCPP_INFO(this->ros_node_->get_logger(), "I heard: '%s'", msg->data.c_str());
        }

        // Pointer to the model
    private:
        physics::ModelPtr model;

        // Pointer to the update event connection
    private:
        event::ConnectionPtr updateConnection;
    };

    // Register this plugin with the simulator
    GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}